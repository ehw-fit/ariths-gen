module s_dadda_cla4(input [3:0] a, input [3:0] b, output [7:0] s_dadda_cla4_out);
  wire s_dadda_cla4_nand_3_0;
  wire s_dadda_cla4_and_2_1;
  wire s_dadda_cla4_ha0_xor0;
  wire s_dadda_cla4_ha0_and0;
  wire s_dadda_cla4_nand_3_1;
  wire s_dadda_cla4_fa0_xor0;
  wire s_dadda_cla4_fa0_xor1;
  wire s_dadda_cla4_fa0_and1;
  wire s_dadda_cla4_fa0_or0;
  wire s_dadda_cla4_and_2_0;
  wire s_dadda_cla4_and_1_1;
  wire s_dadda_cla4_ha1_xor0;
  wire s_dadda_cla4_ha1_and0;
  wire s_dadda_cla4_and_1_2;
  wire s_dadda_cla4_nand_0_3;
  wire s_dadda_cla4_fa1_xor0;
  wire s_dadda_cla4_fa1_and0;
  wire s_dadda_cla4_fa1_xor1;
  wire s_dadda_cla4_fa1_and1;
  wire s_dadda_cla4_fa1_or0;
  wire s_dadda_cla4_and_2_2;
  wire s_dadda_cla4_nand_1_3;
  wire s_dadda_cla4_fa2_xor0;
  wire s_dadda_cla4_fa2_and0;
  wire s_dadda_cla4_fa2_xor1;
  wire s_dadda_cla4_fa2_and1;
  wire s_dadda_cla4_fa2_or0;
  wire s_dadda_cla4_nand_3_2;
  wire s_dadda_cla4_fa3_xor0;
  wire s_dadda_cla4_fa3_and0;
  wire s_dadda_cla4_fa3_xor1;
  wire s_dadda_cla4_fa3_and1;
  wire s_dadda_cla4_fa3_or0;
  wire s_dadda_cla4_and_0_0;
  wire s_dadda_cla4_and_1_0;
  wire s_dadda_cla4_and_0_2;
  wire s_dadda_cla4_nand_2_3;
  wire s_dadda_cla4_and_0_1;
  wire s_dadda_cla4_and_3_3;
  wire s_dadda_cla4_u_cla6_pg_logic0_or0;
  wire s_dadda_cla4_u_cla6_pg_logic0_and0;
  wire s_dadda_cla4_u_cla6_pg_logic0_xor0;
  wire s_dadda_cla4_u_cla6_pg_logic1_or0;
  wire s_dadda_cla4_u_cla6_pg_logic1_and0;
  wire s_dadda_cla4_u_cla6_pg_logic1_xor0;
  wire s_dadda_cla4_u_cla6_xor1;
  wire s_dadda_cla4_u_cla6_and0;
  wire s_dadda_cla4_u_cla6_or0;
  wire s_dadda_cla4_u_cla6_pg_logic2_or0;
  wire s_dadda_cla4_u_cla6_pg_logic2_and0;
  wire s_dadda_cla4_u_cla6_pg_logic2_xor0;
  wire s_dadda_cla4_u_cla6_xor2;
  wire s_dadda_cla4_u_cla6_and1;
  wire s_dadda_cla4_u_cla6_and2;
  wire s_dadda_cla4_u_cla6_and3;
  wire s_dadda_cla4_u_cla6_and4;
  wire s_dadda_cla4_u_cla6_or1;
  wire s_dadda_cla4_u_cla6_or2;
  wire s_dadda_cla4_u_cla6_pg_logic3_or0;
  wire s_dadda_cla4_u_cla6_pg_logic3_and0;
  wire s_dadda_cla4_u_cla6_pg_logic3_xor0;
  wire s_dadda_cla4_u_cla6_xor3;
  wire s_dadda_cla4_u_cla6_and5;
  wire s_dadda_cla4_u_cla6_and6;
  wire s_dadda_cla4_u_cla6_and7;
  wire s_dadda_cla4_u_cla6_and8;
  wire s_dadda_cla4_u_cla6_and9;
  wire s_dadda_cla4_u_cla6_and10;
  wire s_dadda_cla4_u_cla6_and11;
  wire s_dadda_cla4_u_cla6_or3;
  wire s_dadda_cla4_u_cla6_or4;
  wire s_dadda_cla4_u_cla6_or5;
  wire s_dadda_cla4_u_cla6_pg_logic4_or0;
  wire s_dadda_cla4_u_cla6_pg_logic4_and0;
  wire s_dadda_cla4_u_cla6_pg_logic4_xor0;
  wire s_dadda_cla4_u_cla6_xor4;
  wire s_dadda_cla4_u_cla6_and12;
  wire s_dadda_cla4_u_cla6_or6;
  wire s_dadda_cla4_u_cla6_pg_logic5_or0;
  wire s_dadda_cla4_u_cla6_pg_logic5_and0;
  wire s_dadda_cla4_u_cla6_pg_logic5_xor0;
  wire s_dadda_cla4_u_cla6_xor5;
  wire s_dadda_cla4_u_cla6_and13;
  wire s_dadda_cla4_u_cla6_and14;
  wire s_dadda_cla4_u_cla6_and15;
  wire s_dadda_cla4_u_cla6_or7;
  wire s_dadda_cla4_u_cla6_or8;
  wire s_dadda_cla4_xor0;

  assign s_dadda_cla4_nand_3_0 = ~(a[3] & b[0]);
  assign s_dadda_cla4_and_2_1 = a[2] & b[1];
  assign s_dadda_cla4_ha0_xor0 = s_dadda_cla4_nand_3_0 ^ s_dadda_cla4_and_2_1;
  assign s_dadda_cla4_ha0_and0 = s_dadda_cla4_nand_3_0 & s_dadda_cla4_and_2_1;
  assign s_dadda_cla4_nand_3_1 = ~(a[3] & b[1]);
  assign s_dadda_cla4_fa0_xor0 = ~s_dadda_cla4_ha0_and0;
  assign s_dadda_cla4_fa0_xor1 = s_dadda_cla4_fa0_xor0 ^ s_dadda_cla4_nand_3_1;
  assign s_dadda_cla4_fa0_and1 = s_dadda_cla4_fa0_xor0 & s_dadda_cla4_nand_3_1;
  assign s_dadda_cla4_fa0_or0 = s_dadda_cla4_ha0_and0 | s_dadda_cla4_fa0_and1;
  assign s_dadda_cla4_and_2_0 = a[2] & b[0];
  assign s_dadda_cla4_and_1_1 = a[1] & b[1];
  assign s_dadda_cla4_ha1_xor0 = s_dadda_cla4_and_2_0 ^ s_dadda_cla4_and_1_1;
  assign s_dadda_cla4_ha1_and0 = s_dadda_cla4_and_2_0 & s_dadda_cla4_and_1_1;
  assign s_dadda_cla4_and_1_2 = a[1] & b[2];
  assign s_dadda_cla4_nand_0_3 = ~(a[0] & b[3]);
  assign s_dadda_cla4_fa1_xor0 = s_dadda_cla4_ha1_and0 ^ s_dadda_cla4_and_1_2;
  assign s_dadda_cla4_fa1_and0 = s_dadda_cla4_ha1_and0 & s_dadda_cla4_and_1_2;
  assign s_dadda_cla4_fa1_xor1 = s_dadda_cla4_fa1_xor0 ^ s_dadda_cla4_nand_0_3;
  assign s_dadda_cla4_fa1_and1 = s_dadda_cla4_fa1_xor0 & s_dadda_cla4_nand_0_3;
  assign s_dadda_cla4_fa1_or0 = s_dadda_cla4_fa1_and0 | s_dadda_cla4_fa1_and1;
  assign s_dadda_cla4_and_2_2 = a[2] & b[2];
  assign s_dadda_cla4_nand_1_3 = ~(a[1] & b[3]);
  assign s_dadda_cla4_fa2_xor0 = s_dadda_cla4_fa1_or0 ^ s_dadda_cla4_and_2_2;
  assign s_dadda_cla4_fa2_and0 = s_dadda_cla4_fa1_or0 & s_dadda_cla4_and_2_2;
  assign s_dadda_cla4_fa2_xor1 = s_dadda_cla4_fa2_xor0 ^ s_dadda_cla4_nand_1_3;
  assign s_dadda_cla4_fa2_and1 = s_dadda_cla4_fa2_xor0 & s_dadda_cla4_nand_1_3;
  assign s_dadda_cla4_fa2_or0 = s_dadda_cla4_fa2_and0 | s_dadda_cla4_fa2_and1;
  assign s_dadda_cla4_nand_3_2 = ~(a[3] & b[2]);
  assign s_dadda_cla4_fa3_xor0 = s_dadda_cla4_fa2_or0 ^ s_dadda_cla4_fa0_or0;
  assign s_dadda_cla4_fa3_and0 = s_dadda_cla4_fa2_or0 & s_dadda_cla4_fa0_or0;
  assign s_dadda_cla4_fa3_xor1 = s_dadda_cla4_fa3_xor0 ^ s_dadda_cla4_nand_3_2;
  assign s_dadda_cla4_fa3_and1 = s_dadda_cla4_fa3_xor0 & s_dadda_cla4_nand_3_2;
  assign s_dadda_cla4_fa3_or0 = s_dadda_cla4_fa3_and0 | s_dadda_cla4_fa3_and1;
  assign s_dadda_cla4_and_0_0 = a[0] & b[0];
  assign s_dadda_cla4_and_1_0 = a[1] & b[0];
  assign s_dadda_cla4_and_0_2 = a[0] & b[2];
  assign s_dadda_cla4_nand_2_3 = ~(a[2] & b[3]);
  assign s_dadda_cla4_and_0_1 = a[0] & b[1];
  assign s_dadda_cla4_and_3_3 = a[3] & b[3];
  assign s_dadda_cla4_u_cla6_pg_logic0_or0 = s_dadda_cla4_and_1_0 | s_dadda_cla4_and_0_1;
  assign s_dadda_cla4_u_cla6_pg_logic0_and0 = s_dadda_cla4_and_1_0 & s_dadda_cla4_and_0_1;
  assign s_dadda_cla4_u_cla6_pg_logic0_xor0 = s_dadda_cla4_and_1_0 ^ s_dadda_cla4_and_0_1;
  assign s_dadda_cla4_u_cla6_pg_logic1_or0 = s_dadda_cla4_and_0_2 | s_dadda_cla4_ha1_xor0;
  assign s_dadda_cla4_u_cla6_pg_logic1_and0 = s_dadda_cla4_and_0_2 & s_dadda_cla4_ha1_xor0;
  assign s_dadda_cla4_u_cla6_pg_logic1_xor0 = s_dadda_cla4_and_0_2 ^ s_dadda_cla4_ha1_xor0;
  assign s_dadda_cla4_u_cla6_xor1 = s_dadda_cla4_u_cla6_pg_logic1_xor0 ^ s_dadda_cla4_u_cla6_pg_logic0_and0;
  assign s_dadda_cla4_u_cla6_and0 = s_dadda_cla4_u_cla6_pg_logic0_and0 & s_dadda_cla4_u_cla6_pg_logic1_or0;
  assign s_dadda_cla4_u_cla6_or0 = s_dadda_cla4_u_cla6_pg_logic1_and0 | s_dadda_cla4_u_cla6_and0;
  assign s_dadda_cla4_u_cla6_pg_logic2_or0 = s_dadda_cla4_ha0_xor0 | s_dadda_cla4_fa1_xor1;
  assign s_dadda_cla4_u_cla6_pg_logic2_and0 = s_dadda_cla4_ha0_xor0 & s_dadda_cla4_fa1_xor1;
  assign s_dadda_cla4_u_cla6_pg_logic2_xor0 = s_dadda_cla4_ha0_xor0 ^ s_dadda_cla4_fa1_xor1;
  assign s_dadda_cla4_u_cla6_xor2 = s_dadda_cla4_u_cla6_pg_logic2_xor0 ^ s_dadda_cla4_u_cla6_or0;
  assign s_dadda_cla4_u_cla6_and1 = s_dadda_cla4_u_cla6_pg_logic2_or0 & s_dadda_cla4_u_cla6_pg_logic0_or0;
  assign s_dadda_cla4_u_cla6_and2 = s_dadda_cla4_u_cla6_pg_logic0_and0 & s_dadda_cla4_u_cla6_pg_logic2_or0;
  assign s_dadda_cla4_u_cla6_and3 = s_dadda_cla4_u_cla6_and2 & s_dadda_cla4_u_cla6_pg_logic1_or0;
  assign s_dadda_cla4_u_cla6_and4 = s_dadda_cla4_u_cla6_pg_logic1_and0 & s_dadda_cla4_u_cla6_pg_logic2_or0;
  assign s_dadda_cla4_u_cla6_or1 = s_dadda_cla4_u_cla6_and3 | s_dadda_cla4_u_cla6_and4;
  assign s_dadda_cla4_u_cla6_or2 = s_dadda_cla4_u_cla6_pg_logic2_and0 | s_dadda_cla4_u_cla6_or1;
  assign s_dadda_cla4_u_cla6_pg_logic3_or0 = s_dadda_cla4_fa0_xor1 | s_dadda_cla4_fa2_xor1;
  assign s_dadda_cla4_u_cla6_pg_logic3_and0 = s_dadda_cla4_fa0_xor1 & s_dadda_cla4_fa2_xor1;
  assign s_dadda_cla4_u_cla6_pg_logic3_xor0 = s_dadda_cla4_fa0_xor1 ^ s_dadda_cla4_fa2_xor1;
  assign s_dadda_cla4_u_cla6_xor3 = s_dadda_cla4_u_cla6_pg_logic3_xor0 ^ s_dadda_cla4_u_cla6_or2;
  assign s_dadda_cla4_u_cla6_and5 = s_dadda_cla4_u_cla6_pg_logic3_or0 & s_dadda_cla4_u_cla6_pg_logic1_or0;
  assign s_dadda_cla4_u_cla6_and6 = s_dadda_cla4_u_cla6_pg_logic0_and0 & s_dadda_cla4_u_cla6_pg_logic2_or0;
  assign s_dadda_cla4_u_cla6_and7 = s_dadda_cla4_u_cla6_pg_logic3_or0 & s_dadda_cla4_u_cla6_pg_logic1_or0;
  assign s_dadda_cla4_u_cla6_and8 = s_dadda_cla4_u_cla6_and6 & s_dadda_cla4_u_cla6_and7;
  assign s_dadda_cla4_u_cla6_and9 = s_dadda_cla4_u_cla6_pg_logic1_and0 & s_dadda_cla4_u_cla6_pg_logic3_or0;
  assign s_dadda_cla4_u_cla6_and10 = s_dadda_cla4_u_cla6_and9 & s_dadda_cla4_u_cla6_pg_logic2_or0;
  assign s_dadda_cla4_u_cla6_and11 = s_dadda_cla4_u_cla6_pg_logic2_and0 & s_dadda_cla4_u_cla6_pg_logic3_or0;
  assign s_dadda_cla4_u_cla6_or3 = s_dadda_cla4_u_cla6_and8 | s_dadda_cla4_u_cla6_and11;
  assign s_dadda_cla4_u_cla6_or4 = s_dadda_cla4_u_cla6_and10 | s_dadda_cla4_u_cla6_or3;
  assign s_dadda_cla4_u_cla6_or5 = s_dadda_cla4_u_cla6_pg_logic3_and0 | s_dadda_cla4_u_cla6_or4;
  assign s_dadda_cla4_u_cla6_pg_logic4_or0 = s_dadda_cla4_nand_2_3 | s_dadda_cla4_fa3_xor1;
  assign s_dadda_cla4_u_cla6_pg_logic4_and0 = s_dadda_cla4_nand_2_3 & s_dadda_cla4_fa3_xor1;
  assign s_dadda_cla4_u_cla6_pg_logic4_xor0 = s_dadda_cla4_nand_2_3 ^ s_dadda_cla4_fa3_xor1;
  assign s_dadda_cla4_u_cla6_xor4 = s_dadda_cla4_u_cla6_pg_logic4_xor0 ^ s_dadda_cla4_u_cla6_or5;
  assign s_dadda_cla4_u_cla6_and12 = s_dadda_cla4_u_cla6_or5 & s_dadda_cla4_u_cla6_pg_logic4_or0;
  assign s_dadda_cla4_u_cla6_or6 = s_dadda_cla4_u_cla6_pg_logic4_and0 | s_dadda_cla4_u_cla6_and12;
  assign s_dadda_cla4_u_cla6_pg_logic5_or0 = s_dadda_cla4_fa3_or0 | s_dadda_cla4_and_3_3;
  assign s_dadda_cla4_u_cla6_pg_logic5_and0 = s_dadda_cla4_fa3_or0 & s_dadda_cla4_and_3_3;
  assign s_dadda_cla4_u_cla6_pg_logic5_xor0 = s_dadda_cla4_fa3_or0 ^ s_dadda_cla4_and_3_3;
  assign s_dadda_cla4_u_cla6_xor5 = s_dadda_cla4_u_cla6_pg_logic5_xor0 ^ s_dadda_cla4_u_cla6_or6;
  assign s_dadda_cla4_u_cla6_and13 = s_dadda_cla4_u_cla6_or5 & s_dadda_cla4_u_cla6_pg_logic5_or0;
  assign s_dadda_cla4_u_cla6_and14 = s_dadda_cla4_u_cla6_and13 & s_dadda_cla4_u_cla6_pg_logic4_or0;
  assign s_dadda_cla4_u_cla6_and15 = s_dadda_cla4_u_cla6_pg_logic4_and0 & s_dadda_cla4_u_cla6_pg_logic5_or0;
  assign s_dadda_cla4_u_cla6_or7 = s_dadda_cla4_u_cla6_and14 | s_dadda_cla4_u_cla6_and15;
  assign s_dadda_cla4_u_cla6_or8 = s_dadda_cla4_u_cla6_pg_logic5_and0 | s_dadda_cla4_u_cla6_or7;
  assign s_dadda_cla4_xor0 = ~s_dadda_cla4_u_cla6_or8;

  assign s_dadda_cla4_out[0] = s_dadda_cla4_and_0_0;
  assign s_dadda_cla4_out[1] = s_dadda_cla4_u_cla6_pg_logic0_xor0;
  assign s_dadda_cla4_out[2] = s_dadda_cla4_u_cla6_xor1;
  assign s_dadda_cla4_out[3] = s_dadda_cla4_u_cla6_xor2;
  assign s_dadda_cla4_out[4] = s_dadda_cla4_u_cla6_xor3;
  assign s_dadda_cla4_out[5] = s_dadda_cla4_u_cla6_xor4;
  assign s_dadda_cla4_out[6] = s_dadda_cla4_u_cla6_xor5;
  assign s_dadda_cla4_out[7] = s_dadda_cla4_xor0;
endmodule