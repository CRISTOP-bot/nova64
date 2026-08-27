name: Nova64 CI
on: [push, pull_request]
jobs:
 build:
  runs-on: ubuntu-latest
  steps:
   - uses: actions/checkout@v4
   - name: Build
     run: cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug && cmake --build build --parallel
   - name: Tests
     run: ctest --test-dir build --output-on-failure
