#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;


int solution(vector<int> scoville, int K) {

	int answer = 0;
	priority_queue<int, vector<int>, greater<int>>pq;

	for (int i = 0; i < scoville.size(); ++i)
		pq.push(scoville[i]);

	while (1)
	{
		if (pq.empty())
			return -1;
		if (pq.top() >= K)
			break;

		
		answer++;
		int a = pq.top();
		pq.pop();

		if (pq.empty())
			return -1;

		int b = pq.top();
		pq.pop();

		pq.push( (b * 2) + a);
	}

	return answer;
}
