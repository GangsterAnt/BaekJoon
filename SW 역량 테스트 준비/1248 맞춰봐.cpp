//https://www.acmicpc.net/problem/1248
// 중복값 허용!

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector< vector<char>> v;
vector<int> ans;
bool visited[21];
bool done = false;

bool okay(int size)
{
	bool flag = true;
	

	int index = size;
	int temp = 0;
	for (int i = index; i >=0 ; --i)
	{
		temp += ans[i];
		switch (v[i][index])
		{

		case '+':
			
			flag = (temp > 0) ? true: false;
			break;

		case '-':
			flag = (temp < 0) ? true : false;
			break;

		case '0':
			flag = (temp == 0) ? true : false;
			break;
		}

		if (!flag )
			break;

	}

	return flag;
}
void dfs(int now, int depth)
{
	if (now == depth)
	{
		for (int i = 0; i < ans.size(); ++i)
			cout << ans[i] << ' ';
		cout << '\n';
		done = true;
		return;
	}

	

	for (int i = 0; i < 21; ++i)
	{
		//if (visited[i])	continue;

		ans.push_back(i - 10);
		//visited[i] = true;

		if (!okay(now))
		{
			ans.pop_back();
			visited[i] = false;
			continue;
		}

		dfs(now + 1, depth);

		ans.pop_back();
		//visited[i] = false; 
		
		if (done) return;
	}


}
int main()
{
	int n;
	cin >> n;

	v = vector< vector< char>>(n, vector<char>(n, 'x'));
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < n; ++i)
		for (int j = i; j < n; ++j)
			cin >> v[i][j];


	/*for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cout << v[i][j] << ' ';
		cout << '\n';
	}*/

	dfs(0, n);

	

	return 0;
}
