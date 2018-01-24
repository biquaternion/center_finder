#include "ICenterFinder.h"


std::ostream &operator <<(std::ostream &o, const center_data_t &data) {
    const char *dividor = "\n";
    return o << "outer:" << dividor
             << data.wrapperCenter << dividor
             << "inner:" << dividor
             << data.coreCenter << dividor;
}

cv::Mat ICenterFinder::preprocessing(const cv::Mat &image) {
    if (image.channels() > 1) {
        cv::Mat gray;
        cv::cvtColor(image, gray, cv::COLOR_RGB2GRAY);
        return gray;
    }
    return image;
}

center_data_t ICenterFinder::result() const {
    return _result;
}