#include <iostream>
#include <unordered_map>
#include <string>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n;
  std::cin >> n;
  std::unordered_map<std::string, std::string> words;
  for (int i = 0; i < n; ++i) {
    std::string a;
    std::cin >> a;
    std::string b;
    std::cin >> b;
    words[a] = b;
    words[b] = a;
  }
  int q;
  std::cin >> q;
  for (int i = 0; i < q; ++i) {
    std::string a;
    std::cin >> a;
    std::cout << words[a];
    std::cout << "\n";
  }
  return 0;
}
