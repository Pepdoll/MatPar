#pragma once
#include "stdafx.h"
class tok {
private:
	char kind;
	int priority;
	double val;
public:
	tok(char ch);
	tok(double value);
	char getKind();
	int getPriority();
	double getVal();
	tok();
	~tok();
};