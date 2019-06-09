# define CATCH_CONFIG_RUNNER
# include <catch.hpp>
# include <cmath>
# include <algorithm>
#include <iostream>
# include <vector>
# include "Circle.hpp"

TEST_CASE("sortiere Kreise", "[ sort ]")
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
  std::vector<Circle2> sorted_circles;
  sorted_circles.push_back(c_1);
  sorted_circles.push_back(c_2);
  sorted_circles.push_back(c_3);
  sorted_circles.push_back(c_4);
  sorted_circles.push_back(c_5);

  for (auto& circle : sorted_circles) {
    std::cout << circle << "\n";
  }

  std::cout << "-----------------------------------------------------\n" << "\n";

  std::sort(sorted_circles.begin(), sorted_circles.end());
  //std::sort(sorted_circles.begin(), sorted_circles.end(), [](Circle2 c1, Circle2 c2)-> bool {return c1 < c2; });

  for (auto& circle : sorted_circles) {
    std::cout << circle << "\n";
  }

  REQUIRE(std::is_sorted(sorted_circles.begin(), sorted_circles.end()));
}

int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}
