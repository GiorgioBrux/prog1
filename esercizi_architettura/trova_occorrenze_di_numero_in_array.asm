ARR		DCD		1,2,2,7,2
NUM		DCD		5
FIND		DCD		2
RIS		FILL		4
		
		MOV		R0, #ARR
		MOV		R1, #NUM
		MOV		R5, #RIS
		MOV		R7, #FIND
		LDR		R7, [R7]
		LDR		R1, [R1]
		MOV		R2, #0
		
CICLO	LDR		R6, [R0]
		CMP		R6, R7
		BNE		SKIP
		ADD		R2, R2, #1
SKIP		SUB		R1, R1, #1
		CMP		R1, #0
		ADD		R0, R0, #4
		BGT		CICLO
		
		STR		R2, [R5]
		END
