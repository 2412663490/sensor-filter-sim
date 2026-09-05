#ifndef IOBSERVER_H
#define IOBSERVER_H
#include "../sensor/isensor.h"

class IObserver
{
public:
    virtual ~IObserver() = default;
    virtual void onSensorUpdated(const SensorData& data) = 0;
};

#endif // IOBSERVER_H
