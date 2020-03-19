//https://www.acmicpc.net/problem/11054

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int>a;

void dynamic()
{
	int size = a.size();
	int result=1;

	vector<int> dp1, dp2;

	dp1 = dp2 = vector<int>(size, 1);	//dp(수열의 길이)는 최소 1이므로 1로 초기화.

	for(int target = 1; target <size; ++target)
		for (int compare = 0; compare < target; ++compare)
			if (a[compare] < a[target])
				dp1[target] = max(dp1[target], dp1[compare] + 1);


	// dp1 은 순열의 앞에서부터 longest increasing subsequence 를 찾는다.
	//방향은 기본방향 ( 좌 -> 우)  index 0 -> n -1 이다.


	for (int target = size - 2; target >= 0; --target)
		for (int compare = size - 1; target < compare; --compare)
			if (a[target] > a[compare])
				dp2[target] = max(dp2[compare] + 1, dp2[target]);

	// dp2는 뒤에서부터 longest increasing subsequence 를 찾는다.
	// 즉 LIS 의 진행 방향이  index "n-1" 에서 "0" 으로 간다.

		



	/*for (int i = 0; i < size; ++i)
		cout << dp1[i] << ' ';
	cout << '\n';

	for (int i = 0; i < size; ++i)
		cout << dp2[i] << ' ';
	cout << '\n';*/

	for (int i = 0; i < size; ++i)
	{
		result = max ( result , dp1[i] +dp2[i]);
	}
	
	cout << result-1 << '\n';

}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	a = vector<int>(n, 0);

	for (int i = 0; i < n; ++i)
		cin >> a[i];	// reverse(a.begin(), a.end()) == b;
	
	

	dynamic();

	return 0;

}
