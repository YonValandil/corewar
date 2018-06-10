.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti r1, %:live, %1
		and r1, %0, r1 ;set le carry a 0, car le resultat de l'operation est 0
;(carry=='0flag', peut prendre 2 value ou autres, sert que pour le zjmp)
;toutes les operation, and, or, add, etc modifie le carry

live:	live %1
		zjmp %:live //zjmp jump si le carry est a 0
