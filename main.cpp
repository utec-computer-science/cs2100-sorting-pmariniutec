#include <iostream>
#include "tests.h"

int main() {
  std::cout << "Testing Sorts:" << '\n';

  auto tester = Tests{};
  tester.executeTests<int>();
  tester.executeTests<double>();
  tester.executeTests<float>();

  return EXIT_SUCCESS;
}

