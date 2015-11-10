#pragma once
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

	double ExNumber(char *s, int &len);  //���������� ������������� ����� �� ������

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
				inf[i]='\0';
			}
	}
	~TParser(void);

	bool CheckParentheses();  //�������� ������������ ����������� ������
	int Priority(char ch);  //����������� ����������� �������������� ��������
	bool IsOper(char ch);  //��������, �������� �� ������ ����������
	bool IsNumber(char ch); //��������, �������� �� ������ ������
	void inftopost();  //����������� ��������� �� ��������� ����� � �����������
	double CalcPost();  //���������� ���������, ����������� � ����������� �����
	double Calc();  //���������� ���������, ����������� � ��������� �����

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

