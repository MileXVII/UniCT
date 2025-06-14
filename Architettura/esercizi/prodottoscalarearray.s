size_a   dcd     5
size_b   dcd     5
array_a  dcd     9, 12, 3, 5, 1
array_b  dcd     4, 6, 18, 8, 3

         mov     r1, #size_a
         mov     r2, #size_b
         ldr     r0, [r1]
         mov     r1, #array_a
         mov     r2, #array_b
         mov     r5, #0
loop     
         cmp     r0, #0
         beq     fine
         ldr     r3, [r1]
         ldr     r4, [r2]
multiply 
         cmp     r3, #0
         beq     next
         add     r4, r4, r4
         sub     r3, r3, #1
         b       multiply
next     
         add     r5, r5, r4
         add     r1, r1, #4
         add     r2, r2, #4
         sub     r0, r0, #1
         b       loop
fine     
         end
