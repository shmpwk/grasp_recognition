#include <OpenNI.h>
#include "ros/ros.h"

#define INTERVAL 2  //intervall always > Step!!!!! otherwise seg fault ;)
#define STEP 12
cv::Mat img;
PlaneDetector::PlaneDetector(openni::VideoStream* stream){
    depthStream = stream;
    img = cv::Mat(stream->getVideoMode().getResolutionY(), stream->getVideoMode().getResolutionX(), CV_8UC3);

}

// Attention: 16bit input image!!!
void PlaneDetector::calculateNormalImage(cv::Mat* image,cv::Mat* normals){

    if(image->rows!= normals->rows || image->cols!=normals->cols){
         qDebug()<< "Error: wrong cols/rows. Check x/y missmatch!";
    }

    int width = image->cols;
    int height = image->rows ;

    cv::Point3f temp_vectorA; //Top<->Bottom
    cv::Point3f temp_vectorB; // Left<->Right
    cv::Point3f tmpA;
    cv::Point3f tmpB;

    openni::CoordinateConverter::convertDepthToWorld(depth, i, j, pDepth[index], &px, &py, &pz);
