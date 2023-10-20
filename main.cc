#include "nmlib.hpp"

float test_rhs(float x, float v, float y) {
        return  -(4./2.) * v;
}

float test_rhs2(float x, float v, float y) {
        return  v;
}

int main() {
   resultTable res1 = utils::RK4_SOE(test_rhs, test_rhs2, utils::make_config(0.f, 40.f, 10.f, 1.f, 0.f, 0.01, 1e15, true, 1e-6));
   for(int i = 0 ; i < res1.size(); i++) {
        LOG_DEBUG_CLI("Result is ", res1.at(i));
   }
   return 0;
}