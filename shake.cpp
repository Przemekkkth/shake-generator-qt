#include "shake.h"
#include <QRandomGenerator>
#include <QTime>
#include <QDebug>
#include <QRandomGenerator>

Shake::Shake(int duration, int frequency)
    :
    duration(duration),
    frequency(frequency),
    startTime(0),
    t(0),
    isShaking(false)
{
    int sampleCount = (duration / 1000.0) * frequency;
    samples.resize(sampleCount);
    srand(static_cast<unsigned>(time(nullptr)));
    for (auto &sample : samples) {
        sample = QRandomGenerator::global()->generateDouble() * 2.0f - 1.0f;
    }
}

void Shake::start() {
    startTime = getCurrentTimeMillis();
    t = 0;
    isShaking = true;
}

void Shake::update() {
    t = getCurrentTimeMillis() - startTime;
    if (t > duration) isShaking = false;
}

double Shake::amplitude(int timeMs) {
    if (timeMs == -1) {
        if (!isShaking) return 0.0;
        timeMs = t;
    }

    double s = static_cast<double>(timeMs) / 1000.0 * frequency;
    int s0 = static_cast<int>(floor(s));
    int s1 = s0 + 1;

    double k = decay(timeMs);

    return (noise(s0) + (s - s0) * (noise(s1) - noise(s0))) * k;
}

void Shake::setDuration(int newDuration)
{
    duration = newDuration;
}

void Shake::setFrequency(int newFrequency)
{
    frequency = newFrequency;
}

int Shake::getSamplesSize() const
{
    return samples.size();
}

int Shake::getFrequency() const
{
    return frequency;
}

long long Shake::getCurrentTimeMillis()
{
    return static_cast<long long>(std::clock()) * 1000 / CLOCKS_PER_SEC;
}

float Shake::noise(int s) {
    if (s >= static_cast<int>(samples.size())) return 0.0f;
    return samples[s];
}

double Shake::decay(int timeMs) {
    if (timeMs >= duration) return 0.0;
    return static_cast<double>(duration - timeMs) / duration;
}
