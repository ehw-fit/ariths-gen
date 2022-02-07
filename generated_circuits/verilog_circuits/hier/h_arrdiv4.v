module xor_gate(input a, input b, output out);
  assign out = a ^ b;
endmodule

module not_gate(input a, output out);
  assign out = ~a;
endmodule

module and_gate(input a, input b, output out);
  assign out = a & b;
endmodule

module or_gate(input a, input b, output out);
  assign out = a | b;
endmodule

module fs(input [0:0] a, input [0:0] b, input [0:0] bin, output [0:0] fs_xor1, output [0:0] fs_or0);
  wire [0:0] fs_xor0;
  wire [0:0] fs_not0;
  wire [0:0] fs_and0;
  wire [0:0] fs_not1;
  wire [0:0] fs_and1;
  xor_gate xor_gate_fs_xor0(.a(a[0]), .b(b[0]), .out(fs_xor0));
  not_gate not_gate_fs_not0(.a(a[0]), .out(fs_not0));
  and_gate and_gate_fs_and0(.a(fs_not0[0]), .b(b[0]), .out(fs_and0));
  xor_gate xor_gate_fs_xor1(.a(bin[0]), .b(fs_xor0[0]), .out(fs_xor1));
  not_gate not_gate_fs_not1(.a(fs_xor0[0]), .out(fs_not1));
  and_gate and_gate_fs_and1(.a(fs_not1[0]), .b(bin[0]), .out(fs_and1));
  or_gate or_gate_fs_or0(.a(fs_and1[0]), .b(fs_and0[0]), .out(fs_or0));
endmodule

module mux2to1(input [0:0] d0, input [0:0] d1, input [0:0] sel, output [0:0] mux2to1_xor0);
  wire [0:0] mux2to1_and0;
  wire [0:0] mux2to1_not0;
  wire [0:0] mux2to1_and1;
  and_gate and_gate_mux2to1_and0(.a(d1[0]), .b(sel[0]), .out(mux2to1_and0));
  not_gate not_gate_mux2to1_not0(.a(sel[0]), .out(mux2to1_not0));
  and_gate and_gate_mux2to1_and1(.a(d0[0]), .b(mux2to1_not0[0]), .out(mux2to1_and1));
  xor_gate xor_gate_mux2to1_xor0(.a(mux2to1_and0[0]), .b(mux2to1_and1[0]), .out(mux2to1_xor0));
endmodule

