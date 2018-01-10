
cmake_minimum_required(VERSION 3.8)
project(mgbench)

find_package(CUDA REQUIRED)
find_package(Boost 1.64 REQUIRED)

add_definitions(-DCUDA_TOOLKIT_ROOT_DIR=${CUDA_TOOLKIT_ROOT_DIR})

set(CMAKE_MODULE_PATH
    ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

if(NOT CUDA_HOST_COMPILER)
    message(STATUS "separate cuda host compiler  wasn't provided, using default")
endif()

if(NOT CUDA_ARCH)
    message(STATUS "cuda arch wasn't provided, running feature test")
    include(feature_test)
else()
    set(CUDA_GEN_CODE "-gencode arch=compute_${CUDA_ARCH},code=sm_${CUDA_ARCH}")
endif()

set(BUILD_FLAGS
    "${CMAKE_CXX_FLAGS} -std=c++14 -g -Wall -Wextra")

set(CUDA_NVCC_FLAGS "${CUDA_NVCC_FLAGS}; ${CUDA_GEN_CODE} -Xcompiler ${BUILD_FLAGS}")


set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set(SOURCE_FILES
    ./test.cpp
    ${SOURCE_DIR}/main.cpp
    ${SOURCE_DIR}/benchmark_runner.cpp
    ${SOURCE_DIR}/benchmark_suite.cpp)

#cuda_add_executable(${PROJECT_NAME} ${SOURCE_FILES})
set(CMAKE_CXX_FLAGS "-std=c++14 -g -Wall -Wextra")
add_executable(${PROJECT_NAME} ${SOURCE_FILES})


target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${Boost_INCLUDE_DIRS}
    ${CUDA_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME}
    ${Boost_LIBRARIES}
    ${CUDA_LIBRARIES})


