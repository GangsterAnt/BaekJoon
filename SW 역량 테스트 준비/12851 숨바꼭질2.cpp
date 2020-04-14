//https://www.acmicpc.net/problem/12851
//https://code.plus/lecture/347
// with Dp
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;
#define MAX 100000
int cnt[MAX+1];
int dist[MAX+1];

void bfs(int n, int k)
{
	for (int i = 0; i < MAX + 1; ++i)
	{
		cnt[i] = 0;
		dist[i] = -1;
	}

	queue<int> q;
	q.push(n);
	dist[n] = 0;
	cnt[n] = 1;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		

		for (int next : {now + 1, now - 1, now * 2})
		{
			
			if (0 <= next && next <= MAX)
			{
				if (dist[next] == -1)
				{
					
						dist[next] = dist[now] + 1;
						cnt[next] = cnt[now];
						q.push(next);
					
				}
				else if (dist[next] == dist[now] + 1)//발견 했지만... 최소거리
					cnt[next] += cnt[now];

			}
		}
	}



}
int main()
{
	int n, k;
	cin >> n >> k;

	bfs(n, k);

	cout << dist[k] << '\n' << cnt[k] << '\n';
	return 0;
}
