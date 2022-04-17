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

module s_cla24(input [23:0] a, input [23:0] b, output [24:0] s_cla24_out);
  wire [0:0] s_cla24_pg_logic0_or0;
  wire [0:0] s_cla24_pg_logic0_and0;
  wire [0:0] s_cla24_pg_logic0_xor0;
  wire [0:0] s_cla24_pg_logic1_or0;
  wire [0:0] s_cla24_pg_logic1_and0;
  wire [0:0] s_cla24_pg_logic1_xor0;
  wire [0:0] s_cla24_xor1;
  wire [0:0] s_cla24_and0;
  wire [0:0] s_cla24_or0;
  wire [0:0] s_cla24_pg_logic2_or0;
  wire [0:0] s_cla24_pg_logic2_and0;
  wire [0:0] s_cla24_pg_logic2_xor0;
  wire [0:0] s_cla24_xor2;
  wire [0:0] s_cla24_and1;
  wire [0:0] s_cla24_and2;
  wire [0:0] s_cla24_and3;
  wire [0:0] s_cla24_and4;
  wire [0:0] s_cla24_or1;
  wire [0:0] s_cla24_or2;
  wire [0:0] s_cla24_pg_logic3_or0;
  wire [0:0] s_cla24_pg_logic3_and0;
  wire [0:0] s_cla24_pg_logic3_xor0;
  wire [0:0] s_cla24_xor3;
  wire [0:0] s_cla24_and5;
  wire [0:0] s_cla24_and6;
  wire [0:0] s_cla24_and7;
  wire [0:0] s_cla24_and8;
  wire [0:0] s_cla24_and9;
  wire [0:0] s_cla24_and10;
  wire [0:0] s_cla24_and11;
  wire [0:0] s_cla24_or3;
  wire [0:0] s_cla24_or4;
  wire [0:0] s_cla24_or5;
  wire [0:0] s_cla24_pg_logic4_or0;
  wire [0:0] s_cla24_pg_logic4_and0;
  wire [0:0] s_cla24_pg_logic4_xor0;
  wire [0:0] s_cla24_xor4;
  wire [0:0] s_cla24_and12;
  wire [0:0] s_cla24_or6;
  wire [0:0] s_cla24_pg_logic5_or0;
  wire [0:0] s_cla24_pg_logic5_and0;
  wire [0:0] s_cla24_pg_logic5_xor0;
  wire [0:0] s_cla24_xor5;
  wire [0:0] s_cla24_and13;
  wire [0:0] s_cla24_and14;
  wire [0:0] s_cla24_and15;
  wire [0:0] s_cla24_or7;
  wire [0:0] s_cla24_or8;
  wire [0:0] s_cla24_pg_logic6_or0;
  wire [0:0] s_cla24_pg_logic6_and0;
  wire [0:0] s_cla24_pg_logic6_xor0;
  wire [0:0] s_cla24_xor6;
  wire [0:0] s_cla24_and16;
  wire [0:0] s_cla24_and17;
  wire [0:0] s_cla24_and18;
  wire [0:0] s_cla24_and19;
  wire [0:0] s_cla24_and20;
  wire [0:0] s_cla24_and21;
  wire [0:0] s_cla24_or9;
  wire [0:0] s_cla24_or10;
  wire [0:0] s_cla24_or11;
  wire [0:0] s_cla24_pg_logic7_or0;
  wire [0:0] s_cla24_pg_logic7_and0;
  wire [0:0] s_cla24_pg_logic7_xor0;
  wire [0:0] s_cla24_xor7;
  wire [0:0] s_cla24_and22;
  wire [0:0] s_cla24_and23;
  wire [0:0] s_cla24_and24;
  wire [0:0] s_cla24_and25;
  wire [0:0] s_cla24_and26;
  wire [0:0] s_cla24_and27;
  wire [0:0] s_cla24_and28;
  wire [0:0] s_cla24_and29;
  wire [0:0] s_cla24_and30;
  wire [0:0] s_cla24_and31;
  wire [0:0] s_cla24_or12;
  wire [0:0] s_cla24_or13;
  wire [0:0] s_cla24_or14;
  wire [0:0] s_cla24_or15;
  wire [0:0] s_cla24_pg_logic8_or0;
  wire [0:0] s_cla24_pg_logic8_and0;
  wire [0:0] s_cla24_pg_logic8_xor0;
  wire [0:0] s_cla24_xor8;
  wire [0:0] s_cla24_and32;
  wire [0:0] s_cla24_or16;
  wire [0:0] s_cla24_pg_logic9_or0;
  wire [0:0] s_cla24_pg_logic9_and0;
  wire [0:0] s_cla24_pg_logic9_xor0;
  wire [0:0] s_cla24_xor9;
  wire [0:0] s_cla24_and33;
  wire [0:0] s_cla24_and34;
  wire [0:0] s_cla24_and35;
  wire [0:0] s_cla24_or17;
  wire [0:0] s_cla24_or18;
  wire [0:0] s_cla24_pg_logic10_or0;
  wire [0:0] s_cla24_pg_logic10_and0;
  wire [0:0] s_cla24_pg_logic10_xor0;
  wire [0:0] s_cla24_xor10;
  wire [0:0] s_cla24_and36;
  wire [0:0] s_cla24_and37;
  wire [0:0] s_cla24_and38;
  wire [0:0] s_cla24_and39;
  wire [0:0] s_cla24_and40;
  wire [0:0] s_cla24_and41;
  wire [0:0] s_cla24_or19;
  wire [0:0] s_cla24_or20;
  wire [0:0] s_cla24_or21;
  wire [0:0] s_cla24_pg_logic11_or0;
  wire [0:0] s_cla24_pg_logic11_and0;
  wire [0:0] s_cla24_pg_logic11_xor0;
  wire [0:0] s_cla24_xor11;
  wire [0:0] s_cla24_and42;
  wire [0:0] s_cla24_and43;
  wire [0:0] s_cla24_and44;
  wire [0:0] s_cla24_and45;
  wire [0:0] s_cla24_and46;
  wire [0:0] s_cla24_and47;
  wire [0:0] s_cla24_and48;
  wire [0:0] s_cla24_and49;
  wire [0:0] s_cla24_and50;
  wire [0:0] s_cla24_and51;
  wire [0:0] s_cla24_or22;
  wire [0:0] s_cla24_or23;
  wire [0:0] s_cla24_or24;
  wire [0:0] s_cla24_or25;
  wire [0:0] s_cla24_pg_logic12_or0;
  wire [0:0] s_cla24_pg_logic12_and0;
  wire [0:0] s_cla24_pg_logic12_xor0;
  wire [0:0] s_cla24_xor12;
  wire [0:0] s_cla24_and52;
  wire [0:0] s_cla24_or26;
  wire [0:0] s_cla24_pg_logic13_or0;
  wire [0:0] s_cla24_pg_logic13_and0;
  wire [0:0] s_cla24_pg_logic13_xor0;
  wire [0:0] s_cla24_xor13;
  wire [0:0] s_cla24_and53;
  wire [0:0] s_cla24_and54;
  wire [0:0] s_cla24_and55;
  wire [0:0] s_cla24_or27;
  wire [0:0] s_cla24_or28;
  wire [0:0] s_cla24_pg_logic14_or0;
  wire [0:0] s_cla24_pg_logic14_and0;
  wire [0:0] s_cla24_pg_logic14_xor0;
  wire [0:0] s_cla24_xor14;
  wire [0:0] s_cla24_and56;
  wire [0:0] s_cla24_and57;
  wire [0:0] s_cla24_and58;
  wire [0:0] s_cla24_and59;
  wire [0:0] s_cla24_and60;
  wire [0:0] s_cla24_and61;
  wire [0:0] s_cla24_or29;
  wire [0:0] s_cla24_or30;
  wire [0:0] s_cla24_or31;
  wire [0:0] s_cla24_pg_logic15_or0;
  wire [0:0] s_cla24_pg_logic15_and0;
  wire [0:0] s_cla24_pg_logic15_xor0;
  wire [0:0] s_cla24_xor15;
  wire [0:0] s_cla24_and62;
  wire [0:0] s_cla24_and63;
  wire [0:0] s_cla24_and64;
  wire [0:0] s_cla24_and65;
  wire [0:0] s_cla24_and66;
  wire [0:0] s_cla24_and67;
  wire [0:0] s_cla24_and68;
  wire [0:0] s_cla24_and69;
  wire [0:0] s_cla24_and70;
  wire [0:0] s_cla24_and71;
  wire [0:0] s_cla24_or32;
  wire [0:0] s_cla24_or33;
  wire [0:0] s_cla24_or34;
  wire [0:0] s_cla24_or35;
  wire [0:0] s_cla24_pg_logic16_or0;
  wire [0:0] s_cla24_pg_logic16_and0;
  wire [0:0] s_cla24_pg_logic16_xor0;
  wire [0:0] s_cla24_xor16;
  wire [0:0] s_cla24_and72;
  wire [0:0] s_cla24_or36;
  wire [0:0] s_cla24_pg_logic17_or0;
  wire [0:0] s_cla24_pg_logic17_and0;
  wire [0:0] s_cla24_pg_logic17_xor0;
  wire [0:0] s_cla24_xor17;
  wire [0:0] s_cla24_and73;
  wire [0:0] s_cla24_and74;
  wire [0:0] s_cla24_and75;
  wire [0:0] s_cla24_or37;
  wire [0:0] s_cla24_or38;
  wire [0:0] s_cla24_pg_logic18_or0;
  wire [0:0] s_cla24_pg_logic18_and0;
  wire [0:0] s_cla24_pg_logic18_xor0;
  wire [0:0] s_cla24_xor18;
  wire [0:0] s_cla24_and76;
  wire [0:0] s_cla24_and77;
  wire [0:0] s_cla24_and78;
  wire [0:0] s_cla24_and79;
  wire [0:0] s_cla24_and80;
  wire [0:0] s_cla24_and81;
  wire [0:0] s_cla24_or39;
  wire [0:0] s_cla24_or40;
  wire [0:0] s_cla24_or41;
  wire [0:0] s_cla24_pg_logic19_or0;
  wire [0:0] s_cla24_pg_logic19_and0;
  wire [0:0] s_cla24_pg_logic19_xor0;
  wire [0:0] s_cla24_xor19;
  wire [0:0] s_cla24_and82;
  wire [0:0] s_cla24_and83;
  wire [0:0] s_cla24_and84;
  wire [0:0] s_cla24_and85;
  wire [0:0] s_cla24_and86;
  wire [0:0] s_cla24_and87;
  wire [0:0] s_cla24_and88;
  wire [0:0] s_cla24_and89;
  wire [0:0] s_cla24_and90;
  wire [0:0] s_cla24_and91;
  wire [0:0] s_cla24_or42;
  wire [0:0] s_cla24_or43;
  wire [0:0] s_cla24_or44;
  wire [0:0] s_cla24_or45;
  wire [0:0] s_cla24_pg_logic20_or0;
  wire [0:0] s_cla24_pg_logic20_and0;
  wire [0:0] s_cla24_pg_logic20_xor0;
  wire [0:0] s_cla24_xor20;
  wire [0:0] s_cla24_and92;
  wire [0:0] s_cla24_or46;
  wire [0:0] s_cla24_pg_logic21_or0;
  wire [0:0] s_cla24_pg_logic21_and0;
  wire [0:0] s_cla24_pg_logic21_xor0;
  wire [0:0] s_cla24_xor21;
  wire [0:0] s_cla24_and93;
  wire [0:0] s_cla24_and94;
  wire [0:0] s_cla24_and95;
  wire [0:0] s_cla24_or47;
  wire [0:0] s_cla24_or48;
  wire [0:0] s_cla24_pg_logic22_or0;
  wire [0:0] s_cla24_pg_logic22_and0;
  wire [0:0] s_cla24_pg_logic22_xor0;
  wire [0:0] s_cla24_xor22;
  wire [0:0] s_cla24_and96;
  wire [0:0] s_cla24_and97;
  wire [0:0] s_cla24_and98;
  wire [0:0] s_cla24_and99;
  wire [0:0] s_cla24_and100;
  wire [0:0] s_cla24_and101;
  wire [0:0] s_cla24_or49;
  wire [0:0] s_cla24_or50;
  wire [0:0] s_cla24_or51;
  wire [0:0] s_cla24_pg_logic23_or0;
  wire [0:0] s_cla24_pg_logic23_and0;
  wire [0:0] s_cla24_pg_logic23_xor0;
  wire [0:0] s_cla24_xor23;
  wire [0:0] s_cla24_and102;
  wire [0:0] s_cla24_and103;
  wire [0:0] s_cla24_and104;
  wire [0:0] s_cla24_and105;
  wire [0:0] s_cla24_and106;
  wire [0:0] s_cla24_and107;
  wire [0:0] s_cla24_and108;
  wire [0:0] s_cla24_and109;
  wire [0:0] s_cla24_and110;
  wire [0:0] s_cla24_and111;
  wire [0:0] s_cla24_or52;
  wire [0:0] s_cla24_or53;
  wire [0:0] s_cla24_or54;
  wire [0:0] s_cla24_or55;
  wire [0:0] s_cla24_xor24;
  wire [0:0] s_cla24_xor25;

  pg_logic pg_logic_s_cla24_pg_logic0_out(.a(a[0]), .b(b[0]), .pg_logic_or0(s_cla24_pg_logic0_or0), .pg_logic_and0(s_cla24_pg_logic0_and0), .pg_logic_xor0(s_cla24_pg_logic0_xor0));
  pg_logic pg_logic_s_cla24_pg_logic1_out(.a(a[1]), .b(b[1]), .pg_logic_or0(s_cla24_pg_logic1_or0), .pg_logic_and0(s_cla24_pg_logic1_and0), .pg_logic_xor0(s_cla24_pg_logic1_xor0));
  xor_gate xor_gate_s_cla24_xor1(.a(s_cla24_pg_logic1_xor0[0]), .b(s_cla24_pg_logic0_and0[0]), .out(s_cla24_xor1));
  and_gate and_gate_s_cla24_and0(.a(s_cla24_pg_logic0_and0[0]), .b(s_cla24_pg_logic1_or0[0]), .out(s_cla24_and0));
  or_gate or_gate_s_cla24_or0(.a(s_cla24_pg_logic1_and0[0]), .b(s_cla24_and0[0]), .out(s_cla24_or0));
  pg_logic pg_logic_s_cla24_pg_logic2_out(.a(a[2]), .b(b[2]), .pg_logic_or0(s_cla24_pg_logic2_or0), .pg_logic_and0(s_cla24_pg_logic2_and0), .pg_logic_xor0(s_cla24_pg_logic2_xor0));
  xor_gate xor_gate_s_cla24_xor2(.a(s_cla24_pg_logic2_xor0[0]), .b(s_cla24_or0[0]), .out(s_cla24_xor2));
  and_gate and_gate_s_cla24_and1(.a(s_cla24_pg_logic2_or0[0]), .b(s_cla24_pg_logic0_or0[0]), .out(s_cla24_and1));
  and_gate and_gate_s_cla24_and2(.a(s_cla24_pg_logic0_and0[0]), .b(s_cla24_pg_logic2_or0[0]), .out(s_cla24_and2));
  and_gate and_gate_s_cla24_and3(.a(s_cla24_and2[0]), .b(s_cla24_pg_logic1_or0[0]), .out(s_cla24_and3));
  and_gate and_gate_s_cla24_and4(.a(s_cla24_pg_logic1_and0[0]), .b(s_cla24_pg_logic2_or0[0]), .out(s_cla24_and4));
  or_gate or_gate_s_cla24_or1(.a(s_cla24_and3[0]), .b(s_cla24_and4[0]), .out(s_cla24_or1));
  or_gate or_gate_s_cla24_or2(.a(s_cla24_pg_logic2_and0[0]), .b(s_cla24_or1[0]), .out(s_cla24_or2));
  pg_logic pg_logic_s_cla24_pg_logic3_out(.a(a[3]), .b(b[3]), .pg_logic_or0(s_cla24_pg_logic3_or0), .pg_logic_and0(s_cla24_pg_logic3_and0), .pg_logic_xor0(s_cla24_pg_logic3_xor0));
  xor_gate xor_gate_s_cla24_xor3(.a(s_cla24_pg_logic3_xor0[0]), .b(s_cla24_or2[0]), .out(s_cla24_xor3));
  and_gate and_gate_s_cla24_and5(.a(s_cla24_pg_logic3_or0[0]), .b(s_cla24_pg_logic1_or0[0]), .out(s_cla24_and5));
  and_gate and_gate_s_cla24_and6(.a(s_cla24_pg_logic0_and0[0]), .b(s_cla24_pg_logic2_or0[0]), .out(s_cla24_and6));
  and_gate and_gate_s_cla24_and7(.a(s_cla24_pg_logic3_or0[0]), .b(s_cla24_pg_logic1_or0[0]), .out(s_cla24_and7));
  and_gate and_gate_s_cla24_and8(.a(s_cla24_and6[0]), .b(s_cla24_and7[0]), .out(s_cla24_and8));
  and_gate and_gate_s_cla24_and9(.a(s_cla24_pg_logic1_and0[0]), .b(s_cla24_pg_logic3_or0[0]), .out(s_cla24_and9));
  and_gate and_gate_s_cla24_and10(.a(s_cla24_and9[0]), .b(s_cla24_pg_logic2_or0[0]), .out(s_cla24_and10));
  and_gate and_gate_s_cla24_and11(.a(s_cla24_pg_logic2_and0[0]), .b(s_cla24_pg_logic3_or0[0]), .out(s_cla24_and11));
  or_gate or_gate_s_cla24_or3(.a(s_cla24_and8[0]), .b(s_cla24_and11[0]), .out(s_cla24_or3));
  or_gate or_gate_s_cla24_or4(.a(s_cla24_and10[0]), .b(s_cla24_or3[0]), .out(s_cla24_or4));
  or_gate or_gate_s_cla24_or5(.a(s_cla24_pg_logic3_and0[0]), .b(s_cla24_or4[0]), .out(s_cla24_or5));
  pg_logic pg_logic_s_cla24_pg_logic4_out(.a(a[4]), .b(b[4]), .pg_logic_or0(s_cla24_pg_logic4_or0), .pg_logic_and0(s_cla24_pg_logic4_and0), .pg_logic_xor0(s_cla24_pg_logic4_xor0));
  xor_gate xor_gate_s_cla24_xor4(.a(s_cla24_pg_logic4_xor0[0]), .b(s_cla24_or5[0]), .out(s_cla24_xor4));
  and_gate and_gate_s_cla24_and12(.a(s_cla24_or5[0]), .b(s_cla24_pg_logic4_or0[0]), .out(s_cla24_and12));
  or_gate or_gate_s_cla24_or6(.a(s_cla24_pg_logic4_and0[0]), .b(s_cla24_and12[0]), .out(s_cla24_or6));
  pg_logic pg_logic_s_cla24_pg_logic5_out(.a(a[5]), .b(b[5]), .pg_logic_or0(s_cla24_pg_logic5_or0), .pg_logic_and0(s_cla24_pg_logic5_and0), .pg_logic_xor0(s_cla24_pg_logic5_xor0));
  xor_gate xor_gate_s_cla24_xor5(.a(s_cla24_pg_logic5_xor0[0]), .b(s_cla24_or6[0]), .out(s_cla24_xor5));
  and_gate and_gate_s_cla24_and13(.a(s_cla24_or5[0]), .b(s_cla24_pg_logic5_or0[0]), .out(s_cla24_and13));
  and_gate and_gate_s_cla24_and14(.a(s_cla24_and13[0]), .b(s_cla24_pg_logic4_or0[0]), .out(s_cla24_and14));
  and_gate and_gate_s_cla24_and15(.a(s_cla24_pg_logic4_and0[0]), .b(s_cla24_pg_logic5_or0[0]), .out(s_cla24_and15));
  or_gate or_gate_s_cla24_or7(.a(s_cla24_and14[0]), .b(s_cla24_and15[0]), .out(s_cla24_or7));
  or_gate or_gate_s_cla24_or8(.a(s_cla24_pg_logic5_and0[0]), .b(s_cla24_or7[0]), .out(s_cla24_or8));
  pg_logic pg_logic_s_cla24_pg_logic6_out(.a(a[6]), .b(b[6]), .pg_logic_or0(s_cla24_pg_logic6_or0), .pg_logic_and0(s_cla24_pg_logic6_and0), .pg_logic_xor0(s_cla24_pg_logic6_xor0));
  xor_gate xor_gate_s_cla24_xor6(.a(s_cla24_pg_logic6_xor0[0]), .b(s_cla24_or8[0]), .out(s_cla24_xor6));
  and_gate and_gate_s_cla24_and16(.a(s_cla24_or5[0]), .b(s_cla24_pg_logic5_or0[0]), .out(s_cla24_and16));
  and_gate and_gate_s_cla24_and17(.a(s_cla24_pg_logic6_or0[0]), .b(s_cla24_pg_logic4_or0[0]), .out(s_cla24_and17));
  and_gate and_gate_s_cla24_and18(.a(s_cla24_and16[0]), .b(s_cla24_and17[0]), .out(s_cla24_and18));
  and_gate and_gate_s_cla24_and19(.a(s_cla24_pg_logic4_and0[0]), .b(s_cla24_pg_logic6_or0[0]), .out(s_cla24_and19));
  and_gate and_gate_s_cla24_and20(.a(s_cla24_and19[0]), .b(s_cla24_pg_logic5_or0[0]), .out(s_cla24_and20));
  and_gate and_gate_s_cla24_and21(.a(s_cla24_pg_logic5_and0[0]), .b(s_cla24_pg_logic6_or0[0]), .out(s_cla24_and21));
  or_gate or_gate_s_cla24_or9(.a(s_cla24_and18[0]), .b(s_cla24_and20[0]), .out(s_cla24_or9));
  or_gate or_gate_s_cla24_or10(.a(s_cla24_or9[0]), .b(s_cla24_and21[0]), .out(s_cla24_or10));
  or_gate or_gate_s_cla24_or11(.a(s_cla24_pg_logic6_and0[0]), .b(s_cla24_or10[0]), .out(s_cla24_or11));
  pg_logic pg_logic_s_cla24_pg_logic7_out(.a(a[7]), .b(b[7]), .pg_logic_or0(s_cla24_pg_logic7_or0), .pg_logic_and0(s_cla24_pg_logic7_and0), .pg_logic_xor0(s_cla24_pg_logic7_xor0));
  xor_gate xor_gate_s_cla24_xor7(.a(s_cla24_pg_logic7_xor0[0]), .b(s_cla24_or11[0]), .out(s_cla24_xor7));
  and_gate and_gate_s_cla24_and22(.a(s_cla24_or5[0]), .b(s_cla24_pg_logic6_or0[0]), .out(s_cla24_and22));
  and_gate and_gate_s_cla24_and23(.a(s_cla24_pg_logic7_or0[0]), .b(s_cla24_pg_logic5_or0[0]), .out(s_cla24_and23));
  and_gate and_gate_s_cla24_and24(.a(s_cla24_and22[0]), .b(s_cla24_and23[0]), .out(s_cla24_and24));
  and_gate and_gate_s_cla24_and25(.a(s_cla24_and24[0]), .b(s_cla24_pg_logic4_or0[0]), .out(s_cla24_and25));
  and_gate and_gate_s_cla24_and26(.a(s_cla24_pg_logic4_and0[0]), .b(s_cla24_pg_logic6_or0[0]), .out(s_cla24_and26));
  and_gate and_gate_s_cla24_and27(.a(s_cla24_pg_logic7_or0[0]), .b(s_cla24_pg_logic5_or0[0]), .out(s_cla24_and27));
  and_gate and_gate_s_cla24_and28(.a(s_cla24_and26[0]), .b(s_cla24_and27[0]), .out(s_cla24_and28));
  and_gate and_gate_s_cla24_and29(.a(s_cla24_pg_logic5_and0[0]), .b(s_cla24_pg_logic7_or0[0]), .out(s_cla24_and29));
  and_gate and_gate_s_cla24_and30(.a(s_cla24_and29[0]), .b(s_cla24_pg_logic6_or0[0]), .out(s_cla24_and30));
  and_gate and_gate_s_cla24_and31(.a(s_cla24_pg_logic6_and0[0]), .b(s_cla24_pg_logic7_or0[0]), .out(s_cla24_and31));
  or_gate or_gate_s_cla24_or12(.a(s_cla24_and25[0]), .b(s_cla24_and30[0]), .out(s_cla24_or12));
  or_gate or_gate_s_cla24_or13(.a(s_cla24_and28[0]), .b(s_cla24_and31[0]), .out(s_cla24_or13));
  or_gate or_gate_s_cla24_or14(.a(s_cla24_or12[0]), .b(s_cla24_or13[0]), .out(s_cla24_or14));
  or_gate or_gate_s_cla24_or15(.a(s_cla24_pg_logic7_and0[0]), .b(s_cla24_or14[0]), .out(s_cla24_or15));
  pg_logic pg_logic_s_cla24_pg_logic8_out(.a(a[8]), .b(b[8]), .pg_logic_or0(s_cla24_pg_logic8_or0), .pg_logic_and0(s_cla24_pg_logic8_and0), .pg_logic_xor0(s_cla24_pg_logic8_xor0));
  xor_gate xor_gate_s_cla24_xor8(.a(s_cla24_pg_logic8_xor0[0]), .b(s_cla24_or15[0]), .out(s_cla24_xor8));
  and_gate and_gate_s_cla24_and32(.a(s_cla24_or15[0]), .b(s_cla24_pg_logic8_or0[0]), .out(s_cla24_and32));
  or_gate or_gate_s_cla24_or16(.a(s_cla24_pg_logic8_and0[0]), .b(s_cla24_and32[0]), .out(s_cla24_or16));
  pg_logic pg_logic_s_cla24_pg_logic9_out(.a(a[9]), .b(b[9]), .pg_logic_or0(s_cla24_pg_logic9_or0), .pg_logic_and0(s_cla24_pg_logic9_and0), .pg_logic_xor0(s_cla24_pg_logic9_xor0));
  xor_gate xor_gate_s_cla24_xor9(.a(s_cla24_pg_logic9_xor0[0]), .b(s_cla24_or16[0]), .out(s_cla24_xor9));
  and_gate and_gate_s_cla24_and33(.a(s_cla24_or15[0]), .b(s_cla24_pg_logic9_or0[0]), .out(s_cla24_and33));
  and_gate and_gate_s_cla24_and34(.a(s_cla24_and33[0]), .b(s_cla24_pg_logic8_or0[0]), .out(s_cla24_and34));
  and_gate and_gate_s_cla24_and35(.a(s_cla24_pg_logic8_and0[0]), .b(s_cla24_pg_logic9_or0[0]), .out(s_cla24_and35));
  or_gate or_gate_s_cla24_or17(.a(s_cla24_and34[0]), .b(s_cla24_and35[0]), .out(s_cla24_or17));
  or_gate or_gate_s_cla24_or18(.a(s_cla24_pg_logic9_and0[0]), .b(s_cla24_or17[0]), .out(s_cla24_or18));
  pg_logic pg_logic_s_cla24_pg_logic10_out(.a(a[10]), .b(b[10]), .pg_logic_or0(s_cla24_pg_logic10_or0), .pg_logic_and0(s_cla24_pg_logic10_and0), .pg_logic_xor0(s_cla24_pg_logic10_xor0));
  xor_gate xor_gate_s_cla24_xor10(.a(s_cla24_pg_logic10_xor0[0]), .b(s_cla24_or18[0]), .out(s_cla24_xor10));
  and_gate and_gate_s_cla24_and36(.a(s_cla24_or15[0]), .b(s_cla24_pg_logic9_or0[0]), .out(s_cla24_and36));
  and_gate and_gate_s_cla24_and37(.a(s_cla24_pg_logic10_or0[0]), .b(s_cla24_pg_logic8_or0[0]), .out(s_cla24_and37));
  and_gate and_gate_s_cla24_and38(.a(s_cla24_and36[0]), .b(s_cla24_and37[0]), .out(s_cla24_and38));
  and_gate and_gate_s_cla24_and39(.a(s_cla24_pg_logic8_and0[0]), .b(s_cla24_pg_logic10_or0[0]), .out(s_cla24_and39));
  and_gate and_gate_s_cla24_and40(.a(s_cla24_and39[0]), .b(s_cla24_pg_logic9_or0[0]), .out(s_cla24_and40));
  and_gate and_gate_s_cla24_and41(.a(s_cla24_pg_logic9_and0[0]), .b(s_cla24_pg_logic10_or0[0]), .out(s_cla24_and41));
  or_gate or_gate_s_cla24_or19(.a(s_cla24_and38[0]), .b(s_cla24_and40[0]), .out(s_cla24_or19));
  or_gate or_gate_s_cla24_or20(.a(s_cla24_or19[0]), .b(s_cla24_and41[0]), .out(s_cla24_or20));
  or_gate or_gate_s_cla24_or21(.a(s_cla24_pg_logic10_and0[0]), .b(s_cla24_or20[0]), .out(s_cla24_or21));
  pg_logic pg_logic_s_cla24_pg_logic11_out(.a(a[11]), .b(b[11]), .pg_logic_or0(s_cla24_pg_logic11_or0), .pg_logic_and0(s_cla24_pg_logic11_and0), .pg_logic_xor0(s_cla24_pg_logic11_xor0));
  xor_gate xor_gate_s_cla24_xor11(.a(s_cla24_pg_logic11_xor0[0]), .b(s_cla24_or21[0]), .out(s_cla24_xor11));
  and_gate and_gate_s_cla24_and42(.a(s_cla24_or15[0]), .b(s_cla24_pg_logic10_or0[0]), .out(s_cla24_and42));
  and_gate and_gate_s_cla24_and43(.a(s_cla24_pg_logic11_or0[0]), .b(s_cla24_pg_logic9_or0[0]), .out(s_cla24_and43));
  and_gate and_gate_s_cla24_and44(.a(s_cla24_and42[0]), .b(s_cla24_and43[0]), .out(s_cla24_and44));
  and_gate and_gate_s_cla24_and45(.a(s_cla24_and44[0]), .b(s_cla24_pg_logic8_or0[0]), .out(s_cla24_and45));
  and_gate and_gate_s_cla24_and46(.a(s_cla24_pg_logic8_and0[0]), .b(s_cla24_pg_logic10_or0[0]), .out(s_cla24_and46));
  and_gate and_gate_s_cla24_and47(.a(s_cla24_pg_logic11_or0[0]), .b(s_cla24_pg_logic9_or0[0]), .out(s_cla24_and47));
  and_gate and_gate_s_cla24_and48(.a(s_cla24_and46[0]), .b(s_cla24_and47[0]), .out(s_cla24_and48));
  and_gate and_gate_s_cla24_and49(.a(s_cla24_pg_logic9_and0[0]), .b(s_cla24_pg_logic11_or0[0]), .out(s_cla24_and49));
  and_gate and_gate_s_cla24_and50(.a(s_cla24_and49[0]), .b(s_cla24_pg_logic10_or0[0]), .out(s_cla24_and50));
  and_gate and_gate_s_cla24_and51(.a(s_cla24_pg_logic10_and0[0]), .b(s_cla24_pg_logic11_or0[0]), .out(s_cla24_and51));
  or_gate or_gate_s_cla24_or22(.a(s_cla24_and45[0]), .b(s_cla24_and50[0]), .out(s_cla24_or22));
  or_gate or_gate_s_cla24_or23(.a(s_cla24_and48[0]), .b(s_cla24_and51[0]), .out(s_cla24_or23));
  or_gate or_gate_s_cla24_or24(.a(s_cla24_or22[0]), .b(s_cla24_or23[0]), .out(s_cla24_or24));
  or_gate or_gate_s_cla24_or25(.a(s_cla24_pg_logic11_and0[0]), .b(s_cla24_or24[0]), .out(s_cla24_or25));
  pg_logic pg_logic_s_cla24_pg_logic12_out(.a(a[12]), .b(b[12]), .pg_logic_or0(s_cla24_pg_logic12_or0), .pg_logic_and0(s_cla24_pg_logic12_and0), .pg_logic_xor0(s_cla24_pg_logic12_xor0));
  xor_gate xor_gate_s_cla24_xor12(.a(s_cla24_pg_logic12_xor0[0]), .b(s_cla24_or25[0]), .out(s_cla24_xor12));
  and_gate and_gate_s_cla24_and52(.a(s_cla24_or25[0]), .b(s_cla24_pg_logic12_or0[0]), .out(s_cla24_and52));
  or_gate or_gate_s_cla24_or26(.a(s_cla24_pg_logic12_and0[0]), .b(s_cla24_and52[0]), .out(s_cla24_or26));
  pg_logic pg_logic_s_cla24_pg_logic13_out(.a(a[13]), .b(b[13]), .pg_logic_or0(s_cla24_pg_logic13_or0), .pg_logic_and0(s_cla24_pg_logic13_and0), .pg_logic_xor0(s_cla24_pg_logic13_xor0));
  xor_gate xor_gate_s_cla24_xor13(.a(s_cla24_pg_logic13_xor0[0]), .b(s_cla24_or26[0]), .out(s_cla24_xor13));
  and_gate and_gate_s_cla24_and53(.a(s_cla24_or25[0]), .b(s_cla24_pg_logic13_or0[0]), .out(s_cla24_and53));
  and_gate and_gate_s_cla24_and54(.a(s_cla24_and53[0]), .b(s_cla24_pg_logic12_or0[0]), .out(s_cla24_and54));
  and_gate and_gate_s_cla24_and55(.a(s_cla24_pg_logic12_and0[0]), .b(s_cla24_pg_logic13_or0[0]), .out(s_cla24_and55));
  or_gate or_gate_s_cla24_or27(.a(s_cla24_and54[0]), .b(s_cla24_and55[0]), .out(s_cla24_or27));
  or_gate or_gate_s_cla24_or28(.a(s_cla24_pg_logic13_and0[0]), .b(s_cla24_or27[0]), .out(s_cla24_or28));
  pg_logic pg_logic_s_cla24_pg_logic14_out(.a(a[14]), .b(b[14]), .pg_logic_or0(s_cla24_pg_logic14_or0), .pg_logic_and0(s_cla24_pg_logic14_and0), .pg_logic_xor0(s_cla24_pg_logic14_xor0));
  xor_gate xor_gate_s_cla24_xor14(.a(s_cla24_pg_logic14_xor0[0]), .b(s_cla24_or28[0]), .out(s_cla24_xor14));
  and_gate and_gate_s_cla24_and56(.a(s_cla24_or25[0]), .b(s_cla24_pg_logic13_or0[0]), .out(s_cla24_and56));
  and_gate and_gate_s_cla24_and57(.a(s_cla24_pg_logic14_or0[0]), .b(s_cla24_pg_logic12_or0[0]), .out(s_cla24_and57));
  and_gate and_gate_s_cla24_and58(.a(s_cla24_and56[0]), .b(s_cla24_and57[0]), .out(s_cla24_and58));
  and_gate and_gate_s_cla24_and59(.a(s_cla24_pg_logic12_and0[0]), .b(s_cla24_pg_logic14_or0[0]), .out(s_cla24_and59));
  and_gate and_gate_s_cla24_and60(.a(s_cla24_and59[0]), .b(s_cla24_pg_logic13_or0[0]), .out(s_cla24_and60));
  and_gate and_gate_s_cla24_and61(.a(s_cla24_pg_logic13_and0[0]), .b(s_cla24_pg_logic14_or0[0]), .out(s_cla24_and61));
  or_gate or_gate_s_cla24_or29(.a(s_cla24_and58[0]), .b(s_cla24_and60[0]), .out(s_cla24_or29));
  or_gate or_gate_s_cla24_or30(.a(s_cla24_or29[0]), .b(s_cla24_and61[0]), .out(s_cla24_or30));
  or_gate or_gate_s_cla24_or31(.a(s_cla24_pg_logic14_and0[0]), .b(s_cla24_or30[0]), .out(s_cla24_or31));
  pg_logic pg_logic_s_cla24_pg_logic15_out(.a(a[15]), .b(b[15]), .pg_logic_or0(s_cla24_pg_logic15_or0), .pg_logic_and0(s_cla24_pg_logic15_and0), .pg_logic_xor0(s_cla24_pg_logic15_xor0));
  xor_gate xor_gate_s_cla24_xor15(.a(s_cla24_pg_logic15_xor0[0]), .b(s_cla24_or31[0]), .out(s_cla24_xor15));
  and_gate and_gate_s_cla24_and62(.a(s_cla24_or25[0]), .b(s_cla24_pg_logic14_or0[0]), .out(s_cla24_and62));
  and_gate and_gate_s_cla24_and63(.a(s_cla24_pg_logic15_or0[0]), .b(s_cla24_pg_logic13_or0[0]), .out(s_cla24_and63));
  and_gate and_gate_s_cla24_and64(.a(s_cla24_and62[0]), .b(s_cla24_and63[0]), .out(s_cla24_and64));
  and_gate and_gate_s_cla24_and65(.a(s_cla24_and64[0]), .b(s_cla24_pg_logic12_or0[0]), .out(s_cla24_and65));
  and_gate and_gate_s_cla24_and66(.a(s_cla24_pg_logic12_and0[0]), .b(s_cla24_pg_logic14_or0[0]), .out(s_cla24_and66));
  and_gate and_gate_s_cla24_and67(.a(s_cla24_pg_logic15_or0[0]), .b(s_cla24_pg_logic13_or0[0]), .out(s_cla24_and67));
  and_gate and_gate_s_cla24_and68(.a(s_cla24_and66[0]), .b(s_cla24_and67[0]), .out(s_cla24_and68));
  and_gate and_gate_s_cla24_and69(.a(s_cla24_pg_logic13_and0[0]), .b(s_cla24_pg_logic15_or0[0]), .out(s_cla24_and69));
  and_gate and_gate_s_cla24_and70(.a(s_cla24_and69[0]), .b(s_cla24_pg_logic14_or0[0]), .out(s_cla24_and70));
  and_gate and_gate_s_cla24_and71(.a(s_cla24_pg_logic14_and0[0]), .b(s_cla24_pg_logic15_or0[0]), .out(s_cla24_and71));
  or_gate or_gate_s_cla24_or32(.a(s_cla24_and65[0]), .b(s_cla24_and70[0]), .out(s_cla24_or32));
  or_gate or_gate_s_cla24_or33(.a(s_cla24_and68[0]), .b(s_cla24_and71[0]), .out(s_cla24_or33));
  or_gate or_gate_s_cla24_or34(.a(s_cla24_or32[0]), .b(s_cla24_or33[0]), .out(s_cla24_or34));
  or_gate or_gate_s_cla24_or35(.a(s_cla24_pg_logic15_and0[0]), .b(s_cla24_or34[0]), .out(s_cla24_or35));
  pg_logic pg_logic_s_cla24_pg_logic16_out(.a(a[16]), .b(b[16]), .pg_logic_or0(s_cla24_pg_logic16_or0), .pg_logic_and0(s_cla24_pg_logic16_and0), .pg_logic_xor0(s_cla24_pg_logic16_xor0));
  xor_gate xor_gate_s_cla24_xor16(.a(s_cla24_pg_logic16_xor0[0]), .b(s_cla24_or35[0]), .out(s_cla24_xor16));
  and_gate and_gate_s_cla24_and72(.a(s_cla24_or35[0]), .b(s_cla24_pg_logic16_or0[0]), .out(s_cla24_and72));
  or_gate or_gate_s_cla24_or36(.a(s_cla24_pg_logic16_and0[0]), .b(s_cla24_and72[0]), .out(s_cla24_or36));
  pg_logic pg_logic_s_cla24_pg_logic17_out(.a(a[17]), .b(b[17]), .pg_logic_or0(s_cla24_pg_logic17_or0), .pg_logic_and0(s_cla24_pg_logic17_and0), .pg_logic_xor0(s_cla24_pg_logic17_xor0));
  xor_gate xor_gate_s_cla24_xor17(.a(s_cla24_pg_logic17_xor0[0]), .b(s_cla24_or36[0]), .out(s_cla24_xor17));
  and_gate and_gate_s_cla24_and73(.a(s_cla24_or35[0]), .b(s_cla24_pg_logic17_or0[0]), .out(s_cla24_and73));
  and_gate and_gate_s_cla24_and74(.a(s_cla24_and73[0]), .b(s_cla24_pg_logic16_or0[0]), .out(s_cla24_and74));
  and_gate and_gate_s_cla24_and75(.a(s_cla24_pg_logic16_and0[0]), .b(s_cla24_pg_logic17_or0[0]), .out(s_cla24_and75));
  or_gate or_gate_s_cla24_or37(.a(s_cla24_and74[0]), .b(s_cla24_and75[0]), .out(s_cla24_or37));
  or_gate or_gate_s_cla24_or38(.a(s_cla24_pg_logic17_and0[0]), .b(s_cla24_or37[0]), .out(s_cla24_or38));
  pg_logic pg_logic_s_cla24_pg_logic18_out(.a(a[18]), .b(b[18]), .pg_logic_or0(s_cla24_pg_logic18_or0), .pg_logic_and0(s_cla24_pg_logic18_and0), .pg_logic_xor0(s_cla24_pg_logic18_xor0));
  xor_gate xor_gate_s_cla24_xor18(.a(s_cla24_pg_logic18_xor0[0]), .b(s_cla24_or38[0]), .out(s_cla24_xor18));
  and_gate and_gate_s_cla24_and76(.a(s_cla24_or35[0]), .b(s_cla24_pg_logic17_or0[0]), .out(s_cla24_and76));
  and_gate and_gate_s_cla24_and77(.a(s_cla24_pg_logic18_or0[0]), .b(s_cla24_pg_logic16_or0[0]), .out(s_cla24_and77));
  and_gate and_gate_s_cla24_and78(.a(s_cla24_and76[0]), .b(s_cla24_and77[0]), .out(s_cla24_and78));
  and_gate and_gate_s_cla24_and79(.a(s_cla24_pg_logic16_and0[0]), .b(s_cla24_pg_logic18_or0[0]), .out(s_cla24_and79));
  and_gate and_gate_s_cla24_and80(.a(s_cla24_and79[0]), .b(s_cla24_pg_logic17_or0[0]), .out(s_cla24_and80));
  and_gate and_gate_s_cla24_and81(.a(s_cla24_pg_logic17_and0[0]), .b(s_cla24_pg_logic18_or0[0]), .out(s_cla24_and81));
  or_gate or_gate_s_cla24_or39(.a(s_cla24_and78[0]), .b(s_cla24_and80[0]), .out(s_cla24_or39));
  or_gate or_gate_s_cla24_or40(.a(s_cla24_or39[0]), .b(s_cla24_and81[0]), .out(s_cla24_or40));
  or_gate or_gate_s_cla24_or41(.a(s_cla24_pg_logic18_and0[0]), .b(s_cla24_or40[0]), .out(s_cla24_or41));
  pg_logic pg_logic_s_cla24_pg_logic19_out(.a(a[19]), .b(b[19]), .pg_logic_or0(s_cla24_pg_logic19_or0), .pg_logic_and0(s_cla24_pg_logic19_and0), .pg_logic_xor0(s_cla24_pg_logic19_xor0));
  xor_gate xor_gate_s_cla24_xor19(.a(s_cla24_pg_logic19_xor0[0]), .b(s_cla24_or41[0]), .out(s_cla24_xor19));
  and_gate and_gate_s_cla24_and82(.a(s_cla24_or35[0]), .b(s_cla24_pg_logic18_or0[0]), .out(s_cla24_and82));
  and_gate and_gate_s_cla24_and83(.a(s_cla24_pg_logic19_or0[0]), .b(s_cla24_pg_logic17_or0[0]), .out(s_cla24_and83));
  and_gate and_gate_s_cla24_and84(.a(s_cla24_and82[0]), .b(s_cla24_and83[0]), .out(s_cla24_and84));
  and_gate and_gate_s_cla24_and85(.a(s_cla24_and84[0]), .b(s_cla24_pg_logic16_or0[0]), .out(s_cla24_and85));
  and_gate and_gate_s_cla24_and86(.a(s_cla24_pg_logic16_and0[0]), .b(s_cla24_pg_logic18_or0[0]), .out(s_cla24_and86));
  and_gate and_gate_s_cla24_and87(.a(s_cla24_pg_logic19_or0[0]), .b(s_cla24_pg_logic17_or0[0]), .out(s_cla24_and87));
  and_gate and_gate_s_cla24_and88(.a(s_cla24_and86[0]), .b(s_cla24_and87[0]), .out(s_cla24_and88));
  and_gate and_gate_s_cla24_and89(.a(s_cla24_pg_logic17_and0[0]), .b(s_cla24_pg_logic19_or0[0]), .out(s_cla24_and89));
  and_gate and_gate_s_cla24_and90(.a(s_cla24_and89[0]), .b(s_cla24_pg_logic18_or0[0]), .out(s_cla24_and90));
  and_gate and_gate_s_cla24_and91(.a(s_cla24_pg_logic18_and0[0]), .b(s_cla24_pg_logic19_or0[0]), .out(s_cla24_and91));
  or_gate or_gate_s_cla24_or42(.a(s_cla24_and85[0]), .b(s_cla24_and90[0]), .out(s_cla24_or42));
  or_gate or_gate_s_cla24_or43(.a(s_cla24_and88[0]), .b(s_cla24_and91[0]), .out(s_cla24_or43));
  or_gate or_gate_s_cla24_or44(.a(s_cla24_or42[0]), .b(s_cla24_or43[0]), .out(s_cla24_or44));
  or_gate or_gate_s_cla24_or45(.a(s_cla24_pg_logic19_and0[0]), .b(s_cla24_or44[0]), .out(s_cla24_or45));
  pg_logic pg_logic_s_cla24_pg_logic20_out(.a(a[20]), .b(b[20]), .pg_logic_or0(s_cla24_pg_logic20_or0), .pg_logic_and0(s_cla24_pg_logic20_and0), .pg_logic_xor0(s_cla24_pg_logic20_xor0));
  xor_gate xor_gate_s_cla24_xor20(.a(s_cla24_pg_logic20_xor0[0]), .b(s_cla24_or45[0]), .out(s_cla24_xor20));
  and_gate and_gate_s_cla24_and92(.a(s_cla24_or45[0]), .b(s_cla24_pg_logic20_or0[0]), .out(s_cla24_and92));
  or_gate or_gate_s_cla24_or46(.a(s_cla24_pg_logic20_and0[0]), .b(s_cla24_and92[0]), .out(s_cla24_or46));
  pg_logic pg_logic_s_cla24_pg_logic21_out(.a(a[21]), .b(b[21]), .pg_logic_or0(s_cla24_pg_logic21_or0), .pg_logic_and0(s_cla24_pg_logic21_and0), .pg_logic_xor0(s_cla24_pg_logic21_xor0));
  xor_gate xor_gate_s_cla24_xor21(.a(s_cla24_pg_logic21_xor0[0]), .b(s_cla24_or46[0]), .out(s_cla24_xor21));
  and_gate and_gate_s_cla24_and93(.a(s_cla24_or45[0]), .b(s_cla24_pg_logic21_or0[0]), .out(s_cla24_and93));
  and_gate and_gate_s_cla24_and94(.a(s_cla24_and93[0]), .b(s_cla24_pg_logic20_or0[0]), .out(s_cla24_and94));
  and_gate and_gate_s_cla24_and95(.a(s_cla24_pg_logic20_and0[0]), .b(s_cla24_pg_logic21_or0[0]), .out(s_cla24_and95));
  or_gate or_gate_s_cla24_or47(.a(s_cla24_and94[0]), .b(s_cla24_and95[0]), .out(s_cla24_or47));
  or_gate or_gate_s_cla24_or48(.a(s_cla24_pg_logic21_and0[0]), .b(s_cla24_or47[0]), .out(s_cla24_or48));
  pg_logic pg_logic_s_cla24_pg_logic22_out(.a(a[22]), .b(b[22]), .pg_logic_or0(s_cla24_pg_logic22_or0), .pg_logic_and0(s_cla24_pg_logic22_and0), .pg_logic_xor0(s_cla24_pg_logic22_xor0));
  xor_gate xor_gate_s_cla24_xor22(.a(s_cla24_pg_logic22_xor0[0]), .b(s_cla24_or48[0]), .out(s_cla24_xor22));
  and_gate and_gate_s_cla24_and96(.a(s_cla24_or45[0]), .b(s_cla24_pg_logic21_or0[0]), .out(s_cla24_and96));
  and_gate and_gate_s_cla24_and97(.a(s_cla24_pg_logic22_or0[0]), .b(s_cla24_pg_logic20_or0[0]), .out(s_cla24_and97));
  and_gate and_gate_s_cla24_and98(.a(s_cla24_and96[0]), .b(s_cla24_and97[0]), .out(s_cla24_and98));
  and_gate and_gate_s_cla24_and99(.a(s_cla24_pg_logic20_and0[0]), .b(s_cla24_pg_logic22_or0[0]), .out(s_cla24_and99));
  and_gate and_gate_s_cla24_and100(.a(s_cla24_and99[0]), .b(s_cla24_pg_logic21_or0[0]), .out(s_cla24_and100));
  and_gate and_gate_s_cla24_and101(.a(s_cla24_pg_logic21_and0[0]), .b(s_cla24_pg_logic22_or0[0]), .out(s_cla24_and101));
  or_gate or_gate_s_cla24_or49(.a(s_cla24_and98[0]), .b(s_cla24_and100[0]), .out(s_cla24_or49));
  or_gate or_gate_s_cla24_or50(.a(s_cla24_or49[0]), .b(s_cla24_and101[0]), .out(s_cla24_or50));
  or_gate or_gate_s_cla24_or51(.a(s_cla24_pg_logic22_and0[0]), .b(s_cla24_or50[0]), .out(s_cla24_or51));
  pg_logic pg_logic_s_cla24_pg_logic23_out(.a(a[23]), .b(b[23]), .pg_logic_or0(s_cla24_pg_logic23_or0), .pg_logic_and0(s_cla24_pg_logic23_and0), .pg_logic_xor0(s_cla24_pg_logic23_xor0));
  xor_gate xor_gate_s_cla24_xor23(.a(s_cla24_pg_logic23_xor0[0]), .b(s_cla24_or51[0]), .out(s_cla24_xor23));
  and_gate and_gate_s_cla24_and102(.a(s_cla24_or45[0]), .b(s_cla24_pg_logic22_or0[0]), .out(s_cla24_and102));
  and_gate and_gate_s_cla24_and103(.a(s_cla24_pg_logic23_or0[0]), .b(s_cla24_pg_logic21_or0[0]), .out(s_cla24_and103));
  and_gate and_gate_s_cla24_and104(.a(s_cla24_and102[0]), .b(s_cla24_and103[0]), .out(s_cla24_and104));
  and_gate and_gate_s_cla24_and105(.a(s_cla24_and104[0]), .b(s_cla24_pg_logic20_or0[0]), .out(s_cla24_and105));
  and_gate and_gate_s_cla24_and106(.a(s_cla24_pg_logic20_and0[0]), .b(s_cla24_pg_logic22_or0[0]), .out(s_cla24_and106));
  and_gate and_gate_s_cla24_and107(.a(s_cla24_pg_logic23_or0[0]), .b(s_cla24_pg_logic21_or0[0]), .out(s_cla24_and107));
  and_gate and_gate_s_cla24_and108(.a(s_cla24_and106[0]), .b(s_cla24_and107[0]), .out(s_cla24_and108));
  and_gate and_gate_s_cla24_and109(.a(s_cla24_pg_logic21_and0[0]), .b(s_cla24_pg_logic23_or0[0]), .out(s_cla24_and109));
  and_gate and_gate_s_cla24_and110(.a(s_cla24_and109[0]), .b(s_cla24_pg_logic22_or0[0]), .out(s_cla24_and110));
  and_gate and_gate_s_cla24_and111(.a(s_cla24_pg_logic22_and0[0]), .b(s_cla24_pg_logic23_or0[0]), .out(s_cla24_and111));
  or_gate or_gate_s_cla24_or52(.a(s_cla24_and105[0]), .b(s_cla24_and110[0]), .out(s_cla24_or52));
  or_gate or_gate_s_cla24_or53(.a(s_cla24_and108[0]), .b(s_cla24_and111[0]), .out(s_cla24_or53));
  or_gate or_gate_s_cla24_or54(.a(s_cla24_or52[0]), .b(s_cla24_or53[0]), .out(s_cla24_or54));
  or_gate or_gate_s_cla24_or55(.a(s_cla24_pg_logic23_and0[0]), .b(s_cla24_or54[0]), .out(s_cla24_or55));
  xor_gate xor_gate_s_cla24_xor24(.a(a[23]), .b(b[23]), .out(s_cla24_xor24));
  xor_gate xor_gate_s_cla24_xor25(.a(s_cla24_xor24[0]), .b(s_cla24_or55[0]), .out(s_cla24_xor25));

  assign s_cla24_out[0] = s_cla24_pg_logic0_xor0[0];
  assign s_cla24_out[1] = s_cla24_xor1[0];
  assign s_cla24_out[2] = s_cla24_xor2[0];
  assign s_cla24_out[3] = s_cla24_xor3[0];
  assign s_cla24_out[4] = s_cla24_xor4[0];
  assign s_cla24_out[5] = s_cla24_xor5[0];
  assign s_cla24_out[6] = s_cla24_xor6[0];
  assign s_cla24_out[7] = s_cla24_xor7[0];
  assign s_cla24_out[8] = s_cla24_xor8[0];
  assign s_cla24_out[9] = s_cla24_xor9[0];
  assign s_cla24_out[10] = s_cla24_xor10[0];
  assign s_cla24_out[11] = s_cla24_xor11[0];
  assign s_cla24_out[12] = s_cla24_xor12[0];
  assign s_cla24_out[13] = s_cla24_xor13[0];
  assign s_cla24_out[14] = s_cla24_xor14[0];
  assign s_cla24_out[15] = s_cla24_xor15[0];
  assign s_cla24_out[16] = s_cla24_xor16[0];
  assign s_cla24_out[17] = s_cla24_xor17[0];
  assign s_cla24_out[18] = s_cla24_xor18[0];
  assign s_cla24_out[19] = s_cla24_xor19[0];
  assign s_cla24_out[20] = s_cla24_xor20[0];
  assign s_cla24_out[21] = s_cla24_xor21[0];
  assign s_cla24_out[22] = s_cla24_xor22[0];
  assign s_cla24_out[23] = s_cla24_xor23[0];
  assign s_cla24_out[24] = s_cla24_xor25[0];
endmodule