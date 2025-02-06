cmake_minimum_required(VERSION 3.20)
project(CppGameOfLife CXX)

# Set C++23 as the required standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add compiler warnings for better code quality
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Create the executable
add_executable(life main.cpp)

# Optional: Add specific compiler optimization flags
if(CMAKE_BUILD_TYPE MATCHES Release)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
endif()

# Optional: Add specific libraries if needed
# target_link_libraries(game_of_life PRIVATE some_library)
