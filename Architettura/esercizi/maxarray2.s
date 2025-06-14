size_a   dcd     10
size_b   dcd     10
array_c  fill    40
array_a  dcd     10, 12, 45, 7, 34, 9, 28, 72, 11, 99
array_b  dcd     11, 4, 43, 12, 70, 23, 1, 35, 23, 99

         mov     r1, #size_a
         ldr     r0, [r1] ;lunghezza array_a

         mov     r2, #array_a
         mov     r3, #array_b
         mov     r4, #array_c
loop     
         cmp     r0, #0
         beq     fine
         ldr     r5, [r2]
         ldr     r6, [r3]
         cmp     r5, r6
         bge     maggiore
         str     r6, [r4]
         add     r2, r2, #4
         add     r3, r3, #4
         sub     r0, r0, #1
         b       loop

maggiore 
         str     r5, [r4]
         add     r2, r2, #4
         add     r3, r3, #4
         sub     r0, r0, #1
         b       loop
fine     
         end



