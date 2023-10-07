#include "include/nmlib.hpp"

float const_rhs1(float x, float v) {
        return 1.f;
}

float const_rhs2(float x, float v) {
        return (2.f*x*x)/7+x/3;
}

int main() {
   resultTable res1 = utils::RK4(const_rhs1, utils::make_config(0.f, 500.f, 0.f, 0.f, 0.05, 10000, true,0.00001));
   LOG_DEBUG_CLI("Result is ", res1.at(1000));
   resultTable res2 = utils::RK4(const_rhs2, utils::make_config(0.f, 500.f, 0.f, 0.f, 0.0035, 10000, true,0.00001));
   LOG_DEBUG_CLI("Result is ", res2.at(9999));
   return 0;
}