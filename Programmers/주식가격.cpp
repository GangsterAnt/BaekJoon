//https://programmers.co.kr/learn/courses/30/lessons/42584
#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer(prices.size(), 0);

	int size = prices.size();
	stack<int>s;

	for (int i = 0; i < size; ++i)	
	{

		while (!s.empty() && (prices[s.top()] > prices[i]))
		{
			answer[s.top()] = i - s.top();
			s.pop();
		}

		s.push(i);
	}

	while (!s.empty())
	{
		answer[s.top()] = size - 1 - s.top();
		s.pop();
	}
	

	return answer;
}
