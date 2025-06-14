size        dcd     5
array       dcd     7, 14, 9, 3, 12
size_b      dcd     0
array_b

            mov     r1, #size
            ldr     r0, [r1]        ; r0 = size originale
            mov     r1, #array      ; r1 = ptr array
            mov     r6, #array_b    ; r6 = base array_b
            mov     r7, #size_b     ; r7 = addr size_b

            ldr     r2, [r7]        ; r2 = size array_b
            lsl     r8, r2, #2
            add     r3, r6, r8      ; r3 = ptr fine array_b

loop
            cmp     r0, #0
            beq     sort_dispari

            ldr     r4, [r1]
            and     r5, r4, #1
            cmp     r5, #0
            bne     next            ; se dispari, salta

            cmp     r2, #0
            beq     insert_at_end

insert_ord
            cmp     r2, #0
            beq     end_insert
            ldr     r9, [r3, #-4]
            cmp     r9, r4
            bgt     shift_b
            b       insert_at_end

shift_b
            str     r9, [r3]
            sub     r3, r3, #4
            sub     r2, r2, #1
            b       insert_ord

insert_at_end
            str     r4, [r3]
end_insert

            ldr     r5, [r7]
            add     r5, r5, #1
            str     r5, [r7]

elimina
            cmp     r0, #1
            beq     end_shift
            ldr     r4, [r1, #4]
            str     r4, [r1]
            add     r1, r1, #4
            sub     r0, r0, #1
            b       elimina

end_shift
            mov     r1, #size
            str     r0, [r1]
            mov     r1, #array
            b       loop

next
            add     r1, r1, #4
            sub     r0, r0, #1
            b       loop

sort_dispari
            mov     r1, #size
            ldr     r0, [r1]        ; r0 = size
            mov     r1, #array
            mov     r10, r0

outer_loop
            sub     r10, r10, #1
            cmp     r10, #0
            beq     fine
            mov     r11, #0
            mov     r1, #array

inner_loop
            ldr     r2, [r1]
            ldr     r3, [r1, #4]
            cmp     r2, r3
            ble     no_swap

            ; swap
            str     r3, [r1]
            str     r2, [r1, #4]

no_swap
            add     r1, r1, #4
            add     r11, r11, #1
            cmp     r11, r10
            blt     inner_loop
            b       outer_loop

fine
            end
