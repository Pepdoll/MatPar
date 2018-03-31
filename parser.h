#pragma once
#include "stdafx.h"
#include "tok.h"
class parser {
public:
	parser();
	static std::vector<tok> parse(std::string s);
	~parser();
};