// Test MAC operation and Acc access. Fract version.
#include <main.h>

void main()
{
	float result;
	
	#BANKY
	fract_t samples[] = {
		FRACT( 1./2 ),
		FRACT( 1./3 ),
		FRACT( 1./4 ),
		FRACT( 1./5 ),
		FRACT( 1./6 ),
		FRACT( 1./7 ),
		FRACT( 1./8 ),
		FRACT( 1./9 ),
		FRACT( 1./10)
	};
	
	CORCONbits.IFMODE = CORCON_IFMODE_FRACT;

	#ASM
	mov samples,w10  // W10 and W11 can address Y memory
		
	clr A,[w10]+=2,w5

	repeat #8
	mac w5*w5,a,[w10]+=2,w5


	// Compare rounded vs. truncated
	sac   a,w0
	sac.r a,w1

	mov w1, result
	#ENDASM
	
	while(true)	{}
}
