#include <iostream>
#include <vector>

void DFS(std::vector<int>& colour, std::vector<std::vector<int>>& adjacency_list, int& v) {
  colour[v] = 1;
  for (auto& u : adjacency_list[v]) {
    if (colour[u] == 0) {
      DFS(colour, adjacency_list, u);
    }
  }
  colour[v] = 2;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> graph(n + 1);
  std::vector<int> colour(n + 1);
  int b;
  for (int i = 1; i < n + 1; ++i) {
    std::cin >> b;
    graph[i].push_back(b);
    graph[b].push_back(i);
  }
  int sum = 0;
  for (int i = 1; i < n + 1; ++i) {
    if (colour[i] == 0) {
      DFS(colour, graph, i);
      ++sum;
    }
  }
  std::cout << sum;
  return 0;
}
