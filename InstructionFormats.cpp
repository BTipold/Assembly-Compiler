#include "InstructionFormats.h" 

using namespace std;

string format::three_reg(const vector<string> input_command, const string opcode) {
	// For commands with three registers and no immidiates.
	unsigned int reg_num;

	reg_num = utils::get_reg_num(input_command[1]);
	string reg1 = utils::to_bin_str(reg_num, reg);

	reg_num = utils::get_reg_num(input_command[2]);
	string reg2 = utils::to_bin_str(reg_num, reg);
	
	reg_num = utils::get_reg_num(input_command[3]);
	string reg3 = utils::to_bin_str(reg_num, reg);
	
	return opcode + reg1 + reg2 + reg3 + "000000000000000";
}

string format::mul_div(const vector<string> input_command, const string opcode) {
	// For commands with two registers and no immidiates.
	unsigned int reg_num;

	reg_num = utils::get_reg_num(input_command[1]);
	string reg1 = utils::to_bin_str(reg_num, reg);

	reg_num = utils::get_reg_num(input_command[2]);
	string reg2 = utils::to_bin_str(reg_num, reg);

	return opcode + reg1 + reg2 + "0000000000000000000";
}

string format::one_reg(const vector<string> input_command, const string opcode) {
	// For commands with two registers and no immidiates.
	unsigned int reg_num;

	reg_num = utils::get_reg_num(input_command[1]);
	string reg1 = utils::to_bin_str(reg_num, reg);

	return opcode + reg1 + "00000000000000000000000";
}

string format::no_reg(const vector<string> input_command, const string opcode) {
	return opcode + "000000000000000000000000000";
}

string format::immid(const vector<string> input_command, const string opcode) {
	// For commands with two registers and an immidiate.
	unsigned int reg_num;
	unsigned int immid_num;

	reg_num = utils::get_reg_num(input_command[1]);
	string reg1 = utils::to_bin_str(reg_num, reg);

	reg_num = utils::get_reg_num(input_command[2]);
	string reg2 = utils::to_bin_str(reg_num, reg);

	immid_num = utils::get_immid_num(input_command[3]);
	string immid_val = utils::to_bin_str(immid_num, immidiate);
	return opcode + reg1 + reg2 + immid_val;
}

string format::load_store(const vector<string> input_command, const string opcode) {
	// For load/store/loadi commands. May or may not have offset.
	unsigned int reg_num;
	unsigned int immid_num;

	reg_num = utils::get_reg_num(input_command[1]);
	string reg1 = utils::to_bin_str(reg_num, reg);

	string reg2;
	string immid_val;

	// If format is has no offset (only address).
	if (input_command.size() == 3) {
		reg2 = "0000";

		immid_num = utils::get_immid_num(input_command[2]);
		immid_val = utils::to_bin_str(immid_num, immidiate);
	}

	// If format is has an address and an offset.
	else if (input_command.size() == 4) {
		reg_num = utils::get_reg_num(input_command[3]);
		reg2 = utils::to_bin_str(reg_num, reg);

		immid_num = utils::get_immid_num(input_command[2]);
		immid_val = utils::to_bin_str(immid_num, immidiate);
	}

	// Else compile error.
	else {
		cout << "Compilation Error. Incorrect number of arguments." << endl;
		return "";
	}
	return opcode + reg1 + reg2 + immid_val;
}

string format::branch(const vector<string> commands, const string opcode, unordered_map<string, unsigned int> map) {
	// For branch formats. 
	unsigned int reg_num;
	unsigned int mem_addr;

	reg_num = utils::get_reg_num(commands[1]);
	string reg1 = utils::to_bin_str(reg_num, reg);

	// Find the correct condition from command name.
	string condition = utils::get_condition(commands[0]);

	// Use hashmap of labels to find the correct mem address.
	mem_addr = map[commands[2]];
	string immid_val = utils::to_bin_str(mem_addr, immidiate);

	return opcode + reg1 + condition + immid_val;
}