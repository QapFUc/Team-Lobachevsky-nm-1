#pragma once
#include <vector>
#include <functional>
#include <map>

#include "logger.hpp"

struct tableRow {
/// @todo write the constructor for init
// one row of table for nm output (see actual task)
    tableRow(float xi, float vi, float v2i, float viv2i,
            float LE, float hi, uint C1, uint C2, float ui,
            float uvi) : xi(xi), vi(vi), v2i(v2i), viv2i(viv2i), LE(LE), hi(hi), C1(C1), C2(C2), ui(ui), uvi(uvi) {}
    float xi;
    float vi;
    float v2i;
    float viv2i;
    float LE;
    float hi;
    uint C1;
    uint C2;
    float ui;
    float uvi;

    friend std::ostream& operator<< (std::ostream& os, const tableRow& row) {
        os << "xi = " <<row.xi << ", vi = " << row.vi << ", v2i = " << row.v2i << ", viv2i = " << row.viv2i << ", LE = " << row.LE << ", hi = " << row.hi << ", C1 = " 
        << row.C1 << ", C2 = " << row.C2 << ", ui = " << row.ui << ", uvi = " << row.uvi;
        return os;
    }
};

typedef std::vector<tableRow> resultTable; // table for output

struct config {   
    config(float x_min, float x_max, float x_0, float u_0, float step, uint N_max, bool LEC, float eps) : x_min(x_min), x_max(x_max), x_0(x_0), u_0(u_0), step(step), N_max(N_max), LEC(LEC), eps(eps) {}
    // Left and right limits for x variable
    float x_min; 
    float x_max;

    // initial point
    float x_0; 
    float u_0;

    float step; // step
    uint N_max; // Maximum num for iterations

    bool LEC = 1; // Is there control for local error
    float eps = 0.f; // Epsilon for local error control

    friend std::ostream& operator<< (std::ostream& os, const config& cfg) {
        os << "x_min=" << cfg.x_min << " x_max=" << cfg.x_max << " x_0=" << cfg.x_0 
            << " u_0=" << cfg.u_0 << " step=" << cfg.step << " N_max=" << cfg.N_max << " LEC=" << cfg.LEC << " eps=" << cfg.eps;
        return os;
    }
};


/// @brief  This is the core functions block. Each of them calculate one of examples from main task (see actual task) 
/// @todo write an implementation for each one
resultTable test_task_a(config cfg);
resultTable test_task_b(config cfg);

resultTable first_task_a(config cfg);
resultTable first_task_b(config cfg);

resultTable second_task_a(config cfg);
resultTable second_task_b(config cfg);

/// @brief Namespace utils is needed to provide utilities that will be used in core functions
namespace utils {
/// @brief make config from python input
config make_config(float x_min, float x_max, float x_0, float u_0, float step, uint N_max, bool LEC, float eps);

/// numerical method 
resultTable RK4(std::function<float(float,float)> rhs, config cfg);

/// step for method
float StepRK4(std::function<float(float,float)> rhs, float x, float u, float step);
} // namespace utils
