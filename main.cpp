
#include <fmt/ranges.h>
#include <fmt/core.h>
#include <vector>
#include <fmt/chrono.h>


using namespace std;

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
