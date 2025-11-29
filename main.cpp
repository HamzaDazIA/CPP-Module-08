#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers;
    numbers.push_back(10);
    numbers.push_back(20);

    // This iterator writes to standard output with ", " as a delimiter
    std::ostream_iterator<int> output_it(std::cout, ", ");

    *output_it = 5; // Valid: Writes 5 to console
    ++output_it;    // Valid: Ready for next write
    *output_it = 8; // Valid: Writes 8 to console
    
    // int x = *output_it; // INVALID! You cannot read from an output iterator
}