/*
 * File:   main.c
 * Author: BF
 *
 * Created on February 26, 2021, 6:18 PM
 *
 * Description: blinking a led at PIN 4 (GPIO1)
 * (pin 4 is connected to a 270 ohm resistor that is connected to the negative pin of the led
 * the positive pin of the led is connected to the positive power supply
 */

// CONFIG
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF          // Code Protection bit (Program memory code protection is enabled)

#include <xc.h>

#define _XTAL_FREQ 4000000L

void main(void) {
    TRIS = 0b1101;  //0 means output, so GP1 is output

    while(1) {        
        GPIO = 0b0000;  //0 means low, so it lights up
        __delay_ms(1000);
        GPIO = 0b0010;  //1 means high, so it does not light
        __delay_ms(1000);
    }
    return;
}
