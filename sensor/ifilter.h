#ifndef IFILTER_H
#define IFILTER_H
#include "isensor.h"

class IFilter
{
public:
    virtual ~IFilter() = default;
    virtual SensorData apply(const SensorData& input) = 0;
};

#endif // IFILTER_H
