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
	char str[100];
	int op;
	setlocale(LC_CTYPE, "Russian");
	do
	{
	    cout << "Введите арифметическое выражение:" << endl;
	    cin >> str;
	    TParser p(str);
	    cout << "Введите номер операции:" << endl;
	    cout << "1. Вычисление в постфиксной и инфиксной форме;" << endl << "2. Вычисление только в инфиксной форме;" << endl;
	    cout << "3. Вычисление значения функции одной переменной x." << endl << "4. Завершение работы программы" << endl;
		cin >> op;
		switch (op)
		{
		case 1: p.inftopost();
			cout << "Результат выражения (постфиксная форма) = " << p.CalcPost() << endl;
		case 2: cout << "Результат выражения (инфиксная форма) = " << p.Calc() << endl;
			break;
		case 3: p.func();
		case 4: break;
		default: cout << "Некорректный ввод операции. Введите номер операции ещё раз:" << endl;
		}
	} while (op!=4);
    return 0;
}