#include "common.hpp"

#include "src/Body.ipp"

using namespace qrk;

template <typename T>
class BodyTest : public ::testing::Test {
};

TYPED_TEST_SUITE(BodyTest, AllTypes);

TYPED_TEST(BodyTest, ComputeSpatialInertiaFromAbsoluteRadiiGyrationTest)
{
  using T = TypeParam;
  Body<T> body(1.1, Vector3<T>(1.5, 1.2, 1.3), Vector3<T>(1.4, 2.0, 3.0));

  Matrix3<T> inertia;
  inertia << 1.4, 0, 0,
             0, 2.0, 0,
             0, 0, 3.0;

  Matrix6<T> reference_inertia;
  reference_inertia <<
    4.843, -1.98, -2.145, 0, -1.43, 1.32,
    -1.98, 6.334, -1.716, 1.43, 0, -1.65,
    -2.145, -1.716, 7.059, -1.32, 1.65, 0,
    0, 1.43, -1.32, 1.1, 0, 0,
    -1.43, 0, 1.65, 0, 1.1, 0,
    1.32, -1.65, 0, 0, 0, 1.1;

  SpatialInertia<T> body_rbi(body);

  ASSERT_LT((double)(reference_inertia - body_rbi.matrix()).norm(), test_tol);
  ASSERT_LT((double)(inertia - body.inertia).norm(), test_tol);
}