module h_arrdiv4(input [3:0] a, input [3:0] b, output [3:0] h_arrdiv4_out);
  wire [0:0] h_arrdiv4_fs0_xor0;
  wire [0:0] h_arrdiv4_fs0_and0;
  wire [0:0] h_arrdiv4_fs1_xor1;
  wire [0:0] h_arrdiv4_fs1_or0;
  wire [0:0] h_arrdiv4_fs2_xor1;
  wire [0:0] h_arrdiv4_fs2_or0;
  wire [0:0] h_arrdiv4_fs3_xor1;
  wire [0:0] h_arrdiv4_fs3_or0;
  wire [0:0] h_arrdiv4_mux2to10_xor0;
  wire [0:0] h_arrdiv4_mux2to11_and1;
  wire [0:0] h_arrdiv4_mux2to12_and1;
  wire [0:0] h_arrdiv4_not0;
  wire [0:0] h_arrdiv4_fs4_xor0;
  wire [0:0] h_arrdiv4_fs4_and0;
  wire [0:0] h_arrdiv4_fs5_xor1;
  wire [0:0] h_arrdiv4_fs5_or0;
  wire [0:0] h_arrdiv4_fs6_xor1;
  wire [0:0] h_arrdiv4_fs6_or0;
  wire [0:0] h_arrdiv4_fs7_xor1;
  wire [0:0] h_arrdiv4_fs7_or0;
  wire [0:0] h_arrdiv4_mux2to13_xor0;
  wire [0:0] h_arrdiv4_mux2to14_xor0;
  wire [0:0] h_arrdiv4_mux2to15_xor0;
  wire [0:0] h_arrdiv4_not1;
  wire [0:0] h_arrdiv4_fs8_xor0;
  wire [0:0] h_arrdiv4_fs8_and0;
  wire [0:0] h_arrdiv4_fs9_xor1;
  wire [0:0] h_arrdiv4_fs9_or0;
  wire [0:0] h_arrdiv4_fs10_xor1;
  wire [0:0] h_arrdiv4_fs10_or0;
  wire [0:0] h_arrdiv4_fs11_xor1;
  wire [0:0] h_arrdiv4_fs11_or0;
  wire [0:0] h_arrdiv4_mux2to16_xor0;
  wire [0:0] h_arrdiv4_mux2to17_xor0;
  wire [0:0] h_arrdiv4_mux2to18_xor0;
  wire [0:0] h_arrdiv4_not2;
  wire [0:0] h_arrdiv4_fs12_xor0;
  wire [0:0] h_arrdiv4_fs12_and0;
  wire [0:0] h_arrdiv4_fs13_xor1;
  wire [0:0] h_arrdiv4_fs13_or0;
  wire [0:0] h_arrdiv4_fs14_xor1;
  wire [0:0] h_arrdiv4_fs14_or0;
  wire [0:0] h_arrdiv4_fs15_xor1;
  wire [0:0] h_arrdiv4_fs15_or0;
  wire [0:0] h_arrdiv4_not3;

  fs fs_h_arrdiv4_fs0_out(.a(a[3]), .b(b[0]), .bin(1'b0), .fs_xor1(h_arrdiv4_fs0_xor0), .fs_or0(h_arrdiv4_fs0_and0));
  fs fs_h_arrdiv4_fs1_out(.a(1'b0), .b(b[1]), .bin(h_arrdiv4_fs0_and0[0]), .fs_xor1(h_arrdiv4_fs1_xor1), .fs_or0(h_arrdiv4_fs1_or0));
  fs fs_h_arrdiv4_fs2_out(.a(1'b0), .b(b[2]), .bin(h_arrdiv4_fs1_or0[0]), .fs_xor1(h_arrdiv4_fs2_xor1), .fs_or0(h_arrdiv4_fs2_or0));
  fs fs_h_arrdiv4_fs3_out(.a(1'b0), .b(b[3]), .bin(h_arrdiv4_fs2_or0[0]), .fs_xor1(h_arrdiv4_fs3_xor1), .fs_or0(h_arrdiv4_fs3_or0));
  mux2to1 mux2to1_h_arrdiv4_mux2to10_out(.d0(h_arrdiv4_fs0_xor0[0]), .d1(a[3]), .sel(h_arrdiv4_fs3_or0[0]), .mux2to1_xor0(h_arrdiv4_mux2to10_xor0));
  mux2to1 mux2to1_h_arrdiv4_mux2to11_out(.d0(h_arrdiv4_fs1_xor1[0]), .d1(1'b0), .sel(h_arrdiv4_fs3_or0[0]), .mux2to1_xor0(h_arrdiv4_mux2to11_and1));
  mux2to1 mux2to1_h_arrdiv4_mux2to12_out(.d0(h_arrdiv4_fs2_xor1[0]), .d1(1'b0), .sel(h_arrdiv4_fs3_or0[0]), .mux2to1_xor0(h_arrdiv4_mux2to12_and1));
  not_gate not_gate_h_arrdiv4_not0(.a(h_arrdiv4_fs3_or0[0]), .out(h_arrdiv4_not0));
  fs fs_h_arrdiv4_fs4_out(.a(a[2]), .b(b[0]), .bin(1'b0), .fs_xor1(h_arrdiv4_fs4_xor0), .fs_or0(h_arrdiv4_fs4_and0));
  fs fs_h_arrdiv4_fs5_out(.a(h_arrdiv4_mux2to10_xor0[0]), .b(b[1]), .bin(h_arrdiv4_fs4_and0[0]), .fs_xor1(h_arrdiv4_fs5_xor1), .fs_or0(h_arrdiv4_fs5_or0));
  fs fs_h_arrdiv4_fs6_out(.a(h_arrdiv4_mux2to11_and1[0]), .b(b[2]), .bin(h_arrdiv4_fs5_or0[0]), .fs_xor1(h_arrdiv4_fs6_xor1), .fs_or0(h_arrdiv4_fs6_or0));
  fs fs_h_arrdiv4_fs7_out(.a(h_arrdiv4_mux2to12_and1[0]), .b(b[3]), .bin(h_arrdiv4_fs6_or0[0]), .fs_xor1(h_arrdiv4_fs7_xor1), .fs_or0(h_arrdiv4_fs7_or0));
  mux2to1 mux2to1_h_arrdiv4_mux2to13_out(.d0(h_arrdiv4_fs4_xor0[0]), .d1(a[2]), .sel(h_arrdiv4_fs7_or0[0]), .mux2to1_xor0(h_arrdiv4_mux2to13_xor0));
  mux2to1 mux2to1_h_arrdiv4_mux2to14_out(.d0(h_arrdiv4_fs5_xor1[0]), .d1(h_arrdiv4_mux2to10_xor0[0]), .sel(h_arrdiv4_fs7_or0[0]), .mux2to1_xor0(h_arrdiv4_mux2to14_xor0));
  mux2to1 mux2to1_h_arrdiv4_mux2to15_out(.d0(h_arrdiv4_fs6_xor1[0]), .d1(h_arrdiv4_mux2to11_and1[0]), .sel(h_arrdiv4_fs7_or0[0]), .mux2to1_xor0(h_arrdiv4_mux2to15_xor0));
  not_gate not_gate_h_arrdiv4_not1(.a(h_arrdiv4_fs7_or0[0]), .out(h_arrdiv4_not1));
  fs fs_h_arrdiv4_fs8_out(.a(a[1]), .b(b[0]), .bin(1'b0), .fs_xor1(h_arrdiv4_fs8_xor0), .fs_or0(h_arrdiv4_fs8_and0));
  fs fs_h_arrdiv4_fs9_out(.a(h_arrdiv4_mux2to13_xor0[0]), .b(b[1]), .bin(h_arrdiv4_fs8_and0[0]), .fs_xor1(h_arrdiv4_fs9_xor1), .fs_or0(h_arrdiv4_fs9_or0));
  fs fs_h_arrdiv4_fs10_out(.a(h_arrdiv4_mux2to14_xor0[0]), .b(b[2]), .bin(h_arrdiv4_fs9_or0[0]), .fs_xor1(h_arrdiv4_fs10_xor1), .fs_or0(h_arrdiv4_fs10_or0));
  fs fs_h_arrdiv4_fs11_out(.a(h_arrdiv4_mux2to15_xor0[0]), .b(b[3]), .bin(h_arrdiv4_fs10_or0[0]), .fs_xor1(h_arrdiv4_fs11_xor1), .fs_or0(h_arrdiv4_fs11_or0));
  mux2to1 mux2to1_h_arrdiv4_mux2to16_out(.d0(h_arrdiv4_fs8_xor0[0]), .d1(a[1]), .sel(h_arrdiv4_fs11_or0[0]), .mux2to1_xor0(h_arrdiv4_mux2to16_xor0));
  mux2to1 mux2to1_h_arrdiv4_mux2to17_out(.d0(h_arrdiv4_fs9_xor1[0]), .d1(h_arrdiv4_mux2to13_xor0[0]), .sel(h_arrdiv4_fs11_or0[0]), .mux2to1_xor0(h_arrdiv4_mux2to17_xor0));
  mux2to1 mux2to1_h_arrdiv4_mux2to18_out(.d0(h_arrdiv4_fs10_xor1[0]), .d1(h_arrdiv4_mux2to14_xor0[0]), .sel(h_arrdiv4_fs11_or0[0]), .mux2to1_xor0(h_arrdiv4_mux2to18_xor0));
  not_gate not_gate_h_arrdiv4_not2(.a(h_arrdiv4_fs11_or0[0]), .out(h_arrdiv4_not2));
  fs fs_h_arrdiv4_fs12_out(.a(a[0]), .b(b[0]), .bin(1'b0), .fs_xor1(h_arrdiv4_fs12_xor0), .fs_or0(h_arrdiv4_fs12_and0));
  fs fs_h_arrdiv4_fs13_out(.a(h_arrdiv4_mux2to16_xor0[0]), .b(b[1]), .bin(h_arrdiv4_fs12_and0[0]), .fs_xor1(h_arrdiv4_fs13_xor1), .fs_or0(h_arrdiv4_fs13_or0));
  fs fs_h_arrdiv4_fs14_out(.a(h_arrdiv4_mux2to17_xor0[0]), .b(b[2]), .bin(h_arrdiv4_fs13_or0[0]), .fs_xor1(h_arrdiv4_fs14_xor1), .fs_or0(h_arrdiv4_fs14_or0));
  fs fs_h_arrdiv4_fs15_out(.a(h_arrdiv4_mux2to18_xor0[0]), .b(b[3]), .bin(h_arrdiv4_fs14_or0[0]), .fs_xor1(h_arrdiv4_fs15_xor1), .fs_or0(h_arrdiv4_fs15_or0));
  not_gate not_gate_h_arrdiv4_not3(.a(h_arrdiv4_fs15_or0[0]), .out(h_arrdiv4_not3));

  assign h_arrdiv4_out[0] = h_arrdiv4_not3[0];
  assign h_arrdiv4_out[1] = h_arrdiv4_not2[0];
  assign h_arrdiv4_out[2] = h_arrdiv4_not1[0];
  assign h_arrdiv4_out[3] = h_arrdiv4_not0[0];
endmodule