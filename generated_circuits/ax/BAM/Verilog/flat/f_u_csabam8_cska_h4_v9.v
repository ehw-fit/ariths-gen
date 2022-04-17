module f_u_csabam8_cska_h4_v9(input [7:0] a, input [7:0] b, output [15:0] f_u_csabam8_cska_h4_v9_out);
  wire f_u_csabam8_cska_h4_v9_and5_4;
  wire f_u_csabam8_cska_h4_v9_and6_4;
  wire f_u_csabam8_cska_h4_v9_and7_4;
  wire f_u_csabam8_cska_h4_v9_and4_5;
  wire f_u_csabam8_cska_h4_v9_ha4_5_xor0;
  wire f_u_csabam8_cska_h4_v9_ha4_5_and0;
  wire f_u_csabam8_cska_h4_v9_and5_5;
  wire f_u_csabam8_cska_h4_v9_ha5_5_xor0;
  wire f_u_csabam8_cska_h4_v9_ha5_5_and0;
  wire f_u_csabam8_cska_h4_v9_and6_5;
  wire f_u_csabam8_cska_h4_v9_ha6_5_xor0;
  wire f_u_csabam8_cska_h4_v9_ha6_5_and0;
  wire f_u_csabam8_cska_h4_v9_and7_5;
  wire f_u_csabam8_cska_h4_v9_and3_6;
  wire f_u_csabam8_cska_h4_v9_ha3_6_xor0;
  wire f_u_csabam8_cska_h4_v9_ha3_6_and0;
  wire f_u_csabam8_cska_h4_v9_and4_6;
  wire f_u_csabam8_cska_h4_v9_fa4_6_xor0;
  wire f_u_csabam8_cska_h4_v9_fa4_6_and0;
  wire f_u_csabam8_cska_h4_v9_fa4_6_xor1;
  wire f_u_csabam8_cska_h4_v9_fa4_6_and1;
  wire f_u_csabam8_cska_h4_v9_fa4_6_or0;
  wire f_u_csabam8_cska_h4_v9_and5_6;
  wire f_u_csabam8_cska_h4_v9_fa5_6_xor0;
  wire f_u_csabam8_cska_h4_v9_fa5_6_and0;
  wire f_u_csabam8_cska_h4_v9_fa5_6_xor1;
  wire f_u_csabam8_cska_h4_v9_fa5_6_and1;
  wire f_u_csabam8_cska_h4_v9_fa5_6_or0;
  wire f_u_csabam8_cska_h4_v9_and6_6;
  wire f_u_csabam8_cska_h4_v9_fa6_6_xor0;
  wire f_u_csabam8_cska_h4_v9_fa6_6_and0;
  wire f_u_csabam8_cska_h4_v9_fa6_6_xor1;
  wire f_u_csabam8_cska_h4_v9_fa6_6_and1;
  wire f_u_csabam8_cska_h4_v9_fa6_6_or0;
  wire f_u_csabam8_cska_h4_v9_and7_6;
  wire f_u_csabam8_cska_h4_v9_and2_7;
  wire f_u_csabam8_cska_h4_v9_ha2_7_xor0;
  wire f_u_csabam8_cska_h4_v9_ha2_7_and0;
  wire f_u_csabam8_cska_h4_v9_and3_7;
  wire f_u_csabam8_cska_h4_v9_fa3_7_xor0;
  wire f_u_csabam8_cska_h4_v9_fa3_7_and0;
  wire f_u_csabam8_cska_h4_v9_fa3_7_xor1;
  wire f_u_csabam8_cska_h4_v9_fa3_7_and1;
  wire f_u_csabam8_cska_h4_v9_fa3_7_or0;
  wire f_u_csabam8_cska_h4_v9_and4_7;
  wire f_u_csabam8_cska_h4_v9_fa4_7_xor0;
  wire f_u_csabam8_cska_h4_v9_fa4_7_and0;
  wire f_u_csabam8_cska_h4_v9_fa4_7_xor1;
  wire f_u_csabam8_cska_h4_v9_fa4_7_and1;
  wire f_u_csabam8_cska_h4_v9_fa4_7_or0;
  wire f_u_csabam8_cska_h4_v9_and5_7;
  wire f_u_csabam8_cska_h4_v9_fa5_7_xor0;
  wire f_u_csabam8_cska_h4_v9_fa5_7_and0;
  wire f_u_csabam8_cska_h4_v9_fa5_7_xor1;
  wire f_u_csabam8_cska_h4_v9_fa5_7_and1;
  wire f_u_csabam8_cska_h4_v9_fa5_7_or0;
  wire f_u_csabam8_cska_h4_v9_and6_7;
  wire f_u_csabam8_cska_h4_v9_fa6_7_xor0;
  wire f_u_csabam8_cska_h4_v9_fa6_7_and0;
  wire f_u_csabam8_cska_h4_v9_fa6_7_xor1;
  wire f_u_csabam8_cska_h4_v9_fa6_7_and1;
  wire f_u_csabam8_cska_h4_v9_fa6_7_or0;
  wire f_u_csabam8_cska_h4_v9_and7_7;
  wire f_u_csabam8_cska_h4_v9_u_cska6_xor1;
  wire f_u_csabam8_cska_h4_v9_u_cska6_fa0_xor0;
  wire f_u_csabam8_cska_h4_v9_u_cska6_fa0_and0;
  wire f_u_csabam8_cska_h4_v9_u_cska6_xor2;
  wire f_u_csabam8_cska_h4_v9_u_cska6_fa1_xor0;
  wire f_u_csabam8_cska_h4_v9_u_cska6_fa1_and0;
  wire f_u_csabam8_cska_h4_v9_u_cska6_fa1_xor1;
  wire f_u_csabam8_cska_h4_v9_u_cska6_fa1_and1;
  wire f_u_csabam8_cska_h4_v9_u_cska6_fa1_or0;
  wire f_u_csabam8_cska_h4_v9_u_cska6_xor3;
  wire f_u_csabam8_cska_h4_v9_u_cska6_fa2_xor0;
  wire f_u_csabam8_cska_h4_v9_u_cska6_fa2_and0;
  wire f_u_csabam8_cska_h4_v9_u_cska6_fa2_xor1;
  wire f_u_csabam8_cska_h4_v9_u_cska6_fa2_and1;
  wire f_u_csabam8_cska_h4_v9_u_cska6_fa2_or0;
  wire f_u_csabam8_cska_h4_v9_u_cska6_and_propagate00;
  wire f_u_csabam8_cska_h4_v9_u_cska6_and_propagate01;
  wire f_u_csabam8_cska_h4_v9_u_cska6_and_propagate02;
  wire f_u_csabam8_cska_h4_v9_u_cska6_mux2to10_not0;
  wire f_u_csabam8_cska_h4_v9_u_cska6_mux2to10_and1;
  wire f_u_csabam8_cska_h4_v9_u_cska6_xor4;
  wire f_u_csabam8_cska_h4_v9_u_cska6_fa3_xor0;
  wire f_u_csabam8_cska_h4_v9_u_cska6_fa3_and0;
  wire f_u_csabam8_cska_h4_v9_u_cska6_fa3_xor1;
  wire f_u_csabam8_cska_h4_v9_u_cska6_fa3_and1;
  wire f_u_csabam8_cska_h4_v9_u_cska6_fa3_or0;

  assign f_u_csabam8_cska_h4_v9_and5_4 = a[5] & b[4];
  assign f_u_csabam8_cska_h4_v9_and6_4 = a[6] & b[4];
  assign f_u_csabam8_cska_h4_v9_and7_4 = a[7] & b[4];
  assign f_u_csabam8_cska_h4_v9_and4_5 = a[4] & b[5];
  assign f_u_csabam8_cska_h4_v9_ha4_5_xor0 = f_u_csabam8_cska_h4_v9_and4_5 ^ f_u_csabam8_cska_h4_v9_and5_4;
  assign f_u_csabam8_cska_h4_v9_ha4_5_and0 = f_u_csabam8_cska_h4_v9_and4_5 & f_u_csabam8_cska_h4_v9_and5_4;
  assign f_u_csabam8_cska_h4_v9_and5_5 = a[5] & b[5];
  assign f_u_csabam8_cska_h4_v9_ha5_5_xor0 = f_u_csabam8_cska_h4_v9_and5_5 ^ f_u_csabam8_cska_h4_v9_and6_4;
  assign f_u_csabam8_cska_h4_v9_ha5_5_and0 = f_u_csabam8_cska_h4_v9_and5_5 & f_u_csabam8_cska_h4_v9_and6_4;
  assign f_u_csabam8_cska_h4_v9_and6_5 = a[6] & b[5];
  assign f_u_csabam8_cska_h4_v9_ha6_5_xor0 = f_u_csabam8_cska_h4_v9_and6_5 ^ f_u_csabam8_cska_h4_v9_and7_4;
  assign f_u_csabam8_cska_h4_v9_ha6_5_and0 = f_u_csabam8_cska_h4_v9_and6_5 & f_u_csabam8_cska_h4_v9_and7_4;
  assign f_u_csabam8_cska_h4_v9_and7_5 = a[7] & b[5];
  assign f_u_csabam8_cska_h4_v9_and3_6 = a[3] & b[6];
  assign f_u_csabam8_cska_h4_v9_ha3_6_xor0 = f_u_csabam8_cska_h4_v9_and3_6 ^ f_u_csabam8_cska_h4_v9_ha4_5_xor0;
  assign f_u_csabam8_cska_h4_v9_ha3_6_and0 = f_u_csabam8_cska_h4_v9_and3_6 & f_u_csabam8_cska_h4_v9_ha4_5_xor0;
  assign f_u_csabam8_cska_h4_v9_and4_6 = a[4] & b[6];
  assign f_u_csabam8_cska_h4_v9_fa4_6_xor0 = f_u_csabam8_cska_h4_v9_and4_6 ^ f_u_csabam8_cska_h4_v9_ha5_5_xor0;
  assign f_u_csabam8_cska_h4_v9_fa4_6_and0 = f_u_csabam8_cska_h4_v9_and4_6 & f_u_csabam8_cska_h4_v9_ha5_5_xor0;
  assign f_u_csabam8_cska_h4_v9_fa4_6_xor1 = f_u_csabam8_cska_h4_v9_fa4_6_xor0 ^ f_u_csabam8_cska_h4_v9_ha4_5_and0;
  assign f_u_csabam8_cska_h4_v9_fa4_6_and1 = f_u_csabam8_cska_h4_v9_fa4_6_xor0 & f_u_csabam8_cska_h4_v9_ha4_5_and0;
  assign f_u_csabam8_cska_h4_v9_fa4_6_or0 = f_u_csabam8_cska_h4_v9_fa4_6_and0 | f_u_csabam8_cska_h4_v9_fa4_6_and1;
  assign f_u_csabam8_cska_h4_v9_and5_6 = a[5] & b[6];
  assign f_u_csabam8_cska_h4_v9_fa5_6_xor0 = f_u_csabam8_cska_h4_v9_and5_6 ^ f_u_csabam8_cska_h4_v9_ha6_5_xor0;
  assign f_u_csabam8_cska_h4_v9_fa5_6_and0 = f_u_csabam8_cska_h4_v9_and5_6 & f_u_csabam8_cska_h4_v9_ha6_5_xor0;
  assign f_u_csabam8_cska_h4_v9_fa5_6_xor1 = f_u_csabam8_cska_h4_v9_fa5_6_xor0 ^ f_u_csabam8_cska_h4_v9_ha5_5_and0;
  assign f_u_csabam8_cska_h4_v9_fa5_6_and1 = f_u_csabam8_cska_h4_v9_fa5_6_xor0 & f_u_csabam8_cska_h4_v9_ha5_5_and0;
  assign f_u_csabam8_cska_h4_v9_fa5_6_or0 = f_u_csabam8_cska_h4_v9_fa5_6_and0 | f_u_csabam8_cska_h4_v9_fa5_6_and1;
  assign f_u_csabam8_cska_h4_v9_and6_6 = a[6] & b[6];
  assign f_u_csabam8_cska_h4_v9_fa6_6_xor0 = f_u_csabam8_cska_h4_v9_and6_6 ^ f_u_csabam8_cska_h4_v9_and7_5;
  assign f_u_csabam8_cska_h4_v9_fa6_6_and0 = f_u_csabam8_cska_h4_v9_and6_6 & f_u_csabam8_cska_h4_v9_and7_5;
  assign f_u_csabam8_cska_h4_v9_fa6_6_xor1 = f_u_csabam8_cska_h4_v9_fa6_6_xor0 ^ f_u_csabam8_cska_h4_v9_ha6_5_and0;
  assign f_u_csabam8_cska_h4_v9_fa6_6_and1 = f_u_csabam8_cska_h4_v9_fa6_6_xor0 & f_u_csabam8_cska_h4_v9_ha6_5_and0;
  assign f_u_csabam8_cska_h4_v9_fa6_6_or0 = f_u_csabam8_cska_h4_v9_fa6_6_and0 | f_u_csabam8_cska_h4_v9_fa6_6_and1;
  assign f_u_csabam8_cska_h4_v9_and7_6 = a[7] & b[6];
  assign f_u_csabam8_cska_h4_v9_and2_7 = a[2] & b[7];
  assign f_u_csabam8_cska_h4_v9_ha2_7_xor0 = f_u_csabam8_cska_h4_v9_and2_7 ^ f_u_csabam8_cska_h4_v9_ha3_6_xor0;
  assign f_u_csabam8_cska_h4_v9_ha2_7_and0 = f_u_csabam8_cska_h4_v9_and2_7 & f_u_csabam8_cska_h4_v9_ha3_6_xor0;
  assign f_u_csabam8_cska_h4_v9_and3_7 = a[3] & b[7];
  assign f_u_csabam8_cska_h4_v9_fa3_7_xor0 = f_u_csabam8_cska_h4_v9_and3_7 ^ f_u_csabam8_cska_h4_v9_fa4_6_xor1;
  assign f_u_csabam8_cska_h4_v9_fa3_7_and0 = f_u_csabam8_cska_h4_v9_and3_7 & f_u_csabam8_cska_h4_v9_fa4_6_xor1;
  assign f_u_csabam8_cska_h4_v9_fa3_7_xor1 = f_u_csabam8_cska_h4_v9_fa3_7_xor0 ^ f_u_csabam8_cska_h4_v9_ha3_6_and0;
  assign f_u_csabam8_cska_h4_v9_fa3_7_and1 = f_u_csabam8_cska_h4_v9_fa3_7_xor0 & f_u_csabam8_cska_h4_v9_ha3_6_and0;
  assign f_u_csabam8_cska_h4_v9_fa3_7_or0 = f_u_csabam8_cska_h4_v9_fa3_7_and0 | f_u_csabam8_cska_h4_v9_fa3_7_and1;
  assign f_u_csabam8_cska_h4_v9_and4_7 = a[4] & b[7];
  assign f_u_csabam8_cska_h4_v9_fa4_7_xor0 = f_u_csabam8_cska_h4_v9_and4_7 ^ f_u_csabam8_cska_h4_v9_fa5_6_xor1;
  assign f_u_csabam8_cska_h4_v9_fa4_7_and0 = f_u_csabam8_cska_h4_v9_and4_7 & f_u_csabam8_cska_h4_v9_fa5_6_xor1;
  assign f_u_csabam8_cska_h4_v9_fa4_7_xor1 = f_u_csabam8_cska_h4_v9_fa4_7_xor0 ^ f_u_csabam8_cska_h4_v9_fa4_6_or0;
  assign f_u_csabam8_cska_h4_v9_fa4_7_and1 = f_u_csabam8_cska_h4_v9_fa4_7_xor0 & f_u_csabam8_cska_h4_v9_fa4_6_or0;
  assign f_u_csabam8_cska_h4_v9_fa4_7_or0 = f_u_csabam8_cska_h4_v9_fa4_7_and0 | f_u_csabam8_cska_h4_v9_fa4_7_and1;
  assign f_u_csabam8_cska_h4_v9_and5_7 = a[5] & b[7];
  assign f_u_csabam8_cska_h4_v9_fa5_7_xor0 = f_u_csabam8_cska_h4_v9_and5_7 ^ f_u_csabam8_cska_h4_v9_fa6_6_xor1;
  assign f_u_csabam8_cska_h4_v9_fa5_7_and0 = f_u_csabam8_cska_h4_v9_and5_7 & f_u_csabam8_cska_h4_v9_fa6_6_xor1;
  assign f_u_csabam8_cska_h4_v9_fa5_7_xor1 = f_u_csabam8_cska_h4_v9_fa5_7_xor0 ^ f_u_csabam8_cska_h4_v9_fa5_6_or0;
  assign f_u_csabam8_cska_h4_v9_fa5_7_and1 = f_u_csabam8_cska_h4_v9_fa5_7_xor0 & f_u_csabam8_cska_h4_v9_fa5_6_or0;
  assign f_u_csabam8_cska_h4_v9_fa5_7_or0 = f_u_csabam8_cska_h4_v9_fa5_7_and0 | f_u_csabam8_cska_h4_v9_fa5_7_and1;
  assign f_u_csabam8_cska_h4_v9_and6_7 = a[6] & b[7];
  assign f_u_csabam8_cska_h4_v9_fa6_7_xor0 = f_u_csabam8_cska_h4_v9_and6_7 ^ f_u_csabam8_cska_h4_v9_and7_6;
  assign f_u_csabam8_cska_h4_v9_fa6_7_and0 = f_u_csabam8_cska_h4_v9_and6_7 & f_u_csabam8_cska_h4_v9_and7_6;
  assign f_u_csabam8_cska_h4_v9_fa6_7_xor1 = f_u_csabam8_cska_h4_v9_fa6_7_xor0 ^ f_u_csabam8_cska_h4_v9_fa6_6_or0;
  assign f_u_csabam8_cska_h4_v9_fa6_7_and1 = f_u_csabam8_cska_h4_v9_fa6_7_xor0 & f_u_csabam8_cska_h4_v9_fa6_6_or0;
  assign f_u_csabam8_cska_h4_v9_fa6_7_or0 = f_u_csabam8_cska_h4_v9_fa6_7_and0 | f_u_csabam8_cska_h4_v9_fa6_7_and1;
  assign f_u_csabam8_cska_h4_v9_and7_7 = a[7] & b[7];
  assign f_u_csabam8_cska_h4_v9_u_cska6_xor1 = f_u_csabam8_cska_h4_v9_fa4_7_xor1 ^ f_u_csabam8_cska_h4_v9_fa3_7_or0;
  assign f_u_csabam8_cska_h4_v9_u_cska6_fa0_xor0 = f_u_csabam8_cska_h4_v9_fa4_7_xor1 ^ f_u_csabam8_cska_h4_v9_fa3_7_or0;
  assign f_u_csabam8_cska_h4_v9_u_cska6_fa0_and0 = f_u_csabam8_cska_h4_v9_fa4_7_xor1 & f_u_csabam8_cska_h4_v9_fa3_7_or0;
  assign f_u_csabam8_cska_h4_v9_u_cska6_xor2 = f_u_csabam8_cska_h4_v9_fa5_7_xor1 ^ f_u_csabam8_cska_h4_v9_fa4_7_or0;
  assign f_u_csabam8_cska_h4_v9_u_cska6_fa1_xor0 = f_u_csabam8_cska_h4_v9_fa5_7_xor1 ^ f_u_csabam8_cska_h4_v9_fa4_7_or0;
  assign f_u_csabam8_cska_h4_v9_u_cska6_fa1_and0 = f_u_csabam8_cska_h4_v9_fa5_7_xor1 & f_u_csabam8_cska_h4_v9_fa4_7_or0;
  assign f_u_csabam8_cska_h4_v9_u_cska6_fa1_xor1 = f_u_csabam8_cska_h4_v9_u_cska6_fa1_xor0 ^ f_u_csabam8_cska_h4_v9_u_cska6_fa0_and0;
  assign f_u_csabam8_cska_h4_v9_u_cska6_fa1_and1 = f_u_csabam8_cska_h4_v9_u_cska6_fa1_xor0 & f_u_csabam8_cska_h4_v9_u_cska6_fa0_and0;
  assign f_u_csabam8_cska_h4_v9_u_cska6_fa1_or0 = f_u_csabam8_cska_h4_v9_u_cska6_fa1_and0 | f_u_csabam8_cska_h4_v9_u_cska6_fa1_and1;
  assign f_u_csabam8_cska_h4_v9_u_cska6_xor3 = f_u_csabam8_cska_h4_v9_fa6_7_xor1 ^ f_u_csabam8_cska_h4_v9_fa5_7_or0;
  assign f_u_csabam8_cska_h4_v9_u_cska6_fa2_xor0 = f_u_csabam8_cska_h4_v9_fa6_7_xor1 ^ f_u_csabam8_cska_h4_v9_fa5_7_or0;
  assign f_u_csabam8_cska_h4_v9_u_cska6_fa2_and0 = f_u_csabam8_cska_h4_v9_fa6_7_xor1 & f_u_csabam8_cska_h4_v9_fa5_7_or0;
  assign f_u_csabam8_cska_h4_v9_u_cska6_fa2_xor1 = f_u_csabam8_cska_h4_v9_u_cska6_fa2_xor0 ^ f_u_csabam8_cska_h4_v9_u_cska6_fa1_or0;
  assign f_u_csabam8_cska_h4_v9_u_cska6_fa2_and1 = f_u_csabam8_cska_h4_v9_u_cska6_fa2_xor0 & f_u_csabam8_cska_h4_v9_u_cska6_fa1_or0;
  assign f_u_csabam8_cska_h4_v9_u_cska6_fa2_or0 = f_u_csabam8_cska_h4_v9_u_cska6_fa2_and0 | f_u_csabam8_cska_h4_v9_u_cska6_fa2_and1;
  assign f_u_csabam8_cska_h4_v9_u_cska6_and_propagate00 = f_u_csabam8_cska_h4_v9_fa3_7_xor1 & f_u_csabam8_cska_h4_v9_u_cska6_xor2;
  assign f_u_csabam8_cska_h4_v9_u_cska6_and_propagate01 = f_u_csabam8_cska_h4_v9_u_cska6_xor1 & f_u_csabam8_cska_h4_v9_u_cska6_xor3;
  assign f_u_csabam8_cska_h4_v9_u_cska6_and_propagate02 = f_u_csabam8_cska_h4_v9_u_cska6_and_propagate00 & f_u_csabam8_cska_h4_v9_u_cska6_and_propagate01;
  assign f_u_csabam8_cska_h4_v9_u_cska6_mux2to10_not0 = ~f_u_csabam8_cska_h4_v9_u_cska6_and_propagate02;
  assign f_u_csabam8_cska_h4_v9_u_cska6_mux2to10_and1 = f_u_csabam8_cska_h4_v9_u_cska6_fa2_or0 & f_u_csabam8_cska_h4_v9_u_cska6_mux2to10_not0;
  assign f_u_csabam8_cska_h4_v9_u_cska6_xor4 = f_u_csabam8_cska_h4_v9_and7_7 ^ f_u_csabam8_cska_h4_v9_fa6_7_or0;
  assign f_u_csabam8_cska_h4_v9_u_cska6_fa3_xor0 = f_u_csabam8_cska_h4_v9_and7_7 ^ f_u_csabam8_cska_h4_v9_fa6_7_or0;
  assign f_u_csabam8_cska_h4_v9_u_cska6_fa3_and0 = f_u_csabam8_cska_h4_v9_and7_7 & f_u_csabam8_cska_h4_v9_fa6_7_or0;
  assign f_u_csabam8_cska_h4_v9_u_cska6_fa3_xor1 = f_u_csabam8_cska_h4_v9_u_cska6_fa3_xor0 ^ f_u_csabam8_cska_h4_v9_u_cska6_mux2to10_and1;
  assign f_u_csabam8_cska_h4_v9_u_cska6_fa3_and1 = f_u_csabam8_cska_h4_v9_u_cska6_fa3_xor0 & f_u_csabam8_cska_h4_v9_u_cska6_mux2to10_and1;
  assign f_u_csabam8_cska_h4_v9_u_cska6_fa3_or0 = f_u_csabam8_cska_h4_v9_u_cska6_fa3_and0 | f_u_csabam8_cska_h4_v9_u_cska6_fa3_and1;

  assign f_u_csabam8_cska_h4_v9_out[0] = 1'b0;
  assign f_u_csabam8_cska_h4_v9_out[1] = 1'b0;
  assign f_u_csabam8_cska_h4_v9_out[2] = 1'b0;
  assign f_u_csabam8_cska_h4_v9_out[3] = 1'b0;
  assign f_u_csabam8_cska_h4_v9_out[4] = 1'b0;
  assign f_u_csabam8_cska_h4_v9_out[5] = 1'b0;
  assign f_u_csabam8_cska_h4_v9_out[6] = 1'b0;
  assign f_u_csabam8_cska_h4_v9_out[7] = 1'b0;
  assign f_u_csabam8_cska_h4_v9_out[8] = 1'b0;
  assign f_u_csabam8_cska_h4_v9_out[9] = f_u_csabam8_cska_h4_v9_fa3_7_xor1;
  assign f_u_csabam8_cska_h4_v9_out[10] = f_u_csabam8_cska_h4_v9_u_cska6_fa0_xor0;
  assign f_u_csabam8_cska_h4_v9_out[11] = f_u_csabam8_cska_h4_v9_u_cska6_fa1_xor1;
  assign f_u_csabam8_cska_h4_v9_out[12] = f_u_csabam8_cska_h4_v9_u_cska6_fa2_xor1;
  assign f_u_csabam8_cska_h4_v9_out[13] = f_u_csabam8_cska_h4_v9_u_cska6_fa3_xor1;
  assign f_u_csabam8_cska_h4_v9_out[14] = f_u_csabam8_cska_h4_v9_u_cska6_fa3_or0;
  assign f_u_csabam8_cska_h4_v9_out[15] = 1'b0;
endmodule