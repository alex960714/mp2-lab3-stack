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
	char str[100];
	int op;
	setlocale(LC_CTYPE, "Russian");
	do
	{
	    cout << "������� �������������� ���������:" << endl;
	    cin >> str;
	    TParser p(str);
	    cout << "������� ����� ��������:" << endl;
	    cout << "1. ���������� � ����������� � ��������� �����;" << endl << "2. ���������� ������ � ��������� �����;" << endl;
	    cout << "3. ���������� �������� ������� ����� ���������� x." << endl << "4. ���������� ������ ���������" << endl;
		cin >> op;
		switch (op)
		{
		case 1: p.inftopost();
			cout << "��������� ��������� (����������� �����) = " << p.CalcPost() << endl;
		case 2: cout << "��������� ��������� (��������� �����) = " << p.Calc() << endl;
			break;
		case 3: p.func();
		case 4: break;
		default: cout << "������������ ���� ��������. ������� ����� �������� ��� ���:" << endl;
		}
	} while (op!=4);
    return 0;
}