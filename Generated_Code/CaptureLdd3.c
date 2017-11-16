/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : CaptureLdd3.c
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
**          Component name                                 : CaptureLdd3
**          Capture device                                 : FTM3_C2V
**          Counter                                        : FTM3_CNT
**          Counter direction                              : Up
**          Counter width                                  : 16 bits
**          Value type                                     : uint16_t
**          Interrupt service/event                        : Enabled
**            Interrupt                                    : INT_FTM3
**            Interrupt priority                           : high priority
**          Event                                          : 
**            Input pin                                    : PTD2/LLWU_P13/SPI0_SOUT/UART2_RX/FTM3_CH2/FB_AD4/I2C0_SCL
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
**         Init            - LDD_TDeviceData* CaptureLdd3_Init(LDD_TUserData *UserDataPtr);
**         Reset           - LDD_TError CaptureLdd3_Reset(LDD_TDeviceData *DeviceDataPtr);
**         GetCaptureValue - LDD_TError CaptureLdd3_GetCaptureValue(LDD_TDeviceData *DeviceDataPtr,...
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
** @file CaptureLdd3.c
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
**  @addtogroup CaptureLdd3_module CaptureLdd3 module documentation
**  @{
*/         

/* MODULE CaptureLdd3. */

#include "Input_Encoder_TI.h"
#include "CaptureLdd3.h"
/* {Default RTOS Adapter} No RTOS includes */

#ifdef __cplusplus
extern "C" {
#endif 

typedef struct {
  LDD_TDeviceData *LinkedDeviceDataPtr;
  bool EnUser;                         /* Enable/Disable device */
  LDD_TimerUnit_TEdge Edge;            /* Type of the signal edges that are captured */
  uint16_t CntrState;                  /* Content of counter */
  LDD_TEventMask EnEvents;             /* Enable/Disable events mask */
  LDD_TUserData *UserDataPtr;          /* RTOS device data structure */
} CaptureLdd3_TDeviceData;

typedef CaptureLdd3_TDeviceData *CaptureLdd3_TDeviceDataPtr; /* Pointer to the device data structure. */

/* {Default RTOS Adapter} Static object used for simulation of dynamic driver memory allocation */
static CaptureLdd3_TDeviceData DeviceDataPrv__DEFAULT_RTOS_ALLOC;

#define CHANNEL 0x02U
#define AVAILABLE_EVENTS_MASK (LDD_TEventMask)(LDD_CAPTURE_ON_CAPTURE)
/*
** ===================================================================
**     Method      :  CaptureLdd3_Init (component Capture_LDD)
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
LDD_TDeviceData* CaptureLdd3_Init(LDD_TUserData *UserDataPtr)
{
  /* Allocate device structure */
  CaptureLdd3_TDeviceData *DeviceDataPrv;
  /* {Default RTOS Adapter} Driver memory allocation: Dynamic allocation is simulated by a pointer to the static object */
  DeviceDataPrv = &DeviceDataPrv__DEFAULT_RTOS_ALLOC;
  DeviceDataPrv->UserDataPtr = UserDataPtr; /* Store the RTOS device structure */
  DeviceDataPrv->EnEvents = 0x01u;     /* Initial event mask */
  DeviceDataPrv->Edge = EDGE_BOTH;     /* Initial type of edge */
  DeviceDataPrv->CntrState = 0U;       /* Initial state of variable */
  DeviceDataPrv->EnUser = TRUE;        /* Set the flag "device enabled" */
  /* Registration of the device structure */
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_CaptureLdd3_ID,DeviceDataPrv);
  DeviceDataPrv->LinkedDeviceDataPtr = TPulsos_Init((LDD_TUserData *)NULL);
  if (DeviceDataPrv->LinkedDeviceDataPtr == NULL) { /* Is initialization of TimerUnit unsuccessful? */
    /* Unregistration of the device structure */
    PE_LDD_UnregisterDeviceStructure(PE_LDD_COMPONENT_CaptureLdd3_ID);
    /* Deallocation of the device structure */
    /* {Default RTOS Adapter} Driver memory deallocation: Dynamic allocation is simulated, no deallocation code is generated */
    return NULL;                       /* If so, then the Capture initialization is also unsuccessful */
  }
  (void)TPulsos_SelectCaptureEdge(DeviceDataPrv->LinkedDeviceDataPtr, CHANNEL, DeviceDataPrv->Edge); /* Enable capture */
  return ((LDD_TDeviceData *)DeviceDataPrv); /* Return pointer to the device data structure */
}

/*
** ===================================================================
**     Method      :  CaptureLdd3_Reset (component Capture_LDD)
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
LDD_TError CaptureLdd3_Reset(LDD_TDeviceData *DeviceDataPtr)
{
  CaptureLdd3_TDeviceData *DeviceDataPrv = (CaptureLdd3_TDeviceData *)DeviceDataPtr;

  DeviceDataPrv->CntrState = TPulsos_GetCounterValue(DeviceDataPrv->LinkedDeviceDataPtr); /* Load content of counter register to variable CntrState */
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  CaptureLdd3_GetCaptureValue (component Capture_LDD)
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
LDD_TError CaptureLdd3_GetCaptureValue(LDD_TDeviceData *DeviceDataPtr, CaptureLdd3_TValueType *ValuePtr)
{
  CaptureLdd3_TDeviceData *DeviceDataPrv = (CaptureLdd3_TDeviceData *)DeviceDataPtr;
  uint16_t Ticks;

  (void)TPulsos_GetCaptureValue(DeviceDataPrv->LinkedDeviceDataPtr, CHANNEL, &Ticks);
  Ticks -= DeviceDataPrv->CntrState;
  *ValuePtr = (CaptureLdd3_TValueType) Ticks;
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  CaptureLdd3_TPulsos_OnChannel2 (component Capture_LDD)
**
**     Description :
**         The method services the event of the linked component TPulsos 
**         and eventually invokes event CaptureLdd3_OnCapture.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void TPulsos_OnChannel2(LDD_TUserData *UserDataPtr)
{
  CaptureLdd3_TDeviceData *DeviceDataPrv = PE_LDD_DeviceDataList[PE_LDD_COMPONENT_CaptureLdd3_ID];

  (void)UserDataPtr;                   /* Parameter is not used, suppress unused argument warning */
  if (DeviceDataPrv->EnEvents & LDD_CAPTURE_ON_CAPTURE) { /* Is the event enabled? */
    CaptureLdd3_OnCapture(DeviceDataPrv->UserDataPtr); /* Invoke OnOverrun event */
  }
}

/* END CaptureLdd3. */

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
