//https://www.acmicpc.net/problem/9376
//https://code.plus/lecture/347

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
template <typename T>
void print(vector<vector<T>> v)
{
	cout << "Printing Vector 2D : \n";
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[0].size(); ++j)
		{
			cout << v[i][j]<<' ';
		}
		cout << '\n';
	}

	return;
}
vector<vector<int>> bfs(const vector<vector<char>>& v ,int y,int x)
{
	int size_y = v.size();
	int size_x = v[0].size();
	vector<vector<int>> ret = vector<vector<int>>(size_y, vector<int>(size_x, -1));
	deque < pair<int, int> > q;
	q.push_back(make_pair(y, x));
	ret[y][x] = 0;

	while (!q.empty())
	{
		pair<int,int> cornet = q.front();
		q.pop_front();

		int y = cornet.first;
		int x = cornet.second;

		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i]; int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= size_y || nx >= size_x)
				continue;	// 비유효 좌표 
			if (ret[ny][nx] != -1)
				continue;	//이미 방문

			if (v[ny][nx] == '*')
				continue;
			else if (v[ny][nx] == '#')
			{
				ret[ny][nx] = ret[y][x] + 1;
				q.push_back(make_pair(ny, nx));
			}
			else
			{
				ret[ny][nx] = ret[y][x] ;
				q.push_front(make_pair(ny, nx));
			}
		
			

		}
	}
		return ret;
}

int main() 
{
	int T;
	
	cin >> T;
	while (T--)
	{
		int y, x;
		cin >> y >> x;

		vector< pair<int, int>> prisoner;

		vector<vector<char>> v = vector<vector<char>>(y+2, vector<char>(x+2, '.'));

		for (int i = 1; i < y+1; ++i)
			for (int j = 1; j < x+1; ++j)
			{
				cin >> v[i][j];

				if (v[i][j] == '$')
					prisoner.push_back(make_pair(i, j));
			}

		auto graph1 = bfs(v,0, 0);
		auto p_01 = bfs(v,prisoner[0].first, prisoner[0].second);
		auto p_02 = bfs(v,prisoner[1].first, prisoner[1].second);
		
	/*	graph01 ,p_01, p_02 는 각각 감옥의 외부 (0,0) 에서, 죄수 1, 2의 모든 node 에 대한 거리정보.
		i 임의의 좌표 i,j에 대해서 graph1[i][j] + p_01[i][j] + p_02[i][j] 의 값은 죄수 1과 2과 i,j 에서 만나고
		i (p_01[i][j] + p_02[i][j]) 그 좌표에서 0,0 까지의 거리와 같다. ( 양방향 그래프이므로 00 -> ij 의 값은 ij -> 00 과 같다
		print(v);
		print(graph1);
		print(p_01);
		print(p_02);*/
		int ans = -1; 

		for(int i=0; i<y+2; ++i)
			for (int j = 0; j < x + 2; ++j)
			{
				

				int tmp = graph1[i][j] + p_01[i][j] + p_02[i][j];
				if (tmp < 0)
					continue;
		
				if (ans == -1 || ans > tmp && v[i][j] != '#')
					ans = tmp;
				else if (ans == -1 || ans > tmp-2 && v[i][j] == '#')
					ans = tmp-2 ;
			}
		cout <<ans << '\n';

	}

	return 0;
}
