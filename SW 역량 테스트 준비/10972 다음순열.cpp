/*
핵심내용은 오름차순과 내림차순이 반복적으로 나타나게되는데 이때의 경계선( 12543 에서 5는 오름차와 내림차순의 경계선)
의 적절한 처리를 해줘야한다.

키를 간단히 설명하자면.

순열은 모든 원소가 오름차순에서 시작하고, index 의 끝부터 내림차순으로 정렬하는과정을 거쳐 모든 원소가 내림차순으로 정렬되고 끝난다.

12543 를 예시로 들면 오름차순은 125 이고 내림차는 543이다 . 이떄 가장 오른쪽에서부터 오름차순을 찾아내고 그 경계선 2와 5를 찾아낸다

12 543 에서 다음순열은 13245이다. 이를 어떻게 찾아낼까?

우선 경계선 2를 2보다 큰 무언가로 swap 해야할것이다. 순열의 성질에 의해, 경계선 2는 순열상 뒤에있는(arr의 index에서) 것중 사전상 뒤에있는 (이 예시에서는 5 4 3 모두해당된다) 원소중 가장 작은것이 와야한다. (즉 3이와야한다)

그러면 어떠한 알고리즘에 의해 3을 찾았다고 가정하자. 즉 13___ 까지 완성한것이다. 이때 이후의 숫자들은 오름차순으로 정렬되어야 한다.

왜냐하면 13 으로 시작하는 순열중 가장 빠른 순열이 와야하므로. 이는 sort 함수에 의해 간단히 정렬된다.

이제 3을 어떻게 찾아내는지 확인해보자.

만약 3을 찾아내지 않고 sort 함수를 사용하면 어떨까? 12 543 은 12 345 로 정렬될것이다.
이때 경계선 2 의 index 뒤의 원소들 ( arr[2] arr[3] arr[4]) 는 오름차순으로 정렬되어있으므로 ,,, index가 작은것부터 2와 비교하여,

2보다 큰 첫번째 원소 ( 사전상 뒤에있는 원소중 가장 작은것) 3을 찾아내고, 3과 2를 swap 시켜주면된다.

즉 이 알고리즘은 오른쪽부터 오름차순을 찾아내어 오름차순의 마지막 원소를 다음 사전순인 원소로 바꿔주고, 그 뒤를 오름차로 정렬해 놓는다.
어찌보면 분할정복이다.


12'5'43 -> 12 345 -> 13 245 로 바꾼다.

순열이 섞여있는경우도 상관없다.

1253'4' 는 34가 가장 오른쪽 오름차순 , 4 이하에는 원소가 없으므로 오름차순 정렬 불가, 3 이하에 수중에서 3보다 가장큰 하나 와 swap
-> 12'5'43 이된다.,

*/



#include <iostream>
#include <algorithm>

using namespace std;
int arr[10001];
bool fin = 0;
void next_permutation(int n);

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	next_permutation(n);

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

void next_permutation(int n)
{
	int i = n - 1;

	while (i > 0 && arr[i - 1] >= arr[i]) // 오름차순이면 pass
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

		sort(arr + i, arr + n);

		while (threshold <= n)
		{
			if (arr[i - 1] < arr[threshold])
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
