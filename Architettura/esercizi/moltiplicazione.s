         MOV     R1, #7 ; mettiamo 7 nel registro 1
         MOV     R2, #20 ; mettiamo 20 nel registro 2 (contatore)
         MOV     R0, #0 ; impostiamo a 0 il registro 0
loop     ; inizio loop
         cmp     R2, #0 ;compariamo r2 con 0 
         beq     end_loop ;se sono uguali salta a end_loop
         add     R0, R0, R1 ;sommiamo r1 con r0 e mettiamo il risultato in r0
         sub     R2, R2, #1 ;sottriamo di uno r2 
         b       loop ;ritorniamo su
end_loop 
         end ;fine programma