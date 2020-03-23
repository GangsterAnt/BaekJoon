//https://www.acmicpc.net/problem/2225

#include<iostream>
#include <cstring>
using namespace std;

#define MOD 1000000000

int main()
{
	long long  dp[201][201];
	memset(dp, 0, sizeof(dp));

	int n, k;

	cin >> n >> k;

	for (int i = 0; i <= n; ++i)
		dp[i][1] = 1;

	for (int N = 0; N <= n; ++N)
	{
		for (int K = 2; K <= k; ++K)
		{

			for (int i = 0; i <= N; ++i)
			{
				dp[N][K] += dp[i][K - 1];
				dp[N][K] %= MOD;
			}
		} 
	}

	cout << dp[n][k] << '\n';

	for (int i = 0; i <= n; ++i)
	{
		for (int j = 1; j <= k; ++j)
			cout << dp[i][j] << " ";
		cout << '\n';

	}



	return 0;
}
