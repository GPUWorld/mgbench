
//          Copyright RedPortal 2017 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef _MGBENCH_RUN_KERNELS_HPP_
#define _MGBENCH_RUN_KERNELS_HPP_

#include <mgbench/benchmark_runner.hpp>
#include <mgbench/utils.hpp>

namespace mgbench
{
    namespace internal
    {
        inline void
        run_kernels()
        {
            auto* runner = internal::benchmark_runner::get_instance();
        
            for(auto& suite : runner->get_suites())
            { do_not_optimize(suite->run(1)); }
        }
    }
}

#endif
