//https://programmers.co.kr/learn/courses/30/lessons/43165

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {

	int answer = 0;
	int size = numbers.size();

	for (int bitmask = (1 << size) - 1; bitmask >= 0; --bitmask)
	{
		int tmp = 0;
		int tmp_bit = bitmask;

		for (int i = size - 1; i >= 0; --i)
		{
			int pm = tmp_bit & 1;
			tmp_bit = tmp_bit >> 1;

			if (pm == 1) // plus
				tmp += numbers[i];
			else
				tmp -= numbers[i];
		}
		if (tmp == target)
			answer++;
	}


	return answer;
}
