#include <stdio.h>
#include <iostream>
int StrToInt(const char* pc);
using namespace std;
class STACK {
	int  *const  elems;	//闂佽法鍠愰弸濠氬箯閻戣姤鏅搁柡鍌樺€栫€氬綊鏌ㄩ悢璇参濋弶鍫㈠亾鐎氬綊鏌ㄩ悢鍛婄伄闁归鍏橀弫鎾绘嚍閸屾繃褰ч柟椋庡厴閺佹挾绮旈梹鎰覆闁归鍏橀弫鎾绘儍閸♀晙鎮嶉柟椋庡厴閺佹捇鏁撻敓锟�
	const  int   max;	//闁哄秴鐗撻弫鎾诲级閹峰本褰ч柟椋庢焿椤曨垶鏌ㄩ悢鍛婄伄闁归鍏橀弫鎾诲棘閵堝棗顏堕柛蹇撳暣閺佹捇骞嬮鍫熶氦闁归鍏橀弫鎾诲棘閵堝棗顏�
	int   pos;			//闁哄秴鐗嗛悿鍕煥閻斿憡鐏柟椋庡厴閺佹捇寮妶鍡楊伓闂佽法鍠愰弸濠氬箯瀹勬澘甯楅梺璺ㄥ枑閸╁懘妫冮埡鍌氼伓闂佽法鍠愰弸濠氬箯閻戣姤鏅搁柡鍌樺€栫€氬綊寮介崼銉︽櫢闁哄倶鍊栫€氬綊寮粔鏀恠=0;
public:
	STACK(int m);		//闂佽法鍠愰弸濠氬箯瀹勯偊娼楅梺璺ㄥ枑閺嬪骞忛柨瀣灲闂佽法鍠愰弸濠氬箯閻戣姤鏅搁柡鍌樺€栫€氬綊鏌ㄩ悢杞拌吂闂佽法鍠愰弸濠氬箯瀹勬澘甯楅梺璺ㄥ枑閺嬪骞忛敓锟�
	STACK(const STACK&s); //闂佽法鍠愰弸濠氬箯闁垮鍨絪闂佽法鍠愰弸濠氬箯閻戣姤鏅搁柡鍌樺€栫€氬綊鏌ㄩ悢鍛婄伄闁瑰嘲鍢查～鎰版煥閻斿憡鐏柟鐑芥敱閻栵拷
	int  size() const;		//闂佽法鍠愰弸濠氬箯閻戣姤鏅搁柡鍌樺€栫€氬綊寮介崼銉︽櫢闁哄倶鍊栫€氬綊鏌ㄩ悢鍛婄伄闁归鍏橀弫鎾绘儍閸♀晙鎮嶉柟椋庡厴椤╁ジ鏌ㄩ悢鍛婄伄闁归鍏橀弫鎾跺緤椤﹀櫄
	int  howMany() const;	//闂佽法鍠愰弸濠氬箯閻戣姤鏅搁柡鍌樺€栫€氬綊寮介崼銉︽櫢闁哄倶鍊栫€氬湱鈧湱鍋ら弫鎾诲棘閵堝棗顏堕柛蹇撳暣閺佹捇骞嬮鍫熶氦闁归鍏橀弫鎾诲棘閵堝棗顏秔os
	int  getelem(int x) const;	//闁告瑦鐗犻弫鎾绘煣閻楀牆鏁鹃柟椋庮熆闂佽法鍠愰弸濠氬箯閻戣姤鏅搁柡鍌樺€栫€氬綊寮介崼婵嗗笚闂佽法鍠愰弸濠氬箯閿燂拷
	STACK& push(int e); 	//闂佽法鍠愰弸濠氬箯缁屽秹鏌ㄩ悢鍛婄伄闁圭兘鏀遍悥锟�,闂佽法鍠愰弸濠氬箯閻戣姤鏅搁柡鍌樺€栫€氬綊鏌ㄩ悢鍛婄伄闁圭兘鏀遍悥锟�
	STACK& pop(int &e); 	//闂佽法鍠愰弸濠氬箯闁垮鍨介梺璺ㄥ枑閺嬪骞忕粚锟�,闂佽法鍠愰弸濠氬箯閻戣姤鏅搁柡鍌樺€栫€氬綊鏌ㄩ悢鍛婄伄闁圭兘鏀遍悥锟�
	STACK& assign(const STACK&s); //闂佽法鍠愰弸濠氬箯缁屾繈鏌ㄩ悢鍛婄伄闁圭兘鏀遍悥锟�,闂佽法鍠愰弸濠氬箯閻戣姤鏅搁柡鍌樺€栫€氬綊鏌ㄩ悢绋跨劵闁规彃顑嗙€氬綊鏌ㄩ悢鍛婄伄闁瑰嘲鍢查埀顒€銈搁弫鎾诲棘閵堝棗顏堕柡宥忔嫹
	void print() const;		//闂佽法鍠愰弸濠氬箯瀹勬澘绁柡宥忔嫹
	~STACK();				//闂佽法鍠愰弸濠氬箯閻戣姤鏅搁柡鍌樺€栫€氬綊寮介敓锟�
};
STACK::STACK(int m):max(m), elems(new int [m])
{
	pos = 0;
}
STACK::STACK(const STACK&s):elems(new int[s.max]),max(s.max)
{
	pos = s.pos;
}
int  STACK::size() const
{
	return max;
}
int  STACK::howMany() const
{
	return pos;
}
int  STACK::getelem(int x) const
{
	return elems[x];
}
STACK& STACK::push(int e)
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
STACK& STACK::pop(int &e)
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
STACK& STACK::assign(const STACK&s)
{
	if (this == &s)
		return *this;
	delete elems;
	const_cast<int*>(elems)= new int[s.max];
	int* modimax = const_cast<int*>(&max);
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
	int n = StrToInt(argv[2]);
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
				if(p->howMany()==p->size())
				{
					std::cout << "E" << std::endl;
					return 0;
				}
				p->push(test);
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
				if(p->howMany()==0)
				{
					std::cout << "E" << std::endl;
					return -1;
				}
				p->pop(e);
			}
			i += 2;
			p->print();
		}
		else if (strcmp(argv[i], "-A") == 0)
		{
			printf("A  ");
			STACK* tmp = p;
			p->assign(*tmp);
			i += 2;
			p->print();
		}
		else if (strcmp(argv[i], "-C") == 0)
		{
			printf("C  ");
			STACK* tmp = p;
			STACK* tmp2=new STACK(*tmp);
			p = tmp;
			i += 1;
			p->print();
		}
		else if (strcmp(argv[i], "-G") == 0)
		{
			printf("G  ");
			int m = p->getelem(StrToInt(argv[i + 1]));
			if (StrToInt(argv[i + 1]) > (p->howMany() - 1))
			{
				printf("E");
				return 0;
			}
			printf("%d  ", m);
			i += 2;
		}
		else if (strcmp(argv[i], "-N") == 0)
		{
			printf("N  ");
			int m=p->howMany();
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
