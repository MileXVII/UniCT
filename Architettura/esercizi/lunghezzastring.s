s1         dcb     66,62,61,0
s2         dcb     68,66,64,64,68,68,60,0

           mov     r1, #s1
           mov     r2, #s2
           mov     r8, #0
           mov     r9, #0
loop       
           ldrb    r3, [r1]
           ldrb    r4, [r2]
           sub     r0, r3, r4
           cmp     r3, #0
           bne     counts1
           cmp     r4, #0
           bne     counts2
           mov     r0, #0
           b       end_loop
counts1    
           add     r8, r8, #1
           add     r1, r1, #1
           b       loop
counts2    
           add     r9, r9, #1
           add     r2, r2, #1
           b       loop
end_loop   
           cmp     r8, r9
           bgt     s1maggiore
           mov     r8, #0
           mov     r9, #1
           b       fine
s1maggiore 
           mov     r8, #1
           mov     r9, #0
           b       fine
fine       
           end

