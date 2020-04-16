// https://www.acmicpc.net/problem/9328
// https://code.plus/lecture/347

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>

using namespace std;

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
vector<vector<char>> v;

map<char, bool> keychain;
int bfs()
{
	int ret = 0;
	string s;
	map<char, bool> standby;
	//waiting_yx 는 2차원 벡터로 각 알파벳을 인덱스로 사용하는 해당 알파벳의 위치를 가르킨다
	//e.g   waiting_yx[ A -65] 는 평면상의 'A' 들의 좌표 값'들' 을 저장하는 벡터
	vector< vector< pair<int, int>>> waiting_yx = vector<vector<pair<int,int>>>(26);
	queue < pair<int, int>> q;

	

	int size_y = v.size();
	int size_x = v[0].size();
	vector<vector<bool>> visited = vector<vector<bool>>(size_y, vector<bool>(size_x, false));

	q.push(make_pair(0, 0));
	visited[0][0] = true;

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;

		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i]; int nx = x + dx[i];

			if (ny < 0 || ny >= size_y || nx < 0 || nx >= size_x)
				continue;	//유효범위 체크
			if (visited[ny][nx])
				continue;	//방문체크
			if (v[ny][nx] == '*')
				continue;	//벽일경우 패스
			else if (v[ny][nx] == '$')
			{			//문서일경우
				ret++;	//정답 업데이트 +1
				visited[ny][nx] = true;
				q.push(make_pair(ny, nx));	//bfs 처리
			}
			else if (v[ny][nx] == '.')
			{
				visited[ny][nx] = true;
				q.push(make_pair(ny, nx));	//bfs 처리
			}
			// 이외에는 열쇠이거나, 문이다.
			else if ( 96 < v[ny][nx]  && v[ny][nx] < 123)	//소문자의 아스키 범위 == 열쇠
			{
				int key = v[ny][nx] - 32; //대문자로 바까줌
				keychain[key] = true;		//map 업데이트
				visited[ny][nx] = true;
				q.push(make_pair(ny, nx));	//bfs 처리

				//만약 이번 열쇠로 갈수있는곳이 늘었따면.
				//이번에 얻은 열쇠 key
				//standby[key] 는 얻은 열쇠 key가 없어 문을 못열고 대기하고 있었으면 true다
				if (standby[key])
				{					//대문자 -65 는 index
					int size = waiting_yx[key -65].size();
					//대기하고 있던 문의 좌표들은 벡터형태로 저장되어있다.
					for (pair<int,int>X :waiting_yx[key-65])
					{		//모든 원소에 대해 bfs 처리
						int ty = X.first; int tx = X.second;
						if (visited[ty][tx])
							continue;
						visited[ty][tx] = true;
						q.push(make_pair(ty, tx));

					}
				}

				standby[key] = false;
				waiting_yx[key - 65].clear();
				//안해줘도 되는 부분이지만 ( 나중에 문만나면 keychain 에 이미 열쇠가 있으므로)
				// 정확도를 위해 처리해줌. 
			}

			else if (64 < v[ny][nx] && v[ny][nx] < 91)	// 대문자
			{
				if (keychain[v[ny][nx]])	//열쇠가 있는경우
				{
					visited[ny][nx] = true;
					q.push(make_pair(ny, nx)); //따고 들어간다.
				}
				else  //열쇠가 없는경우
				{
					//Standby map 과 waiting vector 업데이트
					waiting_yx[v[ny][nx] - 65].push_back(make_pair(ny, nx));
					standby[v[ny][nx]] = true;
				}
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
		int h, w;
		string s;
		v.clear();
		keychain.clear();
		cin >> h >> w;
		v = vector<vector<char>>(h + 2, vector<char>(w + 2, '.'));

		for (int i = 1; i <= h; ++i)
			for (int j = 1; j <= w; ++j)
				cin >> v[i][j];
			
		cin >> s;
		if (s != "0")
		{
			for (char X : s)
				keychain.insert(make_pair(X - 32, true));
		}
		cout<<bfs()<<'\n';


	}
	return 0;
}
