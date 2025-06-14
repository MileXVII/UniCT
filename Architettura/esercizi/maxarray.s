size   dcd     10
array  dcd     10, 22, 41, 7, 12, 8, 12, 73, 91, 5

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
       blt     max
       add     r1, r1, #4
       sub     r0, r0, #1
       b       loop
max    
       mov     r5, r2
       add     r1, r1, #4
       sub     r0, r0, #1
       b       loop
fine   
       end

