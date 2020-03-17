//https://www.acmicpc.net/problem/10844

#include <iostream>
#include <cstring>

using namespace std;

#define MOD 1000000000
#define MAX 101

long long dp[MAX][10];


void dynamic()
{
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= 9; ++i)
		dp[1][i] = 1;

	for(int i=2; i<MAX;++i)
		for (int j = 0; j <= 9; ++j)
		{
			if (j == 0)
				dp[i][j] = dp[i - 1][j + 1];
			else if (j == 9)
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
		}


}

int main()
{
	dynamic();

	int n;
	cin >> n;

	int temp = 0;
	for (int i = 0; i <= 9; ++i)
	{
		temp += dp[n][i];
		temp %= MOD;	//For 루프 밖에서 MOD 연산시 + 를 10번하면서 오버플로우가 이미 생겨버림.. 각 연산 마다 
	}

	

	cout << temp << '\n';

	return 0;

}
