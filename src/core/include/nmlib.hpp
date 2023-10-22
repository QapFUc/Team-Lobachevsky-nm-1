#pragma once
#include <vector>
#include <functional>
#include <map>
#include <tuple>
#include <cmath>

#include "logger.hpp"

struct tableRow {
/// @todo write the constructor for init
// one row of table for nm output (see actual task)
    tableRow(double xi, double vi, double yi, double v2i, double y2i, double viv2i,
            double LE, double LEOLE, double hi, uint C1, uint C2, double ui,
            double uvi) : xi(xi), vi(vi), yi(yi), v2i(v2i), y2i(y2i), viv2i(viv2i), LEOLE(LEOLE), LE(LE), hi(hi), C1(C1), C2(C2), ui(ui), uvi(uvi) {}
    double xi;
    double vi;
    double v2i;
    double yi;
    double y2i;
    double viv2i;
    double LE;
    double LEOLE;
    double hi;
    uint C1;
    uint C2;
    double ui;
    double uvi;
    

    std::tuple<double, double, double, double, double, double, double, double, double, uint, uint, double, double> get_tuple() {
        return std::tuple<double, double, double, double, double, double, double, double, double, uint, uint, double, double> (xi, vi, yi, v2i, y2i, viv2i, LE, LEOLE,hi, C1, C2, ui, uvi);}


    friend std::ostream& operator<< (std::ostream& os, const tableRow& row) {
        os << "xi = " <<row.xi << ", vi = " << row.vi << ", yi = " << row.yi << ", y2i = " << row.y2i << ", v2i = " << row.v2i << ", viv2i = " << row.viv2i << ", LE = " << row.LE << ", hi = " << row.hi << ", C1 = " 
        << row.C1 << ", C2 = " << row.C2 << ", ui = " << row.ui << ", uvi = " << row.uvi;
        return os;
    }
};

typedef std::vector<tableRow> resultTable; // table for output

struct config {   
    config(double x_min, double x_max, double x_0, double u_0, double du_0, double step, uint N_max, bool LEC, double eps, double A, double B, double C) : x_min(x_min), x_max(x_max), x_0(x_0), u_0(u_0), du_0(du_0), step(step), N_max(N_max), LEC(LEC), eps(eps) {}
    config(std::tuple<double, double, double, double, double, double, uint, bool, double, double, double, double> tpl) : config(std::get<0>(tpl), std::get<1>(tpl), std::get<2>(tpl), std::get<3>(tpl), std::get<4>(tpl), std::get<5>(tpl), std::get<6>(tpl), std::get<7>(tpl), std::get<8>(tpl), std::get<9>(tpl), std::get<10>(tpl), std::get<11>(tpl)) {} 
    // Left and right limits for x variable
    double x_min; 
    double x_max;

    // initial point
    double x_0; 
    double u_0;
    double du_0;

    double step; // step
    uint N_max; // Maximum num for iterations

    bool LEC = 1 ; // Is there control for local error
    double eps = 0.f; // Epsilon for local error control

    double A;
    double B;
    double C;

    friend std::ostream& operator<< (std::ostream& os, const config& cfg) {
        os << "x_min=" << cfg.x_min << " x_max=" << cfg.x_max << " x_0=" << cfg.x_0 
            << " u_0=" << cfg.u_0 << " step=" << cfg.step << " N_max=" << cfg.N_max << " LEC=" << cfg.LEC << " eps=" << cfg.eps;
        return os;
    }
};


namespace utils {
/// @brief make config from python input
config make_config(const double& x_min, const double& x_max, const double& x_0, const double& u_0, const double& du_0, const double& step,  const uint& N_max, const bool& LEC, const double& eps, const double& A, const double& B, const double& C);

/// numerical method 
resultTable RK4(std::function<double(double,double)> rhs, const config& cfg);

/// @brief  RK4 for System Of two Equations 
resultTable RK4_SOE(std::function<double(double, double, double)> rhs1, std::function<double(double, double, double)> rhs2, const config& cfg);

/// step for method
inline double StepRK4(std::function<double(double,double)> rhs, const double& x, const double& u, const double& step);

/// step RK4 for System Of two Equations 
inline std::vector<double> StepRK4_SOE(std::function<double(double, double, double)> rhs1, std::function<double(double,double,double)> rhs2, const double& x, const double& u, const double& y, const double& step);

resultTable RK4_LS(std::function<double(double, double, double)> rhs, const config& cfg);

} // namespace utils

template <class Func, class Tuple, std::size_t... Is>
void apply_elemwise(Func&& f, const Tuple& tp, std::index_sequence<Is...>) {
    (f(std::get<Is>(tp)), ...);
}

static std::function<resultTable(std::function<double(double, double)>, config)> task_rk4 = utils::RK4;

static std::function<resultTable(std::function<double(double, double, double)>, config)> task_rk4_lseq = utils::RK4_LS;

static double test_rhs(double x, double v) {
    return  2 * v;
}

static double task1_rhs(double x, double v) {
    return (std::pow(x, 3) + 1)/(std::pow(x, 5) + 1);
}

static double task21_rhs(double x, double v, double y) {
    return (y * std::abs(y) + y + v);
}


std::function<double(const double&)> make_test_true_sol(const double& x_0, const double& u_0);


void calculate_global_error(resultTable& tbl, std::function<double(const double&)>&& f);

double find_max_LE(const resultTable& tbl);

double find_max_h(const resultTable& tbl);

double find_min_h(const resultTable& tbl);

double find_max_uvi(const resultTable& tbl);