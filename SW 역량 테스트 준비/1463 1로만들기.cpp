//https://www.acmicpc.net/problem/1463

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1000001
using namespace std;

int arr[MAX];
int arr2[MAX];

int topdown(int target) //메모리 초과, 점화식은 맞음 답도 
{
	if (arr2[target] )
		return arr2[target];

	else
	{
		if (target % 3 == 0 && target % 2 == 0)	// 6의 배수
		{
			arr2[target] = topdown(target / 3) +1;
		}
		else if (target % 3 == 0 )	//3의 배수
		{
			arr2[target] = min(topdown(target / 3), topdown(target - 1)) + 1;
		}
		else if ( target % 2 == 0) //2 의배수 
		{
			arr2[target] = min(topdown(target - 1), topdown(target / 2)) +1;
		}
		
		else
			arr2[target] = topdown(target - 1) +1;
		
		return arr2[target];
	}

}

int bottompup(int target)
{
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;

	int minimum;
	for (int i = 4; i <= target; ++i)
	{
		if (i % 3 == 0 && i % 2 == 0)
		{
			minimum = min(arr[i / 3], arr[i / 2]);
			minimum = min(minimum, arr[i - 1]);
		}
		else if (i % 3 != 0 && i % 2 == 0)
		{
			minimum = min(arr[i - 1], arr[i / 2]);
		}
		else if (i % 3 == 0 && i % 2 != 0)
		{
			minimum = min(arr[i / 3], arr[i - 1]);
		}
		else
			minimum = arr[i - 1];
		arr[i] = minimum + 1;
	}
	return arr[target];
}

int main()
{
	arr2[1] = 0;
	arr2[2] = 1;
	arr2[3] = 1;
	int target;
	cin >> target;
	

	cout << topdown(target) << '\n';
	for (int i = 1; i <= target; ++i)
		cout << arr2[i] << " ";
	cout << '\n';
	cout << bottompup(target) << '\n';

	for (int i = 1; i <= target; ++i)
		cout << arr[i] << " ";
	return 0 ;
}
