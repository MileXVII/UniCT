size      dcd     9
array     dcd     4,3,5,10,1,0,9,4,2

          MOV     R1,#size
          ldr     R0,[R1]
          MOV     R1,#array
          MOV     R2,#2

loop      
          CMP     R0,#0
          beq     fine_loop
          ldr     R3,[R1]
          CMP     R3,R2
          beq     delete
          add     R1,R1,#4
          sub     R0,R0,#1
          b       loop

delete    
          ;sub    R3,R3,R3 quesoto serve per sostituire il numero
          ;str    R3,[R1]
          CMP     R0,#1
          beq     end_shift
          ldr     R3,[R1,#4]
          str     R3,[R1]
          add     R1,R1,#4
          sub     R0,R0,#1
          b       delete
end_shift 
          mov     r1,#size
          ldr     r0,[r1]
          sub     r0,r0,#1
          str     r0,[r1]
          b       loop
fine_loop 

          end
