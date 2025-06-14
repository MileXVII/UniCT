size_a   dcd     10
array_a  dcd     4,5,6,7,8,1,2,3,4,5
array_b  fill    40 ; dichiarazione di zona di memoria di 40 byte
         ;
         ;       r0 = size
         ;       r1 = ptr a
         ;       r2 = ptr b
         ;       r3 = elemento
         ;       r5 = numero di elementi dell'array b
         ;
         mov     r1,#size_a
         ldr     r0,[r1]
         mov     r1,#array_a
         mov     r2,#array_b
         mov     r5,#0

loop     
         cmp     r0,#0
         beq     end_loop
         ldr     r3,[r1]
         ;       test pari
         and     r4,r3,#1 ; r4 = r3 and 1
         cmp     r4,#0
         bne     dispari
         ;       r3 e' pari
         str     r3,[r2]
         add     r2,r2,#4
         add     r5,r5,#1

dispari  
         add     r1,r1,#4
         sub     r0,r0,#1
         b       loop

end_loop 
         end