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

double TParser::ExNumber(char *s, int &len)
{
	int i=0;
	double tmp=atof(s);
	while (s[i]!='\0')
	{
		if (IsNumber(s[i]))
			i++;
		else break;
	}
	len=i;
	return tmp;
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
	case 's':
	case 'c':
	case 'l':
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
	if (((ch >= '0') && (ch <= '9'))||(ch == '.'))
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
	post[j]='\0';
	cout<<"����������� ����� ���������:"<<endl<<post<<endl;
}

double TParser::CalcPost()
{
	int i=0;
	st_d.Clear();
	while ((post[i]!='\0')&&(post[i]!='='))
	{
		if (IsNumber(post[i]))
			st_d.Push(post[i]-'0');
		if (IsOper(post[i]))
		{
			double op2=st_d.Pop();
			double op1=st_d.Pop();
			switch (post[i])
			{
			case '+': 
				st_d.Push(op1+op2);
				break;
			case '-': 
				st_d.Push(op1-op2);
				break;
			case '*':
				st_d.Push(op1*op2);
				break;
			case '/':
				if (op2==0)
					throw op2;
				st_d.Push(op1/op2);
				break;
			case '^':
				st_d.Push(pow(op1,op2));
			}
		}
		i++;
	}
	return st_d.Pop();
}

double TParser::Calc()
{
	st_d.Clear();
	st_c.Clear();
	int i=0, len;
	st_d.Push(0);
	st_c.Push('=');
	while (inf[i]!='\0')
	{
		if (IsNumber(inf[i]))
		{
			double tmp = ExNumber(&inf[i],len);
			st_d.Push(tmp);
			i+=len-1;
		}
		else if (inf[i]=='(')
			st_c.Push('(');
		else if (inf[i]==')')
		{
			char tmp=st_c.Pop();
			while (tmp!='(')
			{
				double op2=st_d.Pop();
			    double op1=st_d.Pop();
			    switch (tmp)
			    {
			    case '+': 
				    st_d.Push(op1+op2);
				    break;
			    case '-': 
				    st_d.Push(op1-op2);
				    break;
			    case '*':
				    st_d.Push(op1*op2);
				    break;
			    case '/':
				    if (op2==0)
					    throw op2;
				    st_d.Push(op1/op2);
				    break;
			    case '^':
				    st_d.Push(pow(op1,op2));
					break;
				case 's':
					st_d.Push(op1);
					st_d.Push(sin(op2));
					break;
				case 'c':
					st_d.Push(op1);
					st_d.Push(cos(op2));
					break;
				case 'l':
					st_d.Push(op1);
					st_d.Push(log(op2));
					break;
			    }
				tmp=st_c.Pop();
			}
		}
		else if (IsOper(inf[i]))
		{
			char tmp=st_c.Pop();
			while (Priority(tmp)>=Priority(inf[i]))
			{
				double op2=st_d.Pop();
			    double op1=st_d.Pop();
			    switch (tmp)
			    {
			    case '+': 
				    st_d.Push(op1+op2);
				    break;
			    case '-': 
				    st_d.Push(op1-op2);
				    break;
			    case '*':
				    st_d.Push(op1*op2);
				    break;
			    case '/':
				    if (op2==0)
					    throw op2;
				    st_d.Push(op1/op2);
				    break;
			    case '^':
				    st_d.Push(pow(op1,op2));
					break;
			    }
				tmp=st_c.Pop();
			}
			st_c.Push(tmp);
			st_c.Push(inf[i]);
		}
		else if (inf[i] == 's')
		{
			st_c.Push('(');
			st_c.Push('s');
			i += 3;
		}
		else if (inf[i] == 'c')
		{
			st_c.Push('(');
			st_c.Push('c');
			i += 3;
		}
		else if (inf[i] == 'l')
		{
			st_c.Push('(');
			st_c.Push('l');
			i += 2;
		}
		i++;
	}
	char tmp=st_c.Pop();
	while (tmp!='=')
	{
		double op2=st_d.Pop();
		double op1=st_d.Pop();
		switch (tmp)
		{
		case '+': 
			st_d.Push(op1+op2);
			break;
		case '-': 
			st_d.Push(op1-op2);
			break;
		case '*':
			st_d.Push(op1*op2);
			break;
		case '/':
			if (op2==0)
				throw op2;
			st_d.Push(op1/op2);
			break;
		case '^':
			st_d.Push(pow(op1,op2));
		}
		tmp=st_c.Pop();
	}
	return st_d.Pop();
}