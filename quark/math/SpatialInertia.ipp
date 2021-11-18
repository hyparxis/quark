#pragma once
#include "SpatialInertia.hpp"

#include "quark/Body.ipp"

namespace qrk {


// Constructors
template <typename T>
SpatialInertia<T>::SpatialInertia(
  const Scalar<T>& m, const Vector3<T>& h,
  const Scalar<T>& Ixx, const Scalar<T>& Iyx, const Scalar<T>& Iyy,
  const Scalar<T>& Izx, const Scalar<T>& Izy, const Scalar<T>& Izz)
  : m(m), h(h), Ixx(Ixx), Iyx(Iyx), Iyy(Iyy), Izx(Izx), Izy(Izy), Izz(Izz) {}

template <typename T>
SpatialInertia<T>::SpatialInertia(const Scalar<T>& mass, const Vector3<T>& com,
                                  const Matrix3<T>& inertia)
{
  SpatialInertia<T> out;
  out.m = mass;
  out.h = com;

  out.Ixx = inertia(0, 0);
  out.Iyx = inertia(1, 0);
  out.Iyy = inertia(1, 1);
  out.Izx = inertia(2, 0);
  out.Izy = inertia(2, 1);
  out.Izz = inertia(2, 2);
}

template <typename T>
SpatialInertia<T>::SpatialInertia(const Body<T>& body)
{
  m = body.mass;
  h = body.com * body.mass;

  auto skew_com = skew<T>(body.com);
  Matrix3<T> I = body.inertia + skew_com * skew_com.transpose() * body.mass;

  Ixx = I(0, 0);
  Iyx = I(1, 0);
  Iyy = I(1, 1);
  Izx = I(2, 0);
  Izy = I(2, 1);
  Izz = I(2, 2);
}


// Methods
template <typename T>
Matrix6<T> SpatialInertia<T>::matrix() const
{
  Matrix6<T> M;
  M(0, 0) = Ixx; M(0, 1) = Iyx; M(0, 2) = Izx;
  M(1, 0) = Iyx; M(1, 1) = Iyy; M(1, 2) = Izy;
  M(2, 0) = Izx; M(2, 1) = Izy; M(2, 2) = Izz;

  M.template block<3, 3>(0, 3) = skew<T>(h);
  M.template block<3, 3>(3, 0) = -skew<T>(h);
  M.template block<3, 3>(3, 3) = Matrix3<T>::Identity() * m;

  return M;
}


} // namespace qrk
