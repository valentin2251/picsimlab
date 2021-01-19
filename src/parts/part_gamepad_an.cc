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

#include"../picsimlab1.h"
#include"../picsimlab4.h"
#include"../picsimlab5.h"
#include"part_gamepad_an.h"

/* outputs */
enum
{
 O_P1, O_B1, O_B2, O_B3, O_B4, O_B5
};

/* inputs */
enum
{
 I_B1, I_B2, I_B3, I_B4, I_B5
};

cpart_gamepad_an::cpart_gamepad_an(unsigned x, unsigned y)
{
 X = x;
 Y = y;
 active = 1;

 ReadMaps ();

 lxImage image;
 image.LoadFile (Window1.GetSharePath () + lxT ("parts/") + GetPictureFileName ());

 Bitmap = lxGetBitmapRotated (&image, &Window5, orientation);
 image.Destroy ();

 canvas.Create (Window5.GetWWidget (), Bitmap);

 output_value[0] = 1;
 output_value[1] = 1;
 output_value[2] = 1;
 output_value[3] = 1;
 output_value[4] = 1;

 output_pins[0] = 0;

 RegisterRemoteControl ();

}

void
cpart_gamepad_an::RegisterRemoteControl(void)
{
 for (int i = 0; i < inputc; i++)
  {
   switch (input[i].id)
    {
    case I_B1:
     input[i].status = &output_value[0];
     break;
    case I_B2:
     input[i].status = &output_value[1];
     break;
    case I_B3:
     input[i].status = &output_value[2];
     break;
    case I_B4:
     input[i].status = &output_value[3];
     break;
    case I_B5:
     input[i].status = &output_value[4];
     break;
    }
  }
}

void
cpart_gamepad_an::Reset(void)
{
 //release all
 output_value_an = active * 5.0;

 output_value[0] = 1;
 output_value[1] = 1;
 output_value[2] = 1;
 output_value[3] = 1;
 output_value[4] = 1;

 Window5.SetAPin (output_pins[0], output_value_an);

}

cpart_gamepad_an::~cpart_gamepad_an(void)
{
 delete Bitmap;
 canvas.Destroy ();
}

void
cpart_gamepad_an::Draw(void)
{

 int i;
 lxString temp;
 canvas.Init (1.0, 1.0, orientation);

 lxFont font (9, lxFONTFAMILY_TELETYPE, lxFONTSTYLE_NORMAL, lxFONTWEIGHT_BOLD);
 canvas.SetFont (font);

 for (i = 0; i < outputc; i++)
  {

   switch (output[i].id)
    {
    case O_P1:
     canvas.SetColor (49, 61, 99);
     canvas.Rectangle (1, output[i].x1, output[i].y1, output[i].x2 - output[i].x1 + 30, output[i].y2 - output[i].y1 + 30);
     canvas.SetFgColor (255, 255, 255);

     temp = lxString ().Format ("%3.1f", output_value_an) + lxT ("V");
     canvas.RotatedText ("Out= " + temp, output[i].x1, output[i].y1 + 30, 0);
     if (output_pins[0] == 0)
      canvas.RotatedText ("NC", output[i].x1, output[i].y1, 0);
     else
      canvas.RotatedText (Window5.GetPinName (output_pins[0]), output[i].x1, output[i].y1, 0);
     break;
    case O_B5:
     if (output_value[output[i].id - O_B1])
      {
       canvas.SetColor (15, 15, 15);
      }
     else
      {
       canvas.SetColor (55, 55, 55);
      }
     canvas.Circle (1, output[i].cx, output[i].cy, 11);
     break;
    case O_B2:
    case O_B3:
     if (output_value[output[i].id - O_B1])
      {
       canvas.SetColor (250, 224, 0);
      }
     else
      {
       canvas.SetColor (0x9c, 0x94, 0x47);
      }
     canvas.Circle (1, output[i].cx, output[i].cy, 25);
     break;
    case O_B1:
    case O_B4:
     if (output_value[output[i].id - O_B1])
      {
       canvas.SetColor (3, 114, 212);
      }
     else
      {
       canvas.SetColor (64, 87, 106);
      }
     canvas.Circle (1, output[i].cx, output[i].cy, 25);
     break;
    }
  }

 canvas.End ();

}

void
cpart_gamepad_an::PreProcess(void)
{
 output_value_an = 5.0 * active;

 if (!output_value[0])
  {
   output_value_an = (active * 5.0 * (0.25 / 5.0))+((!active)*5.0 * (3.75 / 5.0));
  }
 else if (!output_value[1])
  {
   output_value_an = (active * 5.0 * (0.75 / 5.0))+((!active)*5.0 * (2.5 / 5.0));
  }
 else if (!output_value[2])
  {
   output_value_an = (active * 5.0 * (1.5 / 5.0))+((!active)*5.0 * (1.5 / 5.0));
  }
 else if (!output_value[3])
  {
   output_value_an = (active * 5.0 * (2.5 / 5.0))+((!active)*5.0 * (0.75 / 5.0));
  }
 else if (!output_value[4])
  {
   output_value_an = (active * 5.0 * (3.75 / 5.0))+((!active)*5.0 * (0.25 / 5.0));
  }

 Window5.SetAPin (output_pins[0], output_value_an);
}

