	.ORIG x3000
	BR Main
Param	.BLKW 1
Result	.BLKW 1
Stack	.FILL x4000
One	.FILL #1


Main		LD R6,Stack
		LD R5,Stack
		LD R0,Param
		Push R0		; step 1 push parameter
		JSR Fac		; step 2 call factorial
		POP R2		; step 13 retrieve return value
		ADD R6,R6,#1	; step 14 remove parameter from stack
		ST R2,Result	; store return value in result		
End		HALT

Fac     	ADD R6,R6,#-1  	; step 3 alloc return value
        	PUSH R7        	; step 4 PUSH return address
        	PUSH R5        	; step 5 PUSH frame pointer
	        ADD R5,R6,#-1  	; step 6 set up new frame pointer FP = SP-1
        	ADD R6,R6,#-1	; step 7 allocate space for local variable

Checkpoint1	LDR R0,R5,#4	; load param into register

        	ADD R2,R0,#-1	; calculate N-1 and store in R1
		STR R5,R2,#0	; store N-1 in the local variable
		BRnz BaseCase	; Detect base case (N<=1)
		
        	Push R2		; step 1 push parameter
		JSR Fac		; step 2 call factorial
		STR R2,R5,#1	; step 13 retrieve return value into R1
		ADD R6,R6,#1	; step 14 remove parameter from stack
		
		LDR R0,R5,#4	; multiply N * Factorial(N-1)
		.ZERO R3	; R3 will conatin the product	
Mult		ADD R3,R3,R2	
		ADD R0,R0,#-1
		BRp Mult		
		STR R3,R5,#3
		BR Finish		

BaseCase	LD R0, One	; Make return value = 1
		STR R0, R5,#3	;

Finish		ADD R6,R6,#1	; step 9 remove local variable from stack
		POP R5		; step 10 restore previous frame pointer
		POP R7		; step 11 restore return address
Checkpoint2	RET		; steo 12 return to calling subroutine

		.END
