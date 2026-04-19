#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	string input; cin >> input;
	int size = input.size();

	int answer = 0;
	int start = 0, end = 0, temp = 0, minus = 0;

	while (end < size) {
		while (1) {
			if (end == size - 1 || input[end] == '-' || input[end] == '+') {
				if (end == size - 1) end++;

				temp += stoi(input.substr(start, end - start));
				
				break;
			}

			end++;
		}

		if (minus == 0) {
			answer += temp; 
			temp = 0;
		}

		if (input[end] == '-' || end == size) {
			minus = 1;
			answer -= temp; 
			temp = 0;
		}
		start = end + 1;
		end = start;
	}

	cout << answer;
}