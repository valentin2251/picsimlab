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

#ifndef PART_STEP_H
#define	PART_STEP_H

#include<lxrad.h>
#include"part.h"


class cpart_step:public part
{
   public:
      lxString GetName(void){return lxT("Step motor");}; 
      lxString GetHelpURL(void){return lxT("Step_Motor.html");};
      lxString GetAboutInfo(void){return lxT("L.C. Gamboa \n <lcgamboa@yahoo.com>");};            
      cpart_step(unsigned x, unsigned y);
      ~cpart_step(void);
      void Draw(void);
      void Process(void);
      lxString GetPictureFileName(void){return lxT("step/step_motor.png");};
      lxString GetInputMapFile(void){return lxT("step/step_motor_i.map");};
      lxString GetOutputMapFile(void){return lxT("step/step_motor_o.map");};
      lxString GetPropertiesWindowFile(void){return lxT("step/step_motor.lxrad");};
      void ConfigurePropertiesWindow(CPWindow *  WProp);
      void ReadPropertiesWindow(CPWindow * WProp);
      lxString WritePreferences(void);
      void ReadPreferences(lxString value);
      unsigned short get_in_id(char * name);
      unsigned short get_out_id(char * name);
    private:
      unsigned char input_pins[4];    
      float angle;
      int b1[2];
      int b2[2];
};




#endif	/* PART_STEP */

