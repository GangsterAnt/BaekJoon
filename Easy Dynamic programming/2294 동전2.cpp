#include <iostream>
#include <algorithm>
using namespace std;

int iterative(int coin_index, int cost);
int coin[101];
int k[10001];

int coin_num, goal;

int main()
{
	k[0] = 0;



	cin >> coin_num >> goal;

	for (int i = 1; i <= goal; ++i)
		k[i] = 10000;

	for (int i = 1; i <= coin_num; ++i)
		cin >> coin[i];

	int temp = iterative(coin_num, goal);

	if ( temp == 10000)
		cout << "-1";
	else
		cout << temp;
	return 0;
}

int iterative(int coin_index, int cost)
{
	for (int index = 0; index <= coin_index; ++index)
	{
		for (int j = 1; j <= cost; ++j)
			if (j - coin[index] >= 0)
				k[j] = min( k[j - coin[index]] +1 ,k[j] ) ;
	}

	return k[cost];
}
