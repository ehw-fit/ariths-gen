module u_CSAwallace_pg_rca4(input [3:0] a, input [3:0] b, output [7:0] u_CSAwallace_pg_rca4_out);
  wire u_CSAwallace_pg_rca4_and_0_0;
  wire u_CSAwallace_pg_rca4_and_1_0;
  wire u_CSAwallace_pg_rca4_and_2_0;
  wire u_CSAwallace_pg_rca4_and_3_0;
  wire u_CSAwallace_pg_rca4_and_0_1;
  wire u_CSAwallace_pg_rca4_and_1_1;
  wire u_CSAwallace_pg_rca4_and_2_1;
  wire u_CSAwallace_pg_rca4_and_3_1;
  wire u_CSAwallace_pg_rca4_and_0_2;
  wire u_CSAwallace_pg_rca4_and_1_2;
  wire u_CSAwallace_pg_rca4_and_2_2;
  wire u_CSAwallace_pg_rca4_and_3_2;
  wire u_CSAwallace_pg_rca4_and_0_3;
  wire u_CSAwallace_pg_rca4_and_1_3;
  wire u_CSAwallace_pg_rca4_and_2_3;
  wire u_CSAwallace_pg_rca4_and_3_3;
  wire u_CSAwallace_pg_rca4_csa0_csa_component_fa1_xor0;
  wire u_CSAwallace_pg_rca4_csa0_csa_component_fa1_and0;
  wire u_CSAwallace_pg_rca4_csa0_csa_component_fa2_xor0;
  wire u_CSAwallace_pg_rca4_csa0_csa_component_fa2_and0;
  wire u_CSAwallace_pg_rca4_csa0_csa_component_fa2_xor1;
  wire u_CSAwallace_pg_rca4_csa0_csa_component_fa2_and1;
  wire u_CSAwallace_pg_rca4_csa0_csa_component_fa2_or0;
  wire u_CSAwallace_pg_rca4_csa0_csa_component_fa3_xor0;
  wire u_CSAwallace_pg_rca4_csa0_csa_component_fa3_and0;
  wire u_CSAwallace_pg_rca4_csa0_csa_component_fa3_xor1;
  wire u_CSAwallace_pg_rca4_csa0_csa_component_fa3_and1;
  wire u_CSAwallace_pg_rca4_csa0_csa_component_fa3_or0;
  wire u_CSAwallace_pg_rca4_csa0_csa_component_fa4_xor1;
  wire u_CSAwallace_pg_rca4_csa0_csa_component_fa4_and1;
  wire u_CSAwallace_pg_rca4_csa1_csa_component_fa2_xor0;
  wire u_CSAwallace_pg_rca4_csa1_csa_component_fa2_and0;
  wire u_CSAwallace_pg_rca4_csa1_csa_component_fa3_xor0;
  wire u_CSAwallace_pg_rca4_csa1_csa_component_fa3_and0;
  wire u_CSAwallace_pg_rca4_csa1_csa_component_fa3_xor1;
  wire u_CSAwallace_pg_rca4_csa1_csa_component_fa3_and1;
  wire u_CSAwallace_pg_rca4_csa1_csa_component_fa3_or0;
  wire u_CSAwallace_pg_rca4_csa1_csa_component_fa4_xor0;
  wire u_CSAwallace_pg_rca4_csa1_csa_component_fa4_and0;
  wire u_CSAwallace_pg_rca4_csa1_csa_component_fa4_xor1;
  wire u_CSAwallace_pg_rca4_csa1_csa_component_fa4_and1;
  wire u_CSAwallace_pg_rca4_csa1_csa_component_fa4_or0;
  wire u_CSAwallace_pg_rca4_csa1_csa_component_fa5_xor0;
  wire u_CSAwallace_pg_rca4_csa1_csa_component_fa5_and0;
  wire u_CSAwallace_pg_rca4_csa1_csa_component_fa5_xor1;
  wire u_CSAwallace_pg_rca4_csa1_csa_component_fa5_and1;
  wire u_CSAwallace_pg_rca4_csa1_csa_component_fa5_or0;
  wire u_CSAwallace_pg_rca4_u_pg_rca8_pg_fa3_xor0;
  wire u_CSAwallace_pg_rca4_u_pg_rca8_pg_fa3_and0;
  wire u_CSAwallace_pg_rca4_u_pg_rca8_pg_fa4_xor0;
  wire u_CSAwallace_pg_rca4_u_pg_rca8_pg_fa4_and0;
  wire u_CSAwallace_pg_rca4_u_pg_rca8_pg_fa4_xor1;
  wire u_CSAwallace_pg_rca4_u_pg_rca8_and4;
  wire u_CSAwallace_pg_rca4_u_pg_rca8_or4;
  wire u_CSAwallace_pg_rca4_u_pg_rca8_pg_fa5_xor0;
  wire u_CSAwallace_pg_rca4_u_pg_rca8_pg_fa5_and0;
  wire u_CSAwallace_pg_rca4_u_pg_rca8_pg_fa5_xor1;
  wire u_CSAwallace_pg_rca4_u_pg_rca8_and5;
  wire u_CSAwallace_pg_rca4_u_pg_rca8_or5;
  wire u_CSAwallace_pg_rca4_u_pg_rca8_pg_fa6_xor0;
  wire u_CSAwallace_pg_rca4_u_pg_rca8_pg_fa6_and0;
  wire u_CSAwallace_pg_rca4_u_pg_rca8_pg_fa6_xor1;
  wire u_CSAwallace_pg_rca4_u_pg_rca8_and6;
  wire u_CSAwallace_pg_rca4_u_pg_rca8_or6;

  assign u_CSAwallace_pg_rca4_and_0_0 = a[0] & b[0];
  assign u_CSAwallace_pg_rca4_and_1_0 = a[1] & b[0];
  assign u_CSAwallace_pg_rca4_and_2_0 = a[2] & b[0];
  assign u_CSAwallace_pg_rca4_and_3_0 = a[3] & b[0];
  assign u_CSAwallace_pg_rca4_and_0_1 = a[0] & b[1];
  assign u_CSAwallace_pg_rca4_and_1_1 = a[1] & b[1];
  assign u_CSAwallace_pg_rca4_and_2_1 = a[2] & b[1];
  assign u_CSAwallace_pg_rca4_and_3_1 = a[3] & b[1];
  assign u_CSAwallace_pg_rca4_and_0_2 = a[0] & b[2];
  assign u_CSAwallace_pg_rca4_and_1_2 = a[1] & b[2];
  assign u_CSAwallace_pg_rca4_and_2_2 = a[2] & b[2];
  assign u_CSAwallace_pg_rca4_and_3_2 = a[3] & b[2];
  assign u_CSAwallace_pg_rca4_and_0_3 = a[0] & b[3];
  assign u_CSAwallace_pg_rca4_and_1_3 = a[1] & b[3];
  assign u_CSAwallace_pg_rca4_and_2_3 = a[2] & b[3];
  assign u_CSAwallace_pg_rca4_and_3_3 = a[3] & b[3];
  assign u_CSAwallace_pg_rca4_csa0_csa_component_fa1_xor0 = u_CSAwallace_pg_rca4_and_1_0 ^ u_CSAwallace_pg_rca4_and_0_1;
  assign u_CSAwallace_pg_rca4_csa0_csa_component_fa1_and0 = u_CSAwallace_pg_rca4_and_1_0 & u_CSAwallace_pg_rca4_and_0_1;
  assign u_CSAwallace_pg_rca4_csa0_csa_component_fa2_xor0 = u_CSAwallace_pg_rca4_and_2_0 ^ u_CSAwallace_pg_rca4_and_1_1;
  assign u_CSAwallace_pg_rca4_csa0_csa_component_fa2_and0 = u_CSAwallace_pg_rca4_and_2_0 & u_CSAwallace_pg_rca4_and_1_1;
  assign u_CSAwallace_pg_rca4_csa0_csa_component_fa2_xor1 = u_CSAwallace_pg_rca4_csa0_csa_component_fa2_xor0 ^ u_CSAwallace_pg_rca4_and_0_2;
  assign u_CSAwallace_pg_rca4_csa0_csa_component_fa2_and1 = u_CSAwallace_pg_rca4_csa0_csa_component_fa2_xor0 & u_CSAwallace_pg_rca4_and_0_2;
  assign u_CSAwallace_pg_rca4_csa0_csa_component_fa2_or0 = u_CSAwallace_pg_rca4_csa0_csa_component_fa2_and0 | u_CSAwallace_pg_rca4_csa0_csa_component_fa2_and1;
  assign u_CSAwallace_pg_rca4_csa0_csa_component_fa3_xor0 = u_CSAwallace_pg_rca4_and_3_0 ^ u_CSAwallace_pg_rca4_and_2_1;
  assign u_CSAwallace_pg_rca4_csa0_csa_component_fa3_and0 = u_CSAwallace_pg_rca4_and_3_0 & u_CSAwallace_pg_rca4_and_2_1;
  assign u_CSAwallace_pg_rca4_csa0_csa_component_fa3_xor1 = u_CSAwallace_pg_rca4_csa0_csa_component_fa3_xor0 ^ u_CSAwallace_pg_rca4_and_1_2;
  assign u_CSAwallace_pg_rca4_csa0_csa_component_fa3_and1 = u_CSAwallace_pg_rca4_csa0_csa_component_fa3_xor0 & u_CSAwallace_pg_rca4_and_1_2;
  assign u_CSAwallace_pg_rca4_csa0_csa_component_fa3_or0 = u_CSAwallace_pg_rca4_csa0_csa_component_fa3_and0 | u_CSAwallace_pg_rca4_csa0_csa_component_fa3_and1;
  assign u_CSAwallace_pg_rca4_csa0_csa_component_fa4_xor1 = u_CSAwallace_pg_rca4_and_3_1 ^ u_CSAwallace_pg_rca4_and_2_2;
  assign u_CSAwallace_pg_rca4_csa0_csa_component_fa4_and1 = u_CSAwallace_pg_rca4_and_3_1 & u_CSAwallace_pg_rca4_and_2_2;
  assign u_CSAwallace_pg_rca4_csa1_csa_component_fa2_xor0 = u_CSAwallace_pg_rca4_csa0_csa_component_fa2_xor1 ^ u_CSAwallace_pg_rca4_csa0_csa_component_fa1_and0;
  assign u_CSAwallace_pg_rca4_csa1_csa_component_fa2_and0 = u_CSAwallace_pg_rca4_csa0_csa_component_fa2_xor1 & u_CSAwallace_pg_rca4_csa0_csa_component_fa1_and0;
  assign u_CSAwallace_pg_rca4_csa1_csa_component_fa3_xor0 = u_CSAwallace_pg_rca4_csa0_csa_component_fa3_xor1 ^ u_CSAwallace_pg_rca4_csa0_csa_component_fa2_or0;
  assign u_CSAwallace_pg_rca4_csa1_csa_component_fa3_and0 = u_CSAwallace_pg_rca4_csa0_csa_component_fa3_xor1 & u_CSAwallace_pg_rca4_csa0_csa_component_fa2_or0;
  assign u_CSAwallace_pg_rca4_csa1_csa_component_fa3_xor1 = u_CSAwallace_pg_rca4_csa1_csa_component_fa3_xor0 ^ u_CSAwallace_pg_rca4_and_0_3;
  assign u_CSAwallace_pg_rca4_csa1_csa_component_fa3_and1 = u_CSAwallace_pg_rca4_csa1_csa_component_fa3_xor0 & u_CSAwallace_pg_rca4_and_0_3;
  assign u_CSAwallace_pg_rca4_csa1_csa_component_fa3_or0 = u_CSAwallace_pg_rca4_csa1_csa_component_fa3_and0 | u_CSAwallace_pg_rca4_csa1_csa_component_fa3_and1;
  assign u_CSAwallace_pg_rca4_csa1_csa_component_fa4_xor0 = u_CSAwallace_pg_rca4_csa0_csa_component_fa4_xor1 ^ u_CSAwallace_pg_rca4_csa0_csa_component_fa3_or0;
  assign u_CSAwallace_pg_rca4_csa1_csa_component_fa4_and0 = u_CSAwallace_pg_rca4_csa0_csa_component_fa4_xor1 & u_CSAwallace_pg_rca4_csa0_csa_component_fa3_or0;
  assign u_CSAwallace_pg_rca4_csa1_csa_component_fa4_xor1 = u_CSAwallace_pg_rca4_csa1_csa_component_fa4_xor0 ^ u_CSAwallace_pg_rca4_and_1_3;
  assign u_CSAwallace_pg_rca4_csa1_csa_component_fa4_and1 = u_CSAwallace_pg_rca4_csa1_csa_component_fa4_xor0 & u_CSAwallace_pg_rca4_and_1_3;
  assign u_CSAwallace_pg_rca4_csa1_csa_component_fa4_or0 = u_CSAwallace_pg_rca4_csa1_csa_component_fa4_and0 | u_CSAwallace_pg_rca4_csa1_csa_component_fa4_and1;
  assign u_CSAwallace_pg_rca4_csa1_csa_component_fa5_xor0 = u_CSAwallace_pg_rca4_and_3_2 ^ u_CSAwallace_pg_rca4_csa0_csa_component_fa4_and1;
  assign u_CSAwallace_pg_rca4_csa1_csa_component_fa5_and0 = u_CSAwallace_pg_rca4_and_3_2 & u_CSAwallace_pg_rca4_csa0_csa_component_fa4_and1;
  assign u_CSAwallace_pg_rca4_csa1_csa_component_fa5_xor1 = u_CSAwallace_pg_rca4_csa1_csa_component_fa5_xor0 ^ u_CSAwallace_pg_rca4_and_2_3;
  assign u_CSAwallace_pg_rca4_csa1_csa_component_fa5_and1 = u_CSAwallace_pg_rca4_csa1_csa_component_fa5_xor0 & u_CSAwallace_pg_rca4_and_2_3;
  assign u_CSAwallace_pg_rca4_csa1_csa_component_fa5_or0 = u_CSAwallace_pg_rca4_csa1_csa_component_fa5_and0 | u_CSAwallace_pg_rca4_csa1_csa_component_fa5_and1;
  assign u_CSAwallace_pg_rca4_u_pg_rca8_pg_fa3_xor0 = u_CSAwallace_pg_rca4_csa1_csa_component_fa3_xor1 ^ u_CSAwallace_pg_rca4_csa1_csa_component_fa2_and0;
  assign u_CSAwallace_pg_rca4_u_pg_rca8_pg_fa3_and0 = u_CSAwallace_pg_rca4_csa1_csa_component_fa3_xor1 & u_CSAwallace_pg_rca4_csa1_csa_component_fa2_and0;
  assign u_CSAwallace_pg_rca4_u_pg_rca8_pg_fa4_xor0 = u_CSAwallace_pg_rca4_csa1_csa_component_fa4_xor1 ^ u_CSAwallace_pg_rca4_csa1_csa_component_fa3_or0;
  assign u_CSAwallace_pg_rca4_u_pg_rca8_pg_fa4_and0 = u_CSAwallace_pg_rca4_csa1_csa_component_fa4_xor1 & u_CSAwallace_pg_rca4_csa1_csa_component_fa3_or0;
  assign u_CSAwallace_pg_rca4_u_pg_rca8_pg_fa4_xor1 = u_CSAwallace_pg_rca4_u_pg_rca8_pg_fa4_xor0 ^ u_CSAwallace_pg_rca4_u_pg_rca8_pg_fa3_and0;
  assign u_CSAwallace_pg_rca4_u_pg_rca8_and4 = u_CSAwallace_pg_rca4_u_pg_rca8_pg_fa3_and0 & u_CSAwallace_pg_rca4_u_pg_rca8_pg_fa4_xor0;
  assign u_CSAwallace_pg_rca4_u_pg_rca8_or4 = u_CSAwallace_pg_rca4_u_pg_rca8_and4 | u_CSAwallace_pg_rca4_u_pg_rca8_pg_fa4_and0;
  assign u_CSAwallace_pg_rca4_u_pg_rca8_pg_fa5_xor0 = u_CSAwallace_pg_rca4_csa1_csa_component_fa5_xor1 ^ u_CSAwallace_pg_rca4_csa1_csa_component_fa4_or0;
  assign u_CSAwallace_pg_rca4_u_pg_rca8_pg_fa5_and0 = u_CSAwallace_pg_rca4_csa1_csa_component_fa5_xor1 & u_CSAwallace_pg_rca4_csa1_csa_component_fa4_or0;
  assign u_CSAwallace_pg_rca4_u_pg_rca8_pg_fa5_xor1 = u_CSAwallace_pg_rca4_u_pg_rca8_pg_fa5_xor0 ^ u_CSAwallace_pg_rca4_u_pg_rca8_or4;
  assign u_CSAwallace_pg_rca4_u_pg_rca8_and5 = u_CSAwallace_pg_rca4_u_pg_rca8_or4 & u_CSAwallace_pg_rca4_u_pg_rca8_pg_fa5_xor0;
  assign u_CSAwallace_pg_rca4_u_pg_rca8_or5 = u_CSAwallace_pg_rca4_u_pg_rca8_and5 | u_CSAwallace_pg_rca4_u_pg_rca8_pg_fa5_and0;
  assign u_CSAwallace_pg_rca4_u_pg_rca8_pg_fa6_xor0 = u_CSAwallace_pg_rca4_and_3_3 ^ u_CSAwallace_pg_rca4_csa1_csa_component_fa5_or0;
  assign u_CSAwallace_pg_rca4_u_pg_rca8_pg_fa6_and0 = u_CSAwallace_pg_rca4_and_3_3 & u_CSAwallace_pg_rca4_csa1_csa_component_fa5_or0;
  assign u_CSAwallace_pg_rca4_u_pg_rca8_pg_fa6_xor1 = u_CSAwallace_pg_rca4_u_pg_rca8_pg_fa6_xor0 ^ u_CSAwallace_pg_rca4_u_pg_rca8_or5;
  assign u_CSAwallace_pg_rca4_u_pg_rca8_and6 = u_CSAwallace_pg_rca4_u_pg_rca8_or5 & u_CSAwallace_pg_rca4_u_pg_rca8_pg_fa6_xor0;
  assign u_CSAwallace_pg_rca4_u_pg_rca8_or6 = u_CSAwallace_pg_rca4_u_pg_rca8_and6 | u_CSAwallace_pg_rca4_u_pg_rca8_pg_fa6_and0;

  assign u_CSAwallace_pg_rca4_out[0] = u_CSAwallace_pg_rca4_and_0_0;
  assign u_CSAwallace_pg_rca4_out[1] = u_CSAwallace_pg_rca4_csa0_csa_component_fa1_xor0;
  assign u_CSAwallace_pg_rca4_out[2] = u_CSAwallace_pg_rca4_csa1_csa_component_fa2_xor0;
  assign u_CSAwallace_pg_rca4_out[3] = u_CSAwallace_pg_rca4_u_pg_rca8_pg_fa3_xor0;
  assign u_CSAwallace_pg_rca4_out[4] = u_CSAwallace_pg_rca4_u_pg_rca8_pg_fa4_xor1;
  assign u_CSAwallace_pg_rca4_out[5] = u_CSAwallace_pg_rca4_u_pg_rca8_pg_fa5_xor1;
  assign u_CSAwallace_pg_rca4_out[6] = u_CSAwallace_pg_rca4_u_pg_rca8_pg_fa6_xor1;
  assign u_CSAwallace_pg_rca4_out[7] = u_CSAwallace_pg_rca4_u_pg_rca8_or6;
endmodule