#include <iostream>

int main() {
	int n, k, f, t, p, m;
	m = -100000000000000000;
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		std::cin >> f >> t;
		if (t > k) {
			p = f - (t - k);
		}
		else {
			p = f;
		}
		if (p > m) {
			m = p;
		}
	}
	std::cout << m;
	return 0;
}