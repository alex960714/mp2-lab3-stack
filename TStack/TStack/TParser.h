#pragma once
#include "T_Stack.h"
#include <string.h>

const int MaxLen=201;

class TParser
{
public:
	char inf[MaxLen];
	char post[MaxLen];
	T_Stack <double> st_d;
	T_Stack <char> st_c;

	
public:
	TParser(char *s=NULL):st_d(150), st_c(100)
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

	int Priority(char ch)
	{
		switch (ch)
		{
		case '(':
		case ')': return 0;
		case '+':
		case '-': return 1;
		case '*': 
		case '/': return 2;
		case '^': return 3;
		default: return -1;
		}
	}

	bool IsOper(char ch)
	{
		if ((ch=='+')||(ch=='-')||(ch=='*')||(ch=='/')||(ch=='^'))
			return true;
		return false;
	}

	bool IsNumber(char ch)
	{
		if ((ch>='0')&&(ch<='9'))
			return true;
		return false;
	}

	void inftopost()
	{
		int i=0,j=0;
		st_c.Push('=');
		while (inf[i]!='\0')
		{
			if (IsNumber(inf[i]))
			{
				post[j]=inf[i];
				j++;
			}
			else if (inf[i]=='(')
				st_c.Push(inf[i]);
			else if (inf[i]=='\0')
			{
				char tmp=st_c.Pop();
				while (tmp!='(')
				{
					post[j++]=tmp;
					tmp=st_c.Pop();
				}
			}
			else if (IsOper(inf[i]))
			{
				char tmp=st_c.Pop();
				while (Priority(tmp)>=Priority(inf[i]))
				{
					post[j]=tmp;
					j++;
					tmp=st_c.Pop();
				}
				st_c.Push(tmp);
				st_c.Push(inf[i]);
			}
			i++;
		}
	}
};

