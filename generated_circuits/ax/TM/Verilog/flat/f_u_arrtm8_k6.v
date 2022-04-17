module f_u_arrtm8_k6(input [7:0] a, input [7:0] b, output [15:0] f_u_arrtm8_k6_out);
  wire f_u_arrtm8_k6_and6_6;
  wire f_u_arrtm8_k6_and7_6;
  wire f_u_arrtm8_k6_and6_7;
  wire f_u_arrtm8_k6_ha6_7_xor0;
  wire f_u_arrtm8_k6_ha6_7_and0;
  wire f_u_arrtm8_k6_and7_7;
  wire f_u_arrtm8_k6_u_cla2_pg_logic0_or0;
  wire f_u_arrtm8_k6_u_cla2_pg_logic0_and0;
  wire f_u_arrtm8_k6_u_cla2_pg_logic0_xor0;

  assign f_u_arrtm8_k6_and6_6 = a[6] & b[6];
  assign f_u_arrtm8_k6_and7_6 = a[7] & b[6];
  assign f_u_arrtm8_k6_and6_7 = a[6] & b[7];
  assign f_u_arrtm8_k6_ha6_7_xor0 = f_u_arrtm8_k6_and6_7 ^ f_u_arrtm8_k6_and7_6;
  assign f_u_arrtm8_k6_ha6_7_and0 = f_u_arrtm8_k6_and6_7 & f_u_arrtm8_k6_and7_6;
  assign f_u_arrtm8_k6_and7_7 = a[7] & b[7];
  assign f_u_arrtm8_k6_u_cla2_pg_logic0_or0 = f_u_arrtm8_k6_and7_7 | f_u_arrtm8_k6_ha6_7_and0;
  assign f_u_arrtm8_k6_u_cla2_pg_logic0_and0 = f_u_arrtm8_k6_and7_7 & f_u_arrtm8_k6_ha6_7_and0;
  assign f_u_arrtm8_k6_u_cla2_pg_logic0_xor0 = f_u_arrtm8_k6_and7_7 ^ f_u_arrtm8_k6_ha6_7_and0;

  assign f_u_arrtm8_k6_out[0] = 1'b0;
  assign f_u_arrtm8_k6_out[1] = 1'b0;
  assign f_u_arrtm8_k6_out[2] = 1'b0;
  assign f_u_arrtm8_k6_out[3] = 1'b0;
  assign f_u_arrtm8_k6_out[4] = 1'b0;
  assign f_u_arrtm8_k6_out[5] = 1'b0;
  assign f_u_arrtm8_k6_out[6] = 1'b0;
  assign f_u_arrtm8_k6_out[7] = 1'b0;
  assign f_u_arrtm8_k6_out[8] = 1'b0;
  assign f_u_arrtm8_k6_out[9] = 1'b0;
  assign f_u_arrtm8_k6_out[10] = 1'b0;
  assign f_u_arrtm8_k6_out[11] = 1'b0;
  assign f_u_arrtm8_k6_out[12] = f_u_arrtm8_k6_and6_6;
  assign f_u_arrtm8_k6_out[13] = f_u_arrtm8_k6_ha6_7_xor0;
  assign f_u_arrtm8_k6_out[14] = f_u_arrtm8_k6_u_cla2_pg_logic0_xor0;
  assign f_u_arrtm8_k6_out[15] = f_u_arrtm8_k6_u_cla2_pg_logic0_and0;
endmodule