; Calcola il massimo tra due numeri

N1		DCD		5
N2		DCD		2
RIS		FILL		4
		
		MOV		R0, #N1
		LDR		R1, [R0]
		
		ADD		R0, R0, #4
		LDR		R2, [R0]
		
		CMP		R1, R2
		MOV		R0, #RIS
		BLT		N2GRANDE
		
N1GRANDE	STR		R1, [R0]
		END
		
N2GRANDE	STR		R2, [R0]
		END
