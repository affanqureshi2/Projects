.data

str: .asciiz  "Enter five values for finding gcd :"
n_line: .asciiz "\n"	
	
gcdtxt: .asciiz  "Greatest common divisor is: "

x: .word 5

.text

.globl main

#Part B
main:

la $a0,str
li $v0,4
syscall 

la $a0,n_line
li $v0,4
syscall 

li $t7,0

li $v0,5
syscall
sw $v0,x($t7)

la $a0,n_line
li $v0,4
syscall 

add $t7,$t7,4
li $v0,5
syscall
sw $v0,x($t7)

la $a0,n_line
li $v0,4
syscall 

add $t7,$t7,4
li $v0,5
syscall
sw $v0,x($t7)

la $a0,n_line
li $v0,4
syscall 

add $t7,$t7,4
li $v0,5
syscall
sw $v0,x($t7)

la $a0,n_line
li $v0,4
syscall 

add $t7,$t7,4
li $v0,5
syscall
sw $v0,x($t7)

la $a0,n_line
li $v0,4
syscall 

lw $t1,x

li $t7,4
li $s1,5
loop1:
lw $t2,x($t7)
#li $t1,-40
#li $t2,-30
bgt $t1,$t2,label
move $t3,$t1
move $t1,$t2
move $t2,$t3

label:

jal gcd
add $t7,$t7,4
sub $s1,$s1,1
bgt $s1,$zero,loop1


la $a0,gcdtxt
li $v0,4
syscall 

move $a0,$t1
li $v0,1
syscall

b exit
#Part A
gcd:
	blt $t1,$zero,l1
	b l3
	l1:
		neg $t1,$t1

	l3:
		blt $t2,$zero,l2
		b loop
	l2:
		neg $t2,$t2

	loop:
		rem $t3,$t1,$t2
		move $t1,$t2
		move $t2,$t3
		bgt $t2,$zero,loop
	
	jr	$ra


exit:
