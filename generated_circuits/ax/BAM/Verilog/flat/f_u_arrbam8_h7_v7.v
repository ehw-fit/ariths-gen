module f_u_arrbam8_h7_v7(input [7:0] a, input [7:0] b, output [15:0] f_u_arrbam8_h7_v7_out);
  wire f_u_arrbam8_h7_v7_and0_7;
  wire f_u_arrbam8_h7_v7_and1_7;
  wire f_u_arrbam8_h7_v7_and2_7;
  wire f_u_arrbam8_h7_v7_and3_7;
  wire f_u_arrbam8_h7_v7_and4_7;
  wire f_u_arrbam8_h7_v7_and5_7;
  wire f_u_arrbam8_h7_v7_and6_7;
  wire f_u_arrbam8_h7_v7_and7_7;

  assign f_u_arrbam8_h7_v7_and0_7 = a[0] & b[7];
  assign f_u_arrbam8_h7_v7_and1_7 = a[1] & b[7];
  assign f_u_arrbam8_h7_v7_and2_7 = a[2] & b[7];
  assign f_u_arrbam8_h7_v7_and3_7 = a[3] & b[7];
  assign f_u_arrbam8_h7_v7_and4_7 = a[4] & b[7];
  assign f_u_arrbam8_h7_v7_and5_7 = a[5] & b[7];
  assign f_u_arrbam8_h7_v7_and6_7 = a[6] & b[7];
  assign f_u_arrbam8_h7_v7_and7_7 = a[7] & b[7];

  assign f_u_arrbam8_h7_v7_out[0] = 1'b0;
  assign f_u_arrbam8_h7_v7_out[1] = 1'b0;
  assign f_u_arrbam8_h7_v7_out[2] = 1'b0;
  assign f_u_arrbam8_h7_v7_out[3] = 1'b0;
  assign f_u_arrbam8_h7_v7_out[4] = 1'b0;
  assign f_u_arrbam8_h7_v7_out[5] = 1'b0;
  assign f_u_arrbam8_h7_v7_out[6] = 1'b0;
  assign f_u_arrbam8_h7_v7_out[7] = f_u_arrbam8_h7_v7_and0_7;
  assign f_u_arrbam8_h7_v7_out[8] = f_u_arrbam8_h7_v7_and1_7;
  assign f_u_arrbam8_h7_v7_out[9] = f_u_arrbam8_h7_v7_and2_7;
  assign f_u_arrbam8_h7_v7_out[10] = f_u_arrbam8_h7_v7_and3_7;
  assign f_u_arrbam8_h7_v7_out[11] = f_u_arrbam8_h7_v7_and4_7;
  assign f_u_arrbam8_h7_v7_out[12] = f_u_arrbam8_h7_v7_and5_7;
  assign f_u_arrbam8_h7_v7_out[13] = f_u_arrbam8_h7_v7_and6_7;
  assign f_u_arrbam8_h7_v7_out[14] = f_u_arrbam8_h7_v7_and7_7;
  assign f_u_arrbam8_h7_v7_out[15] = 1'b0;
endmodule