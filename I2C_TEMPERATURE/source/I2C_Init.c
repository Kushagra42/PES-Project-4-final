

/*
 * @fil I2C_Init.c
 * author: kushagra Pandey & Vaidehi Salway
 * Date:10/14/2019
 *
 */

#include "main.h"


// defining the delay function
void Delay_Time(uint32_t milli_sec_val);
int TimeOut_Counter(int Time_out);


#include "I2C_Init.h"
//function for initializing the I2C sensor
void I2C_Init()
{
	/* Enable clock for I2C0 module */
	SIM->SCGC4 |= SIM_SCGC4_I2C0_MASK;

	/* Enable clock for Port E */
	SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK;

	/* Port E MUX configuration */
	PORTC->PCR[8]  |=  PORT_PCR_MUX(2);
	PORTC->PCR[9]  |=  PORT_PCR_MUX(2);

	I2C0->F=I2C_F_ICR(0x11)| I2C_F_MULT(0);

	I2C0->C1 |= (I2C_C1_IICEN_MASK);

	I2C0->C2 |= (I2C_C2_HDRS_MASK);


}

//Writing bytes on the address of the slave
void i2c_write_byte(uint8_t dev, uint8_t reg, uint8_t BYTE1, uint8_t BYTE2)

{
	I2C_TRAN;
	I2C_M_START;
	I2C0->D=dev;
	I2C_WAIT

	I2C0->D=reg;
	I2C_WAIT

	I2C0->D=BYTE1;
	I2C_WAIT

	I2C0->D=BYTE2;
	I2C_WAIT

	I2C_M_STOP;
}

//Reading the value from the slave
uint8_t i2c_read_byte(uint8_t dev, uint8_t reg_ptr1)
{

	uint8_t Data1;

	I2C_TRAN;
	I2C_M_START;
	I2C0->D=dev;
	I2C_WAIT


	I2C0->D= reg_ptr1;
	I2C_WAIT


	I2C_M_RSTART;
	I2C0->D= (dev|0x1);
	I2C_WAIT

	I2C_REC;
	ACK;

	Data1=I2C0->D;
	I2C_WAIT

	NACK;

	I2C_M_STOP;
	Data1= I2C0->D;

	return Data1;

}

//REading value from a different register pointer,here reading the configuration bytes
uint8_t i2c_read_byte_alert(uint8_t dev, uint8_t reg_ptr2)
{

	uint8_t CR_Data1;
	uint8_t CR_Data2;

	I2C_TRAN;
	I2C_M_START;
	I2C0->D=dev;
	I2C_WAIT


	I2C0->D= reg_ptr2;
	I2C_WAIT


	I2C_M_RSTART;
	I2C0->D= (dev|0x1);
	I2C_WAIT

	I2C_REC;
	ACK;

	CR_Data1=I2C0->D;
	I2C_WAIT
	PRINTF("\n\r CR_DATA1:%x",CR_Data1);

	CR_Data2=I2C0->D;
	I2C_WAIT

	NACK;

	I2C_M_STOP;
	CR_Data2= I2C0->D;
	PRINTF("\n\r CR_DATA2:%x",CR_Data2);



	return CR_Data2;

}







