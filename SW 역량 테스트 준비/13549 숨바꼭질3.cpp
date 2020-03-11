//https://www.acmicpc.net/problem/1697
// BFS 이지만 가중치가 다르다 0 ,1 이므로 가중치 0인 간선은 deque의 push_front() 를 사용
// 추후에 간선의 가중치가ㅣ 많이 다르면 다익스트라 필요할듯
#include <iostream>
#include <cstring>
#include <deque>

using namespace std;

#define PATH 2000001

int visited[PATH];
int start, fin;

void bfs(int start, int fin)
{
	deque<int> q;
	q.push_front(start);
	visited[start] = 0;

	while (!q.empty())
	{
		int now = q.front();
		q.pop_front();

		if (now == fin)
		{
			cout << visited[now] << '\n';
			return;
		}

		int arr[3];
		arr[2] = now - 1;
		arr[1] = now + 1;
		arr[0] = now * 2;

		for (int i = 0; i < 3; ++i)
		{
			if (arr[i] < 0 || arr[i] >= PATH)
				continue;

			if (visited[arr[i]] == -1)
			{
				if (i == 0)
				{
					visited[arr[i]] = visited[now];
					q.push_front(arr[i]);
				}
				else
				{
					visited[arr[i]] = visited[now]+1;
					q.push_back(arr[i]);
				}
			}
			
		}

	}
	return;
}

int main()
{
	cin >> start >> fin;
	memset(visited, -1, sizeof(visited));
	bfs(start, fin);

	return 0;
}
