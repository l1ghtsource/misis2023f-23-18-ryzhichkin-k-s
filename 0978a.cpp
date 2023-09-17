#include <iostream>
#include <vector>

bool in(int el, std::vector<int> arr) {
	bool flag = false;
	if (arr.size() != 0) {
		for (int k = 0; k < arr.size(); k++) {
			if (arr[k] == el) {
				flag = true;
				break;
			}
		}
	}
	return (flag);
}

int main() {
	int n, elem, x;
	std::vector<int> data;
	std::vector<int> visited;
	std::vector<int> redacted;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> elem;
		data.push_back(elem);
	}
	for (int j = n - 1; j >= 0; j--) {
		if (!in(data[j], visited)) {
			redacted.push_back(data[j]);
			visited.push_back(data[j]);
		}
	}
	x = redacted.size();
	std::cout << x << std::endl;
	for (int t = x - 1; t >= 0; t--) {
		std::cout << redacted[t] << " ";
	}
	return 0;
}