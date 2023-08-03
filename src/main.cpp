#include <iostream>
#include <vector>
#include <ranges>

#include <boost/algorithm/string.hpp>

#include "random.h"

int main() {
    std::cout << "A boost random number: " << math::random(0, 10) << std::endl;

    auto capitalise = [](const std::string& word) { return boost::algorithm::to_upper_copy(word); };

    std::vector<std::string> words{"hello", " ", "world"};
    for(const auto& word: std::views::transform(words, capitalise))
        std::cout << word;

    std::cout << std::endl;

    return 0;
}