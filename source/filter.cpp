#include <algorithm>

template<typename T>

T filter(T const& container, bool const& praedikat) {
  bool not_praedikat = !praedikat;
  T new_container = container;
  new_container.erase(std::remove_if(new_container.begin(), new_container.end(), not_praedikat), new_container.end());
  return new_container;
}
