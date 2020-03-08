10972 반대로

#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int arr[10001];
bool fin = 0;
void pre_permutation(int n);

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	pre_permutation(n);

	if (!fin)
	{
		for (int i = 0; i < n; ++i)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
	}
	else
	{
		cout << "-1\n";
	}
	return 0;

}

void pre_permutation(int n)
{
	int i = n - 1;

	while (i > 0 && arr[i - 1] <= arr[i]) // 내림차순이면 pass
		i -= 1;

	if (i == 0)	//다 내림차순이면 end permutation
	{
		fin = 1;
		return;
	}

	else
	{

		//arr[i-1] 을 arr[i-1] 이후 값중 최소로 ,arr[i]부터를 오름차순으로;
		int threshold = i;

		sort(arr + i, arr + n, greater<int>() );

		while (threshold <= n)
		{
			if (arr[i - 1] > arr[threshold])
			{
				int temp = arr[i - 1];
				arr[i - 1] = arr[threshold];
				arr[threshold] = temp;
				break;
			}
			else
				threshold += 1;
		}

	}


}
