//https://www.acmicpc.net/problem/10422
//https://code.plus/lecture/350

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MOD 1000000007

int main()
{
	int T;
	cin >> T;

	vector<long long> dp(5001, 0);
	dp[0] = 1;
	dp[2] = 1;
	dp[4] = 2;

	for (int i = 6; i <= 5000; i += 2)
	{
		for (int j = 2; j <= i; j +=2 )
		{
			dp[i] += dp[j - 2] * dp[i - j] ;
			dp[i] %= MOD;
		}
	}
		
	while (T--)
	{
		int n;
		cin >> n;
		cout << dp[n]<<'\n';
	}

	return 0;
}
