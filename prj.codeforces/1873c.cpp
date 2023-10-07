#include <iostream>
#include <vector>
#include <string>

int main() {
	std::ios::sync_with_stdio(false);
	int t = 0;
	int total = 0;
	std::cin >> t;
	std::vector<std::vector<int>> arr(10, std::vector<int>(10));
	arr = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
		{1, 2, 3, 3, 3, 3, 3, 3, 2, 1},
		{1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
		{1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
		{1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
		{1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
		{1, 2, 3, 3, 3, 3, 3, 3, 2, 1},
		{1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	for (int r = 0; r < t; r++) {
		for (int j = 0; j < 10; j++) {
			for (int i = 0; i < 10; i++) {
				char s;
				std::cin >> s;
				if (s == 'X') {
					total += arr[i][j];
				}
			}
		}
		std::cout << total << std::endl;
		total = 0;
	}
	return 0;
}