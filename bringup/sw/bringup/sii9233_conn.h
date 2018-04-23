
    // line nr: 1, packet id: 702
    // (0x60) (0x06) System Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x06);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 3, packet id: 704
    // (0x60) (0x08) System Ctrl 1
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x08);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 5, packet id: 706
    // (0x60) (0x08) System Ctrl 1 = 0x05
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x08, 0x05);

    // line nr: 7, packet id: 707
    // (0x60) (0x07) SW Reset 2
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x07);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 9, packet id: 709
    // (0x60) (0x07) SW Reset 2 = 0x88
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x07, 0x88);

    // line nr: 11, packet id: 710
    // (0x60) (0x07) SW Reset 2
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x07);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 13, packet id: 712
    // (0x60) (0x07) SW Reset 2 = 0x08
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x07, 0x08);

    // line nr: 15, packet id: 713
    // (0x68) (0x37) RX_AUDP_MUTE
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x68, 0x37);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x69, buf, 1);
    }

    // line nr: 17, packet id: 715
    // (0x60) (0x72) Interrupt Status 2 = 0x08
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x72, 0x08);

    // line nr: 19, packet id: 716
    // (0x60) (0x7b) Interrupt Status 5 = 0x18
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x7b, 0x18);

    // line nr: 21, packet id: 717
    // (0x60) (0xb8) AEX Exception Enable 3
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0xb8);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 23, packet id: 719
    // (0x60) (0xb7) AEX Exception Enable 2
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0xb7);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 25, packet id: 721
    // (0x60) (0x7a) Interrupt Info Frame Control
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x7a);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 27, packet id: 723
    // (0x60) (0x07) SW Reset 2
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x07);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 29, packet id: 725
    // (0x60) (0x07) SW Reset 2 = 0x00
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x07, 0x00);

    // line nr: 31, packet id: 726
    // (0x60) (0x70) Interrupt Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x70);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 33, packet id: 728
    // (0x60) (0x71) Interrupt Status 1
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x71);

    {
    byte buf[4];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 4);
    }

    // line nr: 38, packet id: 730
    // (0x60) (0x7b) Interrupt Status 5
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x7b);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 41, packet id: 732
    // (0x60) (0x90) Interrupt Status 7
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x90);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 44, packet id: 734
    // (0x60) (0x71) Interrupt Status 1 = 0x00
    // (0x60) (0x72) Interrupt Status 2 = 0x10
    // (0x60) (0x73) Interrupt Status 3 = 0x00
    // (0x60) (0x74) Interrupt Status 4 = 0x00
    {
    byte buf[4] = { 0x00, 0x10, 0x00, 0x00 };
    i2c_write_regs(&sii9233_i2c_ctx, 0x60, 0x71, buf, 4);
    }

    // line nr: 49, packet id: 735
    // (0x60) (0x7b) Interrupt Status 5 = 0x01
    // (0x60) (0x7c) Interrupt Status 6 = 0x01
    {
    byte buf[2] = { 0x01, 0x01 };
    i2c_write_regs(&sii9233_i2c_ctx, 0x60, 0x7b, buf, 2);
    }

    // line nr: 52, packet id: 736
    // (0x60) (0x90) Interrupt Status 7 = 0x00
    // (0x60) (0x91) Interrupt Status 8 = 0x00
    {
    byte buf[2] = { 0x00, 0x00 };
    i2c_write_regs(&sii9233_i2c_ctx, 0x60, 0x90, buf, 2);
    }

    // line nr: 55, packet id: 737
    // (0x68) (0x2a) * RX_CH_STATUS1
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x68, 0x2a);

    {
    byte buf[3];
    i2c_read_buf(&sii9233_i2c_ctx, 0x69, buf, 3);
    }

    // line nr: 59, packet id: 739
    // (0x68) (0x30) * RX_CH_STATUS4
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x68, 0x30);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x69, buf, 2);
    }

    // line nr: 62, packet id: 741
    // (0x68) (0x17) TCLK_FS
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x68, 0x17);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x69, buf, 1);
    }

    // line nr: 64, packet id: 743
    // (0x68) (0x34) RX_AUDP_STAT
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x68, 0x34);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x69, buf, 1);
    }

    // line nr: 66, packet id: 745
    // (0x60) (0x70) Interrupt Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x70);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 68, packet id: 747
    // (0x60) (0x71) Interrupt Status 1
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x71);

    {
    byte buf[4];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 4);
    }

    // line nr: 73, packet id: 749
    // (0x60) (0x7b) Interrupt Status 5
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x7b);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 76, packet id: 751
    // (0x60) (0x90) Interrupt Status 7
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x90);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 79, packet id: 753
    // (0x60) (0x71) Interrupt Status 1 = 0x00
    // (0x60) (0x72) Interrupt Status 2 = 0x00
    // (0x60) (0x73) Interrupt Status 3 = 0x00
    // (0x60) (0x74) Interrupt Status 4 = 0x00
    {
    byte buf[4] = { 0x00, 0x00, 0x00, 0x00 };
    i2c_write_regs(&sii9233_i2c_ctx, 0x60, 0x71, buf, 4);
    }

    // line nr: 84, packet id: 754
    // (0x60) (0x7b) Interrupt Status 5 = 0x10
    // (0x60) (0x7c) Interrupt Status 6 = 0x00
    {
    byte buf[2] = { 0x10, 0x00 };
    i2c_write_regs(&sii9233_i2c_ctx, 0x60, 0x7b, buf, 2);
    }

    // line nr: 87, packet id: 755
    // (0x60) (0x90) Interrupt Status 7 = 0x00
    // (0x60) (0x91) Interrupt Status 8 = 0x00
    {
    byte buf[2] = { 0x00, 0x00 };
    i2c_write_regs(&sii9233_i2c_ctx, 0x60, 0x90, buf, 2);
    }

    // line nr: 90, packet id: 756
    // (0x60) (0x61) Deep Color Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x61);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 92, packet id: 758
    // (0x60) (0x70) Interrupt Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x70);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 94, packet id: 760
    // (0x68) (0x34) RX_AUDP_STAT
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x68, 0x34);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x69, buf, 1);
    }

    // line nr: 96, packet id: 762
    // (0x60) (0x70) Interrupt Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x70);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 98, packet id: 764
    // (0x60) (0x70) Interrupt Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x70);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 100, packet id: 766
    // (0x68) (0xbf) MPEG_DECODE = 0x05
    i2c_write_reg(&sii9233_i2c_ctx, 0x68, 0xbf, 0x05);

    // line nr: 102, packet id: 767
    // (0x60) (0x7a) Interrupt Info Frame Control
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x7a);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 104, packet id: 769
    // (0x60) (0x73) Interrupt Status 3 = 0x08
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x73, 0x08);

    // line nr: 106, packet id: 770
    // (0x60) (0x91) Interrupt Status 8 = 0x08
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x91, 0x08);

    // line nr: 108, packet id: 771
    // (0x60) (0x94) INFM_CLR
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x94);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 110, packet id: 773
    // (0x68) (0x7f) SPD_DECODE = 0x81
    i2c_write_reg(&sii9233_i2c_ctx, 0x68, 0x7f, 0x81);

    // line nr: 112, packet id: 774
    // (0x60) (0x73) Interrupt Status 3 = 0x02
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x73, 0x02);

    // line nr: 114, packet id: 775
    // (0x68) (0x34) RX_AUDP_STAT
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x68, 0x34);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x69, buf, 1);
    }

    // line nr: 116, packet id: 777
    // (0x60) (0x70) Interrupt Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x70);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 118, packet id: 779
    // (0x60) (0x61) Deep Color Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x61);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 120, packet id: 781
    // (0x68) (0x34) RX_AUDP_STAT
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x68, 0x34);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x69, buf, 1);
    }

    // line nr: 122, packet id: 783
    // (0x60) (0x70) Interrupt Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x70);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 124, packet id: 785
    // (0x60) (0x70) Interrupt Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x70);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 126, packet id: 787
    // (0x68) (0x34) RX_AUDP_STAT
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x68, 0x34);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x69, buf, 1);
    }

    // line nr: 128, packet id: 789
    // (0x60) (0x70) Interrupt Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x70);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 130, packet id: 791
    // (0x68) (0x34) RX_AUDP_STAT
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x68, 0x34);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x69, buf, 1);
    }

    // line nr: 132, packet id: 793
    // (0x60) (0x70) Interrupt Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x70);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 134, packet id: 795
    // (0x60) (0x61) Deep Color Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x61);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 136, packet id: 797
    // (0x60) (0x70) Interrupt Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x70);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 138, packet id: 799
    // (0x68) (0x34) RX_AUDP_STAT
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x68, 0x34);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x69, buf, 1);
    }

    // line nr: 140, packet id: 801
    // (0x60) (0x70) Interrupt Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x70);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 142, packet id: 803
    // (0x68) (0x34) RX_AUDP_STAT
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x68, 0x34);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x69, buf, 1);
    }

    // line nr: 144, packet id: 805
    // (0x60) (0x70) Interrupt Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x70);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 146, packet id: 807
    // (0x60) (0x06) System Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x06);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 148, packet id: 809
    // (0x60) (0x70) Interrupt Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x70);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 150, packet id: 811
    // (0x68) (0x34) RX_AUDP_STAT
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x68, 0x34);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x69, buf, 1);
    }

    // line nr: 152, packet id: 813
    // (0x60) (0x70) Interrupt Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x70);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 154, packet id: 815
    // (0x60) (0x61) Deep Color Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x61);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 156, packet id: 817
    // (0x60) (0x70) Interrupt Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x70);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 158, packet id: 819
    // (0x68) (0x34) RX_AUDP_STAT
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x68, 0x34);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x69, buf, 1);
    }

    // line nr: 160, packet id: 821
    // (0x60) (0x70) Interrupt Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x70);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 162, packet id: 823
    // (0x60) (0x06) System Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x06);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 164, packet id: 825
    // (0x60) (0x08) System Ctrl 1
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x08);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 166, packet id: 827
    // (0x60) (0x55) <Unknown>
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x55);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 168, packet id: 829
    // (0x60) (0x3a) Video Input H Resolution (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x3a);

    {
    byte buf[4];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 4);
    }

    // line nr: 173, packet id: 831
    // (0x60) (0x6a) XCLK to PCLK Update = 0x01
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x6a, 0x01);

    // line nr: 175, packet id: 832
    // (0x60) (0x6a) XCLK to PCLK Update = 0x00
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x6a, 0x00);

    // line nr: 177, packet id: 833
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 180, packet id: 835
    // (0x60) (0x6a) XCLK to PCLK Update = 0x01
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x6a, 0x01);

    // line nr: 182, packet id: 836
    // (0x60) (0x6a) XCLK to PCLK Update = 0x00
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x6a, 0x00);

    // line nr: 184, packet id: 837
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 187, packet id: 839
    // (0x60) (0x6a) XCLK to PCLK Update = 0x01
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x6a, 0x01);

    // line nr: 189, packet id: 840
    // (0x60) (0x6a) XCLK to PCLK Update = 0x00
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x6a, 0x00);

    // line nr: 191, packet id: 841
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 194, packet id: 843
    // (0x60) (0x6a) XCLK to PCLK Update = 0x01
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x6a, 0x01);

    // line nr: 196, packet id: 844
    // (0x60) (0x6a) XCLK to PCLK Update = 0x00
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x6a, 0x00);

    // line nr: 198, packet id: 845
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 201, packet id: 847
    // (0x60) (0x6a) XCLK to PCLK Update = 0x01
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x6a, 0x01);

    // line nr: 203, packet id: 848
    // (0x60) (0x6a) XCLK to PCLK Update = 0x00
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x6a, 0x00);

    // line nr: 205, packet id: 849
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 208, packet id: 851
    // (0x60) (0x6a) XCLK to PCLK Update = 0x01
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x6a, 0x01);

    // line nr: 210, packet id: 852
    // (0x60) (0x6a) XCLK to PCLK Update = 0x00
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x6a, 0x00);

    // line nr: 212, packet id: 853
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 215, packet id: 855
    // (0x60) (0x6a) XCLK to PCLK Update = 0x01
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x6a, 0x01);

    // line nr: 217, packet id: 856
    // (0x60) (0x6a) XCLK to PCLK Update = 0x00
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x6a, 0x00);

    // line nr: 219, packet id: 857
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 222, packet id: 859
    // (0x60) (0x6a) XCLK to PCLK Update = 0x01
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x6a, 0x01);

    // line nr: 224, packet id: 860
    // (0x60) (0x6a) XCLK to PCLK Update = 0x00
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x6a, 0x00);

    // line nr: 226, packet id: 861
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 229, packet id: 863
    // (0x60) (0x6a) XCLK to PCLK Update = 0x01
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x6a, 0x01);

    // line nr: 231, packet id: 864
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 234, packet id: 866
    // (0x60) (0x69) Video Channel PCLK Count Base = 0x80
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x69, 0x80);

    // line nr: 236, packet id: 867
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 239, packet id: 869
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 242, packet id: 871
    // (0x60) (0x69) Video Channel PCLK Count Base = 0xff
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x69, 0xff);

    // line nr: 244, packet id: 872
    // (0x60) (0x70) Interrupt Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x70);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 246, packet id: 874
    // (0x60) (0x70) Interrupt Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x70);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 248, packet id: 876
    // (0x68) (0x34) RX_AUDP_STAT
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x68, 0x34);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x69, buf, 1);
    }

    // line nr: 250, packet id: 878
    // (0x60) (0x61) Deep Color Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x61);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 252, packet id: 880
    // (0x60) (0x70) Interrupt Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x70);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 254, packet id: 882
    // (0x60) (0x4b) <Unknown> = 0x10
    // (0x60) (0x4c) <Unknown> = 0x10
    // (0x60) (0x4d) <Unknown> = 0x10
    {
    byte buf[3] = { 0x10, 0x10, 0x10 };
    i2c_write_regs(&sii9233_i2c_ctx, 0x60, 0x4b, buf, 3);
    }

    // line nr: 258, packet id: 883
    // (0x60) (0x49) Video Mode 2
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x49);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 260, packet id: 885
    // (0x60) (0x48) Video Control = 0x05
    // (0x60) (0x49) Video Mode 2 = 0x00
    // (0x60) (0x4a) <Unknown> = 0x20
    {
    byte buf[3] = { 0x05, 0x00, 0x20 };
    i2c_write_regs(&sii9233_i2c_ctx, 0x60, 0x48, buf, 3);
    }

    // line nr: 264, packet id: 886
    // (0x60) (0x08) System Ctrl 1
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x08);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 266, packet id: 888
    // (0x60) (0x08) System Ctrl 1 = 0x05
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x08, 0x05);

    // line nr: 268, packet id: 889
    // (0x68) (0x37) RX_AUDP_MUTE
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x68, 0x37);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x69, buf, 1);
    }

    // line nr: 270, packet id: 891
    // (0x68) (0x37) RX_AUDP_MUTE = 0x72
    i2c_write_reg(&sii9233_i2c_ctx, 0x68, 0x37, 0x72);

    // line nr: 272, packet id: 892
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 275, packet id: 894
    // (0x60) (0x69) Video Channel PCLK Count Base = 0x80
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x69, 0x80);

    // line nr: 277, packet id: 895
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 280, packet id: 897
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 283, packet id: 899
    // (0x60) (0x69) Video Channel PCLK Count Base = 0xff
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x69, 0xff);

    // line nr: 285, packet id: 900
    // (0x60) (0x70) Interrupt Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x70);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 287, packet id: 902
    // (0x60) (0x70) Interrupt Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x70);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 289, packet id: 904
    // (0x68) (0x34) RX_AUDP_STAT
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x68, 0x34);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x69, buf, 1);
    }

    // line nr: 291, packet id: 906
    // (0x60) (0x70) Interrupt Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x70);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 293, packet id: 908
    // (0x60) (0x61) Deep Color Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x61);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 295, packet id: 910
    // (0x68) (0x34) RX_AUDP_STAT
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x68, 0x34);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x69, buf, 1);
    }

    // line nr: 297, packet id: 912
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 300, packet id: 914
    // (0x60) (0x69) Video Channel PCLK Count Base = 0x80
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x69, 0x80);

    // line nr: 302, packet id: 915
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 305, packet id: 917
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 308, packet id: 919
    // (0x60) (0x69) Video Channel PCLK Count Base = 0xff
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x69, 0xff);

    // line nr: 310, packet id: 920
    // (0x60) (0x70) Interrupt Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x70);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 312, packet id: 922
    // (0x60) (0x70) Interrupt Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x70);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 314, packet id: 924
    // (0x68) (0x34) RX_AUDP_STAT
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x68, 0x34);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x69, buf, 1);
    }

    // line nr: 316, packet id: 926
    // (0x68) (0x34) RX_AUDP_STAT
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x68, 0x34);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x69, buf, 1);
    }

    // line nr: 318, packet id: 928
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 321, packet id: 930
    // (0x60) (0x69) Video Channel PCLK Count Base = 0x80
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x69, 0x80);

    // line nr: 323, packet id: 931
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 326, packet id: 933
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 329, packet id: 935
    // (0x60) (0x69) Video Channel PCLK Count Base = 0xff
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x69, 0xff);

    // line nr: 331, packet id: 936
    // (0x68) (0x34) RX_AUDP_STAT
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x68, 0x34);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x69, buf, 1);
    }

    // line nr: 333, packet id: 938
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 336, packet id: 940
    // (0x60) (0x69) Video Channel PCLK Count Base = 0x80
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x69, 0x80);

    // line nr: 338, packet id: 941
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 341, packet id: 943
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 344, packet id: 945
    // (0x60) (0x69) Video Channel PCLK Count Base = 0xff
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x69, 0xff);

    // line nr: 346, packet id: 946
    // (0x60) (0x70) Interrupt Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x70);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 348, packet id: 948
    // (0x68) (0x34) RX_AUDP_STAT
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x68, 0x34);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x69, buf, 1);
    }

    // line nr: 350, packet id: 950
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 353, packet id: 952
    // (0x60) (0x69) Video Channel PCLK Count Base = 0x80
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x69, 0x80);

    // line nr: 355, packet id: 953
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 358, packet id: 955
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 361, packet id: 957
    // (0x60) (0x69) Video Channel PCLK Count Base = 0xff
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x69, 0xff);

    // line nr: 363, packet id: 958
    // (0x60) (0x70) Interrupt Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x70);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 365, packet id: 960
    // (0x68) (0x34) RX_AUDP_STAT
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x68, 0x34);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x69, buf, 1);
    }

    // line nr: 367, packet id: 962
    // (0x60) (0x61) Deep Color Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x61);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 369, packet id: 964
    // (0x68) (0x34) RX_AUDP_STAT
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x68, 0x34);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x69, buf, 1);
    }

    // line nr: 371, packet id: 966
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 374, packet id: 968
    // (0x60) (0x69) Video Channel PCLK Count Base = 0x80
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x69, 0x80);

    // line nr: 376, packet id: 969
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 379, packet id: 971
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 382, packet id: 973
    // (0x60) (0x69) Video Channel PCLK Count Base = 0xff
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x69, 0xff);

    // line nr: 384, packet id: 974
    // (0x60) (0x70) Interrupt Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x70);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 386, packet id: 976
    // (0x68) (0x34) RX_AUDP_STAT
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x68, 0x34);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x69, buf, 1);
    }

    // line nr: 388, packet id: 978
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 391, packet id: 980
    // (0x60) (0x69) Video Channel PCLK Count Base = 0x80
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x69, 0x80);

    // line nr: 393, packet id: 981
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 396, packet id: 983
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 399, packet id: 985
    // (0x60) (0x69) Video Channel PCLK Count Base = 0xff
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x69, 0xff);

    // line nr: 401, packet id: 986
    // (0x60) (0x70) Interrupt Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x70);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 403, packet id: 988
    // (0x68) (0x34) RX_AUDP_STAT
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x68, 0x34);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x69, buf, 1);
    }

    // line nr: 405, packet id: 990
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 408, packet id: 992
    // (0x60) (0x69) Video Channel PCLK Count Base = 0x80
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x69, 0x80);

    // line nr: 410, packet id: 993
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 413, packet id: 995
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 416, packet id: 997
    // (0x60) (0x69) Video Channel PCLK Count Base = 0xff
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x69, 0xff);

    // line nr: 418, packet id: 998
    // (0x60) (0x70) Interrupt Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x70);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 420, packet id: 1000
    // (0x60) (0x61) Deep Color Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x61);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 422, packet id: 1002
    // (0x68) (0x34) RX_AUDP_STAT
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x68, 0x34);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x69, buf, 1);
    }

    // line nr: 424, packet id: 1004
    // (0x60) (0x70) Interrupt Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x70);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 426, packet id: 1006
    // (0x68) (0x34) RX_AUDP_STAT
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x68, 0x34);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x69, buf, 1);
    }

    // line nr: 428, packet id: 1008
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 431, packet id: 1010
    // (0x60) (0x69) Video Channel PCLK Count Base = 0x80
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x69, 0x80);

    // line nr: 433, packet id: 1011
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 436, packet id: 1013
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 439, packet id: 1015
    // (0x60) (0x69) Video Channel PCLK Count Base = 0xff
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x69, 0xff);

    // line nr: 441, packet id: 1016
    // (0x60) (0x70) Interrupt Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x70);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 443, packet id: 1018
    // (0x60) (0x70) Interrupt Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x70);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 445, packet id: 1020
    // (0x68) (0x34) RX_AUDP_STAT
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x68, 0x34);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x69, buf, 1);
    }

    // line nr: 447, packet id: 1022
    // (0x68) (0x34) RX_AUDP_STAT
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x68, 0x34);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x69, buf, 1);
    }

    // line nr: 449, packet id: 1024
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 452, packet id: 1026
    // (0x60) (0x69) Video Channel PCLK Count Base = 0x80
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x69, 0x80);

    // line nr: 454, packet id: 1027
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 457, packet id: 1029
    // (0x60) (0x6e) Pixel Clock Timing (l)
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x6e);

    {
    byte buf[2];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 2);
    }

    // line nr: 460, packet id: 1031
    // (0x60) (0x69) Video Channel PCLK Count Base = 0xff
    i2c_write_reg(&sii9233_i2c_ctx, 0x60, 0x69, 0xff);

    // line nr: 462, packet id: 1032
    // (0x60) (0x70) Interrupt Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x70);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }

    // line nr: 464, packet id: 1034
    // (0x60) (0x70) Interrupt Status
    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x60, 0x70);

    {
    byte buf[1];
    i2c_read_buf(&sii9233_i2c_ctx, 0x61, buf, 1);
    }


