/*
  wm8731_config.cpp

  Configuration of the WM8731 Codec.

  By Michael Hirschmugl
*/

#include "wm8731_config.h"

/*

*/
uint8_t WM8731_CONFIGClass::setVolumeL(uint8_t vol)
{
  iLINVOL = vol;
  WM8731_COM.set_wm8731(0x00U, ((iLRINBOTH << 8)|(iLINMUTE << 7)|(iLINVOL << 0)));
  return 0;
}
    
/*

*/
uint8_t WM8731_CONFIGClass::setVolumeR(uint8_t vol)
{
  iRINVOL = vol;
  WM8731_COM.set_wm8731(0x02U, ((iRLINBOTH << 8)|(iRINMUTE << 7)|(iRINVOL << 0)));
  return 0;
}

/*

*/
uint8_t WM8731_CONFIGClass::setVolume(uint8_t vol)
{
  iLINVOL = vol;
  iRINVOL = vol;
  WM8731_COM.set_wm8731(0x00U, ((iLRINBOTH << 8)|(iLINMUTE << 7)|(iLINVOL << 0)));
  WM8731_COM.set_wm8731(0x02U, ((iRLINBOTH << 8)|(iRINMUTE << 7)|(iRINVOL << 0)));
  return 0;
}

/*

*/
uint8_t WM8731_CONFIGClass::setBypassOn(void)
{
  iBYPASS = 0x01U;
  WM8731_COM.set_wm8731(0x08U, ((iSIDEATT << 6)|(iSIDETONE << 5)|(iDACSEL << 4)|(iBYPASS << 3)|(iINSEL << 2)|(iMUTEMIC << 1)|(iMICBOOST << 0)));
  return 0;
}

/*

*/
uint8_t WM8731_CONFIGClass::setBypassOff(void)
{
  iBYPASS = 0x00U;
  WM8731_COM.set_wm8731(0x08U, ((iSIDEATT << 6)|(iSIDETONE << 5)|(iDACSEL << 4)|(iBYPASS << 3)|(iINSEL << 2)|(iMUTEMIC << 1)|(iMICBOOST << 0)));
  return 0;
}

/*
  This function sends all configuration data to the WM8731 chip.
  Returns an integer with a 1 at some position to indicate a time-out error.
*/
uint8_t WM8731_CONFIGClass::fullSetup(void)
{
    WM8731_COM.set_wm8731(0x0CU, ((iPWROFF << 7)|(iCLKOUTPUT << 6)|(iOSCPD << 5)|(iOUTPD << 4)|(iDACPD << 3)|(iADCPD << 2)|(iMICPD << 1)|(iLINEINPD << 0)));
    WM8731_COM.set_wm8731(0x0EU, ((iBCLKINV << 7)|(iMS << 6)|(iLRSWAP << 5)|(iLRP << 4)|(iIWL << 2)|(iFORMAT << 0)));
    WM8731_COM.set_wm8731(0x00U, ((iLRINBOTH << 8)|(iLINMUTE << 7)|(iLINVOL << 0)));
    WM8731_COM.set_wm8731(0x02U, ((iRLINBOTH << 8)|(iRINMUTE << 7)|(iRINVOL << 0)));
    WM8731_COM.set_wm8731(0x04U, ((iLRHPBOTH << 8)|(iLZCEN << 7)|(iLHPVOL << 0)));
    WM8731_COM.set_wm8731(0x06U, ((iRLHPBOTH << 8)|(iRZCEN << 7)|(iRHPVOL << 0)));
    WM8731_COM.set_wm8731(0x0AU, ((iHPOR << 4)|(iDACMU << 3)|(iDEEMPH << 1)|(iADCHPD << 0)));
    WM8731_COM.set_wm8731(0x08U, ((iSIDEATT << 6)|(iSIDETONE << 5)|(iDACSEL << 4)|(iBYPASS << 3)|(iINSEL << 2)|(iMUTEMIC << 1)|(iMICBOOST << 0)));
    WM8731_COM.set_wm8731(0x10U, ((iCLKODIV2 << 7)|(iCLKIDIV2 << 6)|(iSR << 2)|(iBOSR << 1)|(iUSB << 0)));
    WM8731_COM.set_wm8731(0x12U, (iACTIVE << 0));

    return 0;
}

/*
    Enables the peripheral clock for TWI1.
*/
//void SAM3X8E_TWIClass::init_twi1_clk(void)
//{
//    PMC_WPMR = PMC_WPKEY | WPEN_0;
//    PMC_PCER0 = PMC_PCSR0 | TWI1_PID;
//    PMC_WPMR = PMC_WPKEY | WPEN_1;
//}

/*
    Initializes the TWI1 controller.
*/
//void SAM3X8E_TWIClass::init_twi1(void)
//{
//    init_twi1_clk();
//    setup_pio_for_twi1();
//}

/*
    The two pins for TWI1 are configured.
    Peripheral control is disabled and peripheral function A is chosen.
*/
//void SAM3X8E_TWIClass::setup_pio_for_twi1(void)
//{
//    PIOB_WPMR = PIO_WPKEY | WPEN_0;
//    PIOB_PDR = (1U << 12);
//    PIOB_PDR = (1U << 13);
//    PIOB_ABSR = (0U << 12);
//    PIOB_ABSR = (0U << 13);
//    PIOB_WPMR = PIO_WPKEY | WPEN_1;
//}

