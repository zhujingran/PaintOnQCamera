#include "videosurface.h"
#include <QImage>
#include <QPixmap>
#include <QDebug>
VideoSurface::VideoSurface()
{

}

VideoSurface::~VideoSurface()
{

}

QList<QVideoFrame::PixelFormat> VideoSurface::supportedPixelFormats(
        QAbstractVideoBuffer::HandleType type) const
{
    QList<QVideoFrame::PixelFormat> list_pixel_formats;
    list_pixel_formats << QVideoFrame::Format_ABGR32
                       << QVideoFrame::Format_ARGB32_Premultiplied
                       << QVideoFrame::Format_RGB32
                       << QVideoFrame::Format_RGB24
                       << QVideoFrame::Format_RGB565
                       << QVideoFrame::Format_RGB555
                       << QVideoFrame::Format_ARGB8565_Premultiplied
                       << QVideoFrame::Format_BGRA32
                       << QVideoFrame::Format_BGRA32_Premultiplied
                       << QVideoFrame::Format_BGR32
                       << QVideoFrame::Format_BGR24
                       << QVideoFrame::Format_BGR565
                       << QVideoFrame::Format_BGR555
                       << QVideoFrame::Format_BGRA5658_Premultiplied
                       << QVideoFrame::Format_AYUV444
                       << QVideoFrame::Format_AYUV444_Premultiplied
                       << QVideoFrame::Format_YUV444
                       << QVideoFrame::Format_YUV420P
                       << QVideoFrame::Format_YV12
                       << QVideoFrame::Format_UYVY
                       << QVideoFrame::Format_YUYV
                       << QVideoFrame::Format_NV12
                       << QVideoFrame::Format_NV21
                       << QVideoFrame::Format_IMC1
                       << QVideoFrame::Format_IMC2
                       << QVideoFrame::Format_IMC3
                       << QVideoFrame::Format_IMC4
                       << QVideoFrame::Format_Y8
                       << QVideoFrame::Format_Y16
                       << QVideoFrame::Format_Jpeg
                       << QVideoFrame::Format_CameraRaw
                       << QVideoFrame::Format_AdobeDng;
    return list_pixel_formats;
};

bool VideoSurface::present(const QVideoFrame &frame)
{
    if(frame.isValid())
    {
        QImage img = frame.image();
        QPixmap pixmap = QPixmap::fromImage(img);
        emit image(pixmap);

        return true;
    }
    return false;
};
