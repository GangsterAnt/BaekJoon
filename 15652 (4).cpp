//#include <iostream>
//using namespace std;
//
//void search(int now, int min, int max, int detph);
//int arr[9];
//
//int main()
//{
//	int m, n;
//
//	cin >> n >> m;	//N �� �ִ밪  M �� ������ ����
//
//	search(0, 1, n, m);
//	return 0;
//
//}
//
//void search(int now, int min, int max, int depth)
//{
//
//	if (depth == now)
//	{
//		for (int i = 0; i < depth; i++)
//			cout << arr[i] << " ";
//		cout << '\n';
//	}
//	else
//	{
//		for (int i = min; i <= max; i++)		// arr �� ù ���� �������� �����ϱ� ���� lower bound min�� �������ش�.
//		{
//			arr[now] = i;
//			search(now + 1, i, max, depth);
//		}
//	}
//
//}
