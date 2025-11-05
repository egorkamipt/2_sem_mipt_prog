#include <iostream>
#include <vector>

class Edge {
 public:
  int u;
  int v;
  int w;
};

int FindSet(int& x, std::vector<int>& parent) {
  if (x == parent[x]) {
    return x;
  }
  return parent[x] = FindSet(parent[x], parent);
}

void Union(int& x, int& y, std::vector<int>& parent) {
  x = FindSet(x, parent);
  y = FindSet(y, parent);
  parent[x] = y;
}

int Kruskal(const int& n, std::vector<Edge>& edges) {
  int mst_w = 0;
  std::vector<int> parent(n + 1);
  for (int i = 1; i < n + 1; ++i) {
    parent[i] = i;
  }
  for (auto& e : edges) {
    if (FindSet(e.v, parent) != FindSet(e.u, parent)) {
      Union(e.v, e.u, parent);
      mst_w += e.w;
    }
  }
  return mst_w;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
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
  std::cout << Kruskal(n, edges);
  return 0;
}
