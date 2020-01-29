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
		점화식 .. iterative(i , cost) = iterative( i-1, cost) + iterative( i, cost - coin[i])
						 i 제외한 coin으로만 구성된것  coin[i]를 포함한 cost-coin[i]를 구성한것 
					우항은 다시 점화식으로 쪼개지며 .
	순서대로 iterative(i ,cost - coin[i]) -> coin[i]를 1번 쓴것.
	iterative( i, cost - coin[i] - coin[i]) -> coin[i]를 2번 쓴것...... 을 모두 커버한다
 		cout << '\n';*/
		for (int j = 1; j <= cost; ++j)
			if (j - n[i] >= 0)
				k[j] += k[j - n[i]];
	}
	
	return k[cost];
}
