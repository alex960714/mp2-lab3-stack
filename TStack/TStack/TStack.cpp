// TStack.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <math.h>
#include <locale.h>
#include "T_Stack.h"
#include "TParser.h"
#include <iostream>
using namespace std;

bool CheckParenthesis(char *str);  //проверка правильности расстановки скобок


int main()
{
	char str[100];
	setlocale(LC_CTYPE, "Russian");
	cout << "Введите арифметическое выражение:" << endl;
	cin >> str;
	TParser p(str);
	if (CheckParenthesis(str))
	{
		p.inftopost();
		cout << p.post << endl;
	}
    return 0;
}

bool CheckParenthesis(char *str)
{
	T_Stack <char> s;
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '(')
			s.Push('(');
		if (str[i] == ')')
		{
			if (s.IsEmpty())
				return false;
			s.Pop();
		}
		i++;
	}
	return s.IsEmpty();
}