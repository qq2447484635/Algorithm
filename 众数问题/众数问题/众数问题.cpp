// 众数问题.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <time.h>
#include <iterator>
#include <cstdio>

using namespace std;

void quik_input(int &a)
{
	char c;
	a = 0;
	do
	{
		c = getchar();
	} while (!(c <= '9'&&c >= '0'));
	while (c >= '0'&&c <= '9')
	{
		a *= 10;
		a += c - '0';
		c = getchar();
	}
}

int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)(b);
}
int Mode = 0;
int ModeCount = 0;

int middle(int *arr, int left, int right)
{
	return arr[(right + left) / 2];
}

int count(int *arr, int cur,int &left,int &right)
{
	int c=1;
	int p = cur-1;
	while (p>=left&&arr[p] == arr[cur])
	{
		c++;p--;
	}
	left = p;
	p = cur + 1;
	while (p<=right&&arr[p]==arr[cur])
	{
		c++; p++;
	}
	right = p;
	return c;
}

int mode(int *arr,int left,int right)
{
	int lr=left, rr=right;
	int mid = middle(arr, left, right);
	int midc = count(arr, (left + right) / 2,lr,rr);
	if (midc > ModeCount)
	{
		ModeCount = midc;
		Mode = mid;
	}
	if (lr - left > ModeCount)
	{
		mode(arr, left, lr);
	}
	if (right - rr > ModeCount)
	{
		mode(arr, rr, right);
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int *arr[20] = {0};
	int n[20] = { 0 };
	int second;
	char count[3] = {0};
	string file;
	cin >> file;
	int filecount = 1;

	//load test data
	while (1)
	{
		_itoa_s(filecount , count, 10);
		ifstream in(file + "\\TEST\\MODE" + count + ".IN");
		if (!in.is_open())
		{
			break;
		}
		cout << file + "\\TEST\\MODE" + count + ".IN" << endl;
		FILE *err;
		freopen_s(&err, string(file + "\\TEST\\MODE" + count + ".IN").data(), "r", stdin);
		//scanf_s("%d", n + filecount);
		quik_input(n[filecount]);
		arr[filecount] = (int*)new int[n[filecount]];
		for (int i = 0; i < n[filecount]; i++)
		{
			quik_input(arr[filecount][i]);
			//scanf_s("%d", &arr[filecount][i]);
			//in>>arr[filecount][i];
		}
		filecount++;
		in.close();
	}

	for (int j = 1; j < filecount; j++)
	{
		_itoa_s(j, count, 10);
		ifstream out(file + "\\ANSWER\\MODE" + count + ".OUT");
		second = clock();
		//
		qsort(arr[j], n[j], sizeof(int), cmp);
		mode(arr[j], 0, n[j]-1);
		//
		int test1, test2;
		out >> test1 >> test2;

		printf("%-8d %-8d    ",Mode,ModeCount);
		if (Mode == test1 && ModeCount == test2)
		{
			cout << "AC";
		}
		else
		{
			cout << "WA";
		}
		cout << " " << (clock() - second) / 1000.0 << endl;
		Mode = ModeCount = 0;
		out.close();
	}

	//release
	for (int i = 0; i < filecount; i++)
	{
		delete arr[i];
	}
    return 0;
}

