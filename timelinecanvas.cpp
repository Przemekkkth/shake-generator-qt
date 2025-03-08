#include "timelinecanvas.h"
#include <QPainter>
#include <QPainterPath>

TimelineCanvas::TimelineCanvas(QWidget *parent)
    :
    QWidget(parent)
{
    setMinimumSize(QSize(360, 120));
}

void TimelineCanvas::start(int duration, int frequency)
{
    shake = Shake(duration, frequency);
    shake.start();
    update();
}

Shake* TimelineCanvas::getShake()
{
    return &shake;
}

void TimelineCanvas::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    const float WIDTH = size().width();
    const float HEIGHT = size().height();
    p.setBrush(Qt::white);
    p.drawRect(rect());

    p.setPen(Qt::black);
    p.setBrush(Qt::NoBrush);
    p.drawLine(0, HEIGHT / 2, WIDTH, HEIGHT / 2);
    p.setPen(QPen(QBrush(Qt::black), 2));
    QPainterPath path;
    path.moveTo(0, HEIGHT / 2);
    for (int i = 1; i < shake.getSamplesSize(); ++i) {
        double t = static_cast<float>(i) / static_cast<float>(shake.getFrequency()) * 1000.0f;
        double x = static_cast<float>(i) / static_cast<float>(shake.getSamplesSize()) * WIDTH;
        double y = (shake.amplitude(t) * HEIGHT + HEIGHT) / 2.0f;

        path.lineTo(x, y);
    }

    p.drawPath(path);
}
