#include "nmlib.hpp"
#include <cmath>

inline float utils::StepRK4(std::function<float(float,float)> rhs, const float& x, const float& u, const float& step) {

    LOG_INFO_CLI("Start RK4 step with following config", x, u, step);

    float new_u, k1, k2, k3, k4;
    k1 = rhs(x, u);
    k2 = rhs(x + step/2, u + step/2 * k1);
    k3 = rhs(x + step/2, u + step/2 * k2);
    k4 = rhs(x + step, u + step * k3);
    new_u = u + step/6 * (k1 + (2 * k2) + (2 * k3) + k4);
    return(new_u);
}

resultTable utils::RK4(std::function<float(float,float)> rhs, const config& cfg) {
    LOG_INFO_CLI("Start RK4 with following config", cfg);
    
    resultTable table;
    float xi, x_min, x_max, ui, stepi, N_max, eps;
    uint C1, C2;
    C1 = 0;
    C2 = 0;
    xi = cfg.x_0;
    x_min = cfg.x_min;
    x_max = cfg.x_max;
    ui = cfg.u_0;
    stepi = cfg.step;
    N_max = cfg.N_max;
    eps = cfg.eps;

    if (cfg.LEC) {
        int i = 0;
        float u1, u2;
        float viv2i, LocalError;
        while (xi >= x_min && xi <= x_max && i < N_max) {
            u1 = StepRK4(rhs, xi, ui, stepi);
            u2 = StepRK4(rhs, xi, ui, stepi/2);
            u2 = StepRK4(rhs, xi + stepi/2, u2, stepi/2);

            LocalError = (std::abs(u1 - u2))/(std::pow(2,4) - 1);
            if (LocalError < eps/std::pow(2,5)) {
                ui = u1;
                xi = xi + stepi;
                viv2i = std::abs(ui - u2);
                tableRow row(xi, ui, u2, viv2i, LocalError, stepi, C1, C2, 0.f, 0.f);
                table.push_back(row);
                stepi = stepi * 2;
                C2++;
                i++;
            } else if (LocalError >= eps/std::pow(2,5) && LocalError <= eps ) {
                ui = u1;
                xi = xi + stepi;
                viv2i = std::abs(ui - u2);
                tableRow row(xi, ui, u2, viv2i, LocalError, stepi, C1, C2, 0.f, 0.f);
                table.push_back(row);
                i++;
                
            } else if (LocalError > eps) {
                stepi = stepi / 2;
                C1++;
                i++;
            } else {
                LOG_ERROR_CLI(cfg);
            }
        }
        LOG_INFO_CLI("RK4 close", cfg);
        return(table);

    } else if (not(cfg.LEC)){
        int i = 0;
        while (xi >= x_min && xi <= x_max && i < N_max) {
            ui = StepRK4(rhs, xi, ui, stepi);
            xi = xi + stepi;
            i++;
            tableRow row(xi, ui, 0.f, 0.f, 0.f, stepi, 0.f, 0.f, 0.f, 0.f);
            table.push_back(row);
        }
        LOG_INFO_CLI("RK4 close", cfg);
        return(table);
    } else {
        LOG_INFO_CLI("Error in RK4", cfg);
    }
}

resultTable RK4_SOE(std::function<float(float, float, float)>, const config& cfg) {
    [](){};
}