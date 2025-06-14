size_a   dcd     10 ;dichiariamo la grandezza di un array da 10 numeri
array_a  dcd     4,5,6,7,8,1,2,3,4,5 ;10 numeri da mettere dentro l'array
array_b  fill    40 ;dichiarazione zona di memoria di 40 byte

         ;r0     = size
         ;r1     = ptr a
         ;r2     = ptr b
         ;r3     = elemento
         ;r5     = numero di elementi array b
         mov     r1, #size_a ;diamo ad r1 la capienza di size_a
         ldr     r0, [r1] ;r0 numero di elementi
         mov     r1, #array_a ;puntatore ad array a
         mov     r2, #array_b ;puntatore ad array b
         mov     r5, #0 ;impostiamo r5 a 0
loop     ;inizio loop
         cmp     r0, #0 ;compariamo r0 con 0
         beq     end_loop ;se uguali (EQ) effettuiamo un salto alla fine del loop
         ldr     r3,[r1] ;r3 numero di elementi
         ;test   pari
         and     r4,r4,#1 ;r4 = r1 and 1
         cmp     r4,#0 ;compariamo r4 con 0
         bne     dispari ;se è diverso effettuiamo un salto su dispari
         ;r3     è pari
         str     r3,[r2] ;?
         add     r2,r2,#4 ;inseriamo in r2 la somma tra r2 e 4
         add     r5,r5,#1 ;inseriamo in r5 la somma tra r5 e 1
dispari  ;numero dispari
         add     r1,r1,#4 ;inseriamo in r1 la somma tra r1 e 4
         sub     r0,r0,#1 ;sottriamo 1 da r0
end_loop ;fine   del loop
         end     ;fine del programma