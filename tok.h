#pragma once
#include "stdafx.h"
class tok {
public:
	char kind;
	int priority;
	double val;
	tok(char ch);
	tok(double value);
	tok();
	~tok();
};