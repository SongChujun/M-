#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
int StrToInt(const char* pc);
using namespace std;
class QUEUE {
	int  *const  elems;	//申请内存用于存放队列的元素
	const  int   max;	//elems能存放的最大元素个数
	int   head, tail;		//队列头和尾，队列空时head=tail;初始时head=tail=0
public:
	QUEUE(int m);		//初始化循环队列：elems有m个元素
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

QUEUE::QUEUE(int m) :max(m), elems(new int[m])
{
	head = tail = 0;
}
QUEUE::QUEUE(const QUEUE &s):elems(new int[s.max]),max(s.max)
{
	head = s.head;
	tail = s.head;
}
QUEUE& QUEUE::operator<<(int e)
{
	if (head == max)
	{
		if (tail == 0)
		{
			return *this;
		}
		for (int i = 0; i < head - tail; i++)
		{
			elems[i] = elems[i + head - tail-1];
		}
		head = head - tail;
		tail = 0;
		elems[head] = e;
		head++;
	}
	else
	{
		elems[head] = e;
		head++;
	}
}
QUEUE::operator int() const
{
	return head - tail;
}
QUEUE& QUEUE::operator>>(int &e)
{
		e =elems[tail];
		tail++;
		return *this;
}
QUEUE& QUEUE::operator=(const QUEUE&s)
{
	if (this == &s)
		return *this;
	delete elems;
	const_cast<int*>(elems) = new int[s.max];
	/*int* modimax = const_cast<int*>(&max);
	*modimax = s.max;*/
	head = s.head;
	tail = s.tail;
	return *this;
}
void QUEUE::print() const
{
	for (size_t i = tail; i < head ; i++)
	{
		printf("%d", elems[i]);
		printf("  ");
	}
}
QUEUE::~QUEUE()
{
	delete elems;
}
int	QUEUE::full() const
{	if (head-tail+1==max)
		return 1;
	return 0;
}
int QUEUE::operator[ ](int x)const
{
	return elems[x+tail];
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
				if (q->operator int()==0)
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
			(*q)=(*tmp);
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
