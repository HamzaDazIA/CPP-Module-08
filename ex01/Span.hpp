#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>


class Span
{
    private :
        unsigned int N;
        std::vector<int> cont;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span &obj);
        Span & operator=(const Span& obj);
        ~Span();
        void addNumber(unsigned int number);
        int shortestSpan();
        int longestSpan();
        class MaxElement: public std::exception{
            const char * what() const throw();
        };
        void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        
};
#endif