/*
 * @file Table_State_Machine.c
 * author: kushagra Pandey & Vaidehi Salway
 * Date:10/16/2019
 *
 * REFERENCES:
 # Table Driven State Diagram- https://blogs.itemis.com/en/how-to-use-state-machines-for-your-modeling-part-4-the-state-machine-as-a-table
 */


#include "Table_State_Machine.h"

enum states{

POST_TEST,
READING_TEMPERATURE,//READ THE TEMPERATURE VALUE 					->COMPLETE/ALERT/DISCONNECT
COMPLETE_AVERAGE_TEMPERATURE,//DISPLAY THE AVERAGE TEMPERATURE		->TIMEOUT3/TIMEOUT4
DISCONNECT,//DISCONNECT WHEN SENSOR IS NOT RESPONDING
ALERT,//ALERT FROM MASTER WHEN TEMPERATURE BECOMES NEGATIVE			->COMPLETE/DISCONNECT
TIMEOUT_THREE_COUNT,//BACK TO THE TEMPERATURE READING FUNCTION		->COMPLETE(AVERAGE)
TIMEOUT_FOUR_COUNT//AFTER COUNT 4 TRANSIT TO THE STATE MACHINE 2	->STATEMACHINE2

};

enum columns
{
    SOURCE_STATE,POST_TEST_EVENT, AVERAGE_TEMPERATURE_EVENT, ALERT_EVENT, DISCONNECT_EVENT, TIMER_COUNT_THREE_EVENT, TIMER_COUNT_FOUR_EVENT,TARGET_STATE
};

enum columns Column;

//stae machine table for defining the transaction from one state to another
int state_table[ROWS][COLS] = {

    /* source_state,POST_TEST_EVENT,  AVERAGE_TEMPERATURE_EVENT, ALERT_EVENT,  DISCONNECT_EVENT, TIMER_COUNT_THREE_EVENT, TIMER_COUNT_FOUR_EVENT, TARGET_STATE */

	//for Case POST if the event avg_temp is true NEXT STAE->READING TEMPERATURE
    { POST_TEST, false, true, false, false, false, false, READING_TEMPERATURE },
	//for Case POST if the event alert event is true NEXT STAE->ALERT
    { POST_TEST, false, false, true, false, false, false, ALERT },
	//for Case POST if the event disconnect event is true NEXT STAE->DISCONNECT
    { POST_TEST, false, false, false, true, false, false, DISCONNECT },


	//for case reading temperature if the eventAVG TEMPERATURE is true NEXT STATE->avg temperature
    { READING_TEMPERATURE,false, true, false, false, false, false, COMPLETE_AVERAGE_TEMPERATURE },
	//for case reading temperature if the event alert event is true NEXT STATE->ALERT
    { READING_TEMPERATURE,false, false, true, false, false, false, ALERT },
	//for case reading temperature if the event disconnect event is true NEXT STATE->DISCONNECT
    { READING_TEMPERATURE,false, false, false, true, false, false, DISCONNECT },

	//for case  AVG reading temperature if the event TIMER COUNT 3 is true NEXT STATE->AVG TEMPERATURE
    { COMPLETE_AVERAGE_TEMPERATURE, false, false, false, false, true, false, TIMEOUT_THREE_COUNT },
	//for case  AVG reading temperature if the event TIMER COUNT 3 is true NEXT STATE->POS_TEST
    { COMPLETE_AVERAGE_TEMPERATURE,false, false, false, false, false, true, TIMEOUT_FOUR_COUNT },
	//for case  AVG reading temperature if the event disconnect event is true NEXT STATE->DISCONNECT
    { COMPLETE_AVERAGE_TEMPERATURE,false, false, true, false, false, false, ALERT_EVENT },
	//for case  AVG reading temperature if the event disconnect event is true NEXT STATE->DISCONNECT
    { COMPLETE_AVERAGE_TEMPERATURE,false, false, false, true, false, false, DISCONNECT_EVENT },


	{ ALERT, false, false, false, true, false, false, DISCONNECT },
    { ALERT,false, true, false, false, false, false, COMPLETE_AVERAGE_TEMPERATURE },

    { DISCONNECT,false, false, false, true, false, false, DISCONNECT },

    { TIMEOUT_THREE_COUNT, false, true, false, false, false, false, COMPLETE_AVERAGE_TEMPERATURE },
    { TIMEOUT_FOUR_COUNT, true, false, false, false, false, false, POST_TEST }
};



