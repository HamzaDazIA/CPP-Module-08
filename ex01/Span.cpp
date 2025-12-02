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
    long long rs = INT_MAX;
    std::vector<int> tmp = this->cont;
    std::sort(tmp.begin(), tmp.end());

    for (size_t i = 0; i < this->cont.size() - 1; i++)
    {
        long long tmp1 = static_cast<long long>(tmp[i + 1]);
        long long tmp2 = static_cast<long long>(tmp[i]);
        long long diff = tmp1 - tmp2;

        if (diff  < rs)
            rs = diff;
    }
    if (rs > INT_MAX)
        throw std::runtime_error("The ressult is to long for a int type");
    return (static_cast<int>(rs));
}

int Span::longestSpan()
{
    if (this->cont.size() < 2)
        throw std::logic_error("Not enough elements to find a span");

    std::vector<int> tmp = this->cont;
    std::sort(tmp.begin(), tmp.end());
    long long tm1 = static_cast<long long >(tmp.back());
    long long tm2 = static_cast<long long >(tmp.front());
    long long rs = tm1 - tm2;
    
    if (rs > INT_MAX)
        throw std::runtime_error("The ressult is to long for a int type");
    return (static_cast<int>(rs));
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{

    if (this->cont.size() + std::distance(begin, end) > this->N)
        throw(MaxElement());
    
    this->cont.insert(this->cont.end(), begin, end);
}