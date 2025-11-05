#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> quantity(2001);
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    ++quantity[a + 1000];
  }
  int x;
  std::cin >> x;
  std::cout << quantity[x + 1000];
  return 0;
}
