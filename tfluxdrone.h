#ifndef TFLUXDRONE_H
#define TFLUXDRONE_H

#include <iostream>
//#include <opencv2/opencv.hpp>

#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/videoio.hpp>
#include <opencv4/opencv2/highgui.hpp>
class tFluxDrone
{
public:
    tFluxDrone();
    int prise_de_vue();
    int video();
    int photo();
};

#endif // TFLUXDRONE_H
