/* ########################################################################

   PICsimLab - PIC laboratory simulator

   ########################################################################

   Copyright (c) : 2020-2020  Luis Claudio Gambôa Lopes

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

#ifndef PART_UART_H
#define	PART_UART_H

#include<lxrad.h>
#include"part.h"
#include"../devices/uart.h"

class cpart_UART:public part
{
   public:
      lxString GetName(void){return lxT("IO UART");};
      lxString GetHelpURL(void){return lxT("IO_UART.html");};
      lxString GetAboutInfo(void){return lxT("L.C. Gamboa \n <lcgamboa@yahoo.com>");};
      cpart_UART(unsigned x, unsigned y);
      ~cpart_UART(void);
      void Draw(void);
      void PreProcess (void);
      void Process(void); 
      void PostProcess (void);
      lxString GetPictureFileName(void){return lxT("UART/uart.png");};
      lxString GetInputMapFile(void){return lxT("UART/uart_i.map");};
      lxString GetOutputMapFile(void){return lxT("UART/uart_o.map");};
      lxString GetPropertiesWindowFile(void){return lxT("UART/uart.lxrad");};
      void Reset(void);
      void EvMouseButtonPress(uint button, uint x, uint y,uint state);
      void ConfigurePropertiesWindow(CPWindow *  WProp);
      void ReadPropertiesWindow(CPWindow * WProp);
      lxString WritePreferences(void);
      void ReadPreferences(lxString value);
      unsigned short get_in_id(char * name);
      unsigned short get_out_id(char * name);
   private:
      unsigned char input_pins[1];
      unsigned char output_pins[1];
      uart_t sr;
      unsigned short _ret; 
      char uart_name[200];
      unsigned int uart_speed;
};




#endif	/* PART_UART_H */

