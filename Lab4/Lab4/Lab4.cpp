// Lab4.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int n;
int arr[12] = { 0 };
int min=99999;

void addcircle(vector<int> &circle, vector<int> &center, int r)
{
	float temp = 0;
	float p = 0;
	for (int i = 0; i < circle.size(); i++)
	{
		p = sqrt((r + circle[i])*(r + circle[i]) - (r-circle[i])*(r - circle[i]));
		if (p + center[i] > temp)
		{
			temp = center[i] + p;
		}
	}
	circle.push_back(r);
	center.push_back(temp);
}

int length(vector<int>circle,vector<int> center)
{
	int l=999999, r=-9999999;
	for (int i = 0; i < n; i++)
	{
		if (center[i] - circle[i] < l)
		{
			l = center[i] - circle[i];
		}
		if (center[i] + circle[i]>r)
		{
			r = center[i] + circle[i];
		}
	}
	return r - l;
}

void fun()
{
	queue<vector<int>> circle;
	queue<vector<int>> center;
	queue<vector<int>> index;
	vector<int> temp;
	circle.push(temp);
	center.push(temp);
	index.push(vector<int>(10));
	while (!circle.empty())
	{
		if (circle.front().size() == n)
		{
			int len = length(circle.front(), center.front());
			if (len < ::min)
			{
				::min = len;
			}
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				if (index.front()[i] == 0)
				{
					vector<int> temp_r(circle.front()), temp_c(center.front()), temp_i(index.front());
					addcircle(temp_r, temp_c, arr[i]);
					temp_i[i] = 1;
					center.push(temp_c);
					circle.push(temp_r);
					index.push(temp_i);
				}
			}
		}
		center.pop();
		index.pop();
		circle.pop();
	}
	cout << ::min << endl;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	fun();
    return 0;
}

