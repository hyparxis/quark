#pragma once

#include "src/math/math_core.hpp"

namespace qrk {

template <typename T>
struct Body {
  Body() = default;
  ~Body() = default;

  // Constructs a body from mass, center of mass (in body coordinates)
  // and radii of gyration
  Body(const Scalar<T> &mass, const Vector3<T> &com,
       const Vector3<T> &gyration_radii);

  // Constructs a body from mass, center of mass, and a 3x3 inertia matrix
  Body(const Scalar<T>& mass, const Vector3<T>& com, const Matrix3<T> inertia);

  // Joins inertial parameters of two bodies to create a composite
  // body that has inertial properties as if the two bodies were joined by a
  // fixed joint.
  // NOTE: both bodies have to have their inertial parameters expressed in
  // the same orientation. The frame transformation is from the origin of the
  // original body to the origin of the added body
  void join(const Isometry3<T>& transform, const Body<T>& other_body);

  // The mass of the body
  Scalar<T> mass{};
  // The position of the center of mass in body coordinates
  Vector3<T> com{};
  // The 3x3 inertia matrix at the center of mass
  Matrix3<T> inertia{};

  bool is_virtual{};
};


} // namespace qrk
