//https://www.acmicpc.net/problem/14891
//https://code.plus/lecture/351

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

vector < vector<bool>> wheels(4, vector<bool>(8, false));

void rotate(int base, int dir)
{
	bool tmp;
	if (dir == 1) //시계방향
	{
		tmp = wheels[base][7];

		for (int i = 7; i >0; --i)
			wheels[base][i] = wheels[base][i -1];
		
		wheels[base][0] = tmp;
	}
	else //반시계방향
	{
		tmp = wheels[base][0];

		for (int i = 0; i < 7; ++i)
			wheels[base][i] = wheels[base][i + 1];
		
		wheels[base][7] = tmp;
	}

}
void function(int base, int dir)
{
	vector < vector<bool>> prestate (4,vector<bool>(2,false));
	/*
	문제의 인접 톱니바퀴의 회전 여부는 회전 후의 극의 상반 관계가 아닌
	회전 전의 인접 톱니바퀴의 극의 상반관계이다.
	이를 위해 벡터에 인접 톱니바퀴의 극을 저장해놓은 후, 회전시킨다 !
	*/
	for (int i = 0; i < 4; ++i)
	{
		prestate[i][0] = wheels[i][6];
		prestate[i][1] = wheels[i][2];
	}

	rotate(base, dir);

	int dir_now = dir;
	
	int right = 3 - base;
	int left = base;

	bool moved = true;

	if( right !=0)
		for (int i = 1; i <= right; ++i) //오른쪽
		{
			int next = base + i;

			if (prestate[next - 1][1] != prestate[next][0])
			{	//다르다면 돌린다.
				//cout <<"[next - 1][2] : "<< wheels[next - 1][2] << "[ next][6] : " << wheels[next][6] << '\n';
				if (dir_now == 1)
				{
					dir_now = -1;
					rotate(next, dir_now);
				}
				else
				{
					dir_now = 1;
					rotate(next, dir_now);
				}
			}
			else//같다면 오른쪽거는 다 안돈다
				break;
		}

	dir_now = dir;

	if( left !=0)
		for (int i = 1; i <=left; ++i)	//왼쪽
		{
			int pre = base - i;

			if (prestate[pre + 1][0] != prestate[pre][1])
			{//다르다면 돌린다.
				//cout <<"[pre + 1][6] : "<< wheels[pre + 1][6] << " [pre][2] : "  << wheels[pre][2] << '\n';
				if (dir_now == 1)
				{
					dir_now = -1;
					rotate(pre, dir_now);
				}
				else
				{
					dir_now = 1;
					rotate(pre, dir_now);
				}
			}
			else
				break;	//같다면 왼쪽놈들은 다 안돈다
		}



	/*for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 8; ++j)
			cout << wheels[i][j] << ' ';
		cout << '\n';
	}*/
}
int main()
{
	string s;
	for (int i = 0; i < 4; ++i)
	{
		cin >> s;
		for (int j = 0; j < 8; ++j)
		{
			if (s[j] == '1')	// N극은 0 false S극은 1 true
				wheels[i][j] = true;
		}
	}

	int t,dir,base;
	cin >> t;

	while (t--)
	{
		cin >> base >> dir;	//base는 돌릴 휠, dir 는 방향 -1 = 반시계 1 = 시계
		function(base-1, dir);
	}
	
	int ans = 0;
	if (wheels[0][0])
		ans += 1;
	if (wheels[1][0])
		ans += 2;
	if (wheels[2][0])
		ans += 4;
	if (wheels[3][0])
		ans += 8;
	cout<< ans<<'\n';

}
