
`timescale 1 ns/10 ps  // time-unit = 1 ns, precision = 10 ps

module mul_unsigned_tb;
    reg signed [7:0] a;
    reg signed [7:0] b;
    wire signed [15:0] o;

    integer k, j;
    localparam period = 20;

    `dut dut(a, b, o); //.input_a(a), .input_b(b), .cgp_circuit_out(o));

    always 
    begin

        for(k = -127; k < 128; k = k+1) begin
            for(j = -127; j < 128; j = j+1) begin

                assign a = k;
                assign b = j;
                
                #period;

                //$assert(b == 0);
                if ( k * j != o) begin
                    $display("Invalid output: %d * %d = %d", a, b, o);
                end
            end;
        end;
        $finish(0);
    end
endmodule