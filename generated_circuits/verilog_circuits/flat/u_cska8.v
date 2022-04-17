module u_cska8(input [7:0] a, input [7:0] b, output [8:0] u_cska8_out);
  wire u_cska8_xor0;
  wire u_cska8_ha0_xor0;
  wire u_cska8_ha0_and0;
  wire u_cska8_xor1;
  wire u_cska8_fa0_xor0;
  wire u_cska8_fa0_and0;
  wire u_cska8_fa0_xor1;
  wire u_cska8_fa0_and1;
  wire u_cska8_fa0_or0;
  wire u_cska8_xor2;
  wire u_cska8_fa1_xor0;
  wire u_cska8_fa1_and0;
  wire u_cska8_fa1_xor1;
  wire u_cska8_fa1_and1;
  wire u_cska8_fa1_or0;
  wire u_cska8_xor3;
  wire u_cska8_fa2_xor0;
  wire u_cska8_fa2_and0;
  wire u_cska8_fa2_xor1;
  wire u_cska8_fa2_and1;
  wire u_cska8_fa2_or0;
  wire u_cska8_and_propagate00;
  wire u_cska8_and_propagate01;
  wire u_cska8_and_propagate02;
  wire u_cska8_mux2to10_not0;
  wire u_cska8_mux2to10_and1;
  wire u_cska8_xor4;
  wire u_cska8_fa3_xor0;
  wire u_cska8_fa3_and0;
  wire u_cska8_fa3_xor1;
  wire u_cska8_fa3_and1;
  wire u_cska8_fa3_or0;
  wire u_cska8_xor5;
  wire u_cska8_fa4_xor0;
  wire u_cska8_fa4_and0;
  wire u_cska8_fa4_xor1;
  wire u_cska8_fa4_and1;
  wire u_cska8_fa4_or0;
  wire u_cska8_xor6;
  wire u_cska8_fa5_xor0;
  wire u_cska8_fa5_and0;
  wire u_cska8_fa5_xor1;
  wire u_cska8_fa5_and1;
  wire u_cska8_fa5_or0;
  wire u_cska8_xor7;
  wire u_cska8_fa6_xor0;
  wire u_cska8_fa6_and0;
  wire u_cska8_fa6_xor1;
  wire u_cska8_fa6_and1;
  wire u_cska8_fa6_or0;
  wire u_cska8_and_propagate13;
  wire u_cska8_and_propagate14;
  wire u_cska8_and_propagate15;
  wire u_cska8_mux2to11_and0;
  wire u_cska8_mux2to11_not0;
  wire u_cska8_mux2to11_and1;
  wire u_cska8_mux2to11_xor0;

  assign u_cska8_xor0 = a[0] ^ b[0];
  assign u_cska8_ha0_xor0 = a[0] ^ b[0];
  assign u_cska8_ha0_and0 = a[0] & b[0];
  assign u_cska8_xor1 = a[1] ^ b[1];
  assign u_cska8_fa0_xor0 = a[1] ^ b[1];
  assign u_cska8_fa0_and0 = a[1] & b[1];
  assign u_cska8_fa0_xor1 = u_cska8_fa0_xor0 ^ u_cska8_ha0_and0;
  assign u_cska8_fa0_and1 = u_cska8_fa0_xor0 & u_cska8_ha0_and0;
  assign u_cska8_fa0_or0 = u_cska8_fa0_and0 | u_cska8_fa0_and1;
  assign u_cska8_xor2 = a[2] ^ b[2];
  assign u_cska8_fa1_xor0 = a[2] ^ b[2];
  assign u_cska8_fa1_and0 = a[2] & b[2];
  assign u_cska8_fa1_xor1 = u_cska8_fa1_xor0 ^ u_cska8_fa0_or0;
  assign u_cska8_fa1_and1 = u_cska8_fa1_xor0 & u_cska8_fa0_or0;
  assign u_cska8_fa1_or0 = u_cska8_fa1_and0 | u_cska8_fa1_and1;
  assign u_cska8_xor3 = a[3] ^ b[3];
  assign u_cska8_fa2_xor0 = a[3] ^ b[3];
  assign u_cska8_fa2_and0 = a[3] & b[3];
  assign u_cska8_fa2_xor1 = u_cska8_fa2_xor0 ^ u_cska8_fa1_or0;
  assign u_cska8_fa2_and1 = u_cska8_fa2_xor0 & u_cska8_fa1_or0;
  assign u_cska8_fa2_or0 = u_cska8_fa2_and0 | u_cska8_fa2_and1;
  assign u_cska8_and_propagate00 = u_cska8_xor0 & u_cska8_xor2;
  assign u_cska8_and_propagate01 = u_cska8_xor1 & u_cska8_xor3;
  assign u_cska8_and_propagate02 = u_cska8_and_propagate00 & u_cska8_and_propagate01;
  assign u_cska8_mux2to10_not0 = ~u_cska8_and_propagate02;
  assign u_cska8_mux2to10_and1 = u_cska8_fa2_or0 & u_cska8_mux2to10_not0;
  assign u_cska8_xor4 = a[4] ^ b[4];
  assign u_cska8_fa3_xor0 = a[4] ^ b[4];
  assign u_cska8_fa3_and0 = a[4] & b[4];
  assign u_cska8_fa3_xor1 = u_cska8_fa3_xor0 ^ u_cska8_mux2to10_and1;
  assign u_cska8_fa3_and1 = u_cska8_fa3_xor0 & u_cska8_mux2to10_and1;
  assign u_cska8_fa3_or0 = u_cska8_fa3_and0 | u_cska8_fa3_and1;
  assign u_cska8_xor5 = a[5] ^ b[5];
  assign u_cska8_fa4_xor0 = a[5] ^ b[5];
  assign u_cska8_fa4_and0 = a[5] & b[5];
  assign u_cska8_fa4_xor1 = u_cska8_fa4_xor0 ^ u_cska8_fa3_or0;
  assign u_cska8_fa4_and1 = u_cska8_fa4_xor0 & u_cska8_fa3_or0;
  assign u_cska8_fa4_or0 = u_cska8_fa4_and0 | u_cska8_fa4_and1;
  assign u_cska8_xor6 = a[6] ^ b[6];
  assign u_cska8_fa5_xor0 = a[6] ^ b[6];
  assign u_cska8_fa5_and0 = a[6] & b[6];
  assign u_cska8_fa5_xor1 = u_cska8_fa5_xor0 ^ u_cska8_fa4_or0;
  assign u_cska8_fa5_and1 = u_cska8_fa5_xor0 & u_cska8_fa4_or0;
  assign u_cska8_fa5_or0 = u_cska8_fa5_and0 | u_cska8_fa5_and1;
  assign u_cska8_xor7 = a[7] ^ b[7];
  assign u_cska8_fa6_xor0 = a[7] ^ b[7];
  assign u_cska8_fa6_and0 = a[7] & b[7];
  assign u_cska8_fa6_xor1 = u_cska8_fa6_xor0 ^ u_cska8_fa5_or0;
  assign u_cska8_fa6_and1 = u_cska8_fa6_xor0 & u_cska8_fa5_or0;
  assign u_cska8_fa6_or0 = u_cska8_fa6_and0 | u_cska8_fa6_and1;
  assign u_cska8_and_propagate13 = u_cska8_xor4 & u_cska8_xor6;
  assign u_cska8_and_propagate14 = u_cska8_xor5 & u_cska8_xor7;
  assign u_cska8_and_propagate15 = u_cska8_and_propagate13 & u_cska8_and_propagate14;
  assign u_cska8_mux2to11_and0 = u_cska8_mux2to10_and1 & u_cska8_and_propagate15;
  assign u_cska8_mux2to11_not0 = ~u_cska8_and_propagate15;
  assign u_cska8_mux2to11_and1 = u_cska8_fa6_or0 & u_cska8_mux2to11_not0;
  assign u_cska8_mux2to11_xor0 = u_cska8_mux2to11_and0 ^ u_cska8_mux2to11_and1;

  assign u_cska8_out[0] = u_cska8_ha0_xor0;
  assign u_cska8_out[1] = u_cska8_fa0_xor1;
  assign u_cska8_out[2] = u_cska8_fa1_xor1;
  assign u_cska8_out[3] = u_cska8_fa2_xor1;
  assign u_cska8_out[4] = u_cska8_fa3_xor1;
  assign u_cska8_out[5] = u_cska8_fa4_xor1;
  assign u_cska8_out[6] = u_cska8_fa5_xor1;
  assign u_cska8_out[7] = u_cska8_fa6_xor1;
  assign u_cska8_out[8] = u_cska8_mux2to11_xor0;
endmodule