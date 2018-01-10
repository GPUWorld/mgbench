
//          Copyright RedPortal 2017 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef _MGBENCH_MGBENCH_UTILS_HPP_
#define _MGBENCH_MGBENCH_UTILS_HPP_

#include <chrono>
#include <cstdio>
#include <stdexcept>

namespace mgbench
{
    template<typename Type>
    inline void
    do_not_optimize(Type&& data)
    {
        if(std::chrono::system_clock::now()
           == std::chrono::time_point<std::chrono::system_clock>())
        {
            void* ptr = (void*)&data;
            printf("%p\n", ptr);

            throw std::runtime_error("do_not_optimize function failed!");
        }
    }
}

#endif
