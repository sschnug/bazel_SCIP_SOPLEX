cc_binary(
    name = "example_scip",
    srcs = ["example_scip.cc"],
    deps = [
      ":queens",
    ]
)

cc_library(
    name = "queens",
    srcs = ["queens.cc"],
    hdrs = ["queens.h", "scip_exception.h"],
    deps = [
      "//:scip"
    ]
)
