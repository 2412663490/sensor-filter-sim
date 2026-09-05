//medianfilter.cpp
#include "medianfilter.h"
#include <algorithm>

SensorData MedianFilter::apply(const SensorData &input)
{
    m_buf.push_back(input.value);
    if(m_buf.size()>m_win) m_buf.remove(0);
    QVector<float> tmp = m_buf;
    std::sort(tmp.begin(),tmp.end());
    SensorData res = input;
    res.value = tmp[tmp.size()/2];
    return res;
}
