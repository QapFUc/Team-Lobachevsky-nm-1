#include "nmlib.hpp"

resultTable utils::RK4(std::function<float(float,float)> rhs, config cfg) {
    resultTable table;
    float xi = cfg.x_min;
    float vi = cfg.u_0;
    float xi1 = xi;
    float vi1 = vi;
    float xi2 = xi;
    float vi2 = vi;
    float v2i = cfg.u_0;
    float stepi = cfg.step;
    bool LEC = cfg.LEC;
    int C1 = 0; // count div
    int C2 = 0; // count mult
    float v2i = cfg.u_0; // point for step/2
    float viv2i = 0;
    float stepi2 = cfg.step/2;
    float LE = 0;
    bool flag = 1;
    i = 0
    while (xi <= cfg.x_max && i <= cfg.N_max) {
        flag = 1;
        // (xi,vi)
        k1 =  rhs(xi ,vi);
        k2 = rhs(xi+stepi/2 ,vi + (stepi/2) * k1);
        k3 = rhs(xi+stepi/2 ,vi + (stepi/2) * k2);
        k4 = rhs(xi+stepi ,vi + stepi * k3);
        xi1 = xi + stepi;
        vi1 = vi + stepi/6 +( k1 + 2 * k2 + 2 * k3 + k4 );
        // (xi,vi2)
        xi2 = xi;
        vi2 = vi;
        for(int j = 0; j<=1; j++) {
            k1 =  rhs(xi ,v2i);
            k2 = rhs(xi+stepi2/2 ,vi + (stepi2/2) * k1);
            k3 = rhs(xi+stepi2/2 ,vi + (stepi2/2) * k2);
            k4 = rhs(xi+stepi2 ,vi + stepi2 * k3);
            xi2 = xi2 + stepi2;
            v2i = v2i + stepi2/6 +( k1 + 2 * k2 + 2 * k3 + k4 );
        }
        // LEC
        if (LEC) {
            LE = (v2i -vi1)/(pow(2,4) - 1);
            if (LE <= eps) {
                xi = xi1;
                vi = vi1;
                if (LE <= (eps/pow(2,4))) {
                stepi = stepi * 2;
                C2 += 1;
                }
                i++
            }
            if (LE > eps) {
                stepi = stepi / 2;
                C1 += 1;
                flag = 0;
            }
        }
        else {
            xi = xi1;
            vi = vi1;
        }
        if (flag) {
            table.append(xi, vi, v2i, LE, stepi, C1, C2, 0, 0);
        }
    }
    return(table);
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