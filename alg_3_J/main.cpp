#include <iostream>
#include <vector>
#include <unordered_map>

int Deikstra(const int& s, const int& t, const int& n, std::vector<std::vector<int>>& graph) {
  std::vector<int> dist(n + 1, 2000000000);
  dist[s] = 0;
  std::vector<bool> u(n + 1, false);
  for (int i = 1; i < n + 1; ++i) {
    int v = -1;
    for (int j = 1; j < n + 1; ++j) {
      if (!u[j] && (v == -1 || dist[j] < dist[v])) {
        v = j;
      }
    }
    if (dist[v] == 2000000000) {
      break;
    }
    u[v] = true;
    for (int j = 1; j < n + 1; ++j) {
      if (graph[v][j] != -1 && j != v) {
        int to = j;
        int len = graph[v][j];
        if (dist[v] + len < dist[to]) {
          dist[to] = dist[v] + len;
        }
      }
    }
  }
  if (dist[t] == 2000000000) {
    return -1;
  }
  return dist[t];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n = 0;
  int s = 0;
  int t = 0;
  std::cin >> n >> s >> t;
  std::vector<std::vector<int>> graph(n + 1, std::vector<int>(n + 1));
  for (int i = 1; i < n + 1; ++i) {
    for (int j = 1; j < n + 1; ++j) {
      std::cin >> graph[i][j];
    }
  }
  std::cout << Deikstra(s, t, n, graph);
  return 0;
}
