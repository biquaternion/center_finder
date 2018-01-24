#include "HoughBasedCenterFinder.h"

HoughBasedCenterFinder::HoughBasedCenterFinder() :
    ICenterFinder() {}

void HoughBasedCenterFinder::find(const cv::Mat &image) {
    std::cout << "Hough-based CF not implemented yet\n";
    _result.wrapperCenter = {-13, -14};
    _result.coreCenter = {-12, -13};
}

cv::Mat HoughBasedCenterFinder::preprocessing(const cv::Mat &image) {
    cv::Mat tmp;
    tmp = ICenterFinder::preprocessing(image);
    return tmp;
}