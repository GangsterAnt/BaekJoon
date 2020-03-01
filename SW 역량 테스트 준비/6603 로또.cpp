//https://www.acmicpc.net/problem/6603

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int arr[20];
bool visited[20];
int c;
vector<int> v;

void dfs(int depth, int now,int threshold)
{
	if (now == depth)
	{
		
		for (int i = 0; i <depth; ++i)
			cout << v[i]<<" ";
		cout << '\n';

		return;
	}

	for (int i = threshold; i < c; ++i)
	{
		if (!visited[i])
		{
			visited[i] = true;
			v.push_back(arr[i]);

			dfs(depth, now + 1,i+1);

			visited[i] = false;
			v.pop_back();
		}
	}

}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> c;

	while (c !=0)
	{
		for (int i = 0; i < c; ++i)
			cin >> arr[i];

		sort(arr, arr + c);

		dfs(6, 0,0);
		cout << '\n';

		cin >> c;
	}
	return 0;
}
