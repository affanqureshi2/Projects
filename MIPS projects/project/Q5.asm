.data 0x10010000

	x: .word 20
	newline: .asciiz "\n"
	out2: .asciiz "The largest number: "	
	
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

#Algorithm for finding biggest word
main: 
	la $s4, x			# We assign $s4 to arrayA address
	
	addi $s0, $zero, 0		# int max = 0;
	addi $s1, $zero, 0		# int maxIndex = 0; 
	addi $s2, $zero, 0		# int i = 0; 
	
	STARTLOOP:
	addi $s3, $s2, -12
	bgez $s3, ENDLOOP		# Ends the loop if/when i >= 12
	
	add $s5, $s2, $s2		# 2x index
	add $s5, $s5, $s5		# 4x index, every 4 bytes is the next value in arrayA
	add $s6, $s4, $s5		# computes the array indexing correctly
	
	lw $s7, 0($s6)			# load word of index i of arrayA
	
	slt $t1, $s0, $s7			# does comparison of $s7 > $s0 
	move $t2, $s2
	addi $s2, $s2, 1			# increments i by 1
	beq $t1, $zero, STARTLOOP	# if $s7 < $s0 then, go back to start of the loop
	
	move $s0, $s7			# else then, set $s0 = $s7 & set $s1 = $s2
	move $s1, $t2			
	
	j STARTLOOP
ENDLOOP:

# Print a single newline
	
	la $a0, newline		# Load address of newline 
	li $v0, 4			# Load I/O code to print string to console
	syscall 

	# Print out the largest value
	
	la $a0, out2		# Load address of out2 into register $a0
	li $v0, 4			# Load I/O code to print string to console
	syscall				# print string

	li $v0, 1			# an I/O sequence to write an integer from the console window
	move $a0, $s0		# $s0 is the register holding the largest number
syscall 

