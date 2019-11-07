/*
 * @file Logger.c
 * author: kushagra Pandey & Vaidehi Salway
 * Date:10/18/2019
 *
 * This .c file contains the logger statements for cross-platform
 * There are two modes of operating this file
 * 1. Logger Enable
 * 2. Logger Disable
 *
 * Enable or Disable the logger by un-commenting #define logging_init or #define logging_notinit respectively from Logger.h
 *
 # Enum to string Conversion-https://stackoverflow.com/questions/3168306/print-text-instead-of-value-from-c-enum
 *
 *
 */


#include "Logger.h"


uint8_t log_status;


// Function log enable, when called in main returns log_status 1
void Log_Enabled()
	{
		log_status=1;
	}

// Function log disable, when called in main returns log status 0
void Log_Disabled()
	{
		PRINTF("\nLOGGERS ARE DISABLED");
		log_status=0;
	}

// checking condition to enable logging
// Status function called when logging_init is defined in logger.h
#ifdef logging_init

// Function Status calls log_Enabled
uint8_t Status()
	{
		Log_Enabled();
		return log_status;
	}
#endif

//enums defined for different LOG Values
enum LogLevel
{
	TEST,
	DEBUGG,
	STATUS
};

//enums defined for different FUNCTION values
enum Functions
{
	FN_Delay_Time,//0
	FN_TimeOut_Counter,//1
	FN_I2C_Init,//2
	FN_i2c_write_byte,//3
	FN_i2c_read_byte,//4
	FN_Temperature_Reading,//5
	FN_Calculate_Average_Temperature,//6
	FN_State_Machine,//7
	FN_Table_StateMachine,//8
	FN_Power_On_Reset_Test,//9
	FN_Alert,//10
	FN_Disconnect//11
};



// checking condition to disable logging
// Status function called when logging_notinit is defined in logger.h
#ifdef logging_notinit

//Function Status calls log_Disabled
uint8_t Status()
	{
		Log_Disabled();
		return log_status;
	}
#endif


//converting the enum in log levels to string
const char* getloglevel(enum LogLevel log_level)
{
switch (log_level)
{
case 0 : return "Test";
case 1 : return "Debug";
case 2 : return "Status";;
}
};

//converting the enum in function types to string
const char* getFunctions(enum Functions Function)
{
switch (Function)
{
case 0 : return "Delay_Time";
case 1 : return "TimeOut_Counter";
case 2 : return "I2C_Init";
case 3 : return "i2c_write_byte";
case 4 : return "i2c_read_byte";
case 5 : return "Temperature_Reading";
case 6 : return "Calculate_Average_Temperature";
case 7 : return "State_Machine";
case 8 : return "Table_StateMachine";
case 9 : return "Power_On_Reset_Test";
case 10 : return "Alert";
case 11 : return "Disconnect";;
}
};




// Log Data function enables printing data on the terminal when running in freedom board
void Log_Data(int x,int y,int8_t data)
	{
		Status();

		if(log_status==1)
			{
						//only prints if log type is test,all three log types will work

						if(level==0)
						{
					     PRINTF("\n\r%s:%s:%d",getloglevel(x),getFunctions(y),data);
						}
						//only prints if log type is debug,debug and status log types will work

						else if(level==1)
						{
							if(x!=0)
						    {
							PRINTF("\n\r%s:%s:%u",getloglevel(x),getFunctions(y),data);
							}

						}
						//only prints if log type is status,status log types will work

						else if(level==2)
						{
							if(x==2 )
						    {
							PRINTF("\n\r%s:%s:%u",getloglevel(x),getFunctions(y),data);
							}

						}
			}

	}


// Log Data function enables printing Strings on the terminal when running in freedom board
void Log_String(int x,int y,char *statement)
	{


		Status();

		if(log_status==1)//LOG-STRING(TEST,2,HI);//define Z DEBUG
			{
			//only prints if log type is test,all three log types will work

				if(level==0)
				{
			     PRINTF("\n\r%s:%s:%s",getloglevel(x),getFunctions(y),statement);
				}
				//only prints if log type is debug,debug and status log types will work

				else if(level==1)
				{
					if(x!=0)
				    {
					PRINTF("\n\r%s:%s:%s",getloglevel(x),getFunctions(y),statement);
					}

				}
				//only prints if log type is status,status log types will work

				else if(level==2)
				{
					if(x==2 )
				    {
					PRINTF("\n\r%s:%s:%s",getloglevel(x),getFunctions(y),statement);
					}

				}

			}

	}


// Log Data function enables printing integer values on the terminal when running in freedom board
void Log_Integer(int x,int y,int integer_value)
	{
		Status();

		if(log_status==1)
			{
						//only prints if log type is test,all three log types will work
						if(level==0)
						{
					     PRINTF("\n\r%s:%s:%d",getloglevel(x),getFunctions(y),integer_value);
						}

						//only prints if log type is debug,debug and status log types will work

						else if(level==1)
						{
							if(x!=0)
						    {
							PRINTF("\n\r%s:%s:%d",getloglevel(x),getFunctions(y),integer_value);
							}

						}
						//only prints if log type is status,status log types will work

						else if(level==2)
						{
							if(x==2 )
						    {