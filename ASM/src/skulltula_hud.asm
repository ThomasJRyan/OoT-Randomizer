skulltula_draw_count:
    addiu   sp, sp, -0x10
    sw      ra, 0(sp)
    jal     draw_skulltula_count
    nop
    lw      t6, 0x1C44(s6)
    lui     t8, 0xDB06
    lw      ra, 0(sp)
    jr      ra
    addiu   sp,sp, 0x10