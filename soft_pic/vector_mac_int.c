// Test MAC operation and Acc access. Integer version.
#include <main.h>

void main()
{
	int result = 0;
	
	#BANKX
	int filter[]  = {0, 0, 0, 1, 0, 0, 0};
	#BANKY
	int samples[] = {1, 2, 3, 4, 5, 6, 7};
	
	CORCONbits.IFMODE = CORCON_IFMODE_INTEGER;

	
	#ASM
	mov filter,w8    // W8 and W9 can address X memory
	mov samples,w10  // W10 and W11 can address Y memory
		
	clr A,[w8]+=2,w4,[w10]+=2,w5
	  // Clear Acc A, and by the way...
	  // Move to W4 the value where W8 was pointing to
	  // Add two to W8
	  // Move to W5 the value where W10 was pointing to
	  // Add two to W10

	repeat #6  // loop 7 (6+1) times this:
	mac w4*w5,a,[w8]+=2,w4,[w10]+=2,w5
	  // Multiply W4 and W5, add the result to Acc A and btw...
	  // Move to W4 the value where W8 was pointing to
	  // Add two to W8
	  // Move to W5 the value where W10 was pointing to
	  // Add two to W10

	sftac a,#-16  // result is in ACCA.L, we need it in ACCA.H
	sac a,w0      // store ACCA.H into W1
	mov w0,result // move it to the variable		
	#ENDASM
	
	while(true)	{}
}
