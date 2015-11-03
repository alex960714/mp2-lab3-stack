#pragma once
#include "T_Stack.h"
#include <string.h>
#include <iostream>
using namespace std;

const int MaxLen=201;

class TParser
{
public:
	char inf[MaxLen];
	char post[MaxLen];
	T_Stack <double> st_d;
	T_Stack <char> st_c;

	
public:
	TParser(char *s = NULL):st_d(150), st_c(100)  //конструктор
	{
			if (s==NULL)
				inf[0]='\0';
			else 
			{
				int i=0;
				while (s[i]!='\0')
					inf[i]=s[i++];
			}
	}
	~TParser(void);

	bool CheckParentheses();  //проверка правильности расстановки скобок
	int Priority(char ch);  //расстановка приоритетов арифметических операций
	bool IsOper(char ch);  //проверка, является ли символ оператором
	bool IsNumber(char ch); //проверка, является ли символ числом
	void inftopost();  //конвертация выражения из инфиксной формы в постфиксную

	/*friend istream& operator>>(istream& is, TParser& p)  //???
	{
		int i = 0;
		char tmp;
		is >> tmp;
		while (tmp != '\0')
		{
			p.inf[i++] = tmp;
			is >> tmp;
		}
		return is;
	}*/
};

