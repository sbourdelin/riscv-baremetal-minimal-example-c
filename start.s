.global _start

_start:
    csrr    t0, mhartid             # read current hart id
    bnez    t0, park                # single core only, park hart != 0

    la      sp, stack_top           # setup stack
    j       main                    # jump to c

park:
    wfi
    j       park
