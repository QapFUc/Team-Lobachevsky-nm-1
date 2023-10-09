#include "nmlib.hpp"

config utils::make_config(float x_min, float x_max, float x_0, float u_0, float step, uint N_max, bool LEC, float eps) {
    LOG_INFO_CLI("Making some config");
#if defined(DEBUG)
    LOG_DEBUG_CLI("Making config from python data", "Checking arguments");
#endif
    NM_ASSERT((x_max >= x_min), "invalid argument x_min > x_max");
    /// @todo write an asserts for other args

    config cfg {x_min, x_max, x_0, u_0, step, N_max, LEC, eps};
    LOG_INFO_CLI("Configuration done");
    return cfg;
}

namespace utils {
std::map<char*, std::function<resultTable(config)>> functions = {
    {"TEST_TASK_A", test_task_a},
    {"TEST_TASK_B", test_task_b},
    {"FIRST_TASK_A", first_task_a},
    {"FIRST_TASK_B", first_task_b},
    {"SECOND_TASK_A", second_task_a},
    {"SECOND_TASK_B", second_task_b}
};
}

