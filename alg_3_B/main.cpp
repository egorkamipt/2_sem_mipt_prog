#include <iostream>
#include <vector>

int FindSet(int& x, std::vector<std::pair<int, int>>& parent) {
  if (x == parent[x].first) {
    return x;
  }
  return parent[x].first = FindSet(parent[x].first, parent);
}

void Union(int& x, int& y, std::vector<std::pair<int, int>>& parent) {
  x = FindSet(x, parent);
  y = FindSet(y, parent);
  parent[x].first = y;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  std::vector<std::pair<int, int>> parent(n + 1, std::pair<int, int>(0, 0));
  for (int i = 1; i < n + 1; ++i) {
    parent[i].first = i;
  }
  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;
  for (int i = 0; i < m; ++i) {
    std::cin >> a;
    if (a == 1) {
      std::cin >> b >> c >> d;
      if (FindSet(b, parent) != FindSet(c, parent)) {
        parent[FindSet(c, parent)].second += d + parent[FindSet(b, parent)].second;
        Union(b, c, parent);
      } else {
        parent[FindSet(b, parent)].second += d;
      }
    } else if (a == 2) {
      std::cin >> b;
      std::cout << parent[FindSet(b, parent)].second << "\n";
    }
  }
  return 0;
}
