#include "mat2.hpp"

#include <math.h>

#include <iostream>

Mat2& Mat2::operator *=(Mat2 const& m) {
  float h_00 = e_00;
  float h_10 = e_10;
  float h_01 = e_01;
  float h_11 = e_11;

  e_00 = h_00 * m.e_00 + h_10 * m.e_01;
  e_10 = h_00 * m.e_10 + h_10 * m.e_11;
  e_01 = h_01 * m.e_00 + h_11 * m.e_01;
  e_11 = h_01 * m.e_10 + h_11 * m.e_11;
  return *this;
}

float Mat2::det() const {
  return e_00 * e_11 - e_10 * e_01;
}

Mat2 operator *(Mat2 const& m1, Mat2 const& m2) {
  Mat2 n;
  n *= m1;
  n *= m2;
  return n;
}

Vec2 operator *(Mat2 const& m, Vec2 const& v) {
  Vec2 w;
  w.x_ = m.e_00 * v.x_ + m.e_10 * v.y_;
  w.y_ = m.e_01 * v.x_ + m.e_11 * v.y_;
  return w;
}

Vec2 operator *(Vec2 const& v, Mat2 const& m){
  Vec2 w = v;
  std::cout << "vector is transposed (2x1 --> 1x2), result will be transposed to\n";
  w.x_ = v.x_ * m.e_00 + v.y_ * m.e_01;
  w.y_ = v.x_ * m.e_10 + v.y_ * m.e_11;
  return w;
}

Mat2 inverse(Mat2 const& m){
  Mat2 n;
  float s = m.e_00 * m.e_10 - m.e_01 * m.e_11;
  n.e_00 = (m.e_11)/s;
  n.e_10 = (-m.e_10)/s;
  n.e_01 = (-m.e_01)/s;
  n.e_11 = (m.e_00)/s;
  return n;
}

Mat2 transpose(Mat2 const& m){
  Mat2 n = m;
  n.e_10 = m.e_01;
  n.e_01 = m.e_10;
  return n;
}

Mat2 make_rotation_mat2(float phi){
  Mat2 m{ cos(phi),-sin(phi),sin(phi),cos(phi) };
  return m;
}
