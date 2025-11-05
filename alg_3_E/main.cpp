#include <iostream>
#include <vector>

class Edge {
 public:
  int u = -1;
  int v = -1;
  int w = 2000000000;
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

int64_t Boruvka(const int& n, std::vector<Edge>& edges) {
  std::vector<int> parent(n);
  for (int i = 0; i < n; ++i) {
    parent[i] = i;
  }
  int set_count = n;
  int64_t mst_w = 0;
  while (set_count > 1) {
    std::vector<Edge> min_edge(n);
    for (auto& e : edges) {
      int component_v = FindSet(e.v, parent);
      int component_u = FindSet(e.u, parent);
      if (component_v != component_u) {
        if (e.w < min_edge[component_v].w) {
          min_edge[component_v] = e;
        }
        if (e.w < min_edge[component_u].w) {
          min_edge[component_u] = e;
        }
      }
    }
    for (auto& e : min_edge) {
      if (e.w == 2000000000) {
        continue;
      }
      if (FindSet(e.v, parent) != FindSet(e.u, parent)) {
        mst_w += e.w;
        Union(e.v, e.u, parent);
        --set_count;
      }
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
  std::vector<Edge> edges(m);
  int u = 0;
  int v = 0;
  int w = 0;
  for (int i = 0; i < m; ++i) {
    std::cin >> u >> v >> w;
    edges[i].u = --u;
    edges[i].v = --v;
    edges[i].w = w;
  }
  std::cout << Boruvka(n, edges);
  return 0;
}
