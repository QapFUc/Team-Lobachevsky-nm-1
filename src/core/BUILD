cc_library(
    name = "logger",
    hdrs = ["include/logger.hpp"],
    includes = ["include"],
    visibility = ["//visibility:public"]
)

cc_library(
    name = "nmlib",
    srcs = ["src/nmlib.cc",
            "src/methods.cc"],
    hdrs = ["include/nmlib.hpp"],
    includes = ["include"],
    deps = ["logger"],
    visibility = ["//visibility:public"]
)

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = ["nmlib",
            "logger"],
    defines = ["DEBUG"]
)