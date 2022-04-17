module s_dadda_cska4(input [3:0] a, input [3:0] b, output [7:0] s_dadda_cska4_out);
  wire s_dadda_cska4_nand_3_0;
  wire s_dadda_cska4_and_2_1;
  wire s_dadda_cska4_ha0_xor0;
  wire s_dadda_cska4_ha0_and0;
  wire s_dadda_cska4_nand_3_1;
  wire s_dadda_cska4_fa0_xor0;
  wire s_dadda_cska4_fa0_xor1;
  wire s_dadda_cska4_fa0_and1;
  wire s_dadda_cska4_fa0_or0;
  wire s_dadda_cska4_and_2_0;
  wire s_dadda_cska4_and_1_1;
  wire s_dadda_cska4_ha1_xor0;
  wire s_dadda_cska4_ha1_and0;
  wire s_dadda_cska4_and_1_2;
  wire s_dadda_cska4_nand_0_3;
  wire s_dadda_cska4_fa1_xor0;
  wire s_dadda_cska4_fa1_and0;
  wire s_dadda_cska4_fa1_xor1;
  wire s_dadda_cska4_fa1_and1;
  wire s_dadda_cska4_fa1_or0;
  wire s_dadda_cska4_and_2_2;
  wire s_dadda_cska4_nand_1_3;
  wire s_dadda_cska4_fa2_xor0;
  wire s_dadda_cska4_fa2_and0;
  wire s_dadda_cska4_fa2_xor1;
  wire s_dadda_cska4_fa2_and1;
  wire s_dadda_cska4_fa2_or0;
  wire s_dadda_cska4_nand_3_2;
  wire s_dadda_cska4_fa3_xor0;
  wire s_dadda_cska4_fa3_and0;
  wire s_dadda_cska4_fa3_xor1;
  wire s_dadda_cska4_fa3_and1;
  wire s_dadda_cska4_fa3_or0;
  wire s_dadda_cska4_and_0_0;
  wire s_dadda_cska4_and_1_0;
  wire s_dadda_cska4_and_0_2;
  wire s_dadda_cska4_nand_2_3;
  wire s_dadda_cska4_and_0_1;
  wire s_dadda_cska4_and_3_3;
  wire s_dadda_cska4_u_cska6_xor0;
  wire s_dadda_cska4_u_cska6_ha0_xor0;
  wire s_dadda_cska4_u_cska6_ha0_and0;
  wire s_dadda_cska4_u_cska6_xor1;
  wire s_dadda_cska4_u_cska6_fa0_xor0;
  wire s_dadda_cska4_u_cska6_fa0_and0;
  wire s_dadda_cska4_u_cska6_fa0_xor1;
  wire s_dadda_cska4_u_cska6_fa0_and1;
  wire s_dadda_cska4_u_cska6_fa0_or0;
  wire s_dadda_cska4_u_cska6_xor2;
  wire s_dadda_cska4_u_cska6_fa1_xor0;
  wire s_dadda_cska4_u_cska6_fa1_and0;
  wire s_dadda_cska4_u_cska6_fa1_xor1;
  wire s_dadda_cska4_u_cska6_fa1_and1;
  wire s_dadda_cska4_u_cska6_fa1_or0;
  wire s_dadda_cska4_u_cska6_xor3;
  wire s_dadda_cska4_u_cska6_fa2_xor0;
  wire s_dadda_cska4_u_cska6_fa2_and0;
  wire s_dadda_cska4_u_cska6_fa2_xor1;
  wire s_dadda_cska4_u_cska6_fa2_and1;
  wire s_dadda_cska4_u_cska6_fa2_or0;
  wire s_dadda_cska4_u_cska6_and_propagate00;
  wire s_dadda_cska4_u_cska6_and_propagate01;
  wire s_dadda_cska4_u_cska6_and_propagate02;
  wire s_dadda_cska4_u_cska6_mux2to10_not0;
  wire s_dadda_cska4_u_cska6_mux2to10_and1;
  wire s_dadda_cska4_u_cska6_xor4;
  wire s_dadda_cska4_u_cska6_fa3_xor0;
  wire s_dadda_cska4_u_cska6_fa3_and0;
  wire s_dadda_cska4_u_cska6_fa3_xor1;
  wire s_dadda_cska4_u_cska6_fa3_and1;
  wire s_dadda_cska4_u_cska6_fa3_or0;
  wire s_dadda_cska4_u_cska6_xor5;
  wire s_dadda_cska4_u_cska6_fa4_xor0;
  wire s_dadda_cska4_u_cska6_fa4_and0;
  wire s_dadda_cska4_u_cska6_fa4_xor1;
  wire s_dadda_cska4_u_cska6_fa4_and1;
  wire s_dadda_cska4_u_cska6_fa4_or0;
  wire s_dadda_cska4_u_cska6_and_propagate13;
  wire s_dadda_cska4_u_cska6_mux2to11_and0;
  wire s_dadda_cska4_u_cska6_mux2to11_not0;
  wire s_dadda_cska4_u_cska6_mux2to11_and1;
  wire s_dadda_cska4_u_cska6_mux2to11_xor0;
  wire s_dadda_cska4_xor0;

  assign s_dadda_cska4_nand_3_0 = ~(a[3] & b[0]);
  assign s_dadda_cska4_and_2_1 = a[2] & b[1];
  assign s_dadda_cska4_ha0_xor0 = s_dadda_cska4_nand_3_0 ^ s_dadda_cska4_and_2_1;
  assign s_dadda_cska4_ha0_and0 = s_dadda_cska4_nand_3_0 & s_dadda_cska4_and_2_1;
  assign s_dadda_cska4_nand_3_1 = ~(a[3] & b[1]);
  assign s_dadda_cska4_fa0_xor0 = ~s_dadda_cska4_ha0_and0;
  assign s_dadda_cska4_fa0_xor1 = s_dadda_cska4_fa0_xor0 ^ s_dadda_cska4_nand_3_1;
  assign s_dadda_cska4_fa0_and1 = s_dadda_cska4_fa0_xor0 & s_dadda_cska4_nand_3_1;
  assign s_dadda_cska4_fa0_or0 = s_dadda_cska4_ha0_and0 | s_dadda_cska4_fa0_and1;
  assign s_dadda_cska4_and_2_0 = a[2] & b[0];
  assign s_dadda_cska4_and_1_1 = a[1] & b[1];
  assign s_dadda_cska4_ha1_xor0 = s_dadda_cska4_and_2_0 ^ s_dadda_cska4_and_1_1;
  assign s_dadda_cska4_ha1_and0 = s_dadda_cska4_and_2_0 & s_dadda_cska4_and_1_1;
  assign s_dadda_cska4_and_1_2 = a[1] & b[2];
  assign s_dadda_cska4_nand_0_3 = ~(a[0] & b[3]);
  assign s_dadda_cska4_fa1_xor0 = s_dadda_cska4_ha1_and0 ^ s_dadda_cska4_and_1_2;
  assign s_dadda_cska4_fa1_and0 = s_dadda_cska4_ha1_and0 & s_dadda_cska4_and_1_2;
  assign s_dadda_cska4_fa1_xor1 = s_dadda_cska4_fa1_xor0 ^ s_dadda_cska4_nand_0_3;
  assign s_dadda_cska4_fa1_and1 = s_dadda_cska4_fa1_xor0 & s_dadda_cska4_nand_0_3;
  assign s_dadda_cska4_fa1_or0 = s_dadda_cska4_fa1_and0 | s_dadda_cska4_fa1_and1;
  assign s_dadda_cska4_and_2_2 = a[2] & b[2];
  assign s_dadda_cska4_nand_1_3 = ~(a[1] & b[3]);
  assign s_dadda_cska4_fa2_xor0 = s_dadda_cska4_fa1_or0 ^ s_dadda_cska4_and_2_2;
  assign s_dadda_cska4_fa2_and0 = s_dadda_cska4_fa1_or0 & s_dadda_cska4_and_2_2;
  assign s_dadda_cska4_fa2_xor1 = s_dadda_cska4_fa2_xor0 ^ s_dadda_cska4_nand_1_3;
  assign s_dadda_cska4_fa2_and1 = s_dadda_cska4_fa2_xor0 & s_dadda_cska4_nand_1_3;
  assign s_dadda_cska4_fa2_or0 = s_dadda_cska4_fa2_and0 | s_dadda_cska4_fa2_and1;
  assign s_dadda_cska4_nand_3_2 = ~(a[3] & b[2]);
  assign s_dadda_cska4_fa3_xor0 = s_dadda_cska4_fa2_or0 ^ s_dadda_cska4_fa0_or0;
  assign s_dadda_cska4_fa3_and0 = s_dadda_cska4_fa2_or0 & s_dadda_cska4_fa0_or0;
  assign s_dadda_cska4_fa3_xor1 = s_dadda_cska4_fa3_xor0 ^ s_dadda_cska4_nand_3_2;
  assign s_dadda_cska4_fa3_and1 = s_dadda_cska4_fa3_xor0 & s_dadda_cska4_nand_3_2;
  assign s_dadda_cska4_fa3_or0 = s_dadda_cska4_fa3_and0 | s_dadda_cska4_fa3_and1;
  assign s_dadda_cska4_and_0_0 = a[0] & b[0];
  assign s_dadda_cska4_and_1_0 = a[1] & b[0];
  assign s_dadda_cska4_and_0_2 = a[0] & b[2];
  assign s_dadda_cska4_nand_2_3 = ~(a[2] & b[3]);
  assign s_dadda_cska4_and_0_1 = a[0] & b[1];
  assign s_dadda_cska4_and_3_3 = a[3] & b[3];
  assign s_dadda_cska4_u_cska6_xor0 = s_dadda_cska4_and_1_0 ^ s_dadda_cska4_and_0_1;
  assign s_dadda_cska4_u_cska6_ha0_xor0 = s_dadda_cska4_and_1_0 ^ s_dadda_cska4_and_0_1;
  assign s_dadda_cska4_u_cska6_ha0_and0 = s_dadda_cska4_and_1_0 & s_dadda_cska4_and_0_1;
  assign s_dadda_cska4_u_cska6_xor1 = s_dadda_cska4_and_0_2 ^ s_dadda_cska4_ha1_xor0;
  assign s_dadda_cska4_u_cska6_fa0_xor0 = s_dadda_cska4_and_0_2 ^ s_dadda_cska4_ha1_xor0;
  assign s_dadda_cska4_u_cska6_fa0_and0 = s_dadda_cska4_and_0_2 & s_dadda_cska4_ha1_xor0;
  assign s_dadda_cska4_u_cska6_fa0_xor1 = s_dadda_cska4_u_cska6_fa0_xor0 ^ s_dadda_cska4_u_cska6_ha0_and0;
  assign s_dadda_cska4_u_cska6_fa0_and1 = s_dadda_cska4_u_cska6_fa0_xor0 & s_dadda_cska4_u_cska6_ha0_and0;
  assign s_dadda_cska4_u_cska6_fa0_or0 = s_dadda_cska4_u_cska6_fa0_and0 | s_dadda_cska4_u_cska6_fa0_and1;
  assign s_dadda_cska4_u_cska6_xor2 = s_dadda_cska4_ha0_xor0 ^ s_dadda_cska4_fa1_xor1;
  assign s_dadda_cska4_u_cska6_fa1_xor0 = s_dadda_cska4_ha0_xor0 ^ s_dadda_cska4_fa1_xor1;
  assign s_dadda_cska4_u_cska6_fa1_and0 = s_dadda_cska4_ha0_xor0 & s_dadda_cska4_fa1_xor1;
  assign s_dadda_cska4_u_cska6_fa1_xor1 = s_dadda_cska4_u_cska6_fa1_xor0 ^ s_dadda_cska4_u_cska6_fa0_or0;
  assign s_dadda_cska4_u_cska6_fa1_and1 = s_dadda_cska4_u_cska6_fa1_xor0 & s_dadda_cska4_u_cska6_fa0_or0;
  assign s_dadda_cska4_u_cska6_fa1_or0 = s_dadda_cska4_u_cska6_fa1_and0 | s_dadda_cska4_u_cska6_fa1_and1;
  assign s_dadda_cska4_u_cska6_xor3 = s_dadda_cska4_fa0_xor1 ^ s_dadda_cska4_fa2_xor1;
  assign s_dadda_cska4_u_cska6_fa2_xor0 = s_dadda_cska4_fa0_xor1 ^ s_dadda_cska4_fa2_xor1;
  assign s_dadda_cska4_u_cska6_fa2_and0 = s_dadda_cska4_fa0_xor1 & s_dadda_cska4_fa2_xor1;
  assign s_dadda_cska4_u_cska6_fa2_xor1 = s_dadda_cska4_u_cska6_fa2_xor0 ^ s_dadda_cska4_u_cska6_fa1_or0;
  assign s_dadda_cska4_u_cska6_fa2_and1 = s_dadda_cska4_u_cska6_fa2_xor0 & s_dadda_cska4_u_cska6_fa1_or0;
  assign s_dadda_cska4_u_cska6_fa2_or0 = s_dadda_cska4_u_cska6_fa2_and0 | s_dadda_cska4_u_cska6_fa2_and1;
  assign s_dadda_cska4_u_cska6_and_propagate00 = s_dadda_cska4_u_cska6_xor0 & s_dadda_cska4_u_cska6_xor2;
  assign s_dadda_cska4_u_cska6_and_propagate01 = s_dadda_cska4_u_cska6_xor1 & s_dadda_cska4_u_cska6_xor3;
  assign s_dadda_cska4_u_cska6_and_propagate02 = s_dadda_cska4_u_cska6_and_propagate00 & s_dadda_cska4_u_cska6_and_propagate01;
  assign s_dadda_cska4_u_cska6_mux2to10_not0 = ~s_dadda_cska4_u_cska6_and_propagate02;
  assign s_dadda_cska4_u_cska6_mux2to10_and1 = s_dadda_cska4_u_cska6_fa2_or0 & s_dadda_cska4_u_cska6_mux2to10_not0;
  assign s_dadda_cska4_u_cska6_xor4 = s_dadda_cska4_nand_2_3 ^ s_dadda_cska4_fa3_xor1;
  assign s_dadda_cska4_u_cska6_fa3_xor0 = s_dadda_cska4_nand_2_3 ^ s_dadda_cska4_fa3_xor1;
  assign s_dadda_cska4_u_cska6_fa3_and0 = s_dadda_cska4_nand_2_3 & s_dadda_cska4_fa3_xor1;
  assign s_dadda_cska4_u_cska6_fa3_xor1 = s_dadda_cska4_u_cska6_fa3_xor0 ^ s_dadda_cska4_u_cska6_mux2to10_and1;
  assign s_dadda_cska4_u_cska6_fa3_and1 = s_dadda_cska4_u_cska6_fa3_xor0 & s_dadda_cska4_u_cska6_mux2to10_and1;
  assign s_dadda_cska4_u_cska6_fa3_or0 = s_dadda_cska4_u_cska6_fa3_and0 | s_dadda_cska4_u_cska6_fa3_and1;
  assign s_dadda_cska4_u_cska6_xor5 = s_dadda_cska4_fa3_or0 ^ s_dadda_cska4_and_3_3;
  assign s_dadda_cska4_u_cska6_fa4_xor0 = s_dadda_cska4_fa3_or0 ^ s_dadda_cska4_and_3_3;
  assign s_dadda_cska4_u_cska6_fa4_and0 = s_dadda_cska4_fa3_or0 & s_dadda_cska4_and_3_3;
  assign s_dadda_cska4_u_cska6_fa4_xor1 = s_dadda_cska4_u_cska6_fa4_xor0 ^ s_dadda_cska4_u_cska6_fa3_or0;
  assign s_dadda_cska4_u_cska6_fa4_and1 = s_dadda_cska4_u_cska6_fa4_xor0 & s_dadda_cska4_u_cska6_fa3_or0;
  assign s_dadda_cska4_u_cska6_fa4_or0 = s_dadda_cska4_u_cska6_fa4_and0 | s_dadda_cska4_u_cska6_fa4_and1;
  assign s_dadda_cska4_u_cska6_and_propagate13 = s_dadda_cska4_u_cska6_xor4 & s_dadda_cska4_u_cska6_xor5;
  assign s_dadda_cska4_u_cska6_mux2to11_and0 = s_dadda_cska4_u_cska6_mux2to10_and1 & s_dadda_cska4_u_cska6_and_propagate13;
  assign s_dadda_cska4_u_cska6_mux2to11_not0 = ~s_dadda_cska4_u_cska6_and_propagate13;
  assign s_dadda_cska4_u_cska6_mux2to11_and1 = s_dadda_cska4_u_cska6_fa4_or0 & s_dadda_cska4_u_cska6_mux2to11_not0;
  assign s_dadda_cska4_u_cska6_mux2to11_xor0 = s_dadda_cska4_u_cska6_mux2to11_and0 ^ s_dadda_cska4_u_cska6_mux2to11_and1;
  assign s_dadda_cska4_xor0 = ~s_dadda_cska4_u_cska6_mux2to11_xor0;

  assign s_dadda_cska4_out[0] = s_dadda_cska4_and_0_0;
  assign s_dadda_cska4_out[1] = s_dadda_cska4_u_cska6_ha0_xor0;
  assign s_dadda_cska4_out[2] = s_dadda_cska4_u_cska6_fa0_xor1;
  assign s_dadda_cska4_out[3] = s_dadda_cska4_u_cska6_fa1_xor1;
  assign s_dadda_cska4_out[4] = s_dadda_cska4_u_cska6_fa2_xor1;
  assign s_dadda_cska4_out[5] = s_dadda_cska4_u_cska6_fa3_xor1;
  assign s_dadda_cska4_out[6] = s_dadda_cska4_u_cska6_fa4_xor1;
  assign s_dadda_cska4_out[7] = s_dadda_cska4_xor0;
endmodule