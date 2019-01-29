#ifndef __MAIN_H_
#define __MAIN_H_

#include "mico.h"
#include "MiCOKit_EXT.h"

#define ZTC1_NAME "zTC1"

#define PLUG_NAME_LENGTH 32
#define PLUG_NUM 6              //插座数量
#define PLUG_TIME_TASK_NUM 5    //每个插座最多5组定时任务



#define Led         MICO_GPIO_5
#define Button      MICO_GPIO_23

#define Relay_0     MICO_GPIO_6
#define Relay_1     MICO_GPIO_7
#define Relay_2     MICO_GPIO_8
#define Relay_3     MICO_GPIO_9
#define Relay_4     MICO_GPIO_10
#define Relay_5     MICO_GPIO_18
#define Relay_NUM   PLUG_NUM




typedef struct {
    char hour;      //小时
    char minute;    //分钟
    uint8_t repeat; //bit7:一次   bit6-0:周日-周一
    char on;    //开关

} user_plug_task_config_t;

typedef struct {
    char name[PLUG_NAME_LENGTH];
    char idx;
    user_plug_task_config_t task[PLUG_TIME_TASK_NUM];

} user_plug_config_t;

//用户保存参数结构体
typedef struct {
    char idx;
    user_plug_config_t plug[PLUG_NUM];
} user_config_t;

extern system_config_t * sys_config;
extern user_config_t * user_config;

extern mico_gpio_t Relay[Relay_NUM];

#endif
