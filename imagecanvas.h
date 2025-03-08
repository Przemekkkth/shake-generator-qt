#ifndef IMAGECANVAS_H
#define IMAGECANVAS_H

#include <QWidget>
#include <QImage>
#include "shake.h"

class ImageCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit ImageCanvas(QWidget *parent = nullptr);
    void setShake(Shake *shakex, Shake *shakey);
    void setAmplitude(int newAmplitude);
    void updateImage();
signals:

protected:
    virtual void paintEvent(QPaintEvent *event) override;
private:
    QImage m_image;
    Shake *shakeX, *shakeY;
    int x, y;
    int amplitude;
};

#endif // IMAGECANVAS_H
