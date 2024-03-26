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
auto init = []()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 'c';
}();

class Rectangle
{
public:
  const int width;
  const int height;
  const int area;

  Rectangle(int w, int h) : width(w), height(h), area(h * w) {}
  Rectangle(int h) : width(1), height(h), area(h) {}

  Rectangle operator||(const Rectangle &other) const
  {
    if (other.height > height)
    {
      if (other.area > area)
      {
        return other;
      }

      return Rectangle(width + other.width, height);
    }
    
    if ((width + other.width) * other.height > area)
    {
      return Rectangle(width + other.width, other.height);
    }
    return Rectangle(width, height);
  }
};

class Solution
{
public:
  int largestRectangleArea(vector<int> &heights)
  {
    if (heights.size() == 1)
    {
      return heights[0];
    }
    return _aux(heights, 0).area;
  }

  Rectangle _aux(vector<int> &heights, int i)
  {
    if (heights.size() - i-1 == 0)
    {
      return Rectangle(heights[0]);
    }
    else
    {
      Rectangle right = Rectangle(heights[i]);
      Rectangle left = _aux(heights, i + 1);
      return left || right;
    }
  }
};

int main()
{
  Solution sol;

  // vector<int> heights = {2, 1, 5, 6, 2, 3};
  // vector<int> heights = {2, 4};
  vector<int> heights = {4, 2};

  auto result = sol.largestRectangleArea(heights);
  fmt::println("{}", result);

  return 0;
}
