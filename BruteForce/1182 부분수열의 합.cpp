//https://www.acmicpc.net/problem/1182

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[20];
bool visited[20];

int search(int s,int n, int index);

int main()
{
	int n, s;

	cin >> n>>s;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	cout << search(s,n, 0);

	return 0;

}


int search(int s, int n, int index)
{
	int result = 0;
	 
	if (s == 0)
	{
		// 부분수열이 공집합인 경우를 제외해줘야 한다.. S ==0 일떄 공집합이 정답으로 처리되므로
		// 정답수 +1 이 되는 결과가 발생한다.
		for (int i = 0; i < n; ++i)
		{
			if (visited[i] == true)	
			{
				result += 1;
				break;
			}
		}

	/*	for (int i = 0; i < n; ++i)
		{
			if (visited[i] == true)
				cout << arr[i] << " ";
		}
		cout << '\n';*/

	}

	
	for (int i = index; i < n; ++i)
	{
		if (!visited[i])
		{
			visited[i] = true;
			result += search(s - arr[i], n, i);
			visited[i] = false;
		}

	}

	return result;
}
