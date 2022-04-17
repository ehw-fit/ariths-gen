module u_cska24(input [23:0] a, input [23:0] b, output [24:0] u_cska24_out);
  wire u_cska24_xor0;
  wire u_cska24_ha0_xor0;
  wire u_cska24_ha0_and0;
  wire u_cska24_xor1;
  wire u_cska24_fa0_xor0;
  wire u_cska24_fa0_and0;
  wire u_cska24_fa0_xor1;
  wire u_cska24_fa0_and1;
  wire u_cska24_fa0_or0;
  wire u_cska24_xor2;
  wire u_cska24_fa1_xor0;
  wire u_cska24_fa1_and0;
  wire u_cska24_fa1_xor1;
  wire u_cska24_fa1_and1;
  wire u_cska24_fa1_or0;
  wire u_cska24_xor3;
  wire u_cska24_fa2_xor0;
  wire u_cska24_fa2_and0;
  wire u_cska24_fa2_xor1;
  wire u_cska24_fa2_and1;
  wire u_cska24_fa2_or0;
  wire u_cska24_and_propagate00;
  wire u_cska24_and_propagate01;
  wire u_cska24_and_propagate02;
  wire u_cska24_mux2to10_not0;
  wire u_cska24_mux2to10_and1;
  wire u_cska24_xor4;
  wire u_cska24_fa3_xor0;
  wire u_cska24_fa3_and0;
  wire u_cska24_fa3_xor1;
  wire u_cska24_fa3_and1;
  wire u_cska24_fa3_or0;
  wire u_cska24_xor5;
  wire u_cska24_fa4_xor0;
  wire u_cska24_fa4_and0;
  wire u_cska24_fa4_xor1;
  wire u_cska24_fa4_and1;
  wire u_cska24_fa4_or0;
  wire u_cska24_xor6;
  wire u_cska24_fa5_xor0;
  wire u_cska24_fa5_and0;
  wire u_cska24_fa5_xor1;
  wire u_cska24_fa5_and1;
  wire u_cska24_fa5_or0;
  wire u_cska24_xor7;
  wire u_cska24_fa6_xor0;
  wire u_cska24_fa6_and0;
  wire u_cska24_fa6_xor1;
  wire u_cska24_fa6_and1;
  wire u_cska24_fa6_or0;
  wire u_cska24_and_propagate13;
  wire u_cska24_and_propagate14;
  wire u_cska24_and_propagate15;
  wire u_cska24_mux2to11_and0;
  wire u_cska24_mux2to11_not0;
  wire u_cska24_mux2to11_and1;
  wire u_cska24_mux2to11_xor0;
  wire u_cska24_xor8;
  wire u_cska24_fa7_xor0;
  wire u_cska24_fa7_and0;
  wire u_cska24_fa7_xor1;
  wire u_cska24_fa7_and1;
  wire u_cska24_fa7_or0;
  wire u_cska24_xor9;
  wire u_cska24_fa8_xor0;
  wire u_cska24_fa8_and0;
  wire u_cska24_fa8_xor1;
  wire u_cska24_fa8_and1;
  wire u_cska24_fa8_or0;
  wire u_cska24_xor10;
  wire u_cska24_fa9_xor0;
  wire u_cska24_fa9_and0;
  wire u_cska24_fa9_xor1;
  wire u_cska24_fa9_and1;
  wire u_cska24_fa9_or0;
  wire u_cska24_xor11;
  wire u_cska24_fa10_xor0;
  wire u_cska24_fa10_and0;
  wire u_cska24_fa10_xor1;
  wire u_cska24_fa10_and1;
  wire u_cska24_fa10_or0;
  wire u_cska24_and_propagate26;
  wire u_cska24_and_propagate27;
  wire u_cska24_and_propagate28;
  wire u_cska24_mux2to12_and0;
  wire u_cska24_mux2to12_not0;
  wire u_cska24_mux2to12_and1;
  wire u_cska24_mux2to12_xor0;
  wire u_cska24_xor12;
  wire u_cska24_fa11_xor0;
  wire u_cska24_fa11_and0;
  wire u_cska24_fa11_xor1;
  wire u_cska24_fa11_and1;
  wire u_cska24_fa11_or0;
  wire u_cska24_xor13;
  wire u_cska24_fa12_xor0;
  wire u_cska24_fa12_and0;
  wire u_cska24_fa12_xor1;
  wire u_cska24_fa12_and1;
  wire u_cska24_fa12_or0;
  wire u_cska24_xor14;
  wire u_cska24_fa13_xor0;
  wire u_cska24_fa13_and0;
  wire u_cska24_fa13_xor1;
  wire u_cska24_fa13_and1;
  wire u_cska24_fa13_or0;
  wire u_cska24_xor15;
  wire u_cska24_fa14_xor0;
  wire u_cska24_fa14_and0;
  wire u_cska24_fa14_xor1;
  wire u_cska24_fa14_and1;
  wire u_cska24_fa14_or0;
  wire u_cska24_and_propagate39;
  wire u_cska24_and_propagate310;
  wire u_cska24_and_propagate311;
  wire u_cska24_mux2to13_and0;
  wire u_cska24_mux2to13_not0;
  wire u_cska24_mux2to13_and1;
  wire u_cska24_mux2to13_xor0;
  wire u_cska24_xor16;
  wire u_cska24_fa15_xor0;
  wire u_cska24_fa15_and0;
  wire u_cska24_fa15_xor1;
  wire u_cska24_fa15_and1;
  wire u_cska24_fa15_or0;
  wire u_cska24_xor17;
  wire u_cska24_fa16_xor0;
  wire u_cska24_fa16_and0;
  wire u_cska24_fa16_xor1;
  wire u_cska24_fa16_and1;
  wire u_cska24_fa16_or0;
  wire u_cska24_xor18;
  wire u_cska24_fa17_xor0;
  wire u_cska24_fa17_and0;
  wire u_cska24_fa17_xor1;
  wire u_cska24_fa17_and1;
  wire u_cska24_fa17_or0;
  wire u_cska24_xor19;
  wire u_cska24_fa18_xor0;
  wire u_cska24_fa18_and0;
  wire u_cska24_fa18_xor1;
  wire u_cska24_fa18_and1;
  wire u_cska24_fa18_or0;
  wire u_cska24_and_propagate412;
  wire u_cska24_and_propagate413;
  wire u_cska24_and_propagate414;
  wire u_cska24_mux2to14_and0;
  wire u_cska24_mux2to14_not0;
  wire u_cska24_mux2to14_and1;
  wire u_cska24_mux2to14_xor0;
  wire u_cska24_xor20;
  wire u_cska24_fa19_xor0;
  wire u_cska24_fa19_and0;
  wire u_cska24_fa19_xor1;
  wire u_cska24_fa19_and1;
  wire u_cska24_fa19_or0;
  wire u_cska24_xor21;
  wire u_cska24_fa20_xor0;
  wire u_cska24_fa20_and0;
  wire u_cska24_fa20_xor1;
  wire u_cska24_fa20_and1;
  wire u_cska24_fa20_or0;
  wire u_cska24_xor22;
  wire u_cska24_fa21_xor0;
  wire u_cska24_fa21_and0;
  wire u_cska24_fa21_xor1;
  wire u_cska24_fa21_and1;
  wire u_cska24_fa21_or0;
  wire u_cska24_xor23;
  wire u_cska24_fa22_xor0;
  wire u_cska24_fa22_and0;
  wire u_cska24_fa22_xor1;
  wire u_cska24_fa22_and1;
  wire u_cska24_fa22_or0;
  wire u_cska24_and_propagate515;
  wire u_cska24_and_propagate516;
  wire u_cska24_and_propagate517;
  wire u_cska24_mux2to15_and0;
  wire u_cska24_mux2to15_not0;
  wire u_cska24_mux2to15_and1;
  wire u_cska24_mux2to15_xor0;

  assign u_cska24_xor0 = a[0] ^ b[0];
  assign u_cska24_ha0_xor0 = a[0] ^ b[0];
  assign u_cska24_ha0_and0 = a[0] & b[0];
  assign u_cska24_xor1 = a[1] ^ b[1];
  assign u_cska24_fa0_xor0 = a[1] ^ b[1];
  assign u_cska24_fa0_and0 = a[1] & b[1];
  assign u_cska24_fa0_xor1 = u_cska24_fa0_xor0 ^ u_cska24_ha0_and0;
  assign u_cska24_fa0_and1 = u_cska24_fa0_xor0 & u_cska24_ha0_and0;
  assign u_cska24_fa0_or0 = u_cska24_fa0_and0 | u_cska24_fa0_and1;
  assign u_cska24_xor2 = a[2] ^ b[2];
  assign u_cska24_fa1_xor0 = a[2] ^ b[2];
  assign u_cska24_fa1_and0 = a[2] & b[2];
  assign u_cska24_fa1_xor1 = u_cska24_fa1_xor0 ^ u_cska24_fa0_or0;
  assign u_cska24_fa1_and1 = u_cska24_fa1_xor0 & u_cska24_fa0_or0;
  assign u_cska24_fa1_or0 = u_cska24_fa1_and0 | u_cska24_fa1_and1;
  assign u_cska24_xor3 = a[3] ^ b[3];
  assign u_cska24_fa2_xor0 = a[3] ^ b[3];
  assign u_cska24_fa2_and0 = a[3] & b[3];
  assign u_cska24_fa2_xor1 = u_cska24_fa2_xor0 ^ u_cska24_fa1_or0;
  assign u_cska24_fa2_and1 = u_cska24_fa2_xor0 & u_cska24_fa1_or0;
  assign u_cska24_fa2_or0 = u_cska24_fa2_and0 | u_cska24_fa2_and1;
  assign u_cska24_and_propagate00 = u_cska24_xor0 & u_cska24_xor2;
  assign u_cska24_and_propagate01 = u_cska24_xor1 & u_cska24_xor3;
  assign u_cska24_and_propagate02 = u_cska24_and_propagate00 & u_cska24_and_propagate01;
  assign u_cska24_mux2to10_not0 = ~u_cska24_and_propagate02;
  assign u_cska24_mux2to10_and1 = u_cska24_fa2_or0 & u_cska24_mux2to10_not0;
  assign u_cska24_xor4 = a[4] ^ b[4];
  assign u_cska24_fa3_xor0 = a[4] ^ b[4];
  assign u_cska24_fa3_and0 = a[4] & b[4];
  assign u_cska24_fa3_xor1 = u_cska24_fa3_xor0 ^ u_cska24_mux2to10_and1;
  assign u_cska24_fa3_and1 = u_cska24_fa3_xor0 & u_cska24_mux2to10_and1;
  assign u_cska24_fa3_or0 = u_cska24_fa3_and0 | u_cska24_fa3_and1;
  assign u_cska24_xor5 = a[5] ^ b[5];
  assign u_cska24_fa4_xor0 = a[5] ^ b[5];
  assign u_cska24_fa4_and0 = a[5] & b[5];
  assign u_cska24_fa4_xor1 = u_cska24_fa4_xor0 ^ u_cska24_fa3_or0;
  assign u_cska24_fa4_and1 = u_cska24_fa4_xor0 & u_cska24_fa3_or0;
  assign u_cska24_fa4_or0 = u_cska24_fa4_and0 | u_cska24_fa4_and1;
  assign u_cska24_xor6 = a[6] ^ b[6];
  assign u_cska24_fa5_xor0 = a[6] ^ b[6];
  assign u_cska24_fa5_and0 = a[6] & b[6];
  assign u_cska24_fa5_xor1 = u_cska24_fa5_xor0 ^ u_cska24_fa4_or0;
  assign u_cska24_fa5_and1 = u_cska24_fa5_xor0 & u_cska24_fa4_or0;
  assign u_cska24_fa5_or0 = u_cska24_fa5_and0 | u_cska24_fa5_and1;
  assign u_cska24_xor7 = a[7] ^ b[7];
  assign u_cska24_fa6_xor0 = a[7] ^ b[7];
  assign u_cska24_fa6_and0 = a[7] & b[7];
  assign u_cska24_fa6_xor1 = u_cska24_fa6_xor0 ^ u_cska24_fa5_or0;
  assign u_cska24_fa6_and1 = u_cska24_fa6_xor0 & u_cska24_fa5_or0;
  assign u_cska24_fa6_or0 = u_cska24_fa6_and0 | u_cska24_fa6_and1;
  assign u_cska24_and_propagate13 = u_cska24_xor4 & u_cska24_xor6;
  assign u_cska24_and_propagate14 = u_cska24_xor5 & u_cska24_xor7;
  assign u_cska24_and_propagate15 = u_cska24_and_propagate13 & u_cska24_and_propagate14;
  assign u_cska24_mux2to11_and0 = u_cska24_mux2to10_and1 & u_cska24_and_propagate15;
  assign u_cska24_mux2to11_not0 = ~u_cska24_and_propagate15;
  assign u_cska24_mux2to11_and1 = u_cska24_fa6_or0 & u_cska24_mux2to11_not0;
  assign u_cska24_mux2to11_xor0 = u_cska24_mux2to11_and0 ^ u_cska24_mux2to11_and1;
  assign u_cska24_xor8 = a[8] ^ b[8];
  assign u_cska24_fa7_xor0 = a[8] ^ b[8];
  assign u_cska24_fa7_and0 = a[8] & b[8];
  assign u_cska24_fa7_xor1 = u_cska24_fa7_xor0 ^ u_cska24_mux2to11_xor0;
  assign u_cska24_fa7_and1 = u_cska24_fa7_xor0 & u_cska24_mux2to11_xor0;
  assign u_cska24_fa7_or0 = u_cska24_fa7_and0 | u_cska24_fa7_and1;
  assign u_cska24_xor9 = a[9] ^ b[9];
  assign u_cska24_fa8_xor0 = a[9] ^ b[9];
  assign u_cska24_fa8_and0 = a[9] & b[9];
  assign u_cska24_fa8_xor1 = u_cska24_fa8_xor0 ^ u_cska24_fa7_or0;
  assign u_cska24_fa8_and1 = u_cska24_fa8_xor0 & u_cska24_fa7_or0;
  assign u_cska24_fa8_or0 = u_cska24_fa8_and0 | u_cska24_fa8_and1;
  assign u_cska24_xor10 = a[10] ^ b[10];
  assign u_cska24_fa9_xor0 = a[10] ^ b[10];
  assign u_cska24_fa9_and0 = a[10] & b[10];
  assign u_cska24_fa9_xor1 = u_cska24_fa9_xor0 ^ u_cska24_fa8_or0;
  assign u_cska24_fa9_and1 = u_cska24_fa9_xor0 & u_cska24_fa8_or0;
  assign u_cska24_fa9_or0 = u_cska24_fa9_and0 | u_cska24_fa9_and1;
  assign u_cska24_xor11 = a[11] ^ b[11];
  assign u_cska24_fa10_xor0 = a[11] ^ b[11];
  assign u_cska24_fa10_and0 = a[11] & b[11];
  assign u_cska24_fa10_xor1 = u_cska24_fa10_xor0 ^ u_cska24_fa9_or0;
  assign u_cska24_fa10_and1 = u_cska24_fa10_xor0 & u_cska24_fa9_or0;
  assign u_cska24_fa10_or0 = u_cska24_fa10_and0 | u_cska24_fa10_and1;
  assign u_cska24_and_propagate26 = u_cska24_xor8 & u_cska24_xor10;
  assign u_cska24_and_propagate27 = u_cska24_xor9 & u_cska24_xor11;
  assign u_cska24_and_propagate28 = u_cska24_and_propagate26 & u_cska24_and_propagate27;
  assign u_cska24_mux2to12_and0 = u_cska24_mux2to11_xor0 & u_cska24_and_propagate28;
  assign u_cska24_mux2to12_not0 = ~u_cska24_and_propagate28;
  assign u_cska24_mux2to12_and1 = u_cska24_fa10_or0 & u_cska24_mux2to12_not0;
  assign u_cska24_mux2to12_xor0 = u_cska24_mux2to12_and0 ^ u_cska24_mux2to12_and1;
  assign u_cska24_xor12 = a[12] ^ b[12];
  assign u_cska24_fa11_xor0 = a[12] ^ b[12];
  assign u_cska24_fa11_and0 = a[12] & b[12];
  assign u_cska24_fa11_xor1 = u_cska24_fa11_xor0 ^ u_cska24_mux2to12_xor0;
  assign u_cska24_fa11_and1 = u_cska24_fa11_xor0 & u_cska24_mux2to12_xor0;
  assign u_cska24_fa11_or0 = u_cska24_fa11_and0 | u_cska24_fa11_and1;
  assign u_cska24_xor13 = a[13] ^ b[13];
  assign u_cska24_fa12_xor0 = a[13] ^ b[13];
  assign u_cska24_fa12_and0 = a[13] & b[13];
  assign u_cska24_fa12_xor1 = u_cska24_fa12_xor0 ^ u_cska24_fa11_or0;
  assign u_cska24_fa12_and1 = u_cska24_fa12_xor0 & u_cska24_fa11_or0;
  assign u_cska24_fa12_or0 = u_cska24_fa12_and0 | u_cska24_fa12_and1;
  assign u_cska24_xor14 = a[14] ^ b[14];
  assign u_cska24_fa13_xor0 = a[14] ^ b[14];
  assign u_cska24_fa13_and0 = a[14] & b[14];
  assign u_cska24_fa13_xor1 = u_cska24_fa13_xor0 ^ u_cska24_fa12_or0;
  assign u_cska24_fa13_and1 = u_cska24_fa13_xor0 & u_cska24_fa12_or0;
  assign u_cska24_fa13_or0 = u_cska24_fa13_and0 | u_cska24_fa13_and1;
  assign u_cska24_xor15 = a[15] ^ b[15];
  assign u_cska24_fa14_xor0 = a[15] ^ b[15];
  assign u_cska24_fa14_and0 = a[15] & b[15];
  assign u_cska24_fa14_xor1 = u_cska24_fa14_xor0 ^ u_cska24_fa13_or0;
  assign u_cska24_fa14_and1 = u_cska24_fa14_xor0 & u_cska24_fa13_or0;
  assign u_cska24_fa14_or0 = u_cska24_fa14_and0 | u_cska24_fa14_and1;
  assign u_cska24_and_propagate39 = u_cska24_xor12 & u_cska24_xor14;
  assign u_cska24_and_propagate310 = u_cska24_xor13 & u_cska24_xor15;
  assign u_cska24_and_propagate311 = u_cska24_and_propagate39 & u_cska24_and_propagate310;
  assign u_cska24_mux2to13_and0 = u_cska24_mux2to12_xor0 & u_cska24_and_propagate311;
  assign u_cska24_mux2to13_not0 = ~u_cska24_and_propagate311;
  assign u_cska24_mux2to13_and1 = u_cska24_fa14_or0 & u_cska24_mux2to13_not0;
  assign u_cska24_mux2to13_xor0 = u_cska24_mux2to13_and0 ^ u_cska24_mux2to13_and1;
  assign u_cska24_xor16 = a[16] ^ b[16];
  assign u_cska24_fa15_xor0 = a[16] ^ b[16];
  assign u_cska24_fa15_and0 = a[16] & b[16];
  assign u_cska24_fa15_xor1 = u_cska24_fa15_xor0 ^ u_cska24_mux2to13_xor0;
  assign u_cska24_fa15_and1 = u_cska24_fa15_xor0 & u_cska24_mux2to13_xor0;
  assign u_cska24_fa15_or0 = u_cska24_fa15_and0 | u_cska24_fa15_and1;
  assign u_cska24_xor17 = a[17] ^ b[17];
  assign u_cska24_fa16_xor0 = a[17] ^ b[17];
  assign u_cska24_fa16_and0 = a[17] & b[17];
  assign u_cska24_fa16_xor1 = u_cska24_fa16_xor0 ^ u_cska24_fa15_or0;
  assign u_cska24_fa16_and1 = u_cska24_fa16_xor0 & u_cska24_fa15_or0;
  assign u_cska24_fa16_or0 = u_cska24_fa16_and0 | u_cska24_fa16_and1;
  assign u_cska24_xor18 = a[18] ^ b[18];
  assign u_cska24_fa17_xor0 = a[18] ^ b[18];
  assign u_cska24_fa17_and0 = a[18] & b[18];
  assign u_cska24_fa17_xor1 = u_cska24_fa17_xor0 ^ u_cska24_fa16_or0;
  assign u_cska24_fa17_and1 = u_cska24_fa17_xor0 & u_cska24_fa16_or0;
  assign u_cska24_fa17_or0 = u_cska24_fa17_and0 | u_cska24_fa17_and1;
  assign u_cska24_xor19 = a[19] ^ b[19];
  assign u_cska24_fa18_xor0 = a[19] ^ b[19];
  assign u_cska24_fa18_and0 = a[19] & b[19];
  assign u_cska24_fa18_xor1 = u_cska24_fa18_xor0 ^ u_cska24_fa17_or0;
  assign u_cska24_fa18_and1 = u_cska24_fa18_xor0 & u_cska24_fa17_or0;
  assign u_cska24_fa18_or0 = u_cska24_fa18_and0 | u_cska24_fa18_and1;
  assign u_cska24_and_propagate412 = u_cska24_xor16 & u_cska24_xor18;
  assign u_cska24_and_propagate413 = u_cska24_xor17 & u_cska24_xor19;
  assign u_cska24_and_propagate414 = u_cska24_and_propagate412 & u_cska24_and_propagate413;
  assign u_cska24_mux2to14_and0 = u_cska24_mux2to13_xor0 & u_cska24_and_propagate414;
  assign u_cska24_mux2to14_not0 = ~u_cska24_and_propagate414;
  assign u_cska24_mux2to14_and1 = u_cska24_fa18_or0 & u_cska24_mux2to14_not0;
  assign u_cska24_mux2to14_xor0 = u_cska24_mux2to14_and0 ^ u_cska24_mux2to14_and1;
  assign u_cska24_xor20 = a[20] ^ b[20];
  assign u_cska24_fa19_xor0 = a[20] ^ b[20];
  assign u_cska24_fa19_and0 = a[20] & b[20];
  assign u_cska24_fa19_xor1 = u_cska24_fa19_xor0 ^ u_cska24_mux2to14_xor0;
  assign u_cska24_fa19_and1 = u_cska24_fa19_xor0 & u_cska24_mux2to14_xor0;
  assign u_cska24_fa19_or0 = u_cska24_fa19_and0 | u_cska24_fa19_and1;
  assign u_cska24_xor21 = a[21] ^ b[21];
  assign u_cska24_fa20_xor0 = a[21] ^ b[21];
  assign u_cska24_fa20_and0 = a[21] & b[21];
  assign u_cska24_fa20_xor1 = u_cska24_fa20_xor0 ^ u_cska24_fa19_or0;
  assign u_cska24_fa20_and1 = u_cska24_fa20_xor0 & u_cska24_fa19_or0;
  assign u_cska24_fa20_or0 = u_cska24_fa20_and0 | u_cska24_fa20_and1;
  assign u_cska24_xor22 = a[22] ^ b[22];
  assign u_cska24_fa21_xor0 = a[22] ^ b[22];
  assign u_cska24_fa21_and0 = a[22] & b[22];
  assign u_cska24_fa21_xor1 = u_cska24_fa21_xor0 ^ u_cska24_fa20_or0;
  assign u_cska24_fa21_and1 = u_cska24_fa21_xor0 & u_cska24_fa20_or0;
  assign u_cska24_fa21_or0 = u_cska24_fa21_and0 | u_cska24_fa21_and1;
  assign u_cska24_xor23 = a[23] ^ b[23];
  assign u_cska24_fa22_xor0 = a[23] ^ b[23];
  assign u_cska24_fa22_and0 = a[23] & b[23];
  assign u_cska24_fa22_xor1 = u_cska24_fa22_xor0 ^ u_cska24_fa21_or0;
  assign u_cska24_fa22_and1 = u_cska24_fa22_xor0 & u_cska24_fa21_or0;
  assign u_cska24_fa22_or0 = u_cska24_fa22_and0 | u_cska24_fa22_and1;
  assign u_cska24_and_propagate515 = u_cska24_xor20 & u_cska24_xor22;
  assign u_cska24_and_propagate516 = u_cska24_xor21 & u_cska24_xor23;
  assign u_cska24_and_propagate517 = u_cska24_and_propagate515 & u_cska24_and_propagate516;
  assign u_cska24_mux2to15_and0 = u_cska24_mux2to14_xor0 & u_cska24_and_propagate517;
  assign u_cska24_mux2to15_not0 = ~u_cska24_and_propagate517;
  assign u_cska24_mux2to15_and1 = u_cska24_fa22_or0 & u_cska24_mux2to15_not0;
  assign u_cska24_mux2to15_xor0 = u_cska24_mux2to15_and0 ^ u_cska24_mux2to15_and1;

  assign u_cska24_out[0] = u_cska24_ha0_xor0;
  assign u_cska24_out[1] = u_cska24_fa0_xor1;
  assign u_cska24_out[2] = u_cska24_fa1_xor1;
  assign u_cska24_out[3] = u_cska24_fa2_xor1;
  assign u_cska24_out[4] = u_cska24_fa3_xor1;
  assign u_cska24_out[5] = u_cska24_fa4_xor1;
  assign u_cska24_out[6] = u_cska24_fa5_xor1;
  assign u_cska24_out[7] = u_cska24_fa6_xor1;
  assign u_cska24_out[8] = u_cska24_fa7_xor1;
  assign u_cska24_out[9] = u_cska24_fa8_xor1;
  assign u_cska24_out[10] = u_cska24_fa9_xor1;
  assign u_cska24_out[11] = u_cska24_fa10_xor1;
  assign u_cska24_out[12] = u_cska24_fa11_xor1;
  assign u_cska24_out[13] = u_cska24_fa12_xor1;
  assign u_cska24_out[14] = u_cska24_fa13_xor1;
  assign u_cska24_out[15] = u_cska24_fa14_xor1;
  assign u_cska24_out[16] = u_cska24_fa15_xor1;
  assign u_cska24_out[17] = u_cska24_fa16_xor1;
  assign u_cska24_out[18] = u_cska24_fa17_xor1;
  assign u_cska24_out[19] = u_cska24_fa18_xor1;
  assign u_cska24_out[20] = u_cska24_fa19_xor1;
  assign u_cska24_out[21] = u_cska24_fa20_xor1;
  assign u_cska24_out[22] = u_cska24_fa21_xor1;
  assign u_cska24_out[23] = u_cska24_fa22_xor1;
  assign u_cska24_out[24] = u_cska24_mux2to15_xor0;
endmodule