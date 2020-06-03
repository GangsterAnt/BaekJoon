//https://www.acmicpc.net/problem/16198
//http://codeplus.codes/8cac43a2db8346a5b6fb18e0550aac2c

#include <iostream>
#include <vector>

using namespace std;

int dfs(int now, int depth,int sum, vector<int>& v, vector<bool>& visited)
{
	if (now == depth)
	
		return sum;
	

	int ans = 0;

	int n = v.size();
	for (int i = 1; i < n - 1; ++i)
	{
		if (visited[i])
			continue;

		visited[i] = true;

		int left = 0;
		int right = n-1;
		//방문한것은 이미 빠진 구슬이므로.. 방문여부를 통해 실제 원소의 삭제를 대신하자
		for (int j = i - 1; j >= 0; --j)
			if (!visited[j])
			{
				left = j;
				break;
			}
		
		for(int j =i+1; j<= n-1;++j)
			if (!visited[j])
			{
				right = j;
				break;
			}


		int tmp = v[left] * v[right];
		int ret = dfs(now + 1, depth, sum + tmp, v, visited);

		if (ans < ret)
			ans = ret;

		visited[i] = false;

	}

	return ans;
}
int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	vector<bool> visited(n, false);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	cout << dfs(0, n - 2,0, v, visited)<<'\n';
	return 0;
}
