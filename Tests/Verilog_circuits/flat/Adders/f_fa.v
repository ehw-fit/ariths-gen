module f_fa(input a, input b, input cin, output f_fa_y2, output f_fa_y4);
  wire f_fa_a;
  wire f_fa_b;
  wire f_fa_y0;
  wire f_fa_y1;
  wire f_fa_cin;
  wire f_fa_y2;
  wire f_fa_y3;
  wire f_fa_y4;

  assign f_fa_a = a;
  assign f_fa_b = b;
  assign f_fa_cin = cin;
  assign f_fa_y0 = f_fa_a ^ f_fa_b;
  assign f_fa_y1 = f_fa_a & f_fa_b;
  assign f_fa_y2 = f_fa_y0 ^ f_fa_cin;
  assign f_fa_y3 = f_fa_y0 & f_fa_cin;
  assign f_fa_y4 = f_fa_y1 | f_fa_y3;
endmodule