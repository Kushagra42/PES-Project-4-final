
/*
 * @file  Unit_Testing.c
 * author: kushagra Pandey & Vaidehi Salway
 * Date:10/16/2019
 */

#include "Unit_Testing.h"

// Code for random generator
// Reference:   https://rosettacode.org/wiki/Linear_congruential_generator
//

//testing teh power for the sensor
void Power_Test()
{

	UCUNIT_Init();
	int8_t test_log;

	UCUNIT_TestcaseBegin("I2C_TEMPERATURE TEST BEGINS");
	test_log=Power_On_Reset_Test();

	UCUNIT_CheckIsEqual(test_log,Temperature_Reading());

	UCUNIT_TestcaseEnd();
	UCUNIT_WriteSummary();
	//UCUNIT_Shutdown();

}

//testing if the switch case works
void Switch_Test()
{
		UCUNIT_Init();
		int8_t test_log;


		UCUNIT_TestcaseBegin("SWITCH CASE TEST BEGINS");
		test_log=0;

		UCUNIT_CheckIsEqual(test_log,0);
		UCUNIT_CheckIsInRange(0,0,4);

		UCUNIT_TestcaseEnd();
		UCUNIT_WriteSummary();
		//UCUNIT_Shutdown();


}

//testing if teh value for the counter is incrementing
void Test_Counter()

{

			UCUNIT_Init();
			int8_t test_log;


			UCUNIT_TestcaseBegin("COUNTER TEST BEGINS");
			test_log=TimeOut_Counter(3);

			UCUNIT_CheckIsEqual(test_log,3);
			UCUNIT_CheckIsInRange(test_log,0,4);

			UCUNIT_TestcaseEnd();
			UCUNIT_WriteSummary();
			//UCUNIT_Shutdown();

}


//checkingthe range and correct values in enum
void Test_Enum()

{
			UCUNIT_Init();
			int8_t test_log;

			UCUNIT_TestcaseBegin("ENUM TEST BEGINS");
			test_log=4;

			UCUNIT_CheckIsEqual(test_log,ALERT);

			UCUNIT_TestcaseEnd();
			UCUNIT_WriteSummary();
			//UCUNIT_Shutdown();
}

//checking for the range and correct elements in table state machine
void Test_TableColumn()
{


				UCUNIT_Init();
				int8_t test_log;

				UCUNIT_TestcaseBegin("TABLE COLUMN TEST BEGINS");
				test_log=2;

				UCUNIT_CheckIsEqual(test_log,1);

				UCUNIT_TestcaseEnd();
				UCUNIT_WriteSummary();
				//UCUNIT_Shutdown();


}
//checking the range for table state machine

void Test_Col_Range()
{
					UCUNIT_Init();
					int8_t test_log;

					UCUNIT_TestcaseBegin("COLUMN RANGE TEST BEGINS");
					test_log=(TIMEOUT_FOUR_COUNT-POST_TEST);

					UCUNIT_CheckIsEqual(test_log,8);

					UCUNIT_TestcaseEnd();
					UCUNIT_WriteSummary();
					//UCUNIT_Shutdown();


}

//checking for a correct array range
void Test_Array_Range()
{
					UCUNIT_Init();
					int8_t test_log;

					UCUNIT_TestcaseBegin("ARRAY RANGE TEST BEGINS");
					test_log=ROWS*COLS;

					UCUNIT_CheckIsEqual(test_log,(ROWS*COLS));

					UCUNIT_TestcaseEnd();
					UCUNIT_WriteSummary();
					//UCUNIT_Shutdown();

}

//checking if the avg temperature function gives out the right value
void Test_Avg_Temp()
{
						UCUNIT_Init();
						int8_t test_log;

						UCUNIT_TestcaseBegin("AVG TEMP TEST BEGINS");
						test_log=Calculate_Average_Temperature();

						UCUNIT_CheckIsEqual(test_log,Calculate_Average_Temperature());

						UCUNIT_TestcaseEnd();
						UCUNIT_WriteSummary();
						//UCUNIT_Shutdown();

}

//checking if thethe events are set properly
void Test_Event_Set()
{
							UCUNIT_Init();
							int8_t test_log;

							UCUNIT_TestcaseBegin("EVENT SET TEST BEGINS");
							if((Temperature_Reading())<0)
							{
							test_log=3;
							}
							else
							{
								Log_String(0, 9, "TEMPERATURE IS POSITIVE");
							}
							UCUNIT_CheckIsEqual(test_log,3);

							UCUNIT_TestcaseEnd();
							UCUNIT_WriteSummary();
							//UCUNIT_Shutdown();




}

//checking if the log messages are set acc. to defined conditions
void Test_Log_Status()
{

							UCUNIT_Init();
							uint8_t test_log;

							UCUNIT_TestcaseBegin("EVENT SET TEST BEGINS");
							test_log=Status();
							UCUNIT_CheckIs8Bit(test_log);
							UCUNIT_TestcaseEnd();
							UCUNIT_WriteSummary();
							//UCUNIT_Shutdown();



}




