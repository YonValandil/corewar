.name    "sebc"
.comment "sebc"
.extend
	st	r1, :l1+1           ;//+1 byte ici => %1 ligne 5
l1:	live	%1
	ld	%:l1 - :l2, r2
l3:	ldi	%:l2, r2, r4
	sti	r4, %:l2 - 100, r2
	add	r2, r3, r2
live:	zjmp	%:l1 - 100
	xor	r4, r4, r4
	zjmp	%:l3
l2:

;-----------------------------------------------

0x1  [st] [r1] [l1] [l1]
      03   01    |00 05
                 |
                 |
          l1:    v
0x5    [live] [ii] [] [] []
        01     00  00 00 01

