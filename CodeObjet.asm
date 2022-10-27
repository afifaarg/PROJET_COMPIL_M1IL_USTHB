
TITLE : ID_program

PILE SEGMENT stack
		100 DD dup (?)
PILE ENDS

DATA SEGMENT
	a DW 
 	b DW 
 	c DW 
 	d DD 
 	g DT 
 	l DW 
 DATA ENDS

CODE SEGMENT
MAIN:
		ASSUME SS: PILE, DS: DATA, CS: CODE
			Mov AX,DATA
			Mov DX,AX

			MOV AX,1
			MOV a,AX
			MOV AX,4
			MUL AX,b
			PUSH AX
			MOV AX,a
			MOV i,AX
			MOV AX,i
			MOV BX,20
			CMP AX,BX
			JG etiq[ 9 ]
			MOV AX,1
			PUSH AX
			JMP etiq[ 10 ]
etiq [ 9 ] : 
			MOV AX,0
			PUSH AX
etiq [ 10 ] : 
etiq [ 10 ] : 
			POP AX
			 CMP AX,0
			 JE etiq[ 14 ]
			MOV AX,3
			ADD AX,7
			PUSH AX
			JMP etiq[ 10 ]
			MOV AX,c
			MOV BX,4
			CMP AX,BX
			JG etiq[ 17 ]
etiq [ 14 ] : 
			MOV AX,1
			PUSH AX
			JMP etiq[ 18 ]
			MOV AX,0
			PUSH AX
etiq [ 17 ] : 
			POP AX
			CMP AX,0
			JNE etiq[ 21 ]
etiq [ 18 ] : 
			MOV AX,
			PUSH AX
			JMP etiq[ 22 ]
			MOV AX,
			PUSH AX
etiq [ 21 ] : 
			POP AX
			 CMP AX,0
			 JE etiq[ 26 ]
etiq [ 22 ] : 
			MOV AX,b
			ADD AX,5
			PUSH AX
			JMP etiq[ 28 ]
			MOV AX,a
			ADD AX,5
			PUSH AX
			MOV AX,4
			MOV BX,c
			CMP AX,BX
			JG etiq[ 31 ]
etiq [ 26 ] : 
			MOV AX,1
			PUSH AX
			JMP etiq[ 32 ]
etiq [ 28 ] : 
			MOV AX,0
			PUSH AX
			POP AX
			CMP AX,0
			JNE etiq[ 35 ]
			MOV AX,
			PUSH AX
etiq [ 31 ] : 
			JMP etiq[ 36 ]
etiq [ 32 ] : 
			MOV AX,
			PUSH AX
			POP AX
			 CMP AX,0
			 JE etiq[ 38 ]
			MOV AX,1
			MOV b,AX
CODE ENDS
END BEGIN
