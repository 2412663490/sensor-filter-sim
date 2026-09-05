#ifndef ITEMPDRV_H
#define ITEMPDRV_H

//板级温度驱动抽象接口：不同MCU平台各自提供实现
class ITempDrv
{
public:
    virtual ~ITempDrv() = default;
    virtual bool halInit() = 0;
    virtual bool halReadTemp(float& out) = 0;
};

#endif // ITEMPDRV_H
