#include <iostream>
#include <unordered_map>

int main() {
  int n;
  std::cin >> n;
  std::unordered_map<std::string, int> bank_accounts;
  std::string name;
  int sum;
  int command;
  for (int i = 0; i < n; ++i) {
    std::cin >> command;
    std::cin >> name;
    if (command == 1) {
      std::cin >> sum;
      bank_accounts[name] += sum;
    } else if (command == 2 && bank_accounts.find(name) != bank_accounts.end()) {
      std::cout << bank_accounts[name];
      std::cout << "\n";
    } else if (bank_accounts.find(name) == bank_accounts.end()) {
      std::cout << "ERROR";
      std::cout << "\n";
    }
  }
  return 0;
}
