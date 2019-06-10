# define CATCH_CONFIG_RUNNER
# include <catch.hpp>
# include <iostream>
# include "list.hpp"

TEST_CASE("teste Aufgabe2 & 3", "[ Aufgabe2&3 ]")
{
  List<int> list;

  REQUIRE(list.size() == 0);
  REQUIRE(list.empty() == true);
  list.push_front(5);
  list.push_front(50);
  list.push_front(500);
  REQUIRE(list.size() == 3);
  REQUIRE(list.empty() == false);
  //REQUIRE(list.front() == 500);
  //REQUIRE(list.back() == 50);
  list.pop_front();
  REQUIRE(list.size() == 2);
  REQUIRE(list.empty() == false);
}

//TEST_CASE("add an element with push_front ", "[ modifiers ]")
//{
//  List <int > list;
//  list.push_front(42);
//  REQUIRE(42 == list.front());
//}
//
//TEST_CASE(" should be empty after clearing ", "[ modifiers ]")
//{
//  List <int> list;
//  list.push_front(1);
//  list.push_front(2);
//  list.push_front(3);
//  list.push_front(4);
//  list.clear();
//  REQUIRE(list.empty());
//}
//
////TEST_CASE(" should be empty after clearing ", "[ modifiers ]")
////{
////  List < Circle > circle_list;
////  circle_list.push_back(...);
////  auto c_it = circle_list.begin();
////  std::cout << "Der Radius des 1. Circles in der Liste ist: "
////    << c_it->get_radius() << std::endl;
////}
//
//TEST_CASE(" should be an empty range after default construction ",
//  "[ iterators ]")
//{
//  List <int> list;
//  auto b = list.begin();
//  auto e = list.end();
//  REQUIRE(b == e);
//}
//
//TEST_CASE(" provide access to the first element with begin ", "[ iterators ]")
//{
//  List <int> list;
//  list.push_front(42);
//  REQUIRE(42 == *list.begin());
//}
//
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
