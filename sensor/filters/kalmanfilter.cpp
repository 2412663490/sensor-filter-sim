//kalmanfilter.cpp
#include "kalmanfilter.h"

KalmanFilter::KalmanFilter(float q, float r):m_q(q),m_r(r),m_x(0),m_p(0)
{}

SensorData KalmanFilter::apply(const SensorData &input)
{
    float z = input.value;
    if(m_first){
        m_x = z;
        m_p = 1.0f;
        m_first = false;
    }else{
        //预测
        m_p += m_q;
        //更新
        float k = m_p/(m_p + m_r);
        m_x = m_x + k*(z - m_x);
        m_p = (1.0f -k)*m_p;
    }
    SensorData out = input;
    out.value = m_x;
    return out;
}
