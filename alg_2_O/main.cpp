#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

void DFSVisit(const int& n, std::set<int>& art_points, int& time, std::vector<int>& time_up, std::vector<int>& time_in,
              std::vector<int>& colours, bool is_root, std::vector<std::vector<int>>& adj_list, int& v) {
  colours[v] = 1;
  time_in[v] = ++time;
  time_up[v] = time;
  int n_children = 0;
  for (auto& u : adj_list[v]) {
    if (colours[u] == 1) {
      time_up[v] = std::min(time_up[v], time_in[u]);
    }
    if (colours[u] == 0) {
      ++n_children;
      DFSVisit(n, art_points, time, time_up, time_in, colours, false, adj_list, u);
      time_up[v] = std::min(time_up[v], time_up[u]);
      if ((!is_root) && (time_in[v] <= time_up[u])) {
        if (v > n) {
          art_points.insert(v);
        }
      }
    }
  }
  if (is_root && (n_children > 1)) {
    if (v > n) {
      art_points.insert(v);
    }
  }
  colours[v] = 2;
}

std::set<int> APCounter(const int& n, const int& n_new, std::vector<std::vector<int>>& graph) {
  std::set<int> art_points;
  std::vector<int> time_up(n_new + 1);
  std::vector<int> time_in(n_new + 1);
  int time = 0;
  std::vector<int> colours(n_new + 1);
  for (int i = 1; i < n_new + 1; ++i) {
    if (colours[i] == 0) {
      DFSVisit(n, art_points, time, time_up, time_in, colours, true, graph, i);
    }
  }
  return art_points;
}

int main() {
  int n;
  int m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> graph(n + 1);
  int a;
  int b;
  int c;
  graph.resize(n + 1 + m);
  for (int i = 0; i < m; ++i) {
    std::cin >> a >> b >> c;
    graph[n + i + 1].push_back(a);
    graph[n + i + 1].push_back(b);
    graph[n + i + 1].push_back(c);
    graph[a].push_back(n + i + 1);
    graph[b].push_back(n + i + 1);
    graph[c].push_back(n + i + 1);
  }
  size_t n_new = graph.size() - 1;
  std::set<int> art_points = APCounter(n, n_new, graph);
  std::cout << art_points.size() << "\n";
  for (auto& i : art_points) {
    std::cout << i - n << " ";
  }
  return 0;
}
