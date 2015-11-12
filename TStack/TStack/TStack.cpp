// TStack.cpp: ���������� ����� ����� ��� ����������� ����������.
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
	cout << "������� �������������� ���������:" << endl;
	cin >> str;
	TParser p(str);
	int op;
	cout << "������� ����� ��������:" << endl;
	cout << "1. ���������� � ����������� � ��������� �����;" << endl << "2. ���������� ������ � ��������� �����." << endl;
	do
	{
		cin >> op;
		switch (op)
		{
		case 1: p.inftopost();
			cout << "��������� ��������� (����������� �����) = " << p.CalcPost() << endl;
		case 2: cout << "��������� ��������� (��������� �����) = " << p.Calc() << endl;
			break;
		default: cout << "������������ ���� ��������. ������� ����� �������� ��� ���:" << endl;
		}
	} while ((op != 1) && (op != 2));
    return 0;
}