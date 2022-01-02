.data 0x10010000

	x: .word 
	
	
.text

li $t1,20
li $t2,0
loop:
    li $a1, 100  #Here you set $a1 to the max bound.
    li $v0, 42  #generates the random number.
    syscall
    sub $a0, $a0, 50  #Here you add the lowest bound
    sw $a0,x($t2)
    add $t2,$t2,4
    sub $t1,$t1,1
    bne $t1,$zero,loop 
    jal found_no		
j exit

found_no:
li $t1,20
li $t2,0
li $t3,0

li $v0,5
syscall 
move $t5,$a0

loop1:
    lw $t4,x($t2)
    add $t2,$t2,4
    bne $t5,$t4,jmp
    add $t3,$t3,1
    jmp:
    sub $t1,$t1,1
    bne $t1,$zero,loop1
    
 move $a0,$t3
 li $v0,1
 syscall
 jr $ra
 
 exit:
  