
cmake_minimum_required(VERSION 3.8)
project(mgbench)

find_package(CUDA REQUIRED)

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
set(SOURCE_FILES ${SOURCE_DIR}/main.cpp)

cuda_add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${CUDA_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME}
    ${CUDA_LIBRARIES})


