# define CATCH_CONFIG_RUNNER
# include <catch.hpp>
# include <iostream>
# include "list.hpp"
# include "circle.hpp"

TEST_CASE("teste Aufgabe2 & 3", "[ Aufgabe2&3 ]")
{
  List<int> list;

  REQUIRE(list.size() == 0);
  REQUIRE(list.empty() == true);

  list.push_front(1);
  REQUIRE(list.size() == 1);
  REQUIRE(list.empty() == false);
  REQUIRE(list.front() == 1);
  REQUIRE(list.back() == 1);

  list.push_front(2);
  REQUIRE(list.size() == 2);
  REQUIRE(list.empty() == false);
  REQUIRE(list.front() == 2);
  REQUIRE(list.back() == 1);

  list.pop_front();
  REQUIRE(list.size() == 1);
  REQUIRE(list.empty() == false);
  REQUIRE(list.front() == 1);
  REQUIRE(list.back() == 1);

  list.pop_front();
  REQUIRE(list.size() == 0);
  REQUIRE(list.empty() == true);
  
  list.push_back(1);
  REQUIRE(list.front() == 1);
  REQUIRE(list.back() == 1);

  list.push_back(2);
  REQUIRE(list.front() == 1);
  REQUIRE(list.back() == 2);

  list.pop_back();
  REQUIRE(list.front() == 1);
  REQUIRE(list.back() == 1);

  list.pop_back();
  REQUIRE(list.empty() == true);

  list.pop_back();
  REQUIRE(list.empty() == true);
}

TEST_CASE(" should be empty after clearing ", "[ modifiers ]")
{
  List <int> list;
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.push_front(4);
  list.clear();
  REQUIRE(list.empty());
}

//TEST_CASE(" should be empty after clearing ", "[ modifiers ]")
//{
//  List < Circle2 > circle_list;
//  circle_list.push_back(...);
//  auto c_it = circle_list.begin();
//  std::cout << "Der Radius des 1. Circles in der Liste ist: "
//    << c_it->get_radius() << std::endl;
//}

TEST_CASE(" should be an empty range after default construction ",
  "[ iterators ]")
{
  List <int> list;
  auto b = list.begin();
  auto e = list.end();
  REQUIRE(b == e);
}

TEST_CASE(" provide access to the first element with begin ", "[ iterators ]")
{
  List <int> list;
  list.push_front(42);
  REQUIRE(42 == *list.begin());
}

TEST_CASE(" testing Iterators ", "[ iterators ]")
{
  List <int> list;
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.push_front(4);
  auto i = list.begin();
  REQUIRE((*i.node).value == 4);
  i = i.next();
  REQUIRE(*i == 3); // *i statt (*i.node).value
  auto j = i++;
  REQUIRE(*i == 2);
  REQUIRE(*j == 3);
  REQUIRE(j != i);  // test von ==
  j = ++i;
  REQUIRE(j == i);  // test von !=
}

//TEST_CASE(" copy constructor ", "[ constructor ]")
//{
//  List <int > list;
//  list.push_front(1);
//  list.push_front(2);
//  list.push_front(3);
//  list.push_front(4);
//  List <int > list2{ list };
//  //REQUIRE(list == list2);
//}

int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}
