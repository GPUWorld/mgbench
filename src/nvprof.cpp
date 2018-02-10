

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
    std::vector<std::string>
    split_string(const std::string& str, char delimiter)
    {
        std::vector<std::string> strings;

        std::string::size_type pos = 0;
        std::string::size_type prev = 0;
        while ((pos = str.find(delimiter, prev)) != std::string::npos)
        {
            strings.push_back(str.substr(prev, pos - prev));
            prev = pos + 1;
        }
        strings.push_back(str.substr(prev));
        return strings;
    }

    size_t
    count_flops(size_t index,
                std::vector<std::string> const& str)
    {
        auto sp = str[index + 1];
        auto sp_special = str[index + 2];

        auto sp_formatted = split_string(str, ' ');
        auto sp_special_formatted = split_string(str, ' ');

        size_t sp_value = std::stoi(sp_formatted.back());
        size_t sp_special_value = std::stoi(sp_special_formatted.back());

        return sp_value + sp_special_value;
    } 

    namespace bp = boost::process;

    void
    internal::nvprof_handler::
    find_flops(std::vector<std::string>&& output)
    {
        size_t kernel_idx = 0;
        for(auto const& elem : output)
        {
            if(idx != std::string::npos)
            {
                auto kernel_name_idx = elem.find("Kernel: ");
                auto paren_idx = elem.find("(");

                auto kenel_name =
                    std::string(elem, kenel_name_idx, paren_idx);

                _flops[kernel_name] = count_flops(idx, elem);
            }
            ++kernel_idx;
        }
    }


    internal::nvprof_handler::
    nvprof_handler()
        : _flops()
    {
        auto is = bp::ipstream();

        auto command_line_args
            = std::string(" --metrics flops_sp --metrics flops_sp_special");

        auto ec = std::error_code();
        auto nvprof = bp::system("nvprof " + command_line_args, bp::stdout > is, ec);

        auto it = std::istream_iterator<char>(is);
        auto end = std::istream_iterator<char>();

        auto output = std::string(it, end);

        find_flops(split_string(output, '\n'));
    }

    size_t
    internal::nvprof_handler::
    operator[](std::string const& kernel_name)
    {
        return _flops[kenel_name];
    }
}

#endif
