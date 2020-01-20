//https://www.acmicpc.net/problem/2309

#include<iostream>
#include <algorithm>
using namespace std;

void search(int* arr, int i, int j);

int main()
{
	int arr[9];
	for (int i = 0; i < 9; ++i)
		cin >> arr[i];

	sort(arr, arr+9);

	search(arr, 0, 1);

	return 0;

}

void search(int* arr, int i, int j)
{
	int temp = 0;

	for (int a = 0; a < 9; ++a)
	{
		if (a == i || a == j)
			continue;
		temp += arr[a];
	}

	

	if (temp == 100)
	{
		for (int b = 0; b < 9; ++b)
		{
			if (b == i || b == j)
				continue;
			else
				cout << arr[b]<<'\n';
		}
	}
	else
	{
		if (j != 9)
			search(arr, i, j + 1);
		else if( i !=9)
			search(arr, i + 1, 0);
	}

}
