#pragma once
#include <string>
#include <unordered_map>

#define ZEROS_32 "00000000000000000000000000000000"
#define ONES_32	 "11111111111111111111111111111111"

using namespace std;

// Enum of all the commands.
enum asm_commands {	ld, ldi, st, add, sub, _and, _or, shr,
					shra, shl, ror, rol, addi, andi, ori, mul, 
					_div, neg, _not, brzr, brnz, brmi, brpl, jr,
					jal, input, output, mfhi, mflo, nop, halt, word };

namespace assem {
	// This class basically exists so that I can switch case between the commands.
	// Command strings are mapped to enum.
	// Unordered map should do look-up in O(1)
	class cmd_list {
	public:
		unordered_map<string, asm_commands> vals;
		cmd_list(void);
	};
}