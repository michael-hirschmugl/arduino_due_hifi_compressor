/*
  wm8731_config.h
*/

#ifndef WM8731_CONFIG_H
#define WM8731_CONFIG_H

#include <stdint.h>
#include "wm8731_com.h"
//#include "sam3x8e_register_definitions.h"
//#include "sam3x8e_setup_definitions.h"
#include "wm8731_setup_definitions.h"

class WM8731_CONFIGClass {
public:
	WM8731_CONFIGClass(void) { };

//        void init_twi1_clk(void);
//        void init_twi1(void);
//        void setup_pio_for_twi1(void);
//        void setup_twi1_master_transfer(void);
//        uint8_t send_two_bytes_to_wm8731(uint8_t, uint8_t);
//        uint16_t setup_WM8731(void);
        uint8_t setVolumeL(uint8_t);
        uint8_t setVolumeR(uint8_t);
        uint8_t setVolume(uint8_t);
        uint8_t setBypassOn();
        uint8_t setBypassOff();
        uint8_t fullSetup();


private:
  uint8_t iLRINBOTH = LRINBOTH;
  uint8_t iLINMUTE = LINMUTE;
  uint8_t iLINVOL = LINVOL;
  uint8_t iRLINBOTH = RLINBOTH;
  uint8_t iRINMUTE = RINMUTE;
  uint8_t iRINVOL = RINVOL;
  uint8_t iLRHPBOTH = LRHPBOTH;
  uint8_t iLZCEN = LZCEN;
  uint8_t iLHPVOL = LHPVOL;
  uint8_t iRLHPBOTH = RLHPBOTH;
  uint8_t iRZCEN = RZCEN;
  uint8_t iRHPVOL = RHPVOL;
  uint8_t iSIDEATT = SIDEATT;
  uint8_t iSIDETONE = SIDETONE;
  uint8_t iDACSEL = DACSEL;
  uint8_t iBYPASS = BYPASS;
  uint8_t iINSEL = INSEL;
  uint8_t iMUTEMIC = MUTEMIC;
  uint8_t iMICBOOST = MICBOOST;
  uint8_t iHPOR = HPOR;
  uint8_t iDACMU = DACMU;
  uint8_t iDEEMPH = DEEMPH;
  uint8_t iADCHPD = ADCHPD;
  uint8_t iPWROFF = PWROFF;
  uint8_t iCLKOUTPUT = CLKOUTPUT;
  uint8_t iOSCPD = OSCPD;
  uint8_t iOUTPD = OUTPD;
  uint8_t iDACPD = DACPD;
  uint8_t iADCPD = ADCPD;
  uint8_t iMICPD = MICPD;
  uint8_t iLINEINPD = LINEINPD;
  uint8_t iBCLKINV = BCLKINV;
  uint8_t iMS = MS;
  uint8_t iLRSWAP = LRSWAP;
  uint8_t iLRP = LRP;
  uint8_t iIWL = IWL;
  uint8_t iFORMAT = FORMAT;
  uint8_t iCLKODIV2 = CLKODIV2;
  uint8_t iCLKIDIV2 = CLKIDIV2;
  uint8_t iSR = SR;
  uint8_t iBOSR = BOSR;
  uint8_t iUSB = USB;
  uint8_t iACTIVE = ACTIVE;

};

extern WM8731_CONFIGClass WM8731_CONFIG;

#endif