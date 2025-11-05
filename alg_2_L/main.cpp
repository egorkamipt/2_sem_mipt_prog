#include <iostream>
#include <vector>
#include <algorithm>

void DFSVisit(std::vector<int>& colours, std::vector<std::vector<int>>& adj_list, std::vector<int>& component, int& v) {
  component.push_back(v);
  colours[v] = 1;
  for (auto& u : adj_list[v]) {
    if (colours[u] == 0) {
      DFSVisit(colours, adj_list, component, u);
    }
  }
  colours[v] = 2;
}

std::vector<std::vector<int>> DFS(std::vector<std::vector<int>>& adj_list, std::vector<int>& order, const int& n) {
  std::vector<int> colours(n + 1, 0);
  std::vector<std::vector<int>> components;
  size_t size;
  for (auto& v : order) {
    if (colours[v] == 0) {
      components.emplace_back();
      size = components.size();
      DFSVisit(colours, adj_list, components[size - 1], v);
    }
  }
  return components;
}

void TopSortNoCyclesDFS(std::vector<int>& top_sorted, std::vector<int>& colours,
                        std::vector<std::vector<int>>& adj_list, int& v) {
  colours[v] = 1;
  for (auto& u : adj_list[v]) {
    if (colours[u] == 0) {
      TopSortNoCyclesDFS(top_sorted, colours, adj_list, u);
    }
  }
  colours[v] = 2;
  top_sorted.push_back(v);
}

std::vector<int> TopSortNoCycles(const int& n, std::vector<std::vector<int>>& adj_list) {
  std::vector<int> colours(n + 1, 0);
  std::vector<int> top_sorted;
  for (int i = 1; i < n + 1; ++i) {
    if (colours[i] == 0) {
      TopSortNoCyclesDFS(top_sorted, colours, adj_list, i);
    }
  }
  std::reverse(top_sorted.begin(), top_sorted.end());
  return top_sorted;
}

void Transpose(std::vector<std::vector<int>>& adj_list, const int& n) {
  std::vector<std::vector<int>> new_list(n + 1);
  for (int i = 1; i < n + 1; ++i) {
    for (auto& j : adj_list[i]) {
      new_list[j].push_back(i);
    }
  }
  adj_list = new_list;
}

size_t SCC(std::vector<int>& ans, const int& n, std::vector<std::vector<int>>& adj_list) {
  std::vector<int> order = TopSortNoCycles(n, adj_list);
  Transpose(adj_list, n);
  std::vector<std::vector<int>> components = DFS(adj_list, order, n);
  for (size_t i = 0; i < components.size(); ++i) {
    for (auto& j : components[i]) {
      ans[j] = i + 1;
    }
  }
  return components.size();
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n;
  int m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> graph(n + 1);
  int a;
  int b;
  for (int i = 1; i < m + 1; ++i) {
    std::cin >> a >> b;
    graph[a].push_back(b);
  }
  std::vector<int> ans(n + 1);
  std::cout << SCC(ans, n, graph);
  std::cout << "\n";
  for (int i = 1; i < n + 1; ++i) {
    std::cout << ans[i] << " ";
  }
  return 0;
}
