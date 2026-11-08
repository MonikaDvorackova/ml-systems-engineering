#include <cassert>
#include <iostream>
#include <vector>
double dot(const std::vector<double>& a, const std::vector<double>& b) {
    assert(a.size() == b.size());
    double result = 0;
    for (std::size_t i = 0; i < a.size(); ++i) result += a[i] * b[i];
    return result;
}
int main() {
    assert(dot({1, 2}, {3, 4}) == 11);
    std::cout << "dot product test passed\n";
}
