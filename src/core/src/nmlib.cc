#include "nmlib.hpp"

config utils::make_config(float x_min, float x_max, float x_0, float u_0, float step, uint N_max, float eps) {
    config cfg = {.x_min = x_min, .x_max = x_max, .x_0 = x_0, .u_0 = u_0, .step = step, .N_max = N_max, .eps = eps};
    return cfg;
}
