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

#ifndef PART_IO_74XX595_H
#define	PART_IO_74XX595_H

#include<lxrad.h>
#include"part.h"
#include"../devices/io_74xx595.h"

class cpart_IO_74xx595:public part
{
   public:
      lxString GetName(void){return lxT("IO 74xx595");};
      lxString GetHelpURL(void){return lxT("IO_74xx595.html");};
      lxString GetAboutInfo(void){return lxT("L.C. Gamboa \n <lcgamboa@yahoo.com>");};
      cpart_IO_74xx595(unsigned x, unsigned y);
      ~cpart_IO_74xx595(void);
      void Draw(void);
      void PreProcess (void);
      void Process(void); 
      void PostProcess (void);
      lxString GetPictureFileName(void){return lxT("Common/IC16.png");};
      lxString GetInputMapFile(void){return lxT("Common/IC16_i.map");};
      lxString GetOutputMapFile(void){return lxT("Common/IC16_o.map");};
      lxString GetPropertiesWindowFile(void){return lxT("io_74xx595/IO_74xx595.lxrad");};
      void ConfigurePropertiesWindow(CPWindow *  WProp);
      void ReadPropertiesWindow(CPWindow * WProp);
      lxString WritePreferences(void);
      void ReadPreferences(lxString value);
      unsigned short get_in_id(char * name);
      unsigned short get_out_id(char * name);
   private:
      unsigned char input_pins[4];
      unsigned char output_pins[9];
      unsigned long output_pins_alm[9];
      long mcount;
      int JUMPSTEPS_;
      io_74xx595_t sr8;
      unsigned short _ret; 
};




#endif	/* PART_IO_74XX595_H */

