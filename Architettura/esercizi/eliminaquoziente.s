size      dcd     8
array     dcd     9, 12, 7, 18, 20, 15, 4, 6

    mov r1, #size
    ldr r0, [r1]
    mov r1, #array

loop
    cmp r0, #0
    beq fine
    ldr r2, [r1]
    mov r3, #3
    mov r5, #0
division
    cmp r2, r3
    blt cltq
    sub r2, r2, r3
    add r5, r5, #1
    b division
cltq    
    and r6, r5, #1
    cmp r6, #1
    beq elimina
    add r1, r1, #4
    sub r0, r0, #1
    b loop
elimina
    cmp r0, #1
    beq end_shift
    ldr r2, [r1, #4]
    str r2, [r1]
    add r1, r1, #4
    sub r0, r0, #1
    b elimina
end_shift
    mov r1, #size
    ldr r0, [r1]
    sub r0, r0, #1
    str r0, [r1]
    mov r1, #array
    b loop
fine
    end
