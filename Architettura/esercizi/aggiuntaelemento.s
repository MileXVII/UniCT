size         dcd     9
array        dcd     4, 5, 8, 9, 10, 11, 14, 15, 20

             mov     r1, #size
             ldr     r0, [r1]
             mov     r1, #array
             mov     r2, #22 ;elemento da inserire

             lsl     r3, r0, #2 ;r3 9 << 2
             add     r1, r1, r3 ;r1 punta all'ultimo

loop         
             cmp     r0, #0
             blt     end_loop

             ldr     r3, [r1, #-4] ;dobbiamo scorrere al contrario quindi da 36 a diminuire e non da 0 ad aumentare
             cmp     r3, r2
             bgt     move_element ;se r3 è maggiore di r2 dobbiamo spostarlo a destra = |...||r3|r2| => |...||r2||r3|

             str     r2, [r1] ;se r3 non è maggiore inseriamo r2 nella posizione dopo = |...||r3||r2|
             b       end_program

move_element 
             str     r3, [r1] ;spostiamo r3 alla posizione successiva
             sub     r1, r1, #4 ;scorriamo l'array a sinistra = |...||r3||x| => |...||x||r3|
             sub     r0, r0, #1
             b       loop

end_loop     ;se     sono tutti maggiori di r2
             mov     r1, #array ;risettiamo r1
             str     r2, [r1] ;inseriamo r2 all'inizio |r2||...|

end_program  ;dopo   aver inserito r2
             mov     r1, #size ;risettiamo la lunghezza
             ldr     r0, [r1]
             add     r0, r0, #1 ;incrementiamo di 1 la lunghezza
             str     r0, [r1]
             end