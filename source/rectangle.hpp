# ifndef RECTANGLE2_HPP
# define RECTANGLE2_HPP

#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

// Rectangle2 data type definition
class Rectangle2
{
public:
  Rectangle2(){}
  Rectangle2(Vec2 const& min, Vec2 const& max, Color const& color):min_(min), max_(max), color_(color) {}
  float circumference() const;
  bool is_inside(Vec2 v) const;
  void draw(Window const& win) const;
  void draw(Window const& win, float t) const;

private:
  Vec2  min_{ 0.0,1.0 };
  Vec2  max_{ 1.0,0.0 };
  Color color_{ 0.5,0.5,0.5 };
};

# endif // RECTANGLE2_HPP