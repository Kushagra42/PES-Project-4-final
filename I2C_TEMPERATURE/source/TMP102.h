/*
 * @file TMP102.h
 * author: kushagra Pandey & Vaidehi Salway
 * Date:10/16/2019
 */



#include "main.h"
#include "I2C_Init.h"
#include "Delay_Function.h"
#include "LED_Blink.h"


#define SLAVE_ADDRESS  		0x90

//Writing values to CR
#define REG_PTR_CR    		0x01
#define CR_BYTE1			0x6C
#define CR_BYTE2			0xA0

//Writing the Temperature Low value
#define REG_PTR_TEMP_LOW	0x02
#define TEMP_MIN_LOW_BYTE	0x16
#define TEMP_MIN_HIGH_BYTE	0x00

//Writing the Temperature Low value
#define REG_PTR_TEMP_HIGH	0x03
#define TEMP_MAX_LOW_BYTE	0x00
#define TEMP_MAX_HIGH_BYTE	0x00

//Reading Temperature value
#define REG_PTR_TEMP_DATA		0x00

//Reading Configuration Register Value
#define REG_PTR_READ_CR			0x01


uint8_t Temperature_Reading();
uint8_t Calculate_Average_Temperature();
