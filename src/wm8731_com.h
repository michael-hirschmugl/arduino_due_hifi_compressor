/*
  wm8731_com.h
*/

#ifndef WM8731_COM_H
#define WM8731_COM_H

/* Device Address */
#define TWI1_MMR_DADR           0x1AU

#include <stdint.h>
//#include "sam3x8e_register_definitions.h"
//#include "sam3x8e_setup_definitions.h"
//#include "wm8731_setup_definitions.h"

class WM8731_COMClass {
public:
	WM8731_COMClass(void) { };

//        void init_twi1_clk(void);
//        void init_twi1(void);
//        void setup_pio_for_twi1(void);
//        void setup_twi1_master_transfer(void);
        uint8_t set_wm8731(uint8_t, uint8_t);
//        uint16_t setup_WM8731(void);


private:

};

extern WM8731_COMClass WM8731_COM;

#endif