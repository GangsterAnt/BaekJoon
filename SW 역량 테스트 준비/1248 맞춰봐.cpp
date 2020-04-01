//https://www.acmicpc.net/problem/1248
// 중복값 허용! -> 방문처리 X
//백 트래킹

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector< vector<char>> v;
vector<int> ans;
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
	{//방문처리는 필요없다

		ans.push_back(i - 10);

		if (okay(now))
			dfs(now + 1, depth);
		
		ans.pop_back();
		
		if (done) return;
	}
	

}
int main()
{
	int n;
	cin >> n;

	v = vector< vector< char>>(n, vector<char>(n, 'x'));

	for (int i = 0; i < n; ++i)
		for (int j = i; j < n; ++j)
			cin >> v[i][j];

	dfs(0, n);

	

	return 0;
}
