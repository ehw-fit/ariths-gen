# ArithsGen – tool for arithmetic circuits generation
### FIT BUT bachelor's degree project

## Description
ArithsGen presents an open source tool that enables generation of various arithmetic circuits along with the possibility to export them to various representations which all serve their specific purpose. C language for easy simulation, Verilog for logic synthesis, BLIF for formal verification possibilities and CGP to enable further global optimization.

### Usage
```bash
python3 ariths_gen.py
```

### Example of generation
    #Example of 8-bit unsigned dadda multiplier that uses rca to provide the final product
	a = Bus(N=8, prefix="a_bus")
	b = Bus(N=8, prefix="b_bus")

	u_dadda = UnsignedDaddaMultiplier(a=a, b=b, prefix="h_u_dadda_rca8", unsigned_adder_class_name=UnsignedRippleCarryAdder)
	u_dadda.get_v_code_hier(open("h_u_dadda_rca8.v", "w"))

## Documentation
Code documentation is provided using **pdoc** documentation generator tool. Source: https://pdoc3.github.io/pdoc/.

### Instalation
```bash
pip3 install pdoc3	
```

### Usage
```bash
pdoc --html ariths_gen
```