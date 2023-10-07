#include <iostream>
#include <vector>
#include <string>

int main() {
  std::ios::sync_with_stdio(false);
  long long num_of_houses = 0;
  long long num_of_cases = 0;
  std::cin >> num_of_houses >> num_of_cases;
  long long timer = 0;
  long long prev_pos = 1;
  long long curr_pos = 0;
  for (int i = 0; i < num_of_cases; i++) {
    std::cin >> curr_pos;
    long long dist = curr_pos - prev_pos;
    if (dist >= 0) {
      timer += dist;
    }
    else {
      timer += num_of_houses + dist;
    }
    prev_pos = curr_pos;
  }
  std::cout << timer;
  return 0;
}