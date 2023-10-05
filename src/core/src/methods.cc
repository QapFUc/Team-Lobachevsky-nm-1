#include "nmlib.hpp"

resultTable utils::RK4(std::function<float(float,float)> rhs, config cfg) {
    resultTable table;
    float xi = cfg.x_min;
    float vi = cfg.u_0;
    float stepi = cfg.step;
    i = 0
    while (xi <= cfg.x_max && i <= cfg.N_max) {
        tableRow row;
        k1 =  rhs(xi ,vi);
        k2 = rhs(xi+stepi/2 ,vi + (stepi/2) * k1);
        k3 = rhs(xi+stepi/2 ,vi + (stepi/2) * k2);
        k4 = rhs(xi+stepi ,vi + stepi * k3);
        xi = xi + stepi;
        vi = vi + step/6 +( k1 + 2 * k2 + 2 * k3 + k4 );
        
    }
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