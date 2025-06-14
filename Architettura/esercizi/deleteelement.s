size dcd 9
array dcd 4, 3, 5, 10, 1, 0, 9, 4, 2

mov r1, #size
ldr r0, [r1]
mov r1, #array
mov r2, #2 ;elemento da rimuovere

find_loop
    cmp r0, #0
    beq fine
    ldr r3, [r1]
    cmp r3, r2
    beq element_found
    add r1, r1, #4
    sub r0, r0, #1
    b find_loop
element_found
    cmp r0, #1
    beq end_shift
    ldr r3, [r1, #4]
    str r3, [r1]
    add r1, r1, #4
    sub r0, r0, #1
    b element_found
end_shift
    mov r1, #size
    ldr r0, [r1]
    sub r0, r0, #1
    str r0, [r1]
fine
    end
