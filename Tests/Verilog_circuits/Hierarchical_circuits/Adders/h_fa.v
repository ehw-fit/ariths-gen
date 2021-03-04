module xor_gate(input _a, input _b, output _y0);
  assign _y0 = _a ^ _b;
endmodule

module and_gate(input _a, input _b, output _y0);
  assign _y0 = _a & _b;
endmodule

module or_gate(input _a, input _b, output _y0);
  assign _y0 = _a | _b;
endmodule

module h_fa(input a, input b, input cin, output h_fa_y2, output h_fa_y4);
  wire h_fa_y0;
  wire h_fa_y1;
  wire h_fa_y3;

  xor_gate xor_gate_h_fa_y0(a, b, h_fa_y0);
  and_gate and_gate_h_fa_y1(a, b, h_fa_y1);
  and_gate and_gate_h_fa_y3(h_fa_y0, cin, h_fa_y3);

  xor_gate xor_gate_h_fa_y2(h_fa_y0, cin, h_fa_y2);
  or_gate or_gate_h_fa_y4(h_fa_y1, h_fa_y3, h_fa_y4);
endmodule