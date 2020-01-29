#include <iostream>
#include <algorithm>
using namespace std;

int iterative(int coin_index, int cost);
int coin[101];
int k[10001];

int coin_num, goal;

int main()
{
	k[0] = 0;	//기저..0 원을 만들기 위한 동전은? 0개



	cin >> coin_num >> goal;

	for (int i = 1; i <= goal; ++i)
		k[i] = 10000;	//최소값을 구하는 문제이기때문에 큰 임의의 값 할당.

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
		//동전 1과 비슷.. goal을 만드는 coin의 개수는 goal - coin[i] 에 coin[i] 1개를 추가하는 것과 같다.
	}

	return k[cost];
}
