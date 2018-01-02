
//          Copyright RedPortal 2017 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef _MGBENCH_MGBENCH_ADD_BENCHMARK_HPP_
#define _MGBENCH_MGBENCH_ADD_BENCHMARK_HPP_

#include <mgbench/benchmark_suite.hpp>
#include <mgbench/benchmark_runner.hpp>

#define MGBENCH_SUITE_NAME(KERNEL_NAME) _mgbench_suite_##KERNEL_NAME

#define MGBENCH_BENCHMARK(KERNEL_NAME)                                  \
    class MGBENCH_SUITE_NAME(KERNEL_NAME) : public mgbench::benchmark_suite \
    { MGBENCH_SUITE_NAME(KERNEL_NAME)()                                 \
            : mgbench::benchmark_suite(std::string(KERNEL_NAME))        \
        { benchmark_runner::get_instance()                              \
                ->register_benchmark(this); }                           \
        void MGBENCH_SUITE_NAME(KERNEL_NAME)::suite(size_t MGBENCH_N);  \
    };                                                                  \
    void MGBENCH_SUITE_NAME(KERNEL_NAME)::suite(size_t MGBENCH_N)

#endif
