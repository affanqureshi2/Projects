.data
	prompt1: .asciiz "Enter the 1st number: "
	prompt2: .asciiz "Enter the 2nd number: "
	prompt3: .asciiz "Enter the 3rd number: "
	prompt4: .asciiz "Sum of three numbers: "
	prompt5: .asciiz "Product of three numbers: "
	prompt6: .asciiz "Maximum of 1st two numbers: "
	prompt7: .asciiz "Unbiased exp of 1st number: "
	prompt8: .asciiz "Biased exp of 1st number: "
	prompt9: .asciiz "Full Significand of 1st number: "
	two: .float 2.0
	n_line: .asciiz "\n"
.text
	
	li $v0,4
	la $a0,prompt1
	syscall
	
	li $v0,6
	syscall
	mov.s $f1,$f0
	
	la $a0,n_line
	li $v0,4
	syscall
	
	li $v0,4
	la $a0,prompt2
	syscall
	
	li $v0,6
	syscall
	mov.s $f2,$f0
	
	la $a0,n_line
	li $v0,4
	syscall
	
	li $v0,4
	la $a0,prompt3
	syscall
	
	li $v0,6
	syscall
	mov.s $f3,$f0
			
	la $a0,n_line
	li $v0,4
	syscall
	
	#----
	#Unbiased Exp:
	move $s1,$zero
	mov.s $f7,$f1
	lwc1 $f8,two
	
	bin:
	div.s $f7,$f7, $f8
	add $s1,$s1,1
	c.lt.s $f7,$f8
	bc1f bin
	c.lt.s $f8,$f7
	li $v0,4
	la $a0,prompt7
	syscall
	
	li $v0,1
	move $a0,$s1
	syscall 
	
	la $a0,n_line
	li $v0,4
	syscall
	
	#Biased Exp:
	li $v0,4
	la $a0,prompt8
	syscall
	
	add $s1,$s1,7
	li $v0,1
	move $a0,$s1
	syscall 
	
	la $a0,n_line
	li $v0,4
	syscall
	
	#Full Significand
	sub $s1,$s1,7
	Significand:
	mul.s $f7,$f7, $f8
	sub $s1,$s1,1
	bnez $s1,Significand
	
	cvt.w.s $f7,$f7
	mfc1 $t1,$f7
	
	li $v0,4
	la $a0,prompt9
	syscall
	
	li $v0,1
	move $a0,$t1
	syscall 
	
	la $a0,n_line
	li $v0,4
	syscall
	# Max Number
	movf.s $f6,$f1

	c.lt.s $f2, $f6			# does comparison of $s7 > $s0 
	bc1t l1		
	movf.s $f6, $f2			# else then, set $s0 = $s7 & set $s1 = $s2
	
	l1:
	c.lt.s $f6, $f2				
	li $v0,4
	la $a0,prompt6
	syscall
	
	li $v0,2
	movf.s $f12,$f6
	syscall 
		
	la $a0,n_line
	li $v0,4
	syscall
	
	#----
	#Addition of numbers
	jal a3fp
	li $v0,4
	la $a0,prompt4
	syscall
	
	li $v0,2
	movf.s $f12,$f4
	syscall 
		
	la $a0,n_line
	li $v0,4
	syscall
	
	#Multiplication of numbers
	jal m3fp
	li $v0,4
	la $a0,prompt5
	syscall

	li $v0,2
	movf.s $f12,$f5
	syscall 
	
	la $a0,n_line
	li $v0,4
	syscall
	
	li $v0,10
	syscall

a3fp:
	
	add.s $f7,$f2,$f1
	add.s $f4,$f3,$f7
	
	jr $ra
	
m3fp:
	
	mul.s $f7,$f2,$f1
	mul.s $f5,$f3,$f7
	
	jr $ra
