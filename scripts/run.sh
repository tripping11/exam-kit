#!/usr/bin/env bash
set -euo pipefail
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j
if [[ $# -ge 1 ]]; then
  ./build/main < "$1"
else
  ./build/main
fi
