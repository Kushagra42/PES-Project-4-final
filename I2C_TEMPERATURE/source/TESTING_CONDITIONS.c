/*
 * @file TESTING_CONDITIONS.c
 * author: kushagra Pandey & Vaidehi Salway
 * Date:10/16/2019
 */



#include "TESTING_CONDITIONS.h"

#include "Logger.h"

extern uint8_t Alert_Flag;

//function for checking the POST test
uint8_t Power_On_Reset_Test()
{

Delay_Time(500);
uint8_t Test_Data = Temperature_Reading();
Log_String(1,9,"TEMPERATURE IS:");
Log_Data(1,9,Test_Data);

return Test_Data;

}
//function for checking if the temperature is negative
uint8_t Alert()
{

    i2c_write_byte(SLAVE_ADDRESS,REG_PTR_CR,CR_BYTE1,CR_BYTE2);
	Delay_Time(1000);
	i2c_read_byte_alert(SLAVE_ADDRESS, REG_PTR_READ_CR);
	uint8_t Alert_Bit_Value=i2c_read_byte_alert(SLAVE_ADDRESS, REG_PTR_READ_CR);

	Log_String(1,10,"NEGATIVE TEMPERATURE ALERT PIN VALUE:");
	Log_Data(1,10,Alert_Bit_Value);

	return Alert_Bit_Value;
}

//checking if the sensor is discoonected
void Disconnect()
{
	if(NACK)
	{
		RED_LED_ON();

		Log_String(2,10,"SENSOR DISCONNECTED:");
	}
}
