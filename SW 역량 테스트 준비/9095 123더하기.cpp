#include <iostream>
#include <string.h>
using namespace std;

int howmany(int n);

int arr[12];

int main()
{
	int T;
	cin >> T;

	memset(arr, 0, sizeof(arr));

	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4; //1 1 1 ,1 2 , 2 1 , 3 

	while (T--)
	{
		int tc;
		cin >> tc;

		cout << howmany(tc)<<'\n';

	}

	return 0;
}

int howmany(int n)
{
	if (arr[n])
		return arr[n];
	else
	{
		arr[n] = howmany(n - 1) + howmany(n - 2) + howmany(n - 3);

		return arr[n];
	}
}
