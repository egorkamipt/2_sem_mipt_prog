#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

void Deikstra(int& s, const int& n, std::vector<std::unordered_map<int, int>>& graph) {
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
  for (int i = 1; i < n + 1; ++i) {
    if (dist[i] == 2000000000) {
      std::cout << "2009000999";
    } else {
      std::cout << dist[i];
    }
    std::cout << " ";
  }
  std::cout << "\n";
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int k = 0;
  std::cin >> k;
  int n = 0;
  int m = 0;
  int v = 0;
  int u = 0;
  int t = 0;
  int me = 0;
  for (int i = 0; i < k; ++i) {
    std::cin >> n >> m;
    std::vector<std::unordered_map<int, int>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
      std::cin >> v >> u >> t;
      ++v;
      ++u;
      if ((v != u) && ((graph[v].find(u) == graph[v].end()) || (t < graph[v][u]))) {
        graph[v][u] = t;
        graph[u][v] = t;
      }
    }
    std::cin >> me;
    ++me;
    Deikstra(me, n, graph);
  }
  return 0;
}
