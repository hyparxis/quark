cc_binary(
  name = "basic_test",
  srcs = ["basic_test.cpp"],
  deps = ["//src:Body"]
)

cc_library(
  name = "common",
  hdrs = ["common.hpp"],
  deps = [
    "//src/math:math_autodiff",
    "@googletest//:gtest_main"
  ]
)

cc_test(
  name = "BodyTest",
  srcs = ["BodyTest.cpp"],
  deps = [
    ":common",
    "//src:Body",
    "//src/math:math_autodiff",
  ]
)
