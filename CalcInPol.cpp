#include "ÑalcInPol.h"
calc::calc() {

}
double calc::calcinpol(vector<tok> converted) {
	stack<tok> stack;
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
			stack.push(calcnums(t1, t2, t.kind));
		}
	}
	if (stack.size() == 1) {
		return stack.top().val;
	}
}
tok calc::calcnums(tok first, tok second, char operation) {
	switch (operation) {
	case '+':return tok(first.val + second.val);
	case '-':return tok(second.val - first.val);
	case '*':return tok(first.val * second.val);
	case '/':return tok(second.val / first.val);
	}
}
calc::~calc() {

}