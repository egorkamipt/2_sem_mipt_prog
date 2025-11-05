#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

int Prim(std::vector<std::unordered_map<int, int>>& graph, const int& n) {
  int mst_w = 0;
  std::vector<int> dist(n + 1, 2000000000);
  dist[1] = 0;
  std::vector<int> prev(n + 1, -1);
  std::set<int> s;
  while (s.size() != static_cast<size_t>(n)) {
    int v = 1;
    for (int i = 1; i < n + 1; ++i) {
      if (dist[i] < dist[v]) {
        v = i;
      }
    }
    s.insert(v);
    dist[v] = 2000000000;
    if (prev[v] != -1) {
      mst_w += graph[v][prev[v]];
    }
    for (auto& u : graph[v]) {
      if (s.find(u.first) == s.end() && u.second < dist[u.first]) {
        prev[u.first] = v;
        dist[u.first] = u.second;
      }
    }
  }
  return mst_w;
}

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  int b = 0;
  int e = 0;
  int w = 0;
  std::vector<std::unordered_map<int, int>> graph(n + 1);
  for (int i = 0; i < m; ++i) {
    std::cin >> b >> e >> w;
    if (graph[b].find(e) == graph[b].end()) {
      graph[b][e] = w;
      graph[e][b] = w;
    } else {
      if (graph[b][e] > w) {
        graph[b][e] = w;
        graph[e][b] = w;
      }
    }
  }
  std::cout << Prim(graph, n);
  return 0;
}
