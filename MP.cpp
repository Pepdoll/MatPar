#include "stdafx.h"
#include "tok.h"
#include "ConvertToPol.h"
#include "ÑalcInPol.h"
#include "parser.h"
#include <locale.h>
int main() {
	setlocale(LC_ALL, "");
	std::string s;
	parser p = parser();
	while (1) {
		system("cls");
		std::cout << "Calculator that supports input ()*/+-." << std::endl;
		std::cout << "Enter an expression: ";
		std::cin >> s;
		try {
			std::cout <<"\n"<< "Result: " << round(calc::calcInPol(convertToPol::converterToPol(p.parse(s)))*1000)/1000;
		}
		catch(std::runtime_error e){
			std::cout << e.what() << std::endl;
		}
		getchar();
		getchar();
	}
	return 0;
}