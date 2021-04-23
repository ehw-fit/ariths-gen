module xnor_gate(input a, input b, output xnor_gate);
  assign xnor_gate = ~(a ^ b);
endmodule