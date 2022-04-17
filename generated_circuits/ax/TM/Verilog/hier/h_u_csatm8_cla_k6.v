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

module u_cla2(input [1:0] a, input [1:0] b, output [2:0] u_cla2_out);
  wire [0:0] u_cla2_pg_logic0_or0;
  wire [0:0] u_cla2_pg_logic0_and0;
  wire [0:0] u_cla2_pg_logic0_xor0;
  wire [0:0] u_cla2_pg_logic1_or0;
  wire [0:0] u_cla2_pg_logic1_and0;
  wire [0:0] u_cla2_pg_logic1_xor0;
  wire [0:0] u_cla2_xor1;
  wire [0:0] u_cla2_and0;
  wire [0:0] u_cla2_or0;

  pg_logic pg_logic_u_cla2_pg_logic0_out(.a(a[0]), .b(b[0]), .pg_logic_or0(u_cla2_pg_logic0_or0), .pg_logic_and0(u_cla2_pg_logic0_and0), .pg_logic_xor0(u_cla2_pg_logic0_xor0));
  pg_logic pg_logic_u_cla2_pg_logic1_out(.a(a[1]), .b(b[1]), .pg_logic_or0(u_cla2_pg_logic1_or0), .pg_logic_and0(u_cla2_pg_logic1_and0), .pg_logic_xor0(u_cla2_pg_logic1_xor0));
  xor_gate xor_gate_u_cla2_xor1(.a(u_cla2_pg_logic1_xor0[0]), .b(u_cla2_pg_logic0_and0[0]), .out(u_cla2_xor1));
  and_gate and_gate_u_cla2_and0(.a(u_cla2_pg_logic0_and0[0]), .b(u_cla2_pg_logic1_or0[0]), .out(u_cla2_and0));
  or_gate or_gate_u_cla2_or0(.a(u_cla2_pg_logic1_and0[0]), .b(u_cla2_and0[0]), .out(u_cla2_or0));

  assign u_cla2_out[0] = u_cla2_pg_logic0_xor0[0];
  assign u_cla2_out[1] = u_cla2_xor1[0];
  assign u_cla2_out[2] = u_cla2_or0[0];
endmodule

module h_u_csatm8_cla_k6(input [7:0] a, input [7:0] b, output [15:0] h_u_csatm8_cla_k6_out);
  wire [0:0] h_u_csatm8_cla_k6_and6_6;
  wire [0:0] h_u_csatm8_cla_k6_and7_6;
  wire [0:0] h_u_csatm8_cla_k6_and6_7;
  wire [0:0] h_u_csatm8_cla_k6_ha6_7_xor0;
  wire [0:0] h_u_csatm8_cla_k6_ha6_7_and0;
  wire [0:0] h_u_csatm8_cla_k6_and7_7;
  wire [1:0] h_u_csatm8_cla_k6_u_cla2_a;
  wire [1:0] h_u_csatm8_cla_k6_u_cla2_b;
  wire [2:0] h_u_csatm8_cla_k6_u_cla2_out;

  and_gate and_gate_h_u_csatm8_cla_k6_and6_6(.a(a[6]), .b(b[6]), .out(h_u_csatm8_cla_k6_and6_6));
  and_gate and_gate_h_u_csatm8_cla_k6_and7_6(.a(a[7]), .b(b[6]), .out(h_u_csatm8_cla_k6_and7_6));
  and_gate and_gate_h_u_csatm8_cla_k6_and6_7(.a(a[6]), .b(b[7]), .out(h_u_csatm8_cla_k6_and6_7));
  ha ha_h_u_csatm8_cla_k6_ha6_7_out(.a(h_u_csatm8_cla_k6_and6_7[0]), .b(h_u_csatm8_cla_k6_and7_6[0]), .ha_xor0(h_u_csatm8_cla_k6_ha6_7_xor0), .ha_and0(h_u_csatm8_cla_k6_ha6_7_and0));
  and_gate and_gate_h_u_csatm8_cla_k6_and7_7(.a(a[7]), .b(b[7]), .out(h_u_csatm8_cla_k6_and7_7));
  assign h_u_csatm8_cla_k6_u_cla2_a[0] = h_u_csatm8_cla_k6_and7_7[0];
  assign h_u_csatm8_cla_k6_u_cla2_a[1] = 1'b0;
  assign h_u_csatm8_cla_k6_u_cla2_b[0] = h_u_csatm8_cla_k6_ha6_7_and0[0];
  assign h_u_csatm8_cla_k6_u_cla2_b[1] = 1'b0;
  u_cla2 u_cla2_h_u_csatm8_cla_k6_u_cla2_out(.a(h_u_csatm8_cla_k6_u_cla2_a), .b(h_u_csatm8_cla_k6_u_cla2_b), .u_cla2_out(h_u_csatm8_cla_k6_u_cla2_out));

  assign h_u_csatm8_cla_k6_out[0] = 1'b0;
  assign h_u_csatm8_cla_k6_out[1] = 1'b0;
  assign h_u_csatm8_cla_k6_out[2] = 1'b0;
  assign h_u_csatm8_cla_k6_out[3] = 1'b0;
  assign h_u_csatm8_cla_k6_out[4] = 1'b0;
  assign h_u_csatm8_cla_k6_out[5] = 1'b0;
  assign h_u_csatm8_cla_k6_out[6] = 1'b0;
  assign h_u_csatm8_cla_k6_out[7] = 1'b0;
  assign h_u_csatm8_cla_k6_out[8] = 1'b0;
  assign h_u_csatm8_cla_k6_out[9] = 1'b0;
  assign h_u_csatm8_cla_k6_out[10] = 1'b0;
  assign h_u_csatm8_cla_k6_out[11] = 1'b0;
  assign h_u_csatm8_cla_k6_out[12] = h_u_csatm8_cla_k6_and6_6[0];
  assign h_u_csatm8_cla_k6_out[13] = h_u_csatm8_cla_k6_ha6_7_xor0[0];
  assign h_u_csatm8_cla_k6_out[14] = h_u_csatm8_cla_k6_u_cla2_out[0];
  assign h_u_csatm8_cla_k6_out[15] = h_u_csatm8_cla_k6_u_cla2_out[1];
endmodule