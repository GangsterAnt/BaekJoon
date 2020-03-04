//https://www.acmicpc.net/problem/1759

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <char> v;
int l, c;
char arr[15];
bool visited[15];

void dfs(int depth, int now, int threshold)
{
	if (depth == now)
	{
		bool aeiou = false;
		int zaeuom = 0;
		for (int i = 0; i < depth; ++i)
		{
			if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u')
				aeiou = true;
			else
				zaeuom++;
			// 자음 모음 모두 체크 해야한다 왜냐면 arr에 모두 모음이 들어온경우 flag = true 이지만 자음 조건을 만족시키지 않는다
		}

		if (aeiou && zaeuom >=2)
		{
			for (int i = 0; i < depth; ++i)
				cout << v[i];
			cout << '\n';
		}
	}

	/*
	
	if (!visited[threshold])
	{
		visited[threshold] = true;
		v.push_back(arr[threshold]);

		for (int i = threshold + 1 ; i < c; ++i)
			dfs(depth, now + 1, i);

		visited[threshold] = false;
		v.pop_back();
	
	}
	
	위 코드가 제대로 동작하지 않는이유는 DFS 함수가 DEPTH 까지 깊게 들어갔고 함수 호출을 종료하였을때 
	FOR 루프를 벗어나지 못하고 다음 index i 로 넘어가기 때문이다. 이때 
	depth l 이 arr의 크기 C 보다 작기 때문에 i++ 이 되어도 for 루프가 끝나지 않으며,
	vector 에 저장되어있는 마지막 원소는 pop 되지 않기 때문에

	백준의 TC 를 기준으로, acis가 3번 출력되게 된다. acist acisw를 생성하는 과정에서 depth 조건에 걸려서 비정상 종료가 일어난다.

	앞으로 dfs 를 구현할때 주의해야 할 부분이다.

	*/
	
	for (int i = threshold; i < c; ++i)
	{
		if (!visited[i])
		{
			visited[i] = true;
			v.push_back(arr[i]);

			dfs(depth, now + 1, i+1);

			visited[i] = false;
			v.pop_back();
		}
	}
		
		

}



int main()
{
	cin >> l >> c;

	for (int i = 0; i < c; ++i)
		cin >> arr[i];

	sort(arr, arr+c);

	
	dfs(l, 0, 0);

	return 0;

}
