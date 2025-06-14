size   dcd     10
array  dcd     43, 12, 56, 11, 9, 8, 72, 1, 19, 23

       mov     r1, #size
       ldr     r0, [r1]
       mov     r1, #array
       ldr     r5, [r1]
       add     r1, r1, #4
loop   
       cmp     r0, #1
       beq     fine
       ldr     r2, [r1]
       cmp     r5, r2
       bgt     minimo
       add     r1, r1, #4
       sub     r0, r0, #1
       b       loop
minimo 
       mov     r5, r2
       add     r1, r1, #4
       sub     r0, r0, #1
       b       loop
fine   