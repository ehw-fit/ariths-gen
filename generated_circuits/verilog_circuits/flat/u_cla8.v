module u_cla8(input [7:0] a, input [7:0] b, output [8:0] u_cla8_out);
  wire u_cla8_pg_logic0_or0;
  wire u_cla8_pg_logic0_and0;
  wire u_cla8_pg_logic0_xor0;
  wire u_cla8_pg_logic1_or0;
  wire u_cla8_pg_logic1_and0;
  wire u_cla8_pg_logic1_xor0;
  wire u_cla8_xor1;
  wire u_cla8_and0;
  wire u_cla8_or0;
  wire u_cla8_pg_logic2_or0;
  wire u_cla8_pg_logic2_and0;
  wire u_cla8_pg_logic2_xor0;
  wire u_cla8_xor2;
  wire u_cla8_and1;
  wire u_cla8_and2;
  wire u_cla8_and3;
  wire u_cla8_and4;
  wire u_cla8_or1;
  wire u_cla8_or2;
  wire u_cla8_pg_logic3_or0;
  wire u_cla8_pg_logic3_and0;
  wire u_cla8_pg_logic3_xor0;
  wire u_cla8_xor3;
  wire u_cla8_and5;
  wire u_cla8_and6;
  wire u_cla8_and7;
  wire u_cla8_and8;
  wire u_cla8_and9;
  wire u_cla8_and10;
  wire u_cla8_and11;
  wire u_cla8_or3;
  wire u_cla8_or4;
  wire u_cla8_or5;
  wire u_cla8_pg_logic4_or0;
  wire u_cla8_pg_logic4_and0;
  wire u_cla8_pg_logic4_xor0;
  wire u_cla8_xor4;
  wire u_cla8_and12;
  wire u_cla8_or6;
  wire u_cla8_pg_logic5_or0;
  wire u_cla8_pg_logic5_and0;
  wire u_cla8_pg_logic5_xor0;
  wire u_cla8_xor5;
  wire u_cla8_and13;
  wire u_cla8_and14;
  wire u_cla8_and15;
  wire u_cla8_or7;
  wire u_cla8_or8;
  wire u_cla8_pg_logic6_or0;
  wire u_cla8_pg_logic6_and0;
  wire u_cla8_pg_logic6_xor0;
  wire u_cla8_xor6;
  wire u_cla8_and16;
  wire u_cla8_and17;
  wire u_cla8_and18;
  wire u_cla8_and19;
  wire u_cla8_and20;
  wire u_cla8_and21;
  wire u_cla8_or9;
  wire u_cla8_or10;
  wire u_cla8_or11;
  wire u_cla8_pg_logic7_or0;
  wire u_cla8_pg_logic7_and0;
  wire u_cla8_pg_logic7_xor0;
  wire u_cla8_xor7;
  wire u_cla8_and22;
  wire u_cla8_and23;
  wire u_cla8_and24;
  wire u_cla8_and25;
  wire u_cla8_and26;
  wire u_cla8_and27;
  wire u_cla8_and28;
  wire u_cla8_and29;
  wire u_cla8_and30;
  wire u_cla8_and31;
  wire u_cla8_or12;
  wire u_cla8_or13;
  wire u_cla8_or14;
  wire u_cla8_or15;

  assign u_cla8_pg_logic0_or0 = a[0] | b[0];
  assign u_cla8_pg_logic0_and0 = a[0] & b[0];
  assign u_cla8_pg_logic0_xor0 = a[0] ^ b[0];
  assign u_cla8_pg_logic1_or0 = a[1] | b[1];
  assign u_cla8_pg_logic1_and0 = a[1] & b[1];
  assign u_cla8_pg_logic1_xor0 = a[1] ^ b[1];
  assign u_cla8_xor1 = u_cla8_pg_logic1_xor0 ^ u_cla8_pg_logic0_and0;
  assign u_cla8_and0 = u_cla8_pg_logic0_and0 & u_cla8_pg_logic1_or0;
  assign u_cla8_or0 = u_cla8_pg_logic1_and0 | u_cla8_and0;
  assign u_cla8_pg_logic2_or0 = a[2] | b[2];
  assign u_cla8_pg_logic2_and0 = a[2] & b[2];
  assign u_cla8_pg_logic2_xor0 = a[2] ^ b[2];
  assign u_cla8_xor2 = u_cla8_pg_logic2_xor0 ^ u_cla8_or0;
  assign u_cla8_and1 = u_cla8_pg_logic2_or0 & u_cla8_pg_logic0_or0;
  assign u_cla8_and2 = u_cla8_pg_logic0_and0 & u_cla8_pg_logic2_or0;
  assign u_cla8_and3 = u_cla8_and2 & u_cla8_pg_logic1_or0;
  assign u_cla8_and4 = u_cla8_pg_logic1_and0 & u_cla8_pg_logic2_or0;
  assign u_cla8_or1 = u_cla8_and3 | u_cla8_and4;
  assign u_cla8_or2 = u_cla8_pg_logic2_and0 | u_cla8_or1;
  assign u_cla8_pg_logic3_or0 = a[3] | b[3];
  assign u_cla8_pg_logic3_and0 = a[3] & b[3];
  assign u_cla8_pg_logic3_xor0 = a[3] ^ b[3];
  assign u_cla8_xor3 = u_cla8_pg_logic3_xor0 ^ u_cla8_or2;
  assign u_cla8_and5 = u_cla8_pg_logic3_or0 & u_cla8_pg_logic1_or0;
  assign u_cla8_and6 = u_cla8_pg_logic0_and0 & u_cla8_pg_logic2_or0;
  assign u_cla8_and7 = u_cla8_pg_logic3_or0 & u_cla8_pg_logic1_or0;
  assign u_cla8_and8 = u_cla8_and6 & u_cla8_and7;
  assign u_cla8_and9 = u_cla8_pg_logic1_and0 & u_cla8_pg_logic3_or0;
  assign u_cla8_and10 = u_cla8_and9 & u_cla8_pg_logic2_or0;
  assign u_cla8_and11 = u_cla8_pg_logic2_and0 & u_cla8_pg_logic3_or0;
  assign u_cla8_or3 = u_cla8_and8 | u_cla8_and11;
  assign u_cla8_or4 = u_cla8_and10 | u_cla8_or3;
  assign u_cla8_or5 = u_cla8_pg_logic3_and0 | u_cla8_or4;
  assign u_cla8_pg_logic4_or0 = a[4] | b[4];
  assign u_cla8_pg_logic4_and0 = a[4] & b[4];
  assign u_cla8_pg_logic4_xor0 = a[4] ^ b[4];
  assign u_cla8_xor4 = u_cla8_pg_logic4_xor0 ^ u_cla8_or5;
  assign u_cla8_and12 = u_cla8_or5 & u_cla8_pg_logic4_or0;
  assign u_cla8_or6 = u_cla8_pg_logic4_and0 | u_cla8_and12;
  assign u_cla8_pg_logic5_or0 = a[5] | b[5];
  assign u_cla8_pg_logic5_and0 = a[5] & b[5];
  assign u_cla8_pg_logic5_xor0 = a[5] ^ b[5];
  assign u_cla8_xor5 = u_cla8_pg_logic5_xor0 ^ u_cla8_or6;
  assign u_cla8_and13 = u_cla8_or5 & u_cla8_pg_logic5_or0;
  assign u_cla8_and14 = u_cla8_and13 & u_cla8_pg_logic4_or0;
  assign u_cla8_and15 = u_cla8_pg_logic4_and0 & u_cla8_pg_logic5_or0;
  assign u_cla8_or7 = u_cla8_and14 | u_cla8_and15;
  assign u_cla8_or8 = u_cla8_pg_logic5_and0 | u_cla8_or7;
  assign u_cla8_pg_logic6_or0 = a[6] | b[6];
  assign u_cla8_pg_logic6_and0 = a[6] & b[6];
  assign u_cla8_pg_logic6_xor0 = a[6] ^ b[6];
  assign u_cla8_xor6 = u_cla8_pg_logic6_xor0 ^ u_cla8_or8;
  assign u_cla8_and16 = u_cla8_or5 & u_cla8_pg_logic5_or0;
  assign u_cla8_and17 = u_cla8_pg_logic6_or0 & u_cla8_pg_logic4_or0;
  assign u_cla8_and18 = u_cla8_and16 & u_cla8_and17;
  assign u_cla8_and19 = u_cla8_pg_logic4_and0 & u_cla8_pg_logic6_or0;
  assign u_cla8_and20 = u_cla8_and19 & u_cla8_pg_logic5_or0;
  assign u_cla8_and21 = u_cla8_pg_logic5_and0 & u_cla8_pg_logic6_or0;
  assign u_cla8_or9 = u_cla8_and18 | u_cla8_and20;
  assign u_cla8_or10 = u_cla8_or9 | u_cla8_and21;
  assign u_cla8_or11 = u_cla8_pg_logic6_and0 | u_cla8_or10;
  assign u_cla8_pg_logic7_or0 = a[7] | b[7];
  assign u_cla8_pg_logic7_and0 = a[7] & b[7];
  assign u_cla8_pg_logic7_xor0 = a[7] ^ b[7];
  assign u_cla8_xor7 = u_cla8_pg_logic7_xor0 ^ u_cla8_or11;
  assign u_cla8_and22 = u_cla8_or5 & u_cla8_pg_logic6_or0;
  assign u_cla8_and23 = u_cla8_pg_logic7_or0 & u_cla8_pg_logic5_or0;
  assign u_cla8_and24 = u_cla8_and22 & u_cla8_and23;
  assign u_cla8_and25 = u_cla8_and24 & u_cla8_pg_logic4_or0;
  assign u_cla8_and26 = u_cla8_pg_logic4_and0 & u_cla8_pg_logic6_or0;
  assign u_cla8_and27 = u_cla8_pg_logic7_or0 & u_cla8_pg_logic5_or0;
  assign u_cla8_and28 = u_cla8_and26 & u_cla8_and27;
  assign u_cla8_and29 = u_cla8_pg_logic5_and0 & u_cla8_pg_logic7_or0;
  assign u_cla8_and30 = u_cla8_and29 & u_cla8_pg_logic6_or0;
  assign u_cla8_and31 = u_cla8_pg_logic6_and0 & u_cla8_pg_logic7_or0;
  assign u_cla8_or12 = u_cla8_and25 | u_cla8_and30;
  assign u_cla8_or13 = u_cla8_and28 | u_cla8_and31;
  assign u_cla8_or14 = u_cla8_or12 | u_cla8_or13;
  assign u_cla8_or15 = u_cla8_pg_logic7_and0 | u_cla8_or14;

  assign u_cla8_out[0] = u_cla8_pg_logic0_xor0;
  assign u_cla8_out[1] = u_cla8_xor1;
  assign u_cla8_out[2] = u_cla8_xor2;
  assign u_cla8_out[3] = u_cla8_xor3;
  assign u_cla8_out[4] = u_cla8_xor4;
  assign u_cla8_out[5] = u_cla8_xor5;
  assign u_cla8_out[6] = u_cla8_xor6;
  assign u_cla8_out[7] = u_cla8_xor7;
  assign u_cla8_out[8] = u_cla8_or15;
endmodule