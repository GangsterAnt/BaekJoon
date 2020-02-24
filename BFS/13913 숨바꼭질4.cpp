//https://www.acmicpc.net/problem/13913
#include<iostream>
#include<queue>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

int cost[100001];
int parent[100001];

void bfs(int start, int fin);

int main()
{
	int start, fin ,temp;

	cin >> start >> fin;
	if (start == fin)
		cout << 0 << '\n' << start << '\n';
	

	else 
	{

		for (int i = 0; i <= 100001; ++i)
			cost[i] = parent[i] = -1;

		bfs(start, fin);
		cout << cost[fin] << '\n';

		temp = fin;
		vector<int> q;

		while (1)
		{
			if (temp != -1)
			{
				q.push_back(temp);
				temp = parent[temp];
			}
			else
				break;
		}

		reverse(q.begin(), q.end());
		for (int i = 0; i < q.size(); ++i)
			cout << q[i] << " ";
		cout << '\n';
	}

	return 0;

}

void bfs(int start, int fin)
{
	cost[start] = 0;
	queue<int> path;
	path.push(start);
	while (!path.empty())
	{
		int here = path.front(); path.pop();

		if (here == fin)
		{
			return;
		}
		// here +1
		if (here + 1 <= 100001 && cost[here + 1] == -1) // here + 1 <= fin 으로 하면 틀린다
		{
			cost[here + 1] = cost[here] + 1;
			path.push(here + 1);
			parent[here + 1] = here;
		}
		//here -1
		if (here - 1 >= 0 && cost[here - 1] == -1)
		{
			cost[here - 1] = cost[here] + 1;
			path.push(here - 1);
			parent[here - 1] = here;
		}
		//here *2 
		if (here * 2 <= 100001 && cost[here * 2] == -1) // here *2 <= fin 으로 하면 틀린다
		{
			cost[here * 2] = cost[here] + 1;
			path.push(here * 2);
			parent[here * 2] = here;
		}
	}


}
