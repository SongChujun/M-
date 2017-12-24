#include<iostream>
#include<stdio.h>
using namespace std;
int StrToInt(const char* pc);
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
class QUEUE:public STACK {
	STACK  s2;
public:
	QUEUE(int m); //每个栈最多m个元素，要求实现的队列最多能入2m个元素
	QUEUE(const QUEUE&s); 			//用队列s拷贝初始化队列
	virtual operator int() const;			//返回队列的实际元素个数
	virtual int full() const;		       //返回队列是否已满，满返回1，否则返回0
	virtual int operator[ ](int x)const;   //取下标为x的元素，第1个元素下标为0
	virtual QUEUE& operator<<(int e);  //将e入队列,并返回队列
	virtual QUEUE& operator>>(int &e);	//出队列到e,并返回队列
	virtual QUEUE& operator=(const QUEUE&s); //赋s给队列,并返回被赋值的队列
	virtual void print() const;			//打印队列
	virtual ~QUEUE();					//销毁队列
};
QUEUE::QUEUE(int m):STACK(m),s2(m){}
QUEUE::QUEUE(const QUEUE&s) : STACK(s), s2(s.s2)
{
}
QUEUE::operator int() const
{
	return STACK::operator int() + s2.operator int();//直接把两个栈大小相加
}
int QUEUE::full() const
{
	if ((STACK::size() == STACK::operator int()) && (s2.operator int() != 0))//入队列栈满且出队列栈未满
		return 1;
	return 0;
}
int QUEUE::operator[ ](int x) const
{
	if (x < 0)
		return -1;
	if (x > this->operator int())
	{
		return -1;
	}
	if (s2.operator int() != 0)//s2中有元素
	{
		if (x <= (s2.operator int() - 1))//在s2中找
		{
			return s2[s2.operator int() - x - 1];
		}
		else if (x > (s2.operator int() - 1))//否则在基类栈找
		{
			return STACK::operator[](x - s2.operator int());
		}
	}
	else//直接在基类栈找
	{
		if (x > STACK::operator int() - 1)
			return *this;
		else
		{
			return STACK::operator[](x);
		}
	}
}
QUEUE& QUEUE::operator<<(int e)
{
	int elem;
	if (STACK::operator int()!=STACK::size())//边界检查
		STACK::operator<<(e);
	else if (s2.operator int() == 0)//s2空，先倒入s2再入栈
	{
		int n = STACK::operator int();
		for (int i = 0; i < n; i++)
		{
			STACK::operator>>(elem);
			s2<<(elem);
		}
		STACK::operator<<(e);
	}
	return *this;
}
QUEUE& QUEUE::operator>>(int &e)
{
	int elem;
	if (s2.operator int()!= 0)//如果s2非空直接出s2
	{
		s2>>(e);
	}
	else//否则先倒入s2再出栈
	{
		int n = STACK::operator int();
		for (int i = 0; i < n; i++)
		{
			STACK::operator>>(elem);
			s2<<(elem);
		}
		s2>>(e);
	}
	return *this;
}
QUEUE& QUEUE::operator=(const QUEUE&s)//调用基类和成员函数的赋值运算符
{
	STACK::operator =(s);
	s2 = s.s2;
	return *this;
}
void QUEUE::print() const
{
	int n = this->operator int();
	for (int i = 0; i < n; i++)//遍历取元素并打印
	{
		std::cout << QUEUE::operator[](i) << "  ";
	}
}
QUEUE::~QUEUE()
{
	
}
int main(int argc, char **argv)
{
	if (argc == 1)
	{
		int m = 0;
		int M = 0;
		int f = 0;
		int F = 0;
		if ((m > M) || (f > F))
		{
			return -1;
		}
		QUEUE* QueMale = new QUEUE(M);
		QUEUE* QueFemale = new QUEUE(F);
		for (int i = 0; i < M; i++)
		{
			if (i == M - m)
			{
				QueMale->operator<<(1);
			}
			else
			{
				QueMale->operator<<(0);
			}
		}
		for (int i = 0; i <F; i++)
		{
			if (i == F - f)
			{
				QueFemale->operator<<(1);
			}
			else
			{
				QueFemale->operator<<(0);
			}
		}
		int cnt = 0;
		int male = 0;
		int female = 0;
		while (1)
		{
			QueMale->print();
			cout << "\n\r";
			QueFemale->print();
			cout << "\n\r";
			cout << "\n\r";
			QueMale->operator>>(male);
			QueFemale->operator>>(female);
			cnt++;
			if ((male == 1) && (female == 1))
			{
				return cnt;
			}
			QueMale->operator<<(male);
			QueFemale->operator<<(female);
		}
		return 0;
	}
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
			int n = q->operator int();
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
	//scanf_s("%s", str);
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
