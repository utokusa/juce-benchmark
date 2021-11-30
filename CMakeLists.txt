cmake_minimum_required(VERSION 3.15)


PROJECT(JuceBenchmark
    LANGUAGES CXX
    VERSION 1.0.0)

# Add JUCE
add_subdirectory(lib/JUCE)

# Add the plugin code
add_subdirectory(src)
