#define MV_AVG_WINDOW 16 
#define UINT16_T int


typedef enum{
    E_MV_AVG_1 = 0,
    E_MV_AVG_MAX_INSTANCE
}eMvAvgInstance_t;


void simpleMovingAverage_run(eMvAvgInstance_t mvAvgInstance, UINT16_T data);
double simpleMovingAverage_getAverage(eMvAvgInstance_t mvAvgInstance);