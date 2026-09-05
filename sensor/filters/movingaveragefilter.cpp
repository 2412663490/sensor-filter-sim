//movingaveragefilter.cpp
#include "movingaveragefilter.h"

SensorData MovingAverageFilter::apply(const SensorData &input)
{
    m_buf.enqueue(input.value);
    if(m_buf.size()>m_win) m_buf.dequeue();
    float sum=0;
    for(auto v:m_buf) sum+=v;
    SensorData res = input;
    res.value = sum/m_buf.size();
    return res;
}
