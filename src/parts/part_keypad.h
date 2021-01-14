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

#ifndef PART_KEYPAD_H
#define	PART_KEYPAD_H

#include<lxrad.h>
#include"part.h"


class cpart_keypad:public part
{
   public:
      lxString GetName(void){return lxT("Keypad");};
      lxString GetHelpURL(void){return lxT("Keypad.html");};
      lxString GetAboutInfo(void){return lxT("L.C. Gamboa \n <lcgamboa@yahoo.com>");};            
      cpart_keypad(unsigned x, unsigned y);
      ~cpart_keypad(void);
      void Draw(void);
      void Process(void);
      lxString GetPictureFileName(void);
      lxString GetInputMapFile(void);
      lxString GetOutputMapFile(void);
      lxString GetPropertiesWindowFile(void){return lxT("keypad/keypad.lxrad");};
      void EvMouseButtonPress(uint button, uint x, uint y,uint state);
      void EvMouseButtonRelease(uint button, uint x, uint y,uint state);
      void ConfigurePropertiesWindow(CPWindow *  WProp);
      void ReadPropertiesWindow(CPWindow * WProp);
      lxString WritePreferences(void);
      void ReadPreferences(lxString value);
      unsigned short get_in_id(char * name);
      unsigned short get_out_id(char * name);
      void ComboChange(CCombo * control, lxString value);
      void ChangeType(unsigned char tp); 
    private:
      unsigned char type;  
      unsigned char pull;  
      unsigned char output_pins[8];    
      unsigned char keys[4][4];
      unsigned char keys2[2][5];
};




#endif	/* PART_KEYPAD_H */

