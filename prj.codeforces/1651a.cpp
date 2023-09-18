#include <iostream>
#include <cmath>

int main() {
	int t, n;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		std::cin >> n;
		std::cout << (int)pow(2, n) - 1 << std::endl;
	}
	return 0;
}