#include "solution.h"
#include <iostream>
#include <string>

// 获取文件名，去掉路径前缀（跨平台简化版）
inline const char* file_name(const char* path) {
    const char* file = path;
    while (*path) {
        if (*path++ == '/') file = path;
    }
    return file;
}

#define DLOG(msg) \
    do { \
        if (g_debug) { \
            std::cerr << "[\033[33mDEBUG\033[0m] " \
                      << file_name(__FILE__) << ":" << __LINE__ << " | " \
                      << msg << "\n"; \
        } \
    } while (0)

static bool g_debug = false;

static void parse_args(int argc, char** argv) {
  for (int i = 1; i < argc; i++) {
    std::string a = argv[i];
    if (a == "--debug") g_debug = true;
  }
}

int main(int argc, char** argv) {
  parse_args(argc, argv);
  DLOG("start");
  solve(std::cin, std::cout);
  DLOG("end");
  return 0;
}
