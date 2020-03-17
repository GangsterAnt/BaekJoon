//https://www.acmicpc.net/problem/11057

#include <iostream>
#include <cstring>

using namespace std;

#define MAX 1001
#define MOD 10007

long long dp[MAX][10];

void dynamic()
{
	memset(dp, 0, sizeof(dp));

	for (int i = 0; i <= 9; ++i)
		dp[1][i] = 1 ;	// "with" 0, initalize..

	for(int i=2; i<MAX;++i)	//start with 2 digit
		for (int j = 0; j <= 9; ++j)
		{
			for (int k = 0; k <= j; ++k)
			{
				dp[i][j] += dp[i - 1][k]; // 끝 자리가 j 이면  길이 i-1 에서 끝자리가 0 ,1,....,j 까지의 총합이  dp[i][j];
				dp[i][j] %= MOD;
			}
		}


}
int main()
{

	dynamic();

	int n;
	cin >> n;

	int temp=0;
	for (int i = 0; i <= 9; ++i)
	{
		temp += dp[n][i];
		temp %= MOD;
	}

	cout << temp << '\n';

	return 0;

}
