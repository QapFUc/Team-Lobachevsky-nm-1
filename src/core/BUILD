cc_library(
    name = "nmlib",
    srcs = ["src/nmlib.cc"],
    includes = ["include/"],
    hdrs = ["include/nmlib.hpp"],
    visibility = ["//visibility:public"]
)

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = ["nmlib"]
)