#ifndef BUSINESSOBSERVER_H
#define BUSINESSOBSERVER_H
#include "iobserver.h"
#include <QDebug>

class BusinessObserver : public IObserver
{
public:
    void onSensorUpdated(const SensorData &data) override{
        //业务逻辑：温度高于30℃告警
        if(data.value > 30.0f){
            qDebug() << "[Business Alarm] Temperature OVER THRESHOLD! " << data.value;
        }else{
            qDebug() << "[Business Calc] temperature normal:" << data.value;
        }
    }
};

#endif // BUSINESSOBSERVER_H
