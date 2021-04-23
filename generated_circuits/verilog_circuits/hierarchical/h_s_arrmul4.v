module and_gate(input a, input b, output out);
  assign out = a & b;
endmodule

module nand_gate(input a, input b, output out);
  assign out = ~(a & b);
endmodule

module xor_gate(input a, input b, output out);
  assign out = a ^ b;
endmodule

module or_gate(input a, input b, output out);
  assign out = a | b;
endmodule

module not_gate(input a, output out);
  assign out = ~a;
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

module h_s_arrmul4(input [3:0] a, input [3:0] b, output [7:0] h_s_arrmul4_out);
  wire [0:0] h_s_arrmul4_and0_0;
  wire [0:0] h_s_arrmul4_and1_0;
  wire [0:0] h_s_arrmul4_and2_0;
  wire [0:0] h_s_arrmul4_nand3_0;
  wire [0:0] h_s_arrmul4_and0_1;
  wire [0:0] h_s_arrmul4_ha0_1_xor0;
  wire [0:0] h_s_arrmul4_ha0_1_and0;
  wire [0:0] h_s_arrmul4_and1_1;
  wire [0:0] h_s_arrmul4_fa1_1_xor1;
  wire [0:0] h_s_arrmul4_fa1_1_or0;
  wire [0:0] h_s_arrmul4_and2_1;
  wire [0:0] h_s_arrmul4_fa2_1_xor1;
  wire [0:0] h_s_arrmul4_fa2_1_or0;
  wire [0:0] h_s_arrmul4_nand3_1;
  wire [0:0] h_s_arrmul4_fa3_1_xor1;
  wire [0:0] h_s_arrmul4_fa3_1_or0;
  wire [0:0] h_s_arrmul4_and0_2;
  wire [0:0] h_s_arrmul4_ha0_2_xor0;
  wire [0:0] h_s_arrmul4_ha0_2_and0;
  wire [0:0] h_s_arrmul4_and1_2;
  wire [0:0] h_s_arrmul4_fa1_2_xor1;
  wire [0:0] h_s_arrmul4_fa1_2_or0;
  wire [0:0] h_s_arrmul4_and2_2;
  wire [0:0] h_s_arrmul4_fa2_2_xor1;
  wire [0:0] h_s_arrmul4_fa2_2_or0;
  wire [0:0] h_s_arrmul4_nand3_2;
  wire [0:0] h_s_arrmul4_fa3_2_xor1;
  wire [0:0] h_s_arrmul4_fa3_2_or0;
  wire [0:0] h_s_arrmul4_nand0_3;
  wire [0:0] h_s_arrmul4_ha0_3_xor0;
  wire [0:0] h_s_arrmul4_ha0_3_and0;
  wire [0:0] h_s_arrmul4_nand1_3;
  wire [0:0] h_s_arrmul4_fa1_3_xor1;
  wire [0:0] h_s_arrmul4_fa1_3_or0;
  wire [0:0] h_s_arrmul4_nand2_3;
  wire [0:0] h_s_arrmul4_fa2_3_xor1;
  wire [0:0] h_s_arrmul4_fa2_3_or0;
  wire [0:0] h_s_arrmul4_and3_3;
  wire [0:0] h_s_arrmul4_fa3_3_xor1;
  wire [0:0] h_s_arrmul4_fa3_3_or0;
  wire [0:0] h_s_arrmul4_xor4_3;

  and_gate and_gate_h_s_arrmul4_and0_0(.a(a[0]), .b(b[0]), .out(h_s_arrmul4_and0_0));
  and_gate and_gate_h_s_arrmul4_and1_0(.a(a[1]), .b(b[0]), .out(h_s_arrmul4_and1_0));
  and_gate and_gate_h_s_arrmul4_and2_0(.a(a[2]), .b(b[0]), .out(h_s_arrmul4_and2_0));
  nand_gate nand_gate_h_s_arrmul4_nand3_0(.a(a[3]), .b(b[0]), .out(h_s_arrmul4_nand3_0));
  and_gate and_gate_h_s_arrmul4_and0_1(.a(a[0]), .b(b[1]), .out(h_s_arrmul4_and0_1));
  ha ha_h_s_arrmul4_ha0_1_out(.a(h_s_arrmul4_and0_1[0]), .b(h_s_arrmul4_and1_0[0]), .ha_xor0(h_s_arrmul4_ha0_1_xor0), .ha_and0(h_s_arrmul4_ha0_1_and0));
  and_gate and_gate_h_s_arrmul4_and1_1(.a(a[1]), .b(b[1]), .out(h_s_arrmul4_and1_1));
  fa fa_h_s_arrmul4_fa1_1_out(.a(h_s_arrmul4_and1_1[0]), .b(h_s_arrmul4_and2_0[0]), .cin(h_s_arrmul4_ha0_1_and0[0]), .fa_xor1(h_s_arrmul4_fa1_1_xor1), .fa_or0(h_s_arrmul4_fa1_1_or0));
  and_gate and_gate_h_s_arrmul4_and2_1(.a(a[2]), .b(b[1]), .out(h_s_arrmul4_and2_1));
  fa fa_h_s_arrmul4_fa2_1_out(.a(h_s_arrmul4_and2_1[0]), .b(h_s_arrmul4_nand3_0[0]), .cin(h_s_arrmul4_fa1_1_or0[0]), .fa_xor1(h_s_arrmul4_fa2_1_xor1), .fa_or0(h_s_arrmul4_fa2_1_or0));
  nand_gate nand_gate_h_s_arrmul4_nand3_1(.a(a[3]), .b(b[1]), .out(h_s_arrmul4_nand3_1));
  fa fa_h_s_arrmul4_fa3_1_out(.a(h_s_arrmul4_nand3_1[0]), .b(1'b1), .cin(h_s_arrmul4_fa2_1_or0[0]), .fa_xor1(h_s_arrmul4_fa3_1_xor1), .fa_or0(h_s_arrmul4_fa3_1_or0));
  and_gate and_gate_h_s_arrmul4_and0_2(.a(a[0]), .b(b[2]), .out(h_s_arrmul4_and0_2));
  ha ha_h_s_arrmul4_ha0_2_out(.a(h_s_arrmul4_and0_2[0]), .b(h_s_arrmul4_fa1_1_xor1[0]), .ha_xor0(h_s_arrmul4_ha0_2_xor0), .ha_and0(h_s_arrmul4_ha0_2_and0));
  and_gate and_gate_h_s_arrmul4_and1_2(.a(a[1]), .b(b[2]), .out(h_s_arrmul4_and1_2));
  fa fa_h_s_arrmul4_fa1_2_out(.a(h_s_arrmul4_and1_2[0]), .b(h_s_arrmul4_fa2_1_xor1[0]), .cin(h_s_arrmul4_ha0_2_and0[0]), .fa_xor1(h_s_arrmul4_fa1_2_xor1), .fa_or0(h_s_arrmul4_fa1_2_or0));
  and_gate and_gate_h_s_arrmul4_and2_2(.a(a[2]), .b(b[2]), .out(h_s_arrmul4_and2_2));
  fa fa_h_s_arrmul4_fa2_2_out(.a(h_s_arrmul4_and2_2[0]), .b(h_s_arrmul4_fa3_1_xor1[0]), .cin(h_s_arrmul4_fa1_2_or0[0]), .fa_xor1(h_s_arrmul4_fa2_2_xor1), .fa_or0(h_s_arrmul4_fa2_2_or0));
  nand_gate nand_gate_h_s_arrmul4_nand3_2(.a(a[3]), .b(b[2]), .out(h_s_arrmul4_nand3_2));
  fa fa_h_s_arrmul4_fa3_2_out(.a(h_s_arrmul4_nand3_2[0]), .b(h_s_arrmul4_fa3_1_or0[0]), .cin(h_s_arrmul4_fa2_2_or0[0]), .fa_xor1(h_s_arrmul4_fa3_2_xor1), .fa_or0(h_s_arrmul4_fa3_2_or0));
  nand_gate nand_gate_h_s_arrmul4_nand0_3(.a(a[0]), .b(b[3]), .out(h_s_arrmul4_nand0_3));
  ha ha_h_s_arrmul4_ha0_3_out(.a(h_s_arrmul4_nand0_3[0]), .b(h_s_arrmul4_fa1_2_xor1[0]), .ha_xor0(h_s_arrmul4_ha0_3_xor0), .ha_and0(h_s_arrmul4_ha0_3_and0));
  nand_gate nand_gate_h_s_arrmul4_nand1_3(.a(a[1]), .b(b[3]), .out(h_s_arrmul4_nand1_3));
  fa fa_h_s_arrmul4_fa1_3_out(.a(h_s_arrmul4_nand1_3[0]), .b(h_s_arrmul4_fa2_2_xor1[0]), .cin(h_s_arrmul4_ha0_3_and0[0]), .fa_xor1(h_s_arrmul4_fa1_3_xor1), .fa_or0(h_s_arrmul4_fa1_3_or0));
  nand_gate nand_gate_h_s_arrmul4_nand2_3(.a(a[2]), .b(b[3]), .out(h_s_arrmul4_nand2_3));
  fa fa_h_s_arrmul4_fa2_3_out(.a(h_s_arrmul4_nand2_3[0]), .b(h_s_arrmul4_fa3_2_xor1[0]), .cin(h_s_arrmul4_fa1_3_or0[0]), .fa_xor1(h_s_arrmul4_fa2_3_xor1), .fa_or0(h_s_arrmul4_fa2_3_or0));
  and_gate and_gate_h_s_arrmul4_and3_3(.a(a[3]), .b(b[3]), .out(h_s_arrmul4_and3_3));
  fa fa_h_s_arrmul4_fa3_3_out(.a(h_s_arrmul4_and3_3[0]), .b(h_s_arrmul4_fa3_2_or0[0]), .cin(h_s_arrmul4_fa2_3_or0[0]), .fa_xor1(h_s_arrmul4_fa3_3_xor1), .fa_or0(h_s_arrmul4_fa3_3_or0));
  not_gate not_gate_h_s_arrmul4_xor4_3(.a(h_s_arrmul4_fa3_3_or0[0]), .out(h_s_arrmul4_xor4_3));

  assign h_s_arrmul4_out[0] = h_s_arrmul4_and0_0[0];
  assign h_s_arrmul4_out[1] = h_s_arrmul4_ha0_1_xor0[0];
  assign h_s_arrmul4_out[2] = h_s_arrmul4_ha0_2_xor0[0];
  assign h_s_arrmul4_out[3] = h_s_arrmul4_ha0_3_xor0[0];
  assign h_s_arrmul4_out[4] = h_s_arrmul4_fa1_3_xor1[0];
  assign h_s_arrmul4_out[5] = h_s_arrmul4_fa2_3_xor1[0];
  assign h_s_arrmul4_out[6] = h_s_arrmul4_fa3_3_xor1[0];
  assign h_s_arrmul4_out[7] = h_s_arrmul4_xor4_3[0];
endmodule