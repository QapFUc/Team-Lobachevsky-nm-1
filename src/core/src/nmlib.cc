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
