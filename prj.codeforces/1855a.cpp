#include <iostream>
#include <vector>
#include <cmath>

int main() {
  int t, n, a, q, ans;
  std::vector<int> prearr;
  std::vector<int> p;
  std::vector<std::vector<int>> arr;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    std::cin >> n;
    for (int j = 0; j < n; j++) {
      std::cin >> a;
      prearr.push_back(a);
    }
    arr.push_back(prearr);
    prearr.clear();
  }
  for (int k = 0; k < t; k++) {
    p = arr[k];
    q = 0;
    for (int m = 0; m < p.size(); m++) {
      if (m + 1 == p[m]) {
        q++;
      }
    }
    ans = (q + 1) / 2;
    std::cout << ans << std::endl;
  }
  return 0;
}
