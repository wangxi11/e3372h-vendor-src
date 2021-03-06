/******************************************************************************/
/*  Copyright (C), 2007-2013, Hisilicon Technologies Co., Ltd. */

#include "balongv7r2/types.h"
#include "osl_bio.h"
#include "hi_base.h"
#include "hi_syscrg.h"
#include "hi_i2c.h"
#include "bsp_hardtimer.h"
#include "designware_i2c.h"

#define MAX_NAME_LEN 48
#define MAX_SLAVE_NUM 20
#define TEST_SLAVE_ID	0x6b
#define I2C_TEST_PASS 0
#define I2C_TEST_FAILE -1

struct designware_i2c_ctrl
{
    u32		regs;/*register base addr*/
    char* 	master_name;
    u8		i2c_slave_list[MAX_SLAVE_NUM];/*slave list*/
    u8		slave_num;
    u8		master_number;
    u8		reserved[2];
};

static struct designware_i2c_ctrl v7r11_i2c0;
static struct designware_i2c_ctrl v7r11_i2c1;
void designware_i2c_clk_enable(enum i2c_master i2c)
{
    if(i2c ==I2C_MASTER0)
    {
        set_hi_crg_clken1_i2c0_clk_en(1);
    }
    else if(i2c ==I2C_MASTER1)
    {
        set_hi_crg_clken1_i2c1_clk_en(1);
    }
    else
    {
        cprintf(" enable number is error %d\n",i2c);
    }
}
void designware_i2c_clk_disable(enum i2c_master i2c)
{
    if(i2c ==I2C_MASTER0)
    {
        set_hi_crg_clkdis1_i2c0_clk_dis(1);
    }
    else if(i2c ==I2C_MASTER1)
    {
        set_hi_crg_clkdis1_i2c1_clk_dis(1);
    }
    else
    {
        cprintf(" disable number is error %d\n",i2c);
    }
}
int bsp_i2c_slave_register(enum i2c_master i2c,u32 slave_id)
{
    int slave_num;
    int idx;
    struct designware_i2c_ctrl *i2c_master_cur;

    if(I2C_MASTER0==i2c)
    {
        i2c_master_cur=&v7r11_i2c0;
    }
    else
    {
        i2c_master_cur=&v7r11_i2c1;
        if(I2C_MASTER1!=i2c)
        {
        	cprintf("there are i2c_master0 or i2c_master1,don't have i2c_master%d\n",i2c);
        	return I2C_ERROR;
        }
    }

    slave_num=i2c_master_cur->slave_num;

    if(slave_num>=MAX_SLAVE_NUM)
    {
        cprintf("master has %d slaves,add salve fail!\n",slave_num);
        return I2C_ERROR;
    }

    /*ensure one slave_id can't register a master with muti times*/
    for(idx=0;idx<slave_num;idx++)
    {
        if(slave_id==i2c_master_cur->i2c_slave_list[idx])
        {
        	cprintf("the slave has registed!\n");
        	return I2C_ERROR;
        }
    }
    i2c_master_cur->i2c_slave_list[slave_num]=slave_id;
    i2c_master_cur->slave_num=slave_num+1;
    return I2C_OK;

}


/*find i2c master for slave*/
struct designware_i2c_ctrl *find_i2c_ctrl(u8 slave_id)
{
    int idx;/*i2c slave index*/
    struct designware_i2c_ctrl *i2c_master=NULL;

    i2c_master=&v7r11_i2c0;
    for(idx=0;idx<i2c_master->slave_num;idx++)
    {
        if(i2c_master->i2c_slave_list[idx]==slave_id)
        {
            //cprintf("the 0x%x i2c master is %s\n",slave_id,i2c_master->master_name);
            return i2c_master;
        }
    }
    i2c_master=&v7r11_i2c1;

