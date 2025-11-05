#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n;
  std::cin >> n;
  int k;
  std::cin >> k;
  std::vector<std::vector<int>> adjacency_list(n + 1);
  for (int i = 0; i < k; ++i) {
    int tmp;
    std::cin >> tmp;
    if (tmp == 1) {
      int u;
      int v;
      std::cin >> u;
      std::cin >> v;
      adjacency_list[u].push_back(v);
      adjacency_list[v].push_back(u);
    } else if (tmp == 2) {
      int u;
      std::cin >> u;
      for (auto i : adjacency_list[u]) {
        std::cout << i << " ";
      }
      std::cout << "\n";
    }
  }
  return 0;
}
