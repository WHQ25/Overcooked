#define __SFR_OFFSET 0 
#include <avr/io.h> 
#include <stdint.h>

void output_grb(uint8_t *data, uint16_t count) {
    inline asm {
        .equ      OUTBIT,   0
        .global output_grb
        output_grb:
            movw   r26, r24      
            movw   r24, r22      
            in     r22, SREG     
            cli                  
            in     r20, PORTB
            ori    r20, (1<<OUTBIT)        
            in     r21, PORTB
            andi   r21, ~(1<<OUTBIT)        
            ldi    r19, 7        
            ld     r18,X+        
        loop1:
            out    PORTB, r20    
            lsl    r18           
            brcs   L1            
            out    PORTB, r21   
            nop                  
            bst    r18, 7        
            subi   r19, 1        
            breq   bit8          
            rjmp   loop1         
        L1:
            nop                  
            bst    r18, 7        
            subi   r19, 1        
            out    PORTB, r21    
            brne   loop1         
        bit8:
            ldi    r19, 7        
            out    PORTB, r20    
            brts   L2            
            nop                  
            out    PORTB, r21    
            ld     r18, X+       
            sbiw   r24, 1        
            brne   loop1         
            out    SREG, r22     
            ret
        L2:
            ld     r18, X+       
            sbiw   r24, 1        
            out     PORTB, r21   
            brne   loop1         
            out    SREG, r22     
            ret
    }
}



