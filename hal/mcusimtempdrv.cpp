#include "mcusimtempdrv.h"
#include <random>

bool McuSimTempDrv::halInit()
{
    return true;
}

bool McuSimTempDrv::halReadTemp(float &out)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(-1.0f, 1.0f);

    float base = 25.0f;
    float noise = dist(gen);
    out = base + noise;
    return true;
}
