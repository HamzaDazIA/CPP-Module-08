#ifndef  easyfind_HPP
#define  easyfind_HPP


#include <iostream>


class Notfind : public std::exception
{
    public:
        const char *what() const throw();
    
};

template <typename T> void easyfind(T type, int integer)
{
    
}

#endif