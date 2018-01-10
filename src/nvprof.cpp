

//          Copyright RedPortal 2017 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <string>
#include <system_error>

#include <boost/process/child.hpp>
#include <mgbench/nvprof.hpp>

namespace mgbench
{
    namespace bp = boost::process;

    internal::nvprof_handler::
    nvprof_handler()
        : _flops()
    {
        auto is = bp::ipstream();

        auto ec = std::error_code();
        auto nvprof = bp::system("nvprof", bp::stdout > is, ec);

        auto it = std::istream_iterator<char>(is);
        auto end = std::istream_iterator<char>();

        auto output = std::string(it, end);

        std::cout << results;
    }

    size_t
    internal::nvprof_handler::
    operator[](std::string const& kernel_name)
    {
        
    }
}

#endif
