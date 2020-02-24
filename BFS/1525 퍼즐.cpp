//https://www.acmicpc.net/problem/1525

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int Goal = 123456780; //목표를 vector 가 아닌 int 하나로 취급!

const int dx[4] = { -1,1 ,0,0 };  //Swap 을 위한 dx ,dy 배열
const int dy[4] = { 0,0, -1,1 };

int whereiszero(int& temp); // 0 의 자릿 수를 알아내는 함수. 간단

void bfs(const int & numpad);

int main()
{
	int numpad=0;
	int temp;
	for (int y = 1; y <= 3; ++y)
	{
		for (int x = 1; x <= 3; ++x)
		{
			cin >> temp;
			numpad = numpad*10+ temp;
		}
	}

	bfs(numpad);

	return 0;
}

int whereiszero(int& temp)
{
	int size = 8; // int 123456780 을 arr[9]에 한 숫자씩 넣은것으로 추상적으로 생각하자.

	int tmp = temp;
	while (size >= 0)
	{
		if (tmp % 10 == 0)
			return size;  
		else
		{
			tmp /= 10;
			size--;
		}
	}

	return size;
}

void bfs(const int & numpad)
{
	map<int, int> cost;   //Map 을 사용하자 first 는 입력받은 pad 값, second 는 cost 이다.
                        //이 방법을 사용시 numpad를 vector< vector<int> > numpad 로 사용도 가능하겠지만 (bool check는 value 의 값으로)
                        // vector<vector<int>> 는 여러모로 비싸다.
	queue<int> q;

	q.push(numpad);
	cost[numpad] = 0; //Root Node 의 cost 는 0

	while (!q.empty())    //기본 BFS의 틀
	{
		int here = q.front(); q.pop();

		//cout << here << '\n';
		if (here == Goal)
			break;

		int Zero = whereiszero(here);	// 0 이 몇번쨰 index 인가?
		int X = Zero%3;
		int Y = Zero/3;

		for (int i = 0; i < 4; ++i)
		{
			int nextX = X + dx[i];
			int nextY = Y + dy[i];
			if (0 <= nextY && nextY < 3 && 0 <= nextX && nextX <3)  //유효성 Check
			{
				int tmp, tmp2,there =0;
				int arr[9];	//swap 편하게 하기 위해 arr 생성

				tmp = here;

				for (int i = 8; i >= 0; --i)
				{
					arr[i] = tmp % 10;
					tmp /= 10;
				}

				tmp2 = arr[nextY * 3 + nextX]; //Swap! 
				arr[nextY * 3 + nextX] = 0;
				arr[Zero] = tmp2;

				for (int i = 0; i < 9; ++i)
				{
					there = there * 10 + arr[i];
				}
				if (!cost.count(there))
				{
					q.push(there);
					cost[there] = cost[here] + 1;
				}
			}
		}
	}
	if (cost.count(Goal) == 0)
		cout << "-1\n";
	else
		cout << cost[Goal]<<'\n';
}
