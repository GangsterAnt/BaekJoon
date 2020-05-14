//https://www.acmicpc.net/problem/3190
//https://code.plus/lecture/351

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int dy[] = {-1,0,1,0};	// 0:N 1:E 2:S 3:W
int dx[] = {0,1,0,-1};

int function(vector<vector<int>> &v ,vector<pair<int, char>> & direction)
{
	int size = v.size();
	int ans = 0;

	//뱀의 정보
	int dir = 1;	//뱀의 방향  init 은 오른쪽 
	deque <pair<int, int>> snake;	//뱀의 좌표 데큐 0은 머리 back은 꼬리
	snake.push_front(make_pair(1, 1));


	while (1)
	{
		ans++;
		int ny = snake[0].first + dy[dir];
		int nx = snake[0].second + dx[dir];

		if(!direction.empty())//방향전환할게 있다면
			if (direction[0].first == ans)	//방향전환 할때가 되었다면.
			{
				if (direction[0].second == 'L')
					dir = (dir == 0 ? 3 : dir - 1);

			else						//R
					dir = (dir == 3 ? 0 : dir + 1);

				direction.erase(direction.begin());	//맨앞 삭제
			}


		if (ny == 0 || nx == 0 || ny == size - 1 || nx == size - 1)
			break;		//벽에 부딛친 경우


		if (v[ny][nx] == -1)
			break;		// 몸통에 부딛친경우

		else if (v[ny][nx] == 1)	
		{
			//사과를 먹은경우 
			snake.push_front(make_pair(ny, nx)); //머리 업데이트
			v[ny][nx] = -1;		//맵에서 머리 부분을 -1 (몸통) 로 바꿔주고 
			continue;			
		}
		else
		{
			//사과를 먹지 않은경우
			snake.push_front(make_pair(ny, nx)); //머리 업데이트
			v[ny][nx] = -1;		//맵에서 머리 부분을 -1 (몸통) 로 바꿔주고

			int tail_y = snake.back().first;
			int tail_x = snake.back().second;

			v[tail_y][tail_x] = 0;		//맵에서 꼬리 당기기 -1 ->0
			snake.pop_back();			//뱀 정보에서 꼬리 당기기
		}
		
	}

	return ans;
}
int main()
{
	int n;
	cin >> n;
	vector<vector<int>> v(n + 2, vector<int>(n + 2, 0));

	int k;
	cin >> k;


	for (int i = 0; i < k; ++i)
	{
		int y, x;
		cin >> y >> x;
		v[y][x] = 1;
	}

	vector<pair<int, char>> direction;
	int l;
	cin >> l;

	for (int i= 0; i < l; ++i)
	{
		int tmp; char temp;
		cin >> tmp >> temp;
		direction.push_back(make_pair(tmp, temp));
	}

	cout << function(v, direction) << '\n';
	return 0;
}