    for(idx=0;idx<i2c_master->slave_num;idx++)
    {
        if(i2c_master->i2c_slave_list[idx]==slave_id)
        {
            //cprintf("the 0x%x i2c master is %s\n",slave_id,i2c_master->master_name);
            return i2c_master;
        }
    }
    cprintf("can't find the 0x%x slave,may be it didn't have regitstered!\n",slave_id);
    return NULL;

}

/*
 * set_speed - Set the i2c speed mode (standard, high, fast)
 * @i2c_spd:	required i2c speed mode
 *
 * Set the i2c speed mode (standard, high, fast)
 */
static void i2c_set_speed(struct designware_i2c_ctrl *i2c_master,int i2c_spd)
{
    unsigned int cntl;
    unsigned int hcnt, lcnt;
    unsigned int enbl;

    /* to set speed cltr must be disabled */
    enbl = readl(i2c_master->regs+DW_IC_ENABLE);
    enbl &= ~IC_ENABLE_0B;
    writel(enbl, i2c_master->regs+DW_IC_ENABLE);

    cntl = (readl(i2c_master->regs+DW_IC_CON) & (~IC_CON_SPD_MSK));

    switch (i2c_spd) {
    case IC_SPEED_MODE_MAX:
    	cntl |= IC_CON_SPD_HS;
    	hcnt = (IC_CLK * MIN_HS_SCL_HIGHTIME) / NANO_TO_MICRO;
    	writel(hcnt, i2c_master->regs+DW_IC_HS_SCL_HCNT);
    	lcnt = (IC_CLK * MIN_HS_SCL_LOWTIME) / NANO_TO_MICRO;
    	writel(lcnt, i2c_master->regs+DW_IC_HS_SCL_LCNT);
    	break;

    case IC_SPEED_MODE_STANDARD:
    	cntl |= IC_CON_SPD_SS;
    	hcnt = (IC_CLK * MIN_SS_SCL_HIGHTIME) / NANO_TO_MICRO;
    	writel(hcnt, i2c_master->regs+DW_IC_SS_SCL_HCNT);
    	lcnt = (IC_CLK * MIN_SS_SCL_LOWTIME) / NANO_TO_MICRO;
    	writel(lcnt, i2c_master->regs+DW_IC_SS_SCL_LCNT);
    	break;

    case IC_SPEED_MODE_FAST:
    default:
    	cntl |= IC_CON_SPD_FS;
    	hcnt = (IC_CLK * MIN_FS_SCL_HIGHTIME) / NANO_TO_MICRO;
    	writel(hcnt, i2c_master->regs+DW_IC_FS_SCL_HCNT);
    	lcnt = (IC_CLK * MIN_FS_SCL_LOWTIME) / NANO_TO_MICRO;
    	writel(lcnt, i2c_master->regs+DW_IC_FS_SCL_LCNT);
    	break;
    }

    writel(cntl, i2c_master->regs+DW_IC_CON);

    /* Enable back i2c now speed set */
    enbl |= IC_ENABLE_0B;
    writel(enbl, i2c_master->regs+DW_IC_ENABLE);
}

/*
 * i2c_set_bus_speed - Set the i2c speed
 * @speed:	required i2c speed
 *
 * Set the i2c speed.
 */
int designware_i2c_set_speed(struct designware_i2c_ctrl *i2c_master,int speed)
{
    if (speed >= I2C_MAX_SPEED)
    {
        i2c_set_speed(i2c_master,IC_SPEED_MODE_MAX);
    }
    else if (speed >= I2C_FAST_SPEED)
    {
        i2c_set_speed(i2c_master,IC_SPEED_MODE_FAST);
    }
    else
    {
        i2c_set_speed(i2c_master,IC_SPEED_MODE_STANDARD);
    }
    return 0;
}

/*
 * i2c_init - Init function
 * @speed:	required i2c speed
 * @slaveadd:	slave address for the device
 *
 * Initialization function.
 */
