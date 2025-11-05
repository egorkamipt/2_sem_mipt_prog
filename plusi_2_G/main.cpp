#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

bool Comparator(std::pair<int, std::string> a, std::pair<int, std::string> b) {
  if (a.first > b.first) {
    return true;
  }
  if (a.first == b.first && a.second < b.second) {
    return true;
  }
  return false;
}

int main() {
  std::string str;
  std::unordered_map<std::string, int> dictionary;
  while (std::cin >> str) {
    if (dictionary.find(str) != dictionary.end()) {
      ++dictionary[str];
    } else {
      dictionary[str] = 1;
    }
  }
  std::vector<std::pair<int, std::string>> dict_vector;
  for (auto i : dictionary) {
    dict_vector.emplace_back(i.second, i.first);
  }
  std::sort(dict_vector.begin(), dict_vector.end(), Comparator);
  for (auto i : dict_vector) {
    std::cout << i.second;
    std::cout << "\n";
  }
  return 0;
}
