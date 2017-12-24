#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<math.h>
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
int main(int argc, char **argv)
{
	int n = std::stoi(argv[2], nullptr, 10);
	STACK* p = new STACK(n);
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
					if (p->operator int() == p->size())
				{
						cout << "E" << endl;
						return 0;
				}
				p->operator<<(test);
			}
			p->print();
			i = j;
		}
		else if (strcmp(argv[i], "-O") == 0)
		{
			printf("O  ");
			int num = argv[i + 1][0] - '0';
			for (cnt = 0; cnt<num; cnt++)
			{
				if (p->operator int() == 0)
				{
					cout << "E" << endl;
					return 01;
				}
				p->operator>>(e);
			}
			i += 2;
			p->print();
		}
		else if (strcmp(argv[i], "-A") == 0)
		{
			printf("A  ");
			STACK *tmp = p;
			int n = StrToInt(argv[i + 1]);
			p = tmp;
			i += 2;
			p->print();
		}
		else if (strcmp(argv[i], "-C") == 0)
		{
			printf("C  ");
			STACK *tmp = p;
			p = tmp;
			i += 1;
			p->print();
		}
		else if (strcmp(argv[i], "-G") == 0)
		{
			printf("G  ");
			if (StrToInt(argv[i + 1]) > p->operator int()-1)
			{
				printf("E");
				return 0;
			}
			int m = p->operator[](StrToInt(argv[i + 1]));
			//int m = p[StrToInt(argv[i + 1])];
			printf("%d  ", m);
			i += 2;
		}
		else if (strcmp(argv[i], "-N") == 0)
		{
			printf("N  ");
			int m = int(p);
			int n = p->operator int();
			printf("%d  ", n);
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
