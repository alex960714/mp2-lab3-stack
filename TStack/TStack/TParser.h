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
	TParser(char *s = NULL):st_d(150), st_c(100)  //�����������
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

	bool CheckParentheses();  //�������� ������������ ����������� ������
	int Priority(char ch);  //����������� ����������� �������������� ��������
	bool IsOper(char ch);  //��������, �������� �� ������ ����������
	bool IsNumber(char ch); //��������, �������� �� ������ ������
	void inftopost();  //����������� ��������� �� ��������� ����� � �����������

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

