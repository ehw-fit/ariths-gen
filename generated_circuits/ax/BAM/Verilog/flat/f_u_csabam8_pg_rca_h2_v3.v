module f_u_csabam8_pg_rca_h2_v3(input [7:0] a, input [7:0] b, output [15:0] f_u_csabam8_pg_rca_h2_v3_out);
  wire f_u_csabam8_pg_rca_h2_v3_and1_2;
  wire f_u_csabam8_pg_rca_h2_v3_and2_2;
  wire f_u_csabam8_pg_rca_h2_v3_and3_2;
  wire f_u_csabam8_pg_rca_h2_v3_and4_2;
  wire f_u_csabam8_pg_rca_h2_v3_and5_2;
  wire f_u_csabam8_pg_rca_h2_v3_and6_2;
  wire f_u_csabam8_pg_rca_h2_v3_and7_2;
  wire f_u_csabam8_pg_rca_h2_v3_and0_3;
  wire f_u_csabam8_pg_rca_h2_v3_ha0_3_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_ha0_3_and0;
  wire f_u_csabam8_pg_rca_h2_v3_and1_3;
  wire f_u_csabam8_pg_rca_h2_v3_ha1_3_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_ha1_3_and0;
  wire f_u_csabam8_pg_rca_h2_v3_and2_3;
  wire f_u_csabam8_pg_rca_h2_v3_ha2_3_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_ha2_3_and0;
  wire f_u_csabam8_pg_rca_h2_v3_and3_3;
  wire f_u_csabam8_pg_rca_h2_v3_ha3_3_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_ha3_3_and0;
  wire f_u_csabam8_pg_rca_h2_v3_and4_3;
  wire f_u_csabam8_pg_rca_h2_v3_ha4_3_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_ha4_3_and0;
  wire f_u_csabam8_pg_rca_h2_v3_and5_3;
  wire f_u_csabam8_pg_rca_h2_v3_ha5_3_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_ha5_3_and0;
  wire f_u_csabam8_pg_rca_h2_v3_and6_3;
  wire f_u_csabam8_pg_rca_h2_v3_ha6_3_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_ha6_3_and0;
  wire f_u_csabam8_pg_rca_h2_v3_and7_3;
  wire f_u_csabam8_pg_rca_h2_v3_and0_4;
  wire f_u_csabam8_pg_rca_h2_v3_fa0_4_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_fa0_4_and0;
  wire f_u_csabam8_pg_rca_h2_v3_fa0_4_xor1;
  wire f_u_csabam8_pg_rca_h2_v3_fa0_4_and1;
  wire f_u_csabam8_pg_rca_h2_v3_fa0_4_or0;
  wire f_u_csabam8_pg_rca_h2_v3_and1_4;
  wire f_u_csabam8_pg_rca_h2_v3_fa1_4_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_fa1_4_and0;
  wire f_u_csabam8_pg_rca_h2_v3_fa1_4_xor1;
  wire f_u_csabam8_pg_rca_h2_v3_fa1_4_and1;
  wire f_u_csabam8_pg_rca_h2_v3_fa1_4_or0;
  wire f_u_csabam8_pg_rca_h2_v3_and2_4;
  wire f_u_csabam8_pg_rca_h2_v3_fa2_4_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_fa2_4_and0;
  wire f_u_csabam8_pg_rca_h2_v3_fa2_4_xor1;
  wire f_u_csabam8_pg_rca_h2_v3_fa2_4_and1;
  wire f_u_csabam8_pg_rca_h2_v3_fa2_4_or0;
  wire f_u_csabam8_pg_rca_h2_v3_and3_4;
  wire f_u_csabam8_pg_rca_h2_v3_fa3_4_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_fa3_4_and0;
  wire f_u_csabam8_pg_rca_h2_v3_fa3_4_xor1;
  wire f_u_csabam8_pg_rca_h2_v3_fa3_4_and1;
  wire f_u_csabam8_pg_rca_h2_v3_fa3_4_or0;
  wire f_u_csabam8_pg_rca_h2_v3_and4_4;
  wire f_u_csabam8_pg_rca_h2_v3_fa4_4_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_fa4_4_and0;
  wire f_u_csabam8_pg_rca_h2_v3_fa4_4_xor1;
  wire f_u_csabam8_pg_rca_h2_v3_fa4_4_and1;
  wire f_u_csabam8_pg_rca_h2_v3_fa4_4_or0;
  wire f_u_csabam8_pg_rca_h2_v3_and5_4;
  wire f_u_csabam8_pg_rca_h2_v3_fa5_4_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_fa5_4_and0;
  wire f_u_csabam8_pg_rca_h2_v3_fa5_4_xor1;
  wire f_u_csabam8_pg_rca_h2_v3_fa5_4_and1;
  wire f_u_csabam8_pg_rca_h2_v3_fa5_4_or0;
  wire f_u_csabam8_pg_rca_h2_v3_and6_4;
  wire f_u_csabam8_pg_rca_h2_v3_fa6_4_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_fa6_4_and0;
  wire f_u_csabam8_pg_rca_h2_v3_fa6_4_xor1;
  wire f_u_csabam8_pg_rca_h2_v3_fa6_4_and1;
  wire f_u_csabam8_pg_rca_h2_v3_fa6_4_or0;
  wire f_u_csabam8_pg_rca_h2_v3_and7_4;
  wire f_u_csabam8_pg_rca_h2_v3_and0_5;
  wire f_u_csabam8_pg_rca_h2_v3_fa0_5_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_fa0_5_and0;
  wire f_u_csabam8_pg_rca_h2_v3_fa0_5_xor1;
  wire f_u_csabam8_pg_rca_h2_v3_fa0_5_and1;
  wire f_u_csabam8_pg_rca_h2_v3_fa0_5_or0;
  wire f_u_csabam8_pg_rca_h2_v3_and1_5;
  wire f_u_csabam8_pg_rca_h2_v3_fa1_5_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_fa1_5_and0;
  wire f_u_csabam8_pg_rca_h2_v3_fa1_5_xor1;
  wire f_u_csabam8_pg_rca_h2_v3_fa1_5_and1;
  wire f_u_csabam8_pg_rca_h2_v3_fa1_5_or0;
  wire f_u_csabam8_pg_rca_h2_v3_and2_5;
  wire f_u_csabam8_pg_rca_h2_v3_fa2_5_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_fa2_5_and0;
  wire f_u_csabam8_pg_rca_h2_v3_fa2_5_xor1;
  wire f_u_csabam8_pg_rca_h2_v3_fa2_5_and1;
  wire f_u_csabam8_pg_rca_h2_v3_fa2_5_or0;
  wire f_u_csabam8_pg_rca_h2_v3_and3_5;
  wire f_u_csabam8_pg_rca_h2_v3_fa3_5_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_fa3_5_and0;
  wire f_u_csabam8_pg_rca_h2_v3_fa3_5_xor1;
  wire f_u_csabam8_pg_rca_h2_v3_fa3_5_and1;
  wire f_u_csabam8_pg_rca_h2_v3_fa3_5_or0;
  wire f_u_csabam8_pg_rca_h2_v3_and4_5;
  wire f_u_csabam8_pg_rca_h2_v3_fa4_5_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_fa4_5_and0;
  wire f_u_csabam8_pg_rca_h2_v3_fa4_5_xor1;
  wire f_u_csabam8_pg_rca_h2_v3_fa4_5_and1;
  wire f_u_csabam8_pg_rca_h2_v3_fa4_5_or0;
  wire f_u_csabam8_pg_rca_h2_v3_and5_5;
  wire f_u_csabam8_pg_rca_h2_v3_fa5_5_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_fa5_5_and0;
  wire f_u_csabam8_pg_rca_h2_v3_fa5_5_xor1;
  wire f_u_csabam8_pg_rca_h2_v3_fa5_5_and1;
  wire f_u_csabam8_pg_rca_h2_v3_fa5_5_or0;
  wire f_u_csabam8_pg_rca_h2_v3_and6_5;
  wire f_u_csabam8_pg_rca_h2_v3_fa6_5_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_fa6_5_and0;
  wire f_u_csabam8_pg_rca_h2_v3_fa6_5_xor1;
  wire f_u_csabam8_pg_rca_h2_v3_fa6_5_and1;
  wire f_u_csabam8_pg_rca_h2_v3_fa6_5_or0;
  wire f_u_csabam8_pg_rca_h2_v3_and7_5;
  wire f_u_csabam8_pg_rca_h2_v3_and0_6;
  wire f_u_csabam8_pg_rca_h2_v3_fa0_6_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_fa0_6_and0;
  wire f_u_csabam8_pg_rca_h2_v3_fa0_6_xor1;
  wire f_u_csabam8_pg_rca_h2_v3_fa0_6_and1;
  wire f_u_csabam8_pg_rca_h2_v3_fa0_6_or0;
  wire f_u_csabam8_pg_rca_h2_v3_and1_6;
  wire f_u_csabam8_pg_rca_h2_v3_fa1_6_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_fa1_6_and0;
  wire f_u_csabam8_pg_rca_h2_v3_fa1_6_xor1;
  wire f_u_csabam8_pg_rca_h2_v3_fa1_6_and1;
  wire f_u_csabam8_pg_rca_h2_v3_fa1_6_or0;
  wire f_u_csabam8_pg_rca_h2_v3_and2_6;
  wire f_u_csabam8_pg_rca_h2_v3_fa2_6_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_fa2_6_and0;
  wire f_u_csabam8_pg_rca_h2_v3_fa2_6_xor1;
  wire f_u_csabam8_pg_rca_h2_v3_fa2_6_and1;
  wire f_u_csabam8_pg_rca_h2_v3_fa2_6_or0;
  wire f_u_csabam8_pg_rca_h2_v3_and3_6;
  wire f_u_csabam8_pg_rca_h2_v3_fa3_6_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_fa3_6_and0;
  wire f_u_csabam8_pg_rca_h2_v3_fa3_6_xor1;
  wire f_u_csabam8_pg_rca_h2_v3_fa3_6_and1;
  wire f_u_csabam8_pg_rca_h2_v3_fa3_6_or0;
  wire f_u_csabam8_pg_rca_h2_v3_and4_6;
  wire f_u_csabam8_pg_rca_h2_v3_fa4_6_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_fa4_6_and0;
  wire f_u_csabam8_pg_rca_h2_v3_fa4_6_xor1;
  wire f_u_csabam8_pg_rca_h2_v3_fa4_6_and1;
  wire f_u_csabam8_pg_rca_h2_v3_fa4_6_or0;
  wire f_u_csabam8_pg_rca_h2_v3_and5_6;
  wire f_u_csabam8_pg_rca_h2_v3_fa5_6_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_fa5_6_and0;
  wire f_u_csabam8_pg_rca_h2_v3_fa5_6_xor1;
  wire f_u_csabam8_pg_rca_h2_v3_fa5_6_and1;
  wire f_u_csabam8_pg_rca_h2_v3_fa5_6_or0;
  wire f_u_csabam8_pg_rca_h2_v3_and6_6;
  wire f_u_csabam8_pg_rca_h2_v3_fa6_6_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_fa6_6_and0;
  wire f_u_csabam8_pg_rca_h2_v3_fa6_6_xor1;
  wire f_u_csabam8_pg_rca_h2_v3_fa6_6_and1;
  wire f_u_csabam8_pg_rca_h2_v3_fa6_6_or0;
  wire f_u_csabam8_pg_rca_h2_v3_and7_6;
  wire f_u_csabam8_pg_rca_h2_v3_and0_7;
  wire f_u_csabam8_pg_rca_h2_v3_fa0_7_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_fa0_7_and0;
  wire f_u_csabam8_pg_rca_h2_v3_fa0_7_xor1;
  wire f_u_csabam8_pg_rca_h2_v3_fa0_7_and1;
  wire f_u_csabam8_pg_rca_h2_v3_fa0_7_or0;
  wire f_u_csabam8_pg_rca_h2_v3_and1_7;
  wire f_u_csabam8_pg_rca_h2_v3_fa1_7_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_fa1_7_and0;
  wire f_u_csabam8_pg_rca_h2_v3_fa1_7_xor1;
  wire f_u_csabam8_pg_rca_h2_v3_fa1_7_and1;
  wire f_u_csabam8_pg_rca_h2_v3_fa1_7_or0;
  wire f_u_csabam8_pg_rca_h2_v3_and2_7;
  wire f_u_csabam8_pg_rca_h2_v3_fa2_7_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_fa2_7_and0;
  wire f_u_csabam8_pg_rca_h2_v3_fa2_7_xor1;
  wire f_u_csabam8_pg_rca_h2_v3_fa2_7_and1;
  wire f_u_csabam8_pg_rca_h2_v3_fa2_7_or0;
  wire f_u_csabam8_pg_rca_h2_v3_and3_7;
  wire f_u_csabam8_pg_rca_h2_v3_fa3_7_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_fa3_7_and0;
  wire f_u_csabam8_pg_rca_h2_v3_fa3_7_xor1;
  wire f_u_csabam8_pg_rca_h2_v3_fa3_7_and1;
  wire f_u_csabam8_pg_rca_h2_v3_fa3_7_or0;
  wire f_u_csabam8_pg_rca_h2_v3_and4_7;
  wire f_u_csabam8_pg_rca_h2_v3_fa4_7_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_fa4_7_and0;
  wire f_u_csabam8_pg_rca_h2_v3_fa4_7_xor1;
  wire f_u_csabam8_pg_rca_h2_v3_fa4_7_and1;
  wire f_u_csabam8_pg_rca_h2_v3_fa4_7_or0;
  wire f_u_csabam8_pg_rca_h2_v3_and5_7;
  wire f_u_csabam8_pg_rca_h2_v3_fa5_7_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_fa5_7_and0;
  wire f_u_csabam8_pg_rca_h2_v3_fa5_7_xor1;
  wire f_u_csabam8_pg_rca_h2_v3_fa5_7_and1;
  wire f_u_csabam8_pg_rca_h2_v3_fa5_7_or0;
  wire f_u_csabam8_pg_rca_h2_v3_and6_7;
  wire f_u_csabam8_pg_rca_h2_v3_fa6_7_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_fa6_7_and0;
  wire f_u_csabam8_pg_rca_h2_v3_fa6_7_xor1;
  wire f_u_csabam8_pg_rca_h2_v3_fa6_7_and1;
  wire f_u_csabam8_pg_rca_h2_v3_fa6_7_or0;
  wire f_u_csabam8_pg_rca_h2_v3_and7_7;
  wire f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa0_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa0_and0;
  wire f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa1_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa1_and0;
  wire f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa1_xor1;
  wire f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_and1;
  wire f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_or1;
  wire f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa2_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa2_and0;
  wire f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa2_xor1;
  wire f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_and2;
  wire f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_or2;
  wire f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa3_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa3_and0;
  wire f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa3_xor1;
  wire f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_and3;
  wire f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_or3;
  wire f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa4_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa4_and0;
  wire f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa4_xor1;
  wire f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_and4;
  wire f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_or4;
  wire f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa5_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa5_and0;
  wire f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa5_xor1;
  wire f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_and5;
  wire f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_or5;
  wire f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa6_xor0;
  wire f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa6_and0;
  wire f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa6_xor1;
  wire f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_and6;
  wire f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_or6;

  assign f_u_csabam8_pg_rca_h2_v3_and1_2 = a[1] & b[2];
  assign f_u_csabam8_pg_rca_h2_v3_and2_2 = a[2] & b[2];
  assign f_u_csabam8_pg_rca_h2_v3_and3_2 = a[3] & b[2];
  assign f_u_csabam8_pg_rca_h2_v3_and4_2 = a[4] & b[2];
  assign f_u_csabam8_pg_rca_h2_v3_and5_2 = a[5] & b[2];
  assign f_u_csabam8_pg_rca_h2_v3_and6_2 = a[6] & b[2];
  assign f_u_csabam8_pg_rca_h2_v3_and7_2 = a[7] & b[2];
  assign f_u_csabam8_pg_rca_h2_v3_and0_3 = a[0] & b[3];
  assign f_u_csabam8_pg_rca_h2_v3_ha0_3_xor0 = f_u_csabam8_pg_rca_h2_v3_and0_3 ^ f_u_csabam8_pg_rca_h2_v3_and1_2;
  assign f_u_csabam8_pg_rca_h2_v3_ha0_3_and0 = f_u_csabam8_pg_rca_h2_v3_and0_3 & f_u_csabam8_pg_rca_h2_v3_and1_2;
  assign f_u_csabam8_pg_rca_h2_v3_and1_3 = a[1] & b[3];
  assign f_u_csabam8_pg_rca_h2_v3_ha1_3_xor0 = f_u_csabam8_pg_rca_h2_v3_and1_3 ^ f_u_csabam8_pg_rca_h2_v3_and2_2;
  assign f_u_csabam8_pg_rca_h2_v3_ha1_3_and0 = f_u_csabam8_pg_rca_h2_v3_and1_3 & f_u_csabam8_pg_rca_h2_v3_and2_2;
  assign f_u_csabam8_pg_rca_h2_v3_and2_3 = a[2] & b[3];
  assign f_u_csabam8_pg_rca_h2_v3_ha2_3_xor0 = f_u_csabam8_pg_rca_h2_v3_and2_3 ^ f_u_csabam8_pg_rca_h2_v3_and3_2;
  assign f_u_csabam8_pg_rca_h2_v3_ha2_3_and0 = f_u_csabam8_pg_rca_h2_v3_and2_3 & f_u_csabam8_pg_rca_h2_v3_and3_2;
  assign f_u_csabam8_pg_rca_h2_v3_and3_3 = a[3] & b[3];
  assign f_u_csabam8_pg_rca_h2_v3_ha3_3_xor0 = f_u_csabam8_pg_rca_h2_v3_and3_3 ^ f_u_csabam8_pg_rca_h2_v3_and4_2;
  assign f_u_csabam8_pg_rca_h2_v3_ha3_3_and0 = f_u_csabam8_pg_rca_h2_v3_and3_3 & f_u_csabam8_pg_rca_h2_v3_and4_2;
  assign f_u_csabam8_pg_rca_h2_v3_and4_3 = a[4] & b[3];
  assign f_u_csabam8_pg_rca_h2_v3_ha4_3_xor0 = f_u_csabam8_pg_rca_h2_v3_and4_3 ^ f_u_csabam8_pg_rca_h2_v3_and5_2;
  assign f_u_csabam8_pg_rca_h2_v3_ha4_3_and0 = f_u_csabam8_pg_rca_h2_v3_and4_3 & f_u_csabam8_pg_rca_h2_v3_and5_2;
  assign f_u_csabam8_pg_rca_h2_v3_and5_3 = a[5] & b[3];
  assign f_u_csabam8_pg_rca_h2_v3_ha5_3_xor0 = f_u_csabam8_pg_rca_h2_v3_and5_3 ^ f_u_csabam8_pg_rca_h2_v3_and6_2;
  assign f_u_csabam8_pg_rca_h2_v3_ha5_3_and0 = f_u_csabam8_pg_rca_h2_v3_and5_3 & f_u_csabam8_pg_rca_h2_v3_and6_2;
  assign f_u_csabam8_pg_rca_h2_v3_and6_3 = a[6] & b[3];
  assign f_u_csabam8_pg_rca_h2_v3_ha6_3_xor0 = f_u_csabam8_pg_rca_h2_v3_and6_3 ^ f_u_csabam8_pg_rca_h2_v3_and7_2;
  assign f_u_csabam8_pg_rca_h2_v3_ha6_3_and0 = f_u_csabam8_pg_rca_h2_v3_and6_3 & f_u_csabam8_pg_rca_h2_v3_and7_2;
  assign f_u_csabam8_pg_rca_h2_v3_and7_3 = a[7] & b[3];
  assign f_u_csabam8_pg_rca_h2_v3_and0_4 = a[0] & b[4];
  assign f_u_csabam8_pg_rca_h2_v3_fa0_4_xor0 = f_u_csabam8_pg_rca_h2_v3_and0_4 ^ f_u_csabam8_pg_rca_h2_v3_ha1_3_xor0;
  assign f_u_csabam8_pg_rca_h2_v3_fa0_4_and0 = f_u_csabam8_pg_rca_h2_v3_and0_4 & f_u_csabam8_pg_rca_h2_v3_ha1_3_xor0;
  assign f_u_csabam8_pg_rca_h2_v3_fa0_4_xor1 = f_u_csabam8_pg_rca_h2_v3_fa0_4_xor0 ^ f_u_csabam8_pg_rca_h2_v3_ha0_3_and0;
  assign f_u_csabam8_pg_rca_h2_v3_fa0_4_and1 = f_u_csabam8_pg_rca_h2_v3_fa0_4_xor0 & f_u_csabam8_pg_rca_h2_v3_ha0_3_and0;
  assign f_u_csabam8_pg_rca_h2_v3_fa0_4_or0 = f_u_csabam8_pg_rca_h2_v3_fa0_4_and0 | f_u_csabam8_pg_rca_h2_v3_fa0_4_and1;
  assign f_u_csabam8_pg_rca_h2_v3_and1_4 = a[1] & b[4];
  assign f_u_csabam8_pg_rca_h2_v3_fa1_4_xor0 = f_u_csabam8_pg_rca_h2_v3_and1_4 ^ f_u_csabam8_pg_rca_h2_v3_ha2_3_xor0;
  assign f_u_csabam8_pg_rca_h2_v3_fa1_4_and0 = f_u_csabam8_pg_rca_h2_v3_and1_4 & f_u_csabam8_pg_rca_h2_v3_ha2_3_xor0;
  assign f_u_csabam8_pg_rca_h2_v3_fa1_4_xor1 = f_u_csabam8_pg_rca_h2_v3_fa1_4_xor0 ^ f_u_csabam8_pg_rca_h2_v3_ha1_3_and0;
  assign f_u_csabam8_pg_rca_h2_v3_fa1_4_and1 = f_u_csabam8_pg_rca_h2_v3_fa1_4_xor0 & f_u_csabam8_pg_rca_h2_v3_ha1_3_and0;
  assign f_u_csabam8_pg_rca_h2_v3_fa1_4_or0 = f_u_csabam8_pg_rca_h2_v3_fa1_4_and0 | f_u_csabam8_pg_rca_h2_v3_fa1_4_and1;
  assign f_u_csabam8_pg_rca_h2_v3_and2_4 = a[2] & b[4];
  assign f_u_csabam8_pg_rca_h2_v3_fa2_4_xor0 = f_u_csabam8_pg_rca_h2_v3_and2_4 ^ f_u_csabam8_pg_rca_h2_v3_ha3_3_xor0;
  assign f_u_csabam8_pg_rca_h2_v3_fa2_4_and0 = f_u_csabam8_pg_rca_h2_v3_and2_4 & f_u_csabam8_pg_rca_h2_v3_ha3_3_xor0;
  assign f_u_csabam8_pg_rca_h2_v3_fa2_4_xor1 = f_u_csabam8_pg_rca_h2_v3_fa2_4_xor0 ^ f_u_csabam8_pg_rca_h2_v3_ha2_3_and0;
  assign f_u_csabam8_pg_rca_h2_v3_fa2_4_and1 = f_u_csabam8_pg_rca_h2_v3_fa2_4_xor0 & f_u_csabam8_pg_rca_h2_v3_ha2_3_and0;
  assign f_u_csabam8_pg_rca_h2_v3_fa2_4_or0 = f_u_csabam8_pg_rca_h2_v3_fa2_4_and0 | f_u_csabam8_pg_rca_h2_v3_fa2_4_and1;
  assign f_u_csabam8_pg_rca_h2_v3_and3_4 = a[3] & b[4];
  assign f_u_csabam8_pg_rca_h2_v3_fa3_4_xor0 = f_u_csabam8_pg_rca_h2_v3_and3_4 ^ f_u_csabam8_pg_rca_h2_v3_ha4_3_xor0;
  assign f_u_csabam8_pg_rca_h2_v3_fa3_4_and0 = f_u_csabam8_pg_rca_h2_v3_and3_4 & f_u_csabam8_pg_rca_h2_v3_ha4_3_xor0;
  assign f_u_csabam8_pg_rca_h2_v3_fa3_4_xor1 = f_u_csabam8_pg_rca_h2_v3_fa3_4_xor0 ^ f_u_csabam8_pg_rca_h2_v3_ha3_3_and0;
  assign f_u_csabam8_pg_rca_h2_v3_fa3_4_and1 = f_u_csabam8_pg_rca_h2_v3_fa3_4_xor0 & f_u_csabam8_pg_rca_h2_v3_ha3_3_and0;
  assign f_u_csabam8_pg_rca_h2_v3_fa3_4_or0 = f_u_csabam8_pg_rca_h2_v3_fa3_4_and0 | f_u_csabam8_pg_rca_h2_v3_fa3_4_and1;
  assign f_u_csabam8_pg_rca_h2_v3_and4_4 = a[4] & b[4];
  assign f_u_csabam8_pg_rca_h2_v3_fa4_4_xor0 = f_u_csabam8_pg_rca_h2_v3_and4_4 ^ f_u_csabam8_pg_rca_h2_v3_ha5_3_xor0;
  assign f_u_csabam8_pg_rca_h2_v3_fa4_4_and0 = f_u_csabam8_pg_rca_h2_v3_and4_4 & f_u_csabam8_pg_rca_h2_v3_ha5_3_xor0;
  assign f_u_csabam8_pg_rca_h2_v3_fa4_4_xor1 = f_u_csabam8_pg_rca_h2_v3_fa4_4_xor0 ^ f_u_csabam8_pg_rca_h2_v3_ha4_3_and0;
  assign f_u_csabam8_pg_rca_h2_v3_fa4_4_and1 = f_u_csabam8_pg_rca_h2_v3_fa4_4_xor0 & f_u_csabam8_pg_rca_h2_v3_ha4_3_and0;
  assign f_u_csabam8_pg_rca_h2_v3_fa4_4_or0 = f_u_csabam8_pg_rca_h2_v3_fa4_4_and0 | f_u_csabam8_pg_rca_h2_v3_fa4_4_and1;
  assign f_u_csabam8_pg_rca_h2_v3_and5_4 = a[5] & b[4];
  assign f_u_csabam8_pg_rca_h2_v3_fa5_4_xor0 = f_u_csabam8_pg_rca_h2_v3_and5_4 ^ f_u_csabam8_pg_rca_h2_v3_ha6_3_xor0;
  assign f_u_csabam8_pg_rca_h2_v3_fa5_4_and0 = f_u_csabam8_pg_rca_h2_v3_and5_4 & f_u_csabam8_pg_rca_h2_v3_ha6_3_xor0;
  assign f_u_csabam8_pg_rca_h2_v3_fa5_4_xor1 = f_u_csabam8_pg_rca_h2_v3_fa5_4_xor0 ^ f_u_csabam8_pg_rca_h2_v3_ha5_3_and0;
  assign f_u_csabam8_pg_rca_h2_v3_fa5_4_and1 = f_u_csabam8_pg_rca_h2_v3_fa5_4_xor0 & f_u_csabam8_pg_rca_h2_v3_ha5_3_and0;
  assign f_u_csabam8_pg_rca_h2_v3_fa5_4_or0 = f_u_csabam8_pg_rca_h2_v3_fa5_4_and0 | f_u_csabam8_pg_rca_h2_v3_fa5_4_and1;
  assign f_u_csabam8_pg_rca_h2_v3_and6_4 = a[6] & b[4];
  assign f_u_csabam8_pg_rca_h2_v3_fa6_4_xor0 = f_u_csabam8_pg_rca_h2_v3_and6_4 ^ f_u_csabam8_pg_rca_h2_v3_and7_3;
  assign f_u_csabam8_pg_rca_h2_v3_fa6_4_and0 = f_u_csabam8_pg_rca_h2_v3_and6_4 & f_u_csabam8_pg_rca_h2_v3_and7_3;
  assign f_u_csabam8_pg_rca_h2_v3_fa6_4_xor1 = f_u_csabam8_pg_rca_h2_v3_fa6_4_xor0 ^ f_u_csabam8_pg_rca_h2_v3_ha6_3_and0;
  assign f_u_csabam8_pg_rca_h2_v3_fa6_4_and1 = f_u_csabam8_pg_rca_h2_v3_fa6_4_xor0 & f_u_csabam8_pg_rca_h2_v3_ha6_3_and0;
  assign f_u_csabam8_pg_rca_h2_v3_fa6_4_or0 = f_u_csabam8_pg_rca_h2_v3_fa6_4_and0 | f_u_csabam8_pg_rca_h2_v3_fa6_4_and1;
  assign f_u_csabam8_pg_rca_h2_v3_and7_4 = a[7] & b[4];
  assign f_u_csabam8_pg_rca_h2_v3_and0_5 = a[0] & b[5];
  assign f_u_csabam8_pg_rca_h2_v3_fa0_5_xor0 = f_u_csabam8_pg_rca_h2_v3_and0_5 ^ f_u_csabam8_pg_rca_h2_v3_fa1_4_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_fa0_5_and0 = f_u_csabam8_pg_rca_h2_v3_and0_5 & f_u_csabam8_pg_rca_h2_v3_fa1_4_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_fa0_5_xor1 = f_u_csabam8_pg_rca_h2_v3_fa0_5_xor0 ^ f_u_csabam8_pg_rca_h2_v3_fa0_4_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa0_5_and1 = f_u_csabam8_pg_rca_h2_v3_fa0_5_xor0 & f_u_csabam8_pg_rca_h2_v3_fa0_4_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa0_5_or0 = f_u_csabam8_pg_rca_h2_v3_fa0_5_and0 | f_u_csabam8_pg_rca_h2_v3_fa0_5_and1;
  assign f_u_csabam8_pg_rca_h2_v3_and1_5 = a[1] & b[5];
  assign f_u_csabam8_pg_rca_h2_v3_fa1_5_xor0 = f_u_csabam8_pg_rca_h2_v3_and1_5 ^ f_u_csabam8_pg_rca_h2_v3_fa2_4_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_fa1_5_and0 = f_u_csabam8_pg_rca_h2_v3_and1_5 & f_u_csabam8_pg_rca_h2_v3_fa2_4_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_fa1_5_xor1 = f_u_csabam8_pg_rca_h2_v3_fa1_5_xor0 ^ f_u_csabam8_pg_rca_h2_v3_fa1_4_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa1_5_and1 = f_u_csabam8_pg_rca_h2_v3_fa1_5_xor0 & f_u_csabam8_pg_rca_h2_v3_fa1_4_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa1_5_or0 = f_u_csabam8_pg_rca_h2_v3_fa1_5_and0 | f_u_csabam8_pg_rca_h2_v3_fa1_5_and1;
  assign f_u_csabam8_pg_rca_h2_v3_and2_5 = a[2] & b[5];
  assign f_u_csabam8_pg_rca_h2_v3_fa2_5_xor0 = f_u_csabam8_pg_rca_h2_v3_and2_5 ^ f_u_csabam8_pg_rca_h2_v3_fa3_4_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_fa2_5_and0 = f_u_csabam8_pg_rca_h2_v3_and2_5 & f_u_csabam8_pg_rca_h2_v3_fa3_4_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_fa2_5_xor1 = f_u_csabam8_pg_rca_h2_v3_fa2_5_xor0 ^ f_u_csabam8_pg_rca_h2_v3_fa2_4_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa2_5_and1 = f_u_csabam8_pg_rca_h2_v3_fa2_5_xor0 & f_u_csabam8_pg_rca_h2_v3_fa2_4_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa2_5_or0 = f_u_csabam8_pg_rca_h2_v3_fa2_5_and0 | f_u_csabam8_pg_rca_h2_v3_fa2_5_and1;
  assign f_u_csabam8_pg_rca_h2_v3_and3_5 = a[3] & b[5];
  assign f_u_csabam8_pg_rca_h2_v3_fa3_5_xor0 = f_u_csabam8_pg_rca_h2_v3_and3_5 ^ f_u_csabam8_pg_rca_h2_v3_fa4_4_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_fa3_5_and0 = f_u_csabam8_pg_rca_h2_v3_and3_5 & f_u_csabam8_pg_rca_h2_v3_fa4_4_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_fa3_5_xor1 = f_u_csabam8_pg_rca_h2_v3_fa3_5_xor0 ^ f_u_csabam8_pg_rca_h2_v3_fa3_4_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa3_5_and1 = f_u_csabam8_pg_rca_h2_v3_fa3_5_xor0 & f_u_csabam8_pg_rca_h2_v3_fa3_4_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa3_5_or0 = f_u_csabam8_pg_rca_h2_v3_fa3_5_and0 | f_u_csabam8_pg_rca_h2_v3_fa3_5_and1;
  assign f_u_csabam8_pg_rca_h2_v3_and4_5 = a[4] & b[5];
  assign f_u_csabam8_pg_rca_h2_v3_fa4_5_xor0 = f_u_csabam8_pg_rca_h2_v3_and4_5 ^ f_u_csabam8_pg_rca_h2_v3_fa5_4_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_fa4_5_and0 = f_u_csabam8_pg_rca_h2_v3_and4_5 & f_u_csabam8_pg_rca_h2_v3_fa5_4_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_fa4_5_xor1 = f_u_csabam8_pg_rca_h2_v3_fa4_5_xor0 ^ f_u_csabam8_pg_rca_h2_v3_fa4_4_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa4_5_and1 = f_u_csabam8_pg_rca_h2_v3_fa4_5_xor0 & f_u_csabam8_pg_rca_h2_v3_fa4_4_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa4_5_or0 = f_u_csabam8_pg_rca_h2_v3_fa4_5_and0 | f_u_csabam8_pg_rca_h2_v3_fa4_5_and1;
  assign f_u_csabam8_pg_rca_h2_v3_and5_5 = a[5] & b[5];
  assign f_u_csabam8_pg_rca_h2_v3_fa5_5_xor0 = f_u_csabam8_pg_rca_h2_v3_and5_5 ^ f_u_csabam8_pg_rca_h2_v3_fa6_4_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_fa5_5_and0 = f_u_csabam8_pg_rca_h2_v3_and5_5 & f_u_csabam8_pg_rca_h2_v3_fa6_4_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_fa5_5_xor1 = f_u_csabam8_pg_rca_h2_v3_fa5_5_xor0 ^ f_u_csabam8_pg_rca_h2_v3_fa5_4_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa5_5_and1 = f_u_csabam8_pg_rca_h2_v3_fa5_5_xor0 & f_u_csabam8_pg_rca_h2_v3_fa5_4_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa5_5_or0 = f_u_csabam8_pg_rca_h2_v3_fa5_5_and0 | f_u_csabam8_pg_rca_h2_v3_fa5_5_and1;
  assign f_u_csabam8_pg_rca_h2_v3_and6_5 = a[6] & b[5];
  assign f_u_csabam8_pg_rca_h2_v3_fa6_5_xor0 = f_u_csabam8_pg_rca_h2_v3_and6_5 ^ f_u_csabam8_pg_rca_h2_v3_and7_4;
  assign f_u_csabam8_pg_rca_h2_v3_fa6_5_and0 = f_u_csabam8_pg_rca_h2_v3_and6_5 & f_u_csabam8_pg_rca_h2_v3_and7_4;
  assign f_u_csabam8_pg_rca_h2_v3_fa6_5_xor1 = f_u_csabam8_pg_rca_h2_v3_fa6_5_xor0 ^ f_u_csabam8_pg_rca_h2_v3_fa6_4_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa6_5_and1 = f_u_csabam8_pg_rca_h2_v3_fa6_5_xor0 & f_u_csabam8_pg_rca_h2_v3_fa6_4_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa6_5_or0 = f_u_csabam8_pg_rca_h2_v3_fa6_5_and0 | f_u_csabam8_pg_rca_h2_v3_fa6_5_and1;
  assign f_u_csabam8_pg_rca_h2_v3_and7_5 = a[7] & b[5];
  assign f_u_csabam8_pg_rca_h2_v3_and0_6 = a[0] & b[6];
  assign f_u_csabam8_pg_rca_h2_v3_fa0_6_xor0 = f_u_csabam8_pg_rca_h2_v3_and0_6 ^ f_u_csabam8_pg_rca_h2_v3_fa1_5_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_fa0_6_and0 = f_u_csabam8_pg_rca_h2_v3_and0_6 & f_u_csabam8_pg_rca_h2_v3_fa1_5_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_fa0_6_xor1 = f_u_csabam8_pg_rca_h2_v3_fa0_6_xor0 ^ f_u_csabam8_pg_rca_h2_v3_fa0_5_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa0_6_and1 = f_u_csabam8_pg_rca_h2_v3_fa0_6_xor0 & f_u_csabam8_pg_rca_h2_v3_fa0_5_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa0_6_or0 = f_u_csabam8_pg_rca_h2_v3_fa0_6_and0 | f_u_csabam8_pg_rca_h2_v3_fa0_6_and1;
  assign f_u_csabam8_pg_rca_h2_v3_and1_6 = a[1] & b[6];
  assign f_u_csabam8_pg_rca_h2_v3_fa1_6_xor0 = f_u_csabam8_pg_rca_h2_v3_and1_6 ^ f_u_csabam8_pg_rca_h2_v3_fa2_5_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_fa1_6_and0 = f_u_csabam8_pg_rca_h2_v3_and1_6 & f_u_csabam8_pg_rca_h2_v3_fa2_5_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_fa1_6_xor1 = f_u_csabam8_pg_rca_h2_v3_fa1_6_xor0 ^ f_u_csabam8_pg_rca_h2_v3_fa1_5_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa1_6_and1 = f_u_csabam8_pg_rca_h2_v3_fa1_6_xor0 & f_u_csabam8_pg_rca_h2_v3_fa1_5_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa1_6_or0 = f_u_csabam8_pg_rca_h2_v3_fa1_6_and0 | f_u_csabam8_pg_rca_h2_v3_fa1_6_and1;
  assign f_u_csabam8_pg_rca_h2_v3_and2_6 = a[2] & b[6];
  assign f_u_csabam8_pg_rca_h2_v3_fa2_6_xor0 = f_u_csabam8_pg_rca_h2_v3_and2_6 ^ f_u_csabam8_pg_rca_h2_v3_fa3_5_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_fa2_6_and0 = f_u_csabam8_pg_rca_h2_v3_and2_6 & f_u_csabam8_pg_rca_h2_v3_fa3_5_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_fa2_6_xor1 = f_u_csabam8_pg_rca_h2_v3_fa2_6_xor0 ^ f_u_csabam8_pg_rca_h2_v3_fa2_5_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa2_6_and1 = f_u_csabam8_pg_rca_h2_v3_fa2_6_xor0 & f_u_csabam8_pg_rca_h2_v3_fa2_5_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa2_6_or0 = f_u_csabam8_pg_rca_h2_v3_fa2_6_and0 | f_u_csabam8_pg_rca_h2_v3_fa2_6_and1;
  assign f_u_csabam8_pg_rca_h2_v3_and3_6 = a[3] & b[6];
  assign f_u_csabam8_pg_rca_h2_v3_fa3_6_xor0 = f_u_csabam8_pg_rca_h2_v3_and3_6 ^ f_u_csabam8_pg_rca_h2_v3_fa4_5_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_fa3_6_and0 = f_u_csabam8_pg_rca_h2_v3_and3_6 & f_u_csabam8_pg_rca_h2_v3_fa4_5_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_fa3_6_xor1 = f_u_csabam8_pg_rca_h2_v3_fa3_6_xor0 ^ f_u_csabam8_pg_rca_h2_v3_fa3_5_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa3_6_and1 = f_u_csabam8_pg_rca_h2_v3_fa3_6_xor0 & f_u_csabam8_pg_rca_h2_v3_fa3_5_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa3_6_or0 = f_u_csabam8_pg_rca_h2_v3_fa3_6_and0 | f_u_csabam8_pg_rca_h2_v3_fa3_6_and1;
  assign f_u_csabam8_pg_rca_h2_v3_and4_6 = a[4] & b[6];
  assign f_u_csabam8_pg_rca_h2_v3_fa4_6_xor0 = f_u_csabam8_pg_rca_h2_v3_and4_6 ^ f_u_csabam8_pg_rca_h2_v3_fa5_5_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_fa4_6_and0 = f_u_csabam8_pg_rca_h2_v3_and4_6 & f_u_csabam8_pg_rca_h2_v3_fa5_5_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_fa4_6_xor1 = f_u_csabam8_pg_rca_h2_v3_fa4_6_xor0 ^ f_u_csabam8_pg_rca_h2_v3_fa4_5_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa4_6_and1 = f_u_csabam8_pg_rca_h2_v3_fa4_6_xor0 & f_u_csabam8_pg_rca_h2_v3_fa4_5_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa4_6_or0 = f_u_csabam8_pg_rca_h2_v3_fa4_6_and0 | f_u_csabam8_pg_rca_h2_v3_fa4_6_and1;
  assign f_u_csabam8_pg_rca_h2_v3_and5_6 = a[5] & b[6];
  assign f_u_csabam8_pg_rca_h2_v3_fa5_6_xor0 = f_u_csabam8_pg_rca_h2_v3_and5_6 ^ f_u_csabam8_pg_rca_h2_v3_fa6_5_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_fa5_6_and0 = f_u_csabam8_pg_rca_h2_v3_and5_6 & f_u_csabam8_pg_rca_h2_v3_fa6_5_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_fa5_6_xor1 = f_u_csabam8_pg_rca_h2_v3_fa5_6_xor0 ^ f_u_csabam8_pg_rca_h2_v3_fa5_5_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa5_6_and1 = f_u_csabam8_pg_rca_h2_v3_fa5_6_xor0 & f_u_csabam8_pg_rca_h2_v3_fa5_5_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa5_6_or0 = f_u_csabam8_pg_rca_h2_v3_fa5_6_and0 | f_u_csabam8_pg_rca_h2_v3_fa5_6_and1;
  assign f_u_csabam8_pg_rca_h2_v3_and6_6 = a[6] & b[6];
  assign f_u_csabam8_pg_rca_h2_v3_fa6_6_xor0 = f_u_csabam8_pg_rca_h2_v3_and6_6 ^ f_u_csabam8_pg_rca_h2_v3_and7_5;
  assign f_u_csabam8_pg_rca_h2_v3_fa6_6_and0 = f_u_csabam8_pg_rca_h2_v3_and6_6 & f_u_csabam8_pg_rca_h2_v3_and7_5;
  assign f_u_csabam8_pg_rca_h2_v3_fa6_6_xor1 = f_u_csabam8_pg_rca_h2_v3_fa6_6_xor0 ^ f_u_csabam8_pg_rca_h2_v3_fa6_5_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa6_6_and1 = f_u_csabam8_pg_rca_h2_v3_fa6_6_xor0 & f_u_csabam8_pg_rca_h2_v3_fa6_5_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa6_6_or0 = f_u_csabam8_pg_rca_h2_v3_fa6_6_and0 | f_u_csabam8_pg_rca_h2_v3_fa6_6_and1;
  assign f_u_csabam8_pg_rca_h2_v3_and7_6 = a[7] & b[6];
  assign f_u_csabam8_pg_rca_h2_v3_and0_7 = a[0] & b[7];
  assign f_u_csabam8_pg_rca_h2_v3_fa0_7_xor0 = f_u_csabam8_pg_rca_h2_v3_and0_7 ^ f_u_csabam8_pg_rca_h2_v3_fa1_6_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_fa0_7_and0 = f_u_csabam8_pg_rca_h2_v3_and0_7 & f_u_csabam8_pg_rca_h2_v3_fa1_6_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_fa0_7_xor1 = f_u_csabam8_pg_rca_h2_v3_fa0_7_xor0 ^ f_u_csabam8_pg_rca_h2_v3_fa0_6_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa0_7_and1 = f_u_csabam8_pg_rca_h2_v3_fa0_7_xor0 & f_u_csabam8_pg_rca_h2_v3_fa0_6_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa0_7_or0 = f_u_csabam8_pg_rca_h2_v3_fa0_7_and0 | f_u_csabam8_pg_rca_h2_v3_fa0_7_and1;
  assign f_u_csabam8_pg_rca_h2_v3_and1_7 = a[1] & b[7];
  assign f_u_csabam8_pg_rca_h2_v3_fa1_7_xor0 = f_u_csabam8_pg_rca_h2_v3_and1_7 ^ f_u_csabam8_pg_rca_h2_v3_fa2_6_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_fa1_7_and0 = f_u_csabam8_pg_rca_h2_v3_and1_7 & f_u_csabam8_pg_rca_h2_v3_fa2_6_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_fa1_7_xor1 = f_u_csabam8_pg_rca_h2_v3_fa1_7_xor0 ^ f_u_csabam8_pg_rca_h2_v3_fa1_6_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa1_7_and1 = f_u_csabam8_pg_rca_h2_v3_fa1_7_xor0 & f_u_csabam8_pg_rca_h2_v3_fa1_6_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa1_7_or0 = f_u_csabam8_pg_rca_h2_v3_fa1_7_and0 | f_u_csabam8_pg_rca_h2_v3_fa1_7_and1;
  assign f_u_csabam8_pg_rca_h2_v3_and2_7 = a[2] & b[7];
  assign f_u_csabam8_pg_rca_h2_v3_fa2_7_xor0 = f_u_csabam8_pg_rca_h2_v3_and2_7 ^ f_u_csabam8_pg_rca_h2_v3_fa3_6_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_fa2_7_and0 = f_u_csabam8_pg_rca_h2_v3_and2_7 & f_u_csabam8_pg_rca_h2_v3_fa3_6_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_fa2_7_xor1 = f_u_csabam8_pg_rca_h2_v3_fa2_7_xor0 ^ f_u_csabam8_pg_rca_h2_v3_fa2_6_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa2_7_and1 = f_u_csabam8_pg_rca_h2_v3_fa2_7_xor0 & f_u_csabam8_pg_rca_h2_v3_fa2_6_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa2_7_or0 = f_u_csabam8_pg_rca_h2_v3_fa2_7_and0 | f_u_csabam8_pg_rca_h2_v3_fa2_7_and1;
  assign f_u_csabam8_pg_rca_h2_v3_and3_7 = a[3] & b[7];
  assign f_u_csabam8_pg_rca_h2_v3_fa3_7_xor0 = f_u_csabam8_pg_rca_h2_v3_and3_7 ^ f_u_csabam8_pg_rca_h2_v3_fa4_6_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_fa3_7_and0 = f_u_csabam8_pg_rca_h2_v3_and3_7 & f_u_csabam8_pg_rca_h2_v3_fa4_6_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_fa3_7_xor1 = f_u_csabam8_pg_rca_h2_v3_fa3_7_xor0 ^ f_u_csabam8_pg_rca_h2_v3_fa3_6_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa3_7_and1 = f_u_csabam8_pg_rca_h2_v3_fa3_7_xor0 & f_u_csabam8_pg_rca_h2_v3_fa3_6_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa3_7_or0 = f_u_csabam8_pg_rca_h2_v3_fa3_7_and0 | f_u_csabam8_pg_rca_h2_v3_fa3_7_and1;
  assign f_u_csabam8_pg_rca_h2_v3_and4_7 = a[4] & b[7];
  assign f_u_csabam8_pg_rca_h2_v3_fa4_7_xor0 = f_u_csabam8_pg_rca_h2_v3_and4_7 ^ f_u_csabam8_pg_rca_h2_v3_fa5_6_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_fa4_7_and0 = f_u_csabam8_pg_rca_h2_v3_and4_7 & f_u_csabam8_pg_rca_h2_v3_fa5_6_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_fa4_7_xor1 = f_u_csabam8_pg_rca_h2_v3_fa4_7_xor0 ^ f_u_csabam8_pg_rca_h2_v3_fa4_6_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa4_7_and1 = f_u_csabam8_pg_rca_h2_v3_fa4_7_xor0 & f_u_csabam8_pg_rca_h2_v3_fa4_6_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa4_7_or0 = f_u_csabam8_pg_rca_h2_v3_fa4_7_and0 | f_u_csabam8_pg_rca_h2_v3_fa4_7_and1;
  assign f_u_csabam8_pg_rca_h2_v3_and5_7 = a[5] & b[7];
  assign f_u_csabam8_pg_rca_h2_v3_fa5_7_xor0 = f_u_csabam8_pg_rca_h2_v3_and5_7 ^ f_u_csabam8_pg_rca_h2_v3_fa6_6_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_fa5_7_and0 = f_u_csabam8_pg_rca_h2_v3_and5_7 & f_u_csabam8_pg_rca_h2_v3_fa6_6_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_fa5_7_xor1 = f_u_csabam8_pg_rca_h2_v3_fa5_7_xor0 ^ f_u_csabam8_pg_rca_h2_v3_fa5_6_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa5_7_and1 = f_u_csabam8_pg_rca_h2_v3_fa5_7_xor0 & f_u_csabam8_pg_rca_h2_v3_fa5_6_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa5_7_or0 = f_u_csabam8_pg_rca_h2_v3_fa5_7_and0 | f_u_csabam8_pg_rca_h2_v3_fa5_7_and1;
  assign f_u_csabam8_pg_rca_h2_v3_and6_7 = a[6] & b[7];
  assign f_u_csabam8_pg_rca_h2_v3_fa6_7_xor0 = f_u_csabam8_pg_rca_h2_v3_and6_7 ^ f_u_csabam8_pg_rca_h2_v3_and7_6;
  assign f_u_csabam8_pg_rca_h2_v3_fa6_7_and0 = f_u_csabam8_pg_rca_h2_v3_and6_7 & f_u_csabam8_pg_rca_h2_v3_and7_6;
  assign f_u_csabam8_pg_rca_h2_v3_fa6_7_xor1 = f_u_csabam8_pg_rca_h2_v3_fa6_7_xor0 ^ f_u_csabam8_pg_rca_h2_v3_fa6_6_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa6_7_and1 = f_u_csabam8_pg_rca_h2_v3_fa6_7_xor0 & f_u_csabam8_pg_rca_h2_v3_fa6_6_or0;
  assign f_u_csabam8_pg_rca_h2_v3_fa6_7_or0 = f_u_csabam8_pg_rca_h2_v3_fa6_7_and0 | f_u_csabam8_pg_rca_h2_v3_fa6_7_and1;
  assign f_u_csabam8_pg_rca_h2_v3_and7_7 = a[7] & b[7];
  assign f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa0_xor0 = f_u_csabam8_pg_rca_h2_v3_fa1_7_xor1 ^ f_u_csabam8_pg_rca_h2_v3_fa0_7_or0;
  assign f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa0_and0 = f_u_csabam8_pg_rca_h2_v3_fa1_7_xor1 & f_u_csabam8_pg_rca_h2_v3_fa0_7_or0;
  assign f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa1_xor0 = f_u_csabam8_pg_rca_h2_v3_fa2_7_xor1 ^ f_u_csabam8_pg_rca_h2_v3_fa1_7_or0;
  assign f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa1_and0 = f_u_csabam8_pg_rca_h2_v3_fa2_7_xor1 & f_u_csabam8_pg_rca_h2_v3_fa1_7_or0;
  assign f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa1_xor1 = f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa1_xor0 ^ f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa0_and0;
  assign f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_and1 = f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa0_and0 & f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa1_xor0;
  assign f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_or1 = f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_and1 | f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa1_and0;
  assign f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa2_xor0 = f_u_csabam8_pg_rca_h2_v3_fa3_7_xor1 ^ f_u_csabam8_pg_rca_h2_v3_fa2_7_or0;
  assign f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa2_and0 = f_u_csabam8_pg_rca_h2_v3_fa3_7_xor1 & f_u_csabam8_pg_rca_h2_v3_fa2_7_or0;
  assign f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa2_xor1 = f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa2_xor0 ^ f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_or1;
  assign f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_and2 = f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_or1 & f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa2_xor0;
  assign f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_or2 = f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_and2 | f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa2_and0;
  assign f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa3_xor0 = f_u_csabam8_pg_rca_h2_v3_fa4_7_xor1 ^ f_u_csabam8_pg_rca_h2_v3_fa3_7_or0;
  assign f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa3_and0 = f_u_csabam8_pg_rca_h2_v3_fa4_7_xor1 & f_u_csabam8_pg_rca_h2_v3_fa3_7_or0;
  assign f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa3_xor1 = f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa3_xor0 ^ f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_or2;
  assign f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_and3 = f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_or2 & f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa3_xor0;
  assign f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_or3 = f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_and3 | f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa3_and0;
  assign f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa4_xor0 = f_u_csabam8_pg_rca_h2_v3_fa5_7_xor1 ^ f_u_csabam8_pg_rca_h2_v3_fa4_7_or0;
  assign f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa4_and0 = f_u_csabam8_pg_rca_h2_v3_fa5_7_xor1 & f_u_csabam8_pg_rca_h2_v3_fa4_7_or0;
  assign f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa4_xor1 = f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa4_xor0 ^ f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_or3;
  assign f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_and4 = f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_or3 & f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa4_xor0;
  assign f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_or4 = f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_and4 | f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa4_and0;
  assign f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa5_xor0 = f_u_csabam8_pg_rca_h2_v3_fa6_7_xor1 ^ f_u_csabam8_pg_rca_h2_v3_fa5_7_or0;
  assign f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa5_and0 = f_u_csabam8_pg_rca_h2_v3_fa6_7_xor1 & f_u_csabam8_pg_rca_h2_v3_fa5_7_or0;
  assign f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa5_xor1 = f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa5_xor0 ^ f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_or4;
  assign f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_and5 = f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_or4 & f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa5_xor0;
  assign f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_or5 = f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_and5 | f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa5_and0;
  assign f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa6_xor0 = f_u_csabam8_pg_rca_h2_v3_and7_7 ^ f_u_csabam8_pg_rca_h2_v3_fa6_7_or0;
  assign f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa6_and0 = f_u_csabam8_pg_rca_h2_v3_and7_7 & f_u_csabam8_pg_rca_h2_v3_fa6_7_or0;
  assign f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa6_xor1 = f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa6_xor0 ^ f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_or5;
  assign f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_and6 = f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_or5 & f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa6_xor0;
  assign f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_or6 = f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_and6 | f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa6_and0;

  assign f_u_csabam8_pg_rca_h2_v3_out[0] = 1'b0;
  assign f_u_csabam8_pg_rca_h2_v3_out[1] = 1'b0;
  assign f_u_csabam8_pg_rca_h2_v3_out[2] = 1'b0;
  assign f_u_csabam8_pg_rca_h2_v3_out[3] = f_u_csabam8_pg_rca_h2_v3_ha0_3_xor0;
  assign f_u_csabam8_pg_rca_h2_v3_out[4] = f_u_csabam8_pg_rca_h2_v3_fa0_4_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_out[5] = f_u_csabam8_pg_rca_h2_v3_fa0_5_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_out[6] = f_u_csabam8_pg_rca_h2_v3_fa0_6_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_out[7] = f_u_csabam8_pg_rca_h2_v3_fa0_7_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_out[8] = f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa0_xor0;
  assign f_u_csabam8_pg_rca_h2_v3_out[9] = f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa1_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_out[10] = f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa2_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_out[11] = f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa3_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_out[12] = f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa4_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_out[13] = f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa5_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_out[14] = f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_pg_fa6_xor1;
  assign f_u_csabam8_pg_rca_h2_v3_out[15] = f_u_csabam8_pg_rca_h2_v3_u_pg_rca8_or6;
endmodule