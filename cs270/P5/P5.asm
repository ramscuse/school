; P5 Assignment
; Author: <name>
; Date:   <date>
; Email:  <email>
; Class:  CS270
;
; Description: Implements the arithmetic, bitwise, and shift operations

;------------------------------------------------------------------------------
; Begin reserved section: do not change ANYTHING in reserved section!

                .ORIG x3000
                BR Main

Functions       .FILL IntAdd         ; Address of IntAdd routine          (option 0)
                .FILL IntSub         ; Address of IntSub routine          (option 1)
                .FILL IntMul         ; Address of IntMul routine          (option 2)
                .FILL BinaryOr       ; Address of BinaryOr routine        (option 3)
                .FILL BinaryXOr      ; Address of BinaryXOr routine       (option 4)
                .FILL LeftShift      ; Address of LeftShift routine       (option 5)
                .FILL RightArithShift; Address of RightArithShift routine (option 6)

Main            LEA R0,Functions     ; The main routine calls one of the 
                LD  R1,Option        ; subroutines below based on the value of
                ADD R0,R0,R1         ; the Option parameter.
                LDR R0,R0,0          ;
                JSRR R0              ;
EndProg         HALT                 ;

; Parameters and return values for all functions
; Try changing the .BLKW 1 to .FILL xNNNN where N is a hexadecimal value or #NNNN
; where N is a decimal value, this can save you time by not having to set these 
; values in the simulator every time you run your code. This is the only change 
; you should make to this section.
Option          .FILL #0             ; Which function to call
Param1          .BLKW 1              ; Space to specify first parameter
Param2          .BLKW 1              ; Space to specify second parameter
Result          .BLKW 1              ; Space to store result

; End reserved section: do not change ANYTHING in reserved section!
;------------------------------------------------------------------------------

; You may add variables and functions after here as you see fit.
One             .FILL #1             ; the number 1  
;------------------------------------------------------------------------------
IntAdd                               ; Result is Param1 + Param2
                                     ; Your code goes here (~4 lines)
		LD R0,Param1
		LD R1,Param2
		ADD R2,R0,R1
		ST R2,Result
                RET
;------------------------------------------------------------------------------
IntSub                               ; Result is Param1 - Param2
                                     ; Your code goes here (~6 lines)
		LD R0,Param1
		LD R1,Param2
		NOT R1,R1
		ADD R1,R1,#1
		ADD R2,R0,R1
		ST R2,Result
                RET
;------------------------------------------------------------------------------
IntMul                               ; Result is Param1 * Param2
                                     ; Your code goes here (~9 lines)
		LD R0,Param1
		LD R1,Param2
		ADD R1,R1,#0
		BRz Else
	Top	
		ADD R2,R2,R0
		ADD R1,R1,#-1
		BRp Top
		ST R2,Result
		BR End_Else
	Else
		ST R1,Result
	End_Else
                RET
;------------------------------------------------------------------------------
BinaryOr                             ; Result is Param1 | Param2
                                     ; Your code goes here (~7 lines)
		LD R0,Param1
		LD R1,Param2
		NOT R0,R0
		NOT R1,R1
		AND R2,R0,R1
		NOT R2,R2
		ST R2,Result		
                RET
;------------------------------------------------------------------------------
BinaryXOr                            ; Result is Param1 ^ Param2
                                     ; Your code goes here
		LD R0,Param1
		LD R1,Param2
		AND R2,R0,R1
		NOT R2,R2
		AND R2,R0,R2
		NOT R2,R2
		AND R3,R0,R1
		NOT R3,R3
		AND R3,R1,R3
		NOT R3,R3
		AND R4,R2,R3
		NOT R4,R4
		ST R4,Result
                RET
;------------------------------------------------------------------------------
LeftShift                            ; Result is Param1 << Param2
                                     ; (Fill vacant positions with 0's)
                                     ; Your code goes here (~7 lines)
		LD R0,Param1
		LD R1,Param2
	loop	
		ADD R0,R0,R0
		ADD R1,R1,#-1
		BRp loop
		ST R0,Result
                RET
;------------------------------------------------------------------------------
RightArithShift                      ; Result is Param1 >> Param2 with sign extension
                                     ; Your code goes here (~23 lines)
		
                RET
;------------------------------------------------------------------------------
                .END
