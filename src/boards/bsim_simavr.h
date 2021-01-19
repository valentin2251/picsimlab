/* ########################################################################

   PICsimLab - PIC laboratory simulator

   ########################################################################

   Copyright (c) : 2010-2020  Luis Claudio Gambôa Lopes

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

   For e-mail suggestions :  lcgamboa@yahoo.com
   ######################################################################## */

#ifndef BOARD_AVR_H
#define	BOARD_AVR_H

#include "board.h"

#include"../devices/mplabxd.h"
#include"../devices/bitbang_uart.h"
#include"../serial_port.h"

#include <simavr/sim_avr.h>
#include <simavr/avr_ioport.h>
#include <simavr/sim_elf.h>
#include <simavr/sim_hex.h>
#include <simavr/sim_gdb.h>
#include <simavr/avr_adc.h>
#include <simavr/avr_uart.h>
#include <simavr/sim_hex.h>
#include <simavr/avr_twi.h>


class bsim_simavr: virtual public board
{
  public:
      bsim_simavr(void);//Called once on board creation
      int DebugInit(int dtyppe); 
      lxString GetDebugName(void);
      void DebugLoop(void);
      int CpuInitialized(void);
      void MSetSerial(const char * port);
      int MInit(const char * processor, const char * fname, float freq);
      void MEnd(void);
      void MDumpMemory(const char * fname);
      void MEraseFlash(void);
      void MSetFreq(float freq);
      float MGetFreq(void);
      float MGetInstClock(void);
      int MGetPinCount(void);
      lxString MGetPinName(int pin);
      void MSetPin(int pin, unsigned char value);
      void MSetPinDOV(int pin, unsigned char ovalue);      
      void MSetAPin(int pin, float value);
      unsigned char MGetPin(int pin);  
      const picpin * MGetPinsValues(void); 
      void UpdateHardware(void);
      void MStep(void);
      void MStepResume(void);
      int DBGTestBP(unsigned int bp);
      void MReset(int flags);
      unsigned short * DBGGetProcID_p(void);
      unsigned int  DBGGetPC(void);
      void DBGSetPC(unsigned int pc);
      unsigned char * DBGGetRAM_p(void);
      unsigned char * DBGGetROM_p(void);
      unsigned char * DBGGetCONFIG_p(void);
      unsigned char * DBGGetID_p(void);
      unsigned char * DBGGetEEPROM_p(void);
      unsigned int DBGGetRAMSize(void);
      unsigned int DBGGetROMSize(void);
      unsigned int DBGGetCONFIGSize(void);
      unsigned int DBGGetIDSize(void);
      unsigned int DBGGetEEPROM_Size(void);
      
      static void out_hook( struct avr_irq_t* irq, uint32_t value, void* param )
      {      
         picpin * p  = (picpin *)param;
         p->value=value;
      }

      static void ddr_hook( struct avr_irq_t* irq, uint32_t value, void* param )
      {
         picpin * p = (picpin *)param;
         p->dir=!(value & (1<<p->pord));
      }
      
      void SerialSend(unsigned char value);
 protected:
      avr_t *  avr;
      avr_irq_t * serial_irq;
      picpin pins[256];
      avr_irq_t * Write_stat_irq[100];
      unsigned int serialbaud; 
      float serialexbaud;
      void pins_reset(void);
      int avr_debug_type;
      serialfd_t  serialfd;    
      bitbang_uart_t bb_uart;  
 private:
      int parse_hex(char *line,int bytes);
      unsigned char checksum(char* str);
      int read_ihx_avr(const char * fname, int leeprom);
      int write_ihx_avr(const char * fname);  
      
      unsigned char pin_rx;
      unsigned char pin_tx;
      unsigned char uart_config;
};

#define UCSR0A 0XC0
#define UCSR0B 0XC1
#define UCSR0C 0XC2
#define UBRR0L 0xC4
#define UBRR0H 0xC5

#endif	/* BOARD_AVR_H */

