/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Input_Encoder_DI.c
**     Project     : Pre1Motor1.0
**     Processor   : MK64FN1M0VLL12
**     Component   : Capture
**     Version     : Component 02.223, Driver 01.01, CPU db: 3.00.000
**     Compiler    : CodeWarrior ARM C Compiler
**     Date/Time   : 2017-11-16, 18:35, # CodeGen: 125
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
**             Timer                   : FTM3_CNT
**             Counter shared          : No
**
**         High speed mode
**             Prescaler               : divide-by-128
**           Maximal time for capture register
**             microseconds            : ---
**             milliseconds            : ---
**             seconds                 : 2
**             seconds (real)          : 0.174803687265
**             Hz                      : ---
**             kHz                     : ---
**             MHz                     : ---
**
**         Initialization:
**              Timer                  : Enabled
**              Events                 : Enabled
**
**         Timer registers
**              Capture                : FTM3_C0V  [0x400B9010]
**              Counter                : FTM3_CNT  [0x400B9004]
**              Mode                   : FTM3_SC   [0x400B9000]
**              Run                    : FTM3_SC   [0x400B9000]
**              Prescaler              : FTM3_SC   [0x400B9000]
**
**         Used input pin              : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       93            |  PTD0/LLWU_P12/SPI0_PCS0/UART2_RTS_b/FTM3_CH0/FB_ALE/FB_CS1_b/FB_TS_b
**             ----------------------------------------------------
**
**         Port name                   : PTD
**         Bit number (in port)        : 0
**         Bit mask of the port        : 0x0001
**
**         Signal edge/level           : both
**         Priority                    : 80
**
**     Contents    :
**         Reset           - byte Input_Encoder_DI_Reset(void);
**         GetCaptureValue - byte Input_Encoder_DI_GetCaptureValue(Input_Encoder_DI_TCapturedValue *Value);
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
** @file Input_Encoder_DI.c
** @version 01.01
** @brief
**         This component "Capture" simply implements the capture function
**         of timer. The counter counts the same way as in free run mode. On
**         the selected edge of the input signal (on the input pin), the current
**         content of the counter register is written into the capture
**         register and the OnCapture event is called.
*/         
/*!
**  @addtogroup Input_Encoder_DI_module Input_Encoder_DI module documentation
**  @{
*/         

/* MODULE Input_Encoder_DI. */

#include "Events.h"
#include "Input_Encoder_DI.h"

#ifdef __cplusplus
extern "C" {
#endif 

/*
** ===================================================================
**     Method      :  Input_Encoder_DI_Reset (component Capture)
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
/*
byte Input_Encoder_DI_Reset(void)
**  This method is implemented as a macro. See Input_Encoder_DI.h file.  **
*/

/*
** ===================================================================
**     Method      :  Input_Encoder_DI_GetCaptureValue (component Capture)
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
/*
byte Input_Encoder_DI_GetCaptureValue(Input_Encoder_DI_TCapturedValue *Value)
**  This method is implemented as a macro. See Input_Encoder_DI.h file.  **
*/

/*
** ===================================================================
**     Method      :  Input_Encoder_DI_OnCapture (component Capture)
**
**     Description :
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void CaptureLdd1_OnCapture(LDD_TUserData *UserDataPtr)
{
  (void)UserDataPtr;                   /* Parameter is not used, suppress unused argument warning */
  Input_Encoder_DI_OnCapture();        /* Invoke OnCapture event */
}

/* END Input_Encoder_DI. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

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
