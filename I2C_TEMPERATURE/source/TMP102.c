
#include "TMP102.h"
#include "Logger.h"

int8_t Temperature_Data=0;
int8_t Average_Temperature=0;

uint8_t  Temperature_Reading()
{

	    i2c_write_byte(SLAVE_ADDRESS,REG_PTR_CR,CR_BYTE1,CR_BYTE2);
	    Delay_Time(3000);

	    Temperature_Data=i2c_read_byte(SLAVE_ADDRESS, REG_PTR_TEMP_DATA);
	    return Temperature_Data;

}
//this calculates the average temperature
uint8_t Calculate_Average_Temperature()
{
		int8_t Current_Temperature=Temperature_Reading();//Current_Temperature

		Log_String(2,5,"CURRENT TEMPERATURE");
		Log_Data(2,5,Current_Temperature);

		//calculate average temperature

		if(Average_Temperature==0)
		{
			Average_Temperature=Current_Temperature;

		}
		else if(Average_Temperature!=0)
		{
		Average_Temperature = (Average_Temperature+Current_Temperature)/2;

		}
		Log_String(2,5,"Average Temperature");
		Log_Data(2,5,Average_Temperature);


return Average_Temperature;
}
