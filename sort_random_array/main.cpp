#include <algorithm>
#include <cstdio>
#include <iostream>
#include <random>
#include <vector>

auto RandomNumberBetween = [](int low, int high)
{
    auto randomFunc = [distribution_ = std::uniform_int_distribution<int>(low, high),
        random_engine_ = std::mt19937{ std::random_device{}() }]() mutable
    {
        return distribution_(random_engine_);
    };
    return randomFunc;
};

int main()
{
    std::vector<int> numbers;
    std::generate_n(std::back_inserter(numbers), 50, RandomNumberBetween(1, 100));

    std::cout << "Unsorted array: ";
    for (const auto number: numbers)
    {
        std::cout << number << " ";
    }
    std::cout << "\n";

    std::sort(numbers.begin(), numbers.end());

    std::cout << "Sorted array: ";
    for (const auto number : numbers)
    {
        std::cout << number << " ";
    }
    std::cout << "\n";

    return 0;
}