; WSU-EECS-CS594L
*
INT5 EQU $0074 ;Level 5 autovector
…
;
LEDS EQU $E003 ;I/O address of LED display

;
           ORG $900
PROG       MOVE.L #Int5p,INT5 ;Set interrupt vectors

           MOVE.W #$2400,SR ;Accept IRQ 5 - 7
           BRA * ;Wait for interrupts
;
* Interrupt 5 routine
Int5p …
;
* Interrupt 6 routine
Int6p …
;
* Interrupt 7 routine
Int7p …
           END PROG
;