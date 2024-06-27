QT       += core gui network gamepad

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    tMonClientUDP.cpp \
    tclavier.cpp \
    tdrone.cpp \
    tfluxdrone.cpp \
    tgamepad.cpp \
    tinfovol.cpp

HEADERS += \
    mainwindow.h \
    tMonClientUDP.h \
    tclavier.h \
    tdrone.h \
    tfluxdrone.h \
    tgamepad.h \
    tinfovol.h

FORMS += \
    mainwindow.ui

INCLUDEPATH += /usr/include/opencv4

LIBS +=  -L/usr/lib/x86_64-linux-gnu \
       -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_shape -lopencv_videoio -lopencv_calib3d -lopencv_face

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
