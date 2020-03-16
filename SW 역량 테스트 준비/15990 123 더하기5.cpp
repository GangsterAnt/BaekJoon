//https://www.acmicpc.net/problem/15990

#include<iostream>
#include <cstring>
using namespace std;

#define MOD 1000000009
#define MAX 100000

long long arr[MAX+1][4];

void dynamic()
{
	memset(arr, 0, sizeof(arr));
	arr[1][1] = 1;	//1
	arr[2][2] = 1;	//2
	arr[3][1] = 1;	//2+1
	arr[3][2] = 1;	//1+2
	arr[3][3] = 1;	//3

	for (int i = 1; i <= 3; ++i)
		arr[i][0] = arr[i][1] + arr[i][2] + arr[i][3];

	for (int i = 4; i <= MAX; ++i)
	{
		arr[i][1] = (arr[i - 1][2] + arr[i - 1][3])	%	MOD;	//마지막이 1로 끝나는 조합 i-1 에서 1로 끝나는 친구 뺴고
		arr[i][2] = (arr[i - 2][1] + arr[i - 2][3]) %	MOD;	//마지막이 2로 끝나는 조합  i-2 에서 2로 끝나는 친구 빼고
		arr[i][3] = (arr[i - 3][1] + arr[i - 3][2])	%	MOD;	//마지막이 3으로 끝나는 조합	i-3에서 3으로 끝나는 친구 빼고
		arr[i][0] = (arr[i][1] + arr[i][2] + arr[i][3])	%	MOD;
	}
}


int main()
{
	dynamic();
	int t,n;
	cin >> t;

	while (t--)
	{
		cin >> n;
		cout << arr[n][0]<< '\n';
	}
	

	return 0;
}