int Table_StateMachine()//
{

	PRINTF("\n\rIN TABLE DRIVEN STATE MACHINE");
    int activeState = POST_TEST;
    int event = -1;

    while (true)
    {

    	int8_t Event_Test_Variable=Temperature_Reading();
    	int Event_TimerOut_Count=TimeOut_Counter(TIMER_COUNT2);

    	PRINTF("\n\rCurrent Count:%d",Event_TimerOut_Count);

        int row, col;

        bool checkRows = true, checkCols;
		uint8_t table_alert_bit=Alert();
		uint8_t table_alert_flag=0;
        PRINTF("Active state: %d\n\r", activeState);
        PRINTF("Event: %d\n\r", event);


    	   //checking for different events and the conditions for it
	       if(table_alert_bit==128)
	       {
	    	   Column=3;//ALERT_EVENT;
	    	   table_alert_flag=0;
	    	   event=Column;
	       }

	       else if(Event_TimerOut_Count==4)
	       {
	           Column=6;//TIMER_COUNT_FOUR_EVENT;
	    	   event=Column;
	       }

	       else if(Event_Test_Variable>0 && table_alert_bit==96)
	       {
	    	   Column=2;//AVERAGE_TEMPERATURE_EVENT;
	    	   event=Column;
	       }
	       else if(table_alert_bit!=128 && table_alert_bit!=96)
	       {
	       	   Column=4;//DISCONNECT_EVENT;
	       	   event=Column;
	       }

        /* Look for a row with the active state in the SOURCE_STATE column: */
        for (row = 0; checkRows && row < ROWS; row++)
        {

           checkCols = true;

            if (activeState == state_table[row][SOURCE_STATE])
            {
                /* Found a row matching the active state. */
                /* Now check the columns for events triggering this transition: */

                for (col = SOURCE_STATE + 1; checkCols && col < TARGET_STATE; col++)
                {

                    if (state_table[row][col])
                    {
                        /* Found one. The current event must match this column
                         * to trigger the transition. */
                	    PRINTF("\n\rSTATE TABLE:%d\n\r",state_table[row][col]);
                	    PRINTF("Event: %d\n\r", event);
                	    PRINTF("\n\rCOL:%d",col);

                       if (event == col)
                       {

                            /* The event matches. Let's do the transition: */

                    	    PRINTF("\n\rActive state and event matching row %d, column %d.\n", row, col);
                            PRINTF("\n\rTransitioning to target state %d\n", activeState);

                            activeState = state_table[row][TARGET_STATE];

                            /* Stop checking any further rows and columns: */
                            //checkRows = checkCols = false;

                        }
                        else
                        {

                            /* The event does not match, so this transitions won't be triggered.
                             * We do not need to check any remaining columns: */

                            checkCols = false;

                        }
                    }
                }
                PRINTF("Active state: %d\n\r", activeState);


                //defining the actions when particular state is achieved
               if(activeState==READING_TEMPERATURE)
               {

            	   	   	GREEN_LED_ON();
            	   	   	Delay_Time(1000);
            	   		GREEN_LED_OFF();

            	   PRINTF("\n\rTEMPERATURE IS:%d",Event_Test_Variable);

               }
               else if(activeState==COMPLETE_AVERAGE_TEMPERATURE)
               {

            	   	   	GREEN_LED_ON();
            	   	    Delay_Time(1000);
            	   		GREEN_LED_OFF();

            	   uint8_t Table_Avg_Temp=Calculate_Average_Temperature();
            	   PRINTF("\n\rCURRENT TEMPERATURE IS:%d",Event_Test_Variable);
            	   PRINTF("\n\rAVERAGE TEMPERATURE IS:%d",Table_Avg_Temp);

               }
               else if(activeState==DISCONNECT)
               {
            	   	   	RED_LED_ON();
            	   	    Delay_Time(1000);
            	   	    RED_LED_OFF();

            	   PRINTF("\n\r Sensor disconnected");

               }
               else if(activeState==ALERT)
               {
                        BLUE_LED_ON();
                        Delay_Time(1000);
                       	BLUE_LED_OFF();

                   PRINTF("\n\r Sensor Alert");

               }
               else if(activeState==TIMEOUT_THREE_COUNT)
               {
                        GREEN_LED_ON();
                        Delay_Time(1000);
                        GREEN_LED_OFF();

                  PRINTF("\n\r Sensor Alert");

                }
               else if(activeState==TIMEOUT_FOUR_COUNT)