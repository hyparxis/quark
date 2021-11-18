#pragma once
#include "math_core.hpp"

#include "quark/Body.hpp"

namespace qrk {

template <typename T>
struct SpatialInertia {
  SpatialInertia() = default;

  SpatialInertia(const Scalar<T>& m, const Vector3<T>& h, const Scalar<T>& Ixx,
                 const Scalar<T>& Iyx, const Scalar<T>& Iyy,
                 const Scalar<T>& Izx, const Scalar<T>& Izy,
                 const Scalar<T>& Izz);

  SpatialInertia(const Scalar<T>& mass, const Vector3<T>& com,
                 const Matrix3<T>& inertia);

  SpatialInertia(const Body<T>& body);

  Matrix6<T> matrix() const;

  // Mass
  Scalar<T> m;
  // Coordinates of the center of mass
  Vector3<T> h;
  // Inertia expressed at the origin
  Scalar<T> Ixx, Iyx, Iyy, Izx, Izy, Izz;
};


} // namespace qrk
