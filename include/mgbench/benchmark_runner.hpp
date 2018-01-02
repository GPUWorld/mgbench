
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
        class benchmark_runner
        {
        private:
            std::vector<benchmark_suite> _suites;
       
        protected:
            void register_bechmark(benchmark_suite* suite);

        public:
            size_t _iterations;
            std::vector<size_t> _scale;

            static benchmark_runner*
            get_instance();
        };
    }
}

#endif
