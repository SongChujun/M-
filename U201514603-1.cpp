#include<stdio.h>
#include<iostream>
#include <stdexcept>
#include<string>
#include<malloc.h>
#include<cstdlib>
#include<math.h>
#include<string.h>
using namespace std;
struct STACK {
	int  *elems;	//申请内存用于存放栈的元素
	int   max;	//栈能存放的最大元素个数
	int   pos;	//栈实际已有元素个数，栈空时pos=0;
};
void initSTACK(STACK *const p, int m);	//初始化p指向的栈：最多m个元素
void initSTACK(STACK *const p, const STACK&s); //用栈s初始化p指向的栈
int  size(const STACK *const p);		//返回p指向的栈的最大元素个数max
int  howMany(const STACK *const p);	//返回p指向的栈的实际元素个数pos
int  getelem(const STACK *const p, int x);	//取下标x处的栈元素
STACK *const push(STACK *const p, int e); 	//将e入栈，并返回p
STACK *const pop(STACK *const p, int &e); 	//出栈到e，并返回p
STACK *const assign(STACK*const p, const STACK&s); //赋s给p指的栈,并返回p
void print(const STACK*const p);			//打印p指向的栈
void destroySTACK(STACK*const p);		//销毁p指向的栈
int StrToInt(const char* pc);
void initSTACK(STACK *const p, int m)
{
	p->elems =(int*)malloc(40);
	//int *test = (int*)malloc(40);
	if (p->elems == NULL)
	{
		std::cout << "malloc failure" << std::endl;
		return;
	}
	p->max = m;
	p->pos = 0;
	return;
}
void initSTACK(STACK *const p, const STACK&s)
{
	p->elems =(int*)malloc((s.max*sizeof(int)));
	if (p->elems == NULL)
	{
		cout << "malloc failure" << endl;
		return;
	}
	p->max = s.max;
	p->pos = s.pos;
	for (int i = 0; i<s.pos; i++)
	{
		(p->elems)[i] = (s.elems)[i];
	}
	return;
}
int  size(const STACK *const p)
{
	return p->max;
}
int  howMany(const STACK *const p)
{
	return p->pos;
}
int  getelem(const STACK *const p, int x)
{
	if ((x<0) || (x >= p->pos))
	{
		cout << "E" << endl;
		return -1;
	}
	return (p->elems)[x];
}
STACK *const push(STACK *const p, int e)
{
	if (p->pos == p->max)
	{
		cout << "E" << endl;
		return NULL;
	}
	(p->elems)[p->pos] = e;
	p->pos++;
	return p;
}
STACK *const pop(STACK *const p, int &e)
{
	if (p->pos == 0)
	{
		cout << "E" << endl;
		return NULL;
	}
	(p->pos)--;
	e = (p->elems)[p->pos];
	return p;
}
STACK *const assign(STACK*const p, const STACK&s)
{
	free(p->elems);
	p->elems = (int*)malloc(s.max);
	if (p->elems == NULL)
	{
		cout << "E" << endl;
		return NULL;
	}
	for (int i = 0; i<s.pos; i++)
	{
		(p->elems)[i] = (s.elems)[i];
	}
	p->pos = s.pos;
	p->max = s.max;
	return p;
}
void print(const STACK*const p)
{
	for (int i = 0; i<p->pos; i++)
	{
		printf("%d", (p->elems)[i]);
		printf("  ");
	}
	return;
}
void destroySTACK(STACK*const p)
{
	free(p->elems);
}
int main(int argc, char **argv)
{
	STACK* p=(STACK*)malloc(sizeof(STACK));
	int n = std::stoi(argv[2],NULL,10);
	printf("S  ");
	printf("%d  ", n);
	initSTACK(p, n);
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
		else if (strcmp(argv[i],"-I")==0)
		{
			printf("I  ");
			for (j = i+1;(j<=(argc-1)&&(strcmp(argv[j], "-O")!=0)&&(strcmp(argv[j], "-I")!=0)&&(strcmp(argv[j], "-A")!=0)&&(strcmp(argv[j], "-C")!=0)&&(strcmp(argv[j], "-O")!=0)&&(strcmp(argv[j], "-G")!=0)); j++)
			{
				int test = StrToInt(argv[j]);
				if (howMany(p) == size(p))
				{
					cout << "E" << endl;
					return -1;
				}
				push(p,test);
			}
			print(p);
			i = j;
		}
		else if (strcmp(argv[i],"-O")==0)
		{
			printf("O  ");
			int num = argv[i+ 1][0] - '0';
			for (cnt = 0; cnt<num; cnt++)
			{
				if (howMany(p) == 0)
				{
					cout << "E" << endl;
					return 01;
				}
				pop(p, e);
			}
			i += 2;
			print(p);
		}
		else if(strcmp(argv[i],"-A")==0)
		{
			printf("A  ");
			STACK tmp=*p;
			p=(STACK*)malloc(sizeof(STACK));
			initSTACK(p,StrToInt(argv[i+1]));
			p=assign(p,tmp);
			i+=2;
			print(p);
		}
		else if(strcmp(argv[i],"-C")==0)
		{
			printf("C  ");
			STACK tmp=*p;
			p=(STACK*)malloc(sizeof(STACK));
			initSTACK(p,tmp);
			i+=1;
			print(p);
		}
		else if(strcmp(argv[i],"-G")==0)
		{
			printf("G  ");
			if (StrToInt(argv[i + 1]) > (howMany(p) - 1))
			{
				printf("E");
				return 0;
			}
			int m=getelem(p,StrToInt(argv[i+1]));
			printf("%d  ",m);
			i+=2;
		}
		else if(strcmp(argv[i],"-N")==0)
		{
			printf("N  ");
			int m=howMany(p);
			printf("%d  ",m);
			i+=1;
		}
	}
	char str[80];
	// scanf_s("%s", str);
	return 0;
}
int StrToInt(const char* pc)
{
	int res=0;
	int i=0;
	for(i=strlen(pc)-1;i>=0;i--)
	{
		if(!((pc[i]>='0')&&(pc[i]<='9')))
		{
			return -1;
		}
		res=res+(pc[i]-'0')*pow(10,strlen(pc)-1-i);
	}
	return res;
}