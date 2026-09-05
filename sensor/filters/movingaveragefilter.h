#ifndef MOVINGAVERAGEFILTER_H
#define MOVINGAVERAGEFILTER_H
#include "../ifilter.h"
#include <QQueue>

class MovingAverageFilter : public IFilter
{
public:
    MovingAverageFilter(int winSize=5):m_win(winSize){}
    SensorData apply(const SensorData &input) override;
private:
    int m_win;
    QQueue<float> m_buf;
};

#endif // MOVINGAVERAGEFILTER_H
