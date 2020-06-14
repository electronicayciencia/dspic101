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


// Define bit structures for CORCON Register
struct {
   int IFMODE:1; // Integer or Fractional Multiplier Mode Select bit
   int RND:1;    // Rounding Mode Select bit
   int PSV:1;    // Program Space Visibility in Data Space Enable bit
   int IPL3:1;   // CPU Interrupt Priority Level Status bit 3
   int ACCSAT:1; // Accumulator Saturation Mode Select bit
   int SATDW:1;  // Data Space Write from DSP Engine Saturation Enable bit
   int SATB:1;   // AccB Saturation Enable bit
   int SATA:1;   // AccA Saturation Enable bit
   int DL:3;     // DO Loop Nesting Level Status bits
   int EDT:1;    // Early DO Loop Termination Control bit
   int US:1;     // DSP Multiply Unsigned/Signed Control bit
} CORCONbits;
#locate CORCONbits = CORCON

// Constants for CORCONbits
#define CORCON_IFMODE_INTEGER 1
#define CORCON_IFMODE_FRACT   0

#define CORCON_RND_BIASED   1
#define CORCON_RND_UNBIASED 0

#define CORCON_PSV_VISIBLE    1
#define CORCON_PSV_NOTVISIBLE 0

#define CORCON_ACCSAT_SUPER  1
#define CORCON_ACCSAT_NORMAL 0

#define CORCON_SATDW_ENABLED  1
#define CORCON_SATDW_DISABLED 0

#define CORCON_SATB_ENABLED  1
#define CORCON_SATB_DISABLED 0

#define CORCON_SATA_ENABLED  1
#define CORCON_SATA_DISABLED 0

#define CORCON_US_UNSIGNED 0
#define CORCON_US_SIGNED   1


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
#define MODCON_XWM_WREG0    0
#define MODCON_XWM_WREG1    1
#define MODCON_XWM_WREG2    2
#define MODCON_XWM_WREG3    3
#define MODCON_XWM_WREG4    4
#define MODCON_XWM_WREG5    5
#define MODCON_XWM_WREG6    6
#define MODCON_XWM_WREG7    7
#define MODCON_XWM_WREG8    8
#define MODCON_XWM_WREG9    9
#define MODCON_XWM_WREG10  10
#define MODCON_XWM_WREG11  11
#define MODCON_XWM_WREG12  12
#define MODCON_XWM_WREG13  13
#define MODCON_XWM_WREG14  14

// Constants for MODCONbits.YWM or YWM modulo addressing
// All other settings of the YWM<3:0> control bits are 
// reserved and should not be used.
#define MODCON_YWM_WREG10  10
#define MODCON_YWM_WREG11  11

// Constants for MODCONbits.BWM addressing
#define MODCON_BWM_WREG0    0
#define MODCON_BWM_WREG1    1
#define MODCON_BWM_WREG2    2
#define MODCON_BWM_WREG3    3
#define MODCON_BWM_WREG4    4
#define MODCON_BWM_WREG5    5
#define MODCON_BWM_WREG6    6
#define MODCON_BWM_WREG7    7
#define MODCON_BWM_WREG8    8
#define MODCON_BWM_WREG9    9
#define MODCON_BWM_WREG10  10
#define MODCON_BWM_WREG11  11
#define MODCON_BWM_WREG12  12
#define MODCON_BWM_WREG13  13
#define MODCON_BWM_WREG14  14

// Constants for MODCONbits.XMODEN or YMODEN
#define MODCON_XMODEN_DISABLED 0
#define MODCON_XMODEN_ENABLED  1
#define MODCON_YMODEN_DISABLED 0
#define MODCON_YMODEN_ENABLED  1

// Define bit structures for ADCON1 Register
struct {
   int DONE:1;   // A/D Conversion Status
   int SAMP:1;   // A/D Sample Enable
   int ASAM:1;   // A/D Sample Auto-Start
   int SIMSAM:1; // Simultaneous Sample Select
   int Res1:1;   // Unimplemented: Read as 0
   int SSRC:3;   // Conversion Trigger Source Select
   int FORM:2;   // Data Output Format
   int Res2:3;   // Unimplemented: Read as 0
   int ADISDL:1; // Stop in Idle Mode
   int Res3:1;   // Unimplemented: Read as 0
   int ADON:1;   // A/D Operating Mode
} ADCON1bits;
#locate ADCON1bits = ADCON1

#define ADCON_DONE_DONE    1
#define ADCON_DONE_NOTDONE 0

#define ADCON_SAMP_SAMPLING 1
#define ADCON_SAMP_HOLDING  0

#define ADCON_ASAM_AUTO   1
#define ADCON_ASAM_MANUAL 0

#define ADCON_SIMSAMP_SIMULTANEOUS 1
#define ADCON_SIMSAMP_SEQUENTIAL   0

#define ADCON_SSRC_MANUAL   0b000
#define ADCON_SSRC_INT0     0b001
#define ADCON_SSRC_TIMER3   0b010
#define ADCON_SSRC_PWM      0b011
#define ADCON_SSRC_AUTO     0b111

#define ADCON_FORM_SIGNED_FRACTIONAL 0b11
#define ADCON_FORM_FRACTIONAL        0b10
#define ADCON_FORM_SIGNED_INTEGER    0b01
#define ADCON_FORM_INTEGER           0b00

#define ADCON_ADSIDL_STOP     1
#define ADCON_ADSIDL_CONTINUE 0

#define ADCON_ADON_ON  1
#define ADCON_ADON_OFF 0




// Define bit structures for ADCON2 Register
struct {
   int ALTS:1;   // Alternate Input Sample Mode Select
   int BUFM:1;   // Buffer Mode Select
   int SMPI:4;   // Sample/Convert Sequences Per Interrupt Selection
   int res1:1;   // Unimplemented: Read as 0
   int BUFS:1;   // Buffer Fill Status
   int CHPS:2;   // Selects Channels Utilized
   int CSCNA:1;  // Scan Input Selections for CH0+ S/H Input for MUX A Input Multiplexer
   int res2:1;   // Unimplemented: Read as 0
   int res3:1;   // Reserved: User should write 0 to this location
   int VCFG:3;   // Voltage Reference Configuration
} ADCON2bits;
#locate ADCON2bits = ADCON2

#define ADCON_ALTS_ALTERNATE 1
#define ADCON_ALTS_MUXA      0

#define ADCON_BUFM_ONE16WORD 0
#define ADCON_BUFM_TWO8WORDS 1

#define ADCON_VCFG_AVDD_AVSS 0b000
#define ADCON_VCFG_VREF_AVSS 0b001
#define ADCON_VCFG_AVDD_VREF 0b010
#define ADCON_VCFG_VREF_VREF 0b011


// Define bit structures for ADCON3 Register
struct {
   int ADCS:6;   // A/D Conversion Clock Select bits
   int res:1;
   int ADRC:1;   // A/D Conversion Clock Source bit
   int SAMC:5;   // Auto Sample Time bits

} ADCON3bits;
#locate ADCON3bits = ADCON3
