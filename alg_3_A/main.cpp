#include <iostream>
#include <vector>

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

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  std::vector<std::pair<int, int>> parent(n + 1, );
  for (int i = 1; i < n + 1; ++i) {
    parent[i] = i;
  }
  int x = 0;
  int y = 0;
  int counter = n;
  int ans = 0;
  bool flag = true;
  for (int i = 0; i < m; ++i) {
    std::cin >> x >> y;
    ++x;
    ++y;
    if (FindSet(x, parent) != FindSet(y, parent)) {
      --counter;
      Union(x, y, parent);
    }
    if (flag && counter <= 1) {
      ans = i + 1;
      flag = false;
    }
  }
  std::cout << ans;
  return 0;
}
