#include "stdafx.h"
#include "tok.h"
#include "ConvertToPol.h"
#include "СalcInPol.h"
#include "parser.h"
#include <locale.h>
int main() {
	setlocale(LC_ALL, "");
	std::string s;
	parser p = parser();
	while (1) {
		system("cls");
		std::cout << "Калькулятор, поддерживающий ()*/+-. Дробные " << std::endl;
		std::cout << "Введите выражение: ";
		std::cin >> s;
		try {
			std::cout << "Результат: " << round(calc::calcInPol(convertToPol::converterToPol(p.parse(s)))*1000)/1000;
		}
		catch(std::runtime_error e){
			std::cout << e.what() << std::endl;
		}
		getchar();
		getchar();
	}
	return 0;
}