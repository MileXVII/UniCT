size      dcd     5
array     dcd     33, 12, 7, 12, 45

          mov     r1, #size
          ldr     r0, [r1]
          mov     r1, #array
loop      
          cmp     r0, #0
          beq     fine
          ldr     r2, [r1]
          and     r3, r2, #1
          cmp     r3, #1
          beq     delete
          add     r1, r1, #4
          sub     r0, r0, #1
          b       loop
delete    
          cmp     r0, #0
          beq     end_shift
          ldr     r2, [r1, #4]
          str     r2, [r1]
          add     r1, r1, #4
          sub     r0, r0, #1
          b       delete
end_shift 
          mov     r1, #size
          ldr     r0, [r1]
          sub     r0, r0, #1
          str     r0, [r1]
          mov     r1, #array
          b       loop
fine      
          end

