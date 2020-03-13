//https://www.acmicpc.net/problem/11727

#include <iostream>
using namespace std;
#define MAX 1001
#define MOD 10007

int main()
{
	int arr[MAX];
	int n;
	cin >> n;
	arr[1] = 1;
	arr[2] = 3;

	for (int i = 3; i <= n; ++i)
	{
		arr[i] = (2* arr[i - 2] + arr[i - 1])%MOD;
	}

	cout << arr[n]<<'\n';
	return 0;
}
