# Minimum cmake version required
cmake_minimum_required(VERSION 3.8)

# Help CMake to find the installed library on Windows or Mac OS X
if(WIN32)
  list(APPEND CMAKE_PREFIX_PATH "C:\\Program Files (x86)\\ReactPhysics3D")
elseif(APPLE)
  list(APPEND CMAKE_PREFIX_PATH "/usr/local/lib/cmake/ReactPhysics3D")
endif()

# Import the ReactPhysics3D library
find_package(ReactPhysics3D REQUIRED)

# Project
project(Physics_Formula_Class)

# Create the executable
add_executable(Physics_Formula_Class testFactory.cpp)

# Link with the ReactPhysics3D library
target_link_libraries(Physics_Formula_Class ReactPhysics3D::ReactPhysics3D)