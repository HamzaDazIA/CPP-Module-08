#include "Span.hpp"
#include <ctime> 
#include <cstdlib>

int main()
{
    std::cout << "--- Subject Test ---" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "\n--- Large Test (15,000 items) ---" << std::endl;
    try {
        std::vector<int> randomVector;
        std::srand(std::time(NULL)); 
        

        for (int i = 0; i < 15000; i++) {
            randomVector.push_back(std::rand());
        }

        Span bigSpan(15000);

        bigSpan.addRange(randomVector.begin(), randomVector.end());

        std::cout << "Shortest: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest: " << bigSpan.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}