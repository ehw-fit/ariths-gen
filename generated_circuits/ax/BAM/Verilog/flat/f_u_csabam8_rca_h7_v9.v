module f_u_csabam8_rca_h7_v9(input [7:0] a, input [7:0] b, output [15:0] f_u_csabam8_rca_h7_v9_out);
  wire f_u_csabam8_rca_h7_v9_and2_7;
  wire f_u_csabam8_rca_h7_v9_and3_7;
  wire f_u_csabam8_rca_h7_v9_and4_7;
  wire f_u_csabam8_rca_h7_v9_and5_7;
  wire f_u_csabam8_rca_h7_v9_and6_7;
  wire f_u_csabam8_rca_h7_v9_and7_7;

  assign f_u_csabam8_rca_h7_v9_and2_7 = a[2] & b[7];
  assign f_u_csabam8_rca_h7_v9_and3_7 = a[3] & b[7];
  assign f_u_csabam8_rca_h7_v9_and4_7 = a[4] & b[7];
  assign f_u_csabam8_rca_h7_v9_and5_7 = a[5] & b[7];
  assign f_u_csabam8_rca_h7_v9_and6_7 = a[6] & b[7];
  assign f_u_csabam8_rca_h7_v9_and7_7 = a[7] & b[7];

  assign f_u_csabam8_rca_h7_v9_out[0] = 1'b0;
  assign f_u_csabam8_rca_h7_v9_out[1] = 1'b0;
  assign f_u_csabam8_rca_h7_v9_out[2] = 1'b0;
  assign f_u_csabam8_rca_h7_v9_out[3] = 1'b0;
  assign f_u_csabam8_rca_h7_v9_out[4] = 1'b0;
  assign f_u_csabam8_rca_h7_v9_out[5] = 1'b0;
  assign f_u_csabam8_rca_h7_v9_out[6] = 1'b0;
  assign f_u_csabam8_rca_h7_v9_out[7] = 1'b0;
  assign f_u_csabam8_rca_h7_v9_out[8] = 1'b0;
  assign f_u_csabam8_rca_h7_v9_out[9] = f_u_csabam8_rca_h7_v9_and2_7;
  assign f_u_csabam8_rca_h7_v9_out[10] = f_u_csabam8_rca_h7_v9_and3_7;
  assign f_u_csabam8_rca_h7_v9_out[11] = f_u_csabam8_rca_h7_v9_and4_7;
  assign f_u_csabam8_rca_h7_v9_out[12] = f_u_csabam8_rca_h7_v9_and5_7;
  assign f_u_csabam8_rca_h7_v9_out[13] = f_u_csabam8_rca_h7_v9_and6_7;
  assign f_u_csabam8_rca_h7_v9_out[14] = f_u_csabam8_rca_h7_v9_and7_7;
  assign f_u_csabam8_rca_h7_v9_out[15] = 1'b0;
endmodule