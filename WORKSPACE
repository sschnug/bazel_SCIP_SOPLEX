workspace(name = "bazel_minimal_scip")

load("@bazel_tools//tools/build_defs/repo:git.bzl", "new_git_repository")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "rules_foreign_cc",
    sha256 = "2a4d07cd64b0719b39a7c12218a3e507672b82a97b98c6a89d38565894cf7c51",
    strip_prefix = "rules_foreign_cc-0.9.0",
    url = "https://github.com/bazelbuild/rules_foreign_cc/archive/0.9.0.tar.gz",
)

load("@rules_foreign_cc//foreign_cc:repositories.bzl", "rules_foreign_cc_dependencies")

rules_foreign_cc_dependencies()

_SCIP_ALL_CONTENT = """\
filegroup(
    name = "all_srcs",
    srcs = glob(["**"]),
    visibility = ["//visibility:public"],
)
"""

new_git_repository(
    name = "scip",
    build_file_content = _SCIP_ALL_CONTENT,
    commit = "674cd55c4c609cd6aa2f49037c70195c2f8d46af",
    remote = "https://github.com/scipopt/scip.git",
    shallow_since = "1667609838 +0100"
)

_SOPLEX_ALL_CONTENT = """\
filegroup(
    name = "all_srcs",
    srcs = glob(["**"]),
    visibility = ["//visibility:public"],
)
"""

new_git_repository(
    name = "soplex",
    build_file_content = _SOPLEX_ALL_CONTENT,
    commit = "98e1651cc52e21212d88d01983bd8b77bb99c843",
    remote = "https://github.com/scipopt/soplex.git",
    shallow_since = "1667609884 +0100"
)