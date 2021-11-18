load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# Eigen
http_archive(
  name = "eigen",
  url = "https://gitlab.com/libeigen/eigen/-/archive/3.4/eigen-3.4.tar.gz",
  strip_prefix = "eigen-3.4",
  sha256 = "a13c6f0b3753a654e7be0d1a3e4a9e9e4e319bcd11079bc37c3f00270f82f37e",
  build_file = "//third_party:eigen.BUILD",
)

# Autodiff
http_archive(
  name = "autodiff",
  url = "https://github.com/autodiff/autodiff/archive/v0.5.10.zip",
  strip_prefix = "autodiff-0.5.10",
  sha256 = "6bc7425a9f5f2236ce30320279a55feaf9824112afe704bc15aa945cb20ae7de",
  build_file = "//third_party:autodiff.BUILD",
)

# Googletest
http_archive(
    name = "googletest",
    sha256 = "9dc9157a9a1551ec7a7e43daea9a694a0bb5fb8bec81235d8a1e6ef64c716dcb",
    strip_prefix = "googletest-release-1.10.0",
    urls = [
        "https://github.com/google/googletest/archive/release-1.10.0.tar.gz",
    ],
    build_file = "//third_party:googletest.BUILD",
)
