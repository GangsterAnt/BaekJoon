//https://www.acmicpc.net/problem/2422
//http://codeplus.codes/b2471306cc954cefa56a396c183f2d4d
// 걍 3중 for 루프 돌려버림 
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	n++;
	vector<bool> visited(n, false);
	vector< vector<bool>> v(n, vector<bool>(n, false));
	for (int i = 0; i < m; ++i)
	{
		int t1, t2;
		cin >> t1 >> t2;
		v[t1][t2] = true;
	}

	int ans = 0;

	for (int i = 1; i < n-2; ++i)
	{
		if (visited[i])
			continue;
		visited[i] = true;
		for (int j = i + 1; j < n - 1; ++j)
		{
			if (visited[j])
				continue;
			if (v[i][j] || v[j][i])
				continue;
			visited[j] = true;

			for (int k = j + 1; k < n; ++k)
			{
				if (visited[k])
					continue;
				if (v[k][i] || v[k][j])
					continue;
				if (v[j][k] || v[i][k])
					continue;

				visited[k] = true;
				ans++;
				visited[k] = false;
			}
			visited[j] = false;
		}
		visited[i] = false;
	}
	cout << ans<<'\n';
	return 0;
}
