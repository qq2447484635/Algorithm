
// Lab1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <time.h>
#include <cstdlib>

using namespace std;

void GetCount(char* Num, int bit, long long Count[10], int len)
{
	if (bit!=1)
	{
		int t1,t2,t3;
		t1 = (bit - 1)*pow(10, bit - 2)*(Num[len - bit] - '0');
		for (int i = 0; i < 10; i++)//000-999
		{
			Count[i] += t1;
		}	 
		t2 = pow(10, bit - 1);
		for (int i = 0; i < Num[len - bit] - '0'; i++)//max
		{
			Count[i] += t2;
		}
		t3 = pow(10, bit - 1)*(Num[len - bit] - '0');
		for (int i = 0; i < len - bit; i++)
		{
			Count[Num[i] - '0'] += t3 ;
		}
		GetCount(Num, bit - 1, Count, len);
	}
	else
	{
		for (int i = 0; i <= Num[len - 1] - '0'; i++)
		{
			Count[i]++;
		}
   		for (int i = 0; i < len-1; i++)
		{
			Count[Num[i] - '0']+=Num[len-1]-'0'+1;
		}
		for (int i=0; i < len ; i++)
		{
			Count[0] -= pow(10, i);
		}
	}
}

void cmp(string in, string out);

int main()
{
	cmp("../Debug/TEST/COUNT", "../Debug/ANSWER/COUNT");
	cmp("TEST/COUNT", "ANSWER/COUNT");
	//RandomTest();
	system("pause");
    return 0;
}

void cmp(string in, string out)
{
	char filecount[10];
	for(int n=0;n<100;n++)
	{
		_itoa_s(n, filecount, 10);
		string _in, _out;
		_in = in + filecount + ".IN";
		_out = out + filecount + ".OUT";
		ifstream fin(_in);
		ifstream fout(_out);
		if (!fin.is_open() || !fout.is_open())
		{
			return;
		}
		char Num[20] = { 0 };
		int len;
		long long Count[10] = { 0 };
		fin >> Num;
		len = strlen(Num);
		GetCount(Num, len, Count, len);

		bool rt = true;
		for (int i = 0, temp = 0; i < 10; i++)
		{
			fout >> temp;
			if (temp != Count[i])
			{
				rt = false;
			}
		}
		if (rt)
		{
			cout << "AC" << endl;
		}
		else
		{
			cout << "WA" << endl;
		}
		fin.close();
		fout.close();
	}
}


