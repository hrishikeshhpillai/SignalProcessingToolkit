#include <stdio.h>
#include "exponentialMovingAverage.h"


#define EMA_ALPHA 0.8



typedef struct
{
    double prevValue;
    double emaValue;
}sEma_t;


sEma_t emaInstanceArr[E_MAX_EMA_INSTANCE] = 
{
    {0, 0},
};



void exponentialMovingAverage_run(eEmaInstance_t emaInstance, UINT16_T data)
{
    emaInstanceArr[emaInstance].emaValue = EMA_ALPHA * data + (1 - EMA_ALPHA) * emaInstanceArr[emaInstance].prevValue;
    emaInstanceArr[emaInstance].prevValue = emaInstanceArr[emaInstance].emaValue;
}


double exponentialMovingAverage_getAverage(eEmaInstance_t emaInstance)
{
    return emaInstanceArr[emaInstance].emaValue;
}