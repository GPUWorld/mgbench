
//          Copyright RedPortal 2017 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef _MGBENCH_MGBENCH_CONFIGURATION_HPP_
#define _MGBENCH_MGBENCH_CONFIGURATION_HPP_

#include <mgbench/benchmark_runner.hpp>

#include <vector>
#include <algorithm>
#include <cmath>

#define MGBENCH_CONFIGURATION()                 \
    void mgbench_configuration()

namespace mgbench
{
    inline void
    set_iterations(size_t iterations)
    {
        internal::benchmark_runner::get_instance()
            ->_iterations = iterations;
    }

    inline void
    set_linear_scale(size_t from, size_t to, size_t interval)
    {
        std::vector<size_t> sequence(
            std::floor(static_cast<double>(from - to) / interval));

        std::generate(sequence.begin(), sequence.end(),
                      [&from, interval, to](){
                          return std::min(from + interval, to);
                      });

        internal::benchmark_runner::get_instance()
            ->_scale = std::move(sequence);
    }

    inline void
    set_log_scale(size_t from, size_t to, size_t interval)
    {
        std::vector<size_t> sequence((from - to) / interval);

        std::generate(sequence.begin(), sequence.end(),
                      [&from, interval, to](){
                          return std::min(from * interval, to);
                      });

        internal::benchmark_runner::get_instance()
            ->_scale = std::move(sequence);
    }

    inline void
    set_scale_sequence(std::initializer_list<size_t> list)
    {
        internal::benchmark_runner::get_instance()
            ->_scale = std::vector<size_t>(list.begin(), list.end());
    }

    inline void
    set_scale_sequence(std::vector<size_t> const& list)
    {
        internal::benchmark_runner::get_instance()
            ->_scale = std::vector<size_t>(list);
    }
}

#endif
