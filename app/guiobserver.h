#ifndef GUIOBSERVER_H
#define GUIOBSERVER_H
#include "iobserver.h"
#include <QDebug>

class GuiObserver : public IObserver
{
public:
    void onSensorUpdated(const SensorData &data) override{
        qDebug() << "[GUI Display] ts:" << data.timestamp << " temp=" << data.value << " ℃";
    }
};

#endif // GUIOBSERVER_H
