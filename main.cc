#include "nmlib.hpp"

float test_rhs(float x, float v) {
        return  -(4./2.) * v;
}

int main() {
   resultTable res1 = utils::RK4(test_rhs, utils::make_config(0.f, 40, 0.f, 1.f, 0.f, 0.01, 10000, true, 1e-6));
   for(int i = 0 ; i < res1.size(); i++) {
        LOG_DEBUG_CLI("Result is ", res1.at(i).xi);
   }
   return 0;
}