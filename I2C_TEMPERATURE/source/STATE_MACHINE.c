
#include "STATE_MACHINE.h"

//define the initial state of teh state machine
enum states STATE= POST_TEST;
//set alert flag after the alert case is reached
uint8_t Alert_Flag=0;

//function for the state machine
void State_Machine()
{

//switch states for diff cases
switch(STATE)
{
//case to test the power on reset condition for i2c sensor
	case POST_TEST:

		Log_String(2,9,"IN POST CASE");

//if ACK move forward else goes into siconnect state
		if(ACK)
		{
			Log_String(2,9,"continue reading temperature");

			STATE=READING_TEMPERATURE;
		}
		else
		{
			Log_String(2,9,"disconnected state");

			STATE=DISCONNECT;
			//LED setup
			RED_LED_ON();
			Delay_Time(1000);
			RED_LED_OFF();			}

	break;

	//case for reading the temperature value
	//it has possible 3 transactions for the state
	/*1)when temp is negative->ALERT STATE
	 *
	 *2)when temp is positive->AVG_TEMP STATE
	 *
	 *3)when sensor disconnected or connected wrongly->DISCONNECT STATE
	 */
	case READING_TEMPERATURE:

		Log_String(2,5,"IN CASE READING TEMPERATURE");
		GREEN_LED_ON();
		Delay_Time(1000);
		GREEN_LED_OFF();
		uint8_t alert_bit=Alert();

		int8_t Test_Power2=Temperature_Reading();

		if(Test_Power2>0 && alert_bit==96 )
		{
			GREEN_LED_ON();
			Delay_Time(1000);
			GREEN_LED_OFF();


			STATE=COMPLETE_AVERAGE_TEMPERATURE;
		}

		else if(alert_bit==128)
		{
			BLUE_LED_ON();
			Delay_Time(1000);
		    BLUE_LED_OFF();
		    Alert_Flag=0;
			STATE= ALERT;
		}

		else
		{
			RED_LED_ON();
		    Delay_Time(1000);
		    RED_LED_OFF();
		    Disconnect();
			STATE=DISCONNECT;
		}
		break;


	//case for reading the avg temperature value
	//it has possible 3 transactions for the state
	/*1)when temp is negative->ALERT STATE
	*
	*2)when counter count is three->AVG_TEMP STATE
	*
	*3)when counter count is four->NEXT STATE MACHINE
	*/

	case COMPLETE_AVERAGE_TEMPERATURE:

		GREEN_LED_ON();
		Delay_Time(1000);
		GREEN_LED_OFF();

		Log_String(2,6,"IN CASE COMPLETE AVERAGE TEMPERATURE");

		Calculate_Average_Temperature();
		//15 seconds delay for timeout
	    Delay_Time(5000);

	    int Count=TimeOut_Counter(TIMER_COUNT);

		Log_String(2,1,"count is:");
	    Log_Data(2,1,Count);
		int8_t Test=Temperature_Reading();
		Log_String(2,1,"TEMPERATURE is:");
		Log_Data(2,1,Test);

		uint8_t alert_bit2=Alert();
	    if(Count==3)
	    {
	  	    STATE=TIMEOUT_THREE_COUNT;
	    }
	    else if(Count==4)
	    {
	    	STATE=TIMEOUT_FOUR_COUNT;
	    }
	    else if(alert_bit2==128)
	    {
	    	BLUE_LED_ON();
	        Delay_Time(1000);
	    	BLUE_LED_OFF();
	    	Alert_Flag=0;
	    	STATE= ALERT;
	    }
	    else
	    {
	    	STATE=DISCONNECT;
	    }

		break;

		//case after 3 countes->NEXT STATE->AVG_TEMP STATE
	case TIMEOUT_THREE_COUNT:

		Log_String(2,1,"IN CASE TIMEOUT_THREE_COUNT:");
		STATE=COMPLETE_AVERAGE_TEMPERATURE;

		break;

//caes after 4 counts->moves on to the TABLE_DRIVEN_STATE_MACHINE
	case TIMEOUT_FOUR_COUNT:

		Log_String(2,1,"IN CASE TIMEOUT_Four_COUNT:");
		Log_String(2,1,"NEXT STATE MACHINE:");
		Table_StateMachine();

		break;

//case when temperature goes below a defined minimum range
	case ALERT:

		Log_String(2,10,"IN CASE ALERT:");
		BLUE_LED_ON();
	    Delay_Time(1000);
		BLUE_LED_OFF();

		Alert();

		if(Alert_Flag==0)
		{
			GREEN_LED_ON();
			STATE=COMPLETE_AVERAGE_TEMPERATURE;
		}
		else
		{
			STATE=DISCONNECT;
		}

		break;


//disconnect when sensor is not connected properly
	case DISCONNECT:


		RED_LED_ON();
		Delay_Time(1000);
		RED_LED_OFF();
		Log_String(2,10,"IN CASE DISCONNECT:");
		Disconnect();

		break;


}



}
