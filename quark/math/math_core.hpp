#pragma once
#include <Eigen/Dense>
#include <Eigen/Geometry>


namespace qrk {

// Scalar type
template <typename T>
using Scalar = T;


// Vector types
template <typename T>
using Vector2 = Eigen::Vector<T, 2>;

template <typename T>
using Vector3 = Eigen::Vector<T, 3>;

template <typename T>
using Vector4 = Eigen::Vector<T, 4>;

template <typename T>
using Vector6 = Eigen::Vector<T, 6>;

template <typename T>
using VectorX = Eigen::Vector<T, Eigen::Dynamic>;


// Matrix types
template <typename T>
using Matrix2 = Eigen::Matrix<T, 2, 2>;

template <typename T>
using Matrix3 = Eigen::Matrix<T, 3, 3>;

template <typename T>
using Matrix4 = Eigen::Matrix<T, 4, 4>;

template <typename T>
using Matrix6 = Eigen::Matrix<T, 6, 6>;

template <typename T>
using Matrix43 = Eigen::Matrix<T, 4, 3>;

template <typename T>
using Matrix63 = Eigen::Matrix<T, 6, 3>;

template <typename T>
using MatrixX = Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>;


// Transforms
template <typename T>
using Isometry3 = Eigen::Transform<T, 3, Eigen::Isometry>;


// Functions
template <typename T>
inline Matrix3<T> skew(const Vector3<T>& v)
{
  auto x = v.x();
  auto y = v.y();
  auto z = v.z();

  Matrix3<T> out;
  out << 0, -z, y,
         z,  0, -x,
         -y, x, 0;

  return out;
}

} // namespace qrk
