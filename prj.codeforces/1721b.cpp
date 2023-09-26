#include <iostream>

int main() {
	int t = 0;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		int n = 0;
		int m = 0;
		int s_x = 0;
		int s_y = 0;
		int d = 0;
		std::cin >> n >> m >> s_x >> s_y >> d;
		if (std::min(s_x - 1, m - s_y) > d || std::min(s_y - 1, n - s_x) > d) {
			std::cout << n + m - 2 << std::endl;
		}
		else {
			std::cout << -1 << std::endl;
		}
	}
	return 0;
}