.file "sum.s"

.section 	.rodata.str1.1,"aMS",@progbits,1
PR_1:
	.string "\nSize of the array: %i\n"
Result:
	.string "\nThe sum is: %i"
	
PInt:
	.string "%i "
	
.data
	.align 8
array:
	.quad 1
	.quad 2
	.quad 3
	.quad 4
	.quad 5
	.quad 6
	.quad 7
	.quad 8
	.quad 9
	.quad 10

.globl sum
	.type	sum, @function
.text
sum:
	pushq %rbp			# stack frame management
	movq %rsp, %rbp			# stack frame management
	
	movq $PR_1, %rdi		# print out size of array
	movq $10, %rsi
	movq $0, %rax
	call printf
	
	movq $0, %rax			# Initialize sum and index to 0
	movq $0, %rdi
	
sum_loop:
	cmpq $10, %rdi			# check if end of array and jump to end
	je sum_end
	
	movq array(,%rdi,8), %rcx	# add each index into %rax sum register
	addq %rcx, %rax
	
	incq %rdi			# increment i and repeat loop
	jmp sum_loop

sum_end:
	movq $Result, %rdi		# print out sum
	movq %rax, %rsi
	movq $PInt, %rdx
	movq $0, %rax
	call printf

	popq %rbp			# return to main
	ret
.size sum,.-sum
