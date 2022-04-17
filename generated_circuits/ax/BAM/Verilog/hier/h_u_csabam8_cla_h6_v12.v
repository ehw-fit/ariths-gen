module and_gate(input a, input b, output out);
  assign out = a & b;
endmodule

module xor_gate(input a, input b, output out);
  assign out = a ^ b;
endmodule

module or_gate(input a, input b, output out);
  assign out = a | b;
endmodule

module ha(input [0:0] a, input [0:0] b, output [0:0] ha_xor0, output [0:0] ha_and0);
  xor_gate xor_gate_ha_xor0(.a(a[0]), .b(b[0]), .out(ha_xor0));
  and_gate and_gate_ha_and0(.a(a[0]), .b(b[0]), .out(ha_and0));
endmodule

module pg_logic(input [0:0] a, input [0:0] b, output [0:0] pg_logic_or0, output [0:0] pg_logic_and0, output [0:0] pg_logic_xor0);
  or_gate or_gate_pg_logic_or0(.a(a[0]), .b(b[0]), .out(pg_logic_or0));
  and_gate and_gate_pg_logic_and0(.a(a[0]), .b(b[0]), .out(pg_logic_and0));
  xor_gate xor_gate_pg_logic_xor0(.a(a[0]), .b(b[0]), .out(pg_logic_xor0));
endmodule

module u_cla3(input [2:0] a, input [2:0] b, output [3:0] u_cla3_out);
  wire [0:0] u_cla3_pg_logic0_or0;
  wire [0:0] u_cla3_pg_logic0_and0;
  wire [0:0] u_cla3_pg_logic0_xor0;
  wire [0:0] u_cla3_pg_logic1_or0;
  wire [0:0] u_cla3_pg_logic1_and0;
  wire [0:0] u_cla3_pg_logic1_xor0;
  wire [0:0] u_cla3_xor1;
  wire [0:0] u_cla3_and0;
  wire [0:0] u_cla3_or0;
  wire [0:0] u_cla3_pg_logic2_or0;
  wire [0:0] u_cla3_pg_logic2_and0;
  wire [0:0] u_cla3_pg_logic2_xor0;
  wire [0:0] u_cla3_xor2;
  wire [0:0] u_cla3_and1;
  wire [0:0] u_cla3_and2;
  wire [0:0] u_cla3_and3;
  wire [0:0] u_cla3_and4;
  wire [0:0] u_cla3_or1;
  wire [0:0] u_cla3_or2;

  pg_logic pg_logic_u_cla3_pg_logic0_out(.a(a[0]), .b(b[0]), .pg_logic_or0(u_cla3_pg_logic0_or0), .pg_logic_and0(u_cla3_pg_logic0_and0), .pg_logic_xor0(u_cla3_pg_logic0_xor0));
  pg_logic pg_logic_u_cla3_pg_logic1_out(.a(a[1]), .b(b[1]), .pg_logic_or0(u_cla3_pg_logic1_or0), .pg_logic_and0(u_cla3_pg_logic1_and0), .pg_logic_xor0(u_cla3_pg_logic1_xor0));
  xor_gate xor_gate_u_cla3_xor1(.a(u_cla3_pg_logic1_xor0[0]), .b(u_cla3_pg_logic0_and0[0]), .out(u_cla3_xor1));
  and_gate and_gate_u_cla3_and0(.a(u_cla3_pg_logic0_and0[0]), .b(u_cla3_pg_logic1_or0[0]), .out(u_cla3_and0));
  or_gate or_gate_u_cla3_or0(.a(u_cla3_pg_logic1_and0[0]), .b(u_cla3_and0[0]), .out(u_cla3_or0));
  pg_logic pg_logic_u_cla3_pg_logic2_out(.a(a[2]), .b(b[2]), .pg_logic_or0(u_cla3_pg_logic2_or0), .pg_logic_and0(u_cla3_pg_logic2_and0), .pg_logic_xor0(u_cla3_pg_logic2_xor0));
  xor_gate xor_gate_u_cla3_xor2(.a(u_cla3_pg_logic2_xor0[0]), .b(u_cla3_or0[0]), .out(u_cla3_xor2));
  and_gate and_gate_u_cla3_and1(.a(u_cla3_pg_logic2_or0[0]), .b(u_cla3_pg_logic0_or0[0]), .out(u_cla3_and1));
  and_gate and_gate_u_cla3_and2(.a(u_cla3_pg_logic0_and0[0]), .b(u_cla3_pg_logic2_or0[0]), .out(u_cla3_and2));
  and_gate and_gate_u_cla3_and3(.a(u_cla3_and2[0]), .b(u_cla3_pg_logic1_or0[0]), .out(u_cla3_and3));
  and_gate and_gate_u_cla3_and4(.a(u_cla3_pg_logic1_and0[0]), .b(u_cla3_pg_logic2_or0[0]), .out(u_cla3_and4));
  or_gate or_gate_u_cla3_or1(.a(u_cla3_and3[0]), .b(u_cla3_and4[0]), .out(u_cla3_or1));
  or_gate or_gate_u_cla3_or2(.a(u_cla3_pg_logic2_and0[0]), .b(u_cla3_or1[0]), .out(u_cla3_or2));

  assign u_cla3_out[0] = u_cla3_pg_logic0_xor0[0];
  assign u_cla3_out[1] = u_cla3_xor1[0];
  assign u_cla3_out[2] = u_cla3_xor2[0];
  assign u_cla3_out[3] = u_cla3_or2[0];
endmodule

