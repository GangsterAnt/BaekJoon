//https://www.acmicpc.net/problem/15661
//http://codeplus.codes/7215264e92894831a0ee863c8213b76a
//팀은 0 또는 1.. bit mask 를 이용하기 좋아보인다.
/*
	Solution 보다 느리다.
	그이유는 솔루션은 팀 분배를 사람 i를 어느 팀에 넣을지에 따라 두 팀의 구성 벡터를 push back 하는 방식을 채택했고
	즉 1번의 계산( 사람을 팀에 넣는 행위) 에 2번의 pushback ( team1 team2)이 일어나고

	아래 코드는 팀구성 i 를 for 문으로 받고, 하나 하나 해당 팀 구성원을 벡터에 넣었기 떄문이다.
	즉 1번의 계산( 팀구성 i에 따라 벡터를 설정 )에 n번의 pushback 이 일어난다
*/
#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 210000000
using namespace std;

int cal( int team,int people, vector<vector<int>> &v)
{
	int ans = 0;

	vector<int> team0, team1;

	int score0 = 0;
	int score1 = 0;

	for (int i = 0; i < people; ++i)
	{
		if ( team & (1 << i))	// or 연산이 true == team1
			team1.push_back(i);	// 팀원 업데이트
		else
			team0.push_back(i);
	}

	if (team0.size() == 0 || team1.size() == 0)
		return MAX;

	for (int i = 0; i < team0.size(); ++i)
	{
		for (int j = 0; j < team0.size(); ++j)
		{
			if (i == j)
				continue;
			score0 += v[ team0[i]][team0[j]];
		}
	}

	for (int i = 0; i < team1.size(); ++i)
	{
		for (int j = 0; j < team1.size(); ++j)
		{
			if (i == j)
				continue;
			score1 += v[team1[i]][team1[j]];
		}
	}

	if (score0 > score1)
		ans = score0 - score1;
	else
		ans = score1 - score0;

	/*cout << "   Team 0 : ";
	for (int i = 0; i < team0.size(); ++i)
		cout << team0[i] << ' ';
	cout << "\n   Score0 : "<<score0<<'\n';

	cout << "   Team 1 : ";
	for (int i = 0; i < team1.size(); ++i)
		cout << team1[i] << ' ';
	cout << "\n   Score1 : " << score1 << '\n';
	cout << "   Return : " << ans << '\n';*/

	

	return ans;

}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	int ans = -1;
	cin >> n;

	vector<vector<int>> v(n, vector<int>(n, 0));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> v[i][j];

	for (int i = 0; i < (1 << n); ++i)
	{
		/*cout << i << '\n';*/
		int tmp = cal(i, n, v);
		if (ans == -1 || ans > tmp)
			ans = tmp;
	}
	

	cout << ans << '\n';
	return 0;
}

//아래는 백준씨의 솔루션
int n; int s[20][20];
int go(int index, vector<int> &first, vector<int> &second) {
	if (index == n) {
		if (first.size() == 0) return -1;
		if (second.size() == 0) return -1;
		int t1 = 0;
		int t2 = 0;
		for (int i = 0; i<first.size(); i++) {
			for (int j = 0; j<first.size(); j++) {
				if (i == j) continue;
				t1 += s[first[i]][first[j]];
			}
		}
		for (int i = 0; i<second.size(); i++) {
			for (int j = 0; j<second.size(); j++) {
				if (i == j) continue;
				t2 += s[second[i]][second[j]];
			}
		}
		int diff = t1 - t2;
		if (diff < 0) diff = -diff;
		return diff;
	}
	int ans = -1;
	first.push_back(index);
	int t1 = go(index + 1, first, second);
	if (ans == -1 || (t1 != -1 && ans > t1)) {
		ans = t1;
	}
	first.pop_back();
	second.push_back(index);
	int t2 = go(index + 1, first, second);
	if (ans == -1 || (t2 != -1 && ans > t2)) {
		ans = t2;
	}
	second.pop_back();
	return ans;
}
