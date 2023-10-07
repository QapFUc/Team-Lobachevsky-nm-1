#include "include/nmlib.hpp"

float test_rhs(float x, float v) {
        return  -(1./2.) * v;
}

int main() {
   resultTable res1 = utils::RK4(test_rhs, utils::make_config(0.f, 20.f, 0.f, 0.f, 0.01, 1000, true, 1e-6));
   for(int i = 0 ; i < 30; i++) {
        LOG_DEBUG_CLI("Result is ", res1.at(i));
   }
   return 0;
}