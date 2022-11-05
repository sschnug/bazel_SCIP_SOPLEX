load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")

cmake(
    name = "soplex",
    lib_source = "@soplex//:all_srcs",
    out_static_libs = ["libsoplex.a"],
    generate_args = ["-DZLIB=Off", "-DGMP=Off", "-DBOOST=Off"],
    visibility = ["//visibility:public"]
)