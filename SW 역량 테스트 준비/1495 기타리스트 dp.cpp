//https://www.acmicpc.net/problem/1495
//https://code.plus/lecture/350

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, s, m;	//n 은 개수 s 는 시작점, m 은 상한선.
	cin >> n >> s >> m;

	vector<int> v(n+1);
	vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

	v[0] = s;
	dp[0][s] = true;

	for (int i = 1; i <= n; ++i)
		cin >> v[i];

	for (int i = 1; i <=n; ++i)	//노래 index
	{
		for (int j = 0; j <=m; ++j) // volumn 
		{
			if (dp[i - 1][j] ==true)
			{
				if (j + v[i] <= m)
					dp[i][j + v[i]] = 1;
				if (j - v[i] >= 0)
					dp[i][j - v[i]] = 1;
			}
		}
	}

	//for (int i = 0; i <= n; ++i)
	//{
	//	for (int j = 0; j <= m; ++j)
	//		cout << dp[i][j] << ' ';
	//	cout << '\n';
	//}

	int ans = -1;

	for (int i = m; i >= 0; --i)
	{
		if (dp[n][i])
		{
			ans = i;
			break;
		}
	}
	
	cout << ans<<'\n';

	return 0;
}
