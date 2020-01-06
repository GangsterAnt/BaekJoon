//https://www.acmicpc.net/problem/15664
#include <algorithm>
#include <iostream>

using namespace std;

int arr[8], temp[8], visited[8];
void search(int m, int n, int now, int min);

int main()
{
	int m, n;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		visited[i] = 1;
	}

	sort(arr, arr + n);

	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] == arr[i + 1])
		{
			visited[i] += visited[i + 1];

			for (int j = i + 1; j < n - 1; j++)
			{
				arr[j] = arr[j + 1];
				visited[j] = visited[j + 1];
			}
			n -= 1;
			i -= 1;
		}

	}

	//for (int i = 0; i < n; i++)
	//	cout << arr[i] << ' ';
	//cout << '\n';
	//for (int i = 0; i < n; i++)
	//	cout << visited[i] << ' ';
	//cout << '\n';

	search(m, n, 0, 0);
	return 0;
}

void search(int m, int n, int now, int min)
{
	if (m == now)
	{
		for (int i = 0; i < m; i++)
		{
			cout << temp[i] << ' ';
		}
		cout << '\n';
	}
	else
	{
		for (int i = min; i < n; i++)
		{
			if (visited[i] != 0)
			{
				temp[now] = arr[i];
				visited[i] -= 1;
				search(m, n, now + 1, i ); // 중복이 가능하므로... i 을 전달 ( not i+1)
				visited[i] += 1;
			}
		}
		
	}
}
