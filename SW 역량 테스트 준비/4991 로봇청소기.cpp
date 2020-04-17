//https://www.acmicpc.net/problem/4991
//https://code.plus/lecture/347
// 모든 순열 search
// -1 이 거리중에 하나만 있더라도 그래프는 완성되지 않는다.
// 근데 이걸 처리 안해주면  옳타꾸나 하고 거리를 줄여버림
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>


using namespace std;

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };


int bfs(vector<vector<char>>& v, pair<int, int>& start, pair<int,int>& end)
{
	
	int ret = 0;
	int size_y = v.size();
	int size_x = v[0].size();

	queue< pair<int, int>>q;
	vector<vector<int>> dist(size_y, vector<int>(size_x, 0));
	q.push(make_pair(start.first, start.second));

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;

		if ( y == end.first && x == end.second)	//도착
			return dist[y][x];

		q.pop();


		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i]; int nx = x + dx[i];

			if (ny < 0 || ny >= size_y || nx < 0 || nx >= size_x)
				continue;	//유효성
			if (dist[ny][nx] != 0)
				continue;	//재방문
			if (v[ny][nx] == 'x')
				continue;	//벽
			else
			{
				q.push(make_pair(ny, nx));
				dist[ny][nx] = dist[y][x] + 1;
			}

		}


	}


	return -1;
}
int main()
{
	while (1)
	{
		bool done = true;
		int ans = -1;
		vector<int> cycle;
		int y, x;
		cin >> x >> y;
		if (x == 0 && y == 0)
			break;

		vector<vector<char>> v(y, vector<char>(x, '.'));
		vector<pair<int, int>> dust;

		for (int i = 0; i < y; ++i)
			for (int j = 0; j < x; ++j)
			{
				cin >> v[i][j];
				if (v[i][j] == 'o')
				{
					dust.insert(dust.begin(),make_pair(i, j));
				}
				else if (v[i][j] == '*')
					dust.push_back(make_pair(i, j));
			}
		vector<vector<int>>dist(dust.size(), vector<int>(dust.size(),9999));
		
		for (int i = 0; i < dust.size(); ++i)
			for (int j = i + 1; j < dust.size(); ++j)
			{
				dist[j][i] = dist[i][j] = bfs(v, dust[i], dust[j]);

				if (dist[j][i] == -1)
					done = false;
			}
		//양방향 그래프이므로
		//대각선으로 대칭임.
		
		if (!done)
		{//이거 안해줘서 자꼬 틀림. 
		
			cout << "-1\n";
			continue;
		}
		
		for (int i = 0; i < dist.size(); ++i)
			cycle.push_back(i);

		for (int i = 0; i < dust.size(); ++i)
		{
			for (int j = 0; j < dust.size(); ++j)
			{
				cout << dist[i][j] << ' ';
			}
			cout << '\n';
		}
		do
		{
			if (cycle[0] != 0)	//시작점은 항상 로봇청소기 dit[0][?]
				break;
		
			
			int tmp=0;
			for (int i = 0; i < cycle.size()-1; ++i)
				tmp += dist[cycle[i]][cycle[i+1]];
			if (ans == -1 || ans > tmp)
				ans = tmp;
			/*cout << tmp<<" : ";
			for (int j = 0; j < cycle.size(); ++j)
				cout << cycle[j] << ' ';
			cout<< '\n';*/

		} while (next_permutation(cycle.begin(), cycle.end()));

		cout << ans << '\n';
	}

	return 0;
}
