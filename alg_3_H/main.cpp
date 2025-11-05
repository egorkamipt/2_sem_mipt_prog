#include <iostream>
#include <vector>

class Edge {
 public:
  int u = 0;
  int v = 0;
  int w = 30000;
};

int BellmanFord(const int& k, const int& s, const int& f, const int& n, std::vector<Edge>& edges) {
  std::vector<int> dist(n + 1, 2000000000);
  dist[s] = 0;
  for (int i = 0; i < std::min(k, n); ++i) {
    std::vector<int> tmp(n + 1, -1);
    for (auto& e : edges) {
      if (dist[e.u] != 2000000000 && dist[e.v] > dist[e.u] + e.w) {
        tmp[e.v] = dist[e.u] + e.w;
      }
    }
    for (int j = 1; j < n + 1; ++j) {
      if (tmp[j] != -1) {
        dist[j] = tmp[j];
      }
    }
  }
  return dist[f];
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n = 0;
  int m = 0;
  int k = 0;
  int s = 0;
  int f = 0;
  std::cin >> n >> m >> k >> s >> f;
  int s_i = 0;
  int f_i = 0;
  int p_i = 0;
  std::vector<Edge> edges(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> s_i >> f_i >> p_i;
    edges[i].u = s_i;
    edges[i].v = f_i;
    edges[i].w = p_i;
  }
  int ans = BellmanFord(k, s, f, n, edges);
  if (ans == 2000000000) {
    std::cout << -1;
  } else {
    std::cout << ans;
  }
  return 0;
}
