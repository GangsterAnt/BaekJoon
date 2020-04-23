//https://www.acmicpc.net/problem/15558
//https://code.plus/lecture/347

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace  std;



bool bfs(const vector<bool>& Left, const vector<bool>& Right ,int n, int k)
{
	

	vector<int> distL(n,-1);
	vector<int> distR(n,-1);

	queue< pair<int, bool>> q; // int is index bool 0 == L 1 ==R

	q.push(make_pair(0, 0));
	distL[0] = 0;

	while (!q.empty())
	{
		int now = q.front().first;
		int isR = q.front().second;
		q.pop();
		if (isR) //R 이라면
		{
			int tmp = now + 1;

			if (tmp >= n)	// n 을 넘어간다면 성공
				return 1;

			if (Right[tmp] && distR[now] + 1 <= tmp && distR[tmp] == -1)	//안전&& 사라지기전  &&미방문
			{
				distR[tmp] = distR[now] + 1;
				q.push(make_pair(tmp, 1));
			}

			tmp = now - 1;

			if (tmp >= 0)
			{
				if (Right[tmp] && distR[now] + 1 <= tmp && distR[tmp] == -1)	//안전&& 사라지기전  &&미방문
				{
					distR[tmp] = distR[now] + 1;
					q.push(make_pair(tmp, 1));
				}
			}

			tmp = now + k;

			if (tmp >= n)	// n 을 넘어간다면 성공
				return 1;
			if (Left[tmp] && distR[now] + 1 <= tmp && distL[tmp] == -1)	//안전&& 사라지기전  &&미방문
			{
				distL[tmp] = distR[now] + 1;
				q.push(make_pair(tmp, 0));
			}
				
		}
		else //L 이라면
		{
			int tmp = now + 1;

			if (tmp >= n)	// n 을 넘어간다면 성공
				return 1;
			if (Left[tmp] && distL[now] + 1 <= tmp && distL[tmp] == -1)	//안전&& 사라지기전  &&미방문
			{
				distL[tmp] = distL[now] + 1;
				q.push(make_pair(tmp, 0));
			}

			tmp = now - 1;

			if (tmp >= 0)
			{
				if (Left[tmp] && distL[now] + 1 <= tmp && distL[tmp] == -1)	//안전&& 사라지기전  &&미방문
				{
					distL[tmp] = distL[now] + 1;
					q.push(make_pair(tmp, 0));
				}
			}

			tmp = now + k;

			if (tmp >= n)	// n 을 넘어간다면 성공
				return 1;
			if (Right[tmp] && distL[now] + 1 <= tmp && distR[tmp] == -1)	//안전&& 사라지기전  &&미방문
			{
				distR[tmp] = distL[now] + 1;
				q.push(make_pair(tmp, 1));
			}
		}
	}

	/*for (int i = 0; i < n; ++i)
		cout << distL[i] << ' ';
	cout << '\n';

	for (int i = 0; i < n; ++i)
		cout << distR[i] << ' ';
	cout << '\n';*/
	

	return 0;
}
int main()
{
	int n, k;
	string s;

	cin >> n >> k;

	vector<bool> L(n, false); //index and dist;
	vector<bool> R(n, false);

	cin >> s;
	for (int i = 0; i < n; ++i)
		if (s[i] == '1')
			L[i] = true;
	cin >> s;
	for (int i = 0; i < n; ++i)
		if (s[i] == '1')
			R[i] = true;
	


	cout<<bfs(L,R,n, k)<<'\n';
	return 0;
}
