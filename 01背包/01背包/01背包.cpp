// 01背包.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <time.h>

using namespace std;

struct item
{
	int weight;
	int value;
};

int main()
{
	int bagweight;
	int itemcount;
	item items[20005] = {0};
	item bag[50005] = { 0 };

	cin >> bagweight >> itemcount;
	for (int i = 0; i < itemcount; i++)
	{
		cin >> items[i].weight;
		cin >> items[i].value;
	}

	for (int i=0; i < itemcount; i++)
	{
		for (int weight = bagweight ; weight > 0; weight--)
		{
			if (items[i].weight <= weight)
			{
				int a, b;
				a = bag[weight].value;
				b = bag[weight - items[i].weight].value + items[i].value;
				bag[weight].value =  a>b?a:b;
			}
		}
	}

	cout << bag[bagweight].value << endl;

    return 0;
}

