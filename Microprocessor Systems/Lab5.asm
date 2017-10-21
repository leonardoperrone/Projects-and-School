
; WSU-EECS-CS594L
*
INTT EQU $0040 ; Timer interrupt auto-vector address
BAR  EQU $E007 ; Timer interrupt auto-vector address
INT4 EQU $0070 ; Level 4 interrupt auto-vector address
INT5 EQU $0074 ; Level 5 interrupt auto-vector address
LEDS EQU $E003 ; I/O address of LEDs display (Output)
INT3 EQU $006C ; Level 3 interrupt auto-vector address

           ORG $900
* Program begins here
PROG       MOVE.L #Inttp,INTT
           MOVE.L #Int4p,INT4
           MOVE.L #Int5p,INT5
           MOVE.L #Int3p,INT3
           MOVE.W #$2200,SR ; MAKE THE RIGHT CHOICE
           LEA $7000,A7 ;SP for subroutine
 ; Set/clear registers as needed
           ;BRA  ; Wait for interrupt

LOOP       BRA LOOP ; Interrupts with higher levels are serviced
           ;RTE ; DO WE NEED THIS?

           TRAP #15
           DC.W 0

Int3p      LEA MSG1,A0
           TRAP #15
           DC.W 7
           RTE
MSG1       DC.B 'Ping!',0


* Level-4 Interrupt Service Routine
Int4p      ADDQ #1,D4
           MOVE.B D4,LEDS
           ;CMP.B #$FF,D4
           ;BNE SKIP1
           ;CLR.L D4
           BRA *
;SKIP1
           RTE



* Level-5 Interrupt Service Routine
  ; Service level-5 interrupts (hint: say “pong”)
Int5p      LEA MSG,A0
           TRAP #15
           DC.W 7
           RTE
MSG        DC.B 'Pong!',0
* Timer Interrupt Service Routine
Inttp

           ADD.L #1,D0
           MOVE.B D0,BAR
           CMP.B #$FF,D0
           BNE SKIP
           CLR.L D0
SKIP       RTE




