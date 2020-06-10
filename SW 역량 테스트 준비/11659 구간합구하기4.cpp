//https://www.acmicpc.net/problem/11659

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int t = 0; t < n; ++t)
	{
		cin >> v[t];
	}

	for (int i = 1; i < n; ++i)
		v[i] += v[i - 1];


	for (int t = 0; t < m; ++t)
	{
		int i, j;
		cin >> i >> j;
		i--; j--;
		int ans;

		if (i == 0)
			ans = v[j];
		else
			ans = v[j] - v[i - 1];
		cout << ans<<'\n';
	}


	return 0;
}
