//https://www.acmicpc.net/problem/1018

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector < vector <char> > board;
int check(int y, int x);
int paint(int starty, int startx);

int main()
{
	int m, n;

	cin >> m >> n;

	for (int i = 0; i < m; ++i)	// m 은 세로 n 은 가로
	{
		vector <char> element(n);
		board.push_back(element);
	}

	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			cin >> board[i][j];

	cout<<check(m, n);
	return 0;
}


int check(int y, int x)
{
	int result =64;
	for (int i = 0; i < y-7; ++i)
	{
		for (int j = 0; j < x-7; ++j)
			result = min( paint(i, j) ,result);
	}
	
	return result;

}


int paint(int starty, int startx)
{
	int resultW = 0;
	int resultB = 0;
	int result;
	//cout << "Start From : " << starty << " " << startx ;
	//start with W

	for (int i = starty; i < starty + 8; ++i)
	{
		for (int j = startx; j < startx+ 8; ++j)
		{
			if ((i + j) % 2 == 0)	// [0][0] [0][2] 4 6 ... should be W
			{
				if (board[i][j] == 'B')
				{
					resultW += 1;
					//board[i][j] = 'w';
				}
			}
			else         // [0][1] [0][3] ...  should be B
				if (board[i][j] == 'W')
				{
					resultW += 1;
					//board[i][j] = 'b';
				}
		}

	}

	//start with B
	for (int i = starty; i < starty + 8; ++i)
	{
		for (int j = startx; j < startx + 8; ++j)
		{
			if ((i + j) % 2 == 0)	// [0][0] [0][2] 4 6 ... should be W
			{
				if (board[i][j] == 'W')
				{
					resultB += 1;
					//board[i][j] = 'w';
				}
			}
			else         // [0][1] [0][3] ...  should be B
				if (board[i][j] == 'B')
				{
					resultB += 1;
					//board[i][j] = 'b';
				}
		}

	}
	// cout << resultB << " " << resultW << '\n';
	result = min(resultW, resultB);


	return result;

}

/*
8 8
BWBWBWBW
WBWBWBWB
BWBWBWBW
WBWBWBWB
BWBWBWBW
WBWBWBWB
BWBWBWBW
WBWBWBWB
*/
