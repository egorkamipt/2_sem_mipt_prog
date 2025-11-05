#include <iostream>
#include <algorithm>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int64_t> animals(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> animals[i];
  }
  int m;
  std::cin >> m;
  std::vector<int64_t> query(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> query[i];
  }
  for (int i = 0; i < m; ++i) {
    std::cout << std::upper_bound(animals.begin(), animals.end(), query[i]) -
                     std::lower_bound(animals.begin(), animals.end(), query[i]);
    std::cout << "\n";
  }
  return 0;
}
