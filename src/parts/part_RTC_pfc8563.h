/* ########################################################################

   PICsimLab - PIC laboratory simulator

   ########################################################################

   Copyright (c) : 2019-2020  Luis Claudio Gambôa Lopes

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

#ifndef PART_RTC_PFC8563_H
#define	PART_RTC_PFC8563_H

#include<lxrad.h>
#include"part.h"

class cpart_RTC_pfc8563:public part
{
   public:
      lxString GetName(void){return lxT("RTC pfc8563");};
      lxString GetHelpURL(void){return lxT("RTC_pfc8563.html");};
      lxString GetAboutInfo(void){return lxT("L.C. Gamboa \n <lcgamboa@yahoo.com>");};            
      cpart_RTC_pfc8563(unsigned x, unsigned y);
      ~cpart_RTC_pfc8563(void);
      void Draw(void);
      void Process(void);
      lxString GetPictureFileName(void){return lxT("Common/IC8.png");};
      lxString GetInputMapFile(void){return lxT("Common/IC8_i.map");};
      lxString GetOutputMapFile(void){return lxT("Common/IC8_o.map");};
      lxString GetPropertiesWindowFile(void){return lxT("RTC_pfc8563/RTC_pfc8563.lxrad");};
      void ConfigurePropertiesWindow(CPWindow *  WProp);
      void ReadPropertiesWindow(CPWindow * WProp);
      lxString WritePreferences(void);
      void ReadPreferences(lxString value);
      unsigned short get_in_id(char * name);
      unsigned short get_out_id(char * name);
   private:
      unsigned char input_pins[4]; 
      rtc_t rtc;
};




#endif	/* PART_RTC_PFC8563_H */

