/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : CaptureLdd1.h
**     Project     : Pre1Motor1.0
**     Processor   : MK64FN1M0VLL12
**     Component   : Capture_LDD
**     Version     : Component 01.010, Driver 01.02, CPU db: 3.00.000
**     Compiler    : CodeWarrior ARM C Compiler
**     Date/Time   : 2017-11-16, 18:35, # CodeGen: 125
**     Abstract    :
**          This component "Capture_LDD" simply implements the capture function
**          of timer. The counter counts the same way as in free run mode. On
**          the selected edge of the input signal (on the input pin), the current
**          content of the counter register is written into the capture
**          register and the OnCapture event is called.
**          This Capture component provides a high level API for unified
**          hardware access to various timer devices using the TimerUnit
**          component.
**     Settings    :
**          Component name                                 : CaptureLdd1
**          Capture device                                 : FTM3_C0V
**          Counter                                        : FTM3_CNT
**          Counter direction                              : Up
**          Counter width                                  : 16 bits
**          Value type                                     : uint16_t
**          Interrupt service/event                        : Enabled
**            Interrupt                                    : INT_FTM3
**            Interrupt priority                           : high priority
**          Event                                          : 
**            Input pin                                    : PTD0/LLWU_P12/SPI0_PCS0/UART2_RTS_b/FTM3_CH0/FB_ALE/FB_CS1_b/FB_TS_b
**            Input pin signal                             : 
**            Edge                                         : both edges
**            Maximum time of event                        : 2 sec
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : yes
**            Event mask                                   : 
**              OnCapture                                  : Enabled
**              OnOverrun                                  : Disabled
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component disabled
**            Clock configuration 2                        : This component disabled
**            Clock configuration 3                        : This component disabled
**            Clock configuration 4                        : This component disabled
**            Clock configuration 5                        : This component disabled
**            Clock configuration 6                        : This component disabled
**            Clock configuration 7                        : This component disabled
**          Referenced components                          : 
**            Linked TimerUnit                             : TPulsos
**     Contents    :
**         Init            - LDD_TDeviceData* CaptureLdd1_Init(LDD_TUserData *UserDataPtr);
**         Reset           - LDD_TError CaptureLdd1_Reset(LDD_TDeviceData *DeviceDataPtr);
**         GetCaptureValue - LDD_TError CaptureLdd1_GetCaptureValue(LDD_TDeviceData *DeviceDataPtr,...
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
** @file CaptureLdd1.h
** @version 01.02
** @brief
**          This component "Capture_LDD" simply implements the capture function
**          of timer. The counter counts the same way as in free run mode. On
**          the selected edge of the input signal (on the input pin), the current
**          content of the counter register is written into the capture
**          register and the OnCapture event is called.
**          This Capture component provides a high level API for unified
**          hardware access to various timer devices using the TimerUnit
**          component.
*/         
/*!
**  @addtogroup CaptureLdd1_module CaptureLdd1 module documentation
**  @{
*/         

#ifndef __CaptureLdd1_H
#define __CaptureLdd1_H

/* MODULE CaptureLdd1. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "TPulsos.h"

#include "Cpu.h"

#ifdef __cplusplus
extern "C" {
#endif 


#ifndef __BWUserType_CaptureLdd1_TValueType
#define __BWUserType_CaptureLdd1_TValueType
  typedef uint16_t CaptureLdd1_TValueType ; /* Type for data parameters of methods */
#endif

#define CaptureLdd1_CNT_INP_FREQ_U TPulsos_CNT_INP_FREQ_U_0 /* Counter input frequency in Hz */
#define CaptureLdd1_CNT_INP_FREQ_R TPulsos_CNT_INP_FREQ_R_0 /* Counter input frequency in Hz */
#define CaptureLdd1_COUNTER_WIDTH 0x10U /* Counter width in bits  */
#define CaptureLdd1_COUNTER_DIR DIR_UP /* Direction of counting */
/*! Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define CaptureLdd1_PRPH_BASE_ADDRESS  0x400B9000U
  
/*! Device data structure pointer used when auto initialization property is enabled. This constant can be passed as a first parameter to all component's methods. */
#define CaptureLdd1_DeviceData  ((LDD_TDeviceData *)PE_LDD_GetDeviceStructure(PE_LDD_COMPONENT_CaptureLdd1_ID))

/* Methods configuration constants - generated for all enabled component's methods */
#define CaptureLdd1_Init_METHOD_ENABLED /*!< Init method of the component CaptureLdd1 is enabled (generated) */
#define CaptureLdd1_Reset_METHOD_ENABLED /*!< Reset method of the component CaptureLdd1 is enabled (generated) */
#define CaptureLdd1_GetCaptureValue_METHOD_ENABLED /*!< GetCaptureValue method of the component CaptureLdd1 is enabled (generated) */

/* Events configuration constants - generated for all enabled component's events */
#define CaptureLdd1_OnCapture_EVENT_ENABLED /*!< OnCapture event of the component CaptureLdd1 is enabled (generated) */



/*
** ===================================================================
**     Method      :  CaptureLdd1_Init (component Capture_LDD)
*/
/*!
**     @brief
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc. If the
**         property ["Enable in init. code"] is set to "yes" value then
**         the device is also enabled (see the description of the
**         [Enable] method). In this case the [Enable] method is not
**         necessary and needn't to be generated. This method can be
**         called only once. Before the second call of Init the [Deinit]
**         must be called first.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     @return
**                         - Pointer to the dynamically allocated private
**                           structure or NULL if there was an error.
*/
/* ===================================================================*/
LDD_TDeviceData* CaptureLdd1_Init(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Method      :  CaptureLdd1_Reset (component Capture_LDD)
*/
/*!
**     @brief
**         This method resets the counter register (see implementation
**         note in [General Info]).
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
*/
/* ===================================================================*/
LDD_TError CaptureLdd1_Reset(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  CaptureLdd1_GetCaptureValue (component Capture_LDD)
*/
/*!
**     @brief
**         This method gets the last value captured by enabled timer
**         (see implementation note in [General Info]). The method does
**         not return valid value after initialization or after [Reset]
**         until new capture event (even if the returned Error code is
**         ERR_OK).
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         ValuePtr        - A pointer to the content of the
**                           capture register
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
*/
/* ===================================================================*/
LDD_TError CaptureLdd1_GetCaptureValue(LDD_TDeviceData *DeviceDataPtr, CaptureLdd1_TValueType *ValuePtr);

/*
** ===================================================================
**     Method      :  CaptureLdd1_TPulsos_OnChannel0 (component Capture_LDD)
**
**     Description :
**         The method services the event of the linked component TPulsos 
**         and eventually invokes event CaptureLdd1_OnCapture.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void TPulsos_OnChannel0(LDD_TUserData *UserDataPtr);

/* END CaptureLdd1. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __CaptureLdd1_H */
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
