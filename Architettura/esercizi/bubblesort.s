size    dcd     10
array   dcd     4, 6, 18, 8, 3, 9, 91, 72, 14 ,22

        mov     r1, #size
        ldr     r0, [r1]
        mov     r1, #array
loop    
        cmp     r0, #1
        ble     fine
        sub     r0, r0, #1
        mov     r2, r1 ;puntatore corrente inizio array
        mov     r9, r0 ;control loop
control 
        cmp     r9, #0
        beq     loop
        ldr     r3, [r2] ;el. corrente
        ldr     r4, [r2, #4] ;el. successivo
        cmp     r3, r4
        ble     skip
        ;scambio
        str     r4, [r2]
        str     r3, [r2, #4]
skip    
        add     r2, r2, #4
        sub     r9, r9, #1
        b       control
fine    
        end
