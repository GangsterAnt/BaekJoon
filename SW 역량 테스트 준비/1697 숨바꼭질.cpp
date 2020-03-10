//https://www.acmicpc.net/problem/1697

#include <iostream>
#include <queue>

using namespace std;

#define PATH 2000001

int visited[PATH];
int start, fin;

void bfs(int start, int fin)
{
	queue<int> q;
	q.push(start);
	visited[start] = 1;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		if (now == fin)
		{
			cout << visited[now]-1 << '\n';
			return;
		}

		int arr[3];
		arr[0] = now - 1;
		arr[1] = now + 1;
		arr[2] = now * 2;

		for (int i = 0; i < 3; ++i)
		{
			if (arr[i] < 0 || arr[i] >= PATH)
				continue;
			if (!visited[arr[i]])
			{
				visited[arr[i]] = visited[now] + 1;
				q.push(arr[i]);
			}
		}

	}
	return;
}

int main()
{
	cin >> start >> fin;

	bfs(start, fin);

	return 0;
}