/*
    Configures TWI1 for master mode transfer.
*/
//void SAM3X8E_TWIClass::setup_twi1_master_transfer(void)
//{
//    TWI1_CR = TWI1_CR_SWRST;  // Reset
//    /*
//        CLDIV, CHDIV and CKDIV values are copied from ASF.
//    */
//    TWI1_CWGR = TWI1_CWGR_CLDIV | TWI1_CWGR_CHDIV | TWI1_CWGR_CKDIV;
//    TWI1_CR = TWI1_CR_MSEN | TWI1_CR_SVDIS;  // enables master mode
//    /*
//        enables master write mode.
//        Also, DADR is the adress of the device the communication
//        will go to.
//        The WM8731 has a hardwired adress of 0x1A.
//    */
//    TWI1_MMR = TWI1_MMR_MREAD | TWI1_MMR_DADR;
//}

/*
  Sends two bytes on the TW1 interface to a hard coded adress.
  The adress is defined in TWI1_MMR_DADR.
  returns 1 for a time-out.
  returns 0 if OK
*/
//uint8_t SAM3X8E_TWIClass::send_two_bytes_to_wm8731(uint8_t byte1, uint8_t byte2)
//{
//    uint16_t i = 0;
//    TWI1_THR = byte1;
//
//    while((TWI1_SR & TWI1_SR_TXRDY) != TWI1_SR_TXRDY)
//    {
//        if(i++ > GLOBAL_TIMEOUT)
//        {
//            return 1;
//        }
//    }
//    i = 0;
//
//    TWI1_THR = byte2;
//    
//    while((TWI1_SR & TWI1_SR_TXRDY) != TWI1_SR_TXRDY)
//    {
//        if(i++ > GLOBAL_TIMEOUT)
//        {
//            return 1;
//        }
//    }
//    i = 0;
//    
//    TWI1_CR = TWI1_CR_STOP;
//    
//    while((TWI1_SR & TWI1_SR_TXCOMP) != TWI1_SR_TXCOMP)
//    {
//        if(i++ > GLOBAL_TIMEOUT)
//        {
//            return 1;
//        }
//    }
//    
//    if((TWI1_SR & TWI1_SR_NACK) == TWI1_SR_NACK)
//    {
//        return 1;
//    }
//    
//    return 0;
//
//}

/*
  This function sends all configuration data to the WM8731 chip.
  Returns an integer with a 1 at some position to indicate a time-out error.
*/
//uint16_t SAM3X8E_TWIClass::setup_WM8731(void)
//{
//    uint16_t i = 0;
//    
//    i |= (send_two_bytes_to_wm8731(0x0CU,
//                                  ((PWROFF << 7)|
//                                   (CLKOUTPUT << 6)|
//                                   (OSCPD << 5)|
//                                   (OUTPD << 4)|
//                                   (DACPD << 3)|
//                                   (ADCPD << 2)|
//                                   (MICPD << 1)|
//                                   (LINEINPD << 0))) << 0 );
//    i |= (send_two_bytes_to_wm8731(0x0EU,
//                                  ((BCLKINV << 7)|
//                                   (MS << 6)|
//                                   (LRSWAP << 5)|
//                                   (LRP << 4)|
//                                   (IWL << 2)|
//                                   (FORMAT << 0))) << 1);
//    i |= (send_two_bytes_to_wm8731(0x00U,
//                                  ((LRINBOTH << 8)|
//                                   (LINMUTE << 7)|
//                                   (LINVOL << 0))) << 2);
//    i |= (send_two_bytes_to_wm8731(0x02U,
//                                  ((RLINBOTH << 8)|
//                                   (RINMUTE << 7)|
//                                   (RINVOL << 0))) << 3);
//    i |= (send_two_bytes_to_wm8731(0x04U,
//                                  ((LRHPBOTH << 8)|
//                                   (LZCEN << 7)|
//                                   (LHPVOL << 0))) << 4);
//    i |= (send_two_bytes_to_wm8731(0x06U,
//                                  ((RLHPBOTH << 8)|
//                                   (RZCEN << 7)|
//                                   (RHPVOL << 0))) << 5);
//    i |= (send_two_bytes_to_wm8731(0x0AU,
//                                  ((HPOR << 4)|
//                                   (DACMU << 3)|
//                                   (DEEMPH << 1)|
//                                   (ADCHPD << 0))) << 6);
//    i |= (send_two_bytes_to_wm8731(0x08U,
//                                  ((SIDEATT << 6)|
//                                   (SIDETONE << 5)|
//                                   (DACSEL << 4)|
//                                   (BYPASS << 3)|
//                                   (INSEL << 2)|
//                                   (MUTEMIC << 1)|
//                                   (MICBOOST << 0))) << 7);
//    i |= (send_two_bytes_to_wm8731(0x10U,
//                                  ((CLKODIV2 << 7)|
//                                   (CLKIDIV2 << 6)|
//                                   (SR << 2)|
//                                   (BOSR << 1)|
//                                   (USB << 0))) << 8);
//    i |= (send_two_bytes_to_wm8731(0x12U, (ACTIVE << 0)) << 9);
//
//    return i;
//}

// Create object
WM8731_CONFIGClass WM8731_CONFIG = WM8731_CONFIGClass();