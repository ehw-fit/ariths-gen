module f_u_csabam8_cla_h2_v11(input [7:0] a, input [7:0] b, output [15:0] f_u_csabam8_cla_h2_v11_out);
  wire f_u_csabam8_cla_h2_v11_and7_4;
  wire f_u_csabam8_cla_h2_v11_and6_5;
  wire f_u_csabam8_cla_h2_v11_ha6_5_xor0;
  wire f_u_csabam8_cla_h2_v11_ha6_5_and0;
  wire f_u_csabam8_cla_h2_v11_and7_5;
  wire f_u_csabam8_cla_h2_v11_and5_6;
  wire f_u_csabam8_cla_h2_v11_ha5_6_xor0;
  wire f_u_csabam8_cla_h2_v11_ha5_6_and0;
  wire f_u_csabam8_cla_h2_v11_and6_6;
  wire f_u_csabam8_cla_h2_v11_fa6_6_xor0;
  wire f_u_csabam8_cla_h2_v11_fa6_6_and0;
  wire f_u_csabam8_cla_h2_v11_fa6_6_xor1;
  wire f_u_csabam8_cla_h2_v11_fa6_6_and1;
  wire f_u_csabam8_cla_h2_v11_fa6_6_or0;
  wire f_u_csabam8_cla_h2_v11_and7_6;
  wire f_u_csabam8_cla_h2_v11_and4_7;
  wire f_u_csabam8_cla_h2_v11_ha4_7_xor0;
  wire f_u_csabam8_cla_h2_v11_ha4_7_and0;
  wire f_u_csabam8_cla_h2_v11_and5_7;
  wire f_u_csabam8_cla_h2_v11_fa5_7_xor0;
  wire f_u_csabam8_cla_h2_v11_fa5_7_and0;
  wire f_u_csabam8_cla_h2_v11_fa5_7_xor1;
  wire f_u_csabam8_cla_h2_v11_fa5_7_and1;
  wire f_u_csabam8_cla_h2_v11_fa5_7_or0;
  wire f_u_csabam8_cla_h2_v11_and6_7;
  wire f_u_csabam8_cla_h2_v11_fa6_7_xor0;
  wire f_u_csabam8_cla_h2_v11_fa6_7_and0;
  wire f_u_csabam8_cla_h2_v11_fa6_7_xor1;
  wire f_u_csabam8_cla_h2_v11_fa6_7_and1;
  wire f_u_csabam8_cla_h2_v11_fa6_7_or0;
  wire f_u_csabam8_cla_h2_v11_and7_7;
  wire f_u_csabam8_cla_h2_v11_u_cla4_pg_logic1_or0;
  wire f_u_csabam8_cla_h2_v11_u_cla4_pg_logic1_and0;
  wire f_u_csabam8_cla_h2_v11_u_cla4_pg_logic1_xor0;
  wire f_u_csabam8_cla_h2_v11_u_cla4_pg_logic2_or0;
  wire f_u_csabam8_cla_h2_v11_u_cla4_pg_logic2_and0;
  wire f_u_csabam8_cla_h2_v11_u_cla4_pg_logic2_xor0;
  wire f_u_csabam8_cla_h2_v11_u_cla4_xor2;
  wire f_u_csabam8_cla_h2_v11_u_cla4_and0;
  wire f_u_csabam8_cla_h2_v11_u_cla4_and1;
  wire f_u_csabam8_cla_h2_v11_u_cla4_or0;

  assign f_u_csabam8_cla_h2_v11_and7_4 = a[7] & b[4];
  assign f_u_csabam8_cla_h2_v11_and6_5 = a[6] & b[5];
  assign f_u_csabam8_cla_h2_v11_ha6_5_xor0 = f_u_csabam8_cla_h2_v11_and6_5 ^ f_u_csabam8_cla_h2_v11_and7_4;
  assign f_u_csabam8_cla_h2_v11_ha6_5_and0 = f_u_csabam8_cla_h2_v11_and6_5 & f_u_csabam8_cla_h2_v11_and7_4;
  assign f_u_csabam8_cla_h2_v11_and7_5 = a[7] & b[5];
  assign f_u_csabam8_cla_h2_v11_and5_6 = a[5] & b[6];
  assign f_u_csabam8_cla_h2_v11_ha5_6_xor0 = f_u_csabam8_cla_h2_v11_and5_6 ^ f_u_csabam8_cla_h2_v11_ha6_5_xor0;
  assign f_u_csabam8_cla_h2_v11_ha5_6_and0 = f_u_csabam8_cla_h2_v11_and5_6 & f_u_csabam8_cla_h2_v11_ha6_5_xor0;
  assign f_u_csabam8_cla_h2_v11_and6_6 = a[6] & b[6];
  assign f_u_csabam8_cla_h2_v11_fa6_6_xor0 = f_u_csabam8_cla_h2_v11_and6_6 ^ f_u_csabam8_cla_h2_v11_and7_5;
  assign f_u_csabam8_cla_h2_v11_fa6_6_and0 = f_u_csabam8_cla_h2_v11_and6_6 & f_u_csabam8_cla_h2_v11_and7_5;
  assign f_u_csabam8_cla_h2_v11_fa6_6_xor1 = f_u_csabam8_cla_h2_v11_fa6_6_xor0 ^ f_u_csabam8_cla_h2_v11_ha6_5_and0;
  assign f_u_csabam8_cla_h2_v11_fa6_6_and1 = f_u_csabam8_cla_h2_v11_fa6_6_xor0 & f_u_csabam8_cla_h2_v11_ha6_5_and0;
  assign f_u_csabam8_cla_h2_v11_fa6_6_or0 = f_u_csabam8_cla_h2_v11_fa6_6_and0 | f_u_csabam8_cla_h2_v11_fa6_6_and1;
  assign f_u_csabam8_cla_h2_v11_and7_6 = a[7] & b[6];
  assign f_u_csabam8_cla_h2_v11_and4_7 = a[4] & b[7];
  assign f_u_csabam8_cla_h2_v11_ha4_7_xor0 = f_u_csabam8_cla_h2_v11_and4_7 ^ f_u_csabam8_cla_h2_v11_ha5_6_xor0;
  assign f_u_csabam8_cla_h2_v11_ha4_7_and0 = f_u_csabam8_cla_h2_v11_and4_7 & f_u_csabam8_cla_h2_v11_ha5_6_xor0;
  assign f_u_csabam8_cla_h2_v11_and5_7 = a[5] & b[7];
  assign f_u_csabam8_cla_h2_v11_fa5_7_xor0 = f_u_csabam8_cla_h2_v11_and5_7 ^ f_u_csabam8_cla_h2_v11_fa6_6_xor1;
  assign f_u_csabam8_cla_h2_v11_fa5_7_and0 = f_u_csabam8_cla_h2_v11_and5_7 & f_u_csabam8_cla_h2_v11_fa6_6_xor1;
  assign f_u_csabam8_cla_h2_v11_fa5_7_xor1 = f_u_csabam8_cla_h2_v11_fa5_7_xor0 ^ f_u_csabam8_cla_h2_v11_ha5_6_and0;
  assign f_u_csabam8_cla_h2_v11_fa5_7_and1 = f_u_csabam8_cla_h2_v11_fa5_7_xor0 & f_u_csabam8_cla_h2_v11_ha5_6_and0;
  assign f_u_csabam8_cla_h2_v11_fa5_7_or0 = f_u_csabam8_cla_h2_v11_fa5_7_and0 | f_u_csabam8_cla_h2_v11_fa5_7_and1;
  assign f_u_csabam8_cla_h2_v11_and6_7 = a[6] & b[7];
  assign f_u_csabam8_cla_h2_v11_fa6_7_xor0 = f_u_csabam8_cla_h2_v11_and6_7 ^ f_u_csabam8_cla_h2_v11_and7_6;
  assign f_u_csabam8_cla_h2_v11_fa6_7_and0 = f_u_csabam8_cla_h2_v11_and6_7 & f_u_csabam8_cla_h2_v11_and7_6;
  assign f_u_csabam8_cla_h2_v11_fa6_7_xor1 = f_u_csabam8_cla_h2_v11_fa6_7_xor0 ^ f_u_csabam8_cla_h2_v11_fa6_6_or0;
  assign f_u_csabam8_cla_h2_v11_fa6_7_and1 = f_u_csabam8_cla_h2_v11_fa6_7_xor0 & f_u_csabam8_cla_h2_v11_fa6_6_or0;
  assign f_u_csabam8_cla_h2_v11_fa6_7_or0 = f_u_csabam8_cla_h2_v11_fa6_7_and0 | f_u_csabam8_cla_h2_v11_fa6_7_and1;
  assign f_u_csabam8_cla_h2_v11_and7_7 = a[7] & b[7];
  assign f_u_csabam8_cla_h2_v11_u_cla4_pg_logic1_or0 = f_u_csabam8_cla_h2_v11_fa6_7_xor1 | f_u_csabam8_cla_h2_v11_fa5_7_or0;
  assign f_u_csabam8_cla_h2_v11_u_cla4_pg_logic1_and0 = f_u_csabam8_cla_h2_v11_fa6_7_xor1 & f_u_csabam8_cla_h2_v11_fa5_7_or0;
  assign f_u_csabam8_cla_h2_v11_u_cla4_pg_logic1_xor0 = f_u_csabam8_cla_h2_v11_fa6_7_xor1 ^ f_u_csabam8_cla_h2_v11_fa5_7_or0;
  assign f_u_csabam8_cla_h2_v11_u_cla4_pg_logic2_or0 = f_u_csabam8_cla_h2_v11_and7_7 | f_u_csabam8_cla_h2_v11_fa6_7_or0;
  assign f_u_csabam8_cla_h2_v11_u_cla4_pg_logic2_and0 = f_u_csabam8_cla_h2_v11_and7_7 & f_u_csabam8_cla_h2_v11_fa6_7_or0;
  assign f_u_csabam8_cla_h2_v11_u_cla4_pg_logic2_xor0 = f_u_csabam8_cla_h2_v11_and7_7 ^ f_u_csabam8_cla_h2_v11_fa6_7_or0;
  assign f_u_csabam8_cla_h2_v11_u_cla4_xor2 = f_u_csabam8_cla_h2_v11_u_cla4_pg_logic2_xor0 ^ f_u_csabam8_cla_h2_v11_u_cla4_pg_logic1_and0;
  assign f_u_csabam8_cla_h2_v11_u_cla4_and0 = f_u_csabam8_cla_h2_v11_u_cla4_pg_logic2_or0 & f_u_csabam8_cla_h2_v11_fa5_7_xor1;
  assign f_u_csabam8_cla_h2_v11_u_cla4_and1 = f_u_csabam8_cla_h2_v11_u_cla4_pg_logic1_and0 & f_u_csabam8_cla_h2_v11_u_cla4_pg_logic2_or0;
  assign f_u_csabam8_cla_h2_v11_u_cla4_or0 = f_u_csabam8_cla_h2_v11_u_cla4_pg_logic2_and0 | f_u_csabam8_cla_h2_v11_u_cla4_and1;

  assign f_u_csabam8_cla_h2_v11_out[0] = 1'b0;
  assign f_u_csabam8_cla_h2_v11_out[1] = 1'b0;
  assign f_u_csabam8_cla_h2_v11_out[2] = 1'b0;
  assign f_u_csabam8_cla_h2_v11_out[3] = 1'b0;
  assign f_u_csabam8_cla_h2_v11_out[4] = 1'b0;
  assign f_u_csabam8_cla_h2_v11_out[5] = 1'b0;
  assign f_u_csabam8_cla_h2_v11_out[6] = 1'b0;
  assign f_u_csabam8_cla_h2_v11_out[7] = 1'b0;
  assign f_u_csabam8_cla_h2_v11_out[8] = 1'b0;
  assign f_u_csabam8_cla_h2_v11_out[9] = 1'b0;
  assign f_u_csabam8_cla_h2_v11_out[10] = 1'b0;
  assign f_u_csabam8_cla_h2_v11_out[11] = f_u_csabam8_cla_h2_v11_fa5_7_xor1;
  assign f_u_csabam8_cla_h2_v11_out[12] = f_u_csabam8_cla_h2_v11_u_cla4_pg_logic1_xor0;
  assign f_u_csabam8_cla_h2_v11_out[13] = f_u_csabam8_cla_h2_v11_u_cla4_xor2;
  assign f_u_csabam8_cla_h2_v11_out[14] = f_u_csabam8_cla_h2_v11_u_cla4_or0;
  assign f_u_csabam8_cla_h2_v11_out[15] = 1'b0;
endmodule