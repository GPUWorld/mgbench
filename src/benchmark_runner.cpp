
//          Copyright RedPortal 2017 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mgbench/benchmark_runner.hpp>
#include <mgbench/nvprof.hpp>

#include <iostream>

namespace mgbench
{
    internal::benchmark_runner runner;

    internal::benchmark_runner*
    internal::benchmark_runner::
    get_instance()
    { return &runner; }

    void
    internal::benchmark_runner::
    register_benchmark(benchmark_suite* suite)
    { _suites.push_back(suite); }

    std::vector<benchmark_suite*>& 
    internal::benchmark_runner::
    get_suites() 
    { return _suites; }

    std::vector<internal::data_bundle>
    internal::benchmark_runner::
    compute_flops(std::vector<data_bundle>&& data) const
    {
        return data;
    }
    
    std::vector<internal::data_bundle>
    internal::benchmark_runner::
    run_benchmarks()
    {
        auto result = std::vector<internal::data_bundle>();
        result.reserve(_suites.size());

        for(auto& suite : _suites)
        {
            size_t idx = 0;
            for(auto n : _scale)
            {
                result.emplace_back(_scale.size(),
                                    _scale.size(),
                                    suite->get_name());

                result.back().x[idx] = n;
                result.back().time[idx] =
                    std::chrono::duration_cast<std::chrono::microseconds>(
                        suite->run(n));
                ++idx;
            }
        }

        return compute_flops(std::move(result));
    }
}
