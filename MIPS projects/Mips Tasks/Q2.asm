	
.text
.globl main

main:
	jal Q1

exit:

    li $v0, 10
    syscall
    

Q1:
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
	
.data 0x10020000

	x: .word 20
    	
jr $ra