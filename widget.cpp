#include "widget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

const int TIME_INTERVAL = 5; //milisecond

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    createWidgets();
    createLayouts();

    startTimer(TIME_INTERVAL);
    imageCanvas.setMinimumSize(size().width(), size().height());
    imageCanvas.setShake(canvasx.getShake(), canvasy.getShake());
}

Widget::~Widget() {}

void Widget::timerEvent(QTimerEvent *event)
{
    if (canvasx.getShake()->isShaking || canvasy.getShake()->isShaking ) {
        imageCanvas.updateImage();
    }
}

void Widget::shakeButtonClicked()
{
    canvasx.start(durationSpinBox->value(), frequencySpinBox->value());
    canvasy.start(durationSpinBox->value(), frequencySpinBox->value());
    imageCanvas.setAmplitude(amplitudeSpinBox->value() * 10);
}

void Widget::createWidgets()
{
    durationSpinBox  = new QSpinBox(this);
    durationSpinBox->setRange(250, 3000);
    frequencySpinBox = new QSpinBox(this);
    frequencySpinBox->setRange(20, 200);
    amplitudeSpinBox = new QSpinBox(this);
    amplitudeSpinBox->setRange(1, 20);
    shakeButton = new QPushButton(QStringLiteral("Shake!"), this);
    shakeButton->setMinimumHeight(60);
    connect(shakeButton, &QPushButton::clicked, this, &Widget::shakeButtonClicked);
}

void Widget::createLayouts()
{
    QHBoxLayout *hLayout = new QHBoxLayout(this);
    QVBoxLayout *vLayout = new QVBoxLayout(this);
    vLayout->addWidget(new QLabel(QStringLiteral("<h3>X-axis Timeline</h3>")));
    vLayout->addWidget(&canvasx);
    vLayout->addWidget(new QLabel(QStringLiteral("<h3>Y-axis Timeline</h3>")));
    vLayout->addWidget(&canvasy);
    vLayout->addWidget(new QLabel(QStringLiteral("<h3>Settings</h3>")));
    vLayout->addWidget(new QLabel(QStringLiteral("<h4>Duration(milisecond)</h4>")));
    vLayout->addWidget(durationSpinBox);
    vLayout->addWidget(new QLabel(QStringLiteral("<h4>Frequency(hertz)</h4>")));
    vLayout->addWidget(frequencySpinBox);
    vLayout->addWidget(new QLabel(QStringLiteral("<h4>Amplitude(pixel)</h4>")));
    vLayout->addWidget(amplitudeSpinBox);
    vLayout->addWidget(shakeButton);
    hLayout->addLayout(vLayout);

    hLayout->addWidget(&imageCanvas);
    setLayout(hLayout);
}
