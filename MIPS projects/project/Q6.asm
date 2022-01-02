.data 0x10010000

	x: .word 20
	
	
.text
# Random numbers start from address 0x10010000, so you can see and on that address
li $t1,20
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
 
#Algorithm for finding smallest word

li $t1,20
li $t2,0
li $t3,150

loop1:
    lw $a0,x($t2)
    add $t2,$t2,4
    blt $t3,$a0,j1
    move $t3,$a0
    j1:
    sub $t1,$t1,1
    bne $t1,$zero,loop1 
    move $a0,$t3
    li $v0, 1   #1 print integer
    syscall
    