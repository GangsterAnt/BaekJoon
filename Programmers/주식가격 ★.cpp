//https://programmers.co.kr/learn/courses/30/lessons/42584
#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer(prices.size(), 0);

	int size = prices.size();

	//stack 은 현재 index 이전 원소들중 해결되지 않은것들을 저장한다.
	stack<int>s;

	for (int i = 0; i < size; ++i)
	{
		// 스택에 원소가 있고 ( 이전에 처리하지 못한 원소가 있고)
		// 스택맨위의 원소가 현재 index보다 값이 높은경우 ( 가격이 하락한경우)
		// 해당 원소의 정답을 입력해주고
		//반복을통해 스택내에 다른 원소들도 가격이 하락했는지 확인한다.
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
