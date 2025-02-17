/*
 * Copyright 2001 by Arto Salmi and Joze Fabcic
 * Copyright 2006 by Brian Dominy <brian@oddchange.com>
 *
 * This file is part of GCC6809.
 *
 * GCC6809 is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * GCC6809 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GCC6809; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */


#ifndef M6809_H
#define M6809_H

/* #include "config.h" */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef uint8_t UINT8;
typedef signed char INT8;

typedef uint16_t UINT16;
typedef signed short INT16;

typedef uint32_t UINT32;
typedef signed int INT32;

typedef uint16_t target_addr_t;

#include "machine.h"

#define E_FLAG 0x80
#define F_FLAG 0x40
#define H_FLAG 0x20
#define I_FLAG 0x10
#define N_FLAG 0x08
#define Z_FLAG 0x04
#define V_FLAG 0x02
#define C_FLAG 0x01

extern int debug_enabled;
extern int need_flush;
extern int total;
extern int dump_cycles_on_success;

#ifdef CONFIG_WPC
extern UINT8 *regions[4];
#endif
extern UINT8 *memory;

/* Primitive read/write macros */
#define read8(addr)        memory[addr]
#define write8(addr,val)   do { memory[addr] = val; } while (0)

/* 16-bit versions */
#define read16(addr)       (read8(addr) << 8 | read8(addr+1))
#define write16(addr,val)  do { write8(addr, val & 0xFF); write8(addr+1, (val >> 8) & 0xFF) } while (0)

/* Fetch macros */

#define fetch8()           read8(pc++)
#define fetch16()          (pc += 2, read16(pc-2))

/* 6809.c */
extern int cpu_quit;
extern int cpu_execute (int);
extern void cpu_reset (void);

extern unsigned get_a  (void);
extern unsigned get_b  (void);
extern unsigned get_cc (void);
extern unsigned get_dp (void);
extern unsigned get_x  (void);
extern unsigned get_y  (void);
extern unsigned get_s  (void);
extern unsigned get_u  (void);
extern unsigned get_pc (void);
extern unsigned get_d  (void);
extern void set_a  (unsigned);
extern void set_b  (unsigned);
extern void set_cc (unsigned);
extern void set_dp (unsigned);
extern void set_x  (unsigned);
extern void set_y  (unsigned);
extern void set_s  (unsigned);
extern void set_u  (unsigned);
extern void set_pc (unsigned);
extern void set_d  (unsigned);

/* monitor.c */
extern int monitor_on;
extern int check_break (unsigned);
extern void monitor_init (void);
extern int monitor6809 (void);
extern int dasm (char *, int);

extern int load_hex (char *);
extern int load_s19 (char *);
extern int load_bin (char *,int);

void irq (void);
void sim_error (const char *format, ...);
void sim_exit (uint8_t exit_code);

#endif /* M6809_H */
