#include "../include/matrix.h"
#include <chrono>
#include <iostream>
#include <vector>
int main() {
    constexpr std::size_t n = 128;
    std::vector<float> a(n*n, 0.01f), b(n*n, 0.02f);
    const auto start = std::chrono::steady_clock::now();
    auto c = ml::matmul(a,b,n,n,n);
    const auto elapsed = std::chrono::duration<double, std::milli>(
        std::chrono::steady_clock::now()-start).count();
    std::cout << "n=" << n << " elapsed_ms=" << elapsed << " checksum=" << c[0] << "\n";
}
