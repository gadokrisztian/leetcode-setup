#include <iostream>

#include <fmt/ranges.h>
#include <fmt/core.h>
#include <vector>
#include <fmt/chrono.h>

#pragma GCC optimize("O3", "inline", "fast-math", "tree-vectorize")
//#pragma GCC target("arch=native")

using namespace std;

// Boost i/o.
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main() {
    int n = 54;
    fmt::println("dawdaw {} dad awd", n);

    vector<int> alma = {1, 2, 3, 4, 5};
    fmt::println("alma: {}", alma);

    auto now = std::chrono::system_clock::now();
    fmt::print("Date and time: {}\n", now);
    fmt::print("Time: {:%H:%M}\n", now);

    return 0;
}
