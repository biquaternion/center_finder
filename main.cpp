#include <iostream>

#include <opencv2/opencv.hpp>
#include <chrono>
#include "HoughBasedCenterFinder.h"

int main(int argc, char **argv) {

    std::string fileName = "";
    std::string method = "hough";
    if (argc > 1){
        fileName = argv[1];
    }
    if (argc > 2) {
        method = argv[2];
    }

    std::unique_ptr<ICenterFinder> finder;
    if (method == "hough") {
        finder = std::make_unique<HoughBasedCenterFinder>();
    } else {
        finder = std::make_unique<HoughBasedCenterFinder>();
    }

    cv::Mat image = cv::imread(fileName);
    if (image.empty()) {
        std::cout << "no image\n";
        return -1;
    }

    auto t0 = std::chrono::system_clock::now();
    finder->find(image);
    auto t1 = std::chrono::system_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count();

    std::cout << finder->result() << std::endl << elapsed << std::endl;

    cv::waitKey(0);

    return 0;
}