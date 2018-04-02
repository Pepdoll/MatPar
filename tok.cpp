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
tok::tok(double value) : kind('n'), priority(4),val(value) {

}
char tok::getKind() {
	return kind;
}
int tok::getPriority(){
	return priority;
}
double tok::getVal(){
	return val;
}
tok::tok() : kind('0'), val(0) {

}
tok::~tok() {

}