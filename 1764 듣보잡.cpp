//https://www.acmicpc.net/problem/1764

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;

	cin >> n >> m;
	vector<string> N(n);
	vector<string> M(m);
	map<string, bool> mymap;

	for (int i = 0; i < n; ++i)
	{
		cin >> N[i];
		mymap.insert(make_pair(N[i], true));
	}

	for (int j = 0; j < m; ++j)
		cin >> M[j];

	sort(M.begin(), M.end());
	vector<string> ans;

	for (int i = 0; i < M.size(); ++i)
	{
		if (mymap[M[i]])
			ans.push_back(M[i]);
	}
	

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i]<<'\n';

	return 0;
}
