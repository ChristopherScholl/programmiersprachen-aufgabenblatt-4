#include "rectangle.hpp"

//Rectangle2(Vec2 const& min, Vec2 const& max, Color const& color) :min_(min), max_(max), color_(color) {}
float Rectangle2::circumference() const {
  return 2 * (max_.x_ - min_.x_ + max_.y_ + min_.y_);
}

bool Rectangle2::is_inside(Vec2 v) const{
  if (v.x_ > min_.x_ || v.x_ < max_.x_ || v.y_ < min_.y_ || v.y_ > max_.y_) {
    return false;
  }
  else {
    return true;
  }
}

void Rectangle2::draw(Window const& win)const {
  win.draw_line(max_.x_, max_.y_, max_.x_, min_.y_, color_.r_, color_.g_, color_.b_, 1.0);
  win.draw_line(max_.x_, max_.y_, min_.x_, max_.y_, color_.r_, color_.g_, color_.b_, 1.0);
  win.draw_line(min_.x_, min_.y_, max_.x_, min_.y_, color_.r_, color_.g_, color_.b_, 1.0);
  win.draw_line(min_.x_, min_.y_, min_.x_, max_.y_, color_.r_, color_.g_, color_.b_, 1.0);
}

void Rectangle2::draw(Window const& win, float t)const {
  win.draw_line(max_.x_, max_.y_, max_.x_, min_.y_, color_.r_, color_.g_, color_.b_, t);
  win.draw_line(max_.x_, max_.y_, min_.x_, max_.y_, color_.r_, color_.g_, color_.b_, t);
  win.draw_line(min_.x_, min_.y_, max_.x_, min_.y_, color_.r_, color_.g_, color_.b_, t);
  win.draw_line(min_.x_, min_.y_, min_.x_, max_.y_, color_.r_, color_.g_, color_.b_, t);
}
