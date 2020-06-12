/* Core configuration registers. */
#word CORCON = getenv("SFR:CORCON")
#word MODCON = getenv("SFR:MODCON")
#word ADCON1 = getenv("SFR:ADCON1")
#word ADCON2 = getenv("SFR:ADCON2")
#word ADCON3 = getenv("SFR:ADCON3")

#word XMODSRT = getenv("SFR:XMODSRT")
#word XMODEND = getenv("SFR:XMODEND")
#word YMODSRT = getenv("SFR:YMODSRT")
#word YMODEND = getenv("SFR:YMODEND")

#word ADCBUF0 = getenv("SFR:ADCBUF0")


// Define bit structures for MODCON Register
struct {
   int XWM:4;    // addr register for modular buffer X
   int YWM:4;    // addr register for modular buffer Y
   int BWM:4;    // addr register for bit reversing buffer
   int Reserved:2;
   int YMODEN:1; // enable modular buffer X
   int XMODEN:1; // enable modular buffer Y
} MODCONbits;
#locate MODCONbits = MODCON

// Constants for MODCONbits.XWM or XWM modulo addressing
#define MODCON_WREG0    0
#define MODCON_WREG1    1
#define MODCON_WREG2    2
#define MODCON_WREG3    3
#define MODCON_WREG4    4
#define MODCON_WREG5    5
#define MODCON_WREG6    6
#define MODCON_WREG7    7
#define MODCON_WREG8    8
#define MODCON_WREG9    9
#define MODCON_WREG10  10
#define MODCON_WREG11  11
#define MODCON_WREG12  12
#define MODCON_WREG13  13
#define MODCON_WREG14  14

// Constants for MODCONbits.XMODEN or YMODEN
#define MODCON_DISABLED 0
#define MODCON_ENABLED  1


// Constants for MODCONbits.XWM modulo addressing
#define XWM_REGISTER_W0  0



// Define bit structures for ADCON1 Register
struct {
   int DONE:1;   // Sample ready
   int SAMP:1;
   int ASAM:1;   // Automatic sample
   int Res1:2;
   int SSRC:3;   // Sample trigger source
   int FORM:2;   // Sample output format
   int Res2:3;
   int ADISDL:1;
   int Res3:1;
   int ADON:1;   // ADC module enabled
} ADCON1bits;
#locate ADCON1bits = ADCON1

// Constants for ADCON1bits.SSRC
#define ADC_TRIGGER_SOURCE_AUTO   0b111
#define ADC_TRIGGER_SOURCE_TIMER3 0b010
#define ADC_TRIGGER_SOURCE_INT0   0b001
#define ADC_TRIGGER_SOURCE_MANUAL 0b000

// Constants for ADCON1bits.FORM
#define ADC_FORM_SIGNED_FRACTIONAL 0b11
#define ADC_FORM_FRACTIONAL        0b10
#define ADC_FORM_SIGNED_INTEGER    0b01
#define ADC_FORM_INTEGER           0b00


// Define bit structures for ADCON3 Register
struct {
   int ADCS:6;   // A/D Conversion Clock Select bits
   int res:1;
   int ADRC:1;   // A/D Conversion Clock Source bit
   int SAMC:5;   // Auto Sample Time bits

} ADCON3bits;
#locate ADCON3bits = ADCON3
