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

class MergeSort
{
private:
    std::vector<int> merge(std::vector<int> left, std::vector<int> right)
    {
        if (left.size() > 1)
        {
            left = sort(left);
        }
        if (right.size() > 1)
        {
            right = sort(right);
        }

        std::vector<int> merged(left.size() + right.size());
        ulong l = 0;
        ulong r = 0;
        ulong m = 0;
        while (l < left.size() && r < right.size())
        {
            if (left.at(l) < right.at(r)) 
            {
                merged[m++] = left.at(l++);
            }
            else
            {
                merged[m++] = right.at(r++);
            }
        }
        while (l < left.size())
        {
            merged[m++] = left.at(l++);
        }
        while (r < right.size())
        {
            merged[m++] = right.at(r++);
        }

        return merged;
    }

public:
    std::vector<int> sort(std::vector<int> numbers)
    {
        if (numbers.size() < 2)
        {
            return numbers;
        }
        ulong mid = numbers.size() / 2;
        return merge(std::vector<int>(numbers.begin(), numbers.begin() + mid), std::vector<int>(numbers.begin() + mid, numbers.end()));
    }
};

int main()
{
    std::vector<int> numbers;
    std::generate_n(std::back_inserter(numbers), 50, RandomNumberBetween(1, 100));

    std::cout << "Yet unsorted array: ";
    for (const auto number: numbers)
    {
        std::cout << number << " ";
    }
    std::cout << "\n";

    std::vector<int> mergeSorted = MergeSort().sort(numbers);
    std::cout << "Merge sorted array: ";
    for (const auto number : mergeSorted)
    {
        std::cout << number << " ";
    }
    std::cout << "\n";

    std::sort(numbers.begin(), numbers.end());

    std::cout << "Stdrd sorted array: ";
    for (const auto number : numbers)
    {
        std::cout << number << " ";
    }
    std::cout << "\n";

    return 0;
}