/*
 *  arch/arm/plat-omap/include/mach/board-nokia.h
 *
 *  Information structures for Nokia-specific board config data
 *
 *  Copyright (C) 2005	Nokia Corporation
 */

#ifndef __ASM_ARCH_OMAP_NOKIA_H
#define __ASM_ARCH_OMAP_NOKIA_H

#include <linux/types.h>

struct tsc2301_platform_data;
struct dsp_kfunc_device;
struct omap_bluetooth_config;
extern void n800_bt_init(void);
extern void n800_dsp_init(void);
extern void n800_flash_init(void);
extern void n800_mmc_init(void);
extern void n800_pm_init(void);
extern void n800_usb_init(void);
extern void n800_cam_init(void);
extern void n800_audio_init(struct tsc2301_platform_data *);
extern int n800_audio_enable(struct dsp_kfunc_device *kdev, int stage);
extern int n800_audio_disable(struct dsp_kfunc_device *kdev, int stage);
extern void n800_mmc_slot1_cover_handler(void *arg, int state);
extern void omap_bt_init(struct omap_bluetooth_config *bt_config);

extern int board_in_revs(const u32 *revs, int num_revs);

void __init rm680_peripherals_init(void);
void __init rm696_peripherals_init(void);
void __init rx71_peripherals_init(void);

#define OMAP_TAG_NOKIA_BT	0x4e01
#define OMAP_TAG_WLAN_CX3110X	0x4e02
#define OMAP_TAG_CBUS		0x4e03
#define OMAP_TAG_EM_ASIC_BB5	0x4e04

#define BT_CHIP_CSR		1
#define BT_CHIP_TI		2
#define BT_CHIP_BCM		3

#define BT_SYSCLK_12		1
#define BT_SYSCLK_38_4		2

/* Allow C6 state {1, 3120, 5788, 10000} */
#define H4P_WAKEUP_LATENCY	5700

struct omap_bluetooth_config {
	u8    chip_type;
	u8    bt_wakeup_gpio;
	u8    host_wakeup_gpio;
	u8    reset_gpio;
	u8    reset_gpio_shared;
	u8    bt_uart;
	u8    bd_addr[6];
	u8    bt_sysclk;
	void  (*set_pm_limits)(struct device *dev, bool set);
};

struct omap_wlan_cx3110x_config {
	u8  chip_type;
	s16 power_gpio;
	s16 irq_gpio;
	s16 spi_cs_gpio;
};

struct omap_cbus_config {
	s16 clk_gpio;
	s16 dat_gpio;
	s16 sel_gpio;
};

struct omap_em_asic_bb5_config {
	s16 retu_irq_gpio;
	s16 tahvo_irq_gpio;
};

#endif
