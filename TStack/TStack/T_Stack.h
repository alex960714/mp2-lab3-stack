#pragma once


template <class T>
class T_Stack
{
protected:
	int MaxSize;
	int Index;
	T *mas;
public:
	T_Stack(int len = 10)
	{
		if (len <= 0) 
			throw len;
		MaxSize = len;
		Index = -1;
		mas = new T[MaxSize];
	};

	virtual ~T_Stack() { delete[] mas; };

	T_Stack(const T_Stack& s)
	{
		MaxSize = s.MaxSize;
		Index = s.Index;
		mas = new T[MaxSize];
		for (int i = 0; i <= Index; i++)
			mas[i] = s.mas[i];
	};

	T_Stack& operator=(const T_Stack& s)
	{
		if (MaxSize != s.MaxSize)
		{
			delete[] mas;
			MaxSize = s.MaxSize;
			mas = new T[MaxSize];
		}
		Index = s.Index;
		for (int i = 0; i <= Index; i++)
			mas[i] = s.mas[i];
		return *this;
	};

	bool IsEmpty() {  return Index == -1; };

	bool IsFull() { return Index == MaxSize - 1; }

	T Top()  //чтение без удаления
	{
		if (Index == -1)
			throw Index;
		return mas[Index];
	}

	T Pop()  //чтение с удалением
	{
		if (Index == -1)
			throw Index;
		return mas[Index--];
	}

	void Push(const T n) //запись в стек
	{
		if (Index == MaxSize - 1)
			throw Index;
		mas[++Index] = n;
	}
};

