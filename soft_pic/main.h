#include <30F3012.h>
#include <dspic30f.h>

#FUSES NOWDT                 	//No Watch Dog Timer
#FUSES NOCKSFSM              	//Clock Switching is disabled, fail Safe clock monitor is disabled
#FUSES NOBROWNOUT            	//No brownout reset
#FUSES NOMCLR
#FUSES NODEBUG
#device ICSP=1

#FUSES HS2_PLL8
#use delay(clock=80Mhz)
#use rs232(baud=9600,xmit=PIN_B4,rcv=PIN_B5)

#define LED_BIG_RED      PIN_B6
#define LED_SMALL_RED    PIN_C14
#define LED_SMALL_YELLOW PIN_C13
#define LED_SMALL_GREEN  PIN_D0

// circular buffer len
/* That is, the W register pointer may not be adjusted correctly by the modulo 
hardware when the W register pointer for an incrementing buffer is decremented
and vice versa. The exception to this rule is when the buffer length is an even
power of 2 and the start and end addresses can be chosen to meet the boundary 
requirements for both incrementing and decrementing modulo buffers.
*/
#define HISTLEN 256



