#include "solution.h"
#include <iostream>
#include <string>

static bool g_debug = false;

static void parse_args(int argc, char** argv) {
  for (int i = 1; i < argc; i++) {
    std::string a = argv[i];
    if (a == "--debug") g_debug = true;
  }
}

#define DLOG(msg) do { if (g_debug) std::cerr << "[debug] " << msg << "\n"; } while(0)

int main(int argc, char** argv) {
  parse_args(argc, argv);
  DLOG("start");
  solve(std::cin, std::cout);
  DLOG("end");
  return 0;
}
