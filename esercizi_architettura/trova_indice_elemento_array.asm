		;		Trova elemento in array (indice)
		
ARR		DCD		1,7,3,8,4
NN		DCD		5
TROVA	DCD		8
RIS		FILL		4 ;Qui inseriamo l'indice se lo troviamo
		
		;		R0, il numero trova
		;		R1, puntatore all'array
		;		R2, puntatore all'ultimo elemento array
		
		
		MOV		R10, #RIS ;Ci serve dopo per storare
		MOV		R0, #TROVA
		LDR		R0, [R0]
		
		
		MOV		R1, #ARR
		
		MOV		R5, #NN
		LDR		R5, [R5]
		
		MOV		R2, R1
		MOV		R6, #0
		
		
AGGIUNGI	ADD		R2, R2, #4 ;Indirizzo dell'ultimo elemento dell'array
		SUB		R5, R5, #1
		CMP		R5, #0
		BGT		AGGIUNGI
		
		
		
		
		
CICLO	LDR		R3, [R1]
		CMP		R0, R3
		BEQ		TROVATO
		ADD		R6, R6, #1
		ADD		R1, R1, #4
		CMP		R1, R2
		BLT		CICLO
		B		NOTROVATO
		
		
		
TROVATO	SUB		R1, R2, R1
		STR		R6, [R10]
		END
		
		
		
NOTROVATO	END		;Lasciamo il risultato vuoto
		
