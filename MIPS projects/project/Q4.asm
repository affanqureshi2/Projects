.data 0x10010000

	x: .word 

.data 0x10010060 # I know 20 is in hex, it should be in decimal but there must be space to distinguish
    	y: .word 	

.text
.globl main

main:
#putting the data in datablock 1 
	jal D1
#putting the data in datablock 2
	jal D2

	li $t1,20
	li $t2,0
#Substituting the value between them
loop1:
    lw $a0,x($t2)
    lw $t3,y($t2)
    sw $a0,y($t2)
    sw $t3,x($t2)
    add $t2,$t2,4
    sub $t1,$t1,1
    bne $t1,$zero,loop1 
		
exit:

    li $v0, 10
    syscall
    

D1:
li $t1,20
li $t2,0
loop:
    li $a1, 100  #Here you set $a1 to the max bound.
    li $v0, 42  #generates the random number.
    syscall
    add $a0, $a0, 50  #Here you add the lowest bound
    sw $a0,x($t2)
    add $t2,$t2,4
    li $v0, 1   #1 print integer
    syscall
    sub $t1,$t1,1
    bne $t1,$zero,loop 
	jr $ra	
	
D2:
li $t1,20
li $t2,0
loop2:
    li $a1, 100  #Here you set $a1 to the max bound.
    li $v0, 42  #generates the random number.
    syscall
    add $a0, $a0, 50  #Here you add the lowest bound
    sw $a0,y($t2)
    add $t2,$t2,4
    li $v0, 1   #1 print integer
    syscall
    sub $t1,$t1,1
    bne $t1,$zero,loop2
	jr $ra	
	
