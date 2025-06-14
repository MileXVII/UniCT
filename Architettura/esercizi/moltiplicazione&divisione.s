              MOV     R1, #7 ;mettiamo 7 in R1
              MOV     R2, #20 ;mettiamo 20 in R2 (contatore)
              MOV     R0, #0 ;mettiamo 0 in R0
multiply_loop ;inizio loop moltiplicazione
              CMP     R2, #0 ;confrontiamo R2 con 0
              beq     end_multiply ;se uguale (EQ) salta a m.p.
              add     R0, R0, R1 ;aggiungiamo a r0 r1
              sub     R2, R2, #1 ;sottriamo 1 da r2
              b       multiply_loop ;ritorniamo su
end_multiply  ;fine   m.p.

              MOV     R3, #18 ;mettiamo 18 in r3
              MOV     R4, #3 ;mettiamo 3 in r4
              MOV     R5, #0 ;mettiamo 0 in r5
divion_loop   ;inizio loop divisione
              CMP     R3, R4 ;confrontiamo r3 e r4
              blt     end_division ;se r3 è minore saltiamo alla divisione
              sub     R3, R3, R4 ;sottriamo r4 a r3
              add     R5, R5, #1 ;aggiungiamo 1 a r5
              b       divion_loop
end_division  
              end