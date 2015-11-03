// TStack.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <math.h>
#include <locale.h>
#include "T_Stack.h"
#include "TParser.h"
#include <iostream>
using namespace std;

bool CheckParentheses(char *str);  //�������� ������������ ����������� ������


int main()
{
	//TParser p;
	char str[100];
	setlocale(LC_CTYPE, "Russian");
	cout << "������� �������������� ���������:" << endl;
	cin >> str;
	TParser p(str);
	/*if (p.CheckParentheses())
	{*/
		p.inftopost();
		cout << p.post << endl;
	/*}
	else cout << "������������ ����������� ������" << endl;*/
    return 0;
}

bool CheckParentheses(char *str)
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