// 第三届程序设计大赛 汽车加油.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	vector<int> station;
	int n,k,max,t=0;
	int x, last=0;
	cin >> n >> k;
	max = k;
	for (int i = 0; i <= n; i++)
	{
		cin >> x;
		if (x >= max)
		{
			cout << "No Solution" << endl;
			return 0;
		}
		else
		{
			if (k - x < 0)
			{
				k = max;
				t++;
			}
			k -= x;
		}
		last = x;
	}
	cout << t << endl;
    return 0;
}

