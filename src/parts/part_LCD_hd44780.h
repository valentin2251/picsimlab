/* ########################################################################

   PICsimLab - PIC laboratory simulator

   ########################################################################

   Copyright (c) : 2010-2015  Luis Claudio Gambôa Lopes

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

#ifndef PART_LCD_HD44780_H
#define	PART_LCD_HD44780_H

#include<lxrad.h>
#include"part.h"


#define LCD16x2 1
#define LCD16x4 2
#define LCD20x2 4
#define LCD20x4 8

class cpart_LCD_hd44780:public part
{
   public:
      lxString GetName(void){return lxT("LCD hd44780");};
      lxString GetHelpURL(void){return lxT("LCD_hd44780.html");};
      lxString GetAboutInfo(void){return lxT("L.C. Gamboa \n <lcgamboa@yahoo.com>");};      
      cpart_LCD_hd44780(unsigned x, unsigned y);
      ~cpart_LCD_hd44780(void);
      void Draw(void);
      void Process(void);
      lxString GetPictureFileName(void){return lxT("LCD_hd44780/LCD_hd44780.png");};
      lxString GetPictureFileName_(void){return lxT("LCD_hd44780/LCD_hd44780_.png");};
      lxString GetPictureFileName__(void){return lxT("LCD_hd44780/LCD_hd44780__.png");};
      lxString GetPictureFileName___(void){return lxT("LCD_hd44780/LCD_hd44780___.png");};
      lxString GetInputMapFile(void){return lxT("LCD_hd44780/LCD_hd44780_i.map");};
      lxString GetOutputMapFile(void){return lxT("LCD_hd44780/LCD_hd44780_o.map");};
      lxString GetPropertiesWindowFile(void){return lxT("LCD_hd44780/LCD_hd44780.lxrad");};
      void Reset(void);
      void ConfigurePropertiesWindow(CPWindow *  WProp);
      void ReadPropertiesWindow(CPWindow * WProp);
      lxString WritePreferences(void);
      void SetOrientation(int orientation);
      void ReadPreferences(lxString value);
      unsigned short get_in_id(char * name);
      unsigned short get_out_id(char * name);
    private:
      unsigned char input_pins[11]; 
      lcd_t lcd;
      int lcde;
      unsigned char model;
};




#endif	/* PART_LCD_HD44780 */

