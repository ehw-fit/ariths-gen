module f_u_arrtm8_k3(input [7:0] a, input [7:0] b, output [15:0] f_u_arrtm8_k3_out);
  wire f_u_arrtm8_k3_and3_3;
  wire f_u_arrtm8_k3_and4_3;
  wire f_u_arrtm8_k3_and5_3;
  wire f_u_arrtm8_k3_and6_3;
  wire f_u_arrtm8_k3_and7_3;
  wire f_u_arrtm8_k3_and3_4;
  wire f_u_arrtm8_k3_ha3_4_xor0;
  wire f_u_arrtm8_k3_ha3_4_and0;
  wire f_u_arrtm8_k3_and4_4;
  wire f_u_arrtm8_k3_ha4_4_xor0;
  wire f_u_arrtm8_k3_ha4_4_and0;
  wire f_u_arrtm8_k3_and5_4;
  wire f_u_arrtm8_k3_ha5_4_xor0;
  wire f_u_arrtm8_k3_ha5_4_and0;
  wire f_u_arrtm8_k3_and6_4;
  wire f_u_arrtm8_k3_ha6_4_xor0;
  wire f_u_arrtm8_k3_ha6_4_and0;
  wire f_u_arrtm8_k3_and7_4;
  wire f_u_arrtm8_k3_and3_5;
  wire f_u_arrtm8_k3_fa3_5_xor0;
  wire f_u_arrtm8_k3_fa3_5_and0;
  wire f_u_arrtm8_k3_fa3_5_xor1;
  wire f_u_arrtm8_k3_fa3_5_and1;
  wire f_u_arrtm8_k3_fa3_5_or0;
  wire f_u_arrtm8_k3_and4_5;
  wire f_u_arrtm8_k3_fa4_5_xor0;
  wire f_u_arrtm8_k3_fa4_5_and0;
  wire f_u_arrtm8_k3_fa4_5_xor1;
  wire f_u_arrtm8_k3_fa4_5_and1;
  wire f_u_arrtm8_k3_fa4_5_or0;
  wire f_u_arrtm8_k3_and5_5;
  wire f_u_arrtm8_k3_fa5_5_xor0;
  wire f_u_arrtm8_k3_fa5_5_and0;
  wire f_u_arrtm8_k3_fa5_5_xor1;
  wire f_u_arrtm8_k3_fa5_5_and1;
  wire f_u_arrtm8_k3_fa5_5_or0;
  wire f_u_arrtm8_k3_and6_5;
  wire f_u_arrtm8_k3_fa6_5_xor0;
  wire f_u_arrtm8_k3_fa6_5_and0;
  wire f_u_arrtm8_k3_fa6_5_xor1;
  wire f_u_arrtm8_k3_fa6_5_and1;
  wire f_u_arrtm8_k3_fa6_5_or0;
  wire f_u_arrtm8_k3_and7_5;
  wire f_u_arrtm8_k3_and3_6;
  wire f_u_arrtm8_k3_fa3_6_xor0;
  wire f_u_arrtm8_k3_fa3_6_and0;
  wire f_u_arrtm8_k3_fa3_6_xor1;
  wire f_u_arrtm8_k3_fa3_6_and1;
  wire f_u_arrtm8_k3_fa3_6_or0;
  wire f_u_arrtm8_k3_and4_6;
  wire f_u_arrtm8_k3_fa4_6_xor0;
  wire f_u_arrtm8_k3_fa4_6_and0;
  wire f_u_arrtm8_k3_fa4_6_xor1;
  wire f_u_arrtm8_k3_fa4_6_and1;
  wire f_u_arrtm8_k3_fa4_6_or0;
  wire f_u_arrtm8_k3_and5_6;
  wire f_u_arrtm8_k3_fa5_6_xor0;
  wire f_u_arrtm8_k3_fa5_6_and0;
  wire f_u_arrtm8_k3_fa5_6_xor1;
  wire f_u_arrtm8_k3_fa5_6_and1;
  wire f_u_arrtm8_k3_fa5_6_or0;
  wire f_u_arrtm8_k3_and6_6;
  wire f_u_arrtm8_k3_fa6_6_xor0;
  wire f_u_arrtm8_k3_fa6_6_and0;
  wire f_u_arrtm8_k3_fa6_6_xor1;
  wire f_u_arrtm8_k3_fa6_6_and1;
  wire f_u_arrtm8_k3_fa6_6_or0;
  wire f_u_arrtm8_k3_and7_6;
  wire f_u_arrtm8_k3_and3_7;
  wire f_u_arrtm8_k3_fa3_7_xor0;
  wire f_u_arrtm8_k3_fa3_7_and0;
  wire f_u_arrtm8_k3_fa3_7_xor1;
  wire f_u_arrtm8_k3_fa3_7_and1;
  wire f_u_arrtm8_k3_fa3_7_or0;
  wire f_u_arrtm8_k3_and4_7;
  wire f_u_arrtm8_k3_fa4_7_xor0;
  wire f_u_arrtm8_k3_fa4_7_and0;
  wire f_u_arrtm8_k3_fa4_7_xor1;
  wire f_u_arrtm8_k3_fa4_7_and1;
  wire f_u_arrtm8_k3_fa4_7_or0;
  wire f_u_arrtm8_k3_and5_7;
  wire f_u_arrtm8_k3_fa5_7_xor0;
  wire f_u_arrtm8_k3_fa5_7_and0;
  wire f_u_arrtm8_k3_fa5_7_xor1;
  wire f_u_arrtm8_k3_fa5_7_and1;
  wire f_u_arrtm8_k3_fa5_7_or0;
  wire f_u_arrtm8_k3_and6_7;
  wire f_u_arrtm8_k3_fa6_7_xor0;
  wire f_u_arrtm8_k3_fa6_7_and0;
  wire f_u_arrtm8_k3_fa6_7_xor1;
  wire f_u_arrtm8_k3_fa6_7_and1;
  wire f_u_arrtm8_k3_fa6_7_or0;
  wire f_u_arrtm8_k3_and7_7;
  wire f_u_arrtm8_k3_u_cla5_pg_logic0_or0;
  wire f_u_arrtm8_k3_u_cla5_pg_logic0_and0;
  wire f_u_arrtm8_k3_u_cla5_pg_logic0_xor0;
  wire f_u_arrtm8_k3_u_cla5_pg_logic1_or0;
  wire f_u_arrtm8_k3_u_cla5_pg_logic1_and0;
  wire f_u_arrtm8_k3_u_cla5_pg_logic1_xor0;
  wire f_u_arrtm8_k3_u_cla5_xor1;
  wire f_u_arrtm8_k3_u_cla5_and0;
  wire f_u_arrtm8_k3_u_cla5_or0;
  wire f_u_arrtm8_k3_u_cla5_pg_logic2_or0;
  wire f_u_arrtm8_k3_u_cla5_pg_logic2_and0;
  wire f_u_arrtm8_k3_u_cla5_pg_logic2_xor0;
  wire f_u_arrtm8_k3_u_cla5_xor2;
  wire f_u_arrtm8_k3_u_cla5_and1;
  wire f_u_arrtm8_k3_u_cla5_and2;
  wire f_u_arrtm8_k3_u_cla5_and3;
  wire f_u_arrtm8_k3_u_cla5_and4;
  wire f_u_arrtm8_k3_u_cla5_or1;
  wire f_u_arrtm8_k3_u_cla5_or2;
  wire f_u_arrtm8_k3_u_cla5_pg_logic3_or0;
  wire f_u_arrtm8_k3_u_cla5_pg_logic3_and0;
  wire f_u_arrtm8_k3_u_cla5_pg_logic3_xor0;
  wire f_u_arrtm8_k3_u_cla5_xor3;
  wire f_u_arrtm8_k3_u_cla5_and5;
  wire f_u_arrtm8_k3_u_cla5_and6;
  wire f_u_arrtm8_k3_u_cla5_and7;
  wire f_u_arrtm8_k3_u_cla5_and8;
  wire f_u_arrtm8_k3_u_cla5_and9;
  wire f_u_arrtm8_k3_u_cla5_and10;
  wire f_u_arrtm8_k3_u_cla5_and11;
  wire f_u_arrtm8_k3_u_cla5_or3;
  wire f_u_arrtm8_k3_u_cla5_or4;
  wire f_u_arrtm8_k3_u_cla5_or5;

  assign f_u_arrtm8_k3_and3_3 = a[3] & b[3];
  assign f_u_arrtm8_k3_and4_3 = a[4] & b[3];
  assign f_u_arrtm8_k3_and5_3 = a[5] & b[3];
  assign f_u_arrtm8_k3_and6_3 = a[6] & b[3];
  assign f_u_arrtm8_k3_and7_3 = a[7] & b[3];
  assign f_u_arrtm8_k3_and3_4 = a[3] & b[4];
  assign f_u_arrtm8_k3_ha3_4_xor0 = f_u_arrtm8_k3_and3_4 ^ f_u_arrtm8_k3_and4_3;
  assign f_u_arrtm8_k3_ha3_4_and0 = f_u_arrtm8_k3_and3_4 & f_u_arrtm8_k3_and4_3;
  assign f_u_arrtm8_k3_and4_4 = a[4] & b[4];
  assign f_u_arrtm8_k3_ha4_4_xor0 = f_u_arrtm8_k3_and4_4 ^ f_u_arrtm8_k3_and5_3;
  assign f_u_arrtm8_k3_ha4_4_and0 = f_u_arrtm8_k3_and4_4 & f_u_arrtm8_k3_and5_3;
  assign f_u_arrtm8_k3_and5_4 = a[5] & b[4];
  assign f_u_arrtm8_k3_ha5_4_xor0 = f_u_arrtm8_k3_and5_4 ^ f_u_arrtm8_k3_and6_3;
  assign f_u_arrtm8_k3_ha5_4_and0 = f_u_arrtm8_k3_and5_4 & f_u_arrtm8_k3_and6_3;
  assign f_u_arrtm8_k3_and6_4 = a[6] & b[4];
  assign f_u_arrtm8_k3_ha6_4_xor0 = f_u_arrtm8_k3_and6_4 ^ f_u_arrtm8_k3_and7_3;
  assign f_u_arrtm8_k3_ha6_4_and0 = f_u_arrtm8_k3_and6_4 & f_u_arrtm8_k3_and7_3;
  assign f_u_arrtm8_k3_and7_4 = a[7] & b[4];
  assign f_u_arrtm8_k3_and3_5 = a[3] & b[5];
  assign f_u_arrtm8_k3_fa3_5_xor0 = f_u_arrtm8_k3_and3_5 ^ f_u_arrtm8_k3_ha4_4_xor0;
  assign f_u_arrtm8_k3_fa3_5_and0 = f_u_arrtm8_k3_and3_5 & f_u_arrtm8_k3_ha4_4_xor0;
  assign f_u_arrtm8_k3_fa3_5_xor1 = f_u_arrtm8_k3_fa3_5_xor0 ^ f_u_arrtm8_k3_ha3_4_and0;
  assign f_u_arrtm8_k3_fa3_5_and1 = f_u_arrtm8_k3_fa3_5_xor0 & f_u_arrtm8_k3_ha3_4_and0;
  assign f_u_arrtm8_k3_fa3_5_or0 = f_u_arrtm8_k3_fa3_5_and0 | f_u_arrtm8_k3_fa3_5_and1;
  assign f_u_arrtm8_k3_and4_5 = a[4] & b[5];
  assign f_u_arrtm8_k3_fa4_5_xor0 = f_u_arrtm8_k3_and4_5 ^ f_u_arrtm8_k3_ha5_4_xor0;
  assign f_u_arrtm8_k3_fa4_5_and0 = f_u_arrtm8_k3_and4_5 & f_u_arrtm8_k3_ha5_4_xor0;
  assign f_u_arrtm8_k3_fa4_5_xor1 = f_u_arrtm8_k3_fa4_5_xor0 ^ f_u_arrtm8_k3_ha4_4_and0;
  assign f_u_arrtm8_k3_fa4_5_and1 = f_u_arrtm8_k3_fa4_5_xor0 & f_u_arrtm8_k3_ha4_4_and0;
  assign f_u_arrtm8_k3_fa4_5_or0 = f_u_arrtm8_k3_fa4_5_and0 | f_u_arrtm8_k3_fa4_5_and1;
  assign f_u_arrtm8_k3_and5_5 = a[5] & b[5];
  assign f_u_arrtm8_k3_fa5_5_xor0 = f_u_arrtm8_k3_and5_5 ^ f_u_arrtm8_k3_ha6_4_xor0;
  assign f_u_arrtm8_k3_fa5_5_and0 = f_u_arrtm8_k3_and5_5 & f_u_arrtm8_k3_ha6_4_xor0;
  assign f_u_arrtm8_k3_fa5_5_xor1 = f_u_arrtm8_k3_fa5_5_xor0 ^ f_u_arrtm8_k3_ha5_4_and0;
  assign f_u_arrtm8_k3_fa5_5_and1 = f_u_arrtm8_k3_fa5_5_xor0 & f_u_arrtm8_k3_ha5_4_and0;
  assign f_u_arrtm8_k3_fa5_5_or0 = f_u_arrtm8_k3_fa5_5_and0 | f_u_arrtm8_k3_fa5_5_and1;
  assign f_u_arrtm8_k3_and6_5 = a[6] & b[5];
  assign f_u_arrtm8_k3_fa6_5_xor0 = f_u_arrtm8_k3_and6_5 ^ f_u_arrtm8_k3_and7_4;
  assign f_u_arrtm8_k3_fa6_5_and0 = f_u_arrtm8_k3_and6_5 & f_u_arrtm8_k3_and7_4;
  assign f_u_arrtm8_k3_fa6_5_xor1 = f_u_arrtm8_k3_fa6_5_xor0 ^ f_u_arrtm8_k3_ha6_4_and0;
  assign f_u_arrtm8_k3_fa6_5_and1 = f_u_arrtm8_k3_fa6_5_xor0 & f_u_arrtm8_k3_ha6_4_and0;
  assign f_u_arrtm8_k3_fa6_5_or0 = f_u_arrtm8_k3_fa6_5_and0 | f_u_arrtm8_k3_fa6_5_and1;
  assign f_u_arrtm8_k3_and7_5 = a[7] & b[5];
  assign f_u_arrtm8_k3_and3_6 = a[3] & b[6];
  assign f_u_arrtm8_k3_fa3_6_xor0 = f_u_arrtm8_k3_and3_6 ^ f_u_arrtm8_k3_fa4_5_xor1;
  assign f_u_arrtm8_k3_fa3_6_and0 = f_u_arrtm8_k3_and3_6 & f_u_arrtm8_k3_fa4_5_xor1;
  assign f_u_arrtm8_k3_fa3_6_xor1 = f_u_arrtm8_k3_fa3_6_xor0 ^ f_u_arrtm8_k3_fa3_5_or0;
  assign f_u_arrtm8_k3_fa3_6_and1 = f_u_arrtm8_k3_fa3_6_xor0 & f_u_arrtm8_k3_fa3_5_or0;
  assign f_u_arrtm8_k3_fa3_6_or0 = f_u_arrtm8_k3_fa3_6_and0 | f_u_arrtm8_k3_fa3_6_and1;
  assign f_u_arrtm8_k3_and4_6 = a[4] & b[6];
  assign f_u_arrtm8_k3_fa4_6_xor0 = f_u_arrtm8_k3_and4_6 ^ f_u_arrtm8_k3_fa5_5_xor1;
  assign f_u_arrtm8_k3_fa4_6_and0 = f_u_arrtm8_k3_and4_6 & f_u_arrtm8_k3_fa5_5_xor1;
  assign f_u_arrtm8_k3_fa4_6_xor1 = f_u_arrtm8_k3_fa4_6_xor0 ^ f_u_arrtm8_k3_fa4_5_or0;
  assign f_u_arrtm8_k3_fa4_6_and1 = f_u_arrtm8_k3_fa4_6_xor0 & f_u_arrtm8_k3_fa4_5_or0;
  assign f_u_arrtm8_k3_fa4_6_or0 = f_u_arrtm8_k3_fa4_6_and0 | f_u_arrtm8_k3_fa4_6_and1;
  assign f_u_arrtm8_k3_and5_6 = a[5] & b[6];
  assign f_u_arrtm8_k3_fa5_6_xor0 = f_u_arrtm8_k3_and5_6 ^ f_u_arrtm8_k3_fa6_5_xor1;
  assign f_u_arrtm8_k3_fa5_6_and0 = f_u_arrtm8_k3_and5_6 & f_u_arrtm8_k3_fa6_5_xor1;
  assign f_u_arrtm8_k3_fa5_6_xor1 = f_u_arrtm8_k3_fa5_6_xor0 ^ f_u_arrtm8_k3_fa5_5_or0;
  assign f_u_arrtm8_k3_fa5_6_and1 = f_u_arrtm8_k3_fa5_6_xor0 & f_u_arrtm8_k3_fa5_5_or0;
  assign f_u_arrtm8_k3_fa5_6_or0 = f_u_arrtm8_k3_fa5_6_and0 | f_u_arrtm8_k3_fa5_6_and1;
  assign f_u_arrtm8_k3_and6_6 = a[6] & b[6];
  assign f_u_arrtm8_k3_fa6_6_xor0 = f_u_arrtm8_k3_and6_6 ^ f_u_arrtm8_k3_and7_5;
  assign f_u_arrtm8_k3_fa6_6_and0 = f_u_arrtm8_k3_and6_6 & f_u_arrtm8_k3_and7_5;
  assign f_u_arrtm8_k3_fa6_6_xor1 = f_u_arrtm8_k3_fa6_6_xor0 ^ f_u_arrtm8_k3_fa6_5_or0;
  assign f_u_arrtm8_k3_fa6_6_and1 = f_u_arrtm8_k3_fa6_6_xor0 & f_u_arrtm8_k3_fa6_5_or0;
  assign f_u_arrtm8_k3_fa6_6_or0 = f_u_arrtm8_k3_fa6_6_and0 | f_u_arrtm8_k3_fa6_6_and1;
  assign f_u_arrtm8_k3_and7_6 = a[7] & b[6];
  assign f_u_arrtm8_k3_and3_7 = a[3] & b[7];
  assign f_u_arrtm8_k3_fa3_7_xor0 = f_u_arrtm8_k3_and3_7 ^ f_u_arrtm8_k3_fa4_6_xor1;
  assign f_u_arrtm8_k3_fa3_7_and0 = f_u_arrtm8_k3_and3_7 & f_u_arrtm8_k3_fa4_6_xor1;
  assign f_u_arrtm8_k3_fa3_7_xor1 = f_u_arrtm8_k3_fa3_7_xor0 ^ f_u_arrtm8_k3_fa3_6_or0;
  assign f_u_arrtm8_k3_fa3_7_and1 = f_u_arrtm8_k3_fa3_7_xor0 & f_u_arrtm8_k3_fa3_6_or0;
  assign f_u_arrtm8_k3_fa3_7_or0 = f_u_arrtm8_k3_fa3_7_and0 | f_u_arrtm8_k3_fa3_7_and1;
  assign f_u_arrtm8_k3_and4_7 = a[4] & b[7];
  assign f_u_arrtm8_k3_fa4_7_xor0 = f_u_arrtm8_k3_and4_7 ^ f_u_arrtm8_k3_fa5_6_xor1;
  assign f_u_arrtm8_k3_fa4_7_and0 = f_u_arrtm8_k3_and4_7 & f_u_arrtm8_k3_fa5_6_xor1;
  assign f_u_arrtm8_k3_fa4_7_xor1 = f_u_arrtm8_k3_fa4_7_xor0 ^ f_u_arrtm8_k3_fa4_6_or0;
  assign f_u_arrtm8_k3_fa4_7_and1 = f_u_arrtm8_k3_fa4_7_xor0 & f_u_arrtm8_k3_fa4_6_or0;
  assign f_u_arrtm8_k3_fa4_7_or0 = f_u_arrtm8_k3_fa4_7_and0 | f_u_arrtm8_k3_fa4_7_and1;
  assign f_u_arrtm8_k3_and5_7 = a[5] & b[7];
  assign f_u_arrtm8_k3_fa5_7_xor0 = f_u_arrtm8_k3_and5_7 ^ f_u_arrtm8_k3_fa6_6_xor1;
  assign f_u_arrtm8_k3_fa5_7_and0 = f_u_arrtm8_k3_and5_7 & f_u_arrtm8_k3_fa6_6_xor1;
  assign f_u_arrtm8_k3_fa5_7_xor1 = f_u_arrtm8_k3_fa5_7_xor0 ^ f_u_arrtm8_k3_fa5_6_or0;
  assign f_u_arrtm8_k3_fa5_7_and1 = f_u_arrtm8_k3_fa5_7_xor0 & f_u_arrtm8_k3_fa5_6_or0;
  assign f_u_arrtm8_k3_fa5_7_or0 = f_u_arrtm8_k3_fa5_7_and0 | f_u_arrtm8_k3_fa5_7_and1;
  assign f_u_arrtm8_k3_and6_7 = a[6] & b[7];
  assign f_u_arrtm8_k3_fa6_7_xor0 = f_u_arrtm8_k3_and6_7 ^ f_u_arrtm8_k3_and7_6;
  assign f_u_arrtm8_k3_fa6_7_and0 = f_u_arrtm8_k3_and6_7 & f_u_arrtm8_k3_and7_6;
  assign f_u_arrtm8_k3_fa6_7_xor1 = f_u_arrtm8_k3_fa6_7_xor0 ^ f_u_arrtm8_k3_fa6_6_or0;
  assign f_u_arrtm8_k3_fa6_7_and1 = f_u_arrtm8_k3_fa6_7_xor0 & f_u_arrtm8_k3_fa6_6_or0;
  assign f_u_arrtm8_k3_fa6_7_or0 = f_u_arrtm8_k3_fa6_7_and0 | f_u_arrtm8_k3_fa6_7_and1;
  assign f_u_arrtm8_k3_and7_7 = a[7] & b[7];
  assign f_u_arrtm8_k3_u_cla5_pg_logic0_or0 = f_u_arrtm8_k3_fa4_7_xor1 | f_u_arrtm8_k3_fa3_7_or0;
  assign f_u_arrtm8_k3_u_cla5_pg_logic0_and0 = f_u_arrtm8_k3_fa4_7_xor1 & f_u_arrtm8_k3_fa3_7_or0;
  assign f_u_arrtm8_k3_u_cla5_pg_logic0_xor0 = f_u_arrtm8_k3_fa4_7_xor1 ^ f_u_arrtm8_k3_fa3_7_or0;
  assign f_u_arrtm8_k3_u_cla5_pg_logic1_or0 = f_u_arrtm8_k3_fa5_7_xor1 | f_u_arrtm8_k3_fa4_7_or0;
  assign f_u_arrtm8_k3_u_cla5_pg_logic1_and0 = f_u_arrtm8_k3_fa5_7_xor1 & f_u_arrtm8_k3_fa4_7_or0;
  assign f_u_arrtm8_k3_u_cla5_pg_logic1_xor0 = f_u_arrtm8_k3_fa5_7_xor1 ^ f_u_arrtm8_k3_fa4_7_or0;
  assign f_u_arrtm8_k3_u_cla5_xor1 = f_u_arrtm8_k3_u_cla5_pg_logic1_xor0 ^ f_u_arrtm8_k3_u_cla5_pg_logic0_and0;
  assign f_u_arrtm8_k3_u_cla5_and0 = f_u_arrtm8_k3_u_cla5_pg_logic0_and0 & f_u_arrtm8_k3_u_cla5_pg_logic1_or0;
  assign f_u_arrtm8_k3_u_cla5_or0 = f_u_arrtm8_k3_u_cla5_pg_logic1_and0 | f_u_arrtm8_k3_u_cla5_and0;
  assign f_u_arrtm8_k3_u_cla5_pg_logic2_or0 = f_u_arrtm8_k3_fa6_7_xor1 | f_u_arrtm8_k3_fa5_7_or0;
  assign f_u_arrtm8_k3_u_cla5_pg_logic2_and0 = f_u_arrtm8_k3_fa6_7_xor1 & f_u_arrtm8_k3_fa5_7_or0;
  assign f_u_arrtm8_k3_u_cla5_pg_logic2_xor0 = f_u_arrtm8_k3_fa6_7_xor1 ^ f_u_arrtm8_k3_fa5_7_or0;
  assign f_u_arrtm8_k3_u_cla5_xor2 = f_u_arrtm8_k3_u_cla5_pg_logic2_xor0 ^ f_u_arrtm8_k3_u_cla5_or0;
  assign f_u_arrtm8_k3_u_cla5_and1 = f_u_arrtm8_k3_u_cla5_pg_logic2_or0 & f_u_arrtm8_k3_u_cla5_pg_logic0_or0;
  assign f_u_arrtm8_k3_u_cla5_and2 = f_u_arrtm8_k3_u_cla5_pg_logic0_and0 & f_u_arrtm8_k3_u_cla5_pg_logic2_or0;
  assign f_u_arrtm8_k3_u_cla5_and3 = f_u_arrtm8_k3_u_cla5_and2 & f_u_arrtm8_k3_u_cla5_pg_logic1_or0;
  assign f_u_arrtm8_k3_u_cla5_and4 = f_u_arrtm8_k3_u_cla5_pg_logic1_and0 & f_u_arrtm8_k3_u_cla5_pg_logic2_or0;
  assign f_u_arrtm8_k3_u_cla5_or1 = f_u_arrtm8_k3_u_cla5_and3 | f_u_arrtm8_k3_u_cla5_and4;
  assign f_u_arrtm8_k3_u_cla5_or2 = f_u_arrtm8_k3_u_cla5_pg_logic2_and0 | f_u_arrtm8_k3_u_cla5_or1;
  assign f_u_arrtm8_k3_u_cla5_pg_logic3_or0 = f_u_arrtm8_k3_and7_7 | f_u_arrtm8_k3_fa6_7_or0;
  assign f_u_arrtm8_k3_u_cla5_pg_logic3_and0 = f_u_arrtm8_k3_and7_7 & f_u_arrtm8_k3_fa6_7_or0;
  assign f_u_arrtm8_k3_u_cla5_pg_logic3_xor0 = f_u_arrtm8_k3_and7_7 ^ f_u_arrtm8_k3_fa6_7_or0;
  assign f_u_arrtm8_k3_u_cla5_xor3 = f_u_arrtm8_k3_u_cla5_pg_logic3_xor0 ^ f_u_arrtm8_k3_u_cla5_or2;
  assign f_u_arrtm8_k3_u_cla5_and5 = f_u_arrtm8_k3_u_cla5_pg_logic3_or0 & f_u_arrtm8_k3_u_cla5_pg_logic1_or0;
  assign f_u_arrtm8_k3_u_cla5_and6 = f_u_arrtm8_k3_u_cla5_pg_logic0_and0 & f_u_arrtm8_k3_u_cla5_pg_logic2_or0;
  assign f_u_arrtm8_k3_u_cla5_and7 = f_u_arrtm8_k3_u_cla5_pg_logic3_or0 & f_u_arrtm8_k3_u_cla5_pg_logic1_or0;
  assign f_u_arrtm8_k3_u_cla5_and8 = f_u_arrtm8_k3_u_cla5_and6 & f_u_arrtm8_k3_u_cla5_and7;
  assign f_u_arrtm8_k3_u_cla5_and9 = f_u_arrtm8_k3_u_cla5_pg_logic1_and0 & f_u_arrtm8_k3_u_cla5_pg_logic3_or0;
  assign f_u_arrtm8_k3_u_cla5_and10 = f_u_arrtm8_k3_u_cla5_and9 & f_u_arrtm8_k3_u_cla5_pg_logic2_or0;
  assign f_u_arrtm8_k3_u_cla5_and11 = f_u_arrtm8_k3_u_cla5_pg_logic2_and0 & f_u_arrtm8_k3_u_cla5_pg_logic3_or0;
  assign f_u_arrtm8_k3_u_cla5_or3 = f_u_arrtm8_k3_u_cla5_and8 | f_u_arrtm8_k3_u_cla5_and11;
  assign f_u_arrtm8_k3_u_cla5_or4 = f_u_arrtm8_k3_u_cla5_and10 | f_u_arrtm8_k3_u_cla5_or3;
  assign f_u_arrtm8_k3_u_cla5_or5 = f_u_arrtm8_k3_u_cla5_pg_logic3_and0 | f_u_arrtm8_k3_u_cla5_or4;

  assign f_u_arrtm8_k3_out[0] = 1'b0;
  assign f_u_arrtm8_k3_out[1] = 1'b0;
  assign f_u_arrtm8_k3_out[2] = 1'b0;
  assign f_u_arrtm8_k3_out[3] = 1'b0;
  assign f_u_arrtm8_k3_out[4] = 1'b0;
  assign f_u_arrtm8_k3_out[5] = 1'b0;
  assign f_u_arrtm8_k3_out[6] = f_u_arrtm8_k3_and3_3;
  assign f_u_arrtm8_k3_out[7] = f_u_arrtm8_k3_ha3_4_xor0;
  assign f_u_arrtm8_k3_out[8] = f_u_arrtm8_k3_fa3_5_xor1;
  assign f_u_arrtm8_k3_out[9] = f_u_arrtm8_k3_fa3_6_xor1;
  assign f_u_arrtm8_k3_out[10] = f_u_arrtm8_k3_fa3_7_xor1;
  assign f_u_arrtm8_k3_out[11] = f_u_arrtm8_k3_u_cla5_pg_logic0_xor0;
  assign f_u_arrtm8_k3_out[12] = f_u_arrtm8_k3_u_cla5_xor1;
  assign f_u_arrtm8_k3_out[13] = f_u_arrtm8_k3_u_cla5_xor2;
  assign f_u_arrtm8_k3_out[14] = f_u_arrtm8_k3_u_cla5_xor3;
  assign f_u_arrtm8_k3_out[15] = f_u_arrtm8_k3_u_cla5_or5;
endmodule