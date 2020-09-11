//https://programmers.co.kr/learn/courses/30/lessons/42842

#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	int n; int m;

	int total = brown 		+yellow;

	for (int n = 3; n <= sqrt(total); ++n)
	{
		if (total %n == 0)
		{
			int m = total / n;

			if (m < 3)
				continue;

			if (yellow == (n - 2)*(m - 2))
			{
				answer.push_back(max(m,n));
				answer.push_back(min(m,n));

				return answer;
			}



		}
	}

	return answer;
}
