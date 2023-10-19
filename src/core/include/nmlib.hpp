#pragma once
#include <vector>
#include <functional>
#include <map>
#include <tuple>

#include "logger.hpp"

struct tableRow {
/// @todo write the constructor for init
// one row of table for nm output (see actual task)
    tableRow(float xi, float vi, float yi, float v2i, float y2i, float viv2i,
            float LE, float hi, uint C1, uint C2, float ui,
            float uvi) : xi(xi), vi(vi), yi(yi), v2i(v2i), y2i(y2i), viv2i(viv2i), LE(LE), hi(hi), C1(C1), C2(C2), ui(ui), uvi(uvi) {}
    float xi;
    float vi;
    float v2i;
    float yi;
    float y2i;
    float viv2i;
    float LE;
    float hi;
    uint C1;
    uint C2;
    float ui;
    float uvi;

    std::tuple<float, float, float, float, float, float, float, uint, uint, float, float> get_tuple() {
        return std::tuple<float, float, float, float, float, float, float, uint, uint, float, float> (xi, vi, yi, v2i, viv2i, LE, hi, C1, C2, ui, uvi);}


    friend std::ostream& operator<< (std::ostream& os, const tableRow& row) {
        os << "xi = " <<row.xi << ", vi = " << row.vi << ", yi = " << row.yi << ", y2i = " << row.y2i << ", v2i = " << row.v2i << ", viv2i = " << row.viv2i << ", LE = " << row.LE << ", hi = " << row.hi << ", C1 = " 
        << row.C1 << ", C2 = " << row.C2 << ", ui = " << row.ui << ", uvi = " << row.uvi;
        return os;
    }
};

typedef std::vector<tableRow> resultTable; // table for output

struct config {   
    config(float x_min, float x_max, float x_0, float u_0, float du_0, float step, uint N_max, bool LEC, float eps) : x_min(x_min), x_max(x_max), x_0(x_0), u_0(u_0), du_0(du_0), step(step), N_max(N_max), LEC(LEC), eps(eps) {}
    config(std::tuple<float, float, float, float, float, float, uint, bool, float> tpl) : config(std::get<0>(tpl), std::get<1>(tpl), std::get<2>(tpl), std::get<3>(tpl), std::get<4>(tpl), std::get<5>(tpl), std::get<6>(tpl), std::get<7>(tpl), std::get<8>(tpl)) {} 
    // Left and right limits for x variable
    float x_min; 
    float x_max;

    // initial point
    float x_0; 
    float u_0;
    float du_0;

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


namespace utils {
/// @brief make config from python input
config make_config(const float& x_min, const float& x_max, const float& x_0, const float& u_0, const float& du_0, const float& step,  const uint& N_max, const bool& LEC, const float& eps);

/// numerical method 
resultTable RK4(std::function<float(float,float)> rhs, const config& cfg);

/// @brief  RK4 for System Of two Equations 
resultTable RK4_SOE(std::function<float(float, float, float)> rhs1, std::function<float(float, float, float)> rhs2, const config& cfg);

/// step for method
inline float StepRK4(std::function<float(float,float)> rhs, const float& x, const float& u, const float& step);

/// step RK4 for System Of two Equations 
inline float StepRK4_SOE(std::function<float(float,float,float)> rhs1, std::function<float(float,float,float)> rhs2, const float& x, const float& u, const float& y, const float& step);

resultTable RK4_LS(std::function<float(float,float)> rhs, const config& cfg);

} // namespace utils

template<class Return, class... Args>
class task {
    config cfg;
    std::function<Return(Args...)> rhs;
    std::function<resultTable(std::function<Return(Args...)>, config)> method;
    resultTable result;
public:
    task(std::function<Return(Args...)> _rhs, const config& _cfg, std::function<resultTable(std::function<Return(Args...)>, config)> _method) : cfg(_cfg), rhs(_rhs), method(_method) {}
    resultTable operator()() {
        result = method(rhs, cfg);
        return result;
    }
};