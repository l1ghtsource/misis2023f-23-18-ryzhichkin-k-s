#include <iostream>
#include <cmath>

void solve() {
	unsigned long long n = 0;
	unsigned long long k = 0;
	std::cin >> n >> k;
	unsigned long long ans = ((unsigned long long)std::pow(2, k % 6) * n) % 9;
	std::cout << ans << std::endl;
}

int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		solve();
	}
}