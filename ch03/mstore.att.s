	.file	"mstore.c"
	.text
	.globl	multstore
	.type	multstore, @function
multstore:
.LFB0:
	.cfi_startproc
	pushq	%rbx  ;save %rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rdx, %rbx	;copy dest to %rbx
	call	mult2@PLT	;call mult2(x, y)
	movq	%rax, (%rbx)	;store result at *dest
	popq	%rbx	;restore %rbx
	.cfi_def_cfa_offset 8
	ret	;return
	.cfi_endproc
.LFE0:
	.size	multstore, .-multstore
	.ident	"GCC: (GNU) 9.2.0"
	.section	.note.GNU-stack,"",@progbits
