#include <iostream>
#include <vector>

bool TopSortDFS(std::vector<int>& colours, std::vector<std::vector<int>>& adj_list, int& v) {
  colours[v] = 1;
  for (auto& u : adj_list[v]) {
    if (colours[u] == 1) {
      return false;
    }
    if (colours[u] == 0) {
      if (!TopSortDFS(colours, adj_list, u)) {
        return false;
      }
    }
  }
  colours[v] = 2;
  return true;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> graph(n + 1);
  char tmp;
  for (int i = 1; i < n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      std::cin >> tmp;
      if (tmp == 'B') {
        graph[i].push_back(j);
      } else if (tmp == 'R') {
        graph[j].push_back(i);
      }
    }
  }
  bool flag = true;
  std::vector<int> colours(n + 1, 0);
  for (int i = 1; i < n + 1; ++i) {
    if (colours[i] == 0) {
      if (!TopSortDFS(colours, graph, i)) {
        flag = false;
      }
    }
  }
  if (flag) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
  return 0;
}
