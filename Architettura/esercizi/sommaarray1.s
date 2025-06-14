size_a  dcd     10
array_a dcd     7,3,4,1,2,9,12,28,5,34
array_b fill    20

        mov     r1, #size_a
        ldr     r0, [r1]
        mov     r1, #array_a
        mov     r2, #array_b
loop    
        cmp     r0, #0
        beq     fine
        ldr     r3, [r1]
        ldr     r4, [r1, #4]
        add     r5, r3, r4
        str     r5, [r2]
        add     r1, r1, #8
        add     r2, r2, #4
        sub     r0, r0, #2
        b       loop
fine    
        end
