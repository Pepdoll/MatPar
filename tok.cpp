#include "tok.h"
using namespace std;

tok::tok(char ch) : kind(ch), val(0) {
	switch (ch) {
	case '*':
	case '/':
	{
		priority = 3;
	}break;
	case '+':
	case'-':
	{
		priority = 2;
	}break;
	case '(':
	case ')':
	{
		priority = 1;
	}break;
	}
}
tok::tok(double value) : kind('8'), priority(4),val(value) {

}
tok::tok() : kind('0'), val(0) {

}
tok::~tok() {

}