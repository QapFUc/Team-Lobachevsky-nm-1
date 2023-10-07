#include "nmlib.hpp"
#include <cmath>

float utils::StepRK4(std::function<float(float,float)> rhs, float x, float u, float step) {
    float new_u, k1, k2, k3, k4;
    k1 = rhs(x, u);
    k2 = rhs(x + step/2, u + step/2 * k1);
    k3 = rhs(x + step/2, u + step/2 * k2);
    k4 = rhs(x + step, u + step * k3);
    new_u = u + step/6 * (k1 + (2 * k2) + (2 * k3) + k4);
    return(new_u);
}

resultTable utils::RK4(std::function<float(float,float)> rhs, config cfg) {
    LOG_INFO_CLI("Start RK4 with following config", cfg);

    resultTable table;

    
}

/// @todo Implement core functions
resultTable test_task_a(config cfg) {
    [](){};
}
resultTable test_task_b(config cfg) {
    [](){};
}

resultTable first_task_a(config cfg) {
    [](){};
}
resultTable first_task_b(config cfg) {
    [](){};
}

resultTable second_task_a(config cfg) {
    [](){};
}
resultTable second_task_b(config cfg) {
    [](){};
}