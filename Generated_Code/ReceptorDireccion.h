/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : ReceptorDireccion.h
**     Project     : Pre1Motor1.0
**     Processor   : MK64FN1M0VLL12
**     Component   : Capture
**     Version     : Component 02.223, Driver 01.01, CPU db: 3.00.000
**     Compiler    : CodeWarrior ARM C Compiler
**     Date/Time   : 2017-07-04, 19:11, # CodeGen: 30
**     Abstract    :
**         This component "Capture" simply implements the capture function
**         of timer. The counter counts the same way as in free run mode. On
**         the selected edge of the input signal (on the input pin), the current
**         content of the counter register is written into the capture
**         register and the OnCapture event is called.
**     Settings    :
**             Timer capture encapsulation : Capture
**
**         Timer
**             Timer                   : FTM2_CNT
**             Counter shared          : No
**
**         High speed mode
**             Prescaler               : divide-by-16
**           Maximal time for capture register
**             microseconds            : ---
**             milliseconds            : 21
**             seconds                 : ---
**             seconds (real)          : 0.021850460908
**             Hz                      : ---
**             kHz                     : ---
**             MHz                     : ---
**
**         Initialization:
**              Timer                  : Enabled
**              Events                 : Enabled
**
**         Timer registers
**              Capture                : FTM2_C1V  [0x4003A018]
**              Counter                : FTM2_CNT  [0x4003A004]
**              Mode                   : FTM2_SC   [0x4003A000]
**              Run                    : FTM2_SC   [0x4003A000]
**              Prescaler              : FTM2_SC   [0x4003A000]
**
**         Used input pin              : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       65            |  PTB19/CAN0_RX/FTM2_CH1/I2S0_TX_FS/FB_OE_b/FTM2_QD_PHB
**             ----------------------------------------------------
**
**         Port name                   : PTB
**         Bit number (in port)        : 19
**         Bit mask of the port        : 0x00080000
**
**         Signal edge/level           : both
**         Priority                    : 112
**
**     Contents    :
**         Enable          - byte ReceptorDireccion_Enable(void);
**         Disable         - byte ReceptorDireccion_Disable(void);
**         Reset           - byte ReceptorDireccion_Reset(void);
**         GetCaptureValue - byte ReceptorDireccion_GetCaptureValue(ReceptorDireccion_TCapturedValue *Value);
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file ReceptorDireccion.h
** @version 01.01
** @brief
**         This component "Capture" simply implements the capture function
**         of timer. The counter counts the same way as in free run mode. On
**         the selected edge of the input signal (on the input pin), the current
**         content of the counter register is written into the capture
**         register and the OnCapture event is called.
*/         
/*!
**  @addtogroup ReceptorDireccion_module ReceptorDireccion module documentation
**  @{
*/         

#ifndef __ReceptorDireccion_H
#define __ReceptorDireccion_H

/* MODULE ReceptorDireccion. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "CaptureLdd6.h"

#include "Cpu.h"

#ifdef __cplusplus
extern "C" {
#endif 

#ifndef __BWUserType_ReceptorDireccion_TCapturedValue
#define __BWUserType_ReceptorDireccion_TCapturedValue
  typedef uint16_t ReceptorDireccion_TCapturedValue; /* Captured value, unsigned integer value. Bit-width of the type depends on the width of selected timer. */
#endif

#define ReceptorDireccion_PRESCALER_VALUE 0x10UL /* Initial prescaler value of the timer. It is available only if the component is enabled in high speed mode. */
#define ReceptorDireccion_PRESCALER_VALUE_HIGH 0x10UL /* Prescaler value of the timer in high speed mode. It is available only if the component is enabled in high speed mode. */
#define ReceptorDireccion_COUNTER_INPUT_CLOCK_HZ CaptureLdd6_CNT_INP_FREQ_U /* Initial counter input clock frequency [Hz] (integer number). It is available only if the component is enabled in high speed mode. */
#define ReceptorDireccion_COUNTER_INPUT_CLOCK_HZ_HIGH CaptureLdd6_CNT_INP_FREQ_U_CFG_0 /* Counter input clock frequency in high speed mode [Hz] (integer number). It is available only if the component is enabled in high speed mode. */


/*
** ===================================================================
**     Method      :  ReceptorDireccion_Enable (component Capture)
**     Description :
**         This method enables the component - it starts the capture.
**         Events may be generated (<DisableEvent>/<EnableEvent>).
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
#define ReceptorDireccion_Enable() (CaptureLdd6_Enable(CaptureLdd6_DeviceData))

/*
** ===================================================================
**     Method      :  ReceptorDireccion_Disable (component Capture)
**     Description :
**         This method disables the component - it stops the capture.
**         No events will be generated.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
#define ReceptorDireccion_Disable() (CaptureLdd6_Disable(CaptureLdd6_DeviceData))

/*
** ===================================================================
**     Method      :  ReceptorDireccion_Reset (component Capture)
**     Description :
**         This method resets the counter register (see implementation
**         note in <General Info>).
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
#define ReceptorDireccion_Reset() (CaptureLdd6_Reset(CaptureLdd6_DeviceData))

/*
** ===================================================================
**     Method      :  ReceptorDireccion_GetCaptureValue (component Capture)
**     Description :
**         This method gets the last value captured by enabled timer.
**         Note: one tick of timer is
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Value           - A pointer to the content of the
**                           capture register
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
#define ReceptorDireccion_GetCaptureValue(Value) (CaptureLdd6_GetCaptureValue(CaptureLdd6_DeviceData, Value))

/*
** ===================================================================
**     Method      :  ReceptorDireccion_OnCapture (component Capture)
**
**     Description :
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void CaptureLdd6_OnCapture(LDD_TUserData *UserDataPtr);

/* END ReceptorDireccion. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __ReceptorDireccion_H */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
