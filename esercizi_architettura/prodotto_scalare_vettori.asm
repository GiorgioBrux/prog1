DIM		DCD		3
VET1		DCD		5,8,6
VET2		DCD		8,1,3
RES		FILL		4*DIM
		
		MOV		R0, #DIM
		LDR		R0, [R0]
		
		MOV		R6, #0 ;contatore
		
		MOV		R1, #VET1
		MOV		R2, #VET2
		
		MOV		R8, #RES
		
CICLO	LDR		R3, [R1] ;VET1[i]
		LDR		R4, [R2] ;VET2[i]
		MOV		R5, R4
		SUB		R3, R3, #1
		B		MULT
		
TORNA	STR		R4, [R8]
		ADD		R8, R8, #4
		ADD		R1, R1, #4
		ADD		R2, R2, #4
		ADD		R6, R6, #1
		CMP		R6, R0
		BLT		CICLO
		END
		
		
MULT		ADD		R4, R4, R5
		SUB		R3, R3, #1
		CMP		R3, #0
		BGT		MULT
		B		TORNA
		
		
		
