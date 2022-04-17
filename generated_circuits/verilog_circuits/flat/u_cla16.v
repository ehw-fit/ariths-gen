module u_cla16(input [15:0] a, input [15:0] b, output [16:0] u_cla16_out);
  wire u_cla16_pg_logic0_or0;
  wire u_cla16_pg_logic0_and0;
  wire u_cla16_pg_logic0_xor0;
  wire u_cla16_pg_logic1_or0;
  wire u_cla16_pg_logic1_and0;
  wire u_cla16_pg_logic1_xor0;
  wire u_cla16_xor1;
  wire u_cla16_and0;
  wire u_cla16_or0;
  wire u_cla16_pg_logic2_or0;
  wire u_cla16_pg_logic2_and0;
  wire u_cla16_pg_logic2_xor0;
  wire u_cla16_xor2;
  wire u_cla16_and1;
  wire u_cla16_and2;
  wire u_cla16_and3;
  wire u_cla16_and4;
  wire u_cla16_or1;
  wire u_cla16_or2;
  wire u_cla16_pg_logic3_or0;
  wire u_cla16_pg_logic3_and0;
  wire u_cla16_pg_logic3_xor0;
  wire u_cla16_xor3;
  wire u_cla16_and5;
  wire u_cla16_and6;
  wire u_cla16_and7;
  wire u_cla16_and8;
  wire u_cla16_and9;
  wire u_cla16_and10;
  wire u_cla16_and11;
  wire u_cla16_or3;
  wire u_cla16_or4;
  wire u_cla16_or5;
  wire u_cla16_pg_logic4_or0;
  wire u_cla16_pg_logic4_and0;
  wire u_cla16_pg_logic4_xor0;
  wire u_cla16_xor4;
  wire u_cla16_and12;
  wire u_cla16_or6;
  wire u_cla16_pg_logic5_or0;
  wire u_cla16_pg_logic5_and0;
  wire u_cla16_pg_logic5_xor0;
  wire u_cla16_xor5;
  wire u_cla16_and13;
  wire u_cla16_and14;
  wire u_cla16_and15;
  wire u_cla16_or7;
  wire u_cla16_or8;
  wire u_cla16_pg_logic6_or0;
  wire u_cla16_pg_logic6_and0;
  wire u_cla16_pg_logic6_xor0;
  wire u_cla16_xor6;
  wire u_cla16_and16;
  wire u_cla16_and17;
  wire u_cla16_and18;
  wire u_cla16_and19;
  wire u_cla16_and20;
  wire u_cla16_and21;
  wire u_cla16_or9;
  wire u_cla16_or10;
  wire u_cla16_or11;
  wire u_cla16_pg_logic7_or0;
  wire u_cla16_pg_logic7_and0;
  wire u_cla16_pg_logic7_xor0;
  wire u_cla16_xor7;
  wire u_cla16_and22;
  wire u_cla16_and23;
  wire u_cla16_and24;
  wire u_cla16_and25;
  wire u_cla16_and26;
  wire u_cla16_and27;
  wire u_cla16_and28;
  wire u_cla16_and29;
  wire u_cla16_and30;
  wire u_cla16_and31;
  wire u_cla16_or12;
  wire u_cla16_or13;
  wire u_cla16_or14;
  wire u_cla16_or15;
  wire u_cla16_pg_logic8_or0;
  wire u_cla16_pg_logic8_and0;
  wire u_cla16_pg_logic8_xor0;
  wire u_cla16_xor8;
  wire u_cla16_and32;
  wire u_cla16_or16;
  wire u_cla16_pg_logic9_or0;
  wire u_cla16_pg_logic9_and0;
  wire u_cla16_pg_logic9_xor0;
  wire u_cla16_xor9;
  wire u_cla16_and33;
  wire u_cla16_and34;
  wire u_cla16_and35;
  wire u_cla16_or17;
  wire u_cla16_or18;
  wire u_cla16_pg_logic10_or0;
  wire u_cla16_pg_logic10_and0;
  wire u_cla16_pg_logic10_xor0;
  wire u_cla16_xor10;
  wire u_cla16_and36;
  wire u_cla16_and37;
  wire u_cla16_and38;
  wire u_cla16_and39;
  wire u_cla16_and40;
  wire u_cla16_and41;
  wire u_cla16_or19;
  wire u_cla16_or20;
  wire u_cla16_or21;
  wire u_cla16_pg_logic11_or0;
  wire u_cla16_pg_logic11_and0;
  wire u_cla16_pg_logic11_xor0;
  wire u_cla16_xor11;
  wire u_cla16_and42;
  wire u_cla16_and43;
  wire u_cla16_and44;
  wire u_cla16_and45;
  wire u_cla16_and46;
  wire u_cla16_and47;
  wire u_cla16_and48;
  wire u_cla16_and49;
  wire u_cla16_and50;
  wire u_cla16_and51;
  wire u_cla16_or22;
  wire u_cla16_or23;
  wire u_cla16_or24;
  wire u_cla16_or25;
  wire u_cla16_pg_logic12_or0;
  wire u_cla16_pg_logic12_and0;
  wire u_cla16_pg_logic12_xor0;
  wire u_cla16_xor12;
  wire u_cla16_and52;
  wire u_cla16_or26;
  wire u_cla16_pg_logic13_or0;
  wire u_cla16_pg_logic13_and0;
  wire u_cla16_pg_logic13_xor0;
  wire u_cla16_xor13;
  wire u_cla16_and53;
  wire u_cla16_and54;
  wire u_cla16_and55;
  wire u_cla16_or27;
  wire u_cla16_or28;
  wire u_cla16_pg_logic14_or0;
  wire u_cla16_pg_logic14_and0;
  wire u_cla16_pg_logic14_xor0;
  wire u_cla16_xor14;
  wire u_cla16_and56;
  wire u_cla16_and57;
  wire u_cla16_and58;
  wire u_cla16_and59;
  wire u_cla16_and60;
  wire u_cla16_and61;
  wire u_cla16_or29;
  wire u_cla16_or30;
  wire u_cla16_or31;
  wire u_cla16_pg_logic15_or0;
  wire u_cla16_pg_logic15_and0;
  wire u_cla16_pg_logic15_xor0;
  wire u_cla16_xor15;
  wire u_cla16_and62;
  wire u_cla16_and63;
  wire u_cla16_and64;
  wire u_cla16_and65;
  wire u_cla16_and66;
  wire u_cla16_and67;
  wire u_cla16_and68;
  wire u_cla16_and69;
  wire u_cla16_and70;
  wire u_cla16_and71;
  wire u_cla16_or32;
  wire u_cla16_or33;
  wire u_cla16_or34;
  wire u_cla16_or35;

  assign u_cla16_pg_logic0_or0 = a[0] | b[0];
  assign u_cla16_pg_logic0_and0 = a[0] & b[0];
  assign u_cla16_pg_logic0_xor0 = a[0] ^ b[0];
  assign u_cla16_pg_logic1_or0 = a[1] | b[1];
  assign u_cla16_pg_logic1_and0 = a[1] & b[1];
  assign u_cla16_pg_logic1_xor0 = a[1] ^ b[1];
  assign u_cla16_xor1 = u_cla16_pg_logic1_xor0 ^ u_cla16_pg_logic0_and0;
  assign u_cla16_and0 = u_cla16_pg_logic0_and0 & u_cla16_pg_logic1_or0;
  assign u_cla16_or0 = u_cla16_pg_logic1_and0 | u_cla16_and0;
  assign u_cla16_pg_logic2_or0 = a[2] | b[2];
  assign u_cla16_pg_logic2_and0 = a[2] & b[2];
  assign u_cla16_pg_logic2_xor0 = a[2] ^ b[2];
  assign u_cla16_xor2 = u_cla16_pg_logic2_xor0 ^ u_cla16_or0;
  assign u_cla16_and1 = u_cla16_pg_logic2_or0 & u_cla16_pg_logic0_or0;
  assign u_cla16_and2 = u_cla16_pg_logic0_and0 & u_cla16_pg_logic2_or0;
  assign u_cla16_and3 = u_cla16_and2 & u_cla16_pg_logic1_or0;
  assign u_cla16_and4 = u_cla16_pg_logic1_and0 & u_cla16_pg_logic2_or0;
  assign u_cla16_or1 = u_cla16_and3 | u_cla16_and4;
  assign u_cla16_or2 = u_cla16_pg_logic2_and0 | u_cla16_or1;
  assign u_cla16_pg_logic3_or0 = a[3] | b[3];
  assign u_cla16_pg_logic3_and0 = a[3] & b[3];
  assign u_cla16_pg_logic3_xor0 = a[3] ^ b[3];
  assign u_cla16_xor3 = u_cla16_pg_logic3_xor0 ^ u_cla16_or2;
  assign u_cla16_and5 = u_cla16_pg_logic3_or0 & u_cla16_pg_logic1_or0;
  assign u_cla16_and6 = u_cla16_pg_logic0_and0 & u_cla16_pg_logic2_or0;
  assign u_cla16_and7 = u_cla16_pg_logic3_or0 & u_cla16_pg_logic1_or0;
  assign u_cla16_and8 = u_cla16_and6 & u_cla16_and7;
  assign u_cla16_and9 = u_cla16_pg_logic1_and0 & u_cla16_pg_logic3_or0;
  assign u_cla16_and10 = u_cla16_and9 & u_cla16_pg_logic2_or0;
  assign u_cla16_and11 = u_cla16_pg_logic2_and0 & u_cla16_pg_logic3_or0;
  assign u_cla16_or3 = u_cla16_and8 | u_cla16_and11;
  assign u_cla16_or4 = u_cla16_and10 | u_cla16_or3;
  assign u_cla16_or5 = u_cla16_pg_logic3_and0 | u_cla16_or4;
  assign u_cla16_pg_logic4_or0 = a[4] | b[4];
  assign u_cla16_pg_logic4_and0 = a[4] & b[4];
  assign u_cla16_pg_logic4_xor0 = a[4] ^ b[4];
  assign u_cla16_xor4 = u_cla16_pg_logic4_xor0 ^ u_cla16_or5;
  assign u_cla16_and12 = u_cla16_or5 & u_cla16_pg_logic4_or0;
  assign u_cla16_or6 = u_cla16_pg_logic4_and0 | u_cla16_and12;
  assign u_cla16_pg_logic5_or0 = a[5] | b[5];
  assign u_cla16_pg_logic5_and0 = a[5] & b[5];
  assign u_cla16_pg_logic5_xor0 = a[5] ^ b[5];
  assign u_cla16_xor5 = u_cla16_pg_logic5_xor0 ^ u_cla16_or6;
  assign u_cla16_and13 = u_cla16_or5 & u_cla16_pg_logic5_or0;
  assign u_cla16_and14 = u_cla16_and13 & u_cla16_pg_logic4_or0;
  assign u_cla16_and15 = u_cla16_pg_logic4_and0 & u_cla16_pg_logic5_or0;
  assign u_cla16_or7 = u_cla16_and14 | u_cla16_and15;
  assign u_cla16_or8 = u_cla16_pg_logic5_and0 | u_cla16_or7;
  assign u_cla16_pg_logic6_or0 = a[6] | b[6];
  assign u_cla16_pg_logic6_and0 = a[6] & b[6];
  assign u_cla16_pg_logic6_xor0 = a[6] ^ b[6];
  assign u_cla16_xor6 = u_cla16_pg_logic6_xor0 ^ u_cla16_or8;
  assign u_cla16_and16 = u_cla16_or5 & u_cla16_pg_logic5_or0;
  assign u_cla16_and17 = u_cla16_pg_logic6_or0 & u_cla16_pg_logic4_or0;
  assign u_cla16_and18 = u_cla16_and16 & u_cla16_and17;
  assign u_cla16_and19 = u_cla16_pg_logic4_and0 & u_cla16_pg_logic6_or0;
  assign u_cla16_and20 = u_cla16_and19 & u_cla16_pg_logic5_or0;
  assign u_cla16_and21 = u_cla16_pg_logic5_and0 & u_cla16_pg_logic6_or0;
  assign u_cla16_or9 = u_cla16_and18 | u_cla16_and20;
  assign u_cla16_or10 = u_cla16_or9 | u_cla16_and21;
  assign u_cla16_or11 = u_cla16_pg_logic6_and0 | u_cla16_or10;
  assign u_cla16_pg_logic7_or0 = a[7] | b[7];
  assign u_cla16_pg_logic7_and0 = a[7] & b[7];
  assign u_cla16_pg_logic7_xor0 = a[7] ^ b[7];
  assign u_cla16_xor7 = u_cla16_pg_logic7_xor0 ^ u_cla16_or11;
  assign u_cla16_and22 = u_cla16_or5 & u_cla16_pg_logic6_or0;
  assign u_cla16_and23 = u_cla16_pg_logic7_or0 & u_cla16_pg_logic5_or0;
  assign u_cla16_and24 = u_cla16_and22 & u_cla16_and23;
  assign u_cla16_and25 = u_cla16_and24 & u_cla16_pg_logic4_or0;
  assign u_cla16_and26 = u_cla16_pg_logic4_and0 & u_cla16_pg_logic6_or0;
  assign u_cla16_and27 = u_cla16_pg_logic7_or0 & u_cla16_pg_logic5_or0;
  assign u_cla16_and28 = u_cla16_and26 & u_cla16_and27;
  assign u_cla16_and29 = u_cla16_pg_logic5_and0 & u_cla16_pg_logic7_or0;
  assign u_cla16_and30 = u_cla16_and29 & u_cla16_pg_logic6_or0;
  assign u_cla16_and31 = u_cla16_pg_logic6_and0 & u_cla16_pg_logic7_or0;
  assign u_cla16_or12 = u_cla16_and25 | u_cla16_and30;
  assign u_cla16_or13 = u_cla16_and28 | u_cla16_and31;
  assign u_cla16_or14 = u_cla16_or12 | u_cla16_or13;
  assign u_cla16_or15 = u_cla16_pg_logic7_and0 | u_cla16_or14;
  assign u_cla16_pg_logic8_or0 = a[8] | b[8];
  assign u_cla16_pg_logic8_and0 = a[8] & b[8];
  assign u_cla16_pg_logic8_xor0 = a[8] ^ b[8];
  assign u_cla16_xor8 = u_cla16_pg_logic8_xor0 ^ u_cla16_or15;
  assign u_cla16_and32 = u_cla16_or15 & u_cla16_pg_logic8_or0;
  assign u_cla16_or16 = u_cla16_pg_logic8_and0 | u_cla16_and32;
  assign u_cla16_pg_logic9_or0 = a[9] | b[9];
  assign u_cla16_pg_logic9_and0 = a[9] & b[9];
  assign u_cla16_pg_logic9_xor0 = a[9] ^ b[9];
  assign u_cla16_xor9 = u_cla16_pg_logic9_xor0 ^ u_cla16_or16;
  assign u_cla16_and33 = u_cla16_or15 & u_cla16_pg_logic9_or0;
  assign u_cla16_and34 = u_cla16_and33 & u_cla16_pg_logic8_or0;
  assign u_cla16_and35 = u_cla16_pg_logic8_and0 & u_cla16_pg_logic9_or0;
  assign u_cla16_or17 = u_cla16_and34 | u_cla16_and35;
  assign u_cla16_or18 = u_cla16_pg_logic9_and0 | u_cla16_or17;
  assign u_cla16_pg_logic10_or0 = a[10] | b[10];
  assign u_cla16_pg_logic10_and0 = a[10] & b[10];
  assign u_cla16_pg_logic10_xor0 = a[10] ^ b[10];
  assign u_cla16_xor10 = u_cla16_pg_logic10_xor0 ^ u_cla16_or18;
  assign u_cla16_and36 = u_cla16_or15 & u_cla16_pg_logic9_or0;
  assign u_cla16_and37 = u_cla16_pg_logic10_or0 & u_cla16_pg_logic8_or0;
  assign u_cla16_and38 = u_cla16_and36 & u_cla16_and37;
  assign u_cla16_and39 = u_cla16_pg_logic8_and0 & u_cla16_pg_logic10_or0;
  assign u_cla16_and40 = u_cla16_and39 & u_cla16_pg_logic9_or0;
  assign u_cla16_and41 = u_cla16_pg_logic9_and0 & u_cla16_pg_logic10_or0;
  assign u_cla16_or19 = u_cla16_and38 | u_cla16_and40;
  assign u_cla16_or20 = u_cla16_or19 | u_cla16_and41;
  assign u_cla16_or21 = u_cla16_pg_logic10_and0 | u_cla16_or20;
  assign u_cla16_pg_logic11_or0 = a[11] | b[11];
  assign u_cla16_pg_logic11_and0 = a[11] & b[11];
  assign u_cla16_pg_logic11_xor0 = a[11] ^ b[11];
  assign u_cla16_xor11 = u_cla16_pg_logic11_xor0 ^ u_cla16_or21;
  assign u_cla16_and42 = u_cla16_or15 & u_cla16_pg_logic10_or0;
  assign u_cla16_and43 = u_cla16_pg_logic11_or0 & u_cla16_pg_logic9_or0;
  assign u_cla16_and44 = u_cla16_and42 & u_cla16_and43;
  assign u_cla16_and45 = u_cla16_and44 & u_cla16_pg_logic8_or0;
  assign u_cla16_and46 = u_cla16_pg_logic8_and0 & u_cla16_pg_logic10_or0;
  assign u_cla16_and47 = u_cla16_pg_logic11_or0 & u_cla16_pg_logic9_or0;
  assign u_cla16_and48 = u_cla16_and46 & u_cla16_and47;
  assign u_cla16_and49 = u_cla16_pg_logic9_and0 & u_cla16_pg_logic11_or0;
  assign u_cla16_and50 = u_cla16_and49 & u_cla16_pg_logic10_or0;
  assign u_cla16_and51 = u_cla16_pg_logic10_and0 & u_cla16_pg_logic11_or0;
  assign u_cla16_or22 = u_cla16_and45 | u_cla16_and50;
  assign u_cla16_or23 = u_cla16_and48 | u_cla16_and51;
  assign u_cla16_or24 = u_cla16_or22 | u_cla16_or23;
  assign u_cla16_or25 = u_cla16_pg_logic11_and0 | u_cla16_or24;
  assign u_cla16_pg_logic12_or0 = a[12] | b[12];
  assign u_cla16_pg_logic12_and0 = a[12] & b[12];
  assign u_cla16_pg_logic12_xor0 = a[12] ^ b[12];
  assign u_cla16_xor12 = u_cla16_pg_logic12_xor0 ^ u_cla16_or25;
  assign u_cla16_and52 = u_cla16_or25 & u_cla16_pg_logic12_or0;
  assign u_cla16_or26 = u_cla16_pg_logic12_and0 | u_cla16_and52;
  assign u_cla16_pg_logic13_or0 = a[13] | b[13];
  assign u_cla16_pg_logic13_and0 = a[13] & b[13];
  assign u_cla16_pg_logic13_xor0 = a[13] ^ b[13];
  assign u_cla16_xor13 = u_cla16_pg_logic13_xor0 ^ u_cla16_or26;
  assign u_cla16_and53 = u_cla16_or25 & u_cla16_pg_logic13_or0;
  assign u_cla16_and54 = u_cla16_and53 & u_cla16_pg_logic12_or0;
  assign u_cla16_and55 = u_cla16_pg_logic12_and0 & u_cla16_pg_logic13_or0;
  assign u_cla16_or27 = u_cla16_and54 | u_cla16_and55;
  assign u_cla16_or28 = u_cla16_pg_logic13_and0 | u_cla16_or27;
  assign u_cla16_pg_logic14_or0 = a[14] | b[14];
  assign u_cla16_pg_logic14_and0 = a[14] & b[14];
  assign u_cla16_pg_logic14_xor0 = a[14] ^ b[14];
  assign u_cla16_xor14 = u_cla16_pg_logic14_xor0 ^ u_cla16_or28;
  assign u_cla16_and56 = u_cla16_or25 & u_cla16_pg_logic13_or0;
  assign u_cla16_and57 = u_cla16_pg_logic14_or0 & u_cla16_pg_logic12_or0;
  assign u_cla16_and58 = u_cla16_and56 & u_cla16_and57;
  assign u_cla16_and59 = u_cla16_pg_logic12_and0 & u_cla16_pg_logic14_or0;
  assign u_cla16_and60 = u_cla16_and59 & u_cla16_pg_logic13_or0;
  assign u_cla16_and61 = u_cla16_pg_logic13_and0 & u_cla16_pg_logic14_or0;
  assign u_cla16_or29 = u_cla16_and58 | u_cla16_and60;
  assign u_cla16_or30 = u_cla16_or29 | u_cla16_and61;
  assign u_cla16_or31 = u_cla16_pg_logic14_and0 | u_cla16_or30;
  assign u_cla16_pg_logic15_or0 = a[15] | b[15];
  assign u_cla16_pg_logic15_and0 = a[15] & b[15];
  assign u_cla16_pg_logic15_xor0 = a[15] ^ b[15];
  assign u_cla16_xor15 = u_cla16_pg_logic15_xor0 ^ u_cla16_or31;
  assign u_cla16_and62 = u_cla16_or25 & u_cla16_pg_logic14_or0;
  assign u_cla16_and63 = u_cla16_pg_logic15_or0 & u_cla16_pg_logic13_or0;
  assign u_cla16_and64 = u_cla16_and62 & u_cla16_and63;
  assign u_cla16_and65 = u_cla16_and64 & u_cla16_pg_logic12_or0;
  assign u_cla16_and66 = u_cla16_pg_logic12_and0 & u_cla16_pg_logic14_or0;
  assign u_cla16_and67 = u_cla16_pg_logic15_or0 & u_cla16_pg_logic13_or0;
  assign u_cla16_and68 = u_cla16_and66 & u_cla16_and67;
  assign u_cla16_and69 = u_cla16_pg_logic13_and0 & u_cla16_pg_logic15_or0;
  assign u_cla16_and70 = u_cla16_and69 & u_cla16_pg_logic14_or0;
  assign u_cla16_and71 = u_cla16_pg_logic14_and0 & u_cla16_pg_logic15_or0;
  assign u_cla16_or32 = u_cla16_and65 | u_cla16_and70;
  assign u_cla16_or33 = u_cla16_and68 | u_cla16_and71;
  assign u_cla16_or34 = u_cla16_or32 | u_cla16_or33;
  assign u_cla16_or35 = u_cla16_pg_logic15_and0 | u_cla16_or34;

  assign u_cla16_out[0] = u_cla16_pg_logic0_xor0;
  assign u_cla16_out[1] = u_cla16_xor1;
  assign u_cla16_out[2] = u_cla16_xor2;
  assign u_cla16_out[3] = u_cla16_xor3;
  assign u_cla16_out[4] = u_cla16_xor4;
  assign u_cla16_out[5] = u_cla16_xor5;
  assign u_cla16_out[6] = u_cla16_xor6;
  assign u_cla16_out[7] = u_cla16_xor7;
  assign u_cla16_out[8] = u_cla16_xor8;
  assign u_cla16_out[9] = u_cla16_xor9;
  assign u_cla16_out[10] = u_cla16_xor10;
  assign u_cla16_out[11] = u_cla16_xor11;
  assign u_cla16_out[12] = u_cla16_xor12;
  assign u_cla16_out[13] = u_cla16_xor13;
  assign u_cla16_out[14] = u_cla16_xor14;
  assign u_cla16_out[15] = u_cla16_xor15;
  assign u_cla16_out[16] = u_cla16_or35;
endmodule