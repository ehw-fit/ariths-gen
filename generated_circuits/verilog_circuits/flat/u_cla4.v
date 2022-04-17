module u_cla4(input [3:0] a, input [3:0] b, output [4:0] u_cla4_out);
  wire u_cla4_pg_logic0_or0;
  wire u_cla4_pg_logic0_and0;
  wire u_cla4_pg_logic0_xor0;
  wire u_cla4_pg_logic1_or0;
  wire u_cla4_pg_logic1_and0;
  wire u_cla4_pg_logic1_xor0;
  wire u_cla4_xor1;
  wire u_cla4_and0;
  wire u_cla4_or0;
  wire u_cla4_pg_logic2_or0;
  wire u_cla4_pg_logic2_and0;
  wire u_cla4_pg_logic2_xor0;
  wire u_cla4_xor2;
  wire u_cla4_and1;
  wire u_cla4_and2;
  wire u_cla4_and3;
  wire u_cla4_and4;
  wire u_cla4_or1;
  wire u_cla4_or2;
  wire u_cla4_pg_logic3_or0;
  wire u_cla4_pg_logic3_and0;
  wire u_cla4_pg_logic3_xor0;
  wire u_cla4_xor3;
  wire u_cla4_and5;
  wire u_cla4_and6;
  wire u_cla4_and7;
  wire u_cla4_and8;
  wire u_cla4_and9;
  wire u_cla4_and10;
  wire u_cla4_and11;
  wire u_cla4_or3;
  wire u_cla4_or4;
  wire u_cla4_or5;

  assign u_cla4_pg_logic0_or0 = a[0] | b[0];
  assign u_cla4_pg_logic0_and0 = a[0] & b[0];
  assign u_cla4_pg_logic0_xor0 = a[0] ^ b[0];
  assign u_cla4_pg_logic1_or0 = a[1] | b[1];
  assign u_cla4_pg_logic1_and0 = a[1] & b[1];
  assign u_cla4_pg_logic1_xor0 = a[1] ^ b[1];
  assign u_cla4_xor1 = u_cla4_pg_logic1_xor0 ^ u_cla4_pg_logic0_and0;
  assign u_cla4_and0 = u_cla4_pg_logic0_and0 & u_cla4_pg_logic1_or0;
  assign u_cla4_or0 = u_cla4_pg_logic1_and0 | u_cla4_and0;
  assign u_cla4_pg_logic2_or0 = a[2] | b[2];
  assign u_cla4_pg_logic2_and0 = a[2] & b[2];
  assign u_cla4_pg_logic2_xor0 = a[2] ^ b[2];
  assign u_cla4_xor2 = u_cla4_pg_logic2_xor0 ^ u_cla4_or0;
  assign u_cla4_and1 = u_cla4_pg_logic2_or0 & u_cla4_pg_logic0_or0;
  assign u_cla4_and2 = u_cla4_pg_logic0_and0 & u_cla4_pg_logic2_or0;
  assign u_cla4_and3 = u_cla4_and2 & u_cla4_pg_logic1_or0;
  assign u_cla4_and4 = u_cla4_pg_logic1_and0 & u_cla4_pg_logic2_or0;
  assign u_cla4_or1 = u_cla4_and3 | u_cla4_and4;
  assign u_cla4_or2 = u_cla4_pg_logic2_and0 | u_cla4_or1;
  assign u_cla4_pg_logic3_or0 = a[3] | b[3];
  assign u_cla4_pg_logic3_and0 = a[3] & b[3];
  assign u_cla4_pg_logic3_xor0 = a[3] ^ b[3];
  assign u_cla4_xor3 = u_cla4_pg_logic3_xor0 ^ u_cla4_or2;
  assign u_cla4_and5 = u_cla4_pg_logic3_or0 & u_cla4_pg_logic1_or0;
  assign u_cla4_and6 = u_cla4_pg_logic0_and0 & u_cla4_pg_logic2_or0;
  assign u_cla4_and7 = u_cla4_pg_logic3_or0 & u_cla4_pg_logic1_or0;
  assign u_cla4_and8 = u_cla4_and6 & u_cla4_and7;
  assign u_cla4_and9 = u_cla4_pg_logic1_and0 & u_cla4_pg_logic3_or0;
  assign u_cla4_and10 = u_cla4_and9 & u_cla4_pg_logic2_or0;
  assign u_cla4_and11 = u_cla4_pg_logic2_and0 & u_cla4_pg_logic3_or0;
  assign u_cla4_or3 = u_cla4_and8 | u_cla4_and11;
  assign u_cla4_or4 = u_cla4_and10 | u_cla4_or3;
  assign u_cla4_or5 = u_cla4_pg_logic3_and0 | u_cla4_or4;

  assign u_cla4_out[0] = u_cla4_pg_logic0_xor0;
  assign u_cla4_out[1] = u_cla4_xor1;
  assign u_cla4_out[2] = u_cla4_xor2;
  assign u_cla4_out[3] = u_cla4_xor3;
  assign u_cla4_out[4] = u_cla4_or5;
endmodule