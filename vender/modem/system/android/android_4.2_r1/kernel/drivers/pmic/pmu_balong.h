 /*
 * Copyright (C) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
 * foss@huawei.com
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License version 2 and 
 * * only version 2 as published by the Free Software Foundation.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) Neither the name of Huawei nor the names of its contributors may 
 * *    be used to endorse or promote products derived from this software 
 * *    without specific prior written permission.
 * 
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */
#ifndef _PMU_H_
#define _PMU_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <bsp_pmu.h>

struct pmu_dbg_ops{
    void (*pmu_volt_show)(int volt_id);/*所有PMIC统一编码*/
    void (*pmu_volt_state)(void);
    void (*pmu_om_data_show)(void);
    void (*pmu_om_boot_show)(void);
    void (*pmu_exc_state)(void);
    void (*pmu_pmic_info)(void);
};
struct pmu_dbg
{
    u32 info_print_sw;
    struct pmu_dbg_ops dbg_ops[PMIC_BUTTOM];
};
extern struct pmu_dbg g_pmu_dbg;


/*test*/
struct pmu_test_ops{
    int (*pmu_volt_onoff_test)(u32 uctimes);/*电压源开关测试*/
    int (*pmu_volt_setget_test)(u32 uctimes);/*电压源设置电压测试*/
    int (*pmu_volt_mode_test)(u32 uctimes);/*电压源设置eco模式测试*/
    int (*pmu_mutex_onecore_test)(u32 uctimes);/*核内互斥测试*/
    int (*pmu_mutex_cores_test)(u32 uctimes);/*核间互斥测试*/
    int (*pmu_volt_table_test)(u32 uctimes);/*ddr电压表安全性测试*/
    int (*pmu_dr_onoff_test)(u32 uctimes);/*电流源开关测试*/
    int (*pmu_dr_setget_test)(u32 uctimes);/*电流源设置电流测试*/
    int (*pmu_dr_mode_test)(u32 uctimes);/*电流源设置模式测试*/
};
struct pmu_test
{
    u32 test_sw;
    struct pmu_test_ops test_ops[PMIC_BUTTOM];
};

/*print*/
#if defined(__KERNEL__) || defined(__VXWORKS__)
#define  pmic_print_error(fmt, ...)    (bsp_trace(BSP_LOG_LEVEL_ERROR, BSP_MODU_PMU, "[pmu]: <%s> "fmt, __FUNCTION__, ##__VA_ARGS__))
/*#define  pmic_print_info(fmt, ...)      (bsp_trace(BSP_LOG_LEVEL_INFO, BSP_MODU_PMU, "[pmu]: <%s> "fmt"\n", __FUNCTION__, ##__VA_ARGS__))*/

#elif defined(__CMSIS_RTOS)
extern void printk(const char *fmt, ...);
#define  pmic_print_error(fmt, ...)    (printk("[pmu]: <%s> "fmt, __FUNCTION__, ##__VA_ARGS__))
/*#define  pmic_print_info(fmt, ...)      (printk("[pmu]: <%s> "fmt"\n", __FUNCTION__, ##__VA_ARGS__))*/
#elif defined(__FASTBOOT__)
/*#define  pmic_print_error(fmt, ...)    (cprintf(fmt"\n", ...))*/
#define  pmic_print_error(fmt, ...)    (cprintf("[pmu]: <%s> "fmt, __FUNCTION__, ##__VA_ARGS__))
#endif

