/*
 * Copyright (c) 2018 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#include <zephyr/types.h>
#include <string.h>
#include <errno.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

#include <zephyr/usb/usb_device.h>

#include <soc.h>

#include <stdio.h>
#include <stdlib.h>

#ifdef CONFIG_BUILD_WITH_TFM
#include <tfm_ns_interface.h>
#endif
/*********/

/* UTC time */

LOG_MODULE_REGISTER(main, LOG_LEVEL_DBG);

#define PRINT_HEX(p_label, p_text, len)\
	({\
		LOG_INF("---- %s (len: %u): ----", p_label, len);\
		LOG_HEXDUMP_INF(p_text, len, "Content:");\
		LOG_INF("---- %s end  ----", p_label);\
	})


void main(void)
{
	LOG_INF("Welcome...\n");
	LOG_INF("It finally works");

	int rc = 0;
	if (IS_ENABLED(CONFIG_USB_DEVICE_STACK)) {
		rc = usb_enable(NULL);
		if (rc) {
			LOG_ERR("Failed to enable USB");
			return;
		}
	}

	for (;;) 
	{
		k_usleep(1);
	}
}