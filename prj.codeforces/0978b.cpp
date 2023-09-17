#include <iostream>

int main() {
	int n, x_counter = 0, max_x = 0, summary = 0;
	std::string s;
	s += 'z';
	std::cin >> n;
	std::cin >> s;
	for (int i = 0; i <= n; i++) {
		if (s[i] == 'x') {
			x_counter += 1;
		}
		else {
			max_x = (x_counter > max_x) ? x_counter : max_x;
			summary += (max_x > 2) ? max_x - 2 : 0;
			x_counter = 0;
			max_x = 0;
		}
	}
	std::cout << summary;
	return 0;
}