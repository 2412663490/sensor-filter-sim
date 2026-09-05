#ifndef KALMANFILTER_H
#define KALMANFILTER_H
#include "../ifilter.h"

class KalmanFilter : public IFilter
{
public:
    KalmanFilter(float q=0.01f, float r=0.1f);
    SensorData apply(const SensorData &input) override;
private:
    float m_q;
    float m_r;
    float m_x;
    float m_p;
    bool m_first{true};
};

#endif // KALMANFILTER_H
