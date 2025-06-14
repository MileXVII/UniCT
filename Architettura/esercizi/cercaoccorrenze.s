size   dcd     10
array  dcd     9, 8, 12, 9, 42, 1, 1, 9, 23

       mov     r1, #size
       ldr     r0, [r1]
       mov     r1, #array
       mov     r5, #9
       mov     r4, #0
loop   
       cmp     r0, #0
       beq     fine
       ldr     r2, [r1]
       cmp     r5, r2
       beq     count
       add     r1, r1, #4
       sub     r0, r0, #1
       b       loop
count  
       add     r4, r4, #1
       add     r1, r1, #4
       sub     r0, r0, #1
       b       loop
fine   
       end
