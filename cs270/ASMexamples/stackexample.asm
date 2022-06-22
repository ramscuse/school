.ORIG x3000
MAIN    LD R6,STACK    ; init stack pointer
        LD R0, B 		   ; load second operand
        PUSH R0        ; PUSH second operand
        LD R1, A 		   ; load first operand
        PUSH R1        ; PUSH first operand
        JSR FOO			; call function
        LDR R0,R6,#0   ; POP return value
        ADD R6,R6,#3   ; unwind stack
        ST  R0, C		   ; store result
        HALT				
;
A  	 .FILL #5  	 		; first operand
B		 .FILL #20   		; second operand
C		 .BLKW 1     		; result
STACK .FILL x4000  		; stack address

FOO
	ADD R6,R6,#-1  ; alloc return value
	PUSH R7        ; PUSH return address
	PUSH R5        ; PUSH frame pointer
	ADD R5,R6,#-1  ; FP = SP-1
; 	
	ADD R6,R6,#-1  ; alloc local variable
	LDR R2,R5,#4   ; load first operand / A
	LDR R3,R5,#5   ; load second operand / B
	ADD R4,R3,R2   ; add operands
	STR R4,R5,#0   ; store local variable
; FOO stack exit code
       	STR R4,R5,#3   	; store return value
       	ADD R6,R5,#1   	; SP = FP+1
       	POP R5         	; POP frame pointer
       	POP R7         	; POP return address
       	RET            	; return              
;
		 .END

