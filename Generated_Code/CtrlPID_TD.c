/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : CtrlPID_TD.c
**     CDE edition : Community
**     Project     : Pre1Motor1.0
**     Processor   : MK64FN1M0VLL12
**     Component   : PID_Float
**     Version     : Component 01.006, Driver 01.00, CPU db: 3.00.000
**     Compiler    : CodeWarrior ARM C Compiler
**     Date/Time   : 2017-10-24, 17:09, # CodeGen: 91
**     Abstract    :
**
**     Settings    :
**     Contents    :
**         Control - void CtrlPID_TD_Control(float error, void* *u);
**         Reset   - void CtrlPID_TD_Reset(void);
**         Set_K   - void CtrlPID_TD_Set_K(float k);
**         Set_Ti  - void CtrlPID_TD_Set_Ti(float t);
**         Set_Td  - void CtrlPID_TD_Set_Td(float t);
**
**     * (c) Copyright Carlos Alvarez, 2013
**      * For non-commercial use only.
**      * Web:         https://mcuoneclipse.com
**      * SourceForge: https://sourceforge.net/projects/mcuoneclipse
**      * Git:         https://github.com/ErichStyger/McuOnEclipse_PEx
**      * All rights reserved.
** ###################################################################*/
/*!
** @file CtrlPID_TD.c
** @version 01.00
** @brief
**
*/         
/*!
**  @addtogroup CtrlPID_TD_module CtrlPID_TD module documentation
**  @{
*/         

/* MODULE CtrlPID_TD. */

#include "CtrlPID_TD.h"
#define K_VAL           33 /* Constante proporcional */
#define TI_VAL          0.25 /* Tiempo integrativo */
#define TD_VAL          0 /* Tiempo derivativo */
#define T_VAL           0.1 /* Per�odo de control */
#define U_MIN           0 /* Valor de salida m�nimo */
#define U_MAX           19350 /* Valor de salida m�ximo */
#define U_CHG_MAX       0 /* Cambio m�ximo en cada ciclo de control */
/* Coeficientes del control PID */
#define K1              (CtrlPID_TD_K*(1+(CtrlPID_TD_Td/T_VAL)))
#define K2              (-CtrlPID_TD_K*(1+((2*CtrlPID_TD_Td)/T_VAL)-(T_VAL/CtrlPID_TD_Ti)))
#define K3              (CtrlPID_TD_K*(CtrlPID_TD_Td/T_VAL))

/* Variable para la constante proporcional */
static float CtrlPID_TD_K = K_VAL;
/* Variable para el tiempo integrativo */
static float CtrlPID_TD_Ti = TI_VAL;
/* Variable para el tiempo derivativo */
static float CtrlPID_TD_Td = TD_VAL;
/* Variable que almacena los errores */
float CtrlPID_TD_error[2] = {0.0, 0.0};

/*
** ===================================================================
**     Method      :  CtrlPID_TD_Set_Td (component PID_Float)
**     Description :
**         Change the Td parameter.
**     Parameters  :
**         NAME            - DESCRIPTION
**         t               - New Td value.
**     Returns     : Nothing
** ===================================================================
*/
void CtrlPID_TD_Set_Td(float t)
{
  if(t < 0) {
    return;
  }
  CtrlPID_TD_Td = t;
}

/*
** ===================================================================
**     Method      :  CtrlPID_TD_Set_Ti (component PID_Float)
**     Description :
**         Change the Ti parameter.
**     Parameters  :
**         NAME            - DESCRIPTION
**         t               - New Ti value.
**     Returns     : Nothing
** ===================================================================
*/
void CtrlPID_TD_Set_Ti(float t)
{
  if (t <= 0) {
    return;
  }
  CtrlPID_TD_Ti = t;
}

/*
** ===================================================================
**     Method      :  CtrlPID_TD_Set_K (component PID_Float)
**     Description :
**         Change the K parameter.
**     Parameters  :
**         NAME            - DESCRIPTION
**         k               - New K value.
**     Returns     : Nothing
** ===================================================================
*/
void CtrlPID_TD_Set_K(float k)
{
  if(k < 0) {
    return;
  }
  CtrlPID_TD_K = k;
}

/*
** ===================================================================
**     Method      :  CtrlPID_TD_Reset (component PID_Float)
**     Description :
**         Reset the PID.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void CtrlPID_TD_Reset(void)
{
  CtrlPID_TD_error[0] = 0.0;
  CtrlPID_TD_error[1] = 0.0;
}

/*
** ===================================================================
**     Method      :  CtrlPID_TD_Control (component PID_Float)
**     Description :
**         Control function. Must be called every T time.
**     Parameters  :
**         NAME            - DESCRIPTION
**         error           - Error signal. (Reference -
**                           SystemOutput).
**       * u               - Pointer to the control variable.
**     Returns     : Nothing
** ===================================================================
*/
#ifdef __HIWARE__
  #pragma MESSAGE DISABLE C5900
  #pragma MESSAGE DISABLE C5917
#endif

void CtrlPID_TD_Control(float error, uint16_t *u)
{
  float ut = 0.0;

  ut = (float) *u;
  ut += K1 * error;
  ut += K2 * CtrlPID_TD_error[0];
  ut += K3 * CtrlPID_TD_error[1];

  CtrlPID_TD_error[1] = CtrlPID_TD_error[0];
  CtrlPID_TD_error[0] = error;

  if (ut > U_MAX) {
    *u = (uint16_t) U_MAX;
  } else if (ut < U_MIN) {
    *u = (uint16_t) U_MIN;
  } else {
    *u = (uint16_t) ut;
  }
}
#ifdef __HIWARE__
  #pragma MESSAGE DISABLE C5919
#endif

/* END CtrlPID_TD. */

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
