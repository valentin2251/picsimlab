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

#ifndef PART_LCD_SSD1306_H
#define	PART_LCD_SSD1306_H

#include<lxrad.h>
#include"part.h"
#include"../devices/lcd_ssd1306.h"

class cpart_LCD_ssd1306:public part
{
   public:
      lxString GetName(void){return lxT("LCD ssd1306");};
      lxString GetHelpURL(void){return lxT("LCD_ssd1306.html");};
      lxString GetAboutInfo(void){return lxT("L.C. Gamboa \n <lcgamboa@yahoo.com>");};            
      cpart_LCD_ssd1306(unsigned x, unsigned y);
      ~cpart_LCD_ssd1306(void);
      void Draw(void);
      void Process(void);
      lxString GetPictureFileName(void){return lxT("LCD_ssd1306/LCD_ssd1306.png");};
      lxString GetInputMapFile(void){return lxT("LCD_ssd1306/LCD_ssd1306_i.map");};
      lxString GetOutputMapFile(void){return lxT("LCD_ssd1306/LCD_ssd1306_o.map");};
      lxString GetPropertiesWindowFile(void){return lxT("LCD_ssd1306/LCD_ssd1306.lxrad");};
      void ConfigurePropertiesWindow(CPWindow *  WProp);
      void ReadPropertiesWindow(CPWindow * WProp);
      lxString WritePreferences(void);
      void ReadPreferences(lxString value);
      unsigned short get_in_id(char * name);
      unsigned short get_out_id(char * name);
   private:
      unsigned char input_pins[5]; 
      lcd_ssd1306_t lcd;
      unsigned char type_com;
};



#endif	/* PART_LCD_SSD1306_H */

