#include "easyfind.hpp"
#include <vector>

int main()
{
    std::vector<int> cont;

    cont.push_back(2);
    cont.push_back(3);
    cont.push_back(33);
    cont.push_back(444);
    cont.push_back(4);

    try
    {
        easyfind(cont, 33);
        easyfind(cont, 4);
        easyfind(cont, 5);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl; 
    }
}