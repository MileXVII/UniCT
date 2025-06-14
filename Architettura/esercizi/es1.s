size_a    dcd     10
array_a   dcd     4,7,9,3,1,2,6,8,4,9
array_b   fill    40
array_c   fill    40

          ;r0     = size
          ;r1     array a
          ;r2     array b (pari)
          ;r3     array c (dispari)
          ;r5     = contatore pari
          ;r7     = contatore dispari
          ;r4     = elemento
          ;r8     = contatore del

          mov     r1,#size_a
          ldr     r0,[r1]
          ldr     r8,[r1]
          mov     r1,#array_a
          mov     r2,#array_b
          mov     r3,#array_c
          mov     r5,#0

loop      
          cmp     r0,#0
          beq     end_loop
          ldr     r4,[r1]
          ;       test pari
          and     r6,r4,#1
          cmp     r6,#0
          add     r1,r1,#4
          bne     dispari
          ;       r4 è pari
          str     r4,[r2]
          add     r2,r2,#4
          add     r5,r5,#1
          sub     r0,r0,#1
          b       delete

dispari   
          str     r4,[r3]
          add     r3,r3,#4
          add     r7,r7,#1
          sub     r0,r0,#1
          b       delete

delete    
          cmp     r8,#1
          beq     end_shift
          ldr     r4,[r1,#4]
          str     r3,[r1]
          add     r1,r1,#4
          sub     r8,r8,#1
          str     r8,[r1]
          b       delete

end_shift 
          mov     r1,#size_a
          ldr     r0,[r1]
          sub     r0,r0,r8
          str     r0,[r1]
          b       loop

end_loop  
          end

