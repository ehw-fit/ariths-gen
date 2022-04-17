module u_csamul_cska4(input [3:0] a, input [3:0] b, output [7:0] u_csamul_cska4_out);
  wire u_csamul_cska4_and0_0;
  wire u_csamul_cska4_and1_0;
  wire u_csamul_cska4_and2_0;
  wire u_csamul_cska4_and3_0;
  wire u_csamul_cska4_and0_1;
  wire u_csamul_cska4_ha0_1_xor0;
  wire u_csamul_cska4_ha0_1_and0;
  wire u_csamul_cska4_and1_1;
  wire u_csamul_cska4_ha1_1_xor0;
  wire u_csamul_cska4_ha1_1_and0;
  wire u_csamul_cska4_and2_1;
  wire u_csamul_cska4_ha2_1_xor0;
  wire u_csamul_cska4_ha2_1_and0;
  wire u_csamul_cska4_and3_1;
  wire u_csamul_cska4_and0_2;
  wire u_csamul_cska4_fa0_2_xor0;
  wire u_csamul_cska4_fa0_2_and0;
  wire u_csamul_cska4_fa0_2_xor1;
  wire u_csamul_cska4_fa0_2_and1;
  wire u_csamul_cska4_fa0_2_or0;
  wire u_csamul_cska4_and1_2;
  wire u_csamul_cska4_fa1_2_xor0;
  wire u_csamul_cska4_fa1_2_and0;
  wire u_csamul_cska4_fa1_2_xor1;
  wire u_csamul_cska4_fa1_2_and1;
  wire u_csamul_cska4_fa1_2_or0;
  wire u_csamul_cska4_and2_2;
  wire u_csamul_cska4_fa2_2_xor0;
  wire u_csamul_cska4_fa2_2_and0;
  wire u_csamul_cska4_fa2_2_xor1;
  wire u_csamul_cska4_fa2_2_and1;
  wire u_csamul_cska4_fa2_2_or0;
  wire u_csamul_cska4_and3_2;
  wire u_csamul_cska4_and0_3;
  wire u_csamul_cska4_fa0_3_xor0;
  wire u_csamul_cska4_fa0_3_and0;
  wire u_csamul_cska4_fa0_3_xor1;
  wire u_csamul_cska4_fa0_3_and1;
  wire u_csamul_cska4_fa0_3_or0;
  wire u_csamul_cska4_and1_3;
  wire u_csamul_cska4_fa1_3_xor0;
  wire u_csamul_cska4_fa1_3_and0;
  wire u_csamul_cska4_fa1_3_xor1;
  wire u_csamul_cska4_fa1_3_and1;
  wire u_csamul_cska4_fa1_3_or0;
  wire u_csamul_cska4_and2_3;
  wire u_csamul_cska4_fa2_3_xor0;
  wire u_csamul_cska4_fa2_3_and0;
  wire u_csamul_cska4_fa2_3_xor1;
  wire u_csamul_cska4_fa2_3_and1;
  wire u_csamul_cska4_fa2_3_or0;
  wire u_csamul_cska4_and3_3;
  wire u_csamul_cska4_u_cska4_xor0;
  wire u_csamul_cska4_u_cska4_ha0_xor0;
  wire u_csamul_cska4_u_cska4_ha0_and0;
  wire u_csamul_cska4_u_cska4_xor1;
  wire u_csamul_cska4_u_cska4_fa0_xor0;
  wire u_csamul_cska4_u_cska4_fa0_and0;
  wire u_csamul_cska4_u_cska4_fa0_xor1;
  wire u_csamul_cska4_u_cska4_fa0_and1;
  wire u_csamul_cska4_u_cska4_fa0_or0;
  wire u_csamul_cska4_u_cska4_xor2;
  wire u_csamul_cska4_u_cska4_fa1_xor0;
  wire u_csamul_cska4_u_cska4_fa1_and0;
  wire u_csamul_cska4_u_cska4_fa1_xor1;
  wire u_csamul_cska4_u_cska4_fa1_and1;
  wire u_csamul_cska4_u_cska4_fa1_or0;
  wire u_csamul_cska4_u_cska4_and_propagate00;

  assign u_csamul_cska4_and0_0 = a[0] & b[0];
  assign u_csamul_cska4_and1_0 = a[1] & b[0];
  assign u_csamul_cska4_and2_0 = a[2] & b[0];
  assign u_csamul_cska4_and3_0 = a[3] & b[0];
  assign u_csamul_cska4_and0_1 = a[0] & b[1];
  assign u_csamul_cska4_ha0_1_xor0 = u_csamul_cska4_and0_1 ^ u_csamul_cska4_and1_0;
  assign u_csamul_cska4_ha0_1_and0 = u_csamul_cska4_and0_1 & u_csamul_cska4_and1_0;
  assign u_csamul_cska4_and1_1 = a[1] & b[1];
  assign u_csamul_cska4_ha1_1_xor0 = u_csamul_cska4_and1_1 ^ u_csamul_cska4_and2_0;
  assign u_csamul_cska4_ha1_1_and0 = u_csamul_cska4_and1_1 & u_csamul_cska4_and2_0;
  assign u_csamul_cska4_and2_1 = a[2] & b[1];
  assign u_csamul_cska4_ha2_1_xor0 = u_csamul_cska4_and2_1 ^ u_csamul_cska4_and3_0;
  assign u_csamul_cska4_ha2_1_and0 = u_csamul_cska4_and2_1 & u_csamul_cska4_and3_0;
  assign u_csamul_cska4_and3_1 = a[3] & b[1];
  assign u_csamul_cska4_and0_2 = a[0] & b[2];
  assign u_csamul_cska4_fa0_2_xor0 = u_csamul_cska4_and0_2 ^ u_csamul_cska4_ha1_1_xor0;
  assign u_csamul_cska4_fa0_2_and0 = u_csamul_cska4_and0_2 & u_csamul_cska4_ha1_1_xor0;
  assign u_csamul_cska4_fa0_2_xor1 = u_csamul_cska4_fa0_2_xor0 ^ u_csamul_cska4_ha0_1_and0;
  assign u_csamul_cska4_fa0_2_and1 = u_csamul_cska4_fa0_2_xor0 & u_csamul_cska4_ha0_1_and0;
  assign u_csamul_cska4_fa0_2_or0 = u_csamul_cska4_fa0_2_and0 | u_csamul_cska4_fa0_2_and1;
  assign u_csamul_cska4_and1_2 = a[1] & b[2];
  assign u_csamul_cska4_fa1_2_xor0 = u_csamul_cska4_and1_2 ^ u_csamul_cska4_ha2_1_xor0;
  assign u_csamul_cska4_fa1_2_and0 = u_csamul_cska4_and1_2 & u_csamul_cska4_ha2_1_xor0;
  assign u_csamul_cska4_fa1_2_xor1 = u_csamul_cska4_fa1_2_xor0 ^ u_csamul_cska4_ha1_1_and0;
  assign u_csamul_cska4_fa1_2_and1 = u_csamul_cska4_fa1_2_xor0 & u_csamul_cska4_ha1_1_and0;
  assign u_csamul_cska4_fa1_2_or0 = u_csamul_cska4_fa1_2_and0 | u_csamul_cska4_fa1_2_and1;
  assign u_csamul_cska4_and2_2 = a[2] & b[2];
  assign u_csamul_cska4_fa2_2_xor0 = u_csamul_cska4_and2_2 ^ u_csamul_cska4_and3_1;
  assign u_csamul_cska4_fa2_2_and0 = u_csamul_cska4_and2_2 & u_csamul_cska4_and3_1;
  assign u_csamul_cska4_fa2_2_xor1 = u_csamul_cska4_fa2_2_xor0 ^ u_csamul_cska4_ha2_1_and0;
  assign u_csamul_cska4_fa2_2_and1 = u_csamul_cska4_fa2_2_xor0 & u_csamul_cska4_ha2_1_and0;
  assign u_csamul_cska4_fa2_2_or0 = u_csamul_cska4_fa2_2_and0 | u_csamul_cska4_fa2_2_and1;
  assign u_csamul_cska4_and3_2 = a[3] & b[2];
  assign u_csamul_cska4_and0_3 = a[0] & b[3];
  assign u_csamul_cska4_fa0_3_xor0 = u_csamul_cska4_and0_3 ^ u_csamul_cska4_fa1_2_xor1;
  assign u_csamul_cska4_fa0_3_and0 = u_csamul_cska4_and0_3 & u_csamul_cska4_fa1_2_xor1;
  assign u_csamul_cska4_fa0_3_xor1 = u_csamul_cska4_fa0_3_xor0 ^ u_csamul_cska4_fa0_2_or0;
  assign u_csamul_cska4_fa0_3_and1 = u_csamul_cska4_fa0_3_xor0 & u_csamul_cska4_fa0_2_or0;
  assign u_csamul_cska4_fa0_3_or0 = u_csamul_cska4_fa0_3_and0 | u_csamul_cska4_fa0_3_and1;
  assign u_csamul_cska4_and1_3 = a[1] & b[3];
  assign u_csamul_cska4_fa1_3_xor0 = u_csamul_cska4_and1_3 ^ u_csamul_cska4_fa2_2_xor1;
  assign u_csamul_cska4_fa1_3_and0 = u_csamul_cska4_and1_3 & u_csamul_cska4_fa2_2_xor1;
  assign u_csamul_cska4_fa1_3_xor1 = u_csamul_cska4_fa1_3_xor0 ^ u_csamul_cska4_fa1_2_or0;
  assign u_csamul_cska4_fa1_3_and1 = u_csamul_cska4_fa1_3_xor0 & u_csamul_cska4_fa1_2_or0;
  assign u_csamul_cska4_fa1_3_or0 = u_csamul_cska4_fa1_3_and0 | u_csamul_cska4_fa1_3_and1;
  assign u_csamul_cska4_and2_3 = a[2] & b[3];
  assign u_csamul_cska4_fa2_3_xor0 = u_csamul_cska4_and2_3 ^ u_csamul_cska4_and3_2;
  assign u_csamul_cska4_fa2_3_and0 = u_csamul_cska4_and2_3 & u_csamul_cska4_and3_2;
  assign u_csamul_cska4_fa2_3_xor1 = u_csamul_cska4_fa2_3_xor0 ^ u_csamul_cska4_fa2_2_or0;
  assign u_csamul_cska4_fa2_3_and1 = u_csamul_cska4_fa2_3_xor0 & u_csamul_cska4_fa2_2_or0;
  assign u_csamul_cska4_fa2_3_or0 = u_csamul_cska4_fa2_3_and0 | u_csamul_cska4_fa2_3_and1;
  assign u_csamul_cska4_and3_3 = a[3] & b[3];
  assign u_csamul_cska4_u_cska4_xor0 = u_csamul_cska4_fa1_3_xor1 ^ u_csamul_cska4_fa0_3_or0;
  assign u_csamul_cska4_u_cska4_ha0_xor0 = u_csamul_cska4_fa1_3_xor1 ^ u_csamul_cska4_fa0_3_or0;
  assign u_csamul_cska4_u_cska4_ha0_and0 = u_csamul_cska4_fa1_3_xor1 & u_csamul_cska4_fa0_3_or0;
  assign u_csamul_cska4_u_cska4_xor1 = u_csamul_cska4_fa2_3_xor1 ^ u_csamul_cska4_fa1_3_or0;
  assign u_csamul_cska4_u_cska4_fa0_xor0 = u_csamul_cska4_fa2_3_xor1 ^ u_csamul_cska4_fa1_3_or0;
  assign u_csamul_cska4_u_cska4_fa0_and0 = u_csamul_cska4_fa2_3_xor1 & u_csamul_cska4_fa1_3_or0;
  assign u_csamul_cska4_u_cska4_fa0_xor1 = u_csamul_cska4_u_cska4_fa0_xor0 ^ u_csamul_cska4_u_cska4_ha0_and0;
  assign u_csamul_cska4_u_cska4_fa0_and1 = u_csamul_cska4_u_cska4_fa0_xor0 & u_csamul_cska4_u_cska4_ha0_and0;
  assign u_csamul_cska4_u_cska4_fa0_or0 = u_csamul_cska4_u_cska4_fa0_and0 | u_csamul_cska4_u_cska4_fa0_and1;
  assign u_csamul_cska4_u_cska4_xor2 = u_csamul_cska4_and3_3 ^ u_csamul_cska4_fa2_3_or0;
  assign u_csamul_cska4_u_cska4_fa1_xor0 = u_csamul_cska4_and3_3 ^ u_csamul_cska4_fa2_3_or0;
  assign u_csamul_cska4_u_cska4_fa1_and0 = u_csamul_cska4_and3_3 & u_csamul_cska4_fa2_3_or0;
  assign u_csamul_cska4_u_cska4_fa1_xor1 = u_csamul_cska4_u_cska4_fa1_xor0 ^ u_csamul_cska4_u_cska4_fa0_or0;
  assign u_csamul_cska4_u_cska4_fa1_and1 = u_csamul_cska4_u_cska4_fa1_xor0 & u_csamul_cska4_u_cska4_fa0_or0;
  assign u_csamul_cska4_u_cska4_fa1_or0 = u_csamul_cska4_u_cska4_fa1_and0 | u_csamul_cska4_u_cska4_fa1_and1;
  assign u_csamul_cska4_u_cska4_and_propagate00 = u_csamul_cska4_u_cska4_xor0 & u_csamul_cska4_u_cska4_xor2;

  assign u_csamul_cska4_out[0] = u_csamul_cska4_and0_0;
  assign u_csamul_cska4_out[1] = u_csamul_cska4_ha0_1_xor0;
  assign u_csamul_cska4_out[2] = u_csamul_cska4_fa0_2_xor1;
  assign u_csamul_cska4_out[3] = u_csamul_cska4_fa0_3_xor1;
  assign u_csamul_cska4_out[4] = u_csamul_cska4_u_cska4_ha0_xor0;
  assign u_csamul_cska4_out[5] = u_csamul_cska4_u_cska4_fa0_xor1;
  assign u_csamul_cska4_out[6] = u_csamul_cska4_u_cska4_fa1_xor1;
  assign u_csamul_cska4_out[7] = u_csamul_cska4_u_cska4_fa1_or0;
endmodule