.data 0x10010000

	x: .byte 20
	
	
.text

# Random numbers start from address 0x10010000, so you can see and on that address

li $t1,4
li $t2,0
loop:
    li $a1, 1000000  #Here you set $a1 to the max bound.
    li $v0, 42  #generates the random number.
    syscall
    add $a0, $a0, 50  #Here you add the lowest bound
    sw $a0,x($t2)
    add $t2,$t2,4
    sub $t1,$t1,1
    bne $t1,$zero,loop 
#Algorithm to sum each two adjacentbytes in a block and place the resultin the cell with the low address
li $t1,4
li $t2,0
loop1:
    lb $t3,x($t2)
    lb $t4,x+2($t2)
    add $t3,$t3,$t4
    sb $t3,x($t2)
    add $t2,$t2,4
    sub $t1,$t1,1
    bne $t1,$zero,loop1 

