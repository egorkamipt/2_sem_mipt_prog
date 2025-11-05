#include <iostream>
#include <vector>
#include <algorithm>

bool TopSortDFS(std::vector<int>& top_sorted, std::vector<int>& colours, std::vector<std::vector<int>>& adj_list,
                int& v) {
  colours[v] = 1;
  for (auto& u : adj_list[v]) {
    if (colours[u] == 1) {
      return false;
    }
    if (colours[u] == 0) {
      if (!TopSortDFS(top_sorted, colours, adj_list, u)) {
        return false;
      }
    }
  }
  colours[v] = 2;
  top_sorted.push_back(v);
  return true;
}

std::vector<int> TopSort(const int& n, std::vector<std::vector<int>>& adj_list) {
  std::vector<int> colours(n + 1, 0);
  std::vector<int> top_sorted;
  for (int i = 1; i < n + 1; ++i) {
    if (colours[i] == 0) {
      if (!TopSortDFS(top_sorted, colours, adj_list, i)) {
        std::vector<int> ans;
        ans.push_back(-1);
        return ans;
      }
    }
  }
  std::reverse(top_sorted.begin(), top_sorted.end());
  return top_sorted;
}

int main() {
  int n;
  int m;
  std::cin >> n >> m;
  int a;
  int b;
  std::vector<std::vector<int>> graph(n + 1);
  for (int i = 0; i < m; ++i) {
    std::cin >> a >> b;
    graph[a].push_back(b);
  }
  std::vector<int> ans = TopSort(n, graph);
  for (size_t i = 0; i < ans.size(); ++i) {
    std::cout << ans[i] << " ";
  }
  return 0;
}
