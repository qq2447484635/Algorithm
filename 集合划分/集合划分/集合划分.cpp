// 集合划分.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int SetPartition(int ElemCount, int PartCount)
{
	if (ElemCount == 0 ||PartCount==0)
	{
		return 0;
	}
	else if (PartCount == 1||ElemCount==PartCount)
	{
		return 1;
	}
	else
	{
		return SetPartition(ElemCount - 1, PartCount - 1) + PartCount*SetPartition(ElemCount - 1, PartCount);
	}
}


int main()
{
	int n;
	cin >> n;
	int total = 0;
	for (int i = 1; i <= n; i++)
	{
		total += SetPartition(n, i);
	}
	cout << total << endl;
}

