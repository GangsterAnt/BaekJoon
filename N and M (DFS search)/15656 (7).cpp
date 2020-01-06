//#include<iostream>
//#include <algorithm>
//
//using namespace std;
//
//int temp[7], arr[7];
//
//
//void search(int m, int n, int now);
//
//int main()
//{
//	int m, n;
//	cin >> n >> m;
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//
//	sort(arr, arr + n);
//	search(m, n, 0);
//
//
//	return 0;
//}
//
//void search(int m, int n, int now)
//{
//	if (m == now)
//	{
//		for (int i = 0 ; i < m; i++)
//			cout << temp[i] << ' ';
//		cout << '\n';
//	}
//	else
//	{
//		for (int i = 0; i < n; i++)
//		{
//			temp[now] = arr[i];
//			search(m, n, now + 1);
//		}
//	}
//}