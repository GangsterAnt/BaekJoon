//복습 이미 풀었음 https://github.com/GangsterAnt/BaekJoon/blob/master/BFS/13913%20%EC%88%A8%EB%B0%94%EA%BC%AD%EC%A7%884.cpp
//https://www.acmicpc.net/problem/13913
//https://code.plus/lecture/347

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector< pair<bool, int>> visited;

vector<int> bfs(int n, int k)
{
	queue<int> q;
	vector<int>ans;
	q.push(n);
	visited[n].first = true;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		if (now == k)
		{
			ans.push_back(k);
			int now = k;

			while (visited[now].second != -1)
			{
				ans.push_back(visited[now].second);
				now = visited[now].second;
			}
			reverse(ans.begin(), ans.end());

			return ans;

		}
		
		int target = now + 1;

		if( target>=0 && target <=100000)
			if (!visited[target].first)
			{
				visited[target].first = true;
				visited[target].second = now;
				q.push(target);
			}

		target = now - 1;

		if (target>=0 && target <= 100000)
			if (!visited[target].first)
			{
				visited[target].first = true;
				visited[target].second = now;
				q.push(target);
			}

		target = now * 2;

		if (target>=0 && target <= 100000)
			if (!visited[target].first)
			{
				visited[target].first = true;
				visited[target].second = now;
				q.push(target);
			}
	}

	return ans;
}
int main()
{
	int n, k;
	cin >> n >> k;
	visited = vector<pair<bool, int>>(100001, make_pair(false, -1));

	vector<int>ans = bfs(n, k);

	cout << ans.size() - 1 << '\n';
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}
