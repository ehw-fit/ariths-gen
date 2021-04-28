module f_u_dadda_cla4(input [3:0] a, input [3:0] b, output [7:0] f_u_dadda_cla4_out);
  wire f_u_dadda_cla4_and_3_0;
  wire f_u_dadda_cla4_and_2_1;
  wire f_u_dadda_cla4_ha0_xor0;
  wire f_u_dadda_cla4_ha0_and0;
  wire f_u_dadda_cla4_and_3_1;
  wire f_u_dadda_cla4_ha1_xor0;
  wire f_u_dadda_cla4_ha1_and0;
  wire f_u_dadda_cla4_and_2_0;
  wire f_u_dadda_cla4_and_1_1;
  wire f_u_dadda_cla4_ha2_xor0;
  wire f_u_dadda_cla4_ha2_and0;
  wire f_u_dadda_cla4_and_1_2;
  wire f_u_dadda_cla4_and_0_3;
  wire f_u_dadda_cla4_fa0_xor0;
  wire f_u_dadda_cla4_fa0_and0;
  wire f_u_dadda_cla4_fa0_xor1;
  wire f_u_dadda_cla4_fa0_and1;
  wire f_u_dadda_cla4_fa0_or0;
  wire f_u_dadda_cla4_and_2_2;
  wire f_u_dadda_cla4_and_1_3;
  wire f_u_dadda_cla4_fa1_xor0;
  wire f_u_dadda_cla4_fa1_and0;
  wire f_u_dadda_cla4_fa1_xor1;
  wire f_u_dadda_cla4_fa1_and1;
  wire f_u_dadda_cla4_fa1_or0;
  wire f_u_dadda_cla4_and_3_2;
  wire f_u_dadda_cla4_fa2_xor0;
  wire f_u_dadda_cla4_fa2_and0;
  wire f_u_dadda_cla4_fa2_xor1;
  wire f_u_dadda_cla4_fa2_and1;
  wire f_u_dadda_cla4_fa2_or0;
  wire f_u_dadda_cla4_and_0_0;
  wire f_u_dadda_cla4_and_1_0;
  wire f_u_dadda_cla4_and_0_2;
  wire f_u_dadda_cla4_and_2_3;
  wire f_u_dadda_cla4_and_0_1;
  wire f_u_dadda_cla4_and_3_3;
  wire f_u_dadda_cla4_u_cla6_pg_logic0_or0;
  wire f_u_dadda_cla4_u_cla6_pg_logic0_and0;
  wire f_u_dadda_cla4_u_cla6_pg_logic0_xor0;
  wire f_u_dadda_cla4_u_cla6_pg_logic1_or0;
  wire f_u_dadda_cla4_u_cla6_pg_logic1_and0;
  wire f_u_dadda_cla4_u_cla6_pg_logic1_xor0;
  wire f_u_dadda_cla4_u_cla6_xor1;
  wire f_u_dadda_cla4_u_cla6_and0;
  wire f_u_dadda_cla4_u_cla6_or0;
  wire f_u_dadda_cla4_u_cla6_pg_logic2_or0;
  wire f_u_dadda_cla4_u_cla6_pg_logic2_and0;
  wire f_u_dadda_cla4_u_cla6_pg_logic2_xor0;
  wire f_u_dadda_cla4_u_cla6_xor2;
  wire f_u_dadda_cla4_u_cla6_and1;
  wire f_u_dadda_cla4_u_cla6_and2;
  wire f_u_dadda_cla4_u_cla6_and3;
  wire f_u_dadda_cla4_u_cla6_and4;
  wire f_u_dadda_cla4_u_cla6_or1;
  wire f_u_dadda_cla4_u_cla6_or2;
  wire f_u_dadda_cla4_u_cla6_pg_logic3_or0;
  wire f_u_dadda_cla4_u_cla6_pg_logic3_and0;
  wire f_u_dadda_cla4_u_cla6_pg_logic3_xor0;
  wire f_u_dadda_cla4_u_cla6_xor3;
  wire f_u_dadda_cla4_u_cla6_and5;
  wire f_u_dadda_cla4_u_cla6_and6;
  wire f_u_dadda_cla4_u_cla6_and7;
  wire f_u_dadda_cla4_u_cla6_and8;
  wire f_u_dadda_cla4_u_cla6_and9;
  wire f_u_dadda_cla4_u_cla6_and10;
  wire f_u_dadda_cla4_u_cla6_and11;
  wire f_u_dadda_cla4_u_cla6_or3;
  wire f_u_dadda_cla4_u_cla6_or4;
  wire f_u_dadda_cla4_u_cla6_or5;
  wire f_u_dadda_cla4_u_cla6_pg_logic4_or0;
  wire f_u_dadda_cla4_u_cla6_pg_logic4_and0;
  wire f_u_dadda_cla4_u_cla6_pg_logic4_xor0;
  wire f_u_dadda_cla4_u_cla6_xor4;
  wire f_u_dadda_cla4_u_cla6_and12;
  wire f_u_dadda_cla4_u_cla6_or6;
  wire f_u_dadda_cla4_u_cla6_pg_logic5_or0;
  wire f_u_dadda_cla4_u_cla6_pg_logic5_and0;
  wire f_u_dadda_cla4_u_cla6_pg_logic5_xor0;
  wire f_u_dadda_cla4_u_cla6_xor5;
  wire f_u_dadda_cla4_u_cla6_and13;
  wire f_u_dadda_cla4_u_cla6_and14;
  wire f_u_dadda_cla4_u_cla6_and15;
  wire f_u_dadda_cla4_u_cla6_or7;
  wire f_u_dadda_cla4_u_cla6_or8;

  assign f_u_dadda_cla4_and_3_0 = a[3] & b[0];
  assign f_u_dadda_cla4_and_2_1 = a[2] & b[1];
  assign f_u_dadda_cla4_ha0_xor0 = f_u_dadda_cla4_and_3_0 ^ f_u_dadda_cla4_and_2_1;
  assign f_u_dadda_cla4_ha0_and0 = f_u_dadda_cla4_and_3_0 & f_u_dadda_cla4_and_2_1;
  assign f_u_dadda_cla4_and_3_1 = a[3] & b[1];
  assign f_u_dadda_cla4_ha1_xor0 = f_u_dadda_cla4_ha0_and0 ^ f_u_dadda_cla4_and_3_1;
  assign f_u_dadda_cla4_ha1_and0 = f_u_dadda_cla4_ha0_and0 & f_u_dadda_cla4_and_3_1;
  assign f_u_dadda_cla4_and_2_0 = a[2] & b[0];
  assign f_u_dadda_cla4_and_1_1 = a[1] & b[1];
  assign f_u_dadda_cla4_ha2_xor0 = f_u_dadda_cla4_and_2_0 ^ f_u_dadda_cla4_and_1_1;
  assign f_u_dadda_cla4_ha2_and0 = f_u_dadda_cla4_and_2_0 & f_u_dadda_cla4_and_1_1;
  assign f_u_dadda_cla4_and_1_2 = a[1] & b[2];
  assign f_u_dadda_cla4_and_0_3 = a[0] & b[3];
  assign f_u_dadda_cla4_fa0_xor0 = f_u_dadda_cla4_ha2_and0 ^ f_u_dadda_cla4_and_1_2;
  assign f_u_dadda_cla4_fa0_and0 = f_u_dadda_cla4_ha2_and0 & f_u_dadda_cla4_and_1_2;
  assign f_u_dadda_cla4_fa0_xor1 = f_u_dadda_cla4_fa0_xor0 ^ f_u_dadda_cla4_and_0_3;
  assign f_u_dadda_cla4_fa0_and1 = f_u_dadda_cla4_fa0_xor0 & f_u_dadda_cla4_and_0_3;
  assign f_u_dadda_cla4_fa0_or0 = f_u_dadda_cla4_fa0_and0 | f_u_dadda_cla4_fa0_and1;
  assign f_u_dadda_cla4_and_2_2 = a[2] & b[2];
  assign f_u_dadda_cla4_and_1_3 = a[1] & b[3];
  assign f_u_dadda_cla4_fa1_xor0 = f_u_dadda_cla4_fa0_or0 ^ f_u_dadda_cla4_and_2_2;
  assign f_u_dadda_cla4_fa1_and0 = f_u_dadda_cla4_fa0_or0 & f_u_dadda_cla4_and_2_2;
  assign f_u_dadda_cla4_fa1_xor1 = f_u_dadda_cla4_fa1_xor0 ^ f_u_dadda_cla4_and_1_3;
  assign f_u_dadda_cla4_fa1_and1 = f_u_dadda_cla4_fa1_xor0 & f_u_dadda_cla4_and_1_3;
  assign f_u_dadda_cla4_fa1_or0 = f_u_dadda_cla4_fa1_and0 | f_u_dadda_cla4_fa1_and1;
  assign f_u_dadda_cla4_and_3_2 = a[3] & b[2];
  assign f_u_dadda_cla4_fa2_xor0 = f_u_dadda_cla4_fa1_or0 ^ f_u_dadda_cla4_ha1_and0;
  assign f_u_dadda_cla4_fa2_and0 = f_u_dadda_cla4_fa1_or0 & f_u_dadda_cla4_ha1_and0;
  assign f_u_dadda_cla4_fa2_xor1 = f_u_dadda_cla4_fa2_xor0 ^ f_u_dadda_cla4_and_3_2;
  assign f_u_dadda_cla4_fa2_and1 = f_u_dadda_cla4_fa2_xor0 & f_u_dadda_cla4_and_3_2;
  assign f_u_dadda_cla4_fa2_or0 = f_u_dadda_cla4_fa2_and0 | f_u_dadda_cla4_fa2_and1;
  assign f_u_dadda_cla4_and_0_0 = a[0] & b[0];
  assign f_u_dadda_cla4_and_1_0 = a[1] & b[0];
  assign f_u_dadda_cla4_and_0_2 = a[0] & b[2];
  assign f_u_dadda_cla4_and_2_3 = a[2] & b[3];
  assign f_u_dadda_cla4_and_0_1 = a[0] & b[1];
  assign f_u_dadda_cla4_and_3_3 = a[3] & b[3];
  assign f_u_dadda_cla4_u_cla6_pg_logic0_or0 = f_u_dadda_cla4_and_1_0 | f_u_dadda_cla4_and_0_1;
  assign f_u_dadda_cla4_u_cla6_pg_logic0_and0 = f_u_dadda_cla4_and_1_0 & f_u_dadda_cla4_and_0_1;
  assign f_u_dadda_cla4_u_cla6_pg_logic0_xor0 = f_u_dadda_cla4_and_1_0 ^ f_u_dadda_cla4_and_0_1;
  assign f_u_dadda_cla4_u_cla6_pg_logic1_or0 = f_u_dadda_cla4_and_0_2 | f_u_dadda_cla4_ha2_xor0;
  assign f_u_dadda_cla4_u_cla6_pg_logic1_and0 = f_u_dadda_cla4_and_0_2 & f_u_dadda_cla4_ha2_xor0;
  assign f_u_dadda_cla4_u_cla6_pg_logic1_xor0 = f_u_dadda_cla4_and_0_2 ^ f_u_dadda_cla4_ha2_xor0;
  assign f_u_dadda_cla4_u_cla6_xor1 = f_u_dadda_cla4_u_cla6_pg_logic1_xor0 ^ f_u_dadda_cla4_u_cla6_pg_logic0_and0;
  assign f_u_dadda_cla4_u_cla6_and0 = f_u_dadda_cla4_u_cla6_pg_logic0_and0 & f_u_dadda_cla4_u_cla6_pg_logic1_or0;
  assign f_u_dadda_cla4_u_cla6_or0 = f_u_dadda_cla4_u_cla6_pg_logic1_and0 | f_u_dadda_cla4_u_cla6_and0;
  assign f_u_dadda_cla4_u_cla6_pg_logic2_or0 = f_u_dadda_cla4_ha0_xor0 | f_u_dadda_cla4_fa0_xor1;
  assign f_u_dadda_cla4_u_cla6_pg_logic2_and0 = f_u_dadda_cla4_ha0_xor0 & f_u_dadda_cla4_fa0_xor1;
  assign f_u_dadda_cla4_u_cla6_pg_logic2_xor0 = f_u_dadda_cla4_ha0_xor0 ^ f_u_dadda_cla4_fa0_xor1;
  assign f_u_dadda_cla4_u_cla6_xor2 = f_u_dadda_cla4_u_cla6_pg_logic2_xor0 ^ f_u_dadda_cla4_u_cla6_or0;
  assign f_u_dadda_cla4_u_cla6_and1 = f_u_dadda_cla4_u_cla6_pg_logic2_or0 & f_u_dadda_cla4_u_cla6_pg_logic0_or0;
  assign f_u_dadda_cla4_u_cla6_and2 = f_u_dadda_cla4_u_cla6_pg_logic0_and0 & f_u_dadda_cla4_u_cla6_pg_logic2_or0;
  assign f_u_dadda_cla4_u_cla6_and3 = f_u_dadda_cla4_u_cla6_and2 & f_u_dadda_cla4_u_cla6_pg_logic1_or0;
  assign f_u_dadda_cla4_u_cla6_and4 = f_u_dadda_cla4_u_cla6_pg_logic1_and0 & f_u_dadda_cla4_u_cla6_pg_logic2_or0;
  assign f_u_dadda_cla4_u_cla6_or1 = f_u_dadda_cla4_u_cla6_and3 | f_u_dadda_cla4_u_cla6_and4;
  assign f_u_dadda_cla4_u_cla6_or2 = f_u_dadda_cla4_u_cla6_pg_logic2_and0 | f_u_dadda_cla4_u_cla6_or1;
  assign f_u_dadda_cla4_u_cla6_pg_logic3_or0 = f_u_dadda_cla4_ha1_xor0 | f_u_dadda_cla4_fa1_xor1;
  assign f_u_dadda_cla4_u_cla6_pg_logic3_and0 = f_u_dadda_cla4_ha1_xor0 & f_u_dadda_cla4_fa1_xor1;
  assign f_u_dadda_cla4_u_cla6_pg_logic3_xor0 = f_u_dadda_cla4_ha1_xor0 ^ f_u_dadda_cla4_fa1_xor1;
  assign f_u_dadda_cla4_u_cla6_xor3 = f_u_dadda_cla4_u_cla6_pg_logic3_xor0 ^ f_u_dadda_cla4_u_cla6_or2;
  assign f_u_dadda_cla4_u_cla6_and5 = f_u_dadda_cla4_u_cla6_pg_logic3_or0 & f_u_dadda_cla4_u_cla6_pg_logic1_or0;
  assign f_u_dadda_cla4_u_cla6_and6 = f_u_dadda_cla4_u_cla6_pg_logic0_and0 & f_u_dadda_cla4_u_cla6_pg_logic2_or0;
  assign f_u_dadda_cla4_u_cla6_and7 = f_u_dadda_cla4_u_cla6_pg_logic3_or0 & f_u_dadda_cla4_u_cla6_pg_logic1_or0;
  assign f_u_dadda_cla4_u_cla6_and8 = f_u_dadda_cla4_u_cla6_and6 & f_u_dadda_cla4_u_cla6_and7;
  assign f_u_dadda_cla4_u_cla6_and9 = f_u_dadda_cla4_u_cla6_pg_logic1_and0 & f_u_dadda_cla4_u_cla6_pg_logic3_or0;
  assign f_u_dadda_cla4_u_cla6_and10 = f_u_dadda_cla4_u_cla6_and9 & f_u_dadda_cla4_u_cla6_pg_logic2_or0;
  assign f_u_dadda_cla4_u_cla6_and11 = f_u_dadda_cla4_u_cla6_pg_logic2_and0 & f_u_dadda_cla4_u_cla6_pg_logic3_or0;
  assign f_u_dadda_cla4_u_cla6_or3 = f_u_dadda_cla4_u_cla6_and8 | f_u_dadda_cla4_u_cla6_and11;
  assign f_u_dadda_cla4_u_cla6_or4 = f_u_dadda_cla4_u_cla6_and10 | f_u_dadda_cla4_u_cla6_or3;
  assign f_u_dadda_cla4_u_cla6_or5 = f_u_dadda_cla4_u_cla6_pg_logic3_and0 | f_u_dadda_cla4_u_cla6_or4;
  assign f_u_dadda_cla4_u_cla6_pg_logic4_or0 = f_u_dadda_cla4_and_2_3 | f_u_dadda_cla4_fa2_xor1;
  assign f_u_dadda_cla4_u_cla6_pg_logic4_and0 = f_u_dadda_cla4_and_2_3 & f_u_dadda_cla4_fa2_xor1;
  assign f_u_dadda_cla4_u_cla6_pg_logic4_xor0 = f_u_dadda_cla4_and_2_3 ^ f_u_dadda_cla4_fa2_xor1;
  assign f_u_dadda_cla4_u_cla6_xor4 = f_u_dadda_cla4_u_cla6_pg_logic4_xor0 ^ f_u_dadda_cla4_u_cla6_or5;
  assign f_u_dadda_cla4_u_cla6_and12 = f_u_dadda_cla4_u_cla6_or5 & f_u_dadda_cla4_u_cla6_pg_logic4_or0;
  assign f_u_dadda_cla4_u_cla6_or6 = f_u_dadda_cla4_u_cla6_pg_logic4_and0 | f_u_dadda_cla4_u_cla6_and12;
  assign f_u_dadda_cla4_u_cla6_pg_logic5_or0 = f_u_dadda_cla4_fa2_or0 | f_u_dadda_cla4_and_3_3;
  assign f_u_dadda_cla4_u_cla6_pg_logic5_and0 = f_u_dadda_cla4_fa2_or0 & f_u_dadda_cla4_and_3_3;
  assign f_u_dadda_cla4_u_cla6_pg_logic5_xor0 = f_u_dadda_cla4_fa2_or0 ^ f_u_dadda_cla4_and_3_3;
  assign f_u_dadda_cla4_u_cla6_xor5 = f_u_dadda_cla4_u_cla6_pg_logic5_xor0 ^ f_u_dadda_cla4_u_cla6_or6;
  assign f_u_dadda_cla4_u_cla6_and13 = f_u_dadda_cla4_u_cla6_or5 & f_u_dadda_cla4_u_cla6_pg_logic5_or0;
  assign f_u_dadda_cla4_u_cla6_and14 = f_u_dadda_cla4_u_cla6_and13 & f_u_dadda_cla4_u_cla6_pg_logic4_or0;
  assign f_u_dadda_cla4_u_cla6_and15 = f_u_dadda_cla4_u_cla6_pg_logic4_and0 & f_u_dadda_cla4_u_cla6_pg_logic5_or0;
  assign f_u_dadda_cla4_u_cla6_or7 = f_u_dadda_cla4_u_cla6_and14 | f_u_dadda_cla4_u_cla6_and15;
  assign f_u_dadda_cla4_u_cla6_or8 = f_u_dadda_cla4_u_cla6_pg_logic5_and0 | f_u_dadda_cla4_u_cla6_or7;

  assign f_u_dadda_cla4_out[0] = f_u_dadda_cla4_and_0_0;
  assign f_u_dadda_cla4_out[1] = f_u_dadda_cla4_u_cla6_pg_logic0_xor0;
  assign f_u_dadda_cla4_out[2] = f_u_dadda_cla4_u_cla6_xor1;
  assign f_u_dadda_cla4_out[3] = f_u_dadda_cla4_u_cla6_xor2;
  assign f_u_dadda_cla4_out[4] = f_u_dadda_cla4_u_cla6_xor3;
  assign f_u_dadda_cla4_out[5] = f_u_dadda_cla4_u_cla6_xor4;
  assign f_u_dadda_cla4_out[6] = f_u_dadda_cla4_u_cla6_xor5;
  assign f_u_dadda_cla4_out[7] = f_u_dadda_cla4_u_cla6_or8;
endmodule