void
cpart_gamepad_an::EvMouseButtonPress(uint button, uint x, uint y, uint state)
{
 int i;

 for (i = 0; i < inputc; i++)
  {
   if (PointInside (x, y, input[i]))
    {

     switch (input[i].id)
      {
      case I_B1: output_value[0] = 0;
       break;
      case I_B2: output_value[1] = 0;
       break;
      case I_B3: output_value[2] = 0;
       break;
      case I_B4: output_value[3] = 0;
       break;
      case I_B5: output_value[4] = 0;
       break;
      }
    }
  }
}

void
cpart_gamepad_an::EvMouseButtonRelease(uint button, uint x, uint y, uint state)
{
 int i;

 for (i = 0; i < inputc; i++)
  {
   if (PointInside (x, y, input[i]))
    {
     switch (input[i].id)
      {
      case I_B1: output_value[0] = 1;
       break;
      case I_B2: output_value[1] = 1;
       break;
      case I_B3: output_value[2] = 1;
       break;
      case I_B4: output_value[3] = 1;
       break;
      case I_B5: output_value[4] = 1;
       break;
      }
    }
  }
}

void
cpart_gamepad_an::EvKeyPress(uint key, uint mask)
{

 switch (key)
  {
  case 'I':
  case 'i':
   output_value[1] = 0;
   break;
  case 'J':
  case 'j':
   output_value[3] = 0;
   break;
  case 'K':
  case 'k':
   output_value[2] = 0;
   break;
  case 'L':
  case 'l':
   output_value[0] = 0;
   break;
  case 'O':
  case 'o':
   output_value[4] = 0;
   break;
  }
}

void
cpart_gamepad_an::EvKeyRelease(uint key, uint mask)
{
 switch (key)
  {
  case 'I':
  case 'i':
   output_value[1] = 1;
   break;
  case 'J':
  case 'j':
   output_value[3] = 1;
   break;
  case 'K':
  case 'k':
   output_value[2] = 1;
   break;
  case 'L':
  case 'l':
   output_value[0] = 1;
   break;
  case 'O':
  case 'o':
   output_value[4] = 1;
   break;
  }
}

unsigned short
cpart_gamepad_an::get_in_id(char * name)
{
 if (strcmp (name, "PB_1") == 0)return I_B1;
 if (strcmp (name, "PB_2") == 0)return I_B2;
 if (strcmp (name, "PB_3") == 0)return I_B3;
 if (strcmp (name, "PB_4") == 0)return I_B4;
 if (strcmp (name, "PB_5") == 0)return I_B5;

 printf ("Erro input '%s' don't have a valid id! \n", name);
 return -1;
}

unsigned short
cpart_gamepad_an::get_out_id(char * name)
{

 if (strcmp (name, "PB_1") == 0)return O_B1;
 if (strcmp (name, "PB_2") == 0)return O_B2;
 if (strcmp (name, "PB_3") == 0)return O_B3;
 if (strcmp (name, "PB_4") == 0)return O_B4;
 if (strcmp (name, "PB_5") == 0)return O_B5;

 if (strcmp (name, "PN_1") == 0)return O_P1;

 printf ("Erro output '%s' don't have a valid id! \n", name);
 return 1;
}

lxString
cpart_gamepad_an::WritePreferences(void)
{
 char prefs[256];

 sprintf (prefs, "%hhu,%hhu", output_pins[0], active);

 return prefs;
}

void
cpart_gamepad_an::ReadPreferences(lxString value)
{
 sscanf (value.c_str (), "%hhu,%hhu", &output_pins[0], &active);
 output_value_an = active * 5.0;
}

void
cpart_gamepad_an::ConfigurePropertiesWindow(CPWindow * WProp)
{
 lxString Items = Window5.GetPinsNames ();
 lxString spin;

 ((CCombo*) WProp->GetChildByName ("combo1"))->SetItems (Items);
 if (output_pins[0] == 0)
  ((CCombo*) WProp->GetChildByName ("combo1"))->SetText ("0  NC");
 else
  {
   spin = Window5.GetPinName (output_pins[0]);
   ((CCombo*) WProp->GetChildByName ("combo1"))->SetText (itoa (output_pins[0]) + "  " + spin);
  }

 if (active)
  ((CCombo*) WProp->GetChildByName ("combo9"))->SetText ("HIGH");
 else
  ((CCombo*) WProp->GetChildByName ("combo9"))->SetText ("LOW ");


 ((CButton*) WProp->GetChildByName ("button1"))->EvMouseButtonRelease = EVMOUSEBUTTONRELEASE & CPWindow5::PropButtonRelease;
 ((CButton*) WProp->GetChildByName ("button1"))->SetTag (1);

 ((CButton*) WProp->GetChildByName ("button2"))->EvMouseButtonRelease = EVMOUSEBUTTONRELEASE & CPWindow5::PropButtonRelease;
}

void
cpart_gamepad_an::ReadPropertiesWindow(CPWindow * WProp)
{
 output_pins[0] = atoi (((CCombo*) WProp->GetChildByName ("combo1"))->GetText ());


 active = (((CCombo*) WProp->GetChildByName ("combo9"))->GetText ().compare ("HIGH") == 0);

}

part_init("Gamepad (Analogic)", cpart_gamepad_an);

