#pragma once
#include <vector>
#include <functional>
#include <map>

#include "logger.hpp"

struct tableRow {
/// @todo write the constructor for init
// one row of table for nm output (see actual task)
    float xi;
    float vi;
    float v2i;
    float viv2i;
    float localError;
    uint hi;
    uint C1;
    uint C2;
    float ui;
    float uvi;
};

typedef std::vector<tableRow> resultTable; // table for output

struct config {   
    config(float x_min, float x_max, float x_0, float u_0, float step, uint N_max, float eps) : x_min(x_min), x_max(x_max), x_0(x_0), u_0(u_0), step(step), N_max(N_max), eps(eps) {}
    // Left and right limits for x variable
    float x_min; 
    float x_max;

    // initial point
    float x_0; 
    float u_0;

    float step; // step
    uint N_max; // Maximum num for iterations

    float eps = 0.f; // Epsilon for local error control
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
config make_config(float x_min, float x_max, float x_0, float u_0, float step, uint N_max, float eps);
} // namespace utils

/// @brief  Function that will be called from python. 
extern "C" tableRow* run_from_python(char *func_name,    
                                     float x_min, 
                                     float x_max,
                                     float x_0, 
                                     float u_0,
                                     float step,
                                     uint N_max,
                                     float eps,
                                     uint *rowsCount); 
// uint -> c_ulong in python
// float -> c_float