//https://www.acmicpc.net/problem/2193
#include<iostream>

using namespace std;
long long fibonacci(int n);

long long arr[91];
int main()
{
	int n;
	cin >> n;

	cout<< fibonacci(n)<<'\n';

	return 0;
}

long long fibonacci(int n)
{

	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else if (n == 2)
		return 1;
	else
	{
		if (arr[n] != 0)		//차별화... 저장된 값이 이씅면 주워쓴다
			return arr[n];
		else
			arr[n] = fibonacci(n - 2) + fibonacci(n - 1);

		return arr[n];
	}


}
