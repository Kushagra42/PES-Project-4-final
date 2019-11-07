# PES-Project-4-final

#README


# Created by : Vaidehi Salway & Kushagra Pandey
# Date       : 04-Nov-2019

# References: Inspiration was taekn from the mentioned website for writing the code to convert the enum values to string 
#	     Also for writing the Table driven State Diagram

# Enum to string Conversion-https://stackoverflow.com/questions/3168306/print-text-instead-of-value-from-c-enum
# Table Driven State Diagram- https://blogs.itemis.com/en/how-to-use-state-machines-for-your-modeling-part-4-the-state-machine-as-a-table 

# Repo Content:
# main.c/main.h
# STATEMACHINE.c/STATEMACHINE.h
# LED_Blinking.c/LED_Blinking.h
# Delay_Function.c/Delay_Function.h
# Logger.c/Logger.h
# Table_State_Machine.c/Table_State_Machine.h
# TESTING_CONDITIONS.c/TESTING_CONDITIONS.h
# uCUnit.c/uCUnit.h
# I2C_Capture2
# README.txt
# 
# Assignment Description:
# This project combines the KL25Z with an I2C-based temperature sensor, the TMP102.
# In this project we have implemented two different types of state machines: 1. State driven state machine 2. Table Driven state machine
# We measure the room temperature and green LED glows on KL25Z 
# We measure the sub zero temperature which gives an alert and  blue LED glows on KL25Z 
# When we disconnect the sensor from the KL25Z board the onboard red LED glows 
# We have developed a logger which works in three modes:
# 1. Test mode: this only prints the three types of messages on mcuxpresso terminal through UART
# 2. Debug mode: this  prints all the Debug messages on mcuxpresso terminal through UART
# 3. Status mode: this only prints the Status messages on mcuxpresso terminal through UART
# In this project we have also implemented micro unit test for the functions used in the project
#
# Program Execution Instruction:
# Set Cunter value to either 3 or 4 in STATE_MACHINE.h #define Timer_count
# Set Cunter value to either 3 or 4 in Table_State_Machine.h #define Timer_count2
# Change the slave register address and configure register in I2C_Init.h
# Change #define level value in Logger.h to select between Test mode (value 0), Debug mode(value 1), Status mode (value 2)
#
#
# Project Execution:
# The program runs on KL25Z Freedom board
# After setting up as per program execution instructions, the prohram first runs a post test function
# The I2C transactions between the temperature sensor and freedom board begin and values are logged
# Program runs the state driven state machine until counter value reaches 4
# once counter value is 4 the table driven state machine comes into action
# The Log messages are  printed on the MCUXpresso terminal window
# Alert is generated when temparature crosses the limits
# LED indications are shown on the board
# Micro Test Units are run on the board
# 
#
# Difficulties faced:
# In executing State driven table machine 
# Printing enum values as a string
#
# We overcame the difficulties by taking inspiration from the resources mentioned at the top of the file
#
#