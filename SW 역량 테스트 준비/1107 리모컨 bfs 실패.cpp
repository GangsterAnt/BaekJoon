//https://www.acmicpc.net/problem/1107
/* bfs 가 가능한지 모르겠다.
 언듯보면 가능해 보이지만 n= 999를 예시로 들면...
 
 100 -> 99 는 거리가 1이므로 99는 무조건 먼저 큐에 들어간다.
 
 999는 최단거리 9->99->999 를 갖는다.
 그런데 이때 99는 이미 큐에 들어가있고. bfs 의 정의에 따라 99는 재방문할수 없다 ( 99를 업데이트하면 99의 거리가 2로 늘어난다 )
 
 그러므로 프로그램은 100 -> 99 -> + 버튼 900번 을 최단거리로 인식한다..
 
 이를 위한 대안책이 떠오르지 않는다. 예외처리를 해주자니 코드가 스파게티 코드가 될듯

*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

#define MAX 1000001		//채널은 무한대 만큼있다. Goal 이 50만 미만일뿐.
int dp[MAX];	//index 는 채널, value 는 버튼 갯수,
int back[MAX];
bool flag[MAX];

void backtracking(int goal)
{
	int tmp = goal;
	while (back[tmp] != 100)	//0
	{
		cout << tmp << '\n';
		tmp = back[tmp];
	}
}

void bfs(int goal, bool* broken)
{
	memset(dp, 0, sizeof(dp));
	memset(back, 0, sizeof(back));

	dp[100] = 0;
	flag[100] = 1;
	queue<int> q;
	q.push(100);

	while (!q.empty())
	{
		int tmp = q.front();
		//cout << tmp << " " << dp[tmp] << '\n';
		q.pop();

		if (tmp == goal)
		{
			cout << dp[tmp]<<'\n';
			backtracking(tmp);
			return;
		}

		
			for (int i = 0; i < 10; ++i)
			{
				if (!broken[i])		//만약 버튼 i 가 고장나지 않았고 아직 숫자버튼 부분
				{
					if (!dp[i])
					{
						dp[i] = 1;
						back[i] = tmp;
						q.push(i);
					}
					if (!flag[tmp])
					{
						int next = tmp * 10 + i;
						if (next < MAX && !dp[next])	// i버튼을 눌러도 채널 유효값을 가지며, 방문하지 않았다면
						{
							dp[next] = dp[tmp] + 1;		//dp[tmp] 에서 버튼 1개만 눌러도 갈수있는 채널이다.
							q.push(next);				//q 에 업데이트 해준다.
							back[next] = tmp;
						}
					}
				}
			}
		

		if (tmp + 1 < MAX && !dp[tmp+1])	// + 버튼을 누른경우
		{
			flag[tmp+1] = 1;
			dp[tmp + 1] = dp[tmp] + 1;
			q.push(tmp + 1);
			back[tmp + 1] = tmp;
		}

		if (tmp - 1 >= 0 && !dp[tmp - 1])	//- 버튼을 누른경우
		{
			flag[tmp-1] = 1;
			dp[tmp - 1] = dp[tmp] + 1;
			q.push(tmp - 1);
			back[tmp - 1] = tmp;
		}


	}

}

int main()
{
	int n, m;	// n 목표 채널 m 고장난 버튼수 arr 고장난버튼
						//버튼 = 0~ 9 , + ,-
	bool broken[10];
	memset(broken, false, sizeof(broken));
	memset(flag, false, sizeof(flag));
	int init = 100;

	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int temp;
		cin >> temp;
		broken[temp] = 1;
	}
	/*for (int i = 0; i < 10; ++i)
		cout << broken[i] << " ";
	cout << ": Broken\n";*/
	bfs(n, broken);


	return 0;
}
