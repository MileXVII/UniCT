size           dcd     10
array          dcd     9,4,5,28,43,1,8,3,4,3


               ;       R0 = i
               ;       R1 = ptr array
               ;       R4 = in_order

outer_loop     
               mov     r4,#1

               mov     r1,#size
               ldr     r0,[r1]
               mov     r1,#array
inner_loop     
               cmp     r0,#1
               beq     end_inner_loop

               ldr     r2,[r1]
               ldr     r3,[r1,#4]
               cmp     r2,r3 ; CMP ARRAY[i], ARRAY[i+1]
               ble     no_scambio

               str     r3,[r1]
               str     r2,[r1,#4]
               mov     R4,#0

no_scambio     
               add     r1,r1,#4
               sub     r0,r0,#1
               b       inner_loop

end_inner_loop 
               cmp     r4,#0
               beq     outer_loop

               end
