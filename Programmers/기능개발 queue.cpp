//https://programmers.co.kr/learn/courses/30/lessons/42586

#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int> q;

	int size = speeds.size();
	int index = 0;
	int day = 0;

	for (int i = 0; i < size; ++i)
		q.push(i);
	
	while (!q.empty())
	{
		int ans = 0;

		if (progresses[q.front()] < 100)
		{
			for (int i = 0; i < size; ++i)
				progresses[i] += speeds[i];
			day++;
			continue;
		}

		else
		{
			while ( !q.empty() && progresses[q.front()] >= 100)
			{
				ans++;
				q.pop();
			}
		}

		answer.push_back(ans);

	}
	

	return answer;
}
