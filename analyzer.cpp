#include <iostream>
#include <vector>
#include <string>
#include <chrono>

extern std::vector<std::string>& getStringData();

int linear_search(const std::vector<std::string>& container, const std::string& element)
{
    for (size_t i = 0; i < container.size(); ++i)
    {
        if (container[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int binary_search(const std::vector<std::string>& container, const std::string& element)
{
    int left = 0;
    int right = container.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (container[mid] == element)
        {
            return mid;
        }
        if (container[mid] < element)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    std::vector<std::string> dataset = getStringData();
    std::vector<std::string> elements_to_search = {"not_here", "mzzzz", "aaaaa"};

    for (const auto& element : elements_to_search)
    {
        std::cout << "\nSearching for '" << element << "':\n";

        auto start_time = std::chrono::high_resolution_clock::now();
        int index = linear_search(dataset, element);
        auto end_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end_time - start_time;
        std::cout << "Linear Search: Index = " << index << ", Time = " << elapsed.count() << " seconds\n";

        start_time = std::chrono::high_resolution_clock::now();
        index = binary_search(dataset, element);
        end_time = std::chrono::high_resolution_clock::now();
        elapsed = end_time - start_time;
        std::cout << "Binary Search: Index = " << index << ", Time = " << elapsed.count() << " seconds\n";
    }

    return 0;
}
