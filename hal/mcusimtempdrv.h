#ifndef MCUSIMTEMPDRV_H
#define MCUSIMTEMPDRV_H
#include "itempdrv.h"

//PC模拟实现：模拟MCU温度驱动（25℃±1℃随机噪声）
class McuSimTempDrv : public ITempDrv
{
public:
    bool halInit() override;
    bool halReadTemp(float& out) override;
};

#endif // MCUSIMTEMPDRV_H
