#include <algorithm>
#include <cctype>
#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <vector>

#if defined(WITH_GTEST)
#include <gtest/gtest.h>
#endif

#define PokerMax 52
// last number is deck
#define TotalPilesNum 8
#define DeckNum 7

class Poker {
  // constructions
public:
  // methods
public:
  void init_piles(std::string &input);
  std::string game_play(void);
  void show();

private:
  void pick_up_check(int order);
  bool combination_check(int a, int b, int c);

  // data
private:
  std::array<std::deque<int>, TotalPilesNum> piles_;
  std::set<std::vector<std::deque<int>>> pile_set_;
  int play_count;
  std::string game_result;
};

bool Poker::combination_check(int a, int b, int c) {
  int sum = a + b + c;
  return (sum % 10 == 0);
}

void Poker::pick_up_check(int order) {
  while (1) {

    if (piles_[order].size() < 3)
      break;

    int size = piles_[order].size();
    int f = piles_[order].front();
    int s = piles_[order][1];
    int e3 = piles_[order][size - 3];
    int e2 = piles_[order][size - 2];
    int last = piles_[order].back();
    if (combination_check(f, s, last) == true) {
      piles_[DeckNum].push_back(f);
      piles_[DeckNum].push_back(s);
      piles_[DeckNum].push_back(last);
      piles_[order].pop_front();
      piles_[order].pop_front();
      piles_[order].pop_back();
      continue;
    }
    if (combination_check(f, e2, last) == true) {
      piles_[DeckNum].push_back(f);
      piles_[DeckNum].push_back(e2);
      piles_[DeckNum].push_back(last);
      piles_[order].pop_front();
      piles_[order].pop_back();
      piles_[order].pop_back();
      continue;
    }
    if (combination_check(e3, e2, last) == true) {
      piles_[DeckNum].push_back(e3);
      piles_[DeckNum].push_back(e2);
      piles_[DeckNum].push_back(last);
      piles_[order].pop_back();
      piles_[order].pop_back();
      piles_[order].pop_back();
      continue;
    }
    break;
  }
}

void Poker::init_piles(std::string &input) {
  // clear private data
  play_count = 0;
  pile_set_.clear();
  game_result.clear();
  for (int i = 0; i < TotalPilesNum; i++)
    piles_[i].clear();

  // init private data
  std::stringstream ss(input);
  std::string token;
  while (std::getline(ss, token, ' ')) {
    int num = stoi(token);
    if (play_count < TotalPilesNum) {
      piles_[play_count].push_back(num);
      play_count++;
    } else {
      piles_[DeckNum].push_back(num);
    }
  }
}

std::string Poker::game_play() {
  int order = 0;
  for (int count = play_count;; count++) {

    int poker_num = piles_[DeckNum].front();
    piles_[DeckNum].pop_front();
    piles_[order].push_back(poker_num);

    pick_up_check(order);

    std::vector<std::deque<int>> piles_vector(piles_.begin(), piles_.end());
    if (pile_set_.find(piles_vector) != pile_set_.end()) {
      game_result = std::string("Draw: ") + std::to_string(count);
      break;
    }
    pile_set_.insert(piles_vector);

    if (piles_[DeckNum].size() == 0) {
      game_result = std::string("Loss: ") + std::to_string(count);
      break;
    }

    if (piles_[DeckNum].size() == PokerMax) {
      game_result = std::string("Win : ") + std::to_string(count);
      break;
    }

    order = (order + 1) % (TotalPilesNum - 1);
    while (piles_[order].size() == 0) {
      order = (order + 1) % (TotalPilesNum - 1);
    }
  }
  return game_result;
}

void Poker::show(void) {
  std::cout << "deck : " << std::endl;
  for (auto it : piles_[DeckNum])
    std::cout << it << " ";
  std::cout << std::endl;

  for (int i = 0; i < (TotalPilesNum - 1); i++) {
    std::cout << "piles_" << i << ":" << std::endl;
    for (auto it : piles_[i])
      std::cout << it << " ";
    std::cout << std::endl;
  }
}

void solve_uva_problem(std::istream &is, std::ostream &os) {
  Poker poker;
  while (1) {
    std::string input;
    std::getline(is, input);
    if (input.compare("0") == 0)
      break;
    poker.init_piles(input);
    os << poker.game_play() << std::endl;
  }
}

int main(int argc, char **argv) {
#if !defined(WITH_GTEST)
  solve_uva_problem(std::cin, std::cout);
#else
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
#endif
}
