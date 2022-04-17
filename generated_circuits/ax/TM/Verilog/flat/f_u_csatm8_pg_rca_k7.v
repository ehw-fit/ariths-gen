module f_u_csatm8_pg_rca_k7(input [7:0] a, input [7:0] b, output [15:0] f_u_csatm8_pg_rca_k7_out);
  wire f_u_csatm8_pg_rca_k7_and7_7;

  assign f_u_csatm8_pg_rca_k7_and7_7 = a[7] & b[7];

  assign f_u_csatm8_pg_rca_k7_out[0] = 1'b0;
  assign f_u_csatm8_pg_rca_k7_out[1] = 1'b0;
  assign f_u_csatm8_pg_rca_k7_out[2] = 1'b0;
  assign f_u_csatm8_pg_rca_k7_out[3] = 1'b0;
  assign f_u_csatm8_pg_rca_k7_out[4] = 1'b0;
  assign f_u_csatm8_pg_rca_k7_out[5] = 1'b0;
  assign f_u_csatm8_pg_rca_k7_out[6] = 1'b0;
  assign f_u_csatm8_pg_rca_k7_out[7] = 1'b0;
  assign f_u_csatm8_pg_rca_k7_out[8] = 1'b0;
  assign f_u_csatm8_pg_rca_k7_out[9] = 1'b0;
  assign f_u_csatm8_pg_rca_k7_out[10] = 1'b0;
  assign f_u_csatm8_pg_rca_k7_out[11] = 1'b0;
  assign f_u_csatm8_pg_rca_k7_out[12] = 1'b0;
  assign f_u_csatm8_pg_rca_k7_out[13] = 1'b0;
  assign f_u_csatm8_pg_rca_k7_out[14] = f_u_csatm8_pg_rca_k7_and7_7;
  assign f_u_csatm8_pg_rca_k7_out[15] = 1'b0;
endmodule