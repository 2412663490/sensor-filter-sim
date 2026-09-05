#ifndef SENSORMANAGER_H
#define SENSORMANAGER_H
#include "isensor.h"
#include "ifilter.h"
#include "../app/iobserver.h"
#include <QList>

class SensorManager
{
public:
    void setSensor(ISensor* s){ m_sensor = s; }
    void addFilter(IFilter* f){ m_filters.append(f); }
    void addObserver(IObserver* o){ m_observers.append(o); }

    void sampleOnce(){
        if(!m_sensor) return;
        SensorData raw;
        if(!m_sensor->readRaw(raw)) return;

        SensorData processed = raw;
        for(auto f : m_filters){
            processed = f->apply(processed);
        }
        //通知所有订阅者(GUI/MQTT/Business)
        for(auto obs : m_observers){
            obs->onSensorUpdated(processed);
        }
    }

private:
    ISensor* m_sensor = nullptr;
    QList<IFilter*> m_filters;
    QList<IObserver*> m_observers;
};

#endif // SENSORMANAGER_H
