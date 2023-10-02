#pragma once
#include <vector>

typedef unsigned long uint;

struct tableRow {
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

struct resultTable {
// output table (see actual task)
    std::vector<tableRow> rows;
};
struct config {   
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

/// @brief Namespace utils is needed to provide utilities that will be used in core functions
namespace utils {

/// @brief make config from python input
config make_config(float x_min, float x_max, float x_0, float u_0, float step, uint N_max, float eps);

/// @brief make output table for python
/// @todo implementation for this func
void make_out_from_table(resultTable result);
} // namespace utils

/// @brief  This is the core functions block. Each of them calculate one of examples from main task (see actual task) 
/// @todo write an implementation for each one
resultTable test_task_a(config cfg);
resultTable test_task_b(config cfg);

resultTable first_task_a(config cfg);
resultTable first_task_b(config cfg);

resultTable second_task_a(config cfg);
resultTable second_task_b(config cfg);
