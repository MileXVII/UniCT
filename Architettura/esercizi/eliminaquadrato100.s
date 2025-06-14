size      dcd     6
array     dcd     5, 11, 9, 7, 15, 3

          mov     r1, #size
          ldr     r0, [r1]
          mov     r1, #array
loop      
          cmp     r0, #0
          beq     fine
          ldr     r3, [r1]
          mov     r4, r3
          mov     r5, r3
          mov     r6, #0
multiply  
          cmp     r4, #0
          beq     loop2
          add     r6, r6, r5
          sub     r4, r4, #1
          b       multiply
loop2     
          cmp     r6, #100
          bgt     delete
          add     r1, r1, #4
          sub     r0, r0, #1
          b       loop
delete    
          cmp     r0, #1
          beq     end_shift
          ldr     r3, [r1, #4]
          str     r3, [r1]
          add     r1, r1, #4
          sub     r0, r0, #1
end_shift 
          mov     r1, #size
          ldr     r0, [r1]
          sub     r0, r0, #1
          str     r0, [r1]
          mov     r1, #array
          b       loop
fine      
          end