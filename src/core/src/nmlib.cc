#include "nmlib.hpp"

config utils::make_config(const float& x_min, const float& x_max, const float& x_0, const float& u_0, const float& du_0, const float& step,  const uint& N_max, const bool& LEC, const float& eps, const float& A, const float& B, const float& C) {
    LOG_INFO_CLI("Making some config");
#if defined(DEBUG)
    LOG_DEBUG_CLI("Making config from python data", "Checking arguments");
#endif
    NM_ASSERT((x_max >= x_min), "invalid argument x_min > x_max");
    /// @todo write an asserts for other args

    config cfg {x_min, x_max, x_0, u_0, du_0, step, N_max, LEC, eps, A, B, C};
    LOG_INFO_CLI("Configuration done");
    return cfg;
}

void calculate_global_error(resultTable& tbl, std::function<float(const float&)>&& f) {
    for (auto& row : tbl) {
        row.ui = f(row.xi);
        row.uvi = std::abs(row.vi - row.ui); 
    }
}

float find_max_LE(const resultTable& tbl) {
    float max = 0.f;

    for (auto& row : tbl) {
        float tmp = std::abs(row.LE);
        if (tmp > max) max = tmp;
    }

    return max;
}

float find_max_h(const resultTable& tbl) {
    float max = 0.f;

    for (auto& row : tbl) {
        if (row.hi > max) max = row.hi;
    }

    return max;
}

float find_min_h(const resultTable& tbl) {
    float min = tbl.at(0).hi;

    for (auto& row : tbl) {
        if (row.hi < min) min = row.hi;
    }

    return min;
}

float find_max_uvi(const resultTable& tbl) {
    float max = 0.f;

    for (auto& row : tbl) {
        if (row.uvi > max) max = row.uvi;
    }

    return max;
}