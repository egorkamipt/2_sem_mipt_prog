#include <iostream>
#include <vector>
#include <algorithm>

class Edge {
 public:
  int a = 0;
  int b = 0;
  int w = 2000000000;
  Edge(int a, int b, int w);
};

Edge::Edge(int a_new, int b_new, int w_new) : a(a_new), b(b_new), w(w_new) {
}

std::vector<int> BellmanFord(const int& n, std::vector<Edge>& edges) {
  std::vector<int> dist(n);
  std::vector<int> prev(n, -1);
  int x = 0;
  for (int i = 0; i < n; ++i) {
    x = -1;
    for (auto& j : edges) {
      if (dist[j.b] > dist[j.a] + j.w) {
        dist[j.b] = std::max(-2000000000, dist[j.a] + j.w);
        prev[j.b] = j.a;
        x = j.b;
      }
    }
  }
  if (x == -1) {
    std::vector<int> no_cycle;
    return no_cycle;
  }
  int y = x;
  for (int i = 0; i < n; ++i) {
    y = prev[y];
  }
  std::vector<int> path;
  for (int tmp = y;; tmp = prev[tmp]) {
    path.push_back(tmp);
    if (tmp == y && path.size() > 1) {
      break;
    }
  }
  std::reverse(path.begin(), path.end());
  return path;
}

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<Edge> edges;
  int w = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> w;
      if (w != 100000) {
        Edge e(i, j, w);
        edges.push_back(e);
      }
      if (i == j) {
        Edge e(i, j, 0);
        edges.push_back(e);
      }
    }
  }
  std::vector<int> path = BellmanFord(n, edges);
  if (path.size() == static_cast<size_t>(0)) {
    std::cout << "NO";
  } else {
    std::cout << "YES\n";
    std::cout << path.size() << "\n";
    for (size_t i = 0; i < path.size(); ++i) {
      std::cout << path[i] + 1 << " ";
    }
  }
  return 0;
}
