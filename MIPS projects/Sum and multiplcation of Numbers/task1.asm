.data
	num1: .float 5.43
	num2: .float 7.82
	num3: .float 3.61
.text

	lwc1 $f1,num1
	lwc1 $f2,num2
	lwc1 $f3,num3
	jal a3fp
	li $v0,2
	movf.s $f12,$f4
	syscall 
	li $v0,10
	syscall

a3fp:
	
	add.s $f2,$f2,$f1
	add.s $f4,$f3,$f2

	jr $ra