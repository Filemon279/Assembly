.ORG 0x0000            
 
               
rjmp START             
START:
	ldi r18, 0x03
	ldi r17, 0xff
	sts 0x25, r17        ; 0x24 PortB Data Direction Register
	ldi r17, 0b00001001
	sts 0x24, r17
                       
LOOP:
	rcall WAIT5SEC       ; wait for half a second
	lsl r17;			; Shift left
	sts 0x24, r17        
	dec r18				;Dec 1 from r18
	breq RESET_COUNT	;If we done 3 steps reste count and start all over again 
	rjmp LOOP

WAIT5SEC:              
	ldi r16, 31   
	      
OUTER_LOOP:           
	ldi r24, low(1021)   
	ldi r25, high(1021)  

DELAY_LOOP:                    
	adiw r24, 1 ;Add Immediate to Word        					
	brne DELAY_LOOP ;Branch if Not Equal
	dec r16         
	brne OUTER_LOOP 
	ret

RESET_COUNT:
	ldi r17, 0b00001001
	sts 0x24, r17
	ldi r18, 0x03
	rjmp LOOP
