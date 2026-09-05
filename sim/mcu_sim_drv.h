#ifndef MCU_SIM_DRV_H
#define MCU_SIM_DRV_H

class McuTempDrv
{
public:
    bool halInit();
    bool halReadTemp(float& out);
};

#endif // MCU_SIM_DRV_H
