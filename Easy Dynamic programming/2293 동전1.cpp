#include <iostream>
using namespace std;

int iterative(int coin_index, int cost);
int n[101];
int k[10001];
int coin_num, goal;
int main()
{
	k[0] = 1;

	

	cin >> coin_num >> goal;

	for (int i = 1; i <= coin_num; ++i)
		cin >> n[i];

	cout << iterative(coin_num, goal)<<'\n';
	
	/*for (int i = 0; i <= goal; ++i)
		cout << k[i] << " ";
	cout << '\n';*/
	return 0;
}

int iterative(int coin_index, int cost)
{
	for (int i = 0; i <= coin_index; ++i)
	{
		/*for (int i = 0; i <= goal; ++i)
			cout << k[i] << " ";
		cout << '\n';*/
		for (int j = 1; j <= cost; ++j)
			if (j - n[i] >= 0)
				k[j] += k[j - n[i]];
	}
	
	return k[cost];
}