void designware_i2c_init(enum i2c_master i2c,int speed)
{
    unsigned int enbl;
    struct designware_i2c_ctrl *i2c_master_cur=NULL;
    designware_i2c_clk_enable(i2c);
    if(I2C_MASTER0==i2c)
    {
        i2c_master_cur=&v7r11_i2c0;
    }
    else
    {
        i2c_master_cur=&v7r11_i2c1;
        if(I2C_MASTER1!=i2c)
        {
            cprintf("there are i2c_master0 or i2c_master1,don't have i2c_master%d\n",i2c);
            return ;
        }
    }

    /* Disable i2c */
    enbl = readl(i2c_master_cur->regs+DW_IC_ENABLE);
    enbl &= ~IC_ENABLE_0B;
    writel(enbl, i2c_master_cur->regs+DW_IC_ENABLE);

    writel((IC_CON_SD | IC_CON_SPD_FS | IC_CON_MM), i2c_master_cur->regs+DW_IC_CON);
    writel(IC_RX_TL, i2c_master_cur->regs+DW_IC_RX_TL);
    writel(IC_TX_TL, i2c_master_cur->regs+DW_IC_RX_TL);
    designware_i2c_set_speed(i2c_master_cur,speed);
    /*���һ��DW_IC_CLR_ACTIVITY�жϱ�־λ*/
    readl(i2c_master_cur->regs+DW_IC_CLR_ACTIVITY);
    writel(IC_STOP_DET, i2c_master_cur->regs+DW_IC_INTR_MASK);
    /* Enable i2c */
    enbl = readl(i2c_master_cur->regs+DW_IC_ENABLE);
    enbl |= IC_ENABLE_0B;
    writel(enbl, i2c_master_cur->regs+DW_IC_ENABLE);
    designware_i2c_clk_disable(i2c);
}

/*
 * i2c_setaddress - Sets the target slave address
 * @i2c_addr:	target i2c address
 *
 * Sets the target slave address.
 */
static void designware_i2c_setaddress(struct designware_i2c_ctrl *i2c_master,unsigned int i2c_addr)
{
    unsigned int enbl;
    /* Disable i2c */
    enbl = readl(i2c_master->regs+DW_IC_ENABLE);
    enbl &= ~IC_ENABLE_0B;
    writel(enbl, i2c_master->regs+DW_IC_ENABLE);

    writel(i2c_addr, i2c_master->regs+DW_IC_TAR);

    /* Enable i2c */
    enbl = readl(i2c_master->regs+DW_IC_ENABLE);
    enbl |= IC_ENABLE_0B;
    writel(enbl, i2c_master->regs+DW_IC_ENABLE);
}

/*
 * i2c_flush_rxfifo - Flushes the i2c RX FIFO
 *
 * Flushes the i2c RX FIFO
 */
static void designware_i2c_flush_rxfifo(struct designware_i2c_ctrl *i2c_master)
{
    while (readl(i2c_master->regs+DW_IC_STATUS) & IC_STATUS_RFNE)
    {
        cprintf("designware_i2c_flush_rxfifo\n");
        readl(i2c_master->regs+DW_IC_DATA_CMD);
    }
}

/*
 * i2c_wait_for_bb - Waits for bus busy
 *
 * Waits for bus busy
 */
static int designware_i2c_wait_for_bus_busy(struct designware_i2c_ctrl *i2c_master)
{
    unsigned int timeout = bsp_get_slice_value();
    unsigned int now=0;
    while ((readl(i2c_master->regs+DW_IC_STATUS) & IC_STATUS_MA) ||
            !(readl(i2c_master->regs+DW_IC_STATUS) & IC_STATUS_TFE))
    {
        now=bsp_get_slice_value();
        if(get_timer_slice_delta(timeout,now) > I2C_STATUS_TIMEOUT)
        {
            cprintf("designware_i2c_wait_for_bus_busy is busy\n");
            return -1;
        }
    }
    return 0;
}

