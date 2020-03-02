//https://www.acmicpc.net/problem/14888

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int arr[11];
int oper_num[4];
int result_max=-99999999999;
int result_min=99999999999;
vector<int> v;




void dfs(int depth, int now, int num)
{
	if (depth == now)
	{
		int result = arr[0];
		
		for (int i = 0; i < v.size(); ++i)
		{
			switch (v[i])
			{
			case 0:	//+
				result +=  arr[i + 1];
				break;

			case 1: //-
				result -= arr[i + 1];
				break;

			case 2: //*
				result  *= arr[i + 1];
				break;

			case 3: // /
				result  /= arr[i + 1];
				break;
			}
		}


		result_max = max(result, result_max);
		result_min = min(result, result_min);

		return;
	}

	if ( oper_num[num] )
	{

		oper_num[num]--;
		v.push_back(num);

		for (int i = 0; i < 4; ++i)
			dfs(depth, now + 1, i);

		oper_num[num]++;
		v.pop_back();
		
	}
}

void Solution(int depth, int now)
{
	
	for (int i = 0; i < 4; ++i)
	{
		dfs(depth, now, i);
	}

}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	for (int i = 0; i < 4; ++i)
		cin >> oper_num[i];		// + - * /
	
	Solution(n - 1, 0);		// arr의 갯수 n개 , 연산자는 n-1개, 연산자를 숫자로 치환하여 만드는 순열이므로 depth는 n-1;
	
	cout << result_max << '\n' << result_min << '\n';

	return 0;

}
