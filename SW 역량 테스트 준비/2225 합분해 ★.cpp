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

	for (int N = 0; N <= n; ++N)	//첨자 주의... N =0 부터
	{
		for (int K = 2; K <= k; ++K)
		{

			for (int i = 0; i <= N; ++i)
			{
				dp[N][K] += dp[i][K - 1];	//0 이 들어갔음 주의
				dp[N][K] %= MOD;		//dp[0][??]는 항상 1이어아햐는데
			}					// 28번쨰 줄 += 떄문에 초기값이 이미 1로 들어가있으면 고장남
		} 						// dp[0][??]는 이 프로그램에서는 항상 그떄그떄 구해야함 
	}

	cout << dp[n][k] << '\n';

	/*for (int i = 0; i <= n; ++i)
	{
		for (int j = 1; j <= k; ++j)
			cout << dp[i][j] << " ";
		cout << '\n';

	}*/



	return 0;
}
