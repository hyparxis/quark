cc_binary(
  name = "basic_test",
  srcs = ["basic_test.cpp"],
  deps = ["//quark:Body"]
)

cc_library(
  name = "common",
  hdrs = ["common.hpp"],
  deps = [
    "//quark/math:math_autodiff",
    "@googletest//:gtest_main"
  ]
)

cc_test(
  name = "BodyTest",
  srcs = ["BodyTest.cpp"],
  deps = [
    ":common",
    "//quark:Body",
    "//quark/math:math_autodiff",
  ]
)
