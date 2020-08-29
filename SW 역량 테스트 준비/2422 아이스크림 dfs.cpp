//https://www.acmicpc.net/problem/2422

#include<iostream>
#include <map>
#include <vector>

using namespace std;

int ans = 0;

vector<bool> visited;
vector<vector<bool>> hate;
vector<int>ans_set;

void dfs(int now, int start)
{
	if (now == 3)
	{
		ans++;

		/*for (int i = 0; i < back.size(); ++i)
			cout << back[i] << ' ';
		cout << '\n';	*/
		return;
	}

	for (int i = start + 1; i < visited.size(); ++i)
	{
		if (visited[i])
			continue;


		bool pass = false;

		//모든 기존에 뽑은 정답에 대해 현재 방문을 고려중인 i 에 대해 조합의 여부를 확인한다.
		for (int j = 0; j < ans_set.size(); ++j)
			
			if (hate[i][ans_set[j]])
			{//하나라도 걸리면 flag를 true로 한후 종료.
				pass = true;
				break;
			}
		
		// flag 가 true 가 되면 다음 변수로 넘어간다.
		if (pass)
			continue;

		ans_set.push_back(i);
		visited[i] = true;
		dfs(now + 1, i);
		visited[i] = false;
		ans_set.pop_back();

	}

}
int main()
{
	int n, m;

	cin >> n >> m;
	n++;
	hate = vector<vector<bool>>(n, vector<bool>(n, false));
	visited = vector<bool>(n,false);

	for (int i = 0; i < m; ++i)
	{
		int t1, t2;
		cin >> t1 >> t2;
		hate[t1][t2] = hate[t2][t1] = true;
	}

	dfs(0, 0);
	cout << ans << '\n';

	return 0;
}
