//https://www.acmicpc.net/problem/3085

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int changeX(vector< vector <char> > board, int y, int x);
int changeY(vector< vector <char> > board, int y, int x);

int findMax(vector< vector <char> > board);
int bruteforce( vector< vector <char> > board);


int main()
{
	int n;
	vector< vector<char> > board;
	cin >> n;

	for (int y = 0; y < n; ++y)	// 이 반복문을 통해 board 는 n 개의 vector< char> element 를 push_back 할수 있다.
	{
		vector< char> element(n);	//element 는 기본값으로 초기화된 x ( == n )  개 의 원소를 갖는다.
		board.push_back(element);
	}							// 이로써 N x N 의 이차원 벡터를 생성했다.


	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
			cin >> board[y][x];
	}


	cout << bruteforce(board);


	return 0;
}


int findMax(vector< vector <char> > board)
{

	int Max =1;
	int temp =1;
	int size = board.size();

	for (int y = 0; y < size; ++y)		// Row 탐색
	{
		temp = 1;
		for (int x = 0; x < size - 1; ++x)
		{

			if (board[y][x] == board[y][x + 1])
			{
				temp += 1;
			}
			else
			{
				Max = max(Max, temp);
				temp = 1;
			}

			Max = max(Max, temp);
		}
	}

	for (int x = 0; x < size; ++x)		// Column 탐색
	{
		temp = 1;
		for (int y = 0; y < size -1; ++y)
		{
			
			if (board[y][x] == board[y + 1][x])
			{
				temp += 1;
			}
			else
			{
				Max = max(Max, temp);
				temp = 1;
			}
			Max = max(Max, temp);
		}
	}

	return Max;
}

int changeX(vector< vector <char> > board, int y, int x)
{
	int max = 0;
	int size = board[0].size();
	char temp;
	int maxtemp = 0;
 
	if (x != size -1)
	{
		temp =board[y][x];
		board[y][x] = board[y][x + 1];
		board[y][x + 1] = temp;


	/*	cout << "ChangeX! \n";
		for (int y = 0; y < size; ++y)
		{
			for (int x = 0; x < size; ++x)
				cout << board[y][x]<<" ";
			cout << "\n";
		}*/

		maxtemp = findMax(board);
		
		if (maxtemp > max)
			max = maxtemp;

		temp = board[y][x];
		board[y][x] = board[y][x + 1];
		board[y][x + 1] = temp;
	}
	
	
	return max;
};

int changeY(vector< vector <char> > board, int y, int x)
{

	int max = 0;
	int size = board.size();
	char temp;
	int maxtemp = 0;

	if (y != size -1)
	{
		temp = board[y][x];
		board[y][x] = board[y +1][x];
		board[y +1][x] = temp;

		/*cout << "ChangeY! \n";

		for (int y = 0; y < size; ++y)
		{
			for (int x = 0; x < size; ++x)
				cout << board[y][x] << " ";
			cout << "\n";
		}*/

		maxtemp = findMax(board);

		if (maxtemp > max)
			max = maxtemp;

		temp = board[y][x];
		board[y][x] = board[y + 1][x];
		board[y + 1][x] = temp;
	}


	return max;
}


int bruteforce(vector< vector <char> > board)
{
	int Max = 0;
	int temp = 0;
	int size = board.size();

	Max = findMax(board);

	for (int y = 0; y < size; ++y)
	{
		for (int x = 0; x < size ; ++x)
		{
			temp = changeX(board, y, x);
			
			Max = max(temp, Max);
			
			temp = changeY(board, y, x);
			
			Max = max(temp, Max);
		}
	}

	return Max;
}
