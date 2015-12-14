//#pragma once
#ifndef __TPARSER_H__
#define __TPARSER_H__
#include "T_Stack.h"
#include <string.h>
#include <iostream>
using namespace std;

const int MaxLen=201;

class TParser
{
private:
	char inf[MaxLen];
	char post[MaxLen];
	T_Stack <double> st_d;
	T_Stack <char> st_c;

protected:
	double ExNumber(char *s, int &len);  //считывание вещественного числа из строки
	int Priority(char ch);  //расстановка приоритетов арифметических операций

public:
	TParser(char *s = NULL) ;  //конструктор
	virtual ~TParser(void);

	bool CheckParentheses();  //проверка правильности расстановки скобок
	bool IsOper(char ch);  //проверка, является ли символ оператором
	bool IsNumber(char ch); //проверка, является ли символ числом
	void inftopost();  //конвертация выражения из инфиксной формы в постфиксную
	double CalcPost();  //вычисление выражения, записанного в постфиксной форме
	double Calc(const double a = 0);  //вычисление выражения, записанного в инфиксной форме
	void func(const double a, const double b, const double c); //вычисление выражения с неизвестным
};

#endif