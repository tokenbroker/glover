SECTIONS
{
    HIDDEN(__romPos = 0);
    header_ROM_START = __romPos;
    header_VRAM = ADDR(.header);
    .header : AT(header_ROM_START)
    {
        FILL(0x00000000);
        header_DATA_START = .;
        build/asm/header.o(.data);
        header_DATA_END = .;
        header_DATA_SIZE = ABSOLUTE(header_DATA_END - header_DATA_START);
    }
    __romPos += SIZEOF(.header);
    header_ROM_END = __romPos;
    header_VRAM_END = .;

    ipl3_ROM_START = __romPos;
    ipl3_VRAM = ADDR(.ipl3);
    .ipl3 : AT(ipl3_ROM_START)
    {
        FILL(0x00000000);
        ipl3_DATA_START = .;
        build/assets/ipl3.o(.data);
        ipl3_DATA_END = .;
        ipl3_DATA_SIZE = ABSOLUTE(ipl3_DATA_END - ipl3_DATA_START);
    }
    __romPos += SIZEOF(.ipl3);
    ipl3_ROM_END = __romPos;
    ipl3_VRAM_END = .;

    entry_ROM_START = __romPos;
    entry_VRAM = ADDR(.entry);
    .entry 0x80100000 : AT(entry_ROM_START)
    {
        FILL(0x00000000);
        entry_TEXT_START = .;
        build/asm/1000.o(.text);
        entry_TEXT_END = .;
        entry_TEXT_SIZE = ABSOLUTE(entry_TEXT_END - entry_TEXT_START);
        entry_RODATA_START = .;
        build/asm/1000.o(.rodata);
        entry_RODATA_END = .;
        entry_RODATA_SIZE = ABSOLUTE(entry_RODATA_END - entry_RODATA_START);
        entry_DATA_START = .;
        build/asm/1000.o(.data);
        entry_DATA_END = .;
        entry_DATA_SIZE = ABSOLUTE(entry_DATA_END - entry_DATA_START);
    }
    entry_bss_VRAM = ADDR(.entry_bss);
    .entry_bss (NOLOAD) :
    {
        FILL(0x00000000);
        entry_BSS_START = .;
        build/asm/1000.o(.bss);
        entry_BSS_END = .;
        entry_BSS_SIZE = ABSOLUTE(entry_BSS_END - entry_BSS_START);
    }
    __romPos += SIZEOF(.entry);
    __romPos = ALIGN(__romPos, 16);
    entry_ROM_END = __romPos;
    entry_VRAM_END = .;

    main_ROM_START = __romPos;
    main_VRAM = ADDR(.main);
    .main entry_VRAM_END : AT(main_ROM_START)
    {
        FILL(0x00000000);
        main_TEXT_START = .;
        build/link/src/D910.o(.text);
        build/asm/E860.o(.text);
        build/link/src/D910_F0D0.o(.text);
        main_TEXT_END = .;
        main_TEXT_SIZE = ABSOLUTE(main_TEXT_END - main_TEXT_START);
        main_RODATA_START = .;
        build/asm/E860.o(.rodata);
        main_RODATA_END = .;
        main_RODATA_SIZE = ABSOLUTE(main_RODATA_END - main_RODATA_START);
        main_DATA_START = .;
        build/link/src/D910.o(.data);
        build/asm/E860.o(.data);
        build/link/src/D910_F0D0.o(.data);
        main_DATA_END = .;
        main_DATA_SIZE = ABSOLUTE(main_DATA_END - main_DATA_START);
    }
    main_bss_VRAM = ADDR(.main_bss);
    .main_bss (NOLOAD) :
    {
        FILL(0x00000000);
        main_BSS_START = .;
        build/link/src/D910.o(.bss);
        build/asm/E860.o(.bss);
        build/link/src/D910_F0D0.o(.bss);
        main_BSS_END = .;
        main_BSS_SIZE = ABSOLUTE(main_BSS_END - main_BSS_START);
    }
    __romPos += SIZEOF(.main);
    __romPos = ALIGN(__romPos, 16);
    main_ROM_END = __romPos;
    main_VRAM_END = .;

    game_start_ROM_START = __romPos;
    game_start_VRAM = ADDR(.game_start);
    .game_start 0x80117020 : AT(game_start_ROM_START)
    {
        FILL(0x00000000);
        game_start_TEXT_START = .;
        build/link/src/18020.o(.text);
        game_start_TEXT_END = .;
        game_start_TEXT_SIZE = ABSOLUTE(game_start_TEXT_END - game_start_TEXT_START);
        game_start_RODATA_START = .;
        game_start_RODATA_END = .;
        game_start_RODATA_SIZE = ABSOLUTE(game_start_RODATA_END - game_start_RODATA_START);
        game_start_DATA_START = .;
        build/link/src/18020.o(.data);
        game_start_DATA_END = .;
        game_start_DATA_SIZE = ABSOLUTE(game_start_DATA_END - game_start_DATA_START);
    }
    game_start_bss_VRAM = ADDR(.game_start_bss);
    .game_start_bss (NOLOAD) :
    {
        FILL(0x00000000);
        game_start_BSS_START = .;
        build/link/src/18020.o(.bss);
        game_start_BSS_END = .;
        game_start_BSS_SIZE = ABSOLUTE(game_start_BSS_END - game_start_BSS_START);
    }
    __romPos += SIZEOF(.game_start);
    __romPos = ALIGN(__romPos, 16);
    game_start_ROM_END = __romPos;
    game_start_VRAM_END = .;

    rspboot_ROM_START = __romPos;
    rspboot_VRAM = ADDR(.rspboot);
    .rspboot 0x8011C720 : AT(rspboot_ROM_START)
    {
        FILL(0x00000000);
        rspboot_DATA_START = .;
        build/assets/rspboot.o(.data);
        rspboot_DATA_END = .;
        rspboot_DATA_SIZE = ABSOLUTE(rspboot_DATA_END - rspboot_DATA_START);
    }
    __romPos += SIZEOF(.rspboot);
    rspboot_ROM_END = __romPos;
    rspboot_VRAM_END = .;

    game_ROM_START = __romPos;
    game_VRAM = ADDR(.game);
    .game 0x8011C7F0 : AT(game_ROM_START)
    {
        FILL(0x00000000);
        game_TEXT_START = .;
        build/link/src/18020_1D7F0.o(.text);
        build/link/src/18020_2D2B0.o(.text);
        build/link/src/18020_2D5E0.o(.text);
        build/link/src/18020_33940.o(.text);
        build/link/src/18020_34900.o(.text);
        build/link/src/18020_34E60.o(.text);
        build/link/src/18020_376E8.o(.text);
        build/link/src/18020_3A90C.o(.text);
        build/link/src/18020_3AC40.o(.text);
        build/link/src/18020_3AD70.o(.text);
        build/link/src/18020_435D0.o(.text);
        build/link/src/18020_46680.o(.text);
        build/link/src/18020_479E4.o(.text);
        build/link/src/18020_47B98.o(.text);
        build/link/src/18020_48000.o(.text);
        build/link/src/18020_50400.o(.text);
        build/link/src/18020_56B90.o(.text);
        build/link/src/18020_80200.o(.text);
        build/link/src/18020_812E0.o(.text);
        game_TEXT_END = .;
        game_TEXT_SIZE = ABSOLUTE(game_TEXT_END - game_TEXT_START);
        game_RODATA_START = .;
        game_RODATA_END = .;
        game_RODATA_SIZE = ABSOLUTE(game_RODATA_END - game_RODATA_START);
        game_DATA_START = .;
        build/link/src/18020_1D7F0.o(.data);
        build/link/src/18020_2D2B0.o(.data);
        build/link/src/18020_2D5E0.o(.data);
        build/link/src/18020_33940.o(.data);
        build/link/src/18020_34900.o(.data);
        build/link/src/18020_34E60.o(.data);
        build/link/src/18020_376E8.o(.data);
        build/link/src/18020_3A90C.o(.data);
        build/link/src/18020_3AC40.o(.data);
        build/link/src/18020_3AD70.o(.data);
        build/link/src/18020_435D0.o(.data);
        build/link/src/18020_46680.o(.data);
        build/link/src/18020_479E4.o(.data);
        build/link/src/18020_47B98.o(.data);
        build/link/src/18020_48000.o(.data);
        build/link/src/18020_50400.o(.data);
        build/link/src/18020_56B90.o(.data);
        build/link/src/18020_80200.o(.data);
        build/link/src/18020_812E0.o(.data);
        game_DATA_END = .;
        game_DATA_SIZE = ABSOLUTE(game_DATA_END - game_DATA_START);
    }
    game_bss_VRAM = ADDR(.game_bss);
    .game_bss (NOLOAD) :
    {
        FILL(0x00000000);
        game_BSS_START = .;
        build/link/src/18020_1D7F0.o(.bss);
        build/link/src/18020_2D2B0.o(.bss);
        build/link/src/18020_2D5E0.o(.bss);
        build/link/src/18020_33940.o(.bss);
        build/link/src/18020_34900.o(.bss);
        build/link/src/18020_34E60.o(.bss);
        build/link/src/18020_376E8.o(.bss);
        build/link/src/18020_3A90C.o(.bss);
        build/link/src/18020_3AC40.o(.bss);
        build/link/src/18020_3AD70.o(.bss);
        build/link/src/18020_435D0.o(.bss);
        build/link/src/18020_46680.o(.bss);
        build/link/src/18020_479E4.o(.bss);
        build/link/src/18020_47B98.o(.bss);
        build/link/src/18020_48000.o(.bss);
        build/link/src/18020_50400.o(.bss);
        build/link/src/18020_56B90.o(.bss);
        build/link/src/18020_80200.o(.bss);
        build/link/src/18020_812E0.o(.bss);
        game_BSS_END = .;
        game_BSS_SIZE = ABSOLUTE(game_BSS_END - game_BSS_START);
    }
    __romPos += SIZEOF(.game);
    __romPos = ALIGN(__romPos, 16);
    game_ROM_END = __romPos;
    game_VRAM_END = .;

    rspgfx_ROM_START = __romPos;
    rspgfx_VRAM = ADDR(.rspgfx);
    .rspgfx 0x801BC710 : AT(rspgfx_ROM_START)
    {
        FILL(0x00000000);
        rspgfx_DATA_START = .;
        build/assets/rspgfx.o(.data);
        rspgfx_DATA_END = .;
        rspgfx_DATA_SIZE = ABSOLUTE(rspgfx_DATA_END - rspgfx_DATA_START);
    }
    __romPos += SIZEOF(.rspgfx);
    rspgfx_ROM_END = __romPos;
    rspgfx_VRAM_END = .;

    game_end_ROM_START = __romPos;
    game_end_VRAM = ADDR(.game_end);
    .game_end 0x801BF800 : AT(game_end_ROM_START)
    {
        FILL(0x00000000);
        game_end_TEXT_START = .;
        build/link/src/18020_C0800.o(.text);
        build/asm/C5030.o(.text);
        build/link/src/18020_C5030.o(.text);
        build/asm/C72B0.o(.text);
        build/link/src/18020_C7520.o(.text);
        build/asm/C7620.o(.text);
        build/asm/C7D8C.o(.text);
        build/asm/C7DE4.o(.text);
        build/asm/C7F60.o(.text);
        build/asm/C7F70.o(.text);
        build/link/src/18020_C7FB0.o(.text);
        build/asm/C8320.o(.text);
        build/link/src/18020_C8430.o(.text);
        build/asm/C8D80.o(.text);
        build/link/src/18020_C8D90.o(.text);
        build/asm/C8DF0.o(.text);
        build/link/src/18020_C8EB0.o(.text);
        build/asm/D2D00.o(.text);
        build/link/src/18020_D30C0.o(.text);
        build/link/src/18020_D4AA0.o(.text);
        game_end_TEXT_END = .;
        game_end_TEXT_SIZE = ABSOLUTE(game_end_TEXT_END - game_end_TEXT_START);
        game_end_RODATA_START = .;
        build/asm/C5030.o(.rodata);
        build/asm/C72B0.o(.rodata);
        build/asm/C7620.o(.rodata);
        build/asm/C7D8C.o(.rodata);
        build/asm/C7DE4.o(.rodata);
        build/asm/C7F60.o(.rodata);
        build/asm/C7F70.o(.rodata);
        build/asm/C8320.o(.rodata);
        build/asm/C8D80.o(.rodata);
        build/asm/C8DF0.o(.rodata);
        build/asm/D2D00.o(.rodata);
        game_end_RODATA_END = .;
        game_end_RODATA_SIZE = ABSOLUTE(game_end_RODATA_END - game_end_RODATA_START);
        game_end_DATA_START = .;
        build/link/src/18020_C0800.o(.data);
        build/asm/C5030.o(.data);
        build/link/src/18020_C5030.o(.data);
        build/asm/C72B0.o(.data);
        build/link/src/18020_C7520.o(.data);
        build/asm/C7620.o(.data);
        build/asm/C7D8C.o(.data);
        build/asm/C7DE4.o(.data);
        build/asm/C7F60.o(.data);
        build/asm/C7F70.o(.data);
        build/link/src/18020_C7FB0.o(.data);
        build/asm/C8320.o(.data);
        build/link/src/18020_C8430.o(.data);
        build/asm/C8D80.o(.data);
        build/link/src/18020_C8D90.o(.data);
        build/asm/C8DF0.o(.data);
        build/link/src/18020_C8EB0.o(.data);
        build/asm/D2D00.o(.data);
        build/link/src/18020_D30C0.o(.data);
        build/link/src/18020_D4AA0.o(.data);
        build/asm/data/D51D0.data.o(.data);
        game_end_DATA_END = .;
        game_end_DATA_SIZE = ABSOLUTE(game_end_DATA_END - game_end_DATA_START);
    }
    game_end_bss_VRAM = ADDR(.game_end_bss);
    .game_end_bss (NOLOAD) :
    {
        FILL(0x00000000);
        game_end_BSS_START = .;
        build/link/src/18020_C0800.o(.bss);
        build/asm/C5030.o(.bss);
        build/link/src/18020_C5030.o(.bss);
        build/asm/C72B0.o(.bss);
        build/link/src/18020_C7520.o(.bss);
        build/asm/C7620.o(.bss);
        build/asm/C7D8C.o(.bss);
        build/asm/C7DE4.o(.bss);
        build/asm/C7F60.o(.bss);
        build/asm/C7F70.o(.bss);
        build/link/src/18020_C7FB0.o(.bss);
        build/asm/C8320.o(.bss);
        build/link/src/18020_C8430.o(.bss);
        build/asm/C8D80.o(.bss);
        build/link/src/18020_C8D90.o(.bss);
        build/asm/C8DF0.o(.bss);
        build/link/src/18020_C8EB0.o(.bss);
        build/asm/D2D00.o(.bss);
        build/link/src/18020_D30C0.o(.bss);
        build/link/src/18020_D4AA0.o(.bss);
        game_end_BSS_END = .;
        game_end_BSS_SIZE = ABSOLUTE(game_end_BSS_END - game_end_BSS_START);
    }
    __romPos += SIZEOF(.game_end);
    __romPos = ALIGN(__romPos, 16);
    game_end_ROM_END = __romPos;
    game_end_VRAM_END = .;

    game_bss_ROM_START = __romPos;
    game_bss_bss_VRAM = ADDR(.game_bss_bss);
    .game_bss_bss 0x801F5680 (NOLOAD) :
    {
        FILL(0x00000000);
        game_bss_BSS_START = .;
        build/asm/data/F5680.bss.o(.bss);
        game_bss_BSS_END = .;
        game_bss_BSS_SIZE = ABSOLUTE(game_bss_BSS_END - game_bss_BSS_START);
    }
    __romPos = ALIGN(__romPos, 16);
    game_bss_ROM_END = __romPos;
    game_bss_VRAM_END = .;

    F5680_ROM_START = __romPos;
    F5680_VRAM = ADDR(.F5680);
    .F5680 game_bss_VRAM_END : AT(F5680_ROM_START)
    {
        FILL(0x00000000);
        F5680_DATA_START = .;
        build/assets/F5680.o(.data);
        F5680_DATA_END = .;
        F5680_DATA_SIZE = ABSOLUTE(F5680_DATA_END - F5680_DATA_START);
    }
    __romPos += SIZEOF(.F5680);
    F5680_ROM_END = __romPos;
    F5680_VRAM_END = .;

    /* C objects' own .rodata, parked outside the ROM (tools/link_rodata.py). */
    INCLUDE build/link/src/crodata.ld

    /DISCARD/ :
    {
        *(*);
    }
}
