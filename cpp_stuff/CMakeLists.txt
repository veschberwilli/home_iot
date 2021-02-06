cmake_minimum_required(VERSION 3.0.0)

project(exif_header_checker VERSION 0.1.0)

SET(Boost_USE_STATIC_LIBS ON)

find_package(Boost COMPONENTS log program_options REQUIRED)


include_directories( ${Boost_INCLUDE_DIRS} )

add_executable(exif_header_checker main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

target_link_libraries (exif_header_checker ${Boost_LIBRARIES})
