//#include <iostream>
//#include <algorithm>
//using namespace std;
//void search(int m, int n, int now, int min);
//
//int arr[8], temp[8];
//bool visited[8] = { false, };
//int main()
//{
//	int m, n;
//	cin >> n>> m;
//
//	for (int i = 0; i < n; i++)
//		cin >> arr[i];
//
//	sort(arr, arr + n);
//	search(m, n, 0, 0);
//
//	return 0;
//}
//
//void search(int m, int n, int now,int min)
//{
//	if (m == now)
//	{
//		for (int i = 0; i < m; i++)
//			cout << temp[i] << " ";
//		cout << '\n';
//	}
//
//	else
//	{
//		for (int i = min; i < n; i++)
//		{
//			if (visited[i] == false)
//			{
//				visited[i] = true;
//				temp[now] = arr[i];
//				search(m, n, now+1, i+1);
//				visited[i] = false;
//
//			}
//
//		}
//
//	}
//}