.eqv BMP_FILE_SIZE 120054 # for 200*200  images
.eqv BYTES_PER_ROW 600

	.data
#space for the 600x50px 24-bits bmp image
.align 4
res:		.space 2
image:		.space BMP_FILE_SIZE
list:		.space 8160 #32 * 255
modeList:	.word 2, 8, 10, 12, 58, 63, 65, 69, 72, 75, 76, 91 # those are mode values of several pictures of steak, salam and cur.fist four is for cur then ste then sal
file_name:	.asciiz "C:/Users/AQ/Desktop/rsz_0059-01.bmp"
cur:	.asciiz "The Food type # 1 is entered i.e. currant"
sal:	.asciiz "The Food type # 2 is entered i.e. salami"
ste:	.asciiz "The Food type # 3 is entered i.e. steal"
new_line: 	.asciiz "\n"
list_size:	.word 255
mode_list_size:	.word 12
strErrOpenFile: .asciiz "Error opening the file. Are you sure that the name is correct?\n"
strErrReadFile: .asciiz "Error reading the file. Are you sure that it is a 200x200 bmp file? \n"


	.text
main:
	
	la $a0, file_name	#|read image
	jal read_bmp 		#| args: $a0 - file name
	li	$a0, 0		#|
	jal     get_pixel	#|cretae histogram
	# args:		$t1- list size , $t0 - list  , $t2-0, $t3 -0
	li $t4, 0		#|
	li $t3, 0		#|
	li $t2, 0		#|
	lw $t1, list_size	#|
	la $t0, list		#| find mode
	jal find_mode		# $t4 will be the used
	
	li $t3, 0
	li $t2, 0
	la $t0, modeList
	jal compare_image # args:		 $t0 - list, $t2- 0, $t3-0, $t4 0 
	
	sub $a0, $a0, $a0
	add $a0, $a0, $t2
	jal identify_image
	
	
	li $v0, 10	#|
	syscall 	#|end program

#__________________________________________________________________________	
read_bmp: # args: $a0 - file name
#reads the contents of a bmp file into memory
#no args, no return value
	sub $sp, $sp, 4		#push $ra to the stack
	sw $ra,4($sp)
	sub $sp, $sp, 4		#push $s1
	sw $s1, 4($sp)
	
#open file
       	#syscall for open the file
	li $v0, 13			
	la $a0, file_name
	li $a1, 0			# flags (0=read, 1=write)
	li $a2, 0			# mode = unnecessary
	syscall				# returns the descriptor (pointer) of the file in $v0
	move $s1,$v0			#save the file index in $s1
	beq $v0,-1, errOpenFile
#end openFile

#check for errors - if the file was opened
#...

#read file
	
	move $a0, $s1
	la $a1, image
	li $a2, BMP_FILE_SIZE
	li $v0, 14		#read from file
	syscall
	beq $v0, $zero, errReadFile

	la	$t0,image
	


	#loadSize: #Its important to know the size of the image for the apropriate
		#Load each byte of the field and dislocate to compose the full int number
		lb $t3, 34($t0)
		lb $t4, 35($t0)
		sll $t4, $t4, 8
		add $t3, $t3, $t4
		lb $t4, 36($t0)
		sll $t4, $t4, 16
		add $t3, $t3, $t4
		lb $t4, 37($t0)
		sll $t4, $t4, 24
		add $t3, $t3, $t4
#end loadSize
#checking bmp file whether it is  200x200 or not
		bne $t3,54208,errReadFile # 54208 is the size of 200x200 image

#		li	$v0,1
#		syscall 
#end readHeader

#close file
	li $v0, 16
	move $a0, $s1
        syscall
	
	lw $s1, 4($sp)		#restore (pop) $s1
	add $sp, $sp, 4
	lw $ra, 4($sp)		#restore (pop) $ra
	add $sp, $sp, 4
	jr $ra

# ============================================================================

get_pixel:
	sub $sp, $sp, 4		#push $ra to the stack
	sw $ra,4($sp)

	la $t1, image + 10	#adress of file offset to pixel array
	lw $t2, ($t1)		#file offset to pixel array in $t2
	
	li  $t5, BMP_FILE_SIZE
	sub $t5, $t5, $t2 	# |how many green values are there 
	div $t5, $t5, 3		# |how many green values are there 
		
	la $t1, image		#adress of bitmap
	add $t2, $t1, $t2	#adress of pixel array in $t2
	
