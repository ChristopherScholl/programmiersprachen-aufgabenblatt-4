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

  List <Circle2> circle_list;
  circle_list.push_back(Circle2());
  auto c_it = circle_list.begin();
  std::cout << "Der Radius des 1. Circles in der Liste ist: "
    << c_it->get_radius() << std::endl;
  REQUIRE(c_it->get_radius() == 1);
}

TEST_CASE(" testing == operators ", "[ operators ]")
{
  List <int> list1;
  list1.push_front(1);
  list1.push_front(2);
  list1.push_front(3);
  List <int> list2;
  list2.push_front(1);
  list2.push_front(2);
  list2.push_front(3);
  List <int> list3;
  list3.push_front(3);
  list3.push_front(2);
  list3.push_front(1);
  List <int> list4;
  list4.push_front(1);
  list4.push_front(2);
  List <int> list5;
  REQUIRE(list1 == list2);
  REQUIRE(list1 != list3);
  REQUIRE(list1 != list4);
  REQUIRE(list1 != list5);
}

TEST_CASE(" copy constructor ", "[ constructor ]")
{
  List <int> list;
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.push_front(4);
  List <int> list2{ list };
  REQUIRE(list == list2);
}

TEST_CASE(" inserting ", "[ modifiers ]")
{
  List <int> list;
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.push_front(4);
  auto p = list.begin().next();
  list.insert(p, 5);
  REQUIRE(list.front() == 4);
  REQUIRE(*(list.begin().next()) == 5);
  REQUIRE(*p == 3);
  REQUIRE(*(p.next()) == 2);
  REQUIRE(list.back() == 1);
}

TEST_CASE(" reversing ", "[ modifiers ]")
{
  List <int> list;
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.push_front(4);
  list.reverse();
  REQUIRE(list.front() == 1);
  REQUIRE(list.back() == 4);
  List<int> list2 = reverse(list);
  REQUIRE(list2.front() == 4);
  REQUIRE(list2.back() == 1);
}

TEST_CASE(" move constructor ", "[constructor]") 
{
  List<int> list;
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.push_front(4);
  List<int> list2 = std::move(list);
  REQUIRE(0 == list.size());
  REQUIRE(list.empty());
  REQUIRE(4 == list2.size());
}

int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}
