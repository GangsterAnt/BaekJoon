//https://www.acmicpc.net/problem/10819

#include<iostream>
#include<algorithm>
#include <vector>
#include<string.h>

using namespace std;

bool visited[8];
int arr[8];
int result_max = 0;
vector<int> v;

void dfs(int depth, int now);
int cal();

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int c;
	cin >> c;

	
	for (int i = 0; i < c; ++i)
	{
		cin >> arr[i];
	}


	memset(visited, false, sizeof(visited));

	dfs(c, 0);

	cout << result_max<<'\n';
	return 0;
}

void dfs(int depth, int now)
{
	if (depth == now)
	{
		
		/*for (int i = 0; i < v.size(); ++i)
			cout << v[i] << " ";

		int calcul = cal();

		cout << " And.. result of Cal is... : "<<calcul<<'\n';*/

		
		//result_max = max(cal(), result_max);
		result_max = max(cal(), result_max);
		return;
	}

	for (int i = 0; i < depth; ++i)
	{
		if (!visited[i])
		{
			visited[i] = true;
			v.push_back(arr[i]);

			dfs(depth, now + 1);
			visited[i] = false;
			v.pop_back();
		}
	}

	
}

int cal()
{
	int ret =0;
	int temp = 0;

	for (int i = 1; i < v.size(); ++i)
	{
		temp = v[i - 1] - v[i];

		if (temp < 0)
			temp *= -1;
		ret += temp;
	}

	return ret;
}
