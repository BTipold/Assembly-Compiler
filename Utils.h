/*
	Utils holds utility functions that perform misc. tasks such as
	parsing strings, converting to binary and skipping blank lines.
*/

#pragma once
#include "mem_info.h"
#include "assembly.h"

#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <bitset>

#define IN_FILE_NAME  "test.asm"
#define OUT_FILE_NAME "init.memory"

using namespace std;

enum type{reg, immidiate, word_};

namespace utils {
	bool skip_blank(const string);

	int find_char(const string, const int, const string);

	vector<string> parse_cmds(const string);
	
	void write_to_file(const vector<string>, const vector<string>, const mem_info);

	unsigned int get_reg_num(const string);

	unsigned int get_immid_num(const string);

	string get_condition(const string);

	string to_bin_str(const unsigned int, const type);
}