/* ########################################################################

   PICsimLab - PIC laboratory simulator

   ########################################################################

   Copyright (c) : 2020       El-khadraouy Mohammed <mohammed.el-khadraouy@ecole.ensicaen.fr>
   Copyright (c) : 2015-2018  Luis Claudio Gambôa Lopes

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

#ifndef BOARD_Curiosity_HPC_H
#define BOARD_Curiosity_HPC_H

#include<lxrad.h>

#include "bsim_picsim.h"

//New board Class derived from board class defined in board.h
class cboard_Curiosity_HPC:public bsim_picsim
{
    private:
        unsigned char p_BT[2]; // Button S1 and S2
        
        unsigned char pot1;
        unsigned char active;
        
        unsigned char jmp[1];  //jumper

         //controls to be added in simulator window
        CGauge *gauge1;   //gauge to show mean value of RA4
        CGauge *gauge2;   //gauge to show mean value of RA5
        CGauge *gauge3;   //gauge to show mean value of RA6
        CGauge *gauge4;   //gauge to show mean value of RA7
        CGauge *gauge5;   //gauge to show mean value of RA7
        CLabel *label1;   //label of gauge RA4
        CLabel *label2;   //label of gauge RA4
        CLabel *label3;   //label of gauge RA5
        CLabel *label4;   //label of gauge RA6
        CLabel *label5;   //label of gauge RA7
        CLabel *label6;   //label of first serial
        CLabel *label7;   //label of second serial
        CCombo *combo1;  //combo of first serial
        CCombo *combo2;  //combo of second serial
        void RegisterRemoteControl(void); 
    public:
      lxString GetAboutInfo(void){return lxT("El-khadraouy Mohammed\n<mohammed.el-khadraouy@ecole.ensicaen.fr>\nand L.C. Gamboa \n <lcgamboa@yahoo.com>");};  
      //Constructor called once on board creation 
      cboard_Curiosity_HPC(void);
      //Destructor called once on board destruction 
      ~cboard_Curiosity_HPC(void); 
      //Called ever 100ms to draw board
      void Draw(CDraw *draw,double scale);
      void Run_CPU(void);
      //Return a list of board supported microcontrollers
      lxString GetSupportedDevices(void){return lxT("PIC18F27K40,");};
      //Return the filename of board picture 
      lxString GetPictureFileName(void){return lxT("Curiosity_HPC/board.png");};
      //Return the filename of board picture input map 
      lxString GetInputMapFile(void){return lxT("Curiosity_HPC/input.map");};
      //Return the filename of board picture output map 
      lxString GetOutputMapFile(void){return lxT("Curiosity_HPC/output.map");};
      //Reset board status
      void Reset(void);
      //Event on the board
      void EvMouseButtonPress(uint button, uint x, uint y,uint state);
      //Event on the board
      void EvMouseButtonRelease(uint button, uint x, uint y,uint state);
      //Event on the board
      void EvMouseMove(uint button, uint x, uint y, uint state);
      //Event on the board
      void EvKeyPress(uint key, uint mask);
      //Event on the board
      void EvKeyRelease(uint key, uint mask);
      void EvOnShow(void){};
      //Called ever 1s to refresh status
      void RefreshStatus(void);
      //Called to save board preferences in configuration file
      void WritePreferences(void);
      //Called whe configuration file load  preferences 
      void ReadPreferences(char *name,char *value);
      //return the input ids numbers of names used in input map
      unsigned short get_in_id(char * name);
      //return the output ids numbers of names used in output map
      unsigned short get_out_id(char * name);
      //Set Serial port name
      void MSetSerial(const char * port);
};

#endif  /* BOARD_Curiosity_HPC_H */