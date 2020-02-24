//https://www.acmicpc.net/problem/9019
// queue 의 메모리 초과 해결 못함. 값은 정상 
//반례 0 1000
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
#include <string>
#include <map>

using namespace std;

vector<char> order;
map< int, char> tosort;
bool visited[10000];

int rotateL(int in)
{
	int a, b, c, d;
	a = in / 1000;
	b = in / 100 - a * 10;
	c = in / 10 - a * 100 - b * 10;
	d = in % 10;


	int out = b * 1000 + c * 100 + d * 10 + a;

	return out;
}
int rotateR(int in)
{
	int a, b, c, d;
	a = in / 1000;
	b = in / 100 - a * 10;
	c = in / 10 - a * 100 - b * 10;
	d = in % 10;


	int out = d * 1000 + a * 100 + b * 10 + c;;

	return out;
}

void bfs(int start, int fin);

int main()
{
	int c;
	cin >> c;

	while (c--)
	{
		int start, fin;
		cin >> start >> fin;

		order.clear();
		tosort.clear();
		memset(visited, false, sizeof(visited));

		bfs(start, fin);
		
		/*cout << "Graph is Done\n";
		map<int, char> ::iterator iter;

		for (iter = tosort.begin(); iter != tosort.end(); iter++)
		cout << "[" << iter->first << " , " << iter->second << " ]  \n";*/
		int temp = fin;
		while (1)
		{
			if (temp != start)		//temp는 키이자, 숫자값 path 는 경로 (간선)
			{
				char path = tosort.find(temp)->second;
				order.push_back(path);
				//	cout << "Pushing ..." << path << '\n';
				switch (path)
				{
				case 'D':
					temp = temp / 2;
					continue;
				case 'S':
					temp = (temp + 1) % 10000;
					continue;
				case 'L':
					temp = rotateR(temp);
					continue;
				case 'R':
					temp = rotateL(temp);
					continue;
				}

			}
			else
				break;

		}

		//cout << "Pathfinding is Done\n";

		for (int i = order.size() - 1; i >= 0; --i)
		{
			cout << order[i];
		}
		cout << '\n';
	}

	return 0;
}


void bfs(int start, int fin)
{
	

	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty())
	{
		const int here = q.front(); q.pop();
		int temp;

		if (here == fin)
		{
			return;
		}
		//D
			temp = (here * 2 % 10000);

			if (!visited[temp])
			{
				visited[temp] = true;
				tosort.insert(make_pair(temp, 'D'));
				q.push(temp);

				

			}

			//S

			//temp = (here - 1) < 0 ? 9999 : here - 1;
			if (here == 0)
				temp = 9999;

			else
				temp = here - 1;
			if (!visited[temp])
			{
				visited[temp] = true;
				tosort.insert(make_pair(temp, 'S'));
				q.push(temp);

			

			}

			//L
			temp = rotateL(here);
			if (!visited[temp])
			{
				visited[temp] = true;
				tosort.insert(make_pair(temp, 'L'));
				q.push(temp);

			
			}

			//R
			temp = rotateR(here);
			if (!visited[temp])
			{
				visited[temp] = true;
				tosort.insert(make_pair(temp, 'R'));
				q.push(temp);

				
			}
		
	}
}
