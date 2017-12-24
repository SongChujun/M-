#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
int StrToInt(const char* pc);
using namespace std;
class STACK {
	int  *const  elems;	//申请内存用于存放栈的元素
	const  int   max;	//栈能存放的最大元素个数
	int   pos;			//栈实际已有元素个数，栈空时pos=0;
public:
	STACK(int m);		//初始化栈：最多存m个元素
	STACK(const STACK&s); 			//用栈s拷贝初始化栈//C
	virtual int  size() const;			//返回栈的最大元素个数max
	virtual operator int() const;			//返回栈的实际元素个数pos
	virtual int operator[ ] (int x) const;	//取下标x处的栈元素，第1个元素x=0
	virtual STACK& operator<<(int e); 	//将e入栈,并返回栈
	virtual STACK& operator>>(int &e);	//出栈到e,并返回栈
	virtual STACK& operator=(const STACK&s); //赋s给栈,并返回被赋值的栈//A
	virtual void print() const;			//打印栈
	virtual ~STACK();					//销毁栈
};
STACK::STACK(int m) :max(m), elems(new int[m])
{
	pos = 0;
}
STACK::STACK(const STACK&s) : elems(new int[s.max]), max(s.max)
{
	pos = s.pos;
}
int  STACK::size() const
{
	return max;
}
STACK::operator int() const
{
	return pos;
}
int STACK::operator[ ] (int x) const
{
	return elems[x];
}
STACK& STACK::operator<<(int e)
{
	if (pos == max)
	{
		pos = -1;
		return *this;
	}
	else
	{
		elems[pos] = e;
	}
	pos++;
	return *this;
}
STACK& STACK::operator>>(int &e)
{
	if (pos == 0)
	{
		pos = -1;
		return *this;
	}
	else
	{
		e = elems[pos - 1];
	}
	pos--;
}
STACK& STACK::operator=(const STACK&s)
{
	if (this == &s)
		return *this;
	delete elems;
	const_cast<int*>(elems) = new int[s.max];
	int* modimax = const_cast<int*>(&max);
	*modimax = s.max;
	pos = s.pos;
	return *this;
}
void STACK::print() const
{
	for (int i = 0; i<pos; i++)
	{
		printf("%d", elems[i]);
		printf("  ");
	}
	return;
}
STACK::~STACK()
{
	delete elems;
}
class QUEUE {
	STACK s1, s2;
public:
	QUEUE(int m); //每个栈最多m个元素，要求实现的队列最多能入2m个元素
	QUEUE(const QUEUE&s); 			//用队列s拷贝初始化队列
	virtual operator int() const;			//返回队列的实际元素个数
	virtual int full() const;		       //返回队列是否已满，满返回1，否则返回0
	virtual int operator[ ](int x)const;   //取下标为x的元素,第1个元素下标为0
	virtual QUEUE& operator<<(int e); 	//将e入队列,并返回队列
	virtual QUEUE& operator>>(int &e);	//出队列到e,并返回队列
	virtual QUEUE& operator=(const QUEUE&s); //赋s给队列,并返回被赋值的队列
	virtual void print() const;			//打印队列
	virtual ~QUEUE();					//销毁队列
};
QUEUE::QUEUE(int m) : s1(m), s2(m){}
QUEUE::QUEUE(const QUEUE&s) : s1(s.s1),s2(s.s2){}
QUEUE::operator int() const
{
	return s1.operator int() + s2.operator int();
}
int QUEUE::full() const
{
	if ((s1.size() == int(s1)) && (int(s2)!= 0))
		return 1;
	return 0;
}
int QUEUE::operator[ ](int x) const
{
	if (x < 0)
		return -1;
	if (x > QUEUE::operator int())
	{
		return -1;
	}
	if (s2.operator int() != 0)
	{
		if (x <= (s2.operator int() - 1))
		{
			return s2[s2.operator int() - x - 1];
		}
		else if (x > (s2.operator int() - 1))
		{
			return s1[x - s2.operator int()];
		}
	}
	else
	{
		if (x > s1.operator int() - 1)
			return *this;
		else
		{
			return s1[x];
		}
	}
}
QUEUE& QUEUE::operator<<(int e)
{
	int elem;
	if (s1.size() != s1.operator int())
		s1<<(e);
	else if (s2.operator int() == 0)
	{
		int n = s1.operator int();
		for (int i = 0; i < n; i++)
		{
			s1>>elem;
			s2<<elem;
		}
		s1<<e;
	}
	return *this;
}
QUEUE& QUEUE::operator>>(int &e)
{
	int elem;
	if (s2.operator int() != 0)
	{
		s2>>(e);
	}
	else
	{
		int n = s1.operator int();
		for (int i = 0; i < n; i++)
		{
			s1>>(elem);
			s2<<(elem);
		}
		s2>>(e);
	}
	return *this;
}
QUEUE& QUEUE::operator=(const QUEUE&s)
{
	s1 = s.s1;
	s2 = s.s2;
	return *this;
}
void QUEUE::print() const
{
	int n = this->operator int();
	for (int i = 0; i < n; i++)
	{
		std::cout << QUEUE::operator[](i)<<"  ";
	}
}
QUEUE::~QUEUE()
{
	
}
int main(int argc, char **argv)
{
	int n = StrToInt(argv[2]);
	QUEUE* q = new QUEUE(n);
	printf("S  ");
	printf("%d  ", n);
	int i = 3;
	int j = 0;
	int cnt = 0;
	int e = 0;
	while (1)
	{
		if (i>argc - 1)
		{
			break;
		}
		else if (strcmp(argv[i], "-I") == 0)
		{
			printf("I  ");
			for (j = i + 1; (j <= (argc - 1) && (strcmp(argv[j], "-O") != 0) && (strcmp(argv[j], "-I") != 0) && (strcmp(argv[j], "-A") != 0) && (strcmp(argv[j], "-C") != 0) && (strcmp(argv[j], "-O") != 0) && (strcmp(argv[j], "-G") != 0)); j++)
			{
				int test = StrToInt(argv[j]);
				if (q->full())
				{
					cout << "E";
					return 0;
				}
				(*q) << test;
			}
			q->print();
			i = j;
		}
		else if (strcmp(argv[i], "-O") == 0)
		{
			printf("O  ");
			int num = argv[i + 1][0] - '0';
			for (cnt = 0; cnt<num; cnt++)
			{
				if (q->operator int() == 0)
				{
					cout << "E";
					return 0;
				}
				(*q) >> e;
			}
			i += 2;
			q->print();
		}
		else if (strcmp(argv[i], "-A") == 0)
		{
			printf("A  ");
			QUEUE* tmp = q;
			(*q) = (*tmp);
			i += 2;
			q->print();
		}
		else if (strcmp(argv[i], "-C") == 0)
		{
			printf("C  ");
			QUEUE* tmp = q;
			/*QUEUE* tmp2 = new QUEUE(*tmp);
			q = tmp;
			i += 1;*/
			q->print();
			i += 1;
		}
		else if (strcmp(argv[i], "-G") == 0)
		{
			printf("G  ");
			if (StrToInt(argv[i + 1]) > q->operator int() - 1)
			{
				cout << "E";
				return 0;
			}
			int m = q->operator[](StrToInt(argv[i + 1]));
			printf("%d  ", m);
			i += 2;
		}
		else if (strcmp(argv[i], "-N") == 0)
		{
			printf("N  ");
			int m = int(*q);
			printf("%d  ", m);
			i += 1;
		}
	}
	char str[80];
	// scanf_s("%s", str);
	return 0;
}
int StrToInt(const char* pc)
{
	int res = 0;
	int i = 0;
	for (i = strlen(pc) - 1; i >= 0; i--)
	{
		if (!((pc[i] >= '0') && (pc[i] <= '9')))
		{
			return -1;
		}
		res = res + (pc[i] - '0')*pow(10, strlen(pc) - 1 - i);
	}
	return res;
}
