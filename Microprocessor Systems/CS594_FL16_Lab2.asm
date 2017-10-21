; WSU-EECS-CS594L
*
SIZE1 EQU 5 ; array size
…
;
           ORG $0A00
* Program starts here
START      LEA $7000,A7 ; set SP (USP) for subroutine
…
; Set parameters to ascending sort Array 1; then call SORT subroutine
SORT1
           BSR SORT ; ascending sort Array 1
…
; Set parameters to ascending sort Array 2; then call SORT subroutine
SORT2 ……
           BSR SORT ; ascending sort Array 2
…
           TRAP #15
           DC.W 0 ; call system function 0 (exit program)
; Sort subroutine
SORT       MOVE.B D0,D2 ; set loop counter D2=(Size - 1)
…
RTS
; Data section
           ORG $AA0
Ary1       DC.B 5,4,2,3,1 ; Array 1 (before/after sorting)
           ORG $AA8
Ary1s      DS.B 5 ; Array 1 sorted 1,2,3,4,5 (after)
…
;