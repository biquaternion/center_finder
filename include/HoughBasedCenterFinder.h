#ifndef CENTER_FINDER_HOUGHBASEDCENTERFINDER_H
#define CENTER_FINDER_HOUGHBASEDCENTERFINDER_H

#include "ICenterFinder.h"

class HoughBasedCenterFinder : public ICenterFinder
{
public:
    HoughBasedCenterFinder();
    ~HoughBasedCenterFinder() override = default;
    void find(const cv::Mat &image) override;
private:
    cv::Mat preprocessing(const cv::Mat &image) override;
};

#endif //CENTER_FINDER_HOUGHBASEDCENTERFINDER_H
