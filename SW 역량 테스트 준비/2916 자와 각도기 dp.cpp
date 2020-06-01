//https://www.acmicpc.net/problem/2916
//http://codeplus.codes/aff19293ab874affb8d544132acfc7d7

#include <iostream>
#include <cstring>

#define MOD 360
using namespace std;



void dp(bool angle[],int arr[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int k = 0; k < 360; k++)
		{
			for (int j = 0; j < 360; ++j)
			{
				if (angle[j] == false)continue;
				angle[(j - arr[i] + 360) % 360] = true;
				angle[(j + arr[i]) % 360] = true;
			}
		}
	}
	
}
int main()
{
	
	bool angle[360];
	int arr[10];
	int question[10];
	int n, k;

	memset(angle, false, sizeof(angle));
	angle[0] = true;
	cin >> n >> k;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		angle[arr[i]] = true;
	}

	dp(angle,arr,n);

	while (k--)
	{
		int tmp;
		cin >> tmp;

		cout << (angle[tmp] ? "YES\n" : "NO\n") ;
	}
	
	

	return 0;
}
