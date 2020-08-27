//https://www.acmicpc.net/problem/11053

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int result = 1;
int n, arr[1000],dp[1000];

void dynamic()
{
	//target 은 anchor 로 새로 추가되는 부분수열 arr[i+1]
	for (int target = 1; target < n; ++target)
	{
		for (int compare = 0; compare < target; ++compare)
		{
			if (arr[target] > arr[compare]
			{	
				//만약 arr[compare] 보다 arr[target]이 큰경우 무조건 dp[target] 은 dp[compare]보다 클수밖에 없다\
				//그러나 dp[compare]+1 이란 수치는 arr[0],arr[1],...arr[compare] ,arr[target] 으로 이뤄진 부분수열로 
				//compare 와 target 사이의 공백이 존재하기 때문에 최대값이라는 보장이 없다
				//그러므로 임시로 저장해놓고 compare<target의 루프를 수행한다.
				dp[target] = max(dp[compare] + 1, dp[target]);
				result = max(dp[target], result);
			}
			    //arr[target] < arr[compare] 인경우 이 LIS 의 크기는 증가하지 않는다 고로 처리해주지않는다
			    //어차피 if 문에 걸렸을때 result는 update 되기때문에 문제되지않는다.
			    
		}
	}

	
}

int main()
{
	
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	for (int i = 0; i < n; ++i)
		dp[i] = 1;

	dynamic();

	cout << result << '\n';
	return 0;
}
