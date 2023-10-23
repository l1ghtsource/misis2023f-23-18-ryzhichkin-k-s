#include <iostream>
#include <vector>

// проверка, есть ли элемент el в массиве arr
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
  int n = 0; // размер массива
  int x = 0; // количество элементов, которые останутся в массиве после удаления дубликатов
  std::cin >> n;
  std::vector<int> data(n); // исходный массив
  std::vector<int> visited; // уже проверенные элементы
  std::vector<int> redacted; // массив после удаления дубликатов
  for (int i = 0; i < n; i++) {
    std::cin >> data[i];
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
