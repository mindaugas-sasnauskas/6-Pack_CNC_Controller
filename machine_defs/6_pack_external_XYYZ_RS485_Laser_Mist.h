#pragma once
// clang-format off

/*
    6_pack_external_XYYZ_RS485_Laser_Mist.h

    Covers all V1 versions V1p0, V1p1, etc

    Part of Grbl_ESP32
    Pin assignments for the ESP32 I2S 6-axis board
    
    2021-08-02 B. Dring for Jim Mires

    Grbl_ESP32 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    Grbl is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with Grbl_ESP32.  If not, see <http://www.gnu.org/licenses/>.
*/
#define MACHINE_NAME            "6 Pack External XYYZ RS485 Mist"

#define N_AXIS 3

// === Special Features

// I2S (steppers & other output-only pins)
#define USE_I2S_OUT
#define USE_I2S_STEPS
//#define DEFAULT_STEPPER ST_I2S_STATIC

#define I2S_OUT_BCK             GPIO_NUM_22
#define I2S_OUT_WS              GPIO_NUM_17
#define I2S_OUT_DATA            GPIO_NUM_21


// Motor Socket #1
#define X_DISABLE_PIN           I2SO(0)
#define X_DIRECTION_PIN         I2SO(1)
#define X_STEP_PIN              I2SO(2)
#define X_STEPPER_MS3           I2SO(3)

// Motor Socket #2
#define Y_DIRECTION_PIN         I2SO(4)
#define Y_STEP_PIN              I2SO(5)
#define Y_STEPPER_MS3           I2SO(6)
#define Y_DISABLE_PIN           I2SO(7)

// Motor Socket #3
#define Y2_DISABLE_PIN           I2SO(8)
#define Y2_DIRECTION_PIN         I2SO(9)
#define Y2_STEP_PIN              I2SO(10)
#define Y2_STEPPER_MS3           I2SO(11)

// Motor Socket #4
#define Z_DIRECTION_PIN         I2SO(12)
#define Z_STEP_PIN              I2SO(13)
#define Z_STEPPER_MS3           I2SO(14) 
#define Z_DISABLE_PIN           I2SO(15)



/*
    Socket I/O reference
    The list of modules is here...
    https://github.com/bdring/6-Pack_CNC_Controller/wiki/CNC-I-O-Module-List
    Click on each module to get example for using the modules in the sockets


Socket #1
#1 GPIO_NUM_33 
#2 GPIO_NUM_32
#3 GPIO_NUM_35 (input only)
#4 GPIO_NUM_34 (input only)

Socket #2
#1 GPIO_NUM_2
#2 GPIO_NUM_25
#3 GPIO_NUM_39 (input only)
#4 GPIO_NUM_36 (input only)

Socket #3
#1 GPIO_NUM_26
#2 GPIO_NUM_4
#3 GPIO_NUM_16
#4 GPIO_NUM_27

Socket #4
#1 GPIO_NUM_14
#2 GPIO_NUM_13
#3 GPIO_NUM_15
#4 GPIO_NUM_12

Socket #5
#1 I2SO(24)  (output only)
#2 I2SO(25)  (output only)
#3 I2SO26)  (output only)

*/

// 4x Input Module in Socket #1
// https://github.com/bdring/6-Pack_CNC_Controller/wiki/4x-Switch-Input-module
#define X_LIMIT_PIN            GPIO_NUM_33
#define Y_LIMIT_PIN            GPIO_NUM_32
#define Y2_LIMIT_PIN           GPIO_NUM_35
#define Z_LIMIT_PIN            GPIO_NUM_34

// 4x Switch Input module  in socket #2
// // https://github.com/bdring/6-Pack_CNC_Controller/wiki/4x-Switch-Input-module
#define PROBE_PIN                     GPIO_NUM_2
#define CONTROL_FEED_HOLD_PIN         GPIO_NUM_25
#define CONTROL_CYCLE_START_PIN       GPIO_NUM_39
///#define    TBD  GPIO_NUM_36

// RS485 Modbus In socket #3
// https://github.com/bdring/6-Pack_CNC_Controller/wiki/RS485-Modbus-Module
#define SPINDLE_TYPE            SpindleType::HUANYANG // default, check actual $Spindle/Type Setting
#define VFD_RS485_TXD_PIN        GPIO_NUM_26
#define VFD_RS485_RTS_PIN        GPIO_NUM_4
#define VFD_RS485_RXD_PIN        GPIO_NUM_16

// 5V output CNC module in socket #4
// https://github.com/bdring/6-Pack_CNC_Controller/wiki/4x-5V-Buffered-Output-Module
#define LASER_OUTPUT_PIN          GPIO_NUM_14
#define LASER_ENABLE_PIN          GPIO_NUM_13 // optional 
#define COOLANT_MIST_PIN          GPIO_NUM_15
#define COOLANT_FLOOD_PIN         GPIO_NUM_12


// === Default settings
#define DEFAULT_STEP_PULSE_MICROSECONDS I2S_OUT_USEC_PER_PULSE

#define DEFAULT_INVERT_LIMIT_PINS       0
#define DEFAULT_INVERT_PROBE_PIN        0

#ifdef INVERT_CONTROL_PIN_MASK
#    undef INVERT_CONTROL_PIN_MASK
#endif
#define INVERT_CONTROL_PIN_MASK B0001

#define DEFAULT_INVERT_LIMIT_PINS       0