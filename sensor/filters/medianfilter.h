#ifndef MEDIANFILTER_H
#define MEDIANFILTER_H
#include "../ifilter.h"
#include <QVector>

class MedianFilter : public IFilter
{
public:
    MedianFilter(int win=5):m_win(win){}
    SensorData apply(const SensorData &input) override;
private:
    int m_win;
    QVector<float> m_buf;
};

#endif // MEDIANFILTER_H