static s32 designware_i2c_xfer_init(struct designware_i2c_ctrl *i2c_master,u8 device_id, u8 addr)
{
    if(designware_i2c_wait_for_bus_busy(i2c_master))
    {
    	return -1;
    }
    designware_i2c_setaddress(i2c_master,device_id);

    return 0;
}

static s32 designware_i2c_xfer_finish(struct designware_i2c_ctrl *i2c_master)
{
    unsigned int timeout = bsp_get_slice_value();
    unsigned int now=0;
    while (1)
    {
        if ((readl(i2c_master->regs+DW_IC_RAW_INTR_STAT) & IC_STOP_DET))
        {
            readl(i2c_master->regs+DW_IC_CLR_STOP_DET);
            break;
        }
        now=bsp_get_slice_value();
        if(get_timer_slice_delta(timeout,now) > I2C_STATUS_TIMEOUT)
        {
            cprintf("designware_i2c_xfer_finish timeout\n");
            break;
        }
    }
    if (designware_i2c_wait_for_bus_busy(i2c_master))
    {
        cprintf("Timed out waiting for bus\n");
        return -1;
    }
    designware_i2c_flush_rxfifo(i2c_master);
    designware_i2c_clk_disable(i2c_master->master_number);
    return 0;
}

s32 bsp_designware_i2c_read_data(u8 device_id,u8 addr, u8 *buffer, int len)
{
    struct designware_i2c_ctrl *i2c_master;
    unsigned int start_time_rx =0;
    unsigned int read_data_timeout =0x1000;

    /*find i2c master*/
    i2c_master=find_i2c_ctrl(device_id);
    if(!i2c_master)
    {
        cprintf("can find i2c master for device %0x\n",device_id);
        return I2C_ERROR;
    }
    designware_i2c_clk_enable(i2c_master->master_number);

    if (designware_i2c_xfer_init(i2c_master,device_id, addr))
    {
        return -1;
    }
    writel(addr, i2c_master->regs+DW_IC_DATA_CMD);
    while (len)
    {
        if (len == 1)
        {
            writel(IC_CMD | IC_STOP, i2c_master->regs+DW_IC_DATA_CMD);
        }
        else
        {
            writel(IC_CMD, i2c_master->regs+DW_IC_DATA_CMD);
        }
        while ((!(readl(i2c_master->regs+DW_IC_STATUS) & IC_STATUS_RFNE))&& read_data_timeout)
        {
            read_data_timeout --;
        }
        if(read_data_timeout ==0)
        {
            cprintf("bsp_designware_i2c_read_data timeout\n",device_id);
        }
        *buffer++ = (u8)readl(i2c_master->regs+DW_IC_DATA_CMD);
        len--;
        read_data_timeout =I2C_STATUS_TIMEOUT;

    }
    return designware_i2c_xfer_finish(i2c_master);

}


s32 bsp_designware_i2c_write_data(u8 device_id,u8 addr, u8 *buffer, int len)
{
    struct designware_i2c_ctrl *i2c_master;
    unsigned int timeout =0;
    unsigned int now =0;
    /*find i2c master*/
    i2c_master=find_i2c_ctrl(device_id);
    if(!i2c_master)
    {
        cprintf("can find i2c master for device %0x\n",device_id);
        return I2C_ERROR;
    }
    designware_i2c_clk_enable(i2c_master->master_number);
    if (designware_i2c_xfer_init(i2c_master,device_id, addr))
    {
        return 1;
    }
    timeout = bsp_get_slice_value();
    writel(addr, i2c_master->regs+DW_IC_DATA_CMD);
    while (len)
    {
        if (readl(i2c_master->regs+DW_IC_STATUS) & IC_STATUS_TFNF)
        {
            if (--len == 0)
            {
                writel(*buffer | IC_STOP, i2c_master->regs+DW_IC_DATA_CMD);
            }
            else
            {
                writel(*buffer, i2c_master->regs+DW_IC_DATA_CMD);
            }
            buffer++;
            timeout = bsp_get_slice_value();
        }
        else
        {
            now=bsp_get_slice_value();
            if(get_timer_slice_delta(timeout,now) > I2C_STATUS_TIMEOUT)
            {
                cprintf("Timed out. i2c write Failed\n");
                return -1;
            }
        }
    }
    return designware_i2c_xfer_finish(i2c_master);

}


