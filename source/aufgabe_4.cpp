#include "Circle.hpp"

#include <set>
#include <iostream>
#include <algorithm>

int main(int argc, char* argv[])
{
  Circle2 c_1;
  Vec2 mid_2;
  Vec2 mid_3{ 5.0,5.6 };
  Color color_2{ 0.0, 1.0, 0.0 };
  Color color_3{ 0.0, 1.0, 0.5 };
  Circle2 c_2{ "Charles", mid_2, 2.5, color_2 };
  Circle2 c_3{ "Charles", mid_2, 0.1, color_3 };
  Circle2 c_4;
  Circle2 c_5;
  std::multiset<Circle2> circles;
  circles.insert(c_1);
  circles.insert(c_2);
  circles.insert(c_3);
  circles.insert(c_4);
  circles.insert(c_5);

  std::string name;
  std::cout << "Enter circle name:" << "\n";
  std::cin >> name;

  for (auto& circle : circles) {
    if (circle.get_name() == name) {
      std::cout << circle << "\n";
    }
  }
}
