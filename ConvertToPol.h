#pragma once
#include "stdafx.h"
#include "tok.h"
class convertToPol {
public:
	convertToPol();
	static std::vector<tok> converterToPol(std::vector<tok> parsedString);
	~convertToPol();
};