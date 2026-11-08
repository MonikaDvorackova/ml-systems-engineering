#pragma once
#include "matrix.h"
#include <algorithm>
#include <cstdint>
#include <cmath>
#include <limits>
namespace ml {
inline std::vector<float> matmul_blocked(const std::vector<float>& a, const std::vector<float>& b,
  std::size_t m, std::size_t k, std::size_t n, std::size_t block=32) {
  if (!block || !m || !k || !n || m > SIZE_MAX/k || k > SIZE_MAX/n || m > SIZE_MAX/n ||
      a.size()!=m*k || b.size()!=k*n)
    throw std::invalid_argument("invalid matrix dimensions");
  std::vector<float> out(m*n, 0.0f);
  for (std::size_t ii=0;ii<m;ii+=std::min(block,m-ii))
    for (std::size_t pp=0;pp<k;pp+=std::min(block,k-pp))
      for (std::size_t jj=0;jj<n;jj+=std::min(block,n-jj))
        for (std::size_t i=ii;i<ii+std::min(block,m-ii);++i)
          for (std::size_t p=pp;p<pp+std::min(block,k-pp);++p)
            for (std::size_t j=jj;j<jj+std::min(block,n-jj);++j)
              out[i*n+j]+=a[i*k+p]*b[p*n+j];
  return out;
}
}
