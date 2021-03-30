module xor_gate(input _a, input _b, output _y0);
  assign _y0 = _a ^ _b;
endmodule

module and_gate(input _a, input _b, output _y0);
  assign _y0 = _a & _b;
endmodule

module h_ha(input a, input b, output h_ha_y0, output h_ha_y1);
  xor_gate xor_gate_h_ha_y0(a, b, h_ha_y0);
  and_gate and_gate_h_ha_y1(a, b, h_ha_y1);
endmodule