module s_cla32(input [31:0] a, input [31:0] b, output [32:0] s_cla32_out);
  wire s_cla32_pg_logic0_or0;
  wire s_cla32_pg_logic0_and0;
  wire s_cla32_pg_logic0_xor0;
  wire s_cla32_pg_logic1_or0;
  wire s_cla32_pg_logic1_and0;
  wire s_cla32_pg_logic1_xor0;
  wire s_cla32_xor1;
  wire s_cla32_and0;
  wire s_cla32_or0;
  wire s_cla32_pg_logic2_or0;
  wire s_cla32_pg_logic2_and0;
  wire s_cla32_pg_logic2_xor0;
  wire s_cla32_xor2;
  wire s_cla32_and1;
  wire s_cla32_and2;
  wire s_cla32_and3;
  wire s_cla32_and4;
  wire s_cla32_or1;
  wire s_cla32_or2;
  wire s_cla32_pg_logic3_or0;
  wire s_cla32_pg_logic3_and0;
  wire s_cla32_pg_logic3_xor0;
  wire s_cla32_xor3;
  wire s_cla32_and5;
  wire s_cla32_and6;
  wire s_cla32_and7;
  wire s_cla32_and8;
  wire s_cla32_and9;
  wire s_cla32_and10;
  wire s_cla32_and11;
  wire s_cla32_or3;
  wire s_cla32_or4;
  wire s_cla32_or5;
  wire s_cla32_pg_logic4_or0;
  wire s_cla32_pg_logic4_and0;
  wire s_cla32_pg_logic4_xor0;
  wire s_cla32_xor4;
  wire s_cla32_and12;
  wire s_cla32_or6;
  wire s_cla32_pg_logic5_or0;
  wire s_cla32_pg_logic5_and0;
  wire s_cla32_pg_logic5_xor0;
  wire s_cla32_xor5;
  wire s_cla32_and13;
  wire s_cla32_and14;
  wire s_cla32_and15;
  wire s_cla32_or7;
  wire s_cla32_or8;
  wire s_cla32_pg_logic6_or0;
  wire s_cla32_pg_logic6_and0;
  wire s_cla32_pg_logic6_xor0;
  wire s_cla32_xor6;
  wire s_cla32_and16;
  wire s_cla32_and17;
  wire s_cla32_and18;
  wire s_cla32_and19;
  wire s_cla32_and20;
  wire s_cla32_and21;
  wire s_cla32_or9;
  wire s_cla32_or10;
  wire s_cla32_or11;
  wire s_cla32_pg_logic7_or0;
  wire s_cla32_pg_logic7_and0;
  wire s_cla32_pg_logic7_xor0;
  wire s_cla32_xor7;
  wire s_cla32_and22;
  wire s_cla32_and23;
  wire s_cla32_and24;
  wire s_cla32_and25;
  wire s_cla32_and26;
  wire s_cla32_and27;
  wire s_cla32_and28;
  wire s_cla32_and29;
  wire s_cla32_and30;
  wire s_cla32_and31;
  wire s_cla32_or12;
  wire s_cla32_or13;
  wire s_cla32_or14;
  wire s_cla32_or15;
  wire s_cla32_pg_logic8_or0;
  wire s_cla32_pg_logic8_and0;
  wire s_cla32_pg_logic8_xor0;
  wire s_cla32_xor8;
  wire s_cla32_and32;
  wire s_cla32_or16;
  wire s_cla32_pg_logic9_or0;
  wire s_cla32_pg_logic9_and0;
  wire s_cla32_pg_logic9_xor0;
  wire s_cla32_xor9;
  wire s_cla32_and33;
  wire s_cla32_and34;
  wire s_cla32_and35;
  wire s_cla32_or17;
  wire s_cla32_or18;
  wire s_cla32_pg_logic10_or0;
  wire s_cla32_pg_logic10_and0;
  wire s_cla32_pg_logic10_xor0;
  wire s_cla32_xor10;
  wire s_cla32_and36;
  wire s_cla32_and37;
  wire s_cla32_and38;
  wire s_cla32_and39;
  wire s_cla32_and40;
  wire s_cla32_and41;
  wire s_cla32_or19;
  wire s_cla32_or20;
  wire s_cla32_or21;
  wire s_cla32_pg_logic11_or0;
  wire s_cla32_pg_logic11_and0;
  wire s_cla32_pg_logic11_xor0;
  wire s_cla32_xor11;
  wire s_cla32_and42;
  wire s_cla32_and43;
  wire s_cla32_and44;
  wire s_cla32_and45;
  wire s_cla32_and46;
  wire s_cla32_and47;
  wire s_cla32_and48;
  wire s_cla32_and49;
  wire s_cla32_and50;
  wire s_cla32_and51;
  wire s_cla32_or22;
  wire s_cla32_or23;
  wire s_cla32_or24;
  wire s_cla32_or25;
  wire s_cla32_pg_logic12_or0;
  wire s_cla32_pg_logic12_and0;
  wire s_cla32_pg_logic12_xor0;
  wire s_cla32_xor12;
  wire s_cla32_and52;
  wire s_cla32_or26;
  wire s_cla32_pg_logic13_or0;
  wire s_cla32_pg_logic13_and0;
  wire s_cla32_pg_logic13_xor0;
  wire s_cla32_xor13;
  wire s_cla32_and53;
  wire s_cla32_and54;
  wire s_cla32_and55;
  wire s_cla32_or27;
  wire s_cla32_or28;
  wire s_cla32_pg_logic14_or0;
  wire s_cla32_pg_logic14_and0;
  wire s_cla32_pg_logic14_xor0;
  wire s_cla32_xor14;
  wire s_cla32_and56;
  wire s_cla32_and57;
  wire s_cla32_and58;
  wire s_cla32_and59;
  wire s_cla32_and60;
  wire s_cla32_and61;
  wire s_cla32_or29;
  wire s_cla32_or30;
  wire s_cla32_or31;
  wire s_cla32_pg_logic15_or0;
  wire s_cla32_pg_logic15_and0;
  wire s_cla32_pg_logic15_xor0;
  wire s_cla32_xor15;
  wire s_cla32_and62;
  wire s_cla32_and63;
  wire s_cla32_and64;
  wire s_cla32_and65;
  wire s_cla32_and66;
  wire s_cla32_and67;
  wire s_cla32_and68;
  wire s_cla32_and69;
  wire s_cla32_and70;
  wire s_cla32_and71;
  wire s_cla32_or32;
  wire s_cla32_or33;
  wire s_cla32_or34;
  wire s_cla32_or35;
  wire s_cla32_pg_logic16_or0;
  wire s_cla32_pg_logic16_and0;
  wire s_cla32_pg_logic16_xor0;
  wire s_cla32_xor16;
  wire s_cla32_and72;
  wire s_cla32_or36;
  wire s_cla32_pg_logic17_or0;
  wire s_cla32_pg_logic17_and0;
  wire s_cla32_pg_logic17_xor0;
  wire s_cla32_xor17;
  wire s_cla32_and73;
  wire s_cla32_and74;
  wire s_cla32_and75;
  wire s_cla32_or37;
  wire s_cla32_or38;
  wire s_cla32_pg_logic18_or0;
  wire s_cla32_pg_logic18_and0;
  wire s_cla32_pg_logic18_xor0;
  wire s_cla32_xor18;
  wire s_cla32_and76;
  wire s_cla32_and77;
  wire s_cla32_and78;
  wire s_cla32_and79;
  wire s_cla32_and80;
  wire s_cla32_and81;
  wire s_cla32_or39;
  wire s_cla32_or40;
  wire s_cla32_or41;
  wire s_cla32_pg_logic19_or0;
  wire s_cla32_pg_logic19_and0;
  wire s_cla32_pg_logic19_xor0;
  wire s_cla32_xor19;
  wire s_cla32_and82;
  wire s_cla32_and83;
  wire s_cla32_and84;
  wire s_cla32_and85;
  wire s_cla32_and86;
  wire s_cla32_and87;
  wire s_cla32_and88;
  wire s_cla32_and89;
  wire s_cla32_and90;
  wire s_cla32_and91;
  wire s_cla32_or42;
  wire s_cla32_or43;
  wire s_cla32_or44;
  wire s_cla32_or45;
  wire s_cla32_pg_logic20_or0;
  wire s_cla32_pg_logic20_and0;
  wire s_cla32_pg_logic20_xor0;
  wire s_cla32_xor20;
  wire s_cla32_and92;
  wire s_cla32_or46;
  wire s_cla32_pg_logic21_or0;
  wire s_cla32_pg_logic21_and0;
  wire s_cla32_pg_logic21_xor0;
  wire s_cla32_xor21;
  wire s_cla32_and93;
  wire s_cla32_and94;
  wire s_cla32_and95;
  wire s_cla32_or47;
  wire s_cla32_or48;
  wire s_cla32_pg_logic22_or0;
  wire s_cla32_pg_logic22_and0;
  wire s_cla32_pg_logic22_xor0;
  wire s_cla32_xor22;
  wire s_cla32_and96;
  wire s_cla32_and97;
  wire s_cla32_and98;
  wire s_cla32_and99;
  wire s_cla32_and100;
  wire s_cla32_and101;
  wire s_cla32_or49;
  wire s_cla32_or50;
  wire s_cla32_or51;
  wire s_cla32_pg_logic23_or0;
  wire s_cla32_pg_logic23_and0;
  wire s_cla32_pg_logic23_xor0;
  wire s_cla32_xor23;
  wire s_cla32_and102;
  wire s_cla32_and103;
  wire s_cla32_and104;
  wire s_cla32_and105;
  wire s_cla32_and106;
  wire s_cla32_and107;
  wire s_cla32_and108;
  wire s_cla32_and109;
  wire s_cla32_and110;
  wire s_cla32_and111;
  wire s_cla32_or52;
  wire s_cla32_or53;
  wire s_cla32_or54;
  wire s_cla32_or55;
  wire s_cla32_pg_logic24_or0;
  wire s_cla32_pg_logic24_and0;
  wire s_cla32_pg_logic24_xor0;
  wire s_cla32_xor24;
  wire s_cla32_and112;
  wire s_cla32_or56;
  wire s_cla32_pg_logic25_or0;
  wire s_cla32_pg_logic25_and0;
  wire s_cla32_pg_logic25_xor0;
  wire s_cla32_xor25;
  wire s_cla32_and113;
  wire s_cla32_and114;
  wire s_cla32_and115;
  wire s_cla32_or57;
  wire s_cla32_or58;
  wire s_cla32_pg_logic26_or0;
  wire s_cla32_pg_logic26_and0;
  wire s_cla32_pg_logic26_xor0;
  wire s_cla32_xor26;
  wire s_cla32_and116;
  wire s_cla32_and117;
  wire s_cla32_and118;
  wire s_cla32_and119;
  wire s_cla32_and120;
  wire s_cla32_and121;
  wire s_cla32_or59;
  wire s_cla32_or60;
  wire s_cla32_or61;
  wire s_cla32_pg_logic27_or0;
  wire s_cla32_pg_logic27_and0;
  wire s_cla32_pg_logic27_xor0;
  wire s_cla32_xor27;
  wire s_cla32_and122;
  wire s_cla32_and123;
  wire s_cla32_and124;
  wire s_cla32_and125;
  wire s_cla32_and126;
  wire s_cla32_and127;
  wire s_cla32_and128;
  wire s_cla32_and129;
  wire s_cla32_and130;
  wire s_cla32_and131;
  wire s_cla32_or62;
  wire s_cla32_or63;
  wire s_cla32_or64;
  wire s_cla32_or65;
  wire s_cla32_pg_logic28_or0;
  wire s_cla32_pg_logic28_and0;
  wire s_cla32_pg_logic28_xor0;
  wire s_cla32_xor28;
  wire s_cla32_and132;
  wire s_cla32_or66;
  wire s_cla32_pg_logic29_or0;
  wire s_cla32_pg_logic29_and0;
  wire s_cla32_pg_logic29_xor0;
  wire s_cla32_xor29;
  wire s_cla32_and133;
  wire s_cla32_and134;
  wire s_cla32_and135;
  wire s_cla32_or67;
  wire s_cla32_or68;
  wire s_cla32_pg_logic30_or0;
  wire s_cla32_pg_logic30_and0;
  wire s_cla32_pg_logic30_xor0;
  wire s_cla32_xor30;
  wire s_cla32_and136;
  wire s_cla32_and137;
  wire s_cla32_and138;
  wire s_cla32_and139;
  wire s_cla32_and140;
  wire s_cla32_and141;
  wire s_cla32_or69;
  wire s_cla32_or70;
  wire s_cla32_or71;
  wire s_cla32_pg_logic31_or0;
  wire s_cla32_pg_logic31_and0;
  wire s_cla32_pg_logic31_xor0;
  wire s_cla32_xor31;
  wire s_cla32_and142;
  wire s_cla32_and143;
  wire s_cla32_and144;
  wire s_cla32_and145;
  wire s_cla32_and146;
  wire s_cla32_and147;
  wire s_cla32_and148;
  wire s_cla32_and149;
  wire s_cla32_and150;
  wire s_cla32_and151;
  wire s_cla32_or72;
  wire s_cla32_or73;
  wire s_cla32_or74;
  wire s_cla32_or75;
  wire s_cla32_xor32;
  wire s_cla32_xor33;

  assign s_cla32_pg_logic0_or0 = a[0] | b[0];
  assign s_cla32_pg_logic0_and0 = a[0] & b[0];
  assign s_cla32_pg_logic0_xor0 = a[0] ^ b[0];
  assign s_cla32_pg_logic1_or0 = a[1] | b[1];
  assign s_cla32_pg_logic1_and0 = a[1] & b[1];
  assign s_cla32_pg_logic1_xor0 = a[1] ^ b[1];
  assign s_cla32_xor1 = s_cla32_pg_logic1_xor0 ^ s_cla32_pg_logic0_and0;
  assign s_cla32_and0 = s_cla32_pg_logic0_and0 & s_cla32_pg_logic1_or0;
  assign s_cla32_or0 = s_cla32_pg_logic1_and0 | s_cla32_and0;
  assign s_cla32_pg_logic2_or0 = a[2] | b[2];
  assign s_cla32_pg_logic2_and0 = a[2] & b[2];
  assign s_cla32_pg_logic2_xor0 = a[2] ^ b[2];
  assign s_cla32_xor2 = s_cla32_pg_logic2_xor0 ^ s_cla32_or0;
  assign s_cla32_and1 = s_cla32_pg_logic2_or0 & s_cla32_pg_logic0_or0;
  assign s_cla32_and2 = s_cla32_pg_logic0_and0 & s_cla32_pg_logic2_or0;
  assign s_cla32_and3 = s_cla32_and2 & s_cla32_pg_logic1_or0;
  assign s_cla32_and4 = s_cla32_pg_logic1_and0 & s_cla32_pg_logic2_or0;
  assign s_cla32_or1 = s_cla32_and3 | s_cla32_and4;
  assign s_cla32_or2 = s_cla32_pg_logic2_and0 | s_cla32_or1;
  assign s_cla32_pg_logic3_or0 = a[3] | b[3];
  assign s_cla32_pg_logic3_and0 = a[3] & b[3];
  assign s_cla32_pg_logic3_xor0 = a[3] ^ b[3];
  assign s_cla32_xor3 = s_cla32_pg_logic3_xor0 ^ s_cla32_or2;
  assign s_cla32_and5 = s_cla32_pg_logic3_or0 & s_cla32_pg_logic1_or0;
  assign s_cla32_and6 = s_cla32_pg_logic0_and0 & s_cla32_pg_logic2_or0;
  assign s_cla32_and7 = s_cla32_pg_logic3_or0 & s_cla32_pg_logic1_or0;
  assign s_cla32_and8 = s_cla32_and6 & s_cla32_and7;
  assign s_cla32_and9 = s_cla32_pg_logic1_and0 & s_cla32_pg_logic3_or0;
  assign s_cla32_and10 = s_cla32_and9 & s_cla32_pg_logic2_or0;
  assign s_cla32_and11 = s_cla32_pg_logic2_and0 & s_cla32_pg_logic3_or0;
  assign s_cla32_or3 = s_cla32_and8 | s_cla32_and11;
  assign s_cla32_or4 = s_cla32_and10 | s_cla32_or3;
  assign s_cla32_or5 = s_cla32_pg_logic3_and0 | s_cla32_or4;
  assign s_cla32_pg_logic4_or0 = a[4] | b[4];
  assign s_cla32_pg_logic4_and0 = a[4] & b[4];
  assign s_cla32_pg_logic4_xor0 = a[4] ^ b[4];
  assign s_cla32_xor4 = s_cla32_pg_logic4_xor0 ^ s_cla32_or5;
  assign s_cla32_and12 = s_cla32_or5 & s_cla32_pg_logic4_or0;
  assign s_cla32_or6 = s_cla32_pg_logic4_and0 | s_cla32_and12;
  assign s_cla32_pg_logic5_or0 = a[5] | b[5];
  assign s_cla32_pg_logic5_and0 = a[5] & b[5];
  assign s_cla32_pg_logic5_xor0 = a[5] ^ b[5];
  assign s_cla32_xor5 = s_cla32_pg_logic5_xor0 ^ s_cla32_or6;
  assign s_cla32_and13 = s_cla32_or5 & s_cla32_pg_logic5_or0;
  assign s_cla32_and14 = s_cla32_and13 & s_cla32_pg_logic4_or0;
  assign s_cla32_and15 = s_cla32_pg_logic4_and0 & s_cla32_pg_logic5_or0;
  assign s_cla32_or7 = s_cla32_and14 | s_cla32_and15;
  assign s_cla32_or8 = s_cla32_pg_logic5_and0 | s_cla32_or7;
  assign s_cla32_pg_logic6_or0 = a[6] | b[6];
  assign s_cla32_pg_logic6_and0 = a[6] & b[6];
  assign s_cla32_pg_logic6_xor0 = a[6] ^ b[6];
  assign s_cla32_xor6 = s_cla32_pg_logic6_xor0 ^ s_cla32_or8;
  assign s_cla32_and16 = s_cla32_or5 & s_cla32_pg_logic5_or0;
  assign s_cla32_and17 = s_cla32_pg_logic6_or0 & s_cla32_pg_logic4_or0;
  assign s_cla32_and18 = s_cla32_and16 & s_cla32_and17;
  assign s_cla32_and19 = s_cla32_pg_logic4_and0 & s_cla32_pg_logic6_or0;
  assign s_cla32_and20 = s_cla32_and19 & s_cla32_pg_logic5_or0;
  assign s_cla32_and21 = s_cla32_pg_logic5_and0 & s_cla32_pg_logic6_or0;
  assign s_cla32_or9 = s_cla32_and18 | s_cla32_and20;
  assign s_cla32_or10 = s_cla32_or9 | s_cla32_and21;
  assign s_cla32_or11 = s_cla32_pg_logic6_and0 | s_cla32_or10;
  assign s_cla32_pg_logic7_or0 = a[7] | b[7];
  assign s_cla32_pg_logic7_and0 = a[7] & b[7];
  assign s_cla32_pg_logic7_xor0 = a[7] ^ b[7];
  assign s_cla32_xor7 = s_cla32_pg_logic7_xor0 ^ s_cla32_or11;
  assign s_cla32_and22 = s_cla32_or5 & s_cla32_pg_logic6_or0;
  assign s_cla32_and23 = s_cla32_pg_logic7_or0 & s_cla32_pg_logic5_or0;
  assign s_cla32_and24 = s_cla32_and22 & s_cla32_and23;
  assign s_cla32_and25 = s_cla32_and24 & s_cla32_pg_logic4_or0;
  assign s_cla32_and26 = s_cla32_pg_logic4_and0 & s_cla32_pg_logic6_or0;
  assign s_cla32_and27 = s_cla32_pg_logic7_or0 & s_cla32_pg_logic5_or0;
  assign s_cla32_and28 = s_cla32_and26 & s_cla32_and27;
  assign s_cla32_and29 = s_cla32_pg_logic5_and0 & s_cla32_pg_logic7_or0;
  assign s_cla32_and30 = s_cla32_and29 & s_cla32_pg_logic6_or0;
  assign s_cla32_and31 = s_cla32_pg_logic6_and0 & s_cla32_pg_logic7_or0;
  assign s_cla32_or12 = s_cla32_and25 | s_cla32_and30;
  assign s_cla32_or13 = s_cla32_and28 | s_cla32_and31;
  assign s_cla32_or14 = s_cla32_or12 | s_cla32_or13;
  assign s_cla32_or15 = s_cla32_pg_logic7_and0 | s_cla32_or14;
  assign s_cla32_pg_logic8_or0 = a[8] | b[8];
  assign s_cla32_pg_logic8_and0 = a[8] & b[8];
  assign s_cla32_pg_logic8_xor0 = a[8] ^ b[8];
  assign s_cla32_xor8 = s_cla32_pg_logic8_xor0 ^ s_cla32_or15;
  assign s_cla32_and32 = s_cla32_or15 & s_cla32_pg_logic8_or0;
  assign s_cla32_or16 = s_cla32_pg_logic8_and0 | s_cla32_and32;
  assign s_cla32_pg_logic9_or0 = a[9] | b[9];
  assign s_cla32_pg_logic9_and0 = a[9] & b[9];
  assign s_cla32_pg_logic9_xor0 = a[9] ^ b[9];
  assign s_cla32_xor9 = s_cla32_pg_logic9_xor0 ^ s_cla32_or16;
  assign s_cla32_and33 = s_cla32_or15 & s_cla32_pg_logic9_or0;
  assign s_cla32_and34 = s_cla32_and33 & s_cla32_pg_logic8_or0;
  assign s_cla32_and35 = s_cla32_pg_logic8_and0 & s_cla32_pg_logic9_or0;
  assign s_cla32_or17 = s_cla32_and34 | s_cla32_and35;
  assign s_cla32_or18 = s_cla32_pg_logic9_and0 | s_cla32_or17;
  assign s_cla32_pg_logic10_or0 = a[10] | b[10];
  assign s_cla32_pg_logic10_and0 = a[10] & b[10];
  assign s_cla32_pg_logic10_xor0 = a[10] ^ b[10];
  assign s_cla32_xor10 = s_cla32_pg_logic10_xor0 ^ s_cla32_or18;
  assign s_cla32_and36 = s_cla32_or15 & s_cla32_pg_logic9_or0;
  assign s_cla32_and37 = s_cla32_pg_logic10_or0 & s_cla32_pg_logic8_or0;
  assign s_cla32_and38 = s_cla32_and36 & s_cla32_and37;
  assign s_cla32_and39 = s_cla32_pg_logic8_and0 & s_cla32_pg_logic10_or0;
  assign s_cla32_and40 = s_cla32_and39 & s_cla32_pg_logic9_or0;
  assign s_cla32_and41 = s_cla32_pg_logic9_and0 & s_cla32_pg_logic10_or0;
  assign s_cla32_or19 = s_cla32_and38 | s_cla32_and40;
  assign s_cla32_or20 = s_cla32_or19 | s_cla32_and41;
  assign s_cla32_or21 = s_cla32_pg_logic10_and0 | s_cla32_or20;
  assign s_cla32_pg_logic11_or0 = a[11] | b[11];
  assign s_cla32_pg_logic11_and0 = a[11] & b[11];
  assign s_cla32_pg_logic11_xor0 = a[11] ^ b[11];
  assign s_cla32_xor11 = s_cla32_pg_logic11_xor0 ^ s_cla32_or21;
  assign s_cla32_and42 = s_cla32_or15 & s_cla32_pg_logic10_or0;
  assign s_cla32_and43 = s_cla32_pg_logic11_or0 & s_cla32_pg_logic9_or0;
  assign s_cla32_and44 = s_cla32_and42 & s_cla32_and43;
  assign s_cla32_and45 = s_cla32_and44 & s_cla32_pg_logic8_or0;
  assign s_cla32_and46 = s_cla32_pg_logic8_and0 & s_cla32_pg_logic10_or0;
  assign s_cla32_and47 = s_cla32_pg_logic11_or0 & s_cla32_pg_logic9_or0;
  assign s_cla32_and48 = s_cla32_and46 & s_cla32_and47;
  assign s_cla32_and49 = s_cla32_pg_logic9_and0 & s_cla32_pg_logic11_or0;
  assign s_cla32_and50 = s_cla32_and49 & s_cla32_pg_logic10_or0;
  assign s_cla32_and51 = s_cla32_pg_logic10_and0 & s_cla32_pg_logic11_or0;
  assign s_cla32_or22 = s_cla32_and45 | s_cla32_and50;
  assign s_cla32_or23 = s_cla32_and48 | s_cla32_and51;
  assign s_cla32_or24 = s_cla32_or22 | s_cla32_or23;
  assign s_cla32_or25 = s_cla32_pg_logic11_and0 | s_cla32_or24;
  assign s_cla32_pg_logic12_or0 = a[12] | b[12];
  assign s_cla32_pg_logic12_and0 = a[12] & b[12];
  assign s_cla32_pg_logic12_xor0 = a[12] ^ b[12];
  assign s_cla32_xor12 = s_cla32_pg_logic12_xor0 ^ s_cla32_or25;
  assign s_cla32_and52 = s_cla32_or25 & s_cla32_pg_logic12_or0;
  assign s_cla32_or26 = s_cla32_pg_logic12_and0 | s_cla32_and52;
  assign s_cla32_pg_logic13_or0 = a[13] | b[13];
  assign s_cla32_pg_logic13_and0 = a[13] & b[13];
  assign s_cla32_pg_logic13_xor0 = a[13] ^ b[13];
  assign s_cla32_xor13 = s_cla32_pg_logic13_xor0 ^ s_cla32_or26;
  assign s_cla32_and53 = s_cla32_or25 & s_cla32_pg_logic13_or0;
  assign s_cla32_and54 = s_cla32_and53 & s_cla32_pg_logic12_or0;
  assign s_cla32_and55 = s_cla32_pg_logic12_and0 & s_cla32_pg_logic13_or0;
  assign s_cla32_or27 = s_cla32_and54 | s_cla32_and55;
  assign s_cla32_or28 = s_cla32_pg_logic13_and0 | s_cla32_or27;
  assign s_cla32_pg_logic14_or0 = a[14] | b[14];
  assign s_cla32_pg_logic14_and0 = a[14] & b[14];
  assign s_cla32_pg_logic14_xor0 = a[14] ^ b[14];
  assign s_cla32_xor14 = s_cla32_pg_logic14_xor0 ^ s_cla32_or28;
  assign s_cla32_and56 = s_cla32_or25 & s_cla32_pg_logic13_or0;
  assign s_cla32_and57 = s_cla32_pg_logic14_or0 & s_cla32_pg_logic12_or0;
  assign s_cla32_and58 = s_cla32_and56 & s_cla32_and57;
  assign s_cla32_and59 = s_cla32_pg_logic12_and0 & s_cla32_pg_logic14_or0;
  assign s_cla32_and60 = s_cla32_and59 & s_cla32_pg_logic13_or0;
  assign s_cla32_and61 = s_cla32_pg_logic13_and0 & s_cla32_pg_logic14_or0;
  assign s_cla32_or29 = s_cla32_and58 | s_cla32_and60;
  assign s_cla32_or30 = s_cla32_or29 | s_cla32_and61;
  assign s_cla32_or31 = s_cla32_pg_logic14_and0 | s_cla32_or30;
  assign s_cla32_pg_logic15_or0 = a[15] | b[15];
  assign s_cla32_pg_logic15_and0 = a[15] & b[15];
  assign s_cla32_pg_logic15_xor0 = a[15] ^ b[15];
  assign s_cla32_xor15 = s_cla32_pg_logic15_xor0 ^ s_cla32_or31;
  assign s_cla32_and62 = s_cla32_or25 & s_cla32_pg_logic14_or0;
  assign s_cla32_and63 = s_cla32_pg_logic15_or0 & s_cla32_pg_logic13_or0;
  assign s_cla32_and64 = s_cla32_and62 & s_cla32_and63;
  assign s_cla32_and65 = s_cla32_and64 & s_cla32_pg_logic12_or0;
  assign s_cla32_and66 = s_cla32_pg_logic12_and0 & s_cla32_pg_logic14_or0;
  assign s_cla32_and67 = s_cla32_pg_logic15_or0 & s_cla32_pg_logic13_or0;
  assign s_cla32_and68 = s_cla32_and66 & s_cla32_and67;
  assign s_cla32_and69 = s_cla32_pg_logic13_and0 & s_cla32_pg_logic15_or0;
  assign s_cla32_and70 = s_cla32_and69 & s_cla32_pg_logic14_or0;
  assign s_cla32_and71 = s_cla32_pg_logic14_and0 & s_cla32_pg_logic15_or0;
  assign s_cla32_or32 = s_cla32_and65 | s_cla32_and70;
  assign s_cla32_or33 = s_cla32_and68 | s_cla32_and71;
  assign s_cla32_or34 = s_cla32_or32 | s_cla32_or33;
  assign s_cla32_or35 = s_cla32_pg_logic15_and0 | s_cla32_or34;
  assign s_cla32_pg_logic16_or0 = a[16] | b[16];
  assign s_cla32_pg_logic16_and0 = a[16] & b[16];
  assign s_cla32_pg_logic16_xor0 = a[16] ^ b[16];
  assign s_cla32_xor16 = s_cla32_pg_logic16_xor0 ^ s_cla32_or35;
  assign s_cla32_and72 = s_cla32_or35 & s_cla32_pg_logic16_or0;
  assign s_cla32_or36 = s_cla32_pg_logic16_and0 | s_cla32_and72;
  assign s_cla32_pg_logic17_or0 = a[17] | b[17];
  assign s_cla32_pg_logic17_and0 = a[17] & b[17];
  assign s_cla32_pg_logic17_xor0 = a[17] ^ b[17];
  assign s_cla32_xor17 = s_cla32_pg_logic17_xor0 ^ s_cla32_or36;
  assign s_cla32_and73 = s_cla32_or35 & s_cla32_pg_logic17_or0;
  assign s_cla32_and74 = s_cla32_and73 & s_cla32_pg_logic16_or0;
  assign s_cla32_and75 = s_cla32_pg_logic16_and0 & s_cla32_pg_logic17_or0;
  assign s_cla32_or37 = s_cla32_and74 | s_cla32_and75;
  assign s_cla32_or38 = s_cla32_pg_logic17_and0 | s_cla32_or37;
  assign s_cla32_pg_logic18_or0 = a[18] | b[18];
  assign s_cla32_pg_logic18_and0 = a[18] & b[18];
  assign s_cla32_pg_logic18_xor0 = a[18] ^ b[18];
  assign s_cla32_xor18 = s_cla32_pg_logic18_xor0 ^ s_cla32_or38;
  assign s_cla32_and76 = s_cla32_or35 & s_cla32_pg_logic17_or0;
  assign s_cla32_and77 = s_cla32_pg_logic18_or0 & s_cla32_pg_logic16_or0;
  assign s_cla32_and78 = s_cla32_and76 & s_cla32_and77;
  assign s_cla32_and79 = s_cla32_pg_logic16_and0 & s_cla32_pg_logic18_or0;
  assign s_cla32_and80 = s_cla32_and79 & s_cla32_pg_logic17_or0;
  assign s_cla32_and81 = s_cla32_pg_logic17_and0 & s_cla32_pg_logic18_or0;
  assign s_cla32_or39 = s_cla32_and78 | s_cla32_and80;
  assign s_cla32_or40 = s_cla32_or39 | s_cla32_and81;
  assign s_cla32_or41 = s_cla32_pg_logic18_and0 | s_cla32_or40;
  assign s_cla32_pg_logic19_or0 = a[19] | b[19];
  assign s_cla32_pg_logic19_and0 = a[19] & b[19];
  assign s_cla32_pg_logic19_xor0 = a[19] ^ b[19];
  assign s_cla32_xor19 = s_cla32_pg_logic19_xor0 ^ s_cla32_or41;
  assign s_cla32_and82 = s_cla32_or35 & s_cla32_pg_logic18_or0;
  assign s_cla32_and83 = s_cla32_pg_logic19_or0 & s_cla32_pg_logic17_or0;
  assign s_cla32_and84 = s_cla32_and82 & s_cla32_and83;
  assign s_cla32_and85 = s_cla32_and84 & s_cla32_pg_logic16_or0;
  assign s_cla32_and86 = s_cla32_pg_logic16_and0 & s_cla32_pg_logic18_or0;
  assign s_cla32_and87 = s_cla32_pg_logic19_or0 & s_cla32_pg_logic17_or0;
  assign s_cla32_and88 = s_cla32_and86 & s_cla32_and87;
  assign s_cla32_and89 = s_cla32_pg_logic17_and0 & s_cla32_pg_logic19_or0;
  assign s_cla32_and90 = s_cla32_and89 & s_cla32_pg_logic18_or0;
  assign s_cla32_and91 = s_cla32_pg_logic18_and0 & s_cla32_pg_logic19_or0;
  assign s_cla32_or42 = s_cla32_and85 | s_cla32_and90;
  assign s_cla32_or43 = s_cla32_and88 | s_cla32_and91;
  assign s_cla32_or44 = s_cla32_or42 | s_cla32_or43;
  assign s_cla32_or45 = s_cla32_pg_logic19_and0 | s_cla32_or44;
  assign s_cla32_pg_logic20_or0 = a[20] | b[20];
  assign s_cla32_pg_logic20_and0 = a[20] & b[20];
  assign s_cla32_pg_logic20_xor0 = a[20] ^ b[20];
  assign s_cla32_xor20 = s_cla32_pg_logic20_xor0 ^ s_cla32_or45;
  assign s_cla32_and92 = s_cla32_or45 & s_cla32_pg_logic20_or0;
  assign s_cla32_or46 = s_cla32_pg_logic20_and0 | s_cla32_and92;
  assign s_cla32_pg_logic21_or0 = a[21] | b[21];
  assign s_cla32_pg_logic21_and0 = a[21] & b[21];
  assign s_cla32_pg_logic21_xor0 = a[21] ^ b[21];
  assign s_cla32_xor21 = s_cla32_pg_logic21_xor0 ^ s_cla32_or46;
  assign s_cla32_and93 = s_cla32_or45 & s_cla32_pg_logic21_or0;
  assign s_cla32_and94 = s_cla32_and93 & s_cla32_pg_logic20_or0;
  assign s_cla32_and95 = s_cla32_pg_logic20_and0 & s_cla32_pg_logic21_or0;
  assign s_cla32_or47 = s_cla32_and94 | s_cla32_and95;
  assign s_cla32_or48 = s_cla32_pg_logic21_and0 | s_cla32_or47;
  assign s_cla32_pg_logic22_or0 = a[22] | b[22];
  assign s_cla32_pg_logic22_and0 = a[22] & b[22];
  assign s_cla32_pg_logic22_xor0 = a[22] ^ b[22];
  assign s_cla32_xor22 = s_cla32_pg_logic22_xor0 ^ s_cla32_or48;
  assign s_cla32_and96 = s_cla32_or45 & s_cla32_pg_logic21_or0;
  assign s_cla32_and97 = s_cla32_pg_logic22_or0 & s_cla32_pg_logic20_or0;
  assign s_cla32_and98 = s_cla32_and96 & s_cla32_and97;
  assign s_cla32_and99 = s_cla32_pg_logic20_and0 & s_cla32_pg_logic22_or0;
  assign s_cla32_and100 = s_cla32_and99 & s_cla32_pg_logic21_or0;
  assign s_cla32_and101 = s_cla32_pg_logic21_and0 & s_cla32_pg_logic22_or0;
  assign s_cla32_or49 = s_cla32_and98 | s_cla32_and100;
  assign s_cla32_or50 = s_cla32_or49 | s_cla32_and101;
  assign s_cla32_or51 = s_cla32_pg_logic22_and0 | s_cla32_or50;
  assign s_cla32_pg_logic23_or0 = a[23] | b[23];
  assign s_cla32_pg_logic23_and0 = a[23] & b[23];
  assign s_cla32_pg_logic23_xor0 = a[23] ^ b[23];
  assign s_cla32_xor23 = s_cla32_pg_logic23_xor0 ^ s_cla32_or51;
  assign s_cla32_and102 = s_cla32_or45 & s_cla32_pg_logic22_or0;
  assign s_cla32_and103 = s_cla32_pg_logic23_or0 & s_cla32_pg_logic21_or0;
  assign s_cla32_and104 = s_cla32_and102 & s_cla32_and103;
  assign s_cla32_and105 = s_cla32_and104 & s_cla32_pg_logic20_or0;
  assign s_cla32_and106 = s_cla32_pg_logic20_and0 & s_cla32_pg_logic22_or0;
  assign s_cla32_and107 = s_cla32_pg_logic23_or0 & s_cla32_pg_logic21_or0;
  assign s_cla32_and108 = s_cla32_and106 & s_cla32_and107;
  assign s_cla32_and109 = s_cla32_pg_logic21_and0 & s_cla32_pg_logic23_or0;
  assign s_cla32_and110 = s_cla32_and109 & s_cla32_pg_logic22_or0;
  assign s_cla32_and111 = s_cla32_pg_logic22_and0 & s_cla32_pg_logic23_or0;
  assign s_cla32_or52 = s_cla32_and105 | s_cla32_and110;
  assign s_cla32_or53 = s_cla32_and108 | s_cla32_and111;
  assign s_cla32_or54 = s_cla32_or52 | s_cla32_or53;
  assign s_cla32_or55 = s_cla32_pg_logic23_and0 | s_cla32_or54;
  assign s_cla32_pg_logic24_or0 = a[24] | b[24];
  assign s_cla32_pg_logic24_and0 = a[24] & b[24];
  assign s_cla32_pg_logic24_xor0 = a[24] ^ b[24];
  assign s_cla32_xor24 = s_cla32_pg_logic24_xor0 ^ s_cla32_or55;
  assign s_cla32_and112 = s_cla32_or55 & s_cla32_pg_logic24_or0;
  assign s_cla32_or56 = s_cla32_pg_logic24_and0 | s_cla32_and112;
  assign s_cla32_pg_logic25_or0 = a[25] | b[25];
  assign s_cla32_pg_logic25_and0 = a[25] & b[25];
  assign s_cla32_pg_logic25_xor0 = a[25] ^ b[25];
  assign s_cla32_xor25 = s_cla32_pg_logic25_xor0 ^ s_cla32_or56;
  assign s_cla32_and113 = s_cla32_or55 & s_cla32_pg_logic25_or0;
  assign s_cla32_and114 = s_cla32_and113 & s_cla32_pg_logic24_or0;
  assign s_cla32_and115 = s_cla32_pg_logic24_and0 & s_cla32_pg_logic25_or0;
  assign s_cla32_or57 = s_cla32_and114 | s_cla32_and115;
  assign s_cla32_or58 = s_cla32_pg_logic25_and0 | s_cla32_or57;
  assign s_cla32_pg_logic26_or0 = a[26] | b[26];
  assign s_cla32_pg_logic26_and0 = a[26] & b[26];
  assign s_cla32_pg_logic26_xor0 = a[26] ^ b[26];
  assign s_cla32_xor26 = s_cla32_pg_logic26_xor0 ^ s_cla32_or58;
  assign s_cla32_and116 = s_cla32_or55 & s_cla32_pg_logic25_or0;
  assign s_cla32_and117 = s_cla32_pg_logic26_or0 & s_cla32_pg_logic24_or0;
  assign s_cla32_and118 = s_cla32_and116 & s_cla32_and117;
  assign s_cla32_and119 = s_cla32_pg_logic24_and0 & s_cla32_pg_logic26_or0;
  assign s_cla32_and120 = s_cla32_and119 & s_cla32_pg_logic25_or0;
  assign s_cla32_and121 = s_cla32_pg_logic25_and0 & s_cla32_pg_logic26_or0;
  assign s_cla32_or59 = s_cla32_and118 | s_cla32_and120;
  assign s_cla32_or60 = s_cla32_or59 | s_cla32_and121;
  assign s_cla32_or61 = s_cla32_pg_logic26_and0 | s_cla32_or60;
  assign s_cla32_pg_logic27_or0 = a[27] | b[27];
  assign s_cla32_pg_logic27_and0 = a[27] & b[27];
  assign s_cla32_pg_logic27_xor0 = a[27] ^ b[27];
  assign s_cla32_xor27 = s_cla32_pg_logic27_xor0 ^ s_cla32_or61;
  assign s_cla32_and122 = s_cla32_or55 & s_cla32_pg_logic26_or0;
  assign s_cla32_and123 = s_cla32_pg_logic27_or0 & s_cla32_pg_logic25_or0;
  assign s_cla32_and124 = s_cla32_and122 & s_cla32_and123;
  assign s_cla32_and125 = s_cla32_and124 & s_cla32_pg_logic24_or0;
  assign s_cla32_and126 = s_cla32_pg_logic24_and0 & s_cla32_pg_logic26_or0;
  assign s_cla32_and127 = s_cla32_pg_logic27_or0 & s_cla32_pg_logic25_or0;
  assign s_cla32_and128 = s_cla32_and126 & s_cla32_and127;
  assign s_cla32_and129 = s_cla32_pg_logic25_and0 & s_cla32_pg_logic27_or0;
  assign s_cla32_and130 = s_cla32_and129 & s_cla32_pg_logic26_or0;
  assign s_cla32_and131 = s_cla32_pg_logic26_and0 & s_cla32_pg_logic27_or0;
  assign s_cla32_or62 = s_cla32_and125 | s_cla32_and130;
  assign s_cla32_or63 = s_cla32_and128 | s_cla32_and131;
  assign s_cla32_or64 = s_cla32_or62 | s_cla32_or63;
  assign s_cla32_or65 = s_cla32_pg_logic27_and0 | s_cla32_or64;
  assign s_cla32_pg_logic28_or0 = a[28] | b[28];
  assign s_cla32_pg_logic28_and0 = a[28] & b[28];
  assign s_cla32_pg_logic28_xor0 = a[28] ^ b[28];
  assign s_cla32_xor28 = s_cla32_pg_logic28_xor0 ^ s_cla32_or65;
  assign s_cla32_and132 = s_cla32_or65 & s_cla32_pg_logic28_or0;
  assign s_cla32_or66 = s_cla32_pg_logic28_and0 | s_cla32_and132;
  assign s_cla32_pg_logic29_or0 = a[29] | b[29];
  assign s_cla32_pg_logic29_and0 = a[29] & b[29];
  assign s_cla32_pg_logic29_xor0 = a[29] ^ b[29];
  assign s_cla32_xor29 = s_cla32_pg_logic29_xor0 ^ s_cla32_or66;
  assign s_cla32_and133 = s_cla32_or65 & s_cla32_pg_logic29_or0;
  assign s_cla32_and134 = s_cla32_and133 & s_cla32_pg_logic28_or0;
  assign s_cla32_and135 = s_cla32_pg_logic28_and0 & s_cla32_pg_logic29_or0;
  assign s_cla32_or67 = s_cla32_and134 | s_cla32_and135;
  assign s_cla32_or68 = s_cla32_pg_logic29_and0 | s_cla32_or67;
  assign s_cla32_pg_logic30_or0 = a[30] | b[30];
  assign s_cla32_pg_logic30_and0 = a[30] & b[30];
  assign s_cla32_pg_logic30_xor0 = a[30] ^ b[30];
  assign s_cla32_xor30 = s_cla32_pg_logic30_xor0 ^ s_cla32_or68;
  assign s_cla32_and136 = s_cla32_or65 & s_cla32_pg_logic29_or0;
  assign s_cla32_and137 = s_cla32_pg_logic30_or0 & s_cla32_pg_logic28_or0;
  assign s_cla32_and138 = s_cla32_and136 & s_cla32_and137;
  assign s_cla32_and139 = s_cla32_pg_logic28_and0 & s_cla32_pg_logic30_or0;
  assign s_cla32_and140 = s_cla32_and139 & s_cla32_pg_logic29_or0;
  assign s_cla32_and141 = s_cla32_pg_logic29_and0 & s_cla32_pg_logic30_or0;
  assign s_cla32_or69 = s_cla32_and138 | s_cla32_and140;
  assign s_cla32_or70 = s_cla32_or69 | s_cla32_and141;
  assign s_cla32_or71 = s_cla32_pg_logic30_and0 | s_cla32_or70;
  assign s_cla32_pg_logic31_or0 = a[31] | b[31];
  assign s_cla32_pg_logic31_and0 = a[31] & b[31];
  assign s_cla32_pg_logic31_xor0 = a[31] ^ b[31];
  assign s_cla32_xor31 = s_cla32_pg_logic31_xor0 ^ s_cla32_or71;
  assign s_cla32_and142 = s_cla32_or65 & s_cla32_pg_logic30_or0;
  assign s_cla32_and143 = s_cla32_pg_logic31_or0 & s_cla32_pg_logic29_or0;
  assign s_cla32_and144 = s_cla32_and142 & s_cla32_and143;
  assign s_cla32_and145 = s_cla32_and144 & s_cla32_pg_logic28_or0;
  assign s_cla32_and146 = s_cla32_pg_logic28_and0 & s_cla32_pg_logic30_or0;
  assign s_cla32_and147 = s_cla32_pg_logic31_or0 & s_cla32_pg_logic29_or0;
  assign s_cla32_and148 = s_cla32_and146 & s_cla32_and147;
  assign s_cla32_and149 = s_cla32_pg_logic29_and0 & s_cla32_pg_logic31_or0;
  assign s_cla32_and150 = s_cla32_and149 & s_cla32_pg_logic30_or0;
  assign s_cla32_and151 = s_cla32_pg_logic30_and0 & s_cla32_pg_logic31_or0;
  assign s_cla32_or72 = s_cla32_and145 | s_cla32_and150;
  assign s_cla32_or73 = s_cla32_and148 | s_cla32_and151;
  assign s_cla32_or74 = s_cla32_or72 | s_cla32_or73;
  assign s_cla32_or75 = s_cla32_pg_logic31_and0 | s_cla32_or74;
  assign s_cla32_xor32 = a[31] ^ b[31];
  assign s_cla32_xor33 = s_cla32_xor32 ^ s_cla32_or75;

  assign s_cla32_out[0] = s_cla32_pg_logic0_xor0;
  assign s_cla32_out[1] = s_cla32_xor1;
  assign s_cla32_out[2] = s_cla32_xor2;
  assign s_cla32_out[3] = s_cla32_xor3;
  assign s_cla32_out[4] = s_cla32_xor4;
  assign s_cla32_out[5] = s_cla32_xor5;
  assign s_cla32_out[6] = s_cla32_xor6;
  assign s_cla32_out[7] = s_cla32_xor7;
  assign s_cla32_out[8] = s_cla32_xor8;
  assign s_cla32_out[9] = s_cla32_xor9;
  assign s_cla32_out[10] = s_cla32_xor10;
  assign s_cla32_out[11] = s_cla32_xor11;
  assign s_cla32_out[12] = s_cla32_xor12;
  assign s_cla32_out[13] = s_cla32_xor13;
  assign s_cla32_out[14] = s_cla32_xor14;
  assign s_cla32_out[15] = s_cla32_xor15;
  assign s_cla32_out[16] = s_cla32_xor16;
  assign s_cla32_out[17] = s_cla32_xor17;
  assign s_cla32_out[18] = s_cla32_xor18;
  assign s_cla32_out[19] = s_cla32_xor19;
  assign s_cla32_out[20] = s_cla32_xor20;
  assign s_cla32_out[21] = s_cla32_xor21;
  assign s_cla32_out[22] = s_cla32_xor22;
  assign s_cla32_out[23] = s_cla32_xor23;
  assign s_cla32_out[24] = s_cla32_xor24;
  assign s_cla32_out[25] = s_cla32_xor25;
  assign s_cla32_out[26] = s_cla32_xor26;
  assign s_cla32_out[27] = s_cla32_xor27;
  assign s_cla32_out[28] = s_cla32_xor28;
  assign s_cla32_out[29] = s_cla32_xor29;
  assign s_cla32_out[30] = s_cla32_xor30;
  assign s_cla32_out[31] = s_cla32_xor31;
  assign s_cla32_out[32] = s_cla32_xor33;
endmodule