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
