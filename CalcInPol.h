#pragma once
#include "tok.h"
#include "stdafx.h"
class calc {
public:
	calc();
	static double calcInPol(std::vector<tok> converted);
	static tok calcNums(tok first, tok second, char operation);
	~calc();
};