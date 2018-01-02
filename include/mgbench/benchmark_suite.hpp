
//          Copyright RedPortal 2017 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef _MGBENCH_MGBENCH_BENCHMARK_SUITE_HPP_
#define _MGBENCH_MGBENCH_BENCHMARK_SUITE_HPP_

#include <string>
#include <chrono>
#include <memory>

#define MGBENCH_MEASURE(CLOSURE)                                        \
    do{ benchmark_suite::_start = std::chrono::steady_clock::now(); \
        benchmark_suite::_start = true;                                 \
        do CLOSURE while(false);                                        \
        benchmark_suite::_end= std::chrono::steady_clock::now();        \
        benchmark_suite::_end= true; }while(false);                                                      


namespace mgbench
{
    class benchmark_suite
    {
    private:
        std::string _kernel_name;

    protected:
        std::chrono::time_point<std::chrono::steady_clock> _start;
        std::chrono::time_point<std::chrono::steady_clock> _end;
        bool _start_set;
        bool _end_set;

        explicit benchmark_suite(std::string&& kernel_name);

        std::chrono::duration<double>
        run(size_t n);

    public:
        virtual void suite(size_t n) = 0;
    }; 
}

#endif
