QT += core network
QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        main.cpp \
        sensor/temperaturesensor.cpp \
        sensor/filters/movingaveragefilter.cpp \
        sensor/filters/medianfilter.cpp \
        sensor/filters/kalmanfilter.cpp \
        hal/mcusimtempdrv.cpp

HEADERS += \
        sensor/isensor.h \
        sensor/temperaturesensor.h \
        sensor/ifilter.h \
        sensor/sensormanager.h \
        sensor/filters/movingaveragefilter.h \
        sensor/filters/medianfilter.h \
        sensor/filters/kalmanfilter.h \
        app/iobserver.h \
        app/guiobserver.h \
        app/mqttobserver.h \
        app/businessobserver.h \
        hal/itempdrv.h \
        hal/mcusimtempdrv.h

