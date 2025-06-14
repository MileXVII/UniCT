size_a  dcd     10
array_a dcd     24, 31, 7, 9, 34, 22, 5, 1, 32, 59
size_b  dcd     10
array_b dcd     12, 63, 11, 2, 43, 7, 8, 15, 21, 19
array_c fill    40

        mov     r1, #size_a
        ldr     r0, [r1] ; r0 = lunghezza array (10)

        mov     r2, #array_a ; r2 = puntatore array_a
        mov     r3, #array_b ; r3 = puntatore array_b
        mov     r4, #array_c ; r4 = puntatore array_c

loop    
        cmp     r0, #0
        beq     fine

        ldr     r5, [r2] ; r5 = array_a[i]
        ldr     r6, [r3] ; r6 = array_b[i]
        add     r7, r5, r6 ; r7 = somma
        str     r7, [r4] ; salva in array_c[i]

        add     r2, r2, #4 ; avanza array_a
        add     r3, r3, #4 ; avanza array_b
        add     r4, r4, #4 ; avanza array_c
        sub     r0, r0, #1 ; decrementa contatore
        b       loop

fine    
        end
