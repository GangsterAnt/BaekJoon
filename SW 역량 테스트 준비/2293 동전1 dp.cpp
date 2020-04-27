//https://www.acmicpc.net/problem/2293
//https://code.plus/lecture/349
// 15989 123 더하기4 dp ★.cpp 와 완전히 같다 단 num -> coin 이 될뿐
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> coin(n, 0);
	vector<int> cost(k+1, 0);
	cost[0] = 1;	//0 원을 채우는 방법은  동전 0개를 쓰는 1가지 case

	for (int i = 0; i < n; ++i)
		cin >> coin[i];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j <= k; ++j)
		{
			if (j >= coin[i])
				cost[j] += cost[j -  coin[i]];
		}
	}
	
		cout << cost[k]<<'\n';
	return 0;
}
