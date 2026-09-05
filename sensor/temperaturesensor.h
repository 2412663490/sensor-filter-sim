//temperaturesensor.h
#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H
#include "isensor.h"
#include "../sim/mcu_sim_drv.h"

class TemperatureSensor : public ISensor
{
public:
    bool init() override;
    bool readRaw(SensorData &out) override;
private:
    McuTempDrv m_drv;
};

#endif // TEMPERATURESENSOR_H
