#include "Span.hpp"

Span::Span() : N(5) {}

Span::Span(unsigned int N)
{
    this->N = N;
}

Span::~Span() {}

Span::Span(const Span &obj)
{
    this->N = obj.N;
    if (obj.cont.size() == 0)
        return;
    else
    {
        for (size_t i = 0; i < obj.cont.size(); i++)
            cont.push_back(obj.cont[i]);
    }
}

Span &Span::operator=(const Span &obj)
{
    this->N = obj.N;
    if (obj.cont.empty())
        return (*this);

    else
    {
        if (this->cont.size() != 0)
            this->cont.clear();
        for (size_t i = 0; i < obj.cont.size(); i++)
            cont.push_back(obj.cont[i]);
    }
    return (*this);
}

void Span::addNumber(unsigned int number)
{
    if (this->cont.size() == this->N)
        throw(MaxElement());
    this->cont.push_back(number);
}

const char *Span::MaxElement::what() const throw()
{
    return ("Error size of Container is equle N");
}

int Span::shortestSpan()
{
    if (this->cont.size() < 2)
        throw std::logic_error("Not enough elements to find a span");
    int rs = INT_MAX;
    std::vector<int> tmp = this->cont;
    std::sort(tmp.begin(), tmp.end());

    for (size_t i = 0; i < this->cont.size() - 1; i++)
    {
        if (tmp[i + 1] - tmp[i] < rs)
            rs = tmp[i + 1] - tmp[i];
    }
    return (rs);
}

int Span::longestSpan()
{
    if (this->cont.size() < 2)
        throw std::logic_error("Not enough elements to find a span");

    std::vector<int> tmp = this->cont;
    std::sort(tmp.begin(), tmp.end());
    return (tmp.back() - tmp.front());
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{

    if (this->cont.size() + std::distance(begin, end) > this->N)
        throw(MaxElement());
    
    this->cont.insert(this->cont.end(), begin, end);
}