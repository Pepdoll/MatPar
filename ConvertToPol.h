#pragma once
#include "stdafx.h"
#include "tok.h"
using namespace std;
class convertToPol {
public:
	convertToPol();
	static vector<tok> converterToPol(vector<tok> parsedString);
	~convertToPol();
};