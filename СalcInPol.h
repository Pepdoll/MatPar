#pragma once
#include "tok.h"
#include "stdafx.h"
using namespace std;
class calc {
public:
	calc();
	static double calcinpol(vector<tok> converted);
	static tok calcnums(tok first, tok second, char operation);
	~calc();
};