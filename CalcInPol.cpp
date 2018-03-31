#include "ÑalcInPol.h"
calc::calc() {

}
double calc::calcInPol(std::vector<tok> converted) {
	std::stack<tok> stack;
	for (tok t : converted) {
		if (t.kind == '8') {
			stack.push(t);
		}
		else {
			tok t1, t2;
			if (!stack.empty() && stack.top().kind == '8') {
				t1 = stack.top();
				stack.pop();
			}
			if (!stack.empty() && stack.top().kind == '8') {
				t2 = stack.top();
				stack.pop();
			}
			stack.push(calcNums(t1, t2, t.kind));
		}
	}
	if (stack.size() == 1) {
		return stack.top().val;
	}
}
tok calc::calcNums(tok first, tok second, char operation) {
	switch (operation) {
	case '+':return tok(second.val + first.val);
	case '-':return tok(second.val - first.val);
	case '*':return tok(second.val * first.val);
	case '/':if (first.val != 0) {
		return tok(second.val / first.val);
	}
			 else {
				 throw std::runtime_error("Äåëåíèå íà 0!");
	}
	}
}
calc::~calc() {

}