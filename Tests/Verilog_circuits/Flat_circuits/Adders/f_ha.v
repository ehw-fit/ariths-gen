module f_ha(input a, input b, output f_ha_y0, output f_ha_y1);
  wire f_ha_a;
  wire f_ha_b;
  wire f_ha_y0;
  wire f_ha_y1;

  assign f_ha_a = a;
  assign f_ha_b = b;
  assign f_ha_y0 = f_ha_a ^ f_ha_b;
  assign f_ha_y1 = f_ha_a & f_ha_b;
endmodule