#include "mem_info.h"
#include "Utils.h"

using namespace std;

mem_info::mem_info(ifstream &file) {
	string size_str;
	string instructions_str;
	string stack_str;
	string heap_str;
	getline(file, size_str);
	getline(file, instructions_str);
	getline(file, stack_str);
	getline(file, heap_str);
	size = stoi(size_str.substr(utils::find_char(size_str, 0, ":") + 2, size_str.length()));
	instr_start = stoi(instructions_str.substr(utils::find_char(instructions_str, 0, ":") + 2, instructions_str.length()));
	stack_start = stoi(stack_str.substr(utils::find_char(stack_str, 0, ":") + 2, stack_str.length()));
	heap_start = stoi(heap_str.substr(utils::find_char(heap_str, 0, ":") + 2, heap_str.length()));
}