size      dcd     10
array     dcd     4, 13, 6, 17, 22, 9, 15, 8, 3, 12

          mov     r1, #array
          ldr     r0, [r1]
          mov     r1, #array
          mov     r4, #0
loop      
          cmp     r0, #0
          beq     fine
          ldr     r2, [r1]
          and     r3, r2, #1
          cmp     r3, #0
          beq     pari
dispari   
          cmp     r2, #10
          bgt     somma
          add     r1, r1, #4
          sub     r0, r0, #1
          b       loop
somma     
          add     r4, r4, r2
          add     r1, r1, #4
          sub     r0, r0, #1
          b       loop
pari      
          cmp     r0, #1
          beq     end_shift
          ldr     r2, [r1, #4]
          str     r2, [r1]
          add     r1, r1, #4
          sub     r0, r0, #1
          b       pari
end_shift 
          mov     r1, #size
          ldr     r0, [r1]
          sub     r0, r0, #1
          str     r0, [r1]
          mov     r1, #array
          b       loop
fine      
          end
