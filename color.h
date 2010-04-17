/*
	DDS GIMP plugin

	Copyright (C) 2004-2010 Shawn Kirst <skirst@insightbb.com>,
   with parts (C) 2003 Arne Reuter <homepage@arnereuter.de> where specified.

	This program is free software; you can redistribute it and/or
	modify it under the terms of the GNU General Public
	License as published by the Free Software Foundation; either
	version 2 of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; see the file COPYING.  If not, write to
	the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
	Boston, MA 02111-1307, USA.
*/

#ifndef COLOR_H
#define COLOR_H

/* sRGB encoding/decoding */
int linear_to_sRGB(int c);
int sRGB_to_linear(int c);

/* YCoCg encoding/decoding */
static inline int RGB_to_YCoCg_Y (int r, int g, int b)
{
   return(((r + (g << 1) + b) + 2) >> 2);
}

static inline int RGB_to_YCoCg_Co(int r, int g, int b)
{
   return((((r << 1) - (b << 1)) + 2) >> 2);
}

static inline int RGB_to_YCoCg_Cg(int r, int g, int b)
{
   return(((-r + (g << 1) - b) + 2) >> 2);
}

/* other color conversions */

static inline int rgb_to_luminance(int r, int g, int b)
{
   return((r * 54 + g * 182 + b * 20) >> 8);
}

static inline unsigned short pack_r5g6b5(int r, int g, int b)
{
   return(((unsigned short)((r >> 3) & 0x1f) << 11) |
          ((unsigned short)((g >> 2) & 0x3f) <<  5) |
          ((unsigned short)((b >> 3) & 0x1f)      ));
}

static inline unsigned short pack_rgba4(int r, int g, int b, int a)
{
   return(((unsigned short)((a >> 4) & 0x0f) << 12) |
          ((unsigned short)((r >> 4) & 0x0f) <<  8) |
          ((unsigned short)((g >> 4) & 0x0f) <<  4) |
          ((unsigned short)((b >> 4) & 0x0f)      ));
}

static inline unsigned short pack_rgb5a1(int r, int g, int b, int a)
{
   return(((unsigned short)((a >> 7) & 0x01) << 15) |
          ((unsigned short)((r >> 3) & 0x1f) << 10) |
          ((unsigned short)((g >> 3) & 0x1f) <<  5) |
          ((unsigned short)((b >> 3) & 0x1f)      ));
}

static inline unsigned int pack_rgb10a2(int r, int g, int b, int a)
{
   return(((unsigned int)((a >> 6) & 0x003) << 30) |
          ((unsigned int)((r << 2) & 0x3ff) << 20) |
          ((unsigned int)((g << 2) & 0x3ff) << 10) |
          ((unsigned int)((b << 2) & 0x3ff)      ));
}

static inline unsigned char pack_r3g3b2(int r, int g, int b)
{
   return(((unsigned char)((r >> 5) & 0x07) << 5) |
          ((unsigned char)((g >> 5) & 0x07) << 2) |
          ((unsigned char)((b >> 6) & 0x03)     ));
}

#endif