
//          Copyright RedPortal 2017 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef _MGBENCH_MGBENCH_NVPROF_HPP_
#define _MGBENCH_MGBENCH_NVPROF_HPP_

#include <string>
#include <cstdlib>
#include <unordered_map>

namespace boost{ namespace process{} }

namespace mgbench
{
    namespace internal
    {
        class nvprof_handler
        {
        private:
            std::unordered_map<std::string, size_t> _flops;

        public:
            nvprof_handler();

            size_t
            operator[](std::string const& kernel_name) const;
        };
    }
}

#endif
