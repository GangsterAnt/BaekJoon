//https://programmers.co.kr/learn/courses/30/lessons/42748

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int a, int b)
{
	return a < b;
}
vector<int> solution(vector<int> array, vector<vector<int>> commands) {

	vector<int> answer;

	for (int t = 0; t < commands.size(); ++t)
	{
		vector<int> v = array;
		int i = commands[t][0];
		int j = commands[t][1];
		int k = commands[t][2];

		v.erase(v.begin() + j, v.end());
		v.erase(v.begin(), v.begin() + i - 1);

		sort(v.begin(), v.end(), cmp);

		answer.push_back(v[k - 1]);
	}
	return answer;
}
