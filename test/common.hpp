#pragma once
#include "quark/math/math_autodiff.hpp"

#include "gtest/gtest.h"

using AllTypes = testing::Types<double, autodiff::var>;
using NumericTypes = testing::Types<double>;
using ADTypes = testing::Types<autodiff::var>;

constexpr double test_tol = 1e-14;
