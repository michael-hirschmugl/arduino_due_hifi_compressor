/**************************************************
 *
 * This file contains the vector table for the SAM3X8E.
 * Not all available interrupt vectors are implemented.
 * This file was changed from a template file, which is provided with
 * IAR Workbench.
 *
 * Changes by Michael Hirschmugl
 * Copyright 2007 IAR Systems. All rights reserved.
 *
 * $Revision: 41481 $
 *
 **************************************************/
   
#pragma language=extended
#pragma segment="CSTACK"

extern "C" void __iar_program_start( void );

class NMI
{
public:
    static void Handler();
};

class HardFault
{
public:
    static void Handler();
};

class MemManage
{
public:
    static void Handler();
};

class BusFault
{
public:
    static void Handler();
};

class UsageFault
{
public:
    static void Handler();
};

class SVC
{
public:
    static void Handler();
};

class TWI1
{
public:
    static void Handler();
};

class SSC1
{
public:
    static void Handler();
};

class PIOD
{
public:
    static void Handler();
};

class DMAC
{
public:
    static void Handler();
};

class DebugMon
{
public:
    static void Handler();
};

class PendSV
{
public:
    static void Handler();
};

class SystemTick
{
public:
    static void Handler();
};

typedef void( *intfunc )( void );
typedef union { intfunc __fun; void * __ptr; } intvec_elem;

// The vector table is normally located at address 0.
// When debugging in RAM, it can be located in RAM, aligned to at least 2^6.
// If you need to define interrupt service routines,
// make a copy of this file and include it in your project.
// The name "__vector_table" has special meaning for C-SPY:
// it is where the SP start value is found, and the NVIC vector
// table register (VTOR) is initialized to this address if != 0.

#pragma location = ".intvec"
extern "C" const intvec_elem __vector_table[] =
{
  { .__ptr = __sfe( "CSTACK" ) },
  __iar_program_start,

  NMI::Handler,
  HardFault::Handler,
  MemManage::Handler,
  BusFault::Handler,
  UsageFault::Handler,
  0,
  0,
  0,
  0,
  SVC::Handler,
  DebugMon::Handler,
  0,
  PendSV::Handler,
  SystemTick::Handler,
  0,  //0
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,  //10
  0,
  0,
  0,
  PIOD::Handler,
  0,
  0,
  0,
  0,
  0,
  0,  //20
  0,
  0,
  TWI1::Handler,
  0,
  0,
  SSC1::Handler,
  0,
  0,
  0,
  0,  //30
  0,
  0,
  0,
  0,
  0,  //35
  0,
  0,
  0,
  DMAC::Handler  //ISR 37 but PID 39

};

__weak void NMI::Handler()          { while (1) {} }
__weak void HardFault::Handler()    { while (1) {} }
__weak void MemManage::Handler()    { while (1) {} }
__weak void BusFault::Handler()     { while (1) {} }
__weak void UsageFault::Handler()   { while (1) {} }
__weak void SVC::Handler()          { while (1) {} }
__weak void TWI1::Handler()          { while (1) {} }
__weak void SSC1::Handler()          { while (1) {} }
__weak void PIOD::Handler()          { while (1) {} }
__weak void DMAC::Handler()          { while (1) {} }
__weak void DebugMon::Handler()     { while (1) {} }
__weak void PendSV::Handler()       { while (1) {} }
__weak void SystemTick::Handler()      { while (1) {} }


extern "C" void __cmain( void );
extern "C" __weak void __iar_init_core( void );
extern "C" __weak void __iar_init_vfp( void );

#pragma required=__vector_table
void __iar_program_start( void )
{
  __iar_init_core();
  __iar_init_vfp();
  __cmain();
}
