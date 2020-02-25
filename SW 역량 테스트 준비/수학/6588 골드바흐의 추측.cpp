#include <iostream>
#include <vector>

using namespace std;
#define MAX 1000001

int main()
{
	//이거 없으면 시간 초과남 ... ㅅㅂ
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);			

	bool arr[MAX] = { 0, }; //100만
	vector<int> v;


	for (int i = 2; i < MAX; ++i)	// 에라토스테네스의 체
	{
		if (arr[i] == false)
		{
			v.push_back(i);

			for (int j = i*2; j < MAX; j += i)
				arr[j] = true;
		}
	}

	/*while (true) {		//정답코드
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		for (int i = 1; i < v.size(); i++) {
			if (arr[n - v[i]] == false) {
				cout << n << " = " << v[i] << " + " << n - v[i] << '\n';
				break;
			}
		}
	}*/

	int here =0;
	
	cin >> here;

	while (here)
	{

		for (int i = 0; i < v.size() - 1; ++i)
		{
			if (v[i] > here)
			{
				cout << " Goldbach's conjecture is wrong.\n";
				break;
			}
			
			if (arr[here - v[i]] == false)
			{
				cout << here << " = " << v[i] << " + " << here - v[i] << '\n';
				break;
			}
			
		}

		cin >> here;
		
	}

	return 0;
}
