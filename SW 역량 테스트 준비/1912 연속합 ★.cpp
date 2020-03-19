//https://www.acmicpc.net/problem/1912

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> v,dp;

void dynamic()
{
	int ret = v[0];
	for (int i = 1; i < dp.size(); ++i)
	{
		dp[i] = max(dp[i - 1] + v[i], dp[i]);
		ret = max(ret, dp[i]);
	}

	cout << ret << '\n';

	return;
}

int main()
{
	int n;
	cin >> n;
	dp = v = vector<int>(n, 0);

	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
		dp[i] = v[i];
	}

	
	dynamic();

	return 0;
}
