#include "CalcInPol.h"
calc::calc() {

}
double calc::calcInPol(std::vector<tok> converted) {
	std::stack<tok> stack;
	for (tok t : converted) {
		if (t.getKind() == 'n') {
			stack.push(t);
		}
		else {
			tok t1, t2;
			if (!stack.empty() && stack.top().getKind() == 'n') {
				t1 = stack.top();
				stack.pop();
			}
			if (!stack.empty() && stack.top().getKind() == 'n') {
				t2 = stack.top();
				stack.pop();
			}
			stack.push(calcNums(t1, t2, t.getKind()));
		}
	}
	if (stack.size() == 1) {
		return stack.top().getVal();
	}
}
tok calc::calcNums(tok first, tok second, char operation) {
	switch (operation) {
	case '+':return tok(second.getVal() + first.getVal());
	case '-':return tok(second.getVal() - first.getVal());
	case '*':return tok(second.getVal() * first.getVal());
	case '/':if (first.getVal() != 0) {
		return tok(second.getVal() / first.getVal());
	}
			 else {
				 throw std::runtime_error("Division by 0!");
	}
	}
}
calc::~calc() {

}