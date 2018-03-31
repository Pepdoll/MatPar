#pragma once
#include "stdafx.h"
#include "tok.h"
using namespace std;
class parser {
public:
	parser();
	static vector<tok> parse(string s);
	~parser();
};