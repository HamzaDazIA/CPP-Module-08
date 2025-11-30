#ifndef  easyfind_HPP
#define  easyfind_HPP

#include <iostream>
#include <algorithm>


template <typename T> void easyfind(T &type, int integer)
{
    typename T::iterator a = std::find(type.begin(), type.end(), integer);

    if ( a == type.end())
        throw std::runtime_error("we not found in container");
    else
        std::cout << "we found " << integer << " in container " << std::endl ; 
}

#endif