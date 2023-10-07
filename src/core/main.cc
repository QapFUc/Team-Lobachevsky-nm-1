#include "include/nmlib.hpp"

float const_rhs1(float x, float v) {
        return 1.f;
}

float const_rhs2(float x, float v) {
        return 2.f*x;
}

int main() {
   resultTable res1 = utils::RK4(const_rhs1, utils::make_config(0.f, 5.f, 0.f, 0.f, 0.05, 1000, false,0.0));
   LOG_DEBUG_CLI("Result is ", res1.at(2));
   resultTable res2 = utils::RK4(const_rhs2, utils::make_config(0.f, 5.f, 0.f, 0.f, 0.05, 1000, false,0.0));
   LOG_DEBUG_CLI("Result is ", res2.at(2));
   return 0;
}