#if defined(__FASTBOOT__)
#define  pmic_print_info(fmt, ...) \
do {                               \
    /*    pmic_print_error(fmt, ##__VA_ARGS__);*/\
} while (0)
#else
#define  pmic_print_info(fmt, ...) \
do {                               \
    if (g_pmu_dbg.info_print_sw)    \
        pmic_print_error(fmt, ##__VA_ARGS__);\
} while (0)
#endif

/*函数声明*/
/*****************************************************************************
 函 数 名  : bsp_pmu_dbg_register
 功能描述  : pmu模块dbg信息注册
 输入参数  : void
 输出参数  : 无
 返 回 值  : 注册成功或失败
 调用函数  :
 被调函数  : 异常定位
*****************************************************************************/
int bsp_pmu_dbg_register(pmic_id_e pmic_id,struct pmu_dbg_ops ops_func);
/*****************************************************************************
 函 数 名  : bsp_pmu_test_register
 功能描述  : pmu模块test信息注册
 输入参数  : void
 输出参数  : 无
 返 回 值  : 注册成功或失败
 调用函数  :
 被调函数  : 异常定位
*****************************************************************************/
int bsp_pmu_test_register(pmic_id_e pmic_id,struct pmu_test_ops ops_func);

#ifdef CONFIG_PMIC_HI6451
/*****************************************************************************
 函 数 名  : bsp_hi6451_debug_init
 功能描述  : hi6451 debug模块的初始化
 输入参数  : void
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  : 异常定位
*****************************************************************************/
void bsp_hi6451_debug_init(void);
/*****************************************************************************
 函 数 名  : bsp_hi6451_test_init
 功能描述  : hi6451 test模块的初始化
 输入参数  : void
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  : 测试
*****************************************************************************/
int bsp_hi6451_test_init(void);
#if defined(__KERNEL__)
extern int hi6451_get_boot_state(void);
#endif
#endif
#ifdef CONFIG_PMIC_HI6551
/*异常存储数据*/
extern  u8 pmu_hi6551_om_boot[];
extern  u8 pmu_hi6551_om_data[];
/*****************************************************************************
 函 数 名  : bsp_hi6551_debug_init
 功能描述  : hi6551 debug模块的初始化
 输入参数  : void
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  : 异常定位
*****************************************************************************/
void bsp_hi6551_debug_init(void);
/*****************************************************************************
 函 数 名  : bsp_hi6551_test_init
 功能描述  : hi6551 test模块的初始化
 输入参数  : void
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  : 异常定位
*****************************************************************************/
int bsp_hi6551_test_init(void);
//void bsp_hi6551_sim_volt_disable(u32 sim_id);
int hi6551_sim_upres_disable(u32 sim_id);


#if defined(__KERNEL__)
extern int hi6551_get_boot_state(void);
#endif
#endif

#ifdef CONFIG_PMIC_HI6559
/* 异常存储数据 */
extern  u8 pmu_hi6559_om_boot[];
extern  u8 pmu_hi6559_om_data[];
/*****************************************************************************
 函 数 名  : bsp_hi6559_debug_init
 功能描述  : hi6559 debug模块的初始化
 输入参数  : void
 输出参数  : 无
 返 回 值  : 无
*****************************************************************************/
void bsp_hi6559_debug_init(void);

/*****************************************************************************
 函 数 名  : bsp_hi6559_test_init
 功能描述  : hi6559 test模块的初始化
 输入参数  : void
 输出参数  : 无
 返 回 值  : 无
*****************************************************************************/
s32 bsp_hi6559_test_init(void);

/*****************************************************************************
 函 数 名  : hi6559_sim_upres_disable
 功能描述  : 
 输入参数  : @sim_id:sim卡ID
 输出参数  : 无
 返 回 值  : 
*****************************************************************************/
s32 hi6559_sim_upres_disable(u32 sim_id);


#if defined(__KERNEL__)
extern int hi6559_get_boot_state(void);
#endif
#endif


#if (defined(CONFIG_PASTAR) && defined(__VXWORKS__))
/*****************************************************************************
 函 数 名  : bsp_hi6561_test_init
 功能描述  : hi6561 test模块的初始化
 输入参数  : void
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  : 异常定位
*****************************************************************************/
void bsp_hi6561_test_init(void);
#endif
#ifdef __cplusplus
}
#endif

#endif /* end #define _PMU_TEST_H_*/