#fill the array with green values
	add $t2, $t2, 1		 #first green 
	li $t3, 0		 # $t3 is the counter of loop
	li $t4, 0
loop_through_pixels:
	beq $t3, $t5, get_pixel_end
	la $t6, list      	# $t6 = array address
	
	mul $t4, $t3, 3		# $t4 = 3* $t3
	add $t4, $t2, $t4	# $t4 = $t4 + $t2
	lb $t1,($t4)		# load G 
	
	#save to array
	#sb $t1, ($t6)
	#add $t6, $t6, 4
	
	#inc array
	mul $t1, $t1, 4 #or 4
	add $t6, $t6, $t1
	lw $t7, ($t6)   
	addi $t7, $t7, 1
	sw  $t7, ($t6)
	
	add $t3, $t3, 1
	j loop_through_pixels 
	
	
get_pixel_end:												
	lw $ra, 4($sp)		#restore (pop) $ra
	add $sp, $sp, 4
	jr $ra

# ============================================================================


#____________________________________________________________________________________#

find_mode:# tis function finds the most occuring number from the array
# args:		$t1- list size , $t0 - list, $t2- 0, $t3-0, $t4 0
#t3 is for max value
#t4 for identify which one is mode 
	li $t4, 0
	li $t3, 0
	li $t2, 0
loop:
	beq $t2, 255, find_mode_done  # check for array end
	lw $a0, ($t0) 			# load the value of modelist is a0
	
	bge $a0, $t3, greater		#check whether the value is greater than other value
	
	add $t2, $t2, 1      # increment loop counter
	add $t0, $t0, 4      # increment array pointer
	b loop               # repeat the loop
greater:
	li $t4, 0		#|
	add $t4, $t4, $t2	#| t4 = t2 
	
	li $t3,0		#|
	add $t3, $a0, $t3 	#| t3 = a0
	
	add $t2, $t2, 1      # advance loop counter
	add $t0, $t0, 4      # advance array pointer
	j loop
	
find_mode_done: 	
	jr $ra
#____________________________________________________________________________________#
compare_image: # args:	, $t0 - list, $t2- 0, $t3-0, $t4 0 #return t2
la $a1, mode_list_size
lw $a2, ($a1)
compare_loop:
	beq $t2, $a2, compare_image_done  # check for array end
	lw $a0, ($t0) 
	bge $a0, $t4, compare_image_done
	
	add $t2, $t2, 1      # increment loop counter
	add $t0, $t0, 4      # increment array pointer
	b compare_loop               # repeat the loop

compare_image_done:
	 	
	jr $ra
#____________________________________________________________________________________#

identify_image: #a0- value
	sub $sp, $sp, 4		#push $ra to the stack
	sw $ra,4($sp)

#indetify_loop is function to identify the type of food, if the mode value is from 3-6 it print currant, if the mode value is from 7-10 it print steal, if the mode value is from 11 to onwards it print salami
indentify_loop:
	li $t0, 3
	bge $t0, $a0, print_cur
	li $t0, 7
	bge $t0, $a0, print_ste
	li $t0, 11
	bge $t0, $a0, print_sal
	
print_cur:
	la $a0, cur
	li $v0, 4
	syscall
	b identify_image_exit
	
print_ste:
	la $a0, ste
	li $v0, 4
	syscall
	j identify_image_exit

print_sal:
	la $a0, sal
	li $v0, 4
	syscall
	b identify_image_exit

errOpenFile:
	#If the file does not exists this function will be triggered
	la $a0, strErrOpenFile
	jal printStr
	jal identify_image_exit
#end errOpenFile

errReadFile:
	#If the file information does not come out as it should, this function will be triggered
	la $a0, strErrReadFile
	jal printStr
	jal identify_image_exit
#end errReadFile

printStr:
	li $v0, 4
	syscall
	jr $ra
#end printStr
	
identify_image_exit:
	lw $ra, 4($sp)		#restore (pop) $ra
	add $sp, $sp, 4

	li $v0, 10
	syscall
#	jr $ra

#____________________________________________________________________________________#
