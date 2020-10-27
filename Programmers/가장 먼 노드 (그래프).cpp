#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

struct cmp
{
	bool operator()(int a, int b)
	{
		return a < b;
	}
};

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;

	int max_dist = 0;
	vector<int> dist(n+1, -1);
	vector<vector<int>> v( n+1 , vector<int>(n+1,0));
	//priority_queue< int, vector<int>, cmp> pq;
	queue<int> pq;

	for (int i = 0; i < edge.size(); ++i)
	{
		v[edge[i][0]][edge[i][1]] = 1;
		v[edge[i][1]][edge[i][0]] = 1;
	}

	pq.push(1);
	dist[1] = 0;

	while (!pq.empty())
	{
		int now = pq.front();
		pq.pop();

		for( int i= 1; i< v[now].size(); ++i)
		{
			if (dist[i] != -1)
				continue;
			if (v[now][i] != 1 )
				continue;
			dist[i] = dist[now] + 1;
			max_dist = max(max_dist, dist[i]);
			pq.push(i);
		}
	}

	for (int i = 1; i < dist.size(); ++i)
		cout << dist[i] << ' ';
	cout << '\n';

	for (int i = 1; i < dist.size(); ++i)
		if (dist[i] == max_dist)
			answer++;

	return answer;
}
