#include <iostream>
#include <vector>

class Edge {
 public:
  int u = 0;
  int v = 0;
  int w = 30000;
};

bool Relax(Edge& e, std::vector<int>& dist, std::vector<int>& prev) {
  if (dist[e.v] > dist[e.u] + e.w) {
    dist[e.v] = dist[e.u] + e.w;
    prev[e.v] = e.u;
    return true;
  }
  return false;
}

std::vector<int> BellmanFord(const int& n, std::vector<Edge>& edges) {
  std::vector<int> dist(n + 1, 30000);
  dist[1] = 0;
  std::vector<int> prev(n + 1, -1);
  for (int i = 1; i < n; ++i) {
    for (auto& e : edges) {
      if (dist[e.u] != 30000) {
        Relax(e, dist, prev);
      }
    }
  }
  return dist;
}

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  int u = 0;
  int v = 0;
  int w = 0;
  std::vector<Edge> edges(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> u >> v >> w;
    edges[i].u = u;
    edges[i].v = v;
    edges[i].w = w;
  }
  std::vector<int> dist = BellmanFord(n, edges);
  for (int i = 1; i < n + 1; ++i) {
    std::cout << dist[i] << " ";
  }
  return 0;
}
