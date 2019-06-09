# define CATCH_CONFIG_RUNNER
# include <catch.hpp>
# include <cmath>
# include <algorithm>
# include <vector>
# include "filter.cpp"

bool is_even(int n) { return n % 2 == 0; }

TEST_CASE("f", "[ F ]")
{
  std::vector <int> v{ 1 ,2 ,3 ,4 ,5 ,6 };
  std::vector <int> all_even = filter(v, is_even);

  REQUIRE(v[0] == 2);
  REQUIRE(v[1] == 4);
  REQUIRE(v[2] == 6);
}

int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}
