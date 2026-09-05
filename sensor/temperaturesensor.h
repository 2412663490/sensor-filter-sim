//temperaturesensor.h
#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H
#include "isensor.h"
#include "../hal/itempdrv.h"

//传感器实现案例：温度传感器。依赖注入板级驱动，与具体MCU解耦
class TemperatureSensor : public ISensor
{
public:
    explicit TemperatureSensor(ITempDrv* drv) : m_drv(drv) {}
    bool init() override;
    bool readRaw(SensorData &out) override;
private:
    ITempDrv* m_drv;
};

#endif // TEMPERATURESENSOR_H
