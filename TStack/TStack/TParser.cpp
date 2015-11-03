#include "stdafx.h"
#include "TParser.h"


/*TParser::TParser(char *s = NULL): st_d(150), st_c(100)
{
	if (s == NULL)
		inf[0] = '\0';
	else
	{
		int i = 0;
		while (s[i] != '\0')
			inf[i] = s[i++];
	}
}*/


TParser::~TParser(void)
{
}

bool TParser::CheckParentheses()
{
	T_Stack <char> s;
	int i = 0;
	while (inf[i] != '\0')
	{
		if (inf[i] == '(')
			s.Push('(');
		if (inf[i] == ')')
		{
			if (s.IsEmpty())
				return false;
			s.Pop();
		}
		i++;
	}
	return s.IsEmpty();
}

int TParser::Priority(char ch)
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
	
	
bool TParser::IsOper(char ch)
{
	if ((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/') || (ch == '^'))
		return true;
	return false;
}

bool TParser::IsNumber(char ch)
{
	if ((ch >= '0') && (ch <= '9'))
		return true;
	return false;
}

void TParser::inftopost()
{
	if (!CheckParentheses())
		throw "Irregular placement of parentheses";
	int i = 0, j = 0;
	st_c.Push('=');
	while (inf[i] != '\0')
	{
		if (IsNumber(inf[i]))
		{
			post[j] = inf[i];
			j++;
		}
		else if (inf[i] == '(')
			st_c.Push(inf[i]);
		else if (inf[i] == ')')
		{
			char tmp = st_c.Pop();
			while (tmp != '(')
			{
				post[j++] = tmp;
				tmp = st_c.Pop();
			}
		}
		else if (IsOper(inf[i]))
		{
			char tmp = st_c.Pop();
			while (Priority(tmp) >= Priority(inf[i]))
			{
				post[j] = tmp;
				j++;
				tmp = st_c.Pop();
			}
			st_c.Push(tmp);
			st_c.Push(inf[i]);
		}
		i++;
	}
	char tmp = st_c.Pop();
	while (tmp != '=')
	{
		post[j++] = tmp;
		tmp = st_c.Pop();
	}
}
