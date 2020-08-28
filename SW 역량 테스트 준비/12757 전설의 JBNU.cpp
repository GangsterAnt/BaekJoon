//https://www.acmicpc.net/problem/12757
//timeout

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int n, m, k;

//정방향 map과 역방향 map2
map<int, int>mymap;
map<int, int>mymap2;

pair<int,int> nearestKey(int key)
{
	int plus = -1;
	int minus = -1;

//정방향 map 의 key 바로 다음 key를 찾아준다.
	map<int, int>::iterator iter;
	iter =mymap.lower_bound(key);
  
//존재시 업데이트
	if( iter !=  mymap.end())
		plus = iter->first;

	iter = mymap2.lower_bound(-1 * key);
//역방향 map 에서 key 바로 직전 key 를 찾아준다.
	if (iter != mymap2.end())
		minus = (iter->first) *-1;

	return make_pair(plus, minus);
}

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
		cout<<mymap[near.first] << '\n';
		return;
	}
	//근접키가 두개다


	cout << "?\n";
	return;
	


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
