#pragma once
#include <cstddef>
#include <stdexcept>
#include <vector>

namespace ml {
inline std::vector<float> matmul(const std::vector<float>& a, const std::vector<float>& b,
                                  std::size_t m, std::size_t k, std::size_t n) {
    if (m == 0 || k == 0 || n == 0 || a.size() != m*k || b.size() != k*n)
        throw std::invalid_argument("invalid matrix dimensions");
    std::vector<float> out(m*n, 0.0f);
    for (std::size_t i=0; i<m; ++i)
        for (std::size_t p=0; p<k; ++p)
            for (std::size_t j=0; j<n; ++j)
                out[i*n+j] += a[i*k+p]*b[p*n+j];
    return out;
}
}
