              MOV     R1,#3
              MOV     R2,#5
              MOV     R0,#0
multiply_loop 
              cmp     R2,#0
              beq     end_multiply
              add     R0,R0,R1
              sub     R2,R2,#1
              b       multiply_loop
end_multiply  




              mov     R3,#18
              mov     R4,#3
              mov     R5,#0

divison_loop  
              cmp     R3,R4
              blt     end_divison
              sub     R3,R3,R4
              add     R5,R5,#1
              b       divison_loop
end_divison   
