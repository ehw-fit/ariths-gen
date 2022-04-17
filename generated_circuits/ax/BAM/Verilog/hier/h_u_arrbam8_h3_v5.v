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

module fa(input [0:0] a, input [0:0] b, input [0:0] cin, output [0:0] fa_xor1, output [0:0] fa_or0);
  wire [0:0] fa_xor0;
  wire [0:0] fa_and0;
  wire [0:0] fa_and1;
  xor_gate xor_gate_fa_xor0(.a(a[0]), .b(b[0]), .out(fa_xor0));
  and_gate and_gate_fa_and0(.a(a[0]), .b(b[0]), .out(fa_and0));
  xor_gate xor_gate_fa_xor1(.a(fa_xor0[0]), .b(cin[0]), .out(fa_xor1));
  and_gate and_gate_fa_and1(.a(fa_xor0[0]), .b(cin[0]), .out(fa_and1));
  or_gate or_gate_fa_or0(.a(fa_and0[0]), .b(fa_and1[0]), .out(fa_or0));
endmodule

module h_u_arrbam8_h3_v5(input [7:0] a, input [7:0] b, output [15:0] h_u_arrbam8_h3_v5_out);
  wire [0:0] h_u_arrbam8_h3_v5_and2_3;
  wire [0:0] h_u_arrbam8_h3_v5_and3_3;
  wire [0:0] h_u_arrbam8_h3_v5_and4_3;
  wire [0:0] h_u_arrbam8_h3_v5_and5_3;
  wire [0:0] h_u_arrbam8_h3_v5_and6_3;
  wire [0:0] h_u_arrbam8_h3_v5_and7_3;
  wire [0:0] h_u_arrbam8_h3_v5_and1_4;
  wire [0:0] h_u_arrbam8_h3_v5_ha1_4_xor0;
  wire [0:0] h_u_arrbam8_h3_v5_ha1_4_and0;
  wire [0:0] h_u_arrbam8_h3_v5_and2_4;
  wire [0:0] h_u_arrbam8_h3_v5_fa2_4_xor1;
  wire [0:0] h_u_arrbam8_h3_v5_fa2_4_or0;
  wire [0:0] h_u_arrbam8_h3_v5_and3_4;
  wire [0:0] h_u_arrbam8_h3_v5_fa3_4_xor1;
  wire [0:0] h_u_arrbam8_h3_v5_fa3_4_or0;
  wire [0:0] h_u_arrbam8_h3_v5_and4_4;
  wire [0:0] h_u_arrbam8_h3_v5_fa4_4_xor1;
  wire [0:0] h_u_arrbam8_h3_v5_fa4_4_or0;
  wire [0:0] h_u_arrbam8_h3_v5_and5_4;
  wire [0:0] h_u_arrbam8_h3_v5_fa5_4_xor1;
  wire [0:0] h_u_arrbam8_h3_v5_fa5_4_or0;
  wire [0:0] h_u_arrbam8_h3_v5_and6_4;
  wire [0:0] h_u_arrbam8_h3_v5_fa6_4_xor1;
  wire [0:0] h_u_arrbam8_h3_v5_fa6_4_or0;
  wire [0:0] h_u_arrbam8_h3_v5_and7_4;
  wire [0:0] h_u_arrbam8_h3_v5_ha7_4_xor0;
  wire [0:0] h_u_arrbam8_h3_v5_ha7_4_and0;
  wire [0:0] h_u_arrbam8_h3_v5_and0_5;
  wire [0:0] h_u_arrbam8_h3_v5_ha0_5_xor0;
  wire [0:0] h_u_arrbam8_h3_v5_ha0_5_and0;
  wire [0:0] h_u_arrbam8_h3_v5_and1_5;
  wire [0:0] h_u_arrbam8_h3_v5_fa1_5_xor1;
  wire [0:0] h_u_arrbam8_h3_v5_fa1_5_or0;
  wire [0:0] h_u_arrbam8_h3_v5_and2_5;
  wire [0:0] h_u_arrbam8_h3_v5_fa2_5_xor1;
  wire [0:0] h_u_arrbam8_h3_v5_fa2_5_or0;
  wire [0:0] h_u_arrbam8_h3_v5_and3_5;
  wire [0:0] h_u_arrbam8_h3_v5_fa3_5_xor1;
  wire [0:0] h_u_arrbam8_h3_v5_fa3_5_or0;
  wire [0:0] h_u_arrbam8_h3_v5_and4_5;
  wire [0:0] h_u_arrbam8_h3_v5_fa4_5_xor1;
  wire [0:0] h_u_arrbam8_h3_v5_fa4_5_or0;
  wire [0:0] h_u_arrbam8_h3_v5_and5_5;
  wire [0:0] h_u_arrbam8_h3_v5_fa5_5_xor1;
  wire [0:0] h_u_arrbam8_h3_v5_fa5_5_or0;
  wire [0:0] h_u_arrbam8_h3_v5_and6_5;
  wire [0:0] h_u_arrbam8_h3_v5_fa6_5_xor1;
  wire [0:0] h_u_arrbam8_h3_v5_fa6_5_or0;
  wire [0:0] h_u_arrbam8_h3_v5_and7_5;
  wire [0:0] h_u_arrbam8_h3_v5_fa7_5_xor1;
  wire [0:0] h_u_arrbam8_h3_v5_fa7_5_or0;
  wire [0:0] h_u_arrbam8_h3_v5_and0_6;
  wire [0:0] h_u_arrbam8_h3_v5_ha0_6_xor0;
  wire [0:0] h_u_arrbam8_h3_v5_ha0_6_and0;
  wire [0:0] h_u_arrbam8_h3_v5_and1_6;
  wire [0:0] h_u_arrbam8_h3_v5_fa1_6_xor1;
  wire [0:0] h_u_arrbam8_h3_v5_fa1_6_or0;
  wire [0:0] h_u_arrbam8_h3_v5_and2_6;
  wire [0:0] h_u_arrbam8_h3_v5_fa2_6_xor1;
  wire [0:0] h_u_arrbam8_h3_v5_fa2_6_or0;
  wire [0:0] h_u_arrbam8_h3_v5_and3_6;
  wire [0:0] h_u_arrbam8_h3_v5_fa3_6_xor1;
  wire [0:0] h_u_arrbam8_h3_v5_fa3_6_or0;
  wire [0:0] h_u_arrbam8_h3_v5_and4_6;
  wire [0:0] h_u_arrbam8_h3_v5_fa4_6_xor1;
  wire [0:0] h_u_arrbam8_h3_v5_fa4_6_or0;
  wire [0:0] h_u_arrbam8_h3_v5_and5_6;
  wire [0:0] h_u_arrbam8_h3_v5_fa5_6_xor1;
  wire [0:0] h_u_arrbam8_h3_v5_fa5_6_or0;
  wire [0:0] h_u_arrbam8_h3_v5_and6_6;
  wire [0:0] h_u_arrbam8_h3_v5_fa6_6_xor1;
  wire [0:0] h_u_arrbam8_h3_v5_fa6_6_or0;
  wire [0:0] h_u_arrbam8_h3_v5_and7_6;
  wire [0:0] h_u_arrbam8_h3_v5_fa7_6_xor1;
  wire [0:0] h_u_arrbam8_h3_v5_fa7_6_or0;
  wire [0:0] h_u_arrbam8_h3_v5_and0_7;
  wire [0:0] h_u_arrbam8_h3_v5_ha0_7_xor0;
  wire [0:0] h_u_arrbam8_h3_v5_ha0_7_and0;
  wire [0:0] h_u_arrbam8_h3_v5_and1_7;
  wire [0:0] h_u_arrbam8_h3_v5_fa1_7_xor1;
  wire [0:0] h_u_arrbam8_h3_v5_fa1_7_or0;
  wire [0:0] h_u_arrbam8_h3_v5_and2_7;
  wire [0:0] h_u_arrbam8_h3_v5_fa2_7_xor1;
  wire [0:0] h_u_arrbam8_h3_v5_fa2_7_or0;
  wire [0:0] h_u_arrbam8_h3_v5_and3_7;
  wire [0:0] h_u_arrbam8_h3_v5_fa3_7_xor1;
  wire [0:0] h_u_arrbam8_h3_v5_fa3_7_or0;
  wire [0:0] h_u_arrbam8_h3_v5_and4_7;
  wire [0:0] h_u_arrbam8_h3_v5_fa4_7_xor1;
  wire [0:0] h_u_arrbam8_h3_v5_fa4_7_or0;
  wire [0:0] h_u_arrbam8_h3_v5_and5_7;
  wire [0:0] h_u_arrbam8_h3_v5_fa5_7_xor1;
  wire [0:0] h_u_arrbam8_h3_v5_fa5_7_or0;
  wire [0:0] h_u_arrbam8_h3_v5_and6_7;
  wire [0:0] h_u_arrbam8_h3_v5_fa6_7_xor1;
  wire [0:0] h_u_arrbam8_h3_v5_fa6_7_or0;
  wire [0:0] h_u_arrbam8_h3_v5_and7_7;
  wire [0:0] h_u_arrbam8_h3_v5_fa7_7_xor1;
  wire [0:0] h_u_arrbam8_h3_v5_fa7_7_or0;

  and_gate and_gate_h_u_arrbam8_h3_v5_and2_3(.a(a[2]), .b(b[3]), .out(h_u_arrbam8_h3_v5_and2_3));
  and_gate and_gate_h_u_arrbam8_h3_v5_and3_3(.a(a[3]), .b(b[3]), .out(h_u_arrbam8_h3_v5_and3_3));
  and_gate and_gate_h_u_arrbam8_h3_v5_and4_3(.a(a[4]), .b(b[3]), .out(h_u_arrbam8_h3_v5_and4_3));
  and_gate and_gate_h_u_arrbam8_h3_v5_and5_3(.a(a[5]), .b(b[3]), .out(h_u_arrbam8_h3_v5_and5_3));
  and_gate and_gate_h_u_arrbam8_h3_v5_and6_3(.a(a[6]), .b(b[3]), .out(h_u_arrbam8_h3_v5_and6_3));
  and_gate and_gate_h_u_arrbam8_h3_v5_and7_3(.a(a[7]), .b(b[3]), .out(h_u_arrbam8_h3_v5_and7_3));
  and_gate and_gate_h_u_arrbam8_h3_v5_and1_4(.a(a[1]), .b(b[4]), .out(h_u_arrbam8_h3_v5_and1_4));
  ha ha_h_u_arrbam8_h3_v5_ha1_4_out(.a(h_u_arrbam8_h3_v5_and1_4[0]), .b(h_u_arrbam8_h3_v5_and2_3[0]), .ha_xor0(h_u_arrbam8_h3_v5_ha1_4_xor0), .ha_and0(h_u_arrbam8_h3_v5_ha1_4_and0));
  and_gate and_gate_h_u_arrbam8_h3_v5_and2_4(.a(a[2]), .b(b[4]), .out(h_u_arrbam8_h3_v5_and2_4));
  fa fa_h_u_arrbam8_h3_v5_fa2_4_out(.a(h_u_arrbam8_h3_v5_and2_4[0]), .b(h_u_arrbam8_h3_v5_and3_3[0]), .cin(h_u_arrbam8_h3_v5_ha1_4_and0[0]), .fa_xor1(h_u_arrbam8_h3_v5_fa2_4_xor1), .fa_or0(h_u_arrbam8_h3_v5_fa2_4_or0));
  and_gate and_gate_h_u_arrbam8_h3_v5_and3_4(.a(a[3]), .b(b[4]), .out(h_u_arrbam8_h3_v5_and3_4));
  fa fa_h_u_arrbam8_h3_v5_fa3_4_out(.a(h_u_arrbam8_h3_v5_and3_4[0]), .b(h_u_arrbam8_h3_v5_and4_3[0]), .cin(h_u_arrbam8_h3_v5_fa2_4_or0[0]), .fa_xor1(h_u_arrbam8_h3_v5_fa3_4_xor1), .fa_or0(h_u_arrbam8_h3_v5_fa3_4_or0));
  and_gate and_gate_h_u_arrbam8_h3_v5_and4_4(.a(a[4]), .b(b[4]), .out(h_u_arrbam8_h3_v5_and4_4));
  fa fa_h_u_arrbam8_h3_v5_fa4_4_out(.a(h_u_arrbam8_h3_v5_and4_4[0]), .b(h_u_arrbam8_h3_v5_and5_3[0]), .cin(h_u_arrbam8_h3_v5_fa3_4_or0[0]), .fa_xor1(h_u_arrbam8_h3_v5_fa4_4_xor1), .fa_or0(h_u_arrbam8_h3_v5_fa4_4_or0));
  and_gate and_gate_h_u_arrbam8_h3_v5_and5_4(.a(a[5]), .b(b[4]), .out(h_u_arrbam8_h3_v5_and5_4));
  fa fa_h_u_arrbam8_h3_v5_fa5_4_out(.a(h_u_arrbam8_h3_v5_and5_4[0]), .b(h_u_arrbam8_h3_v5_and6_3[0]), .cin(h_u_arrbam8_h3_v5_fa4_4_or0[0]), .fa_xor1(h_u_arrbam8_h3_v5_fa5_4_xor1), .fa_or0(h_u_arrbam8_h3_v5_fa5_4_or0));
  and_gate and_gate_h_u_arrbam8_h3_v5_and6_4(.a(a[6]), .b(b[4]), .out(h_u_arrbam8_h3_v5_and6_4));
  fa fa_h_u_arrbam8_h3_v5_fa6_4_out(.a(h_u_arrbam8_h3_v5_and6_4[0]), .b(h_u_arrbam8_h3_v5_and7_3[0]), .cin(h_u_arrbam8_h3_v5_fa5_4_or0[0]), .fa_xor1(h_u_arrbam8_h3_v5_fa6_4_xor1), .fa_or0(h_u_arrbam8_h3_v5_fa6_4_or0));
  and_gate and_gate_h_u_arrbam8_h3_v5_and7_4(.a(a[7]), .b(b[4]), .out(h_u_arrbam8_h3_v5_and7_4));
  ha ha_h_u_arrbam8_h3_v5_ha7_4_out(.a(h_u_arrbam8_h3_v5_and7_4[0]), .b(h_u_arrbam8_h3_v5_fa6_4_or0[0]), .ha_xor0(h_u_arrbam8_h3_v5_ha7_4_xor0), .ha_and0(h_u_arrbam8_h3_v5_ha7_4_and0));
  and_gate and_gate_h_u_arrbam8_h3_v5_and0_5(.a(a[0]), .b(b[5]), .out(h_u_arrbam8_h3_v5_and0_5));
  ha ha_h_u_arrbam8_h3_v5_ha0_5_out(.a(h_u_arrbam8_h3_v5_and0_5[0]), .b(h_u_arrbam8_h3_v5_ha1_4_xor0[0]), .ha_xor0(h_u_arrbam8_h3_v5_ha0_5_xor0), .ha_and0(h_u_arrbam8_h3_v5_ha0_5_and0));
  and_gate and_gate_h_u_arrbam8_h3_v5_and1_5(.a(a[1]), .b(b[5]), .out(h_u_arrbam8_h3_v5_and1_5));
  fa fa_h_u_arrbam8_h3_v5_fa1_5_out(.a(h_u_arrbam8_h3_v5_and1_5[0]), .b(h_u_arrbam8_h3_v5_fa2_4_xor1[0]), .cin(h_u_arrbam8_h3_v5_ha0_5_and0[0]), .fa_xor1(h_u_arrbam8_h3_v5_fa1_5_xor1), .fa_or0(h_u_arrbam8_h3_v5_fa1_5_or0));
  and_gate and_gate_h_u_arrbam8_h3_v5_and2_5(.a(a[2]), .b(b[5]), .out(h_u_arrbam8_h3_v5_and2_5));
  fa fa_h_u_arrbam8_h3_v5_fa2_5_out(.a(h_u_arrbam8_h3_v5_and2_5[0]), .b(h_u_arrbam8_h3_v5_fa3_4_xor1[0]), .cin(h_u_arrbam8_h3_v5_fa1_5_or0[0]), .fa_xor1(h_u_arrbam8_h3_v5_fa2_5_xor1), .fa_or0(h_u_arrbam8_h3_v5_fa2_5_or0));
  and_gate and_gate_h_u_arrbam8_h3_v5_and3_5(.a(a[3]), .b(b[5]), .out(h_u_arrbam8_h3_v5_and3_5));
  fa fa_h_u_arrbam8_h3_v5_fa3_5_out(.a(h_u_arrbam8_h3_v5_and3_5[0]), .b(h_u_arrbam8_h3_v5_fa4_4_xor1[0]), .cin(h_u_arrbam8_h3_v5_fa2_5_or0[0]), .fa_xor1(h_u_arrbam8_h3_v5_fa3_5_xor1), .fa_or0(h_u_arrbam8_h3_v5_fa3_5_or0));
  and_gate and_gate_h_u_arrbam8_h3_v5_and4_5(.a(a[4]), .b(b[5]), .out(h_u_arrbam8_h3_v5_and4_5));
  fa fa_h_u_arrbam8_h3_v5_fa4_5_out(.a(h_u_arrbam8_h3_v5_and4_5[0]), .b(h_u_arrbam8_h3_v5_fa5_4_xor1[0]), .cin(h_u_arrbam8_h3_v5_fa3_5_or0[0]), .fa_xor1(h_u_arrbam8_h3_v5_fa4_5_xor1), .fa_or0(h_u_arrbam8_h3_v5_fa4_5_or0));
  and_gate and_gate_h_u_arrbam8_h3_v5_and5_5(.a(a[5]), .b(b[5]), .out(h_u_arrbam8_h3_v5_and5_5));
  fa fa_h_u_arrbam8_h3_v5_fa5_5_out(.a(h_u_arrbam8_h3_v5_and5_5[0]), .b(h_u_arrbam8_h3_v5_fa6_4_xor1[0]), .cin(h_u_arrbam8_h3_v5_fa4_5_or0[0]), .fa_xor1(h_u_arrbam8_h3_v5_fa5_5_xor1), .fa_or0(h_u_arrbam8_h3_v5_fa5_5_or0));
  and_gate and_gate_h_u_arrbam8_h3_v5_and6_5(.a(a[6]), .b(b[5]), .out(h_u_arrbam8_h3_v5_and6_5));
  fa fa_h_u_arrbam8_h3_v5_fa6_5_out(.a(h_u_arrbam8_h3_v5_and6_5[0]), .b(h_u_arrbam8_h3_v5_ha7_4_xor0[0]), .cin(h_u_arrbam8_h3_v5_fa5_5_or0[0]), .fa_xor1(h_u_arrbam8_h3_v5_fa6_5_xor1), .fa_or0(h_u_arrbam8_h3_v5_fa6_5_or0));
  and_gate and_gate_h_u_arrbam8_h3_v5_and7_5(.a(a[7]), .b(b[5]), .out(h_u_arrbam8_h3_v5_and7_5));
  fa fa_h_u_arrbam8_h3_v5_fa7_5_out(.a(h_u_arrbam8_h3_v5_and7_5[0]), .b(h_u_arrbam8_h3_v5_ha7_4_and0[0]), .cin(h_u_arrbam8_h3_v5_fa6_5_or0[0]), .fa_xor1(h_u_arrbam8_h3_v5_fa7_5_xor1), .fa_or0(h_u_arrbam8_h3_v5_fa7_5_or0));
  and_gate and_gate_h_u_arrbam8_h3_v5_and0_6(.a(a[0]), .b(b[6]), .out(h_u_arrbam8_h3_v5_and0_6));
  ha ha_h_u_arrbam8_h3_v5_ha0_6_out(.a(h_u_arrbam8_h3_v5_and0_6[0]), .b(h_u_arrbam8_h3_v5_fa1_5_xor1[0]), .ha_xor0(h_u_arrbam8_h3_v5_ha0_6_xor0), .ha_and0(h_u_arrbam8_h3_v5_ha0_6_and0));
  and_gate and_gate_h_u_arrbam8_h3_v5_and1_6(.a(a[1]), .b(b[6]), .out(h_u_arrbam8_h3_v5_and1_6));
  fa fa_h_u_arrbam8_h3_v5_fa1_6_out(.a(h_u_arrbam8_h3_v5_and1_6[0]), .b(h_u_arrbam8_h3_v5_fa2_5_xor1[0]), .cin(h_u_arrbam8_h3_v5_ha0_6_and0[0]), .fa_xor1(h_u_arrbam8_h3_v5_fa1_6_xor1), .fa_or0(h_u_arrbam8_h3_v5_fa1_6_or0));
  and_gate and_gate_h_u_arrbam8_h3_v5_and2_6(.a(a[2]), .b(b[6]), .out(h_u_arrbam8_h3_v5_and2_6));
  fa fa_h_u_arrbam8_h3_v5_fa2_6_out(.a(h_u_arrbam8_h3_v5_and2_6[0]), .b(h_u_arrbam8_h3_v5_fa3_5_xor1[0]), .cin(h_u_arrbam8_h3_v5_fa1_6_or0[0]), .fa_xor1(h_u_arrbam8_h3_v5_fa2_6_xor1), .fa_or0(h_u_arrbam8_h3_v5_fa2_6_or0));
  and_gate and_gate_h_u_arrbam8_h3_v5_and3_6(.a(a[3]), .b(b[6]), .out(h_u_arrbam8_h3_v5_and3_6));
  fa fa_h_u_arrbam8_h3_v5_fa3_6_out(.a(h_u_arrbam8_h3_v5_and3_6[0]), .b(h_u_arrbam8_h3_v5_fa4_5_xor1[0]), .cin(h_u_arrbam8_h3_v5_fa2_6_or0[0]), .fa_xor1(h_u_arrbam8_h3_v5_fa3_6_xor1), .fa_or0(h_u_arrbam8_h3_v5_fa3_6_or0));
  and_gate and_gate_h_u_arrbam8_h3_v5_and4_6(.a(a[4]), .b(b[6]), .out(h_u_arrbam8_h3_v5_and4_6));
  fa fa_h_u_arrbam8_h3_v5_fa4_6_out(.a(h_u_arrbam8_h3_v5_and4_6[0]), .b(h_u_arrbam8_h3_v5_fa5_5_xor1[0]), .cin(h_u_arrbam8_h3_v5_fa3_6_or0[0]), .fa_xor1(h_u_arrbam8_h3_v5_fa4_6_xor1), .fa_or0(h_u_arrbam8_h3_v5_fa4_6_or0));
  and_gate and_gate_h_u_arrbam8_h3_v5_and5_6(.a(a[5]), .b(b[6]), .out(h_u_arrbam8_h3_v5_and5_6));
  fa fa_h_u_arrbam8_h3_v5_fa5_6_out(.a(h_u_arrbam8_h3_v5_and5_6[0]), .b(h_u_arrbam8_h3_v5_fa6_5_xor1[0]), .cin(h_u_arrbam8_h3_v5_fa4_6_or0[0]), .fa_xor1(h_u_arrbam8_h3_v5_fa5_6_xor1), .fa_or0(h_u_arrbam8_h3_v5_fa5_6_or0));
  and_gate and_gate_h_u_arrbam8_h3_v5_and6_6(.a(a[6]), .b(b[6]), .out(h_u_arrbam8_h3_v5_and6_6));
  fa fa_h_u_arrbam8_h3_v5_fa6_6_out(.a(h_u_arrbam8_h3_v5_and6_6[0]), .b(h_u_arrbam8_h3_v5_fa7_5_xor1[0]), .cin(h_u_arrbam8_h3_v5_fa5_6_or0[0]), .fa_xor1(h_u_arrbam8_h3_v5_fa6_6_xor1), .fa_or0(h_u_arrbam8_h3_v5_fa6_6_or0));
  and_gate and_gate_h_u_arrbam8_h3_v5_and7_6(.a(a[7]), .b(b[6]), .out(h_u_arrbam8_h3_v5_and7_6));
  fa fa_h_u_arrbam8_h3_v5_fa7_6_out(.a(h_u_arrbam8_h3_v5_and7_6[0]), .b(h_u_arrbam8_h3_v5_fa7_5_or0[0]), .cin(h_u_arrbam8_h3_v5_fa6_6_or0[0]), .fa_xor1(h_u_arrbam8_h3_v5_fa7_6_xor1), .fa_or0(h_u_arrbam8_h3_v5_fa7_6_or0));
  and_gate and_gate_h_u_arrbam8_h3_v5_and0_7(.a(a[0]), .b(b[7]), .out(h_u_arrbam8_h3_v5_and0_7));
  ha ha_h_u_arrbam8_h3_v5_ha0_7_out(.a(h_u_arrbam8_h3_v5_and0_7[0]), .b(h_u_arrbam8_h3_v5_fa1_6_xor1[0]), .ha_xor0(h_u_arrbam8_h3_v5_ha0_7_xor0), .ha_and0(h_u_arrbam8_h3_v5_ha0_7_and0));
  and_gate and_gate_h_u_arrbam8_h3_v5_and1_7(.a(a[1]), .b(b[7]), .out(h_u_arrbam8_h3_v5_and1_7));
  fa fa_h_u_arrbam8_h3_v5_fa1_7_out(.a(h_u_arrbam8_h3_v5_and1_7[0]), .b(h_u_arrbam8_h3_v5_fa2_6_xor1[0]), .cin(h_u_arrbam8_h3_v5_ha0_7_and0[0]), .fa_xor1(h_u_arrbam8_h3_v5_fa1_7_xor1), .fa_or0(h_u_arrbam8_h3_v5_fa1_7_or0));
  and_gate and_gate_h_u_arrbam8_h3_v5_and2_7(.a(a[2]), .b(b[7]), .out(h_u_arrbam8_h3_v5_and2_7));
  fa fa_h_u_arrbam8_h3_v5_fa2_7_out(.a(h_u_arrbam8_h3_v5_and2_7[0]), .b(h_u_arrbam8_h3_v5_fa3_6_xor1[0]), .cin(h_u_arrbam8_h3_v5_fa1_7_or0[0]), .fa_xor1(h_u_arrbam8_h3_v5_fa2_7_xor1), .fa_or0(h_u_arrbam8_h3_v5_fa2_7_or0));
  and_gate and_gate_h_u_arrbam8_h3_v5_and3_7(.a(a[3]), .b(b[7]), .out(h_u_arrbam8_h3_v5_and3_7));
  fa fa_h_u_arrbam8_h3_v5_fa3_7_out(.a(h_u_arrbam8_h3_v5_and3_7[0]), .b(h_u_arrbam8_h3_v5_fa4_6_xor1[0]), .cin(h_u_arrbam8_h3_v5_fa2_7_or0[0]), .fa_xor1(h_u_arrbam8_h3_v5_fa3_7_xor1), .fa_or0(h_u_arrbam8_h3_v5_fa3_7_or0));
  and_gate and_gate_h_u_arrbam8_h3_v5_and4_7(.a(a[4]), .b(b[7]), .out(h_u_arrbam8_h3_v5_and4_7));
  fa fa_h_u_arrbam8_h3_v5_fa4_7_out(.a(h_u_arrbam8_h3_v5_and4_7[0]), .b(h_u_arrbam8_h3_v5_fa5_6_xor1[0]), .cin(h_u_arrbam8_h3_v5_fa3_7_or0[0]), .fa_xor1(h_u_arrbam8_h3_v5_fa4_7_xor1), .fa_or0(h_u_arrbam8_h3_v5_fa4_7_or0));
  and_gate and_gate_h_u_arrbam8_h3_v5_and5_7(.a(a[5]), .b(b[7]), .out(h_u_arrbam8_h3_v5_and5_7));
  fa fa_h_u_arrbam8_h3_v5_fa5_7_out(.a(h_u_arrbam8_h3_v5_and5_7[0]), .b(h_u_arrbam8_h3_v5_fa6_6_xor1[0]), .cin(h_u_arrbam8_h3_v5_fa4_7_or0[0]), .fa_xor1(h_u_arrbam8_h3_v5_fa5_7_xor1), .fa_or0(h_u_arrbam8_h3_v5_fa5_7_or0));
  and_gate and_gate_h_u_arrbam8_h3_v5_and6_7(.a(a[6]), .b(b[7]), .out(h_u_arrbam8_h3_v5_and6_7));
  fa fa_h_u_arrbam8_h3_v5_fa6_7_out(.a(h_u_arrbam8_h3_v5_and6_7[0]), .b(h_u_arrbam8_h3_v5_fa7_6_xor1[0]), .cin(h_u_arrbam8_h3_v5_fa5_7_or0[0]), .fa_xor1(h_u_arrbam8_h3_v5_fa6_7_xor1), .fa_or0(h_u_arrbam8_h3_v5_fa6_7_or0));
  and_gate and_gate_h_u_arrbam8_h3_v5_and7_7(.a(a[7]), .b(b[7]), .out(h_u_arrbam8_h3_v5_and7_7));
  fa fa_h_u_arrbam8_h3_v5_fa7_7_out(.a(h_u_arrbam8_h3_v5_and7_7[0]), .b(h_u_arrbam8_h3_v5_fa7_6_or0[0]), .cin(h_u_arrbam8_h3_v5_fa6_7_or0[0]), .fa_xor1(h_u_arrbam8_h3_v5_fa7_7_xor1), .fa_or0(h_u_arrbam8_h3_v5_fa7_7_or0));

  assign h_u_arrbam8_h3_v5_out[0] = 1'b0;
  assign h_u_arrbam8_h3_v5_out[1] = 1'b0;
  assign h_u_arrbam8_h3_v5_out[2] = 1'b0;
  assign h_u_arrbam8_h3_v5_out[3] = 1'b0;
  assign h_u_arrbam8_h3_v5_out[4] = 1'b0;
  assign h_u_arrbam8_h3_v5_out[5] = h_u_arrbam8_h3_v5_ha0_5_xor0[0];
  assign h_u_arrbam8_h3_v5_out[6] = h_u_arrbam8_h3_v5_ha0_6_xor0[0];
  assign h_u_arrbam8_h3_v5_out[7] = h_u_arrbam8_h3_v5_ha0_7_xor0[0];
  assign h_u_arrbam8_h3_v5_out[8] = h_u_arrbam8_h3_v5_fa1_7_xor1[0];
  assign h_u_arrbam8_h3_v5_out[9] = h_u_arrbam8_h3_v5_fa2_7_xor1[0];
  assign h_u_arrbam8_h3_v5_out[10] = h_u_arrbam8_h3_v5_fa3_7_xor1[0];
  assign h_u_arrbam8_h3_v5_out[11] = h_u_arrbam8_h3_v5_fa4_7_xor1[0];
  assign h_u_arrbam8_h3_v5_out[12] = h_u_arrbam8_h3_v5_fa5_7_xor1[0];
  assign h_u_arrbam8_h3_v5_out[13] = h_u_arrbam8_h3_v5_fa6_7_xor1[0];
  assign h_u_arrbam8_h3_v5_out[14] = h_u_arrbam8_h3_v5_fa7_7_xor1[0];
  assign h_u_arrbam8_h3_v5_out[15] = h_u_arrbam8_h3_v5_fa7_7_or0[0];
endmodule