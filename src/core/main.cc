#include "include/nmlib.hpp"

int main() {
    LOG_INFO_CLI("startup");
    NM_ASSERT((1+1==3), "error");
    return 0;
}