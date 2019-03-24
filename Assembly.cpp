#include "assembly.h"

using namespace std;

assem::cmd_list::cmd_list(void) {
	// Initialize the hash map to be used with switch case.
	vals["ld"] = ld;
	vals["ldi"] = ldi;
	vals["st"] = st;
	vals["add"] = add;
	vals["sub"] = sub;
	vals["and"] = _and;
	vals["or"] = _or;
	vals["shr"] = shr;
	vals["shra"] = shra;
	vals["shl"] = shl;
	vals["ror"] = ror;
	vals["rol"] = rol;
	vals["addi"] = addi;
	vals["andi"] = andi;
	vals["ori"] = ori;
	vals["mul"] = mul;
	vals["div"] = _div;
	vals["neg"] = neg;
	vals["not"] = _not;
	vals["brzr"] = brzr;
	vals["brnz"] = brnz;
	vals["brmi"] = brmi;
	vals["brpl"] = brpl;
	vals["jr"] = jr;
	vals["jal"] = jal;
	vals["in"] = input;
	vals["out"] = output;
	vals["mfhi"] = mfhi;
	vals["mflo"] = mflo;
	vals["nop"] = nop;
	vals["halt"] = halt;
	vals[".word"] = word;
}