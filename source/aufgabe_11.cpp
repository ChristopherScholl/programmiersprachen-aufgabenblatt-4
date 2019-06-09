# define CATCH_CONFIG_RUNNER
# include <catch.hpp>
# include <cmath>
# include <algorithm>
# include <vector>

bool is_multiple_of_3(int const& i)
{
  if (i % 3 == 0) {
    return true; 
  }
  else {
    return false;
  }
}

bool is_not_multiple_of_3(int const& i)
{
  if (i % 3 == 0) {
    return false;
  }
  else {
    return true;
  }
}

TEST_CASE("filter alle vielfache von drei", "[ erase ]")
{
  std::vector <int> v(100);
  for (auto& element : v) {
    element = std::rand() % 101;
  }

  std::cout << "\n";
  v.erase(std::remove_if(v.begin(), v.end(), is_not_multiple_of_3), v.end());

  REQUIRE(std::all_of(v.begin(), v.end(), is_multiple_of_3));
}

TEST_CASE("addiere Werte zweier vectoren", "[ transform ]")
{
  std::vector <int> v_1{ 1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 };
  std::vector <int> v_2{ 9 ,8 ,7 ,6 ,5 ,4 ,3 ,2 ,1 };
  std::vector <int> v_3(9);
  
  std::transform(v_1.begin(), v_1.end(), v_2.begin(), v_3.begin(), [](const int &v, const int &w)-> int {return v + w; });

  REQUIRE(std::all_of(v_3.begin(), v_3.end(), [](const int& v)-> bool {return v == 10; }));
}

int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}
