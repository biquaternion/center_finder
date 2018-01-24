#ifndef CENTER_FINDER_ICENTERFINDER_H
#define CENTER_FINDER_ICENTERFINDER_H

#include <opencv2/opencv.hpp>

struct center_data_t {
    cv::Point2f wrapperCenter {-1, -1};
    cv::Point2f coreCenter {-1, -1};
};

std::ostream &operator <<(std::ostream &o, const center_data_t &data);

class ICenterFinder {
public:
    ICenterFinder() = default;
    virtual ~ICenterFinder() = default;
    virtual void find(const cv::Mat &image) = 0;
    center_data_t result() const;

protected:
    center_data_t _result;
    virtual cv::Mat preprocessing(const cv::Mat &image);

private:
    cv::Mat _image;
    ICenterFinder(const ICenterFinder &) = delete;
    ICenterFinder &operator = (const ICenterFinder &) = delete;
};

#endif //CENTER_FINDER_ICENTERFINDER_H
