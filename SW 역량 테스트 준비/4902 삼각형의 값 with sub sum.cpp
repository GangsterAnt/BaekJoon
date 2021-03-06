//https://www.acmicpc.net/problem/4902
//http://codeplus.codes/fc4635361cd3470ea1bd66a11ed91f1a
// ANS 가 0 으로 초기화되면 모든 삼각형의 값이 음수인경우 답이 0이 되는경우 존재.
// 삼각형 row 는 400  값의 절대값은 1000 미만이라 하였으므로... 400 * 400 * 1000 * -1 이 lowerbound임 200만 더줘서 -1800만을 lowerbound로 설정하고 구현

#include<iostream>
#include <vector>
#include <algorithm>

#define LOWERBOUND -18000000
using namespace std;

void summaker(const vector<vector<int>>& v, vector<vector<int>> & subsum)
{

	int height = v.size();
	
	for (int i = 0; i < height; ++i)
	{
		int tmp = 0;
		subsum.emplace_back();
		for (int j = 0; j <= 2 * i; ++j)
		{
			tmp += v[i][j];
			subsum[i].emplace_back(tmp);
		}
	}
	
	/*for (int i = 0; i < subsum.size(); ++i)
	{
		for (int j = 0; j < subsum[i].size(); ++j)
			cout << subsum[i][j] << ' ';
		cout << '\n';
	}*/
	return;
}
int topdown(vector<vector<int>>& v, vector<vector<int>> & subsum ,int y, int x )
{
	//정방 삼각형의 경우 ㅅ 모양일때..

	int height = v.size(); 
	
	int tmp = 0;
	int ans = LOWERBOUND;
	//조건 1 . 아래층이 있을것. ( i+k < n )
	//부분 삼각형의 j 증가율 ( j+ 2k) 
	//이 가장 큰 삼각형의 증가율 (j +2k) 을 넘지 못한다.

	for (int i = y; i < height; ++i)
	{
		
		int diff = i - y; // 현재 부분 삼각형의 높이 
		
		int left = x; int right = x + 2 * diff;

		if (left == 0)
			tmp += subsum[i][right];
		else
		tmp += (subsum[i][right] - subsum[i][left-1]);

		//cout << "\nY : "<< y << " X : " << x<<"  Height : "<<diff<< "\n	Result : " << tmp << '\n';
			//한층의 연산이 끝나면 비교후 저장
		if (ans == LOWERBOUND || ans < tmp)
			ans = tmp;
	
	}

	return ans;
}

int bottomup(vector<vector<int>>& v, vector<vector<int>> & subsum, int y, int x)
{
	int height = v.size();
	int tmp = 0;
	int ans = LOWERBOUND;

	//조건1 윗층이 존재한다 i >=0
	for (int i = y;  i>= 0; --i)
	{

		int diff = y-i; // 현재 부분 삼각형의 높이 

		int left = x- 2* diff ;
		int right = x;

		if (right > 2 * i)
			break;
		if (left < 0)
			break;

		tmp += (subsum[i][right] - subsum[i][left-1]);
		//한층의 연산이 끝나면 비교후 저장
		if (ans == LOWERBOUND || ans < tmp)
			ans = tmp;
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
		vector<vector<int>>sub;
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

		summaker(v, sub);

		cout << step << ". ";
		step++;

		int ans = LOWERBOUND;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j <= 2 * i; ++j)
			{
				if (j % 2 == 0)
				{
					int tmp = topdown(v, sub, i, j);
					if (ans == LOWERBOUND || ans < tmp)
						ans = tmp;
				}
				else
				{
					int tmp = bottomup(v, sub, i, j);
					if (ans == LOWERBOUND || ans < tmp)
						ans = tmp;

				}
					
			}
		}

		cout << ans << '\n';
			
	}

	return 0;
}