module h_u_csabam8_cla_h6_v12(input [7:0] a, input [7:0] b, output [15:0] h_u_csabam8_cla_h6_v12_out);
  wire [0:0] h_u_csabam8_cla_h6_v12_and6_6;
  wire [0:0] h_u_csabam8_cla_h6_v12_and7_6;
  wire [0:0] h_u_csabam8_cla_h6_v12_and5_7;
  wire [0:0] h_u_csabam8_cla_h6_v12_ha5_7_xor0;
  wire [0:0] h_u_csabam8_cla_h6_v12_ha5_7_and0;
  wire [0:0] h_u_csabam8_cla_h6_v12_and6_7;
  wire [0:0] h_u_csabam8_cla_h6_v12_ha6_7_xor0;
  wire [0:0] h_u_csabam8_cla_h6_v12_ha6_7_and0;
  wire [0:0] h_u_csabam8_cla_h6_v12_and7_7;
  wire [2:0] h_u_csabam8_cla_h6_v12_u_cla3_a;
  wire [2:0] h_u_csabam8_cla_h6_v12_u_cla3_b;
  wire [3:0] h_u_csabam8_cla_h6_v12_u_cla3_out;

  and_gate and_gate_h_u_csabam8_cla_h6_v12_and6_6(.a(a[6]), .b(b[6]), .out(h_u_csabam8_cla_h6_v12_and6_6));
  and_gate and_gate_h_u_csabam8_cla_h6_v12_and7_6(.a(a[7]), .b(b[6]), .out(h_u_csabam8_cla_h6_v12_and7_6));
  and_gate and_gate_h_u_csabam8_cla_h6_v12_and5_7(.a(a[5]), .b(b[7]), .out(h_u_csabam8_cla_h6_v12_and5_7));
  ha ha_h_u_csabam8_cla_h6_v12_ha5_7_out(.a(h_u_csabam8_cla_h6_v12_and5_7[0]), .b(h_u_csabam8_cla_h6_v12_and6_6[0]), .ha_xor0(h_u_csabam8_cla_h6_v12_ha5_7_xor0), .ha_and0(h_u_csabam8_cla_h6_v12_ha5_7_and0));
  and_gate and_gate_h_u_csabam8_cla_h6_v12_and6_7(.a(a[6]), .b(b[7]), .out(h_u_csabam8_cla_h6_v12_and6_7));
  ha ha_h_u_csabam8_cla_h6_v12_ha6_7_out(.a(h_u_csabam8_cla_h6_v12_and6_7[0]), .b(h_u_csabam8_cla_h6_v12_and7_6[0]), .ha_xor0(h_u_csabam8_cla_h6_v12_ha6_7_xor0), .ha_and0(h_u_csabam8_cla_h6_v12_ha6_7_and0));
  and_gate and_gate_h_u_csabam8_cla_h6_v12_and7_7(.a(a[7]), .b(b[7]), .out(h_u_csabam8_cla_h6_v12_and7_7));
  assign h_u_csabam8_cla_h6_v12_u_cla3_a[0] = h_u_csabam8_cla_h6_v12_ha6_7_xor0[0];
  assign h_u_csabam8_cla_h6_v12_u_cla3_a[1] = h_u_csabam8_cla_h6_v12_and7_7[0];
  assign h_u_csabam8_cla_h6_v12_u_cla3_a[2] = 1'b0;
  assign h_u_csabam8_cla_h6_v12_u_cla3_b[0] = 1'b0;
  assign h_u_csabam8_cla_h6_v12_u_cla3_b[1] = h_u_csabam8_cla_h6_v12_ha6_7_and0[0];
  assign h_u_csabam8_cla_h6_v12_u_cla3_b[2] = 1'b0;
  u_cla3 u_cla3_h_u_csabam8_cla_h6_v12_u_cla3_out(.a(h_u_csabam8_cla_h6_v12_u_cla3_a), .b(h_u_csabam8_cla_h6_v12_u_cla3_b), .u_cla3_out(h_u_csabam8_cla_h6_v12_u_cla3_out));

  assign h_u_csabam8_cla_h6_v12_out[0] = 1'b0;
  assign h_u_csabam8_cla_h6_v12_out[1] = 1'b0;
  assign h_u_csabam8_cla_h6_v12_out[2] = 1'b0;
  assign h_u_csabam8_cla_h6_v12_out[3] = 1'b0;
  assign h_u_csabam8_cla_h6_v12_out[4] = 1'b0;
  assign h_u_csabam8_cla_h6_v12_out[5] = 1'b0;
  assign h_u_csabam8_cla_h6_v12_out[6] = 1'b0;
  assign h_u_csabam8_cla_h6_v12_out[7] = 1'b0;
  assign h_u_csabam8_cla_h6_v12_out[8] = 1'b0;
  assign h_u_csabam8_cla_h6_v12_out[9] = 1'b0;
  assign h_u_csabam8_cla_h6_v12_out[10] = 1'b0;
  assign h_u_csabam8_cla_h6_v12_out[11] = 1'b0;
  assign h_u_csabam8_cla_h6_v12_out[12] = h_u_csabam8_cla_h6_v12_u_cla3_out[0];
  assign h_u_csabam8_cla_h6_v12_out[13] = h_u_csabam8_cla_h6_v12_u_cla3_out[1];
  assign h_u_csabam8_cla_h6_v12_out[14] = h_u_csabam8_cla_h6_v12_u_cla3_out[2];
  assign h_u_csabam8_cla_h6_v12_out[15] = 1'b0;
endmodule