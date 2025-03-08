#ifndef TIMELINECANVAS_H
#define TIMELINECANVAS_H

#include "shake.h"
#include <QPainter>
#include <QWidget>

class TimelineCanvas : public QWidget
{
    Q_OBJECT
public:
    TimelineCanvas(QWidget* parent = nullptr);
    void start(int duration, int frequency);
    Shake* getShake();
protected:
    virtual void paintEvent(QPaintEvent *event) override;

private:
    Shake shake;
};

#endif // TIMELINECANVAS_H
