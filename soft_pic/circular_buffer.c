// Test hardware circular buffer
#include <main.h>

void main()
{
	#define BUFFER_LEN 8
	
	#BANKX
	int buffer[BUFFER_LEN];
	
	// Modulo addressing inicialization
	XMODSRT           = buffer;
	XMODEND           = buffer + BUFFER_LEN - 1;
	MODCONbits.XWM    = MODCON_WREG1;
	MODCONbits.XMODEN = MODCON_ENABLED;

	#ASM
	mov #0,w0      // w0 is the counter: start at 0
	mov buffer,w1  // w1 is the pointer: start at buffer[0]
		
	do #100,end    // repeat 100 times until "fill", included
	mov w0,[w1++]  // store w0 at w1, post-increment pointer
	end: 
	inc w0,w0      // increment counter
	#ENDASM
	
	while(true)	{}
}
