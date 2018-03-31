#pragma once
#include "tok.h"
#include "stdafx.h"
using namespace std;
class calc {
public:
	calc();
	static double calcInPol(vector<tok> converted);
	static tok calcNums(tok first, tok second, char operation);
	~calc();
};