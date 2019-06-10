# define CATCH_CONFIG_RUNNER
# include <catch.hpp>
# include "list.hpp"

TEST_CASE("teste Aufgabe1", "[ Aufgabe1 ]")
{
  List<int> list1;
  List<int> list2{0, 2, 3};

  REQUIRE(list1.empty() == true);
  REQUIRE(list2.empty() == false);
  REQUIRE(list1.size() == 0);
  REQUIRE(list2.size() == 3);
}

int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}
