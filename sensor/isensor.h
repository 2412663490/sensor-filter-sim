#ifndef ISENSOR_H
#define ISENSOR_H
#include <QVariant>

struct SensorData{
    qint64 timestamp;
    float value;
};

class ISensor
{
public:
    virtual ~ISensor() = default;
    virtual bool init() = 0;
    virtual bool readRaw(SensorData& out) = 0;
};

#endif // ISENSOR_H