s32 bsp_i2c_initial(void)
{
    v7r11_i2c0.regs=HI_I2C0_REGBASE_ADDR;
    v7r11_i2c0.master_name="designware_i2c0";
    v7r11_i2c0.slave_num=0;
    v7r11_i2c0.master_number=I2C_MASTER0;

    v7r11_i2c1.regs=HI_I2C1_REGBASE_ADDR;
    v7r11_i2c1.master_name="designware_i2c1";
    v7r11_i2c1.slave_num=0;
    v7r11_i2c1.master_number=I2C_MASTER1;

    designware_i2c_init(I2C_MASTER0,400000);
    return 0;
}
s32 bsp_i2c_byte_data_send(u8 device_id,u8 addr, u8 data)
{
    u8 temp=data;
    return bsp_designware_i2c_write_data(device_id,addr,(u8 *)&temp,1);
}
s32 bsp_i2c_word_data_send(u8 device_id,u8 addr, u16 data)
{
    u16 temp=data;
    return bsp_designware_i2c_write_data(device_id,addr,(u8 *)&temp,2);
}
s32 bsp_i2c_byte_data_receive(u8 device_id, u8 addr,  u8 *data)
{
    return bsp_designware_i2c_read_data(device_id,addr,data,1);
}
s32 bsp_i2c_word_data_receive(u8 device_id, u8 addr,  u16 *data)
{
    return bsp_designware_i2c_read_data(device_id,addr,(u8 *)data,2);
}
/************************************************************/
/*send byte data from bq24161 03# register*/
/*									*/
/************************************************************/
int debug_designware_i2c_byte_data_send(u8 addr,u8 value)
{
    u8 slave_id = TEST_SLAVE_ID;
    u8 offset = addr;
    u8 data = value;
    u8 back_data=0;
    int ret=0;

    /*send data to register*/
    ret=bsp_designware_i2c_write_data(slave_id, offset, &data,1);
    if(I2C_TEST_PASS!=ret)
    {
        cprintf("TEST FAIL!offset:%x,send data:%x\n",offset,data);
        return I2C_TEST_FAILE;
    }
    /*read the 0x02 register data*/
    ret=bsp_designware_i2c_read_data(slave_id, offset, &back_data,1);
    if(I2C_TEST_PASS!=ret)
    {
        cprintf("TEST FAIL!read back:%x,should:%x\n",back_data,data);
        return I2C_TEST_FAILE;
    }

    /*check read data is write data or not*/
    if(value!=back_data)
    {
        cprintf("TEST FAIL!register:%d,data=%x,back_data=%x\n",offset,data,back_data);
        return I2C_TEST_FAILE;
    }
    return I2C_TEST_PASS;

}



/************************************************************/
/*send byte data from bq24161 03# register*/
/*									*/
/************************************************************/
int debug_designware_i2c_word_data_send(u8 addr,u16 value)
{
    u8 slave_id = TEST_SLAVE_ID;
    u8 offset = addr;
    u16 data = value;
    u16 back_data=0;
    int ret=0;

    /*send data to register*/
    ret=bsp_designware_i2c_write_data(slave_id, offset, (u8 *)&data,2);
    if(I2C_TEST_PASS!=ret)
    {
        cprintf("TEST FAIL!offset:%x,send data:%x\n",offset,data);
        return I2C_TEST_FAILE;
    }
    /*read the 0x02 register data*/
    ret=bsp_designware_i2c_read_data(slave_id, offset, (u8 *)&back_data,2);
    if(I2C_TEST_PASS!=ret)
    {
        cprintf("TEST FAIL!read back:%x,should:%x\n",back_data,data);
        return I2C_TEST_FAILE;
    }

    /*check read data is write data or not*/
    if(value!=back_data)
    {
        cprintf("TEST FAIL!register:%d,data=%x,back_data=%x\n",offset,data,back_data);
        return I2C_TEST_FAILE;
    }
    return I2C_TEST_PASS;
}


