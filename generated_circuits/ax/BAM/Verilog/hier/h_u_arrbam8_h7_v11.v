module and_gate(input a, input b, output out);
  assign out = a & b;
endmodule

module h_u_arrbam8_h7_v11(input [7:0] a, input [7:0] b, output [15:0] h_u_arrbam8_h7_v11_out);
  wire [0:0] h_u_arrbam8_h7_v11_and4_7;
  wire [0:0] h_u_arrbam8_h7_v11_and5_7;
  wire [0:0] h_u_arrbam8_h7_v11_and6_7;
  wire [0:0] h_u_arrbam8_h7_v11_and7_7;

  and_gate and_gate_h_u_arrbam8_h7_v11_and4_7(.a(a[4]), .b(b[7]), .out(h_u_arrbam8_h7_v11_and4_7));
  and_gate and_gate_h_u_arrbam8_h7_v11_and5_7(.a(a[5]), .b(b[7]), .out(h_u_arrbam8_h7_v11_and5_7));
  and_gate and_gate_h_u_arrbam8_h7_v11_and6_7(.a(a[6]), .b(b[7]), .out(h_u_arrbam8_h7_v11_and6_7));
  and_gate and_gate_h_u_arrbam8_h7_v11_and7_7(.a(a[7]), .b(b[7]), .out(h_u_arrbam8_h7_v11_and7_7));

  assign h_u_arrbam8_h7_v11_out[0] = 1'b0;
  assign h_u_arrbam8_h7_v11_out[1] = 1'b0;
  assign h_u_arrbam8_h7_v11_out[2] = 1'b0;
  assign h_u_arrbam8_h7_v11_out[3] = 1'b0;
  assign h_u_arrbam8_h7_v11_out[4] = 1'b0;
  assign h_u_arrbam8_h7_v11_out[5] = 1'b0;
  assign h_u_arrbam8_h7_v11_out[6] = 1'b0;
  assign h_u_arrbam8_h7_v11_out[7] = 1'b0;
  assign h_u_arrbam8_h7_v11_out[8] = 1'b0;
  assign h_u_arrbam8_h7_v11_out[9] = 1'b0;
  assign h_u_arrbam8_h7_v11_out[10] = 1'b0;
  assign h_u_arrbam8_h7_v11_out[11] = h_u_arrbam8_h7_v11_and4_7[0];
  assign h_u_arrbam8_h7_v11_out[12] = h_u_arrbam8_h7_v11_and5_7[0];
  assign h_u_arrbam8_h7_v11_out[13] = h_u_arrbam8_h7_v11_and6_7[0];
  assign h_u_arrbam8_h7_v11_out[14] = h_u_arrbam8_h7_v11_and7_7[0];
  assign h_u_arrbam8_h7_v11_out[15] = 1'b0;
endmodule