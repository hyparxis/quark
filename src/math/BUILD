package(default_visibility = ["//visibility:public"])

cc_library(
  name = "math_core",
  hdrs = ["math_core.hpp"],
  deps = ["@eigen"]
)

cc_library(
  name = "math_autodiff",
  hdrs = ["math_autodiff.hpp"],
  deps = ["@autodiff"]
)

cc_library(
  name = "SpatialInertia",
  hdrs = ["SpatialInertia.hpp", "SpatialInertia.ipp"],
  deps = [":math_core"]
)
