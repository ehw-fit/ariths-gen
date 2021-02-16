module f_ha(input a, input b, output [1:0]out);
  wire f_ha_a;
  wire f_ha_b;
  wire f_ha_y0;
  wire f_ha_y1;

  assign f_ha_a = a;
  assign f_ha_b = b;
  assign f_ha_y0 = f_ha_a ^ f_ha_b;
  assign f_ha_y1 = f_ha_a & f_ha_b;

  assign out[0] = f_ha_y0;
  assign out[1] = f_ha_y1;
endmodule