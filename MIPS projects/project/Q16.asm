.data

newline: .asciiz "\n"
#Give the address where file which is to be read is placed. Note that format of address must be like following i.e. / instead of \
fileName: .asciiz "C:/Users/AQ/Desktop/35$/Allice.txt"

#Give the address where file which is to be write is placed. Note that format of address must be like following i.e. / instead of \

fileName2: .asciiz "C:/Users/AQ/Desktop/35$/AlliceU.txt"
fileWords: .space 2048

.text
main:
    jal ReadFile
    jal Replace
there:
    jal WriteFile
    
	

exit:
    li $v0, 4
    la $a0, fileWords
    syscall

    li $v0, 10
    syscall
    
 ReadFile:
	#HOW TO READ INTO A FILE
	
	li $v0,13           	# open_file syscall code = 13
    	la $a0,fileName     	# get the file name
    	li $a1,0           	# file flag = read (0)
    	syscall
    	move $s0,$v0        	# save the file descriptor. $s0 = file
	
	#read the file
	li $v0, 14		# read_file syscall code = 14
	move $a0,$s0		# file descriptor
	la $a1,fileWords  	# The buffer that holds the string of the WHOLE file
	la $a2,2048		# hardcoded buffer length
	syscall

# print whats in the file
	li $v0, 4		# read_string syscall code = 4
	la $a0,fileWords
	syscall
#Close the file
    	li $v0, 16         		# close_file syscall code
    	move $a0,$s0      		# file descriptor to close
    	syscall
    	jr $ra

WriteFile:
	#open file 
    	li $v0,13           	# open_file syscall code = 13
    	la $a0,fileName2     	# get the file name
    	li $a1,1           	# file flag = write (1)
    	syscall
    	move $s1,$v0        	# save the file descriptor. $s0 = file
    	
    	#Write the file
    	li $v0,15		# write_file syscall code = 15
    	move $a0,$s1		# file descriptor
   	la $a1,fileWords	# the string that will be written
    	la $a2,2048		# length of the toWrite string
    	syscall
    	
	#MUST CLOSE FILE IN ORDER TO UPDATE THE FILE
    	li $v0,16         		# close_file syscall code
    	move $a0,$s1      		# file descriptor to close
    	syscall
    	jr $ra
    	
 Replace:
     li $v0, 4
    li $t0, 0

loop:
    lb $t1, fileWords($t0)
    beq $t1, 0, there
    blt $t1, 'a', case
    bgt $t1, 'z', case
    sub $t1, $t1, 32
    sb $t1, fileWords($t0)

case: 
    addi $t0, $t0, 1
    j loop
    jr $ra