int bsp_i2c_debug(void)
{
	int i = 0;
	int count = 0;
    u8 buffer[2]={0,0};
    u16 datatemp = 0x1234;
    u16 datatempback = 0x0;
	unsigned int clk0 = 0;
	unsigned int clk1 = 0;
    unsigned char datawrite[6]={1,2,3,4,5,6};
    unsigned char datawriteback[6]={0,0,0,0,0,0};

	clk0 = get_hi_crg_clkstat1_i2c0_clk_status();
	clk1 = get_hi_crg_clkstat1_i2c1_clk_status();
	cprintf("i2c0_clk:%d  i2c1_clk:%d\n",clk0,clk1);

	bsp_i2c_slave_register(I2C_MASTER0,TEST_SLAVE_ID);

	/*���ֽڲ��ԣ�05�Ĵ���������д50��*/
	count=0;
	for(i=0;i<50;i++)
    {

		if(I2C_TEST_PASS!=debug_designware_i2c_byte_data_send(0x05,0x8a))
		{
			count++;
			cprintf("register offset:0x05,send data:0x8a,times:%d\n\n",i);
		}
	}
	cprintf("test count:%d times,success %d times\n\n",i,i-count);

	/*���ֽڲ��ԣ�02�Ĵ�����д50��*/
	count = 0;
	for(i=0;i<50;i++)
    {
		if(I2C_TEST_PASS!=debug_designware_i2c_byte_data_send(0x2,0x8a))
		{
			count++;
			cprintf("register offset:%x,send data:0x8a\n",i);
		}
	}

	cprintf("\ntest count:%d times,success %d times\n\n",i,i-count);


	/*˫�ֽڲ��ԣ�05�Ĵ�����д50��*/
	count=0;
	for(i=0;i<50;i++)
    {

		if(I2C_TEST_PASS!=debug_designware_i2c_word_data_send(0x02,0x8a8a))
		{
			count++;
			cprintf("register offset:0x05,send data:0x8a,times:%d\n\n",i);
		}
	}
	cprintf("\ntest count:%d times,success %d times\n\n",i,i-count);

	/*˫�ֽڲ��ԣ�02�Ĵ�����д50��*/
	count = 0;
	for(i=0;i<50;i++)
    {
		if(I2C_TEST_PASS!=debug_designware_i2c_word_data_send(0x05,0x8a8a))
		{
			count++;
			cprintf("register offset:0x02,send data:0x8a8a\n",i);
		}
	}
	cprintf("\ntest count:%d times,success %d times\n\n",i,i-count);

    bsp_designware_i2c_write_data(0x6b,1,datawrite,6);
    bsp_designware_i2c_read_data(0x6b,1,datawriteback,6);
    cprintf("register read back data %x,%x,%x,%x,%x,%x\n",datawriteback[0],datawriteback[1],datawriteback[2],datawriteback[3],datawriteback[4],datawriteback[5]);

    bsp_i2c_word_data_send(0x6b,4,datatemp);
    bsp_i2c_word_data_receive(0x6b,4,&datatempback);
    cprintf("register datatempback %x\n",datatempback);
    datatempback =0;
    bsp_i2c_byte_data_receive(0x6b,4,&datatempback);
    cprintf("register datatempback %x\n",datatempback);
    bsp_designware_i2c_read_data(0x6b,4, buffer, 2);
    cprintf("register buffer[0] %x buffer[1] %x\n",buffer[0],buffer[1]);
	return 0;
}

