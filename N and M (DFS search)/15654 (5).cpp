//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//void search(int* arr,int* temp, bool* visited, int n, int m,int now);
//
//int main()
//{
//	int arr[8],temp[8];
//	bool visited[8] = { false, };
//	int m, n;	// n ¼ýÀÚ max index, m Àº depth
//
//	cin >> n >> m;
//
//	for (int i = 0; i < n; i++)
//		cin>>arr[i];
//	sort(arr, arr + n);
//
//	search(arr,temp, visited, n, m ,0);
//	return 0;
//}
//
//
//void search(int* arr,int* temp, bool* visited, int n, int m, int now)
//{
//	if (now == m)
//	{
//		for (int i = 0; i < m; i++)
//			cout << temp[i] << " ";
//		cout << '\n';
//	}
//	else
//	{
//		for (int i = 0; i < n; i++)
//		{
//			if (visited[i] == false)
//			{
//				visited[i] = true;
//				temp[now] = arr[i];
//				search(arr,temp, visited, n, m, now+1);
//				visited[i] = false;
//			}
//			else
//				continue;
//		}
//	}
//
//}