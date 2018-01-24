cmake_minimum_required(VERSION 3.8)
project(center_finder)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV)
if (${OpenCV_FOUND})
    include_directories(${OpenCV_INCLUDE_DIRS})
    set(LIBRARIES ${OpenCV_LIBRARIES})
else()
    message(FATAL_ERROR "Can't find OpenCV")
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/ICenterFinder
        ${CMAKE_CURRENT_SOURCE_DIR}/src/HoughBasedCenterFinder
        )

add_library(center_finder ${SRC})
set(LIBRARIES ${LIBRARIES} center_finder)

add_executable(center_finder_test main.cpp)

target_link_libraries(center_finder_test ${LIBRARIES})
