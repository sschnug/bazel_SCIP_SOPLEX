load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")

cmake(
    name = "soplex",
    lib_source = "@soplex//:all_srcs",
    # out_static_libs = ["libsoplex.a"],
    out_static_libs = 
      select({
          "@bazel_tools//src/conditions:windows": ["libsoplex.lib"],
          "//conditions:default": ["libsoplex.a"],
        }),
    generate_args = ["-DZLIB=Off",
                     "-DGMP=Off",
                     "-DBOOST=Off"],
    visibility = ["//visibility:public"]
)

cmake(
    name = "scip",
    lib_source = "@scip//:all_srcs",
    # out_static_libs = ["libscip.a"],
    out_static_libs =
      select({
          "@bazel_tools//src/conditions:windows": ["libscip.lib"],
          "//conditions:default": ["libscip.a"],
        }),
    generate_args = ["-DSHARED=Off",
                     "-DZLIB=Off",
                     "-DREADLINE=Off",
                     "-DGMP=Off",
                     "-DBOOST=Off",
                     "-DPAPILO=Off",
                     "-DZIMPL=Off",
                     "-DAMPL=Off",
                     "-DIPOPT=Off",
                     "-DSYM=none"],
    deps = [
      ":soplex",
    ],
    visibility = ["//visibility:public"]
)