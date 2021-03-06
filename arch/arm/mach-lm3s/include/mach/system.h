/*
 * arch/arm/mach-mps/include/mach/system.h
 *
 * Copyright (C) 2009 ARM Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */
#ifndef __ASM_ARCH_SYSTEM_H
#define __ASM_ARCH_SYSTEM_H

#include <linux/io.h>
#include <mach/hardware.h>
#include <mach/platform.h>

static inline void arch_idle(void)
{
}

static inline void arch_reset(char mode, const char *cmd)
{
	unsigned long *paircr = (unsigned long *) 0xE000ED0C;

	asm volatile ("dsb");
	*paircr = (*paircr & (7 << 8)) | 1 << 2 | 0x5FA << 16;
	asm volatile ("dsb");
}

#endif
