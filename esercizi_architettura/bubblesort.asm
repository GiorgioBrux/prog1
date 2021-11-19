ARR		DCD		9,5,4,3,2
NUM		DCD		5
		
		
		MOV		R0, #ARR
		MOV		R1, R0
		ADD		R1, R1, #4 ;R0=*arr, R1= *arr+4
		
		MOV		R9, #NUM
		LDR		R2, [R9]
		MOV		R8, R2
		
CICLO	LDR		R3, [R0]
		LDR		R4, [R1]
		CMP		R3, R4
		BGT		SWAP
BACK		STR		R3, [R0]
		STR		R4, [R1]
		SUB		R2, R2, #1
		ADD		R1, R1, #4
		ADD		R0, R0, #4
		CMP		R2, #1
		BGT		CICLO
		SUB		R8, R8, #1
		MOV		R0, #ARR
		MOV		R1, R0
		ADD		R1, R1, #4
		CMP		R8, #0
		LDR		R2, [R9]
		BGT		CICLO
		END
		
		
		
SWAP		MOV		R5, R4
		MOV		R4, R3
		MOV		R3, R5
		B		BACK
		
