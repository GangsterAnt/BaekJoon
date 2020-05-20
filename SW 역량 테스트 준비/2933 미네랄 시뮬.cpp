//https://www.acmicpc.net/problem/2933
//https://www.acmicpc.net/source/share/6ea34ad7d5c748a0a6a76926cf461cd4

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dy[] = { -1, 1, 0,0 };
int dx[] = { 0,0,-1,1 };

vector< pair<int, int>> bfs(vector<vector<char>> &v, vector<vector<bool>>& check, int i, int j)
{
	int r = v.size();
	int c = v[0].size();
	vector<pair<int, int>> ret;
	ret.push_back(make_pair(i, j));
	queue< pair<int, int>> q;

	q.push(make_pair(i, j));

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int d = 0; d < 4; ++d)
		{
			int ny = y + dy[d];
			int nx = x + dx[d];

			if (ny < 0 || nx < 0 || ny >= r || nx >= c)
				continue;

			if (v[ny][nx] == '.')
				continue;
			if (check[ny][nx] == true)
				continue;

			v[ny][nx] = '.';
			check[ny][nx] = true;
			ret.push_back(make_pair(ny, nx));
			q.push(make_pair(ny, nx));
		}
	}

	return ret;

}


void drop(vector<vector<char>> &v, vector<vector<bool>>& check)
{

	int r = v.size();
	int c = v[0].size();
	
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			check[i][j] = false;

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (v[i][j] == '.')	//빈칸
				continue;
			if (check[i][j])	//이미 클러스터링 된거.
				continue;

			vector<pair<int, int>> cluster = bfs(v, check, i, j);

			vector<int>lowest_in_column(c, -1);	//각 열에서 가장 밑에있는 클러스터 원소

			for (auto &p : cluster)
			{
				lowest_in_column[p.second] = max(lowest_in_column[p.second], p.first);
				v[p.first][p.second] = '.';	//클러스터내의 모든 원소들을 일단 '.' 으로 업데이트
			}

			int threshold = r;	//모든 클러스터가 몇칸 내려갈지

			for (int y, x = 0; x < c; ++x)	//각 열을 스캔해 나아감.
			{
				if (lowest_in_column[x] == -1)	//클러스터 내 x 열의 원소가 없다면
					continue;
				/*
				아래의 for 루프를 주의하자 for 루프의 수행문은 아무것도 하지않는다
				조건문을 통해 ++y 자체를 수행문처럼 사용한다.

				이를 통해 y 는  v[y][x]  != '.' 인 최초의 y에서 for 루프를 종료한다.

				y - lowest_in_column[x] -1 은  

				lowest_in_column[x] == 클러스터의 가장 아래 원소의 y 값
				y 는 클러스터가 아닌 원소중에 가장 위에있는 x 의 원소값이다.

				y-1 ( y 바로 윗칸) 까지 클러스터가 떨어져야 하므로.. y-1 - lowest... 가 
				클러스터가 이동해야 하는 거리이다.


				threshold = min(threshold, y - lowest_in_column[x] -1);
				을 통해 각 열에서의 다음 x 까지의 거리를 구하고,
				그 거리중 최소값만큼만 내려가야한다.

				*/
				for (y = lowest_in_column[x]; y < r && v[y][x] == '.'; ++y);
						//y는 x 열에서 가장 밑에있는 원소, y 가 유효값 내이며 빈칸이라면 진행한다.
				threshold = min(threshold, y - lowest_in_column[x] -1);
								
				

			}

			for (auto&p : cluster)
			{
				p.first += threshold;
				v[p.first][p.second] = 'x';
				check[p.first][p.second] = true;
			}
		}
	}
}

void function(vector<vector<char>> &v , vector<vector<bool>>& check, vector<int>&throwing)
{
	int r = v.size();
	int c = v[0].size();
	for (int i = 0; i < throwing.size(); ++i)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < c; ++j)
			{
				if (v[throwing[i]][j] == '.')
					continue;
				v[throwing[i]][j] = '.';
				drop(v,check);
				break;
			}
		}
		else
		{
			for (int j = c-1; j >=0; --j)
			{
				if (v[throwing[i]][j] == '.')
					continue;

				v[throwing[i]][j] = '.';
				drop(v, check);
				break;
			}
		}
	}
}


int main()
{
	int r, c;
	cin >> r >> c;

	vector<vector<char>> v(r, vector<char>(c,'.'));
	vector<vector<bool>> check(r, vector<bool>(c, false));

	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			cin >> v[i][j];

	int n;
	cin >> n;

	vector<int>throwing;
	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >>tmp;
		throwing.push_back(r - tmp);
	}


	function(v, check, throwing);

	
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)

			cout << v[i][j];
		cout << '\n';
	}

	return 0;
}
