.data
		x: .word 4
.text
addi $t0, $zero, 8200 # Output loc 
addi	$t3,$zero,10
li $t6,0
li $t9,123    

#BegLoop:
sw $t9,x($t6)
#addi $t6, $zero, x # Input ready?    
#lw $t5, 0($t6)    
#beq $t5, $zero, NoInput       
lw $t1, x($t6)       
#jal rev

#j BegLoop 

rev:
div	$t1,$t1,$t3	# v1 /=  10; divide integer variable by 10 for eliminating left most digit e.g 123 / 10 = 12 
mfhi	$t4		# modulus of number by 10 for taking left most number e.g 123 mod 10 = 3
mul	$t2,$t2,$t3	#out *= 10;  ,  multiply output by 10
add	$t2,$t2,$t4	#out += temp; , add left most digit of previous sequence of number
beq 	$t1,$zero,exit	# while(v1 != 0), when v1 == null loop break
j rev

exit:
#jr	$ra

sw $t2, x($t6) # Output to screen      

NoInput:
