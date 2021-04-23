module nor_gate(input a, input b, output nor_gate);
  assign nor_gate = ~(a | b);
endmodule