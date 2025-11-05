#include <iostream>
#include <vector>

void FloydWarshall(int v, std::vector<std::vector<int>>& d) {
  for (int k = 0; k < v; ++k) {
    for (int x = 0; x < v; ++x) {
      for (int y = 0; y < v; ++y) {
        d[x][y] = std::min(d[x][y], d[x][k] + d[k][y]);
      }
    }
  }
}

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<std::vector<int>> adj_matrix(n, std::vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> adj_matrix[i][j];
    }
  }
  FloydWarshall(n, adj_matrix);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cout << adj_matrix[i][j] << " ";
    }
    std::cout << "\n";
  }
  return 0;
}
