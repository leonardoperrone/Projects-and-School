     ; WSU-EECS-CS594L

SWTH EQU $E001 ;I/O address of switches
LEDS EQU $E003 ;I/O address of LED display

           ORG $900
           LEA $7000,A7 ;SP for subroutine

;INIT       ORI.B #$3C,D0 ;force LEDS connected to L5-L2 to be ON, initialize the LEDS to 3C

LOOPALL    MOVE.B #0,LEDS
CHKB7      BTST.B #7,SWTH              ;test b7 to decide on direction of rotation;
           BNE SKIP
           ORI.B #$3C,D0 ;force LEDS connected to L5-L2 to be ON
           MOVE.B D0,LEDS

SKIP       BTST.B #7,SWTH
           BEQ CHKB7

           MOVE.B D0,LEDS   ;make sure S5-S2 are turned ON anyway


CHKB6      BTST.B #6,SWTH              ;test b6 to decide on direction of rotation;…
           BNE RRGHT
RLEFT      ROL.B #1,D0   ;rotate bit pattern to the left
           MOVE.B    D0,LEDS    ;Copy to the LEDS
           BSR CHKB4
           BRA CHKB5


           BTST.B #6,SWTH
           BEQ CHKB6
RRGHT      ROR.B     #1,D0   ;rotate bit pattern to the right
           MOVE.B    D0,LEDS    ;Copy to the LEDS
           BSR CHKB4
           BRA CHKB5




DONE       TRAP #15
           DC.W 0

CHKB5      BTST.B #5,SWTH
           BEQ DLY1
           BRA DLY2

CHKB4      BTST #4,SWTH
           BNE BIT4
           RTS

BIT4       LEA MSG,A0
           TRAP #15
           DC.W 7
           RTS
MSG        DC.B 'Hope you are enjoying this Lab',0



DLY1       MOVE.L #25,D5
LOOP1      BSR DELAY
           SUBQ #1,D5
           BNE LOOP1
           BRA LOOPALL

DLY2       MOVE.L #100,D5
LOOP2      BSR DELAY
           SUBQ #1,D5
           BNE LOOP2
           BRA LOOPALL



DELAY      MOVE.L #$7FFFFFFF,D4
LOOPDLY    SUBQ #1,D4
           BNE LOOPDLY
           RTS