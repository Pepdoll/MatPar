#include "tok.h"
#include "stdafx.h"
#include "ConvertToPol.h"
using namespace std;
ConvertToPol::ConvertToPol() {

}
vector<tok> ConvertToPol::ConverterToPol(vector<tok> parsedstring) {
	vector<tok> res;
	stack<tok> stack;
	for (tok t : parsedstring) {
		if (t.kind == '8') {
			res.push_back(t);
		}
		else {
			if (t.kind == '(') {
				stack.push(t);
			}
			else if (t.kind == ')') {
				while (!stack.empty() && stack.top().kind != '(') {
					res.push_back(stack.top());
					stack.pop();
				}
				if (!stack.empty()) stack.pop();
				else throw runtime_error("Ошибка перевода!");
			}
			else if(!stack.empty()){
				if (stack.top().priority < t.priority) stack.push(t);
				else {
					while (!stack.empty() && t.priority <= stack.top().priority) {
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
		if (stack.top().kind != '(') {
			res.push_back(stack.top());
			stack.pop();
		}
	}
	cout << " " << endl;
	for (tok t : res) {
		if (t.kind == '8') cout << t.val << " ";
		else cout << t.kind << " ";
	}
	cout << " " << endl;
	return res;
}
ConvertToPol::~ConvertToPol() {

}