# address 0x10020000 is not display in mars, so you can change this address to 0x10010000 to check the results

.data 0x10020000

	x: .word 20
	n_line: .asciiz "\n"
	comma: .asciiz ", "  	
	g: .asciiz "Generation of random numbers:"
.text

la $a0,g
li $v0,4
syscall

la $a0,n_line
    li $v0,4
    syscall

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
    
    la $a0,comma
    li $v0,4
    syscall

    sub $t1,$t1,1
    bne $t1,$zero,loop 