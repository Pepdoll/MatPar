#include "parser.h"
#include "tok.h"
parser::parser() {

}
std::vector<tok> parser::parse(std::string s) {
	std::vector<tok> res;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			int index = 0;
			char p[10]=" ";
			while (s[i] >= '0' && s[i] <= '9' || s[i] == ','||s[i]=='.') {
				if (s[i] == '.') s[i] = ',';
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
			throw std::runtime_error("Ошибка ввода!");
		}
	}
	return res;
}
parser::~parser() {

}