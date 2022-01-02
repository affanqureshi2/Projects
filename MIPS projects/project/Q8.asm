.data 0x10010000

	x: .word 20
	
	
.text

# Random numbers start from address 0x10010000, so you can see and on that address

li $t1,4
li $t2,0
loop:
    li $a1, 100  #Here you set $a1 to the max bound.
    li $v0, 42  #generates the random number.
    syscall
    add $a0, $a0, 50  #Here you add the lowest bound
    sw $a0,x($t2)
    add $t2,$t2,4
    sub $t1,$t1,1
    bne $t1,$zero,loop 

#Algorithm for replacing two halves of each word in a data block.
li $t1,4
li $t2,0
loop1:
    lb $t3,x($t2)
    lb $t4,x+2($t2)
    sb $t3,x+2($t2)
    sb $t4,x($t2)
    add $t2,$t2,4
    sub $t1,$t1,1
    bne $t1,$zero,loop1 

