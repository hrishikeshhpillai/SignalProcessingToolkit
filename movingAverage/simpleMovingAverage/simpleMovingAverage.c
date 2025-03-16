#include <stdio.h>
#include <stdbool.h>
#include "simpleMovingAverage.h"



typedef struct{
    double mvBuff[MV_AVG_WINDOW];
    double sum; 
    double average;
    bool isFirstInsert;
}sMvAvg_t;



sMvAvg_t mvAvgInstanceArr[E_MV_AVG_MAX_INSTANCE] = 
{
    {{0}, 0, 0},
};


void simpleMovingAverage_run(eMvAvgInstance_t mvAvgInstance, UINT16_T data)
{

    static int mvAvgIndex = 0;

    if(mvAvgInstanceArr[mvAvgInstance].isFirstInsert == false)
    {
        for(UINT16_T mvAvgIter = 0; mvAvgIter < MV_AVG_WINDOW; mvAvgIter++)
        {
            mvAvgInstanceArr[mvAvgInstance].mvBuff[mvAvgIter] = data;
        }
        mvAvgInstanceArr[mvAvgInstance].sum = (mvAvgInstanceArr[mvAvgInstance].mvBuff[mvAvgIndex] * MV_AVG_WINDOW);

    }
    else
    {
        mvAvgInstanceArr[mvAvgInstance].sum = mvAvgInstanceArr[mvAvgInstance].sum - mvAvgInstanceArr[mvAvgInstance].mvBuff[mvAvgIndex] + data;
        mvAvgInstanceArr[mvAvgInstance].mvBuff[mvAvgIndex++] = data;
        mvAvgIndex = mvAvgIndex%MV_AVG_WINDOW;
    }
    mvAvgInstanceArr[mvAvgInstance].average = (mvAvgInstanceArr[mvAvgInstance].sum / MV_AVG_WINDOW);

}

double simpleMovingAverage_getAverage(eMvAvgInstance_t mvAvgInstance)
{
    return mvAvgInstanceArr[mvAvgInstance].average;
}


double simpleMovingAverage_getSum(eMvAvgInstance_t mvAvgInstance)
{
    return mvAvgInstanceArr[mvAvgInstance].sum;
}
