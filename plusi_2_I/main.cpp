#include <iostream>
#include <queue>

int main() {
  std::priority_queue<int, std::vector<int>, std::greater<int>> queue;
  double sum = 0;
  int n;
  std::cin >> n;
  int tmp;
  for (int i = 0; i < n; ++i) {
    std::cin >> tmp;
    queue.push(tmp);
  }
  int a;
  for (int i = 0; i < n - 1; ++i) {
    tmp = queue.top();
    queue.pop();
    a = queue.top();
    sum = sum + 0.05 * (tmp + a);
    queue.pop();
    queue.push(tmp + a);
  }
  std::cout << sum;
  return 0;
}
