//https://programmers.co.kr/learn/courses/30/lessons/42583
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int now_weight = 0;
	int time = 0;

	queue<int> truck;
	deque<pair<int, int>> bridge;
	

	for (int i = 0; i < truck_weights.size(); ++i)
		truck.push(truck_weights[i]);


	while (!truck.empty())
	{             
		time++;
		//빼는거 먼저 해줘야 후발주자가 들어올수 있다 weight 업데이트 우선
		if (!bridge.empty())
		{
			if (bridge.front().second + bridge_length <= time)
			{
				auto b = bridge.front();
				now_weight -= b.first;
				//cout << "Pop : " << b.first << " Time : " << time<< '\n';
				bridge.pop_front();
			}
		}

		int t = truck.front();

		if (now_weight + t <= weight)
		{
			now_weight += t;
			bridge.push_back(make_pair(t, time));
			truck.pop();
			//cout << "Pusing Back : " << t << " Time : " << time<<" Now_Weight : "<< now_weight << '\n';
		}
	}


	return time + bridge_length;
}
