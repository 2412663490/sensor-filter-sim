#ifndef MQTTOBSERVER_H
#define MQTTOBSERVER_H
#include "iobserver.h"
#include <QDebug>

class MqttObserver : public IObserver
{
public:
    void onSensorUpdated(const SensorData &data) override{
        //此处真实代码：组装json publish到MQTT topic "sensor/temp"
        qDebug() << "[MQTT Publish] topic:sensor/temp value:" << data.value;
    }
};

#endif // MQTTOBSERVER_H
