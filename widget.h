#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSpinBox>
#include <QPushButton>
#include "timelinecanvas.h"
#include "shake.h"
#include "imagecanvas.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    TimelineCanvas canvasx, canvasy;
protected:
    virtual void timerEvent(QTimerEvent *event) override;
private slots:
    void shakeButtonClicked();
private:
    void createWidgets();
    void createLayouts();
    QSpinBox* durationSpinBox;
    QSpinBox* frequencySpinBox;
    QSpinBox* amplitudeSpinBox;
    QPushButton* shakeButton;
    ImageCanvas imageCanvas;
};
#endif // WIDGET_H
