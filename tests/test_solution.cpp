#include "solution.h"
#include <cassert>
#include <sstream>
#include <string>

static void test_echo() {
  std::istringstream in("hello");
  std::ostringstream out;
  solve(in, out);
  assert(out.str() == "hello\n");
}

int main() {
  test_echo();
  return 0;
}
