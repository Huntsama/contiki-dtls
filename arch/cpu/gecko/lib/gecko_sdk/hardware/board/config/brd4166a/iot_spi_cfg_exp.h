/***************************************************************************//**
 * @file    iot_spi_cfg_inst.h
 * @brief   Common I/O SPI instance configurations.
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 ******************************************************************************/

/*******************************************************************************
 *                              SAFE GUARD
 ******************************************************************************/

#ifndef _IOT_SPI_CFG_EXP_H_
#define _IOT_SPI_CFG_EXP_H_

/*******************************************************************************
 *                          SPI Default Configs
 ******************************************************************************/

// <<< Use Configuration Wizard in Context Menu >>>

// <h> SPI General Options

// <o IOT_SPI_CFG_EXP_INST_NUM> Instance number
// <i> Instance number used when iot_spi_open() is called.
// <i> Default: 0
#define IOT_SPI_CFG_EXP_INST_NUM                  0

// <o  IOT_SPI_CFG_EXP_DEFAULT_BITRATE> Default SPI bitrate
// <i> Default: 1000000
#define IOT_SPI_CFG_EXP_DEFAULT_BITRATE           1000000

// <o  IOT_SPI_CFG_EXP_DEFAULT_FRAME_LENGTH> Default SPI frame length <4-16>
// <i> Default: 8
#define IOT_SPI_CFG_EXP_DEFAULT_FRAME_LENGTH      8

// <o  IOT_SPI_CFG_EXP_DEFAULT_TYPE> Default SPI master/slave mode
// <spidrvMaster=> Master
// <spidrvSlave=> Slave
#define IOT_SPI_CFG_EXP_DEFAULT_TYPE              spidrvMaster

// <o  IOT_SPI_CFG_EXP_DEFAULT_BIT_ORDER> Default SPI bit order
// <spidrvBitOrderLsbFirst=> LSB transmitted first
// <spidrvBitOrderMsbFirst=> MSB transmitted first
#define IOT_SPI_CFG_EXP_DEFAULT_BIT_ORDER         spidrvBitOrderMsbFirst

// <o  IOT_SPI_CFG_EXP_DEFAULT_CLOCK_MODE> Default SPI clock mode
// <spidrvClockMode0=> SPI mode 0: CLKPOL=0, CLKPHA=0
// <spidrvClockMode1=> SPI mode 1: CLKPOL=0, CLKPHA=1
// <spidrvClockMode2=> SPI mode 2: CLKPOL=1, CLKPHA=0
// <spidrvClockMode3=> SPI mode 3: CLKPOL=1, CLKPHA=1
#define IOT_SPI_CFG_EXP_DEFAULT_CLOCK_MODE        spidrvClockMode0

// <o  IOT_SPI_CFG_EXP_DEFAULT_CS_CONTROL> Default SPI CS control scheme
// <spidrvCsControlAuto=> CS controlled by the SPI driver
// <spidrvCsControlApplication=> CS controlled by the application
#define IOT_SPI_CFG_EXP_DEFAULT_CS_CONTROL        spidrvCsControlApplication

// <o  IOT_SPI_CFG_EXP_DEFAULT_SLAVE_START_MODE> Default SPI transfer scheme
// <spidrvSlaveStartImmediate=> Transfer starts immediately
// <spidrvSlaveStartDelayed=> Transfer starts when the bus is idle
#define IOT_SPI_CFG_EXP_DEFAULT_SLAVE_START_MODE  spidrvSlaveStartImmediate

// <q IOT_SPI_CFG_EXP_LOOPBACK> Internal Loopback
// <i> Enable USART Internal loopback
// Default: 0
#define IOT_SPI_CFG_EXP_LOOPBACK                    0

// </h>

// <<< end of configuration section >>>

/*******************************************************************************
 *                        H/W PERIPHERAL CONFIG
 ******************************************************************************/

// <<< sl:start pin_tool >>>
// <usart signal=TX,RX,CLK,CS> IOT_SPI_CFG_EXP
// $[USART_IOT_SPI_CFG_EXP]
#define IOT_SPI_CFG_EXP_PERIPHERAL               USART2
#define IOT_SPI_CFG_EXP_PERIPHERAL_NO            2

// USART2 TX on PK0
#define IOT_SPI_CFG_EXP_TX_PORT                  gpioPortK
#define IOT_SPI_CFG_EXP_TX_PIN                   0
#define IOT_SPI_CFG_EXP_TX_LOC                   29

// USART2 RX on PK2
#define IOT_SPI_CFG_EXP_RX_PORT                  gpioPortK
#define IOT_SPI_CFG_EXP_RX_PIN                   2
#define IOT_SPI_CFG_EXP_RX_LOC                   30

// USART2 CLK on PF7
#define IOT_SPI_CFG_EXP_CLK_PORT                 gpioPortF
#define IOT_SPI_CFG_EXP_CLK_PIN                  7
#define IOT_SPI_CFG_EXP_CLK_LOC                  18

// USART2 CS on PA5
#define IOT_SPI_CFG_EXP_CS_PORT                  gpioPortA
#define IOT_SPI_CFG_EXP_CS_PIN                   5
#define IOT_SPI_CFG_EXP_CS_LOC                   29

// [USART_IOT_SPI_CFG_EXP]$
// <<< sl:end pin_tool >>>

/*******************************************************************************
 *                              SAFE GUARD
 ******************************************************************************/

#endif /* _IOT_SPI_CFG_EXP_H_ */
