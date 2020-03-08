//https://www.acmicpc.net/problem/14501

#include <iostream>
#include <algorithm>

using namespace std;

int T[16];
int P[16];
int n;
int result = 0;

void go(int money, int index)
{
	if (n < index)
	{
		result = max(money, result);
		return;
	}

	if(n+1 >= index + T[index])
		go(money + P[index], index + T[index]); //Take this Job
	go(money, index +1 );//not take this job
}

//int go2(int money, int index)
//{
//	if (n+1 < index)
//	{
//		return max(money, result);
//	}
//
//		return go2(money + P[index], index + T[index])+ go2(money, index + 1);
//
//	return go2(money, index + 1);//not take this job
//}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> T[i] >> P[i];
	}

	go(0, 1);

	cout << result<<'\n';
	return 0;
}
