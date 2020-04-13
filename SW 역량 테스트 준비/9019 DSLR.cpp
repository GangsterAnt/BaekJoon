//복습 https://github.com/GangsterAnt/BaekJoon/blob/master/BFS/9019%20DSLR.cpp ,
//https://github.com/GangsterAnt/BaekJoon/blob/master/BFS/9019%20DSLR_2.cpp
//https://www.acmicpc.net/problem/9019
//https://code.plus/lecture/347

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

#define MOD 10000

using namespace std;
vector< tuple<bool, char,int>> visited;

vector<char> bfs(int n, int m)
{

	visited = vector <tuple<bool, char, int>>(10001, make_tuple(false, 'X', -1));
	queue<int> q;
	vector<char> ret;
	get<0>(visited[n]) = true;
	get<1>(visited[n]) = 'X';
	get<2>(visited[n]) = -1;
	q.push(n);

	while (!q.empty())
	{
		int tmp = q.front();
		q.pop();

		if (tmp == m)
		{
			int now = m;
			while ( get<2>(visited[now]) != -1)
			{
				//cout << now << "'s get<2> is " << get<2>(visited[now]) << " So.. Push back " << get<1>(visited[now]) << '\n';
				ret.push_back( get<1>(visited[now] ) );
				now = get<2>(visited[now]);
			}

			reverse(ret.begin(), ret.end());

			return ret;
		}

		// D
		int target = (tmp * 2)  % MOD;

		if (!get<0>(visited[target]))
		{
			get<0>(visited[target]) = true;
			get<1>(visited[target]) = 'D';
			get<2>(visited[target]) = tmp;
			q.push(target);
		}

		// S
		target = (tmp - 1);
		if (target == -1)
			target = 9999;

		if (!get<0>(visited[target]))
		{
			get<0>(visited[target]) = true;
			get<1>(visited[target]) = 'S';
			get<2>(visited[target]) = tmp;
			q.push(target);
		}

		//L

		int rest = tmp / 1000;
		target = (tmp - rest*1000)*10 + rest;

		if (!get<0>(visited[target]))
		{
			get<0>(visited[target]) = true;
			get<1>(visited[target]) = 'L';
			get<2>(visited[target]) = tmp;
			q.push(target);
		}

		//R
		rest = tmp % 10;
		target = (tmp / 10) + rest * 1000;

		if (!get<0>(visited[target]))
		{
			get<0>(visited[target]) = true;
			get<1>(visited[target]) = 'R';
			get<2>(visited[target]) = tmp;
			q.push(target);
		}

	}

	return ret;
}

int main()
{
	int t, n, m;

	cin >> t;

	while (t--)
	{
		cin >> n >> m;
		vector<char> ans = bfs(n, m);

		for (int i = 0; i < ans.size(); ++i)
			cout << ans[i];
		cout << '\n';
	}
	return 0;
}
