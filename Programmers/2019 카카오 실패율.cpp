//https://www.welcomekakao.com/learn/courses/30/lessons/42889

#include <string>
#include <vector>
#include<algorithm>

using namespace std;

bool cmp(const pair<int, float>&a, const pair<int, float>&b)
{

    if(a.second != b.second)
        return a.second > b.second;

else return a.first < b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    vector<float>head(N+2);
    vector<float>tail(N+2,stages.size());

    for (int i = 0; i < stages.size(); ++i)
    {
        head[stages[i]]++;
    }

    for (int i = 1; i < N + 2; ++i)
        for(int j=1; j<i; ++j)
        tail[i]  -= head[j];



    vector<pair<int, float>>v;

    for (int i = 1; i <=N; ++i)
    {//0으로 나누는것 주의
        if (tail[i] == 0)
            v.emplace_back(i, 0);
    else
        v.emplace_back(i, head[i] / tail[i]);

    }

    sort(v.begin(), v.end(),cmp);

    for (int i = 0; i < v.size(); ++i)
        answer.push_back(v[i].first);
    return answer;
}
