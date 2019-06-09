#include "vec2.hpp"

#include <iostream>

Vec2& Vec2::operator +=(Vec2 const& v) {
  x_ += v.x_;
  y_ += v.y_;
  return *this;
}

Vec2& Vec2::operator -=(Vec2 const& v) {
  x_ -= v.x_;
  y_ -= v.y_;
  return *this;
}

Vec2& Vec2::operator *=(float s){
  x_ *= s;
  y_ *= s;
  return *this;
}

Vec2& Vec2::operator /=(float s) {
  if (s == 0) {
    std::cout << "Don't divide by 0! Dividing float ignored.\n";
  }
  else {
    x_ /= s;
    y_ /= s;
  }
  return *this;
}

Vec2 operator +(Vec2 const& u, Vec2 const& v) {
  Vec2 w = u;
  w += v;
  return w;
}

Vec2 operator -(Vec2 const& u, Vec2 const& v) {
  Vec2 w = u;
  w -= v;
  return w;
}

Vec2 operator *(Vec2 const& v, float s) {
  Vec2 w = v;
  w *= s;
  return w;
}

Vec2 operator /(Vec2 const& v, float s) {
  Vec2 w = v;
  if (s == 0) {
    std::cout << "Don't divide by 0! Dividing float ignored.\n";
  }
  else {
    w /= s;
  }
  return w;
}

Vec2 operator *(float s, Vec2 const& v) {
  Vec2 w = v;
  w *= s;
  return w;
}
