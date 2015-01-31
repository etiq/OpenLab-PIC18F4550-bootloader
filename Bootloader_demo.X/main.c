/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>        /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>       /* HiTech General Include File */
#elif defined(__18CXX)
    #include <p18cxxx.h>   /* C18 General Include File */
#endif

#if defined(__XC) || defined(HI_TECH_C)

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#endif

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp */

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/* i.e. uint8_t <variable_name>; */

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/
/* --- type definitions ---------------------------------------------------- */
typedef unsigned char   byte;           // 8-bit
typedef unsigned int    word;           // 16-bit
typedef unsigned long   dword;          // 32-bit

#define InitLEDs()  LATE &= 0xFC; TRISE &= 0xFC;

#define LED1_On()	LATEbits.LATE0 = 1
#define LED1_Off()	LATEbits.LATE0 = 0


/* --- BEGIN: changes required for bootloader ------------------------------ */
#define PROG_START 0x800        //application memory origin

#asm
PSECT intcode
        goto PROG_START+0x8
PSECT intcodelo
        goto PROG_START+0x18
#endasm
void interrupt my_isr()
{
    /*High priority interrupt code goes here*/
}

void interrupt low_priority my_isrlo(void)
{
    /* Low priority interrupt code goes here*/
}

/* ------------------------------------------------------------------------- */
/* delay                                                                     */
/* Delay function.                                                           */
/* ------------------------------------------------------------------------- */
void delay(void)
{
	int i;
	int j;
	for (j = 0; j < 10; j++)
    {
		for (i = 0; i < 30000; i++);
    }
}


/* ------------------------------------------------------------------------- */
/* main                                                                      */
/* Delay function.                                                           */
/* ------------------------------------------------------------------------- */
void main(void)
{
    /* Configure the oscillator for the device */
    ConfigureOscillator();

    /* Initialize I/O and Peripherals for application */
    InitApp();

    /* TODO <INSERT USER APPLICATION CODE HERE> */

        ADCON1 |= 0x0F;

	InitLEDs();

	/* toggle I/0 pin */
    while(1)
	{
		LED1_On();
		delay();
		LED1_Off();
		delay();
	}

}

