#include "imagecanvas.h"
#include <QPainter>

ImageCanvas::ImageCanvas(QWidget *parent)
    : QWidget{parent}, x(0), y(0), amplitude(0)
{
    m_image.load(QStringLiteral(":/assets/image.jpg"));
}

void ImageCanvas::setShake(Shake *shakex, Shake *shakey)
{
    shakeX = shakex;
    shakeY = shakey;
}

void ImageCanvas::setAmplitude(int newAmplitude)
{
    amplitude = newAmplitude;
}

void ImageCanvas::updateImage()
{
    shakeX->update();
    shakeY->update();
    x = shakeX->amplitude() * amplitude;
    y = shakeY->amplitude() * amplitude;
    update();
}

void ImageCanvas::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.setBrush(Qt::black);
    p.drawRect(rect());
    p.drawImage(x, y, m_image);
}
