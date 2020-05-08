//https://www.acmicpc.net/problem/12865
//https://code.plus/lecture/350

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, k;
	int ans = 0;
	cin >> n >> k;

	vector<int> w(n+1,0);
	vector<int> v(n+1,0);
	vector< vector<int>> dp(n+1, vector<int>(k+1,0));	// n x (k+1) 의 size... 세로축 n 은 물건 index, 가로축 k+1 은 무게 value
													// dp[i][j] 는 i 번째까지의 물건만을 고려, 무게 한계를 j로 늘렸을때, 가치
	for (int i = 1; i <= n; i++)
		cin >> w[i] >> v[i];
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= k; ++j)
		{
			dp[i][j] = dp[i - 1][j];	//넣지 않은 경우
			if( j-w[i] >= 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
				// 넣은경우 , 이때 max(dp[i-1][j], dp[i - 1][j - w[i]] + v[i]);로 바로 수행할시
				// 조건문에 안걸리는 경우 그대로 dp[i][j] =0 이므로 넣지않은 경우는 위에서 처리해줘야 한다.
			ans = max(ans, dp[i][j]);
		}
	}
	// 점화식 dp[i][j] = max ( dp[i-1][j], dp[i-1][j -w[i]] + v[i]);

	/*for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= k; ++j)
			cout << dp[i][j] << ' ';
		cout << '\n';
	}*/
	
	cout << ans << '\n';
	return 0;
}
