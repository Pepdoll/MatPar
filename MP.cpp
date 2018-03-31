#include "stdafx.h"
#include "tok.h"
#include "ConvertToPol.h"
#include "�alcInPol.h"
#include "parser.h"
#include <locale.h>
int main() {
	setlocale(LC_ALL, "");
	string s;
	parser p = parser();
	while (1) {
		system("cls");
		cout << "�����������, �������������� ()*/+-. ������� " << endl;
		cout << "������� ���������: ";
		cin >> s;
		try {
			cout << "���������: " << round(calc::calcInPol(convertToPol::converterToPol(p.parse(s)))*1000)/1000;
		}
		catch(runtime_error e){
			cout << e.what() << endl;
		}
		getchar();
		getchar();
	}
	return 0;
}