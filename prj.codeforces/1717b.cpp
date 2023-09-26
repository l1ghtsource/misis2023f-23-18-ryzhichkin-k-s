#include <iostream>
#include <vector>

int main() {
	int t = 0;
	std::cin >> t;
	for (int _ = 0; _ < t; _++) {
		int n = 0;
		int k = 0;
		int r = 0;
		int c = 0;
		std::cin >> n >> k >> r >> c;
		std::vector<std::vector<char>> mat(n, std::vector<char>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				mat[i][j] = '.';
			}
		}
		for (int p = 1; p <= n; p++) {
			for (int q = 1; q <= n; q++) {
				if (((r + c) % k) == ((p + q) % k)) {
					mat[p - 1][q - 1] = 'X';
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				std::cout << mat[i][j];
			}
			std::cout << std::endl;
		}
	}
	return 0;
}