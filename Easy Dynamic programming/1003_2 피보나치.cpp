#include<iostream>

using namespace std;
int fibonacci(int n);

int arr[41];
int main()
{
	int n,m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> n;
		if (n == 0)
			cout << "1 0\n";
		else
			cout << fibonacci(n - 1) << " " << fibonacci(n)<<'\n';
	}
	return 0;
}

int fibonacci(int n)
{
	int temp;

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
