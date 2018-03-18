#ifndef IMG_TRANSFORMATOR_H
#define IMG_TRANSFORMATOR_H

class ImgTransformator
{
public:
    ImgTransformator(const QPixmap& src, const QPolygonF& area);
    QPixmap get(int width, int height);

private:
    cv::Mat _src;
    std::vector<cv::Point2f> _area;
};

#endif // IMG_TRANSFORMATOR_H
