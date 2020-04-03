//https://www.acmicpc.net/problem/1062
//https://code.plus/lecture/344

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int countwords(int mask, vector<int> & v)
{
	int ret = 0;

	for (int i = 0; i < v.size(); ++i)
	{ 
  // ((1<<26)-1-mask ))는 111111...111 에서 배운 알파벳들을 뺸것. ( mask 의 여집합)
  //즉 v[i] &((1<<26)-1-mask )) 는 v[i]에서 내가 배우지 않은 ( mask 의 여집합) 알파벳이 있는지 검출
  // 없다면 (==0) 배운 알파벳으로 단어를 읽을수 있다는 의미. ( ok) ret ++;
		if ( (v[i] & ((1<<26)-1-mask )) == 0)
			ret++;
	}

	return ret;
}
// index 는alphabet 의 index, k는 배울수 있는 알파벳 수, mask 는 배운것들의 비트마스크 ,v는 단어 비트들
int dfs(int index, int k, int mask, vector<int>& v) 
{
	if (k < 0) return 0;	// back tracking.. 답ㅇ ㅣ될수 없음.
	if (index == 26) return countwords(mask, v);	// 종료조건
	
	int ans = -1;
	int pick_alphabet = dfs(index + 1, k - 1, mask | (1 << index), v);
	ans = max(ans, pick_alphabet);

	if (index != 'a' - 'a' && index != 'n' - 'a' && index != 't' - 'a' && index != 'c' - 'a'
		&& index != 'i' - 'a')
	{
		int not_pick = dfs(index + 1, k, mask, v);
		ans = max(ans, not_pick);
	}

	return ans;
}

int main()
{
	int n, k;
	int ans = 0;
	cin >> n >> k;
	
	vector<int> v = vector<int>(n, 0);

	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;

		for (char X : s)
			v[i] |= (1 << (X - 'a'));

	}



	cout << dfs(0, k, 0, v) << '\n';

	return 0;
}
