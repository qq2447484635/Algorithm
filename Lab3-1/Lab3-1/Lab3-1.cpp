// Lab3-1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

string trans;
int n, m;
int min = 99;
int maxdepth=0;
int maxmulti = 0;
int multistep = 0;
void dfs(int step,int n,string t)
{
	if (step == maxdepth||step>=min)
	{
		return;
	}
	if (n == m&&step<min)
	{
		min = step;
		trans = t;
		return;
	}
	if (n!=0)
	{
		if (multistep < maxmulti)
		{
			dfs(step + 1, n * 3, t + 'f');
			multistep++;
		}
		multistep--;
		dfs(step + 1, n / 2, t + 'g');
	}
}


int main()
{
	cin >> n >> m;
	double temp = n;
	while (temp < m)
	{
		temp *= 1.5;
		maxmulti++;
	}
	for (int i = 0; i < 30; i++)
	{
		maxdepth++;
		if (min != 99)
		{
			break;
		}
		dfs(0, n, string());
	}
	cout << min << endl << trans << endl;
	return 0;
}