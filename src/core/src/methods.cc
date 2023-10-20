#include "nmlib.hpp"

#include <cmath>
#include <algorithm>

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
        while (xi > x_min && xi+stepi < x_max && i < N_max) {
            u1 = StepRK4(rhs, xi, ui, stepi);
            u2 = StepRK4(rhs, xi, ui, stepi/2);
            u2 = StepRK4(rhs, xi + stepi/2, u2, stepi/2);

            LocalError = (std::abs(u1 - u2))/(std::pow(2,4) - 1);
            if (LocalError < eps/std::pow(2,5)) {
                ui = u1;
                xi = xi + stepi;
                viv2i = std::abs(ui - u2);
                tableRow row(xi, ui, 0.f, u2, viv2i, 0.f,LocalError, stepi, C1, C2, 0.f, 0.f);
                table.push_back(row);
                stepi = stepi * 2;
                C2++;
                i++;
            } else if (LocalError >= eps/std::pow(2,5) && LocalError <= eps ) {
                ui = u1;
                xi = xi + stepi;
                viv2i = std::abs(ui - u2);
                tableRow row(xi, ui, 0.f, u2, 0.f,viv2i, LocalError, stepi, C1, C2, 0.f, 0.f);
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
        while (xi > x_min && xi+stepi < x_max && i < N_max) {
            ui = StepRK4(rhs, xi, ui, stepi);
            xi = xi + stepi;
            i++;
            tableRow row(xi, ui, 0.f, 0.f,0.f,0.f, 0.f, stepi, 0.f, 0.f, 0.f, 0.f);
            table.push_back(row);
        }
        LOG_INFO_CLI("RK4 close", cfg);
        return(table);
    } else {
        LOG_INFO_CLI("Error in RK4", cfg);
    }
}

inline std::vector<float> utils::StepRK4_SOE(std::function<float(float,float,float)> rhs1,std::function<float(float,float,float)> rhs2, const float& x, const float& u, const float& y, const float& step) {

    LOG_DEBUG_CLI("Start StepRK4_SOE step with following config", x, u, step);

    float new_u, new_y, k11, k12, k21, k22, k31, k32, k41, k42;
    std::vector<float> res;
    k11 = rhs1(x, u, y);
    k12 = rhs2(x, u, y);
    k21 = rhs1(x + step/2, u + step/2 * k11, y + step/2 * k12);
    k22 = rhs2(x + step/2, u + step/2 * k11, y + step/2 * k12);
    k31 = rhs1(x + step/2, u + step/2 * k21, y + step/2 * k22);
    k32 = rhs2(x + step/2, u + step/2 * k21, y + step/2 * k22);
    k41 = rhs1(x + step, u + step * k31, y + step * k32);
    k42 = rhs2(x + step, u + step * k31, y + step * k32);
    new_u = u + step/6 * (k11 + (2 * k21) + (2 * k31) + k41);
    new_y = y + step/6 * (k12 + (2 * k22) + (2 * k32) + k42);
    res.push_back(new_u);
    res.push_back(new_y);
    return(res);
}

resultTable utils::RK4_SOE(std::function<float(float, float, float)> rhs1, std::function<float(float, float, float)> rhs2, const config& cfg) {
    LOG_INFO_CLI("Start RK4_SOE with following config", cfg);
    resultTable table;
    float xi, x_min, x_max, ui, yi, stepi, N_max, eps;
    uint C1, C2;
    std::vector<float> tmp1, tmp2;
    C1 = 0;
    C2 = 0;
    xi = cfg.x_0;
    x_min = cfg.x_min;
    x_max = cfg.x_max;
    float a = cfg.A;
    float b = cfg.B;
    float c = cfg.C;
    ui = cfg.u_0;
    yi = cfg.du_0;
    stepi = cfg.step;
    N_max = cfg.N_max;
    eps = cfg.eps;
    if (cfg.LEC) {
        float LocalError, viv2i;
        int i = 0;
        while (xi > x_min && xi+stepi < x_max && i < N_max) {
            //LOG_DEBUG_CLI("Start RK4_SOE with localstecpcontrol", cfg);
            tmp1 = StepRK4_SOE(rhs1, rhs2, xi, ui, yi, stepi);
            tmp2 = StepRK4_SOE(rhs1, rhs2, xi, ui, yi, stepi/2);
            tmp2 = StepRK4_SOE(rhs1, rhs2, xi, tmp2.at(0), tmp2.at(1), stepi/2);
            LocalError = std::max(std::abs(tmp1.at(0) - tmp2.at(0)), std::abs(tmp1.at(1)-tmp2.at(1))) / 15;
            //LOG_DEBUG_CLI("tmp generated", cfg);
            if (LocalError < eps/std::pow(2,5)) {
                //LOG_DEBUG_CLI("try LocalErroe < lec", cfg);
                yi = tmp1.at(1);
                ui = tmp1.at(0);
                xi = xi + stepi;
                viv2i = std::abs(ui - tmp2.at(0));
                //LOG_DEBUG_CLI("viv2i generated", cfg);
                tableRow row(xi, ui, yi, tmp1.at(0), tmp2.at(1), viv2i, LocalError, stepi, C1, C2, 0.f, 0.f);
                //LOG_DEBUG_CLI("try push_back", cfg);
                table.push_back(row);
                //LOG_DEBUG_CLI("push_back done", cfg);
                stepi = stepi * 2;
                C2++;
                i++;
                //LOG_DEBUG_CLI("LocalErroe < lec done", cfg);
            } else if (LocalError >= eps/std::pow(2,5) && LocalError <= eps ) {
                //LOG_DEBUG_CLI("LocalErroe >= lec", cfg);
                yi = tmp1.at(1);
                ui = tmp1.at(0);
                xi = xi + stepi;
                viv2i = std::abs(ui - tmp2.at(0));
                tableRow row(xi, ui, yi, tmp2.at(0), tmp2.at(1), viv2i, LocalError, stepi, C1, C2, 0.f, 0.f);
                table.push_back(row);
                i++; 
            } else if (LocalError > eps) {
                LOG_DEBUG_CLI("LocalErroe > lec*", cfg);
                stepi = stepi / 2;
                C1++;
                i++;
            } else {
                LOG_ERROR_CLI(cfg);
            }
        }
        return(table);
    } else if (not(cfg.LEC)){
        //LOG_DEBUG_CLI("Start RK4_SOE without localstecpcontrol", cfg);
        int i = 0;
        while (xi > x_min && xi+stepi < x_max && i < N_max) {
            tmp1 = StepRK4_SOE(rhs1, rhs2, xi, ui, yi, stepi);
            yi = tmp1.at(1);
            ui = tmp1.at(0);
            xi = xi + stepi;
            i++;
            tableRow row(xi, ui, yi, 0.f, 0.f, 0.f, 0.f, stepi, 0.f, 0.f, 0.f, 0.f);
            table.push_back(row);
        }
        return(table);
    } else {
        LOG_INFO_CLI("Error in RK4", cfg);
    }
}

resultTable utils::RK4_LS(std::function<float(float, float, float)> rhs, const config& cfg) {
    return utils::RK4_SOE(rhs, [&](float x, float u, float du){ return u; }, cfg);
}