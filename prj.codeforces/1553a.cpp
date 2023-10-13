#include <iostream>

void solve() {
	int n = 0;
	std::cin >> n;
	std::cout << ((n + 1) / 10) << std::endl;
}

int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		solve();
	}
}