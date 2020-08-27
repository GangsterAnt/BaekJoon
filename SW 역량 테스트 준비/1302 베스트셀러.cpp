#include <iostream>
#include <vector>
#include <string>
#include<map>
#include<algorithm>

using namespace std;



int main()
{
	int n;
	cin >> n;

	int max = 1;

	string s;
	map<string, int> m;
	vector<string> keychain;
	ans;

	// O(1000) == O(n)
	for (int i = 0; i < n; ++i)
	{
		cin >> s;
  
		if (m.find(s) == m.end())
		{ 
    //없으면 키체인에 추가 및 value 초기화
			m[s] = 1;
			keychain.push_back(s);
		}
		else
		{
    //있으면 value +1, 만약 value+1 이 새로운 최대값이면 업데이트
			m[s]++;
			if (max < m[s])
				max = m[s];
		}

	}

	for (int i = 0; i < keychain.size(); ++i)
	{
  //각 key 에 대한 value 가 max 와 같다면 최대 판매책이다. 정답에 추가.
		if (m[keychain[i]] == max)
			{
        if (ans.empty() || ans > keychain[i])
				ans = keychain[i];
		  }
	}

	cout << ans << '\n';
	return 0;
}
