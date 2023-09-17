#include <iostream>
#include <cmath>

int main() {
	int t, a, b, c, ans;
	double delta = 0, n = 0;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		std::cin >> a >> b >> c;
		delta = abs(a - b);
		n = delta / (2 * c);
		std::cout << ceil(n) << std::endl;

	}
	return 0;
}