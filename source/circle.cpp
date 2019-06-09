#include "circle.hpp"
#include "vec2.hpp"
#include "vec2.cpp"
#include "mat2.hpp"
#include "mat2.cpp"

#include <cmath>
#include <iostream>
#include <string>

std::string Circle2::get_name() const {
  return name_;
}

float Circle2::get_radius() const {
  return radius_;
}

float Circle2::circumference() const {
  return 2 * 3.14159265359* radius_;
}

bool Circle2::is_inside(Vec2 v) const {
  v -= mid_;
  if (sqrt(pow(v.x_, 2) + pow(v.y_, 2)) > radius_) {
    return false;
  }
  else {
    return true;
  }
}

std::string Circle2::print()const {
  return "Name: " + name_ + "\n"
  + "Radius: " + std::to_string(radius_) + "\n"
  + "Mittelpunkt: {" + std::to_string(mid_.x_) + ", " + std::to_string(mid_.y_) + "}\n"
  + "Farbe: {" + std::to_string(color_.r_) + ", " + std::to_string(color_.g_) + ", " + std::to_string(color_.b_) + "}\n";
}

std::ostream& operator <<(std::ostream& os, const Circle2 const& c) {
  return os << c.print();
}

bool operator ==(Circle2 const& c1, Circle2 const& c2){
  if (c1.get_radius() == c2.get_radius()) {
    return true;
  }
  else {
    return false;
  }
}

bool operator <(Circle2 const& c1, Circle2 const& c2){
  if (c1.get_radius() < c2.get_radius()) {
    return true;
  }
  else {
    return false;
  }
}

bool operator >(Circle2 const& c1, Circle2 const& c2){
  if (c1.get_radius() > c2.get_radius()) {
    return true;
  }
  else {
    return false;
  }
}
