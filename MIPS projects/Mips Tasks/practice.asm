.data
space: .asciiz " "
x: .word 
N: .word 20						#number of elements

.text

.globl main


main:   
	jal Q1
	la $a0, x       #$a0=load address of array X
    	lw $a1, N       #$a1=10  --number elements
    	
    	li $t2, 0	#max = 0
    	li $t3, 100	#min = 100
    	
    	jal readArray  #call readArray
    	li $v0, 10      #exit program   
    	syscall 
    	
    	
readArray:
    li $t0, 0       		#counter = 0
    li $t1, 0       		#location of array = 0
    
loop1:    bge $t0, $a1, final 	#if  $t0 >= $a1 then goto final
    lw $a0, x($t1) 		#$a0 = X(i)
    
    blt $a0, $t3, new_min	#if X(i) < min
    j check_max
    new_min: move $t3, $a0		#min = X(i)
    j update_counter
    
    check_max:
    bgt $a0, $t2, new_max	#if X(i) > max
    j update_counter
    
    new_max: move $t2, $a0		#max = X(i)
    
    update_counter:
    addi $t1, $t1, 4    	#Every 4 bytes there is an integer in the array
    addi $t0, $t0, 1    	#counter ++
    b loop1       		#goto loop
final:  
	
	li $v0, 1		#integer print
	move $a0, $t3		#load the min to be printed
	syscall			#execute the print
	
	la $a0, space   	#load a space:  " "
    	li $v0, 4       	#print string               
    	syscall
    	jr $ra      		#return
    	j exit	
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
    sub $t1,$t1,1
    bne $t1,$zero,loop 
   jr $ra 

exit: