# ifndef CIRCLE2_HPP
# define CIRCLE2_HPP

#include "vec2.hpp"
#include "color.hpp"

#include <iostream>

// Circle2 data type definition
class Circle2
{
public:
  Circle2() {}
  Circle2(std::string name, Vec2 const& mid, float const& radius, Color const& color) :name_(name), mid_(mid), radius_(radius), color_(color) {}
  std::string get_name() const;
  float get_radius() const;
  float circumference() const;
  bool is_inside(Vec2 v) const;
  std::string print() const;

private:
  std::string name_ = "YEE";
  Vec2  mid_{ 1.0,1.0 };
  float  radius_ = 1.0;
  Color color_{ 0.5,0.5,0.5 };
};

std::ostream& operator <<(std::ostream& os, Circle2 const& c);
bool operator ==(Circle2 const& c1, Circle2 const& c2);
bool operator <(Circle2 const& c1, Circle2 const& c2);
bool operator >(Circle2 const& c1, Circle2 const& c2);

# endif // CIRCLE2_HPP