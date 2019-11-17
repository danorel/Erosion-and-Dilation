//
// Created by Dan Orel on 2019-10-17.
//
#include "erosion.h"


Erosion::Erosion() {
    this->isDefaultKernel = true;
    this->kernelSize      = 3;
    // Initialising the default erosion kernel
    this->kernel = new int*[this->kernelSize];
    for(int index = 0; index < this->kernelSize; index++){
        this->kernel[index] = new int[this->kernelSize];
    }
}

cv::Mat Erosion::start(cv::Mat &Image) {
    cv::Mat ProcessedImage(
            Image.size(),
            Image.type());
    // Use/Not use default kernel
    if(this->isDefaultKernel){
        defaultKernel();
    }
    int verticalBound   = ceil((this->kernelSize - 1) / 2);
    int horizontalBound = ceil((this->kernelSize - 1) / 2);
    for(int row = 0; row < ProcessedImage.rows; row++){
        for(int column = 0; column < ProcessedImage.cols; column++){
            uchar minimum = 255,
                  value;
            for(int kernel_row = 0; kernel_row < this->kernelSize; kernel_row++){
                for(int kernel_column = 0; kernel_column < this->kernelSize; kernel_column++){
                    value = (this->kernel[kernel_row][kernel_column] * Image.at<uchar>(kernel_row + row - verticalBound,kernel_column + column - horizontalBound));
                    if(minimum > value){
                        minimum = value;
                    }
                }
            }
            ProcessedImage.at<uchar>(row, column) = minimum;
        }
    }
    return ProcessedImage;
}

void Erosion::setupKernel(int **kernel, int kernelSize) {
    this->kernel          = kernel;
    this->kernelSize      = kernelSize;
    this->isDefaultKernel = false;
}

void Erosion::defaultKernel() {
    for(int row = 0; row < this->kernelSize; row++){
        for(int column = 0; column < this->kernelSize; column++){
            if(row == 0 && column == 0){
                this->kernel[row][column] = 1;
            } else {
                this->kernel[row][column] = 1;
            }
        }
    }
    std::cout << "Erosion kernel is in usage: " << std::endl;
    for(int row = 0; row < this->kernelSize; row++){
        for(int column = 0; column < this->kernelSize; column++){
            std::cout << this->kernel[row][column] << " ";
        }
        std::cout << "\n";
    }
}

Erosion::~Erosion() {
    // Removing all inner arrays
    for(int index = 0; index < this->kernelSize; index++) {
        delete[] this->kernel[index];
    }
    // Removing the outer array
    delete[] this->kernel;
}
