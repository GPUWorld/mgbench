
//          Copyright RedPortal 2017 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mgbench/benchmark_suite.hpp>
#include <mgbench/benchmark_runner.hpp>

#include <numeric>
#include <iterator>
#include <exception>
#include <vector>

namespace mgbench
{
    template<typename It>
    std::chrono::duration<double>
    chrono_reduce_mean(It begin, It end)
    {
        auto sum = std::accumulate(begin, end, std::chrono::duration<double>(0));
        return sum / std::distance(begin, end);
    }

    benchmark_suite::
    benchmark_suite(std::string&& kernel_name)
        :_kernel_name(kernel_name),
         _start_set(false),
         _end_set(false) {}

    std::string
    benchmark_suite::
    get_name()
    { return _kernel_name; }

    std::chrono::duration<double>
    benchmark_suite::
    run(size_t n)
    {
        size_t iterations =
            internal::benchmark_runner::get_instance()->_iterations;
        auto raw_results = std::vector<std::chrono::duration<double>>(iterations);

        for(auto& i : raw_results)
        {
            if(!_start_set || !_end_set)
                throw std::runtime_error("[mgbench error] region to be measured not set.");
            
            suite(n);

            i = _end - _start;

            _start_set = false;
            _end_set = false;
        }
        
        return chrono_reduce_mean(raw_results.cbegin(), raw_results.cend());
    } 
}
