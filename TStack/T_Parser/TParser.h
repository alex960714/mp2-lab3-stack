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
	double ExNumber(char *s, int &len);  //���������� ������������� ����� �� ������
	int Priority(char ch);  //����������� ����������� �������������� ��������

public:
	TParser(char *s = NULL) ;  //�����������
	virtual ~TParser(void);

	bool CheckParentheses();  //�������� ������������ ����������� ������
	bool IsOper(char ch);  //��������, �������� �� ������ ����������
	bool IsNumber(char ch); //��������, �������� �� ������ ������
	void inftopost();  //����������� ��������� �� ��������� ����� � �����������
	double CalcPost();  //���������� ���������, ����������� � ����������� �����
	double Calc(const double a = 0);  //���������� ���������, ����������� � ��������� �����
	void func(const double a, const double b, const double c); //���������� ��������� � �����������
};

#endif