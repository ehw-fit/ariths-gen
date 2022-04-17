module u_cska4(input [3:0] a, input [3:0] b, output [4:0] u_cska4_out);
  wire u_cska4_xor0;
  wire u_cska4_ha0_xor0;
  wire u_cska4_ha0_and0;
  wire u_cska4_xor1;
  wire u_cska4_fa0_xor0;
  wire u_cska4_fa0_and0;
  wire u_cska4_fa0_xor1;
  wire u_cska4_fa0_and1;
  wire u_cska4_fa0_or0;
  wire u_cska4_xor2;
  wire u_cska4_fa1_xor0;
  wire u_cska4_fa1_and0;
  wire u_cska4_fa1_xor1;
  wire u_cska4_fa1_and1;
  wire u_cska4_fa1_or0;
  wire u_cska4_xor3;
  wire u_cska4_fa2_xor0;
  wire u_cska4_fa2_and0;
  wire u_cska4_fa2_xor1;
  wire u_cska4_fa2_and1;
  wire u_cska4_fa2_or0;
  wire u_cska4_and_propagate00;
  wire u_cska4_and_propagate01;
  wire u_cska4_and_propagate02;
  wire u_cska4_mux2to10_not0;
  wire u_cska4_mux2to10_and1;

  assign u_cska4_xor0 = a[0] ^ b[0];
  assign u_cska4_ha0_xor0 = a[0] ^ b[0];
  assign u_cska4_ha0_and0 = a[0] & b[0];
  assign u_cska4_xor1 = a[1] ^ b[1];
  assign u_cska4_fa0_xor0 = a[1] ^ b[1];
  assign u_cska4_fa0_and0 = a[1] & b[1];
  assign u_cska4_fa0_xor1 = u_cska4_fa0_xor0 ^ u_cska4_ha0_and0;
  assign u_cska4_fa0_and1 = u_cska4_fa0_xor0 & u_cska4_ha0_and0;
  assign u_cska4_fa0_or0 = u_cska4_fa0_and0 | u_cska4_fa0_and1;
  assign u_cska4_xor2 = a[2] ^ b[2];
  assign u_cska4_fa1_xor0 = a[2] ^ b[2];
  assign u_cska4_fa1_and0 = a[2] & b[2];
  assign u_cska4_fa1_xor1 = u_cska4_fa1_xor0 ^ u_cska4_fa0_or0;
  assign u_cska4_fa1_and1 = u_cska4_fa1_xor0 & u_cska4_fa0_or0;
  assign u_cska4_fa1_or0 = u_cska4_fa1_and0 | u_cska4_fa1_and1;
  assign u_cska4_xor3 = a[3] ^ b[3];
  assign u_cska4_fa2_xor0 = a[3] ^ b[3];
  assign u_cska4_fa2_and0 = a[3] & b[3];
  assign u_cska4_fa2_xor1 = u_cska4_fa2_xor0 ^ u_cska4_fa1_or0;
  assign u_cska4_fa2_and1 = u_cska4_fa2_xor0 & u_cska4_fa1_or0;
  assign u_cska4_fa2_or0 = u_cska4_fa2_and0 | u_cska4_fa2_and1;
  assign u_cska4_and_propagate00 = u_cska4_xor0 & u_cska4_xor2;
  assign u_cska4_and_propagate01 = u_cska4_xor1 & u_cska4_xor3;
  assign u_cska4_and_propagate02 = u_cska4_and_propagate00 & u_cska4_and_propagate01;
  assign u_cska4_mux2to10_not0 = ~u_cska4_and_propagate02;
  assign u_cska4_mux2to10_and1 = u_cska4_fa2_or0 & u_cska4_mux2to10_not0;

  assign u_cska4_out[0] = u_cska4_ha0_xor0;
  assign u_cska4_out[1] = u_cska4_fa0_xor1;
  assign u_cska4_out[2] = u_cska4_fa1_xor1;
  assign u_cska4_out[3] = u_cska4_fa2_xor1;
  assign u_cska4_out[4] = u_cska4_mux2to10_and1;
endmodule