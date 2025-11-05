#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

void DFSVisit(std::set<int>& art_points, int& time, std::vector<int>& time_up, std::vector<int>& time_in,
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
      DFSVisit(art_points, time, time_up, time_in, colours, false, adj_list, u);
      time_up[v] = std::min(time_up[v], time_up[u]);
      if ((!is_root) && (time_in[v] <= time_up[u])) {
        art_points.insert(v);
      }
    }
  }
  if (is_root && (n_children > 1)) {
    art_points.insert(v);
  }
  colours[v] = 2;
}

std::set<int> APCounter(const int& n, std::vector<std::vector<int>>& graph) {
  std::set<int> art_points;
  std::vector<int> time_up(n + 1);
  std::vector<int> time_in(n + 1);
  int time = 0;
  std::vector<int> colours(n + 1);
  for (int i = 1; i < n + 1; ++i) {
    if (colours[i] == 0) {
      DFSVisit(art_points, time, time_up, time_in, colours, true, graph, i);
    }
  }
  return art_points;
}

int main() {
  int n;
  int m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> graph(n + 1);
  int b;
  int e;
  for (int i = 1; i < m + 1; ++i) {
    std::cin >> b >> e;
    graph[b].push_back(e);
    graph[e].push_back(b);
  }
  std::set<int> art_points = APCounter(n, graph);
  std::cout << art_points.size() << "\n";
  for (auto& i : art_points) {
    std::cout << i << "\n";
  }
  return 0;
}
