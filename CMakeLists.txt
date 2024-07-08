cmake_minimum_required(VERSION 3.0.0)
project(GEOSPATIAL_FUNCTIONS VERSION 0.1.0 LANGUAGES C CXX)

# Find the GEOS library
find_package(GEOS REQUIRED)

add_executable(GEOSPATIAL_FUNCTIONS main.cpp)

# Link the GEOS library to your target
target_link_libraries(GEOSPATIAL_FUNCTIONS GEOS::geos)

