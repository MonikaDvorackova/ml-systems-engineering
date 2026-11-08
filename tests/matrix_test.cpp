#include "../include/matrix.h"
#include <cassert>
#include <cmath>
int main() {
    auto c = ml::matmul({1,2,3,4,5,6}, {7,8,9,10,11,12}, 2,3,2);
    assert(c.size()==4);
    assert(std::fabs(c[0]-58)<1e-5);
    assert(std::fabs(c[1]-64)<1e-5);
    assert(std::fabs(c[2]-139)<1e-5);
    assert(std::fabs(c[3]-154)<1e-5);
    bool threw = false;
    try { ml::matmul({1},{2},2,1,1); } catch (const std::invalid_argument&) { threw=true; }
    assert(threw);
}
