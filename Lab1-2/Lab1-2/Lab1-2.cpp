// Lab1-2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int C(int a, int b)
{
	int res = 1;
	int u = 1, d = 1;
	for (int i = 0; i < a; i++)
	{
		u *= b - i;
	}
	for (int i = 0; i < a; i++)
	{
		d *= i + 1;
	}
	res = u / d;
	return res;
}


int main()
{
	char code[7] = { 0 };
	int n;
	cin >> n;
	while (n--)
	{
		cin >> code;
		int length = strlen(code);
		int num = 0;
		for (int i = 1; i < length; i++)//+++++
		{
			num += C(i, 26);
		}
		for (int i = 'a'; i < code[0]; i++)//
		{
			num += C(length - 1, 26-i+'a'-1);
		}
		for (int i = 1; i < length; i++)//
		{
			for (int j = code[i - 1] - 'a' + 1; j < code[i] - 'a'; j++)
			{
				num += C(length - i - 1, 26 - j -1);
			}
		}
		cout << num + 1 << endl;
	}
	return 0;
}
       
