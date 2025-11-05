#include <iostream>
#include <vector>
#include <deque>

bool HasCycleDfs(int& x, std::vector<int>& parent, int& v, std::vector<std::vector<int>>& adjacency_list,
                 std::vector<int>& colour) {
  colour[v] = 1;
  for (auto& u : adjacency_list[v]) {
    parent[u] = v;
    if (colour[u] == 1) {
      x = u;
      return true;
    }
    if (colour[u] == 0) {
      if (HasCycleDfs(x, parent, u, adjacency_list, colour)) {
        return true;
      }
    }
  }
  colour[v] = 2;
  return false;
}

bool HasCycle(int& x, std::vector<int>& parent, const int& n, std::vector<std::vector<int>>& adjacency_list) {
  std::vector<int> colour(n + 1, 0);
  for (int i = 1; i < n + 1; ++i) {
    if (colour[i] == 0) {
      if (HasCycleDfs(x, parent, i, adjacency_list, colour)) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  int x = 0;
  int n;
  std::cin >> n;
  int m;
  std::cin >> m;
  std::vector<std::vector<int>> adjacency_list(n + 1);
  int a;
  int b;
  for (int i = 0; i < m; ++i) {
    std::cin >> a >> b;
    adjacency_list[a].push_back(b);
  }
  std::vector<int> parent(n + 1);
  std::deque<int> ans;
  if (HasCycle(x, parent, n, adjacency_list)) {
    std::cout << "YES\n";
    int i = x;
    while (parent[i] != x) {
      ans.push_front(i);
      i = parent[i];
    }
    ans.push_front(i);
    for (auto& k : ans) {
      std::cout << k << " ";
    }
  } else {
    std::cout << "NO";
  }
  return 0;
}
