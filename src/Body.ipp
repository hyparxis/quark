#pragma once
#include "Body.hpp"

#include "src/math/SpatialInertia.ipp"

namespace qrk {


namespace internal {
// Translate inertia matrix to new center
template <typename T>
inline Matrix3<T> parallel_axis(
  const Matrix3<T>& inertia, const Scalar<T>& mass, const Vector3<T>& com)
{
  auto com_cross = skew<T>(com);

  return inertia + mass * com_cross * com_cross.transpose();
}

} // namespace internal


// Constructors
template <typename T>
Body<T>::Body(const Scalar<T>& mass, const Vector3<T>& com,
              const Vector3<T>& gyration_radii)
  : mass(mass), com(com), inertia(Matrix3<T>::Zero())
{ inertia.diagonal() = gyration_radii; }

template <typename T>
Body<T>::Body(
  const Scalar<T>& mass, const Vector3<T>& com, const Matrix3<T> inertia)
    : mass(mass), com(com), inertia(inertia) {}


// Methods
template <typename T>
void Body<T>::join(const Isometry3<T>& transform, const Body<T>& other_body)
{
  // Nothing to do if we join a massles body to the current.
  if (other_body.mass == 0 && other_body.inerta == Matrix3<T>::Zero())
    return;

  Scalar<T> other_mass = other_body.mass;
  Scalar<T> new_mass = mass + other_mass;

  // assert(new_mass > 0, "Cannot joint two bodies with zero mass.");

  Vector3<T> other_com =
    transform.linear().transpose() * other_body.com + transform.translation();

  Vector3<T> new_com =
    (1 / new_mass) * (mass * com + other_mass * other_com);

  // We have to transform the inertia of other_body to the new COM. This
  // is done in 4 steps:
  //
  // 1. Transform the inertia from other origin to other COM
  // 2. Rotate the inertia so that it is aligned to the frame of this body
  // 3. Transform inertia of other_body to the origin of the frame of
  // this body
  // 4. Sum the two inertias
  // 5. Transform the summed inertia to the new COM

  SpatialInertia<T> other_rbi(other_body);
  SpatialInertia<T> this_rbi(*this);

  Matrix3<T> inertia_other = other_rbi.matrix().template block<3, 3>(0, 0);

  // 1. Transform the inertia from other origin to other CoM
  auto other_com_skew = skew<T>(other_body.com);
  auto inertia_other_com =
    internal::parallel_axis<T>(inertia_other, -other_mass, other_body.com);

  // 2. Rotate the inertia so that it is aligned to the frame of this body
  Matrix3<T> inertia_other_com_rotated =
    transform.linear().transpose() * inertia_other_com * transform.linear();

  // 3. Transform inertia of other_body to the origin of the frame of this
  // body
  auto inertia_other_com_rotated_this_origin =
    internal::parallel_axis<T>(inertia_other_com_rotated, other_mass, other_com);

  // 4. Sum the two inertias
  Matrix3<T> inertia_summed = this_rbi.matrix().template block<3, 3>(0, 0) +
                              inertia_other_com_rotated_this_origin;

  // 5. Transform the summed inertia to the new COM
  auto new_inertia =
    internal::parallel_axis<T>(inertia_summed, -new_mass, new_com);

  *this = Body(new_mass, new_com, new_inertia);
}


} // namespace qrk
