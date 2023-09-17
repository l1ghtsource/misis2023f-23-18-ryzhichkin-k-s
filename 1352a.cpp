#include <iostream>
#include <cmath>
#include <vector>


int main() {
	std::vector<int> nums;
	int t, n, k, true_len, true_n, zero_counter, pseudo_n, r, x;
	double l;
	std::cin >> t;
	std::vector<int> data;
	for (int h = 0; h < t; h++) {
		std::cin >> x;
		data.push_back(x);
	}
	for (int i = 0; i < t; i++) {
		n = data[i];
		true_len = floor(log10(n) + 1);
		true_n = n;
		pseudo_n = n;
		zero_counter = 0;
		nums.push_back(n);
		while (n > 10) {
			l = floor(log10(n) + 1);
			n = n % (int)pow(10, l - 1);
			if (n != 0) {
				nums.push_back(n);
			}
		}
		while (pseudo_n > 0) {
			r = pseudo_n % 10;
			if (r == 0) {
				zero_counter++;
			}
			pseudo_n /= 10;
		}
		nums.push_back(0);
		if (zero_counter + 1 == true_len) {
			std::cout << 1 << std::endl;
			std::cout << true_n << std::endl;
		}
		else {
			std::cout << nums.size() - 1 << std::endl;
			for (int j = 1; j < nums.size(); j++) {
				std::cout << nums[j - 1] - nums[j] << " ";
			}
			std::cout << std::endl;
		}
		nums.clear();
	}
	return 0;
}