//https://www.acmicpc.net/problem/2503

#include <iostream>
using namespace std;

int checkball( int index, int query);
int checkstrike(int index, int query);
int check(bool* arr, int index, int query, int strike, int ball);

int main()
{
	bool arr[988] = { false, };
	int query,q_strike,q_ball;
	int numofquery;
	int result = 0;
	cin >> numofquery;

	for (int i = 0; i < numofquery; ++i)
	{
		cin >> query >> q_strike >> q_ball;
		for (int j = 100; j < 988; ++j)
		{
			check(arr, j, query, q_strike, q_ball);
		}
	}

	for (int j = 100; j < 988; ++j)
		if (arr[j] == false)
			result += 1;

	cout << result;

	return 0;

}




//int main()
//{
//	bool arr[988] = { false, };
//	int query, index;
//	int numofquery;
//	int result = 0;
//	int time;
//	cin >> time;
//	for (int i = 0; i < time; ++i)
//	{
//		cin >> index >> query;
//		cout << checkstrike(index, query) << ' ';
//		cout << checkball(index, query)<< '\n';
//	}
//
//
//	return 0;
//
//}

int checkstrike( int index, int query)
{
	int result = 0;

	int last = index %10;
	int second = (index/10) % 10;
	int first = (index/100) % 10;

	int q_last = query % 10;
	int q_second = (query / 10) % 10;
	int q_first = (query / 100) % 10;

	if (q_last == last)
		result += 1;

	if (q_second == second)
		result += 1;

	if (q_first == first)
		result += 1;

	return result;
}

int checkball(int index, int query)
{
	int result = 0;

	int last = index % 10;
	int second = (index / 10) % 10;
	int first = (index / 100) % 10;

	int q_last = query % 10;
	int q_second = (query / 10) % 10;
	int q_first = (query / 100) % 10;

	if (q_last == first || q_last == second)
		result += 1;

	if (q_second == first || q_second == last)
		result += 1;

	if (q_first == second || q_first == last)
		result += 1;
	return result;
}

int check(bool* arr, int index, int query, int strike, int ball)
{
	
	
	int last = index % 10;
	int second = (index / 10) % 10;
	int first = (index / 100) % 10;

	//기저

	if (first == last || first == second || second == last || first == 0 || second == 0 || last == 0)
	{
		arr[index] = true;
		return 0;
	}
	if (arr[index] == false)
	{
		if (checkstrike(index, query) == strike)
		{
			if (checkball(index, query) == ball)
			{
				//cout << index << " " << query << "has strkie , ball : " << checkstrike(index, query) << " " << strike << " " << checkball(index, query) << " " << ball << '\n';
				return 1;
			}

		}
	}
	
	arr[index] = true;

	return 0;
}
