

/*
 * @fil I2C_Init.h
 * author: kushagra Pandey & Vaidehi Salway
 * Date:10/14/2019
 *
 */


#include "main.h"


//defining all the i2c transactions for I2C0
#define I2C_M_START    I2C0->C1 |= I2C_C1_MST_MASK
#define I2C_M_STOP     I2C0->C1 &=  ~I2C_C1_MST_MASK
#define I2C_M_RSTART   I2C0->C1 |= I2C_C1_RSTA_MASK

#define I2C_TRAN       I2C0->C1 |= I2C_C1_TX_MASK
#define I2C_REC        I2C0->C1 &= ~I2C_C1_TX_MASK

#define I2C_WAIT       while((I2C0->S & I2C_S_IICIF_MASK)==0) {} \
                       I2C0->S |= I2C_S_IICIF_MASK;

#define NACK           I2C0->C1 |= I2C_C1_TXAK_MASK
#define ACK            I2C0->C1 &= ~I2C_C1_TXAK_MASK


void I2C_Init();
void i2c_write_byte(uint8_t dev, uint8_t reg, uint8_t BYTE2, uint8_t BYTE1);//,uint8_t BYTE1,uint8_t BYTE2
uint8_t i2c_read_byte(uint8_t dev, uint8_t reg_ptr1);
uint8_t i2c_read_byte_alert(uint8_t dev, uint8_t reg_ptr2);
