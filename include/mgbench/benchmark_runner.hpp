
//          Copyright RedPortal 2017 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef _MGBENCH_MGBENCH_BENCHMARK_RUNNER_HPP_
#define _MGBENCH_MGBENCH_BENCHMARK_RUNNER_HPP_

#include <vector>
#include <memory>

#include "benchmark_suite.hpp"

namespace mgbench
{
    namespace internal
    {
        struct data_bundle
        {
            inline data_bundle(size_t x_n, size_t y_n,
                               std::string const& name)
                : x(x_n), time(y_n), flops(y_n), name(name) {}

            std::vector<size_t> x;
            std::vector<std::chrono::microseconds> time;
            std::vector<std::chrono::microseconds> flops;
            std::string name;
        };


        class benchmark_runner
        {
        private:
            std::vector<benchmark_suite*> _suites;

            std::vector<data_bundle>
            compute_flops(std::vector<data_bundle>&& data) const;

        public:
            size_t _iterations;
            std::vector<size_t> _scale;

            void register_benchmark(benchmark_suite* suite);

            std::vector<data_bundle>
            run_benchmarks();

            std::vector<benchmark_suite*>&
            get_suites();


            static benchmark_runner*
            get_instance();
        };
    }
}

#endif
