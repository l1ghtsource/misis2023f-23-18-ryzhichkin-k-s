#include <iostream>
#include <vector>

int main() {
	int t = 0; // ���������� ������� ������� ������
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		int n = 0; // ���������� �������
		int x = 0; // ���������� ��������� ���������
		std::cin >> n >> x;
		std::vector<int> arr(300);
		for (int i = 1; i <= n + x; i++) {
			arr[i] = 0;
		}
		for (int j = 0; j < n; j++) {
			int a = 0; // ����� � j-� ������
			std::cin >> a;
			arr[a] = 1;
		}
		int ans = 0;
		for (int k = n + x; k > 0; k--) {
			int v = 0;
			for (int r = 1; r <= k; r++) {
				if (arr[r] == 0) {
					v++;
				}
			}
			if (v <= x) {
				ans = k;
				break;
			}
		}
		std::cout << ans << std::endl;
	}
	return 0;
}