//https://www.acmicpc.net/problem/2193

#include <iostream>
using namespace std;

long long dp[91][2];
long long dp2[91];

void dynamic()
{
	dp[1][1] = 1;
	dp[1][0] = 0;

	dp[2][1] = 0;
	dp[2][0] = 1;

	for (int i = 3; i <= 90; ++i)
	{
		dp[i][0] = dp[i - 1][1] + dp[i - 1][0];
		dp[i][1] = dp[i - 1][0];
	}
}

void dynamic2()
{
	dp2[1] = 1;
	dp2[2] = 1;

	for (int i = 3; i <= 90; ++i)
		dp2[i] = dp2[i - 1] + dp2[i - 2];
	/*
		왜 이게 피보나치가 되는가..?
	Sol 1)	by 식의 정리
		dp[i] = dp[i][0] + do[i][1]
			  = dp[i - 1][1] + dp[i - 1][0]   +  dp[i - 1][0]
			  =	dp[i-1] + (dp[i-1][0])
			  = dp[i-1] +( dp[i-2][1] +dp[i-1][0])
			  = dp[i-1] + dp[i-2]
	
	Sol 2) by 논리적 접근
		dp[i][0] = dp[i-1]의 뒤에 0을 붙이면 되므로 dp[i-1]의 개수와 같다.
		dp[i][1] = dp[i-2]의 뒤에 01을 붙이면 되므로 dp[i-2]의 개수와 같다.
		고로.. dp[i] = dp[i-1] + dp[i-2]
	
	*/


}

int main()
{
	dynamic();

	int n;
	cin >> n;
	cout << dp[n][1]+ dp[n][0] << '\n';
	return 0;
}
