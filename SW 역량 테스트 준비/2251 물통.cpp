//https://www.acmicpc.net/problem/2251
//https://code.plus/lecture/347

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <map>
#include <algorithm>






using namespace std;

bool valid(int i, int j, tuple<int, int, int> cap, tuple<int, int, int> now)
{
	// i to j
	int capacity[3],water[3];
	capacity[0] = get<0>(cap);
	capacity[1] = get<1>(cap);
	capacity[2] = get<2>(cap);
	water[0] = get<0>(now);
	water[1] = get<1>(now);
	water[2] = get<2>(now);

	if (capacity[j] == water[j])	//j is full
		return false;
	if (water[i] == 0 ) //i is empty
		return false;

	return true;
}

tuple<int, int, int> pour(int i, int j, tuple<int, int, int> cap, tuple<int, int, int> now)
{
	int capacity[3], water[3];
	capacity[0] = get<0>(cap);
	capacity[1] = get<1>(cap);
	capacity[2] = get<2>(cap);

	water[0] = get<0>(now);
	water[1] = get<1>(now);
	water[2] = get<2>(now);

	if (water[i] + water[j] <= capacity[j])
	{
		water[j] += water[i];
		water[i] = 0;
		return make_tuple(water[0], water[1], water[2]);
	}

	water[i] = water[i] + water[j] - capacity[j];
	water[j] = capacity[j];
	
	return make_tuple(water[0], water[1], water[2]);

	
}
vector<int> bfs(int A, int B, int C)
{
	tuple<int, int, int> Capacity = make_tuple(A, B, C);
	vector<int> ans;
	map< tuple<int, int, int>, bool> m;
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0, 0, C));
	m.insert(make_pair(make_tuple(0, 0, C), true));

	while (!q.empty())
	{
		tuple<int,int,int> now = q.front();
		int now_A = get<0>(now);
		int now_C = get<2>(now);
		q.pop();
		if (now_A == 0)
			ans.push_back(now_C);
		

		//cout << "Now...... " << get<0>(now) << ' ' << get<1>(now) << ' ' << get<2>(now) << '\n';

		for(int i=0; i<3; ++i)
			for (int j = 0; j < 3; ++j)
			{
				if (i == j)
					continue;
				if (!valid(i, j, Capacity, now))
					continue;

				tuple<int, int, int> next = pour(i, j, Capacity, now);

				if (m[next])
					continue;
				m[next] = true;
				//cout << "Pusing... " << get<0>(next) << ' ' << get<1>(next) << ' ' << get<2>(next) << '\n';
				q.push(next);
			}
	}

	return ans;
}

int main()
{
	int A, B, C;

	cin >> A >> B >> C;

	vector<int>ans = bfs(A, B, C);

	sort(ans.begin(), ans.end());
	ans.erase( unique( ans.begin(), ans.end()),ans.end());
	int size = ans.size();
	for (int i = 0; i < size; ++i)
		cout << ans[i]<<' ';
	cout << '\n';
	return 0;
}
