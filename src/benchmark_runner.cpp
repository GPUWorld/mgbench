
//          Copyright RedPortal 2017 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mgbench/benchmark_runner.hpp>
#include <iostream>

namespace mgbench
{
    internal::benchmark_runner runner;

    internal::benchmark_runner*
    internal::benchmark_runner::
    get_instance()
    {
        return &runner;
    }

    void
    internal::benchmark_runner::
    register_bechmark(u_ptr<benchmark_suite>&& suite)
    {
        _suites.push_back(std::move(suite));
    }
}
