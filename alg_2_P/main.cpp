#include <iostream>
#include <vector>
#include <set>

void DFSVisit(int edge, std::set<int>& bridges, int& time, std::vector<int>& time_up, std::vector<int>& time_in,
              std::vector<int>& colours, std::vector<std::vector<std::pair<int, int>>>& adj_list, int& v) {
  colours[v] = 1;
  time_in[v] = ++time;
  time_up[v] = time;
  for (auto& u : adj_list[v]) {
    if (u.second == edge) {
      continue;
    }
    if (colours[u.first] == 1) {
      time_up[v] = std::min(time_up[v], time_in[u.first]);
    }
    if (colours[u.first] == 0) {
      DFSVisit(u.second, bridges, time, time_up, time_in, colours, adj_list, u.first);
      time_up[v] = std::min(time_up[v], time_up[u.first]);
      if (time_in[v] < time_up[u.first]) {
        bridges.insert(u.second);
      }
    }
  }
  colours[v] = 2;
}

std::set<int> BridgesCounter(const int& n, std::vector<std::vector<std::pair<int, int>>>& graph) {
  std::set<int> bridges;
  std::vector<int> time_up(n + 1);
  std::vector<int> time_in(n + 1);
  int time = 0;
  std::vector<int> colours(n + 1);
  for (int i = 1; i < n + 1; ++i) {
    if (colours[i] == 0) {
      DFSVisit(0, bridges, time, time_up, time_in, colours, graph, i);
    }
  }
  return bridges;
}

int main() {
  int n;
  int m;
  std::cin >> n >> m;
  std::vector<std::vector<std::pair<int, int>>> graph(n + 1);
  int a;
  int b;
  for (int i = 0; i < m; ++i) {
    std::cin >> a >> b;
    graph[a].emplace_back(b, i + 1);
    graph[b].emplace_back(a, i + 1);
  }
  std::set<int> bridges = BridgesCounter(n, graph);
  std::cout << bridges.size();
  std::cout << "\n";
  for (auto& i : bridges) {
    std::cout << i << " ";
  }
  return 0;
}
