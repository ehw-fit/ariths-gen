module nand_gate(input a, input b, output nand_gate);
  assign nand_gate = ~(a & b);
endmodule