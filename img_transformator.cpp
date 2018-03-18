#include "img_transformator.h"
#include "asm_open_cv.h"

namespace
{
    std::vector<cv::Point2f> makeNeedArea(int width, int height)
    {
        return {
            { 0.0f, 0.0f },
            { width - 1.0f, 0.0f },
            { width - 1.0f, height - 1.0f },
            { 0.0f, height - 1.0f },
        };
    }
}

ImgTransformator::ImgTransformator(const QPixmap& src, const QPolygonF &area)
    : _src{ ASM::QPixmapToCvMat(src) }
{
    for(const auto& point : area)
        _area.emplace_back(point.x(), point.y());
}

QPixmap ImgTransformator::get(int width, int height)
{
    const cv::Size size{ width, height };
    cv::Mat imgDst = cv::Mat::zeros(size, CV_8UC3);
    const std::vector<cv::Point2f> _needArea = ::makeNeedArea(width, height);

    try
    {
        cv::Mat homograhy = cv::findHomography(_area, _needArea);
        cv::warpPerspective(_src, imgDst, homograhy, size);
    }
    catch(const cv::Exception& ex)
    {
        std::ignore = ex;
        return {};
    }

    return ASM::cvMatToQPixmap(imgDst);
}
