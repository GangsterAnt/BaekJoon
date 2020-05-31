//https://www.acmicpc.net/problem/4902
//http://codeplus.codes/fc4635361cd3470ea1bd66a11ed91f1a
// 시간초과.. 부분합 구하기 필요한듯.
#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int topdown(vector<vector<int>>& v ,int y, int x )
{
	//정방 삼각형의 경우 ㅅ 모양일때..

	int height = v.size(); 
	
	int tmp = 0;
	int ans = tmp;
	//조건 1 . 아래층이 있을것. ( i+k < n )
	//부분 삼각형의 j 증가율 ( j+ 2k) 
	//이 가장 큰 삼각형의 증가율 (j +2k) 을 넘지 못한다.

	for (int i = y; i < height; ++i)
	{
		
		int diff = i - y; // 현재 부분 삼각형의 높이 
		for (int j = x; j <= x + 2 * diff; ++j)
		{
			tmp += v[i][j];
		}
		//cout << "\nY : "<< y << " X : " << x<<"  Height : "<<i<< "\n	Result : " << tmp << '\n';
		ans = max(tmp, ans);	//한층의 연산이 끝나면 비교후 저장
	}

	return ans;
}

int bottomup(vector<vector<int>>& v , int y, int x)
{
	int height = v.size();
	int tmp = 0;
	int ans = tmp;

	//조건1 윗층이 존재한다 i >=0
	for (int i = y;  i>= 0; --i)
	{
		int diff = i - y; // 현재 부분삼각형의 높이.

		for (int j = x; j >= x - 2 * diff; --j)
		{
			if (j > 2 * i)	// j 가 높이 i의 최대 x 좌표값 2i 를 초과하면 안된다.
				break;
			if (j - 2 * diff < 0)	// j가 0 미만이 되면 안된다.
				break;
			tmp += v[i][j];
		}
		//cout << "\nY : " << y << " X : " << x << "  Height : " << i << "\n	Result : " << tmp << '\n';
		//한층의 연산이 끝나면 비교후 저장
		ans = max(tmp, ans);
	}

	return ans;

}


int main()
{ 
	

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int step = 1;

	while (1)
	{
		int n;
		cin >> n;

		if (n == 0)
			break;



		vector<vector<int>> v;

		for(int j =0; j<n;++j)
		{	vector<int> tmpvector;
			int tmp;

				// n 번째 층에 2n+1 만큼의 원소를 집어넣는  방식 ( 0층 1개시작)
			for (int i = 0; i < 2 * j + 1; ++i)
			{
				cin >> tmp;
				tmpvector.emplace_back(tmp);
			}

			v.emplace_back(tmpvector);
		}

		cout << step << ". ";
		step++;

		int ans = 0;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j <= 2 * i; ++j)
			{
				if (j % 2 == 0)
					ans = max(ans, topdown(v,i,j));
				else
					ans = max(ans, bottomup(v,i,j));
			}
		}

		cout << ans << '\n';
			
	}

	return 0;
}
