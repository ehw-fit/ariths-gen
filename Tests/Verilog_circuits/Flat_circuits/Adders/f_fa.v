module f_fa(input a, input b, input cout, output [1:0]out);
  wire f_fa_a;
  wire f_fa_b;
  wire f_fa_y0;
  wire f_fa_y1;
  wire f_fa_cout;
  wire f_fa_y2;
  wire f_fa_y3;
  wire f_fa_y4;

  assign f_fa_a = a;
  assign f_fa_b = b;
  assign f_fa_cout = cout;
  assign f_fa_y0 = f_fa_a ^ f_fa_b;
  assign f_fa_y1 = f_fa_a & f_fa_b;
  assign f_fa_y2 = f_fa_y0 ^ f_fa_cout;
  assign f_fa_y3 = f_fa_y0 & f_fa_cout;
  assign f_fa_y4 = f_fa_y1 | f_fa_y3;

  assign out[0] = f_fa_y2;
  assign out[1] = f_fa_y4;
endmodule