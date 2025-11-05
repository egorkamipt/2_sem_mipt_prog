#include <iostream>
#include <vector>

void DFS(std::vector<char>& colour, std::vector<std::vector<int>>& adjacency_list, int& v) {
  colour[v] = '1';
  for (auto& u : adjacency_list[v]) {
    if (colour[u] == '0') {
      DFS(colour, adjacency_list, u);
    }
  }
  colour[v] = '2';
}

int BigDFS(const int& n, std::vector<std::vector<int>>& graph) {
  int chats = 0;
  std::vector<char> colour(n + 1, '0');
  for (int i = 1; i < n + 1; ++i) {
    if (colour[i] == '0') {
      DFS(colour, graph, i);
      ++chats;
    }
  }
  return chats;
}

void DFSWrite(std::vector<int>& queue, std::vector<char>& colour, std::vector<std::vector<int>>& adjacency_list,
              int& v) {
  queue.push_back(v);
  colour[v] = '1';
  for (auto& u : adjacency_list[v]) {
    if (colour[u] == '0') {
      DFSWrite(queue, colour, adjacency_list, u);
    }
  }
  colour[v] = '2';
}

void BigDFSWrite(const int& n, std::vector<std::vector<int>> graph) {
  std::vector<char> colour(n + 1, '0');
  for (int i = 1; i < n + 1; ++i) {
    if (colour[i] == '0') {
      std::vector<int> queue;
      DFSWrite(queue, colour, graph, i);
      std::cout << queue.size() << "\n";
      for (size_t j = 0; j < queue.size(); ++j) {
        std::cout << queue[j] << " ";
      }
      std::cout << "\n";
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n;
  int m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> graph(n + 1);
  int a;
  int b;
  for (int i = 0; i < m; ++i) {
    std::cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  std::cout << BigDFS(n, graph);
  std::cout << "\n";
  BigDFSWrite(n, graph);
  return 0;
}
