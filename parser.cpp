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
			int j = i;
			while (s[i] >= '0' && s[i] <= '9' || s[i] == ','||s[i]=='.') {
				if (s[i] == '.') s[i] = ',';
				p[index] = s[i];
				i++;
				index++;
			}
			i--;
			double m = atof(p);
			if (j > 0 && s[j - 1] == '-') {
				m *= -1;
				res.erase(res.end() - 1);
			}
			res.push_back(tok::tok(m));
		}
		else if (s[i] == '+'|| s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '(' || s[i] == ')') {
			if (i > 0 && (s[i - 1] == '*' || s[i - 1] == '/'))continue;
			res.push_back(tok::tok(s[i]));
		}
		else {
			throw std::runtime_error("Input Error!");
		}
	}
	return res;
}
parser::~parser() {

}