#include "include/nmlib.hpp"

float const_rhs(float x, float v) {
        return 1.f;
}

int main() {
   resultTable res = utils::RK4(const_rhs, utils::make_config(0.f, 5.f, 0.f, 0.f, 0.05, 1000, false,0.0));
   LOG_DEBUG_CLI("Result is ", res.at(2));
   return 0;
}