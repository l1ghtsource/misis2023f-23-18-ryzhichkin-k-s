#include <iostream>

int main() {
	int t, n, a, c;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		std::cin >> n;
		c = 0;
		for (int j = 0; j < n; j++) {
			std::cin >> a;
			if (a % 2 != 0) {
				c++;
			}
		}
		if (c % 2 == 0) {
			std::cout << "YES" << std::endl;
		}
		else {
			std::cout << "NO" << std::endl;
		}
	}
	return 0;
}