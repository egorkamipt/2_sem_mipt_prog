#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

class Edge {
 public:
  int v = 0;
  int u = 0;
  int w = 2000000000;
  Edge(int a, int b, int w);
};

Edge::Edge(int a_new, int b_new, int w_new) : v(a_new), u(b_new), w(w_new) {
}

int Deikstra(std::vector<int>& poth, const int& s, const int& n, std::vector<std::unordered_map<int, int>>& graph) {
  std::vector<int> dist(n + 1, 2000000000);
  dist[s] = 0;
  std::set<std::pair<int, int>> q;
  q.insert({dist[s], s});
  while (!q.empty()) {
    int v = q.begin()->second;
    q.erase(q.begin());
    for (auto& u : graph[v]) {
      int to = u.first;
      int time = u.second;
      if (dist[v] + time < dist[to]) {
        q.erase({dist[to], to});
        dist[to] = dist[v] + time;
        q.insert({dist[to], to});
      }
    }
  }
  int maximal = -2000000000;
  for (int i = 0; i < n; ++i) {
    if (i != s && dist[i] != 2000000000 && dist[i] - poth[s] + poth[i] > maximal) {
      maximal = dist[i] - poth[s] + poth[i];
    }
  }
  return maximal;
}

bool Relax(Edge& e, std::vector<int>& dist, std::vector<int>& prev) {
  if (dist[e.v] > dist[e.u] + e.w) {
    dist[e.v] = dist[e.u] + e.w;
    prev[e.v] = e.u;
    return true;
  }
  return false;
}

std::vector<int> BellmanFord(int n, std::vector<Edge>& edges) {
  std::vector<int> dist(n, 2000000000);
  dist[n - 1] = 0;
  std::vector<int> prev(n, -1);
  for (int i = 0; i < n - 1; ++i) {
    for (auto& e : edges) {
      if (dist[e.u] != 2000000000) {
        Relax(e, dist, prev);
      }
    }
  }
  for (auto& e : edges) {
    e.w += dist[e.v] - dist[e.u];
  }
  return dist;
}

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  int a = 0;
  int b = 0;
  int w = 0;
  std::vector<Edge> edges;
  std::vector<std::unordered_map<int, int>> graph(n + 1);
  for (int i = 0; i < m; ++i) {
    std::cin >> a >> b >> w;
    Edge e(a, b, w);
    edges.push_back(e);
  }
  //
  for (int i = 0; i < n; ++i) {
    graph[n][i] = 0;
    Edge e(n, i, 0);
    edges.push_back(e);
  }
  std::vector<int> dist = BellmanFord(n + 1, edges);
  for (auto& e : edges) {
    graph[e.v][e.u] = e.w;
  }
  int maximal = -2000000000;
  for (int i = 0; i < n; ++i) {
    maximal = std::max(maximal, Deikstra(dist, i, n, graph));
  }
  std::cout << maximal;
  return 0;
}
