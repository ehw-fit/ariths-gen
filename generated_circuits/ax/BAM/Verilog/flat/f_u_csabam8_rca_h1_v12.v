module f_u_csabam8_rca_h1_v12(input [7:0] a, input [7:0] b, output [15:0] f_u_csabam8_rca_h1_v12_out);
  wire f_u_csabam8_rca_h1_v12_and7_5;
  wire f_u_csabam8_rca_h1_v12_and6_6;
  wire f_u_csabam8_rca_h1_v12_ha6_6_xor0;
  wire f_u_csabam8_rca_h1_v12_ha6_6_and0;
  wire f_u_csabam8_rca_h1_v12_and7_6;
  wire f_u_csabam8_rca_h1_v12_and5_7;
  wire f_u_csabam8_rca_h1_v12_ha5_7_xor0;
  wire f_u_csabam8_rca_h1_v12_ha5_7_and0;
  wire f_u_csabam8_rca_h1_v12_and6_7;
  wire f_u_csabam8_rca_h1_v12_fa6_7_xor0;
  wire f_u_csabam8_rca_h1_v12_fa6_7_and0;
  wire f_u_csabam8_rca_h1_v12_fa6_7_xor1;
  wire f_u_csabam8_rca_h1_v12_fa6_7_and1;
  wire f_u_csabam8_rca_h1_v12_fa6_7_or0;
  wire f_u_csabam8_rca_h1_v12_and7_7;
  wire f_u_csabam8_rca_h1_v12_u_rca3_fa1_xor0;
  wire f_u_csabam8_rca_h1_v12_u_rca3_fa1_and0;

  assign f_u_csabam8_rca_h1_v12_and7_5 = a[7] & b[5];
  assign f_u_csabam8_rca_h1_v12_and6_6 = a[6] & b[6];
  assign f_u_csabam8_rca_h1_v12_ha6_6_xor0 = f_u_csabam8_rca_h1_v12_and6_6 ^ f_u_csabam8_rca_h1_v12_and7_5;
  assign f_u_csabam8_rca_h1_v12_ha6_6_and0 = f_u_csabam8_rca_h1_v12_and6_6 & f_u_csabam8_rca_h1_v12_and7_5;
  assign f_u_csabam8_rca_h1_v12_and7_6 = a[7] & b[6];
  assign f_u_csabam8_rca_h1_v12_and5_7 = a[5] & b[7];
  assign f_u_csabam8_rca_h1_v12_ha5_7_xor0 = f_u_csabam8_rca_h1_v12_and5_7 ^ f_u_csabam8_rca_h1_v12_ha6_6_xor0;
  assign f_u_csabam8_rca_h1_v12_ha5_7_and0 = f_u_csabam8_rca_h1_v12_and5_7 & f_u_csabam8_rca_h1_v12_ha6_6_xor0;
  assign f_u_csabam8_rca_h1_v12_and6_7 = a[6] & b[7];
  assign f_u_csabam8_rca_h1_v12_fa6_7_xor0 = f_u_csabam8_rca_h1_v12_and6_7 ^ f_u_csabam8_rca_h1_v12_and7_6;
  assign f_u_csabam8_rca_h1_v12_fa6_7_and0 = f_u_csabam8_rca_h1_v12_and6_7 & f_u_csabam8_rca_h1_v12_and7_6;
  assign f_u_csabam8_rca_h1_v12_fa6_7_xor1 = f_u_csabam8_rca_h1_v12_fa6_7_xor0 ^ f_u_csabam8_rca_h1_v12_ha6_6_and0;
  assign f_u_csabam8_rca_h1_v12_fa6_7_and1 = f_u_csabam8_rca_h1_v12_fa6_7_xor0 & f_u_csabam8_rca_h1_v12_ha6_6_and0;
  assign f_u_csabam8_rca_h1_v12_fa6_7_or0 = f_u_csabam8_rca_h1_v12_fa6_7_and0 | f_u_csabam8_rca_h1_v12_fa6_7_and1;
  assign f_u_csabam8_rca_h1_v12_and7_7 = a[7] & b[7];
  assign f_u_csabam8_rca_h1_v12_u_rca3_fa1_xor0 = f_u_csabam8_rca_h1_v12_and7_7 ^ f_u_csabam8_rca_h1_v12_fa6_7_or0;
  assign f_u_csabam8_rca_h1_v12_u_rca3_fa1_and0 = f_u_csabam8_rca_h1_v12_and7_7 & f_u_csabam8_rca_h1_v12_fa6_7_or0;

  assign f_u_csabam8_rca_h1_v12_out[0] = 1'b0;
  assign f_u_csabam8_rca_h1_v12_out[1] = 1'b0;
  assign f_u_csabam8_rca_h1_v12_out[2] = 1'b0;
  assign f_u_csabam8_rca_h1_v12_out[3] = 1'b0;
  assign f_u_csabam8_rca_h1_v12_out[4] = 1'b0;
  assign f_u_csabam8_rca_h1_v12_out[5] = 1'b0;
  assign f_u_csabam8_rca_h1_v12_out[6] = 1'b0;
  assign f_u_csabam8_rca_h1_v12_out[7] = 1'b0;
  assign f_u_csabam8_rca_h1_v12_out[8] = 1'b0;
  assign f_u_csabam8_rca_h1_v12_out[9] = 1'b0;
  assign f_u_csabam8_rca_h1_v12_out[10] = 1'b0;
  assign f_u_csabam8_rca_h1_v12_out[11] = 1'b0;
  assign f_u_csabam8_rca_h1_v12_out[12] = f_u_csabam8_rca_h1_v12_fa6_7_xor1;
  assign f_u_csabam8_rca_h1_v12_out[13] = f_u_csabam8_rca_h1_v12_u_rca3_fa1_xor0;
  assign f_u_csabam8_rca_h1_v12_out[14] = f_u_csabam8_rca_h1_v12_u_rca3_fa1_and0;
  assign f_u_csabam8_rca_h1_v12_out[15] = 1'b0;
endmodule