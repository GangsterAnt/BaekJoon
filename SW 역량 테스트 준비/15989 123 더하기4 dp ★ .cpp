//https://www.acmicpc.net/problem/15989
//https://code.plus/lecture/349

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v(10001, 0);


int main()
{
	int T;
	cin >> T;
	int n;
	int num[] = { 1,2,3 };
	v[0] = 1;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 1; j <= 10000; ++j)
		{
			if (j >= num[i])
				v[j] += v[j - num[i]];
		}
	}
	while (T--)
	{
		cin >> n;
		cout<<v[n]<<'\n';
	}

	return 0;
}


/*
점화식이 조금 직관적이지 않다.
이전에는 각 dp[i] 의 i를 계산한후 dp[i+1] 을 dp[0] ... dp[i]를 이용했지만.

이번 문제는 dp[i] 를 완성하기 위해 dp[0]...dp[i-1] 까지를 부분적으로 완성해 나아간다.
{
	for all i in dp[i] , 1로만 이뤄진것.
						 1로만 이뤄진 dp 를 기반으로 2 가 추가된것.
						 1과 2로 이뤄진 dp를 기반으로 3을 추가 연산.
						 하는 순으로 순열을 채워나아간다.

}
알고리즘 설명.

for (int i = 0; i < 3; ++i)
{
for (int j = 1; j <= 10000; ++j)
{
if (j >= num[i])
v[j] += v[j - num[i]];
}
}

가장 먼저 1로 만 만들수 있는 모든 경우를 채운다. (사실 1*n 의 한가지 밖에 없다)
dp	1: 1
	2: 1+1
 	3: 1+1+1
	4	....
	5
	6
	7	....

이후 2를 추가할수 있는 경우를 추가해준다 (i==1; num[i] ==2) v[j] += v[j - 2];

dp	1: 1
	2: 1+1		,0+2
	3: 1+1+1	,1+2
	4: 1+1+1+1	, 1+1+2 , 2+2 (by dp[2])
	5: 1, 1+1+1+2 , 1+2+2(by dp[3])
	6: 1 .. 1+1+2+2, 2+2+2 (by dp[4] (which is bt dp[2] ))
	7	....

이후 3을 추가할수 있는 경우를 추가해준다 (i==2; num[i] ==3) v[j] += v[j - 3];

dp	1: 1
	2: 2
	3: 2	, 0+3
	4: 3	, 1+3 
	5: 3	, 2+3
	6:...
	7:..
*/
