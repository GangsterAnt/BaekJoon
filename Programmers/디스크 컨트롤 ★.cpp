//https://www.welcomekakao.com/learn/courses/30/lessons/42627

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

struct cmp_heap {

	bool operator()(vector<int>a, vector<int>b)
	{
		return a[1] > b[1];
	}
};

bool cmp(vector<int>a, vector<int> b)
{
	return a[0] < b[0];
}
/*
	접근방법.
	jobs를 어디까지 처리했는지 저장하는 job_index
	작업 처리시간 jobs[i][1]이 작은순 (min_heap)으로 저장된 우선큐 pq
	pq에 들어있다는것은 해당 시간(time) 에 요청을 받은 상태라는 것을 의미한다.
	현재 시간을 나타내는 time을 이용

	알고리즘
	
	가장 시간을 단축하는 방법은 요청이 들어와있는 일들중에 jobs[i][1] ( 처리시간 ) 이 제일 적은것을 먼저 해주는것이
	항상 가장 빠르다.

	proof)
	job[i][1] < job[j][1] 라 하자
	i를 먼저 처리하는 경우 걸리는 시간은  
	(현재시간 - i 의 요청시간) + (현재시간 - j의 요청시간) + job[i][1] ( i의 처리시간 ) + job[i][1] + job[i][2] ( i를 대기하는 시간 + j의 처리시간 )

	j의 처리시간은 
	(현재시간 - i 의 요청시간) + (현재시간 - j의 요청시간) + job[i][1] ( j의 처리시간 ) + job[i][1] + job[i][2] ( j를 대기하는 시간 + i의 처리시간 )

	이므로 
	i를 먼저 처리하는것이 
	job[j][1] -job[i][1] ( > 0 왜냐면 가정 job[i][1] < job[j][1])  만큼 항상 빠르다. 

	구현 방향

	1.	진행중인 일이 없을때
			1-1. pq 가 비어있지 않다면 pq 에서 진행시간이 가장 짧은 pq.top() 을 처리한다.
				 이때 일의 요청부터 종료까지의 시간 : 일을 처리하는데 걸린시간 + (일을 실제로 시작한시간( 현재 time) - 요청시간)
			1-2. pq 가 비어있다면 jobs[ job_index] 를 이용, 현재시간 time 보다 전에 들어온 요청들을 모두 큐에 넣어준다.
				이때 현재 시간 time 을 jobs[job_index]가 들어온 시간 jobs[job_index][0] 으로 변경해준다.
	
	2. 진행중인 일이 있을때
			현재진행중인 일을 마감하고, time += jobs[i][1] 처리를 해줘 시간을 업데이트 한다.
			이후 1.로 이동한다.

	*/
int solution(vector<vector<int>> jobs) {

	int answer = 0;
	sort(jobs.begin(), jobs.end(),cmp);
	priority_queue<vector<int>, vector< vector<int>>, cmp_heap> pq;

	int time = 0;
	int job_index = 0;

	while (1)
	{
		//해당 시간 이전에 job이 있는지 확인
		if(job_index < jobs.size() )
			while (jobs[job_index][0] <= time)
			{
				pq.push(jobs[job_index]);

				if (job_index < jobs.size())
					job_index++;
				if (job_index == jobs.size())
					break;
			}
	
		if (pq.empty())
		{
			//job의 index 검사
			//job 이 비어있다. 끝
			if( job_index == jobs.size())
				break;
			//job 이 안비어있다. 해당시간으로 이동
			else
			{
				time = jobs[job_index][0];
				continue;
			}
		}
		//pq가 안비어있다. 작은것부터 처리하자.
		else 
		{
			auto tmp = pq.top();
			pq.pop();
			answer += tmp[1] + (time - tmp[0]);
			time += tmp[1];
		}


	}

	return answer/ jobs.size();
}


int main()
{

	vector<vector<int>>jobs;
	vector<int>tmp;

	tmp.push_back(0);
	tmp.push_back(3);
	jobs.push_back(tmp);
	tmp.clear();

	tmp.push_back(1);
	tmp.push_back(9);
	jobs.push_back(tmp);
	tmp.clear();

	tmp.push_back(2);
	tmp.push_back(6);
	jobs.push_back(tmp);
	tmp.clear();

	cout << solution(jobs);

	return 0;
}
