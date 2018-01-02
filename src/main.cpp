
//          Copyright RedPortal 2017 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <string>
#include <iostream>
#include <exception>

void help();
void mgbench_configuration();

int main(int argc, char** argv)
{
    bool graph_result = false;
    bool print_result = false;

    for(int i = 1; i < argc; ++i)
    {
        auto opt = std::string(argv[i]);

        if(opt == "--graph" || opt == "-g")
            graph_result = true;
        else if(opt == "--print" || opt == "-p")
            print_result = true;
        else if(opt == "--help" || opt == "-h")
        {
            help();
            std::terminate();
        }
        else
        {
            std::cerr << "unknow command: " << opt << '\n'
                      << "pass --help or -h for help"
                      << std::endl;
            std::terminate();
        }
    }
    
    mgbench_configuration();

    if(print_result)
        ;
    if(graph_result)
        ;


    return 0;
}

void
help()
{
    std::cout << "mgbench. A CUDA Kernel benchmark framework\n"
              << "------------------------------------------\n"
              << "command line arguments:\n"
              << " --graph -g : plot benchmark result into a graph\n"
              << " --print -p : print benchmark result through stdout"
              << std::endl;
}
