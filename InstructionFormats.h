/*
	This file contains helper functions that turn
	the list of commands and keywords into a binary 
	instruction. 
*/

#pragma once
#include <string>
#include <vector>
#include <bitset>
#include <iostream>
#include <unordered_map>

#include "Utils.h"

using namespace std;

namespace format {
	string three_reg(const vector<string>, const string);
	string mul_div(const vector<string>, const string);
	string one_reg(const vector<string>, const string);
	string no_reg(const vector<string>, const string);
	string immid(const vector<string>, const string);
	string load_store(const vector<string>, const string);
	string branch(const vector<string>, string, unordered_map<string, unsigned int>);
}