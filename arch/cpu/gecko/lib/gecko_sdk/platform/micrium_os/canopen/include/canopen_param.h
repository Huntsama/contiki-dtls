/***************************************************************************//**
 * @file
 * @brief CANopen Parameters Object Management
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc.  Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement.
 * The software is governed by the sections of the MSLA applicable to Micrium
 * Software.
 *
 ******************************************************************************/

/****************************************************************************************************//**
 * @addtogroup CANOPEN_CORE
 * @{
 *******************************************************************************************************/

/********************************************************************************************************
 ********************************************************************************************************
 *                                               MODULE
 ********************************************************************************************************
 *******************************************************************************************************/

#ifndef _CANOPEN_PARAM_H_
#define _CANOPEN_PARAM_H_

/********************************************************************************************************
 ********************************************************************************************************
 *                                            INCLUDE FILES
 ********************************************************************************************************
 *******************************************************************************************************/

#include  <cpu/include/cpu.h>

#include  <canopen/include/canopen_obj.h>

/********************************************************************************************************
 ********************************************************************************************************
 *                                               DEFINES
 ********************************************************************************************************
 *******************************************************************************************************/

#define CANOPEN_PARAM____        0x0000                         // disable
#define CANOPEN_PARAM___E        0x0001                         // enable (on command)
#define CANOPEN_PARAM__A_        0x0002                         // enable (autonomously)
#define CANOPEN_PARAM__AE        0x0003                         // enable (autonomously and on command)

/********************************************************************************************************
 ********************************************************************************************************
 *                                          LOCAL DATA TYPES
 ********************************************************************************************************
 *******************************************************************************************************/

/*
 ********************************************************************************************************
 *                                   CANopen parameter structure
 *******************************************************************************************************/

typedef struct canopen_param {
  CPU_INT32U        MemBlkSize;                                 ///< Size of parameter memory block.
  CPU_INT08U        *StartMemBlkPtr;                            ///< Start of parameter memory block.
  CPU_INT08U        *DfltMemBlkPtr;                             ///< Start of default memory block.
  CANOPEN_NMT_RESET ResetType;                                  ///< Parameter reset type.
  void              *IdPtr;                                     ///< Pointer to User Identification-Code for this group.
  CPU_INT32U        Val;                                        ///< Value when reading parameter object.
} CANOPEN_PARAM;

/****************************************************************************************************//**
 ********************************************************************************************************
 * @}                                            MODULE END
 ********************************************************************************************************
 *******************************************************************************************************/

#endif // _CANOPEN_PARAM_H_
