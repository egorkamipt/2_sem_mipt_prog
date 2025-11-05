#include <iostream>
#include <algorithm>
#include <vector>

class Team {
 public:
  int64_t solved;
  int64_t time;
  int64_t number;
};

bool Comparator(Team& a, Team& b) {
  if (a.solved > b.solved) {
    return true;
  }
  if (a.solved == b.solved && a.time < b.time) {
    return true;
  }
  if (a.solved == b.solved && a.time == b.time && a.number < b.number) {
    return true;
  }
  return false;
}

int main() {
  int64_t n;
  std::cin >> n;
  std::vector<Team> teams(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> teams[i].solved >> teams[i].time;
    teams[i].number = i + 1;
  }
  std::sort(teams.begin(), teams.end(), Comparator);
  for (int i = 0; i < n; ++i) {
    std::cout << teams[i].number;
    std::cout << "\n";
  }
  return 0;
}
