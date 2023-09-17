.globl factorial

.data
n: .word 8

.text
main:
    la t0, n
    lw a0, 0(t0)
    jal ra, factorial

    addi a1, a0, 0
    addi a0, x0, 1
    ecall # Print Result

    addi a1, x0, '\n'
    addi a0, x0, 11
    ecall # Print newline

    addi a0, x0, 10
    ecall # Exit

factorial:
    # YOUR CODE HERE
    #Prologue
    addi sp, sp, -8
    sw s0, 0(sp) # store the total amount
    sw s1, 4(sp) # store the current number

    li s0, 1 # amount initialized as 1
    mv s1, a0 # current number initialized as a0 (the initial value)
    li t1, 1 # constant used for loop condition check

loop_start:
    beq s1, t1, loop_end # goto loop_end if counter == 0
    mul s0, s0, s1
    addi s1, s1, -1
    j loop_start

loop_end:
    mv a0, s0

    #Epilogue
    lw s0,0(sp)
    lw s1,4(sp)
    addi sp, sp, 8

    ret
