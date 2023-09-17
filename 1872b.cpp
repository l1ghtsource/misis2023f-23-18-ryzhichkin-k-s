#include <iostream>

int main() {
	int t, n, d, s, m, f;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		m = 10000000000;
		std::cin >> n;
		for (int j = 0; j < n; j++) {
			std::cin >> d >> s;
			f = d + (s - 1) / 2;
			if (f < m) {
				m = f;
			}
		}
		std::cout << m << std::endl;
	}
	return 0;
}