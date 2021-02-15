#include "rpnx/environment.hpp"
#include <iostream>

int main()
{
    auto env = rpnx::get_environment();


    for (auto & x : env)
    {
        std::cout << "Key=" << x.first << " Value=" << x.second << std::endl;
    }

    auto path = rpnx::get_path();

    for (std::filesystem::path const & x : path)
    {
        std::cout << "Path Value=" << x << std::endl;
    }

    std::cout << "Current directory: " << rpnx::current_path() << std::endl;

}