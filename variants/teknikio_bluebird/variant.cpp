/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.
  Copyright (c) 2016 Sandeep Mistry All right reserved.
  Copyright (c) 2018, Adafruit Industries (adafruit.com)

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
//Bluebird

#include "variant.h"
#include "wiring_constants.h"
#include "wiring_digital.h"
#include "nrf.h"

const uint32_t g_ADigitalPinMap[] =
{
  // P0
  29, //IO1
  31, //IO2
  2,  //IO3
  3,  //IO4
  4,
  5,
  6,
  7,
  8,
  11,
  28,//COLOR SENSOR
  30,//COLOR SENSOR ENABLE

  // P1
  40, //P1.08
  41, //P1.09
  42,//ACCELEROMETER INTERRUPT
  47,//SPEAKER
  43,//ACCELEROMETER SCL
  44,//ACCELEROMETER SDA
};


void initVariant()
{
}
