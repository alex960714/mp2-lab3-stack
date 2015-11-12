// TStack.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <math.h>
#include <locale.h>
#include "T_Stack.h"
#include "TParser.h"
#include <iostream>
using namespace std;


int main()
{
	//TParser p;
	char str[100];
	setlocale(LC_CTYPE, "Russian");
	cout << "Введите арифметическое выражение:" << endl;
	cin >> str;
	TParser p(str);
	int op;
	cout << "Введите номер операции:" << endl;
	cout << "1. Вычисление в постфиксной и инфиксной форме;" << endl << "2. Вычисление только в инфиксной форме." << endl;
	do
	{
		cin >> op;
		switch (op)
		{
		case 1: p.inftopost();
			cout << "Результат выражения (постфиксная форма) = " << p.CalcPost() << endl;
		case 2: cout << "Результат выражения (инфиксная форма) = " << p.Calc() << endl;
			break;
		default: cout << "Некорректный ввод операции. Введите номер операции ещё раз:" << endl;
		}
	} while ((op != 1) && (op != 2));
    return 0;
}