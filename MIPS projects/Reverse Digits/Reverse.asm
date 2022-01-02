addi $t0, $zero, 8200 # Output loc 
addi	$t3,$zero,10
BegLoop:    
addi $t6, $zero, 8192 # Input ready?    
lw $t5, 0($t6)    
beq $t5, $zero, NoInput       
addi $t6, $zero, 8196 # Input loc       
lw $t1, 0($t6)       
addi	$t5,$zero,1


jal rev

sw $t2, 0($t0) # Output to screen      

j BegLoop 

rev:
addi $t4,$t4,0
divide:
addi $t4,$t4,1
sub $t1,$t1,$t3
slt  $t6,$t1,$t5
bne $t6,$t5,divide
sub $t4,$t4,$t5
add $t1,$t1,$t3
#div	$t1,$t1,$t3	# v1 /=  10; divide integer variable by 10 for eliminating left most digit e.g 123 / 10 = 12 
#mfhi	$t4		# modulus of number by 10 for taking left most number e.g 123 mod 10 = 3
mul	$t2,$t2,$t3	#out *= 10;  ,  multiply output by 10
add	$t2,$t2,$t4	#out += temp; , add left most digit of previous sequence of number
beq 	$t1,$zero,exit	# while(v1 != 0), when v1 == null loop break
j rev

exit:
jr	$ra

NoInput:
