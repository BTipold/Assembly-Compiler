/* 
	Memory info holds information pertaining to the size
	and layout of the memory. This is loaded in from the 
	assembly file. 
*/

#pragma once
#include <fstream>
#include <string>

using namespace std;

class mem_info {
public:
	unsigned int size;
	unsigned int instr_start;
	unsigned int stack_start;
	unsigned int heap_start;

	mem_info(ifstream &);
};