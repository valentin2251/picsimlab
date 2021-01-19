/* ########################################################################

   PICsimLab - PIC laboratory simulator

   ########################################################################

   Copyright (c) : 2020-2021  Luis Claudio Gambôa Lopes

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


#include<stdio.h>
#include"tsc_xpt2046.h"

#define dprintf if (1) {} else printf

#define BIT_S       0x80
#define BIT_A2      0x40 
#define BIT_A1      0x20
#define BIT_A0      0x10
#define BIT_SMODE   0x08
#define BIT_SER_DFR 0x04
#define BIT_PD1     0x02
#define BIT_PD0     0x01

void
tsc_XPT2046_rst(tsc_XPT2046_t *tsc_)
{
 tsc_->x = 0;
 tsc_->y = 0;

 tsc_->data = 0;
 tsc_->bit = 0xFF;
 tsc_->byte = 0xFF;
 tsc_->pclk = -1;
 tsc_->cmd = 0;
 tsc_->pint = 2;

 dprintf ("tsc_ rst\n");
}

void
tsc_XPT2046_init(tsc_XPT2046_t *tsc_, unsigned int w, unsigned int h)
{
 tsc_->width = w;
 tsc_->height = h;
 dprintf ("tsc_ init %i %i\n", w, h);
 tsc_XPT2046_rst (tsc_);
}

void
tsc_XPT2046_set_pos(tsc_XPT2046_t *tsc_, int x, int y)
{

 if ((x >= 0)&&(y >= 0))
  {
   tsc_->pint = 0;
   tsc_->x = x;
   tsc_->y = y;
  }
 else
  {
   tsc_->pint = 2;
  }

 dprintf ("tsc_ set pos %i %i \n", x, y);
}

unsigned char
tsc_XPT2046_SPI_io(tsc_XPT2046_t *tsc_, unsigned char clk, unsigned char din, unsigned char cs)
{

 if (cs)
  {
   tsc_->bit = 0;
   tsc_->byte = 0;
   return (tsc_->pint);
  }


 //transicao
 if ((tsc_->pclk == 0)&&(clk == 1))//rising edge
  {
   if (tsc_->bit == 8) tsc_->bit = 0;

   if (tsc_->bit < 8)
    {
     if (din)
      {
       tsc_->data = (tsc_->data << 1) | 1;

       if (tsc_->byte)
        {
         tsc_->byte = 0;
         tsc_->bit = 0;
        }
      }
     else
      {
       tsc_->data = (tsc_->data << 1) & 0xFE;
      }
     tsc_->bit++;

     tsc_->datas = tsc_->datas << 1;
    }

   if (tsc_->bit == 8)
    {

     if (tsc_->data & BIT_S)
      {
       tsc_->byte = 0;
      }

     //dprintf ("-------tsc_ data 0x%02X  byte=%i\n", tsc_->data,tsc_->byte);
     tsc_->bit = 0;
     switch (tsc_->byte)
      {
      case 0:
       if (tsc_->data & BIT_S)
        {
         tsc_->cmd = tsc_->data;
         tsc_->byte++;
         dprintf ("tsc_ cmd 0x%02X OK\n", tsc_->cmd);

         switch ((tsc_->cmd & 0x70) >> 4)
          {
          case 1: // Y -Position
           tsc_->datas = (tsc_->x * 4095) / tsc_->height;
           break;
          case 5: // X -Position
           tsc_->datas = (tsc_->y * 4095) / tsc_->width;
           break;
          default:
           tsc_->datas = 0;
           break;
          }
        }
       else
        {
         tsc_->bit = 0xFF;
         tsc_->byte = 0xFF;
         dprintf ("tsc_ cmd 0x%02X ERROR\n", tsc_->cmd);
        }
       break;
      default:
       tsc_->byte++;
       break;
      }
    }
  }

 tsc_->pclk = clk;

 return ((tsc_->pint) | ((tsc_->datas & 0x1000) > 0));
}
