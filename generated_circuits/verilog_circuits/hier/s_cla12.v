module or_gate(input a, input b, output out);
  assign out = a | b;
endmodule

module and_gate(input a, input b, output out);
  assign out = a & b;
endmodule

module xor_gate(input a, input b, output out);
  assign out = a ^ b;
endmodule

module pg_logic(input [0:0] a, input [0:0] b, output [0:0] pg_logic_or0, output [0:0] pg_logic_and0, output [0:0] pg_logic_xor0);
  or_gate or_gate_pg_logic_or0(.a(a[0]), .b(b[0]), .out(pg_logic_or0));
  and_gate and_gate_pg_logic_and0(.a(a[0]), .b(b[0]), .out(pg_logic_and0));
  xor_gate xor_gate_pg_logic_xor0(.a(a[0]), .b(b[0]), .out(pg_logic_xor0));
endmodule

module s_cla12(input [11:0] a, input [11:0] b, output [12:0] s_cla12_out);
  wire [0:0] s_cla12_pg_logic0_or0;
  wire [0:0] s_cla12_pg_logic0_and0;
  wire [0:0] s_cla12_pg_logic0_xor0;
  wire [0:0] s_cla12_pg_logic1_or0;
  wire [0:0] s_cla12_pg_logic1_and0;
  wire [0:0] s_cla12_pg_logic1_xor0;
  wire [0:0] s_cla12_xor1;
  wire [0:0] s_cla12_and0;
  wire [0:0] s_cla12_or0;
  wire [0:0] s_cla12_pg_logic2_or0;
  wire [0:0] s_cla12_pg_logic2_and0;
  wire [0:0] s_cla12_pg_logic2_xor0;
  wire [0:0] s_cla12_xor2;
  wire [0:0] s_cla12_and1;
  wire [0:0] s_cla12_and2;
  wire [0:0] s_cla12_and3;
  wire [0:0] s_cla12_and4;
  wire [0:0] s_cla12_or1;
  wire [0:0] s_cla12_or2;
  wire [0:0] s_cla12_pg_logic3_or0;
  wire [0:0] s_cla12_pg_logic3_and0;
  wire [0:0] s_cla12_pg_logic3_xor0;
  wire [0:0] s_cla12_xor3;
  wire [0:0] s_cla12_and5;
  wire [0:0] s_cla12_and6;
  wire [0:0] s_cla12_and7;
  wire [0:0] s_cla12_and8;
  wire [0:0] s_cla12_and9;
  wire [0:0] s_cla12_and10;
  wire [0:0] s_cla12_and11;
  wire [0:0] s_cla12_or3;
  wire [0:0] s_cla12_or4;
  wire [0:0] s_cla12_or5;
  wire [0:0] s_cla12_pg_logic4_or0;
  wire [0:0] s_cla12_pg_logic4_and0;
  wire [0:0] s_cla12_pg_logic4_xor0;
  wire [0:0] s_cla12_xor4;
  wire [0:0] s_cla12_and12;
  wire [0:0] s_cla12_or6;
  wire [0:0] s_cla12_pg_logic5_or0;
  wire [0:0] s_cla12_pg_logic5_and0;
  wire [0:0] s_cla12_pg_logic5_xor0;
  wire [0:0] s_cla12_xor5;
  wire [0:0] s_cla12_and13;
  wire [0:0] s_cla12_and14;
  wire [0:0] s_cla12_and15;
  wire [0:0] s_cla12_or7;
  wire [0:0] s_cla12_or8;
  wire [0:0] s_cla12_pg_logic6_or0;
  wire [0:0] s_cla12_pg_logic6_and0;
  wire [0:0] s_cla12_pg_logic6_xor0;
  wire [0:0] s_cla12_xor6;
  wire [0:0] s_cla12_and16;
  wire [0:0] s_cla12_and17;
  wire [0:0] s_cla12_and18;
  wire [0:0] s_cla12_and19;
  wire [0:0] s_cla12_and20;
  wire [0:0] s_cla12_and21;
  wire [0:0] s_cla12_or9;
  wire [0:0] s_cla12_or10;
  wire [0:0] s_cla12_or11;
  wire [0:0] s_cla12_pg_logic7_or0;
  wire [0:0] s_cla12_pg_logic7_and0;
  wire [0:0] s_cla12_pg_logic7_xor0;
  wire [0:0] s_cla12_xor7;
  wire [0:0] s_cla12_and22;
  wire [0:0] s_cla12_and23;
  wire [0:0] s_cla12_and24;
  wire [0:0] s_cla12_and25;
  wire [0:0] s_cla12_and26;
  wire [0:0] s_cla12_and27;
  wire [0:0] s_cla12_and28;
  wire [0:0] s_cla12_and29;
  wire [0:0] s_cla12_and30;
  wire [0:0] s_cla12_and31;
  wire [0:0] s_cla12_or12;
  wire [0:0] s_cla12_or13;
  wire [0:0] s_cla12_or14;
  wire [0:0] s_cla12_or15;
  wire [0:0] s_cla12_pg_logic8_or0;
  wire [0:0] s_cla12_pg_logic8_and0;
  wire [0:0] s_cla12_pg_logic8_xor0;
  wire [0:0] s_cla12_xor8;
  wire [0:0] s_cla12_and32;
  wire [0:0] s_cla12_or16;
  wire [0:0] s_cla12_pg_logic9_or0;
  wire [0:0] s_cla12_pg_logic9_and0;
  wire [0:0] s_cla12_pg_logic9_xor0;
  wire [0:0] s_cla12_xor9;
  wire [0:0] s_cla12_and33;
  wire [0:0] s_cla12_and34;
  wire [0:0] s_cla12_and35;
  wire [0:0] s_cla12_or17;
  wire [0:0] s_cla12_or18;
  wire [0:0] s_cla12_pg_logic10_or0;
  wire [0:0] s_cla12_pg_logic10_and0;
  wire [0:0] s_cla12_pg_logic10_xor0;
  wire [0:0] s_cla12_xor10;
  wire [0:0] s_cla12_and36;
  wire [0:0] s_cla12_and37;
  wire [0:0] s_cla12_and38;
  wire [0:0] s_cla12_and39;
  wire [0:0] s_cla12_and40;
  wire [0:0] s_cla12_and41;
  wire [0:0] s_cla12_or19;
  wire [0:0] s_cla12_or20;
  wire [0:0] s_cla12_or21;
  wire [0:0] s_cla12_pg_logic11_or0;
  wire [0:0] s_cla12_pg_logic11_and0;
  wire [0:0] s_cla12_pg_logic11_xor0;
  wire [0:0] s_cla12_xor11;
  wire [0:0] s_cla12_and42;
  wire [0:0] s_cla12_and43;
  wire [0:0] s_cla12_and44;
  wire [0:0] s_cla12_and45;
  wire [0:0] s_cla12_and46;
  wire [0:0] s_cla12_and47;
  wire [0:0] s_cla12_and48;
  wire [0:0] s_cla12_and49;
  wire [0:0] s_cla12_and50;
  wire [0:0] s_cla12_and51;
  wire [0:0] s_cla12_or22;
  wire [0:0] s_cla12_or23;
  wire [0:0] s_cla12_or24;
  wire [0:0] s_cla12_or25;
  wire [0:0] s_cla12_xor12;
  wire [0:0] s_cla12_xor13;

  pg_logic pg_logic_s_cla12_pg_logic0_out(.a(a[0]), .b(b[0]), .pg_logic_or0(s_cla12_pg_logic0_or0), .pg_logic_and0(s_cla12_pg_logic0_and0), .pg_logic_xor0(s_cla12_pg_logic0_xor0));
  pg_logic pg_logic_s_cla12_pg_logic1_out(.a(a[1]), .b(b[1]), .pg_logic_or0(s_cla12_pg_logic1_or0), .pg_logic_and0(s_cla12_pg_logic1_and0), .pg_logic_xor0(s_cla12_pg_logic1_xor0));
  xor_gate xor_gate_s_cla12_xor1(.a(s_cla12_pg_logic1_xor0[0]), .b(s_cla12_pg_logic0_and0[0]), .out(s_cla12_xor1));
  and_gate and_gate_s_cla12_and0(.a(s_cla12_pg_logic0_and0[0]), .b(s_cla12_pg_logic1_or0[0]), .out(s_cla12_and0));
  or_gate or_gate_s_cla12_or0(.a(s_cla12_pg_logic1_and0[0]), .b(s_cla12_and0[0]), .out(s_cla12_or0));
  pg_logic pg_logic_s_cla12_pg_logic2_out(.a(a[2]), .b(b[2]), .pg_logic_or0(s_cla12_pg_logic2_or0), .pg_logic_and0(s_cla12_pg_logic2_and0), .pg_logic_xor0(s_cla12_pg_logic2_xor0));
  xor_gate xor_gate_s_cla12_xor2(.a(s_cla12_pg_logic2_xor0[0]), .b(s_cla12_or0[0]), .out(s_cla12_xor2));
  and_gate and_gate_s_cla12_and1(.a(s_cla12_pg_logic2_or0[0]), .b(s_cla12_pg_logic0_or0[0]), .out(s_cla12_and1));
  and_gate and_gate_s_cla12_and2(.a(s_cla12_pg_logic0_and0[0]), .b(s_cla12_pg_logic2_or0[0]), .out(s_cla12_and2));
  and_gate and_gate_s_cla12_and3(.a(s_cla12_and2[0]), .b(s_cla12_pg_logic1_or0[0]), .out(s_cla12_and3));
  and_gate and_gate_s_cla12_and4(.a(s_cla12_pg_logic1_and0[0]), .b(s_cla12_pg_logic2_or0[0]), .out(s_cla12_and4));
  or_gate or_gate_s_cla12_or1(.a(s_cla12_and3[0]), .b(s_cla12_and4[0]), .out(s_cla12_or1));
  or_gate or_gate_s_cla12_or2(.a(s_cla12_pg_logic2_and0[0]), .b(s_cla12_or1[0]), .out(s_cla12_or2));
  pg_logic pg_logic_s_cla12_pg_logic3_out(.a(a[3]), .b(b[3]), .pg_logic_or0(s_cla12_pg_logic3_or0), .pg_logic_and0(s_cla12_pg_logic3_and0), .pg_logic_xor0(s_cla12_pg_logic3_xor0));
  xor_gate xor_gate_s_cla12_xor3(.a(s_cla12_pg_logic3_xor0[0]), .b(s_cla12_or2[0]), .out(s_cla12_xor3));
  and_gate and_gate_s_cla12_and5(.a(s_cla12_pg_logic3_or0[0]), .b(s_cla12_pg_logic1_or0[0]), .out(s_cla12_and5));
  and_gate and_gate_s_cla12_and6(.a(s_cla12_pg_logic0_and0[0]), .b(s_cla12_pg_logic2_or0[0]), .out(s_cla12_and6));
  and_gate and_gate_s_cla12_and7(.a(s_cla12_pg_logic3_or0[0]), .b(s_cla12_pg_logic1_or0[0]), .out(s_cla12_and7));
  and_gate and_gate_s_cla12_and8(.a(s_cla12_and6[0]), .b(s_cla12_and7[0]), .out(s_cla12_and8));
  and_gate and_gate_s_cla12_and9(.a(s_cla12_pg_logic1_and0[0]), .b(s_cla12_pg_logic3_or0[0]), .out(s_cla12_and9));
  and_gate and_gate_s_cla12_and10(.a(s_cla12_and9[0]), .b(s_cla12_pg_logic2_or0[0]), .out(s_cla12_and10));
  and_gate and_gate_s_cla12_and11(.a(s_cla12_pg_logic2_and0[0]), .b(s_cla12_pg_logic3_or0[0]), .out(s_cla12_and11));
  or_gate or_gate_s_cla12_or3(.a(s_cla12_and8[0]), .b(s_cla12_and11[0]), .out(s_cla12_or3));
  or_gate or_gate_s_cla12_or4(.a(s_cla12_and10[0]), .b(s_cla12_or3[0]), .out(s_cla12_or4));
  or_gate or_gate_s_cla12_or5(.a(s_cla12_pg_logic3_and0[0]), .b(s_cla12_or4[0]), .out(s_cla12_or5));
  pg_logic pg_logic_s_cla12_pg_logic4_out(.a(a[4]), .b(b[4]), .pg_logic_or0(s_cla12_pg_logic4_or0), .pg_logic_and0(s_cla12_pg_logic4_and0), .pg_logic_xor0(s_cla12_pg_logic4_xor0));
  xor_gate xor_gate_s_cla12_xor4(.a(s_cla12_pg_logic4_xor0[0]), .b(s_cla12_or5[0]), .out(s_cla12_xor4));
  and_gate and_gate_s_cla12_and12(.a(s_cla12_or5[0]), .b(s_cla12_pg_logic4_or0[0]), .out(s_cla12_and12));
  or_gate or_gate_s_cla12_or6(.a(s_cla12_pg_logic4_and0[0]), .b(s_cla12_and12[0]), .out(s_cla12_or6));
  pg_logic pg_logic_s_cla12_pg_logic5_out(.a(a[5]), .b(b[5]), .pg_logic_or0(s_cla12_pg_logic5_or0), .pg_logic_and0(s_cla12_pg_logic5_and0), .pg_logic_xor0(s_cla12_pg_logic5_xor0));
  xor_gate xor_gate_s_cla12_xor5(.a(s_cla12_pg_logic5_xor0[0]), .b(s_cla12_or6[0]), .out(s_cla12_xor5));
  and_gate and_gate_s_cla12_and13(.a(s_cla12_or5[0]), .b(s_cla12_pg_logic5_or0[0]), .out(s_cla12_and13));
  and_gate and_gate_s_cla12_and14(.a(s_cla12_and13[0]), .b(s_cla12_pg_logic4_or0[0]), .out(s_cla12_and14));
  and_gate and_gate_s_cla12_and15(.a(s_cla12_pg_logic4_and0[0]), .b(s_cla12_pg_logic5_or0[0]), .out(s_cla12_and15));
  or_gate or_gate_s_cla12_or7(.a(s_cla12_and14[0]), .b(s_cla12_and15[0]), .out(s_cla12_or7));
  or_gate or_gate_s_cla12_or8(.a(s_cla12_pg_logic5_and0[0]), .b(s_cla12_or7[0]), .out(s_cla12_or8));
  pg_logic pg_logic_s_cla12_pg_logic6_out(.a(a[6]), .b(b[6]), .pg_logic_or0(s_cla12_pg_logic6_or0), .pg_logic_and0(s_cla12_pg_logic6_and0), .pg_logic_xor0(s_cla12_pg_logic6_xor0));
  xor_gate xor_gate_s_cla12_xor6(.a(s_cla12_pg_logic6_xor0[0]), .b(s_cla12_or8[0]), .out(s_cla12_xor6));
  and_gate and_gate_s_cla12_and16(.a(s_cla12_or5[0]), .b(s_cla12_pg_logic5_or0[0]), .out(s_cla12_and16));
  and_gate and_gate_s_cla12_and17(.a(s_cla12_pg_logic6_or0[0]), .b(s_cla12_pg_logic4_or0[0]), .out(s_cla12_and17));
  and_gate and_gate_s_cla12_and18(.a(s_cla12_and16[0]), .b(s_cla12_and17[0]), .out(s_cla12_and18));
  and_gate and_gate_s_cla12_and19(.a(s_cla12_pg_logic4_and0[0]), .b(s_cla12_pg_logic6_or0[0]), .out(s_cla12_and19));
  and_gate and_gate_s_cla12_and20(.a(s_cla12_and19[0]), .b(s_cla12_pg_logic5_or0[0]), .out(s_cla12_and20));
  and_gate and_gate_s_cla12_and21(.a(s_cla12_pg_logic5_and0[0]), .b(s_cla12_pg_logic6_or0[0]), .out(s_cla12_and21));
  or_gate or_gate_s_cla12_or9(.a(s_cla12_and18[0]), .b(s_cla12_and20[0]), .out(s_cla12_or9));
  or_gate or_gate_s_cla12_or10(.a(s_cla12_or9[0]), .b(s_cla12_and21[0]), .out(s_cla12_or10));
  or_gate or_gate_s_cla12_or11(.a(s_cla12_pg_logic6_and0[0]), .b(s_cla12_or10[0]), .out(s_cla12_or11));
  pg_logic pg_logic_s_cla12_pg_logic7_out(.a(a[7]), .b(b[7]), .pg_logic_or0(s_cla12_pg_logic7_or0), .pg_logic_and0(s_cla12_pg_logic7_and0), .pg_logic_xor0(s_cla12_pg_logic7_xor0));
  xor_gate xor_gate_s_cla12_xor7(.a(s_cla12_pg_logic7_xor0[0]), .b(s_cla12_or11[0]), .out(s_cla12_xor7));
  and_gate and_gate_s_cla12_and22(.a(s_cla12_or5[0]), .b(s_cla12_pg_logic6_or0[0]), .out(s_cla12_and22));
  and_gate and_gate_s_cla12_and23(.a(s_cla12_pg_logic7_or0[0]), .b(s_cla12_pg_logic5_or0[0]), .out(s_cla12_and23));
  and_gate and_gate_s_cla12_and24(.a(s_cla12_and22[0]), .b(s_cla12_and23[0]), .out(s_cla12_and24));
  and_gate and_gate_s_cla12_and25(.a(s_cla12_and24[0]), .b(s_cla12_pg_logic4_or0[0]), .out(s_cla12_and25));
  and_gate and_gate_s_cla12_and26(.a(s_cla12_pg_logic4_and0[0]), .b(s_cla12_pg_logic6_or0[0]), .out(s_cla12_and26));
  and_gate and_gate_s_cla12_and27(.a(s_cla12_pg_logic7_or0[0]), .b(s_cla12_pg_logic5_or0[0]), .out(s_cla12_and27));
  and_gate and_gate_s_cla12_and28(.a(s_cla12_and26[0]), .b(s_cla12_and27[0]), .out(s_cla12_and28));
  and_gate and_gate_s_cla12_and29(.a(s_cla12_pg_logic5_and0[0]), .b(s_cla12_pg_logic7_or0[0]), .out(s_cla12_and29));
  and_gate and_gate_s_cla12_and30(.a(s_cla12_and29[0]), .b(s_cla12_pg_logic6_or0[0]), .out(s_cla12_and30));
  and_gate and_gate_s_cla12_and31(.a(s_cla12_pg_logic6_and0[0]), .b(s_cla12_pg_logic7_or0[0]), .out(s_cla12_and31));
  or_gate or_gate_s_cla12_or12(.a(s_cla12_and25[0]), .b(s_cla12_and30[0]), .out(s_cla12_or12));
  or_gate or_gate_s_cla12_or13(.a(s_cla12_and28[0]), .b(s_cla12_and31[0]), .out(s_cla12_or13));
  or_gate or_gate_s_cla12_or14(.a(s_cla12_or12[0]), .b(s_cla12_or13[0]), .out(s_cla12_or14));
  or_gate or_gate_s_cla12_or15(.a(s_cla12_pg_logic7_and0[0]), .b(s_cla12_or14[0]), .out(s_cla12_or15));
  pg_logic pg_logic_s_cla12_pg_logic8_out(.a(a[8]), .b(b[8]), .pg_logic_or0(s_cla12_pg_logic8_or0), .pg_logic_and0(s_cla12_pg_logic8_and0), .pg_logic_xor0(s_cla12_pg_logic8_xor0));
  xor_gate xor_gate_s_cla12_xor8(.a(s_cla12_pg_logic8_xor0[0]), .b(s_cla12_or15[0]), .out(s_cla12_xor8));
  and_gate and_gate_s_cla12_and32(.a(s_cla12_or15[0]), .b(s_cla12_pg_logic8_or0[0]), .out(s_cla12_and32));
  or_gate or_gate_s_cla12_or16(.a(s_cla12_pg_logic8_and0[0]), .b(s_cla12_and32[0]), .out(s_cla12_or16));
  pg_logic pg_logic_s_cla12_pg_logic9_out(.a(a[9]), .b(b[9]), .pg_logic_or0(s_cla12_pg_logic9_or0), .pg_logic_and0(s_cla12_pg_logic9_and0), .pg_logic_xor0(s_cla12_pg_logic9_xor0));
  xor_gate xor_gate_s_cla12_xor9(.a(s_cla12_pg_logic9_xor0[0]), .b(s_cla12_or16[0]), .out(s_cla12_xor9));
  and_gate and_gate_s_cla12_and33(.a(s_cla12_or15[0]), .b(s_cla12_pg_logic9_or0[0]), .out(s_cla12_and33));
  and_gate and_gate_s_cla12_and34(.a(s_cla12_and33[0]), .b(s_cla12_pg_logic8_or0[0]), .out(s_cla12_and34));
  and_gate and_gate_s_cla12_and35(.a(s_cla12_pg_logic8_and0[0]), .b(s_cla12_pg_logic9_or0[0]), .out(s_cla12_and35));
  or_gate or_gate_s_cla12_or17(.a(s_cla12_and34[0]), .b(s_cla12_and35[0]), .out(s_cla12_or17));
  or_gate or_gate_s_cla12_or18(.a(s_cla12_pg_logic9_and0[0]), .b(s_cla12_or17[0]), .out(s_cla12_or18));
  pg_logic pg_logic_s_cla12_pg_logic10_out(.a(a[10]), .b(b[10]), .pg_logic_or0(s_cla12_pg_logic10_or0), .pg_logic_and0(s_cla12_pg_logic10_and0), .pg_logic_xor0(s_cla12_pg_logic10_xor0));
  xor_gate xor_gate_s_cla12_xor10(.a(s_cla12_pg_logic10_xor0[0]), .b(s_cla12_or18[0]), .out(s_cla12_xor10));
  and_gate and_gate_s_cla12_and36(.a(s_cla12_or15[0]), .b(s_cla12_pg_logic9_or0[0]), .out(s_cla12_and36));
  and_gate and_gate_s_cla12_and37(.a(s_cla12_pg_logic10_or0[0]), .b(s_cla12_pg_logic8_or0[0]), .out(s_cla12_and37));
  and_gate and_gate_s_cla12_and38(.a(s_cla12_and36[0]), .b(s_cla12_and37[0]), .out(s_cla12_and38));
  and_gate and_gate_s_cla12_and39(.a(s_cla12_pg_logic8_and0[0]), .b(s_cla12_pg_logic10_or0[0]), .out(s_cla12_and39));
  and_gate and_gate_s_cla12_and40(.a(s_cla12_and39[0]), .b(s_cla12_pg_logic9_or0[0]), .out(s_cla12_and40));
  and_gate and_gate_s_cla12_and41(.a(s_cla12_pg_logic9_and0[0]), .b(s_cla12_pg_logic10_or0[0]), .out(s_cla12_and41));
  or_gate or_gate_s_cla12_or19(.a(s_cla12_and38[0]), .b(s_cla12_and40[0]), .out(s_cla12_or19));
  or_gate or_gate_s_cla12_or20(.a(s_cla12_or19[0]), .b(s_cla12_and41[0]), .out(s_cla12_or20));
  or_gate or_gate_s_cla12_or21(.a(s_cla12_pg_logic10_and0[0]), .b(s_cla12_or20[0]), .out(s_cla12_or21));
  pg_logic pg_logic_s_cla12_pg_logic11_out(.a(a[11]), .b(b[11]), .pg_logic_or0(s_cla12_pg_logic11_or0), .pg_logic_and0(s_cla12_pg_logic11_and0), .pg_logic_xor0(s_cla12_pg_logic11_xor0));
  xor_gate xor_gate_s_cla12_xor11(.a(s_cla12_pg_logic11_xor0[0]), .b(s_cla12_or21[0]), .out(s_cla12_xor11));
  and_gate and_gate_s_cla12_and42(.a(s_cla12_or15[0]), .b(s_cla12_pg_logic10_or0[0]), .out(s_cla12_and42));
  and_gate and_gate_s_cla12_and43(.a(s_cla12_pg_logic11_or0[0]), .b(s_cla12_pg_logic9_or0[0]), .out(s_cla12_and43));
  and_gate and_gate_s_cla12_and44(.a(s_cla12_and42[0]), .b(s_cla12_and43[0]), .out(s_cla12_and44));
  and_gate and_gate_s_cla12_and45(.a(s_cla12_and44[0]), .b(s_cla12_pg_logic8_or0[0]), .out(s_cla12_and45));
  and_gate and_gate_s_cla12_and46(.a(s_cla12_pg_logic8_and0[0]), .b(s_cla12_pg_logic10_or0[0]), .out(s_cla12_and46));
  and_gate and_gate_s_cla12_and47(.a(s_cla12_pg_logic11_or0[0]), .b(s_cla12_pg_logic9_or0[0]), .out(s_cla12_and47));
  and_gate and_gate_s_cla12_and48(.a(s_cla12_and46[0]), .b(s_cla12_and47[0]), .out(s_cla12_and48));
  and_gate and_gate_s_cla12_and49(.a(s_cla12_pg_logic9_and0[0]), .b(s_cla12_pg_logic11_or0[0]), .out(s_cla12_and49));
  and_gate and_gate_s_cla12_and50(.a(s_cla12_and49[0]), .b(s_cla12_pg_logic10_or0[0]), .out(s_cla12_and50));
  and_gate and_gate_s_cla12_and51(.a(s_cla12_pg_logic10_and0[0]), .b(s_cla12_pg_logic11_or0[0]), .out(s_cla12_and51));
  or_gate or_gate_s_cla12_or22(.a(s_cla12_and45[0]), .b(s_cla12_and50[0]), .out(s_cla12_or22));
  or_gate or_gate_s_cla12_or23(.a(s_cla12_and48[0]), .b(s_cla12_and51[0]), .out(s_cla12_or23));
  or_gate or_gate_s_cla12_or24(.a(s_cla12_or22[0]), .b(s_cla12_or23[0]), .out(s_cla12_or24));
  or_gate or_gate_s_cla12_or25(.a(s_cla12_pg_logic11_and0[0]), .b(s_cla12_or24[0]), .out(s_cla12_or25));
  xor_gate xor_gate_s_cla12_xor12(.a(a[11]), .b(b[11]), .out(s_cla12_xor12));
  xor_gate xor_gate_s_cla12_xor13(.a(s_cla12_xor12[0]), .b(s_cla12_or25[0]), .out(s_cla12_xor13));

  assign s_cla12_out[0] = s_cla12_pg_logic0_xor0[0];
  assign s_cla12_out[1] = s_cla12_xor1[0];
  assign s_cla12_out[2] = s_cla12_xor2[0];
  assign s_cla12_out[3] = s_cla12_xor3[0];
  assign s_cla12_out[4] = s_cla12_xor4[0];
  assign s_cla12_out[5] = s_cla12_xor5[0];
  assign s_cla12_out[6] = s_cla12_xor6[0];
  assign s_cla12_out[7] = s_cla12_xor7[0];
  assign s_cla12_out[8] = s_cla12_xor8[0];
  assign s_cla12_out[9] = s_cla12_xor9[0];
  assign s_cla12_out[10] = s_cla12_xor10[0];
  assign s_cla12_out[11] = s_cla12_xor11[0];
  assign s_cla12_out[12] = s_cla12_xor13[0];
endmodule