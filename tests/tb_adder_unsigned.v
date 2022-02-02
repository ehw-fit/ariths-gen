
`timescale 1 ns/10 ps  // time-unit = 1 ns, precision = 10 ps

module add_unsigned_tb;
    reg [7:0] a;
    reg [7:0] b;
    wire [8:0] o;

    integer k, j;
    localparam period = 20;

    `dut dut(a, b, o); //.input_a(a), .input_b(b), .cgp_circuit_out(o));

    always 
    begin

        for(k = 0; k < 256; k = k+1) begin
            for(j = 0; j < 256; j = j+1) begin

                assign a = k;
                assign b = j;
                
                #period;

                //$assert(b == 0);
                if ( k + j != o) begin
                    $display("Invalid output: %d + %d = %d", a, b, o);
                end
            end;
        end;
        $finish;
    end
endmodule