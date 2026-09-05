#include <QCoreApplication>
#include <QTimer>
#include "sensor/temperaturesensor.h"
#include "sensor/sensormanager.h"
#include "sensor/filters/movingaveragefilter.h"
#include "sensor/filters/medianfilter.h"
#include "sensor/filters/kalmanfilter.h"
#include "app/guiobserver.h"
#include "app/mqttobserver.h"
#include "app/businessobserver.h"
#include "hal/mcusimtempdrv.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //1. 创建sensor实例：注入MCU驱动，换平台只需替换注入的驱动实现
    McuSimTempDrv simDrv;
    TemperatureSensor tempSensor(&simDrv);
    tempSensor.init();

    //2. SensorManager
    SensorManager mgr;
    mgr.setSensor(&tempSensor);

    //3. 灵活配置滤波器链，可自由增删组合
    mgr.addFilter(new MovingAverageFilter(5));
    mgr.addFilter(new KalmanFilter());
    //mgr.addFilter(new MedianFilter(5)); //需要时打开

    //4. 挂载应用层观察者：GUI / MQTT / 业务计算，完全解耦
    mgr.addObserver(new GuiObserver());
    mgr.addObserver(new MqttObserver());
    mgr.addObserver(new BusinessObserver());

    //定时采样，200ms一次
    QTimer timer;
    QObject::connect(&timer,&QTimer::timeout,[&](){
        mgr.sampleOnce();
    });
    timer.start(200);

    return a.exec();
}
