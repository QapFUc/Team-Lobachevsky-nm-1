#pragma once
#include <vector>
#include <functional>
#include <map>
#include <tuple>

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

    float Get_xi() {
        return(xi);
    }
    float Get_vi() {
        return(vi);
    }
    float Get_v2i() {
        return(v2i);
    }
    float Get_viv2i() {
        return(viv2i);
    }
    float Get_LE() {
        return(LE);
    }
    float Get_hi() {
        return(hi);
    }
    float Get_C1() {
        return(C1);
    }
    float Get_C2() {
        return(C2);
    }
    float Get_ui(){
        return(ui);
    }
    float Get_uvi() {
        return(uvi);
    }




    friend std::ostream& operator<< (std::ostream& os, const tableRow& row) {
        os << "xi = " <<row.xi << ", vi = " << row.vi << ", v2i = " << row.v2i << ", viv2i = " << row.viv2i << ", LE = " << row.LE << ", hi = " << row.hi << ", C1 = " 
        << row.C1 << ", C2 = " << row.C2 << ", ui = " << row.ui << ", uvi = " << row.uvi;
        return os;
    }
};

typedef std::vector<tableRow> resultTable; // table for output

struct config {   
    config(float x_min, float x_max, float x_0, float u_0, float step, uint N_max, bool LEC, float eps) : x_min(x_min), x_max(x_max), x_0(x_0), u_0(u_0), step(step), N_max(N_max), LEC(LEC), eps(eps) {}
    config(std::tuple<float, float, float, float, float, uint, bool, float> tpl) : config(std::get<0>(tpl), std::get<1>(tpl), std::get<2>(tpl), std::get<3>(tpl), std::get<4>(tpl), std::get<5>(tpl), std::get<6>(tpl), std::get<7>(tpl)) {} 
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

struct task {
    config cfg;
    std::function<float(float, float)> rhs;
    resultTable result;
public:
    task(std::function<float(float,float)> _rhs, config _cfg) : cfg(_cfg), rhs(_rhs) {}
    resultTable operator()() {
        result = utils::RK4(rhs, cfg);
        return result;
    }
};

namespace utils {
/// @brief make config from python input
config make_config(float x_min, float x_max, float x_0, float u_0, float step, uint N_max, bool LEC, float eps);

/// numerical method 
resultTable RK4(std::function<float(float,float)> rhs, config cfg);

/// step for method
float StepRK4(std::function<float(float,float)> rhs, float x, float u, float step);
} // namespace utils
