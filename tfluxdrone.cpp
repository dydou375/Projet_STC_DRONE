#include "tfluxdrone.h"


using namespace std;
using namespace cv;

tFluxDrone::tFluxDrone()
{

}

int tFluxDrone::prise_de_vue()
{
    VideoCapture cap("udp://0.0.0.0:11111/",CAP_GSTREAMER); 	// Ouvrir la caméra par défault : 0 (caméra usb si présente)
    if(!cap.isOpened())  	// Test si l'ouverture est correcte
        return -1;

    for(;;)
    {
        Mat frame;          // Déclaration d'une matrice point (pixels)
        cap >> frame; 		// Obtention d'une nouvelle frame depuis la caméra

        imshow("StreamOn Tello Edu", frame);					// Affichage
        char c = (char)waitKey(1);
        if( c == 30 )
          break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}

int tFluxDrone::photo()
{
    using namespace cv;
    // Capture the Image from the webcam
    VideoCapture cap("udp://0.0.0.0:11111/",CAP_GSTREAMER);
    if(!cap.isOpened())  	// Test si l'ouverture est correcte
        return -1;

    // Get the frame
    Mat save_img; cap >> save_img;

    if(save_img.empty())
    {
      std::cerr << "Something is wrong with the webcam, could not get frame." << std::endl;
    }
    // Save the frame into a file
    imwrite("/home/etu903/Images/photoDrone.jpg", save_img); // A JPG FILE IS BEING SAVED

    return 0;
}

int tFluxDrone::video()
{
    // Create a VideoCapture object and use camera to capture the video
    VideoCapture cap("udp://0.0.0.0:11111/",CAP_GSTREAMER);;

    // Check if camera opened successfully
    if(!cap.isOpened()){
      cout << "Error opening video stream" << endl;
          return -1;
    }

    // Default resolutions of the frame are obtained.The default resolutions are system dependent.
    int frame_width = cap.get(cv::CAP_PROP_FRAME_WIDTH);
    int frame_height = cap.get(cv::CAP_PROP_FRAME_HEIGHT);

    // Define the codec and create VideoWriter object.The output is stored in 'outcpp.avi' file.
    VideoWriter video("/home/etu903/Images/VideoDrone.avi", cv::VideoWriter::fourcc('M','J','P','G'), 10, Size(frame_width,frame_height)); //voir pour prendre un autre encodeur video lente lors de l'enrengistrement

    while(1){

      Mat frame;

      // Capture frame-by-frame
      cap >> frame;

      // If the frame is empty, break immediately
      if (frame.empty())
        break;

      // Write the frame into the file 'outcpp.avi'
      video.write(frame);

      // Display the resulting frame
      imshow( "Frame", frame );

      // Press  ESC on keyboard to  exit
      char c = (char)waitKey(1);
      if( c == 30 )
        break;
    }

    // When everything done, release the video capture and write object
    cap.release();
    video.release();

    // Closes all the frames
    destroyAllWindows();
    return 0;
}
