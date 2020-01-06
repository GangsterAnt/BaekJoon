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

	for (int i = 0; i < n-1; i++)
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
}
