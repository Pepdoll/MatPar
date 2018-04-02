#include "tok.h"
#include "stdafx.h"
#include "ConvertToPol.h"
convertToPol::convertToPol() {

}
std::vector<tok> convertToPol::converterToPol(std::vector<tok> parsedString) {
	std::vector<tok> res;
	std::stack<tok> stack;
	for (tok t : parsedString) {
		if (t.getKind() == 'n') {
			res.push_back(t);
		}else {
			if (t.getKind() == '(') {
				stack.push(t);
			}else if (t.getKind() == ')') {
				while (!stack.empty() && stack.top().getKind() != '(') {
					res.push_back(stack.top());
					stack.pop();
				}
				if (!stack.empty()) {
					stack.pop();
				} else throw std::runtime_error("Ошибка перевода!");
			}
			else if(!stack.empty()){
				if (stack.top().getPriority() < t.getPriority()) {
					stack.push(t);
				}else {
					while (!stack.empty() && t.getPriority() <= stack.top().getPriority()) {
						res.push_back(stack.top());
						stack.pop();
					}
					stack.push(t);
				}
			}
			else {
				stack.push(t);
			}
		}
	}
	while (!stack.empty()) {
		if (stack.top().getKind() != '(') {
			res.push_back(stack.top());
			stack.pop();
		}
	}
	return res;
}
convertToPol::~convertToPol() {

}