module and_gate(input a, input b, output out);
  assign out = a & b;
endmodule

module h_u_csabam8_pg_rca_h7_v7(input [7:0] a, input [7:0] b, output [15:0] h_u_csabam8_pg_rca_h7_v7_out);
  wire [0:0] h_u_csabam8_pg_rca_h7_v7_and0_7;
  wire [0:0] h_u_csabam8_pg_rca_h7_v7_and1_7;
  wire [0:0] h_u_csabam8_pg_rca_h7_v7_and2_7;
  wire [0:0] h_u_csabam8_pg_rca_h7_v7_and3_7;
  wire [0:0] h_u_csabam8_pg_rca_h7_v7_and4_7;
  wire [0:0] h_u_csabam8_pg_rca_h7_v7_and5_7;
  wire [0:0] h_u_csabam8_pg_rca_h7_v7_and6_7;
  wire [0:0] h_u_csabam8_pg_rca_h7_v7_and7_7;

  and_gate and_gate_h_u_csabam8_pg_rca_h7_v7_and0_7(.a(a[0]), .b(b[7]), .out(h_u_csabam8_pg_rca_h7_v7_and0_7));
  and_gate and_gate_h_u_csabam8_pg_rca_h7_v7_and1_7(.a(a[1]), .b(b[7]), .out(h_u_csabam8_pg_rca_h7_v7_and1_7));
  and_gate and_gate_h_u_csabam8_pg_rca_h7_v7_and2_7(.a(a[2]), .b(b[7]), .out(h_u_csabam8_pg_rca_h7_v7_and2_7));
  and_gate and_gate_h_u_csabam8_pg_rca_h7_v7_and3_7(.a(a[3]), .b(b[7]), .out(h_u_csabam8_pg_rca_h7_v7_and3_7));
  and_gate and_gate_h_u_csabam8_pg_rca_h7_v7_and4_7(.a(a[4]), .b(b[7]), .out(h_u_csabam8_pg_rca_h7_v7_and4_7));
  and_gate and_gate_h_u_csabam8_pg_rca_h7_v7_and5_7(.a(a[5]), .b(b[7]), .out(h_u_csabam8_pg_rca_h7_v7_and5_7));
  and_gate and_gate_h_u_csabam8_pg_rca_h7_v7_and6_7(.a(a[6]), .b(b[7]), .out(h_u_csabam8_pg_rca_h7_v7_and6_7));
  and_gate and_gate_h_u_csabam8_pg_rca_h7_v7_and7_7(.a(a[7]), .b(b[7]), .out(h_u_csabam8_pg_rca_h7_v7_and7_7));

  assign h_u_csabam8_pg_rca_h7_v7_out[0] = 1'b0;
  assign h_u_csabam8_pg_rca_h7_v7_out[1] = 1'b0;
  assign h_u_csabam8_pg_rca_h7_v7_out[2] = 1'b0;
  assign h_u_csabam8_pg_rca_h7_v7_out[3] = 1'b0;
  assign h_u_csabam8_pg_rca_h7_v7_out[4] = 1'b0;
  assign h_u_csabam8_pg_rca_h7_v7_out[5] = 1'b0;
  assign h_u_csabam8_pg_rca_h7_v7_out[6] = 1'b0;
  assign h_u_csabam8_pg_rca_h7_v7_out[7] = h_u_csabam8_pg_rca_h7_v7_and0_7[0];
  assign h_u_csabam8_pg_rca_h7_v7_out[8] = h_u_csabam8_pg_rca_h7_v7_and1_7[0];
  assign h_u_csabam8_pg_rca_h7_v7_out[9] = h_u_csabam8_pg_rca_h7_v7_and2_7[0];
  assign h_u_csabam8_pg_rca_h7_v7_out[10] = h_u_csabam8_pg_rca_h7_v7_and3_7[0];
  assign h_u_csabam8_pg_rca_h7_v7_out[11] = h_u_csabam8_pg_rca_h7_v7_and4_7[0];
  assign h_u_csabam8_pg_rca_h7_v7_out[12] = h_u_csabam8_pg_rca_h7_v7_and5_7[0];
  assign h_u_csabam8_pg_rca_h7_v7_out[13] = h_u_csabam8_pg_rca_h7_v7_and6_7[0];
  assign h_u_csabam8_pg_rca_h7_v7_out[14] = h_u_csabam8_pg_rca_h7_v7_and7_7[0];
  assign h_u_csabam8_pg_rca_h7_v7_out[15] = 1'b0;
endmodule