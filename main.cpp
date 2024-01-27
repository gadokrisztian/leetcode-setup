#include <algorithm>
#include <cstddef>
#include <iostream>

#include <fmt/chrono.h>
#include <fmt/core.h>
#include <fmt/ranges.h>
#include <stack>
#include <vector>

using namespace std;

#pragma GCC optimize("O3", "inline", "fast-math", "tree-vectorize")
// #pragma GCC target("arch=native")


// Boost i/o.
auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 'c';
}();

class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    if(heights.size() == 1) {
      return heights[0];
    }
    pair<int, int> result = _aux(heights, 0);
    return result.first * result.second;
  }

  pair<int, int> _aux(vector<int> &heights, int i) {
    if (heights.size() - i == 1) {
      return {1, heights[0]};
    } else {
      pair<int, int> left = _aux(heights, i + 1);
      if ((left.first + 1) * heights[i] >= left.first * left.second) {
        return {left.first, heights[i]};
      } else {
        return left;
      }
    }
  }
};

int main() {
  Solution sol;

  vector<int> heights = {2, 1, 5, 6, 2, 3};
  // vector<int> heights = {2, 4};
  // vector<int> heights = {4, 2};

  auto result = sol.largestRectangleArea(heights);
  fmt::println("{}", result);

  return 0;
}
