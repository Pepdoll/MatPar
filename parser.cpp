#include "parser.h"
#include "tok.h"
parser::parser() {

}
vector<tok> parser::parse(string s) {
	vector<tok> res;
	char op[7] = "+-()/*";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			int index = 0;
			char p[10]=" ";
			while (s[i] >= '0' && s[i] <= '9' || s[i] == ',') {
				p[index] = s[i];
				i++;
				index++;
			}
			i--;
			double m = atof(p);
			res.push_back(tok::tok(atof(p)));
		}
		else if (s[i] == '+'|| s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '(' || s[i] == ')') {
			res.push_back(tok::tok(s[i]));
		}
		else {
			cout << "Ошибка ввода!" << endl;
		}
	}
	for (tok t : res) {
		if (t.kind == '8') cout << t.val << " ";
		else cout << t.kind << " " ;
	}
	return res;
}
parser::~parser() {

}