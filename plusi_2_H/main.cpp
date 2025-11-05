#include <iostream>
#include <map>

int main() {
  std::map<std::string, std::map<std::string, int64_t>> data_base;
  std::string name;
  std::string product;
  int cost;
  while (std::cin >> name) {
    std::cin >> product;
    std::cin >> cost;
    if (data_base.find(name) == data_base.end()) {
      data_base[name][product] = cost;
    } else if (data_base[name].find(product) == data_base[name].end()) {
      data_base[name][product] = cost;
    } else {
      data_base[name][product] += cost;
    }
  }
  for (auto i : data_base) {
    std::cout << i.first << ":";
    std::cout << "\n";
    for (auto j : i.second) {
      std::cout << j.first << " " << j.second;
      std::cout << "\n";
    }
  }
  return 0;
}
