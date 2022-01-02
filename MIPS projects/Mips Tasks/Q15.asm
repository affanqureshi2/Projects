.data 0x10010000
	
	stat: .asciiz "Enter two numbers and I'll show you the sum, difference, product, qoutient and remainder"
	fno: .asciiz "First Number: "  
	sno: .asciiz "Second Number: "
	n_line: .asciiz "\n"	
	sum: .asciiz " + "
	dif: .asciiz " - "
	pro: .asciiz " * "
	qou: .asciiz " / "
	equ: .asciiz " = "
	rdr: .asciiz " R "
	
	
.text

la $a0,stat
li $v0,4
syscall 

la $a0,n_line
li $v0,4
syscall

la $a0,fno
li $v0,4
syscall

li $v0,5
syscall
move $s1,$v0

la $a0,n_line
li $v0,4
syscall

la $a0,sno
li $v0,4
syscall 

li $v0,5
syscall
move $s2,$v0

la $a0,n_line
li $v0,4
syscall

add $t1,$s1,$s2
sub $t2,$s1,$s2
mul  $t3,$s1,$s2
div $t4,$s1,$s2
rem $t5,$s1,$s2

la $a0,n_line
li $v0,4
syscall

move $a0,$s1
li $v0,1
syscall

la $a0,sum
li $v0,4
syscall

move $a0,$s2
li $v0,1
syscall

la $a0,equ
li $v0,4
syscall

move $a0,$t1
li $v0,1
syscall

la $a0,n_line
li $v0,4
syscall

move $a0,$s1
li $v0,1
syscall

la $a0,dif
li $v0,4
syscall

move $a0,$s2
li $v0,1
syscall

la $a0,equ
li $v0,4
syscall

move $a0,$t2
li $v0,1
syscall

la $a0,n_line
li $v0,4
syscall

move $a0,$s1
li $v0,1
syscall

la $a0,pro
li $v0,4
syscall

move $a0,$s2
li $v0,1
syscall

la $a0,equ
li $v0,4
syscall

move $a0,$t3
li $v0,1
syscall

la $a0,n_line
li $v0,4
syscall

move $a0,$s1
li $v0,1
syscall

la $a0,qou
li $v0,4
syscall

move $a0,$s2
li $v0,1
syscall

la $a0,equ
li $v0,4
syscall

move $a0,$t4
li $v0,1
syscall

la $a0,rdr
li $v0,4
syscall

move $a0,$t5
li $v0,1
syscall
