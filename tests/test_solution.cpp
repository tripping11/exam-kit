#include "solution.h"
#include <cassert>
#include <sstream>
#include <string>
#include "test_utils.h"

static void test_echo() {
  std::istringstream in("hello");
  std::ostringstream out;
  solve(in, out);
  EXPECT_EQ(out.str(), "hello\n");
}

int main() {
  test_echo();
  return 0;
}
