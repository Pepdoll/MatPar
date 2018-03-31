#include "stdafx.h"
#include "tok.h"
#include "ConvertToPol.h"
#include "СalcInPol.h"
#include "parser.h"
#include <locale.h>
int main() {
	setlocale(LC_ALL, "");
	string s;
	parser p = parser();
	while (1) {
		system("cls");
		cout << "Калькулятор, поддерживающий ()*/+-. Дробные " << endl;
		cout << "Введите выражение: ";
		cin >> s;
		try {
			cout << "Результат: " << round(calc::calcInPol(convertToPol::converterToPol(p.parse(s)))*1000)/1000;
		}
		catch(runtime_error e){
			cout << e.what() << endl;
		}
		getchar();
		getchar();
	}
	return 0;
}