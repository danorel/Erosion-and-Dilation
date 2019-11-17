#include <iostream>
#include "erosion.h"
#include "dilation.h"

int main() {
    std::string pathToImage = "/Users/danorel/Workspace/World of C/C++/KMA/MMPI/Erosion&Dilation/";
    std::string image = "binary.png";
    std::string BinaryLabel = "Binary Image";
    std::string ErosionLabel = "Erosion Image";
    std::string DylatacyLabel = "Dilation Image";

    cv::Mat Image = cv::imread(
            (pathToImage + image),
            cv::IMREAD_GRAYSCALE);
    cv::Mat BinaryImage;
    cv::threshold(
            Image,
            BinaryImage,
            128.0,
            255.0,
            cv::THRESH_BINARY);
    cv::Mat ErosionImage = Erosion().start(BinaryImage);
    cv::Mat DylatacyImage = Dilation().start(BinaryImage);
    imshow(BinaryLabel, BinaryImage);
    imshow(ErosionLabel, ErosionImage);
    imshow(DylatacyLabel, DylatacyImage);
    cv::waitKey();
    return 0;
}