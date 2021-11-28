cmake_minimum_required(VERSION 3.15)


PROJECT(JuceBenchmark
    LANGUAGES CXX
    VERSION 1.0.0)


# Google Benchmark and its dependency
# https://stackoverflow.com/questions/55376111/how-to-build-and-link-google-benchmark-using-cmake-in-windows
include(FetchContent)

FetchContent_Declare(googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG main)

FetchContent_Declare(googlebenchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG v1.5.2)

FetchContent_MakeAvailable(
    googletest
    googlebenchmark)

# Add JUCE
add_subdirectory(lib/JUCE)

# Add the plugin code
add_subdirectory(src)
add_subdirectory(benchmark) # Uncomment after we add the benchmark project
