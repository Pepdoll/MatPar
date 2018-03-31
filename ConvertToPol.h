#pragma once
#include "stdafx.h"
#include "tok.h"
using namespace std;
class ConvertToPol {
public:
	ConvertToPol();
	static vector<tok> ConverterToPol(vector<tok> parsedstring);
	~ConvertToPol();
};