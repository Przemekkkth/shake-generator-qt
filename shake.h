#ifndef SHAKE_H
#define SHAKE_H
#include <vector>

class Shake
{
public:
    Shake(int duration = 2000, int frequency = 40);
    void start();
    void update();

    double amplitude(int newElapsedTime = -1);

    void setDuration(int newDuration);
    void setFrequency(int newFrequency);
    int getSamplesSize() const;
    int getFrequency() const;
    bool isShaking;
private:
    static long long getCurrentTimeMillis();
    float noise(int idx);
    double decay(int timeMs);

    int duration;
    int frequency;
    std::vector<float> samples;
    long long startTime;
    int t;
};

#endif // SHAKE_H
