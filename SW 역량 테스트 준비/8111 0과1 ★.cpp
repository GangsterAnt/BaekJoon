//https://www.acmicpc.net/problem/8111
//https://code.plus/lecture/347
//접근 방식 .. %n 들을 vector 로 만들고..
// 1 10 11 들에대해 각 %n 연산을 통해 vector 를 채워나간다.
//이떄 %n == k 라고 할떄 vector[k] 는 나머지가 k인 길이가 최소인 수가 된다.
//즉 1 % n 10%n 11%n 을 채워나가는것.... 어렵다
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
string find(int n)
{
	queue<long long> q;

	vector<int> from(n, -1); // from 은 어떤 index 로 부터 왔는지
	vector<int> how(n, -1);	//how 는 0 과 1중 어떤걸 뒤에 붙여서 왔는지
	vector<int> dist(n, -1);	//방문체크위해서.. 문제와 상관은 없지만 dist+1 은 자릿수와 같다

	q.push(1 % n);
	how[1 % n] = 1;	// 
	dist[1 % n] = 0;

	while (!q.empty())
	{
		int now = q.front();	// now 는 어떤 수 % n 과 같다 어떤수는 바로 알수 없다.
		q.pop();				// 다만 % n 을 index 로 벡터에서 사용한다.
								// 정답을 찾으면 how와 from 을통해 역추적 할수는 있다.
		for (int i = 0; i < 2; ++i)
		{
			int next = (now * 10 + i) % n;
			if (dist[next] != -1)
				continue;
			dist[next] = dist[now] + 1;
			from[next] = now;
			how[next] = i;
			q.push(next);
		}

	}

	if( dist[0] ==-1)
		return "BRAK";

	string ans ="";
	for (int i = 0; i != -1; i = from[i])
		ans += to_string(how[i]);
	reverse(ans.begin(), ans.end());
	// reverse 의 이유..
	//eg. n == 17 ans == 11101 
	// 11101 <- 1110 <- 111 <- 11 <- 1
	// how==1  how==0 how==1 how==1 how ==1
	// how += 하면.. 10111이 된다.
	return ans;
}
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;
		cout << find(n)<<'\n';
	}
	return 0;
}
