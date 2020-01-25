//https://www.acmicpc.net/problem/1051

#include <iostream>
#include <vector>
#include <algorithm>

int getmax();
int maxsquare(int starty, int startx, int temp_size);

using namespace std;
char board[50][50];
int y, x, temp;

int main()
{
	

	cin >> y >> x;

	for(int  i= 0; i<y; ++i)
		for(int j =0; j <x ; ++j)
			cin>>board[i][j];

	cout << getmax()<<'\n';
	return 0;
}

int getmax()
{
	int maxsize = 1;

	for (int starty = 0; starty < y; ++starty)
	{
		for (int startx = 0; startx < x; ++startx)
		{
			//cout << "Call from " << starty << " " << startx << '\n';
			maxsize = max(maxsize, maxsquare(starty, startx , 1));
		}
	}
	return maxsize*maxsize;

}

int maxsquare(int starty, int startx, int temp_size)
{
	
	char pivot = board[starty][startx];
	//cout << starty << " " << startx << '\n';
	int max_now =1;

	if (y < starty + temp_size || x < startx + temp_size )
	{
		return -1;
	}

	if (
			board[starty + (temp_size - 1)][startx] == pivot && 
			board[starty][startx + (temp_size - 1)] == pivot &&
			board[starty + ( temp_size - 1 )][startx + (temp_size - 1)] == pivot 
		)
	{
		//cout << temp_size << " " << starty << " " << startx << " " << pivot << '\n';
		max_now = temp_size;
	
	}


	max_now = max ( maxsquare(starty, startx, temp_size + 1) , max_now);

	//cout << max_now<<endl;

	return max_now;

}
