#define UINT16_T int


typedef enum
{
    E_EMA_1 = 0,
    E_MAX_EMA_INSTANCE
}eEmaInstance_t;



void exponentialMovingAverage_run(eEmaInstance_t emaInstance, UINT16_T data);
double exponentialMovingAverage_getAverage(eEmaInstance_t emaInstance);