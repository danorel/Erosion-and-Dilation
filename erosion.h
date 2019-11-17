//
// Created by Dan Orel on 2019-10-17.
//
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/opencv.hpp>
#ifndef EROSION_DYLATACY_EROSION_H
#define EROSION_DYLATACY_EROSION_H
class Erosion{
public:
    Erosion();
    void setupKernel(
            int **kernel,
            int kernelSize);
    cv::Mat start(cv::Mat &Image);
    ~Erosion();
private:
    void defaultKernel();
private:
    int       kernelSize;
    int         **kernel;
    bool isDefaultKernel;
};
#endif //EROSION_DYLATACY_EROSION_H
