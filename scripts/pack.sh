#!/usr/bin/env bash
set -euo pipefail
rm -f submit.zip
zip -r submit.zip CMakeLists.txt README.md src include tests scripts -x "build/*" ".git/*"
echo "[ok] generated submit.zip"
