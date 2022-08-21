#include <stdint.h>
#include "intrinsics.h"
#include "sam3x8e_setup.h"
#include "sam3x8e_wdt.h"
#include "sam3x8e_twi.h"
#include "sam3x8e_ssc.h"
#include "sam3x8e_adc.h"
#include "sam3x8e_din.h"
#include "wm8731_config.h"

using namespace std;

void init_clock_for_wm8731(void);

class SSC1
{
public:
    static void Handler();
    static volatile unsigned int ticks;
};

void SSC1::Handler()
{
}

int main()
{
  volatile uint8_t vol = 0x17U;
  
  __disable_interrupt();

  SAM3X8E_WDT.disable_watchdog_timer();

  SAM3X8E_SETUP.init_clock();
    
  init_clock_for_wm8731();
    
    
  SAM3X8E_TWI.init_twi1();
  SAM3X8E_TWI.setup_twi1_master_transfer();
  WM8731_CONFIG.fullSetup();
  
  __enable_interrupt();
    
  WM8731_COM.set_wm8731(0x00U, 0x00U);

  while(1)
  {
    WM8731_CONFIG.setVolume(vol);
    WM8731_CONFIG.setBypassOn();
    WM8731_CONFIG.setBypassOff();
  }
  
  
  return 0;
}

void init_clock_for_wm8731()
{
  PIOA_WPMR = PIO_WPKEY | WPEN_0;
  PIOA_PDR = ~PIOA_PSR | (1U << 1);  // enable peripheral control
  PIOA_PER = PIOA_PSR & ~(1U << 1);
  PIOA_ABSR |= (1U << 1);  // peripherial B selected
  PIOA_WPMR = PIO_WPKEY | WPEN_1;
    
  PMC_WPMR = PMC_WPKEY | WPEN_0;
  PMC_SCER |=	0x0100U;  // page 558
  PMC_PCK0 = 0x01U;  // main crystak osc = 12Mhz
  PMC_WPMR = PMC_WPKEY | WPEN_1;
}