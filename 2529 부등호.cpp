//https://www.acmicpc.net/problem/2529
/*
자리수 조심 9876543210 (98억) 은 int 의 범위 (21억), unsigned 의 범위( 42억) 을 넘어간다 
MAX, MIN 모두 long long 으로
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

long long MIN = 99999999999;
long long  MAX = -1;

vector <char> A;
vector <long long > v;

bool visited[10];

long long  v_to_int(vector<long long > v)
{
	long long  ans = 0;

	for (int i = 0; i < v.size(); ++i)
	{
		ans *= 10;
		ans += v[i];
	}

	return ans;
}



void dfs(int depth ,int now)
{
	if (now == depth + 1)	//depth k는 부등호의 개수이므로 숫자는 k+1;
	{
		MAX = max(v_to_int(v), MAX);
		MIN = min(v_to_int(v), MIN);

		//cout << v_to_int(v) << '\n';
		return;
	}


	for (int i = 0; i < 10; ++i)
	{
		if (visited[i])
			continue;

		bool flag = false;

		switch (A[now - 1])
		{
			case '<':
				flag = (v[now - 1] < i) ? true : false;
				break;
			case '>':
				flag = (v[now - 1] > i) ? true : false;
				break;

		}

		/*if (A[now - 1] == '<' && v[now - 1] < i)
			flag = true;
		else if (A[now - 1] == '>' && v[now - 1] > i)
			flag = true;*/

		if (!flag)
			continue;

		visited[i] = true;
		v.push_back(i);
		dfs(depth, now + 1);
		v.pop_back();
		visited[i] = false;
		
		
	}


}

void solution(int depth)
{
	for (int i = 0; i < 10; ++i)
	{
		visited[i] = true;
		v.push_back(i);

		dfs(depth, 1);

		visited[i] = false;
		v.pop_back();
	}

	return;
}

int main()
{
	memset(visited, false, sizeof(visited));
	
	int k;
	cin >> k;

	for(int i=0; i<k ; ++i)
	{
		char a;
		cin >> a;
		A.push_back(a);
	}


	solution(k);

	cout.width(k + 1);
	cout.fill('0');
	cout << MAX << '\n';

	cout.width(k + 1);
	cout.fill('0');
	cout << MIN << '\n';
	//cout << MAX << '\n' << MIN << '\n';
	return 0;
}
