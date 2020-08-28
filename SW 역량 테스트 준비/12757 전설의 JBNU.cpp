//https://www.acmicpc.net/problem/12757
// 14528kb 240ms

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int n, m, k;

//mymap 은 key 가 정방향 
// key 이상의 가장 작은 값을 찾는데 사용된다.
map<int, int>mymap;

//mymap2는 key가 * -1 되어있는 map
// key 이하의 가장 큰 값을 찾는데 사용된다.
map<int, int>mymap2;

pair<int, int> nearestKey(int key)
{
	int plus = -1;
	int minus = -1;

	map<int, int>::iterator iter;
	iter = mymap.lower_bound(key);

	if (iter != mymap.end())
		plus = iter->first;

	//초기에는 iter-- 를 이용하였는데 iter가 mymap.begin() 이전으로 넘어가버리면 참조에러가 뜬다.
	// iter > mymap.begin() 은 안되길래 걍 포기 역방향 map인 map2를 생성. 해결
	iter = mymap2.lower_bound(-1 * key);

	
	if (iter != mymap2.end())
		minus = (iter->first) *-1;

	// K 보다 오차값이 크면 유효 X
	if (plus - key > k)
		plus = -1;

	if (key - minus > k)
		minus = -1;

	// -1 이 리턴될경우 유효내에 키가 없다는뜻.
	return make_pair(plus, minus);
}

// O( 2* K ) 느리다. 
pair<int, int> nearestKey2(int key)
{
	int plus = -1;
	int minus = -1;

	for (int i = 1; i <= k; ++i)
	{

		if (mymap.find(key + i) != mymap.end())
		{
			plus = key + i;
		}
		if (mymap.find(key - i) != mymap.end())
		{
			minus = key - i;
		}

		if (plus != -1 || minus != -1)
			break;
	}

	return make_pair(plus, minus);
}

void function2(int key, int value)
{
	if (mymap.find(key) != mymap.end())
	{
		mymap[key] = value;
		return;
	}

	auto near = nearestKey(key);

	//근접키가 없다
	if (near.first == -1 && near.second == -1)
		return;

	//근접키가 1개다

	if (near.first == -1)
	{
		mymap[near.second] = value;
		return;
	}

	if (near.second == -1)
	{
		mymap[near.first] = value;
		return;
	}

	int p_diff = near.first - key;
	int m_diff = key - near.second;

	//동일거리 = 무시
	if (p_diff == m_diff)
	{
		return;
	}

	if (m_diff > p_diff)
	{
		mymap[near.first] = value;
	}
	else
	{
		mymap[near.second] = value;
	}



}

void function3(int key)
{
	if (mymap.find(key) != mymap.end())
	{
		cout << mymap[key] << '\n';
		return;
	}

	auto near = nearestKey(key);

	//근접키가 없다
	if (near.first == -1 && near.second == -1)
	{
		cout << "-1\n";
		return;
	}

	//근접키가 1개다

	if (near.first == -1)
	{
		cout << mymap[near.second] << '\n';
		return;
	}

	if (near.second == -1)
	{
		cout << mymap[near.first] << '\n';
		return;
	}
	//근접키가 두개다


	int p_diff = near.first - key;
	int m_diff = key - near.second;

	//동일거리 
	if (p_diff == m_diff)
	{
		cout << "?\n";
		return;
	}

	if (m_diff > p_diff)
	{
		cout << mymap[near.first] << '\n';
	}
	else
	{
		cout << mymap[near.second] << '\n';
	}


}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;

	for (int i = 0; i < n; ++i)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		mymap[tmp1] = tmp2;
		mymap2[tmp1 * -1] = tmp2;
	}

	for (int i = 0; i < m; ++i)
	{
		int q;
		int key, value;

		cin >> q;

		switch (q)
		{
		case 1:
			cin >> key >> value;
			mymap[key] = value;
			mymap2[-1 * key] = value;
			break;
		case 2:
			cin >> key >> value;
			function2(key, value);
			break;
		case 3:
			cin >> key;
			function3(key);
			break;
		}
	}

	return 0;
}
