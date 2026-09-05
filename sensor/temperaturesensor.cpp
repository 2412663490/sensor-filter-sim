//temperaturesensor.cpp
#include "temperaturesensor.h"
#include <QDateTime>

bool TemperatureSensor::init()
{
    return m_drv.halInit();
}

bool TemperatureSensor::readRaw(SensorData &out)
{
    float val;
    bool ok = m_drv.halReadTemp(val);
    if(!ok) return false;
    out.timestamp = QDateTime::currentMSecsSinceEpoch();
    out.value = val;
    return true;